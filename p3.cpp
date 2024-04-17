#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
if (argc != 3) {
fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
exit(EXIT_FAILURE);
}

char *source = argv[1];
char *destination = argv[2];

// Create a hard link from source to destination
if (link(source, destination) == -1) {
perror("link");
exit(EXIT_FAILURE);
}

// Remove the source file

if (unlink(source) == -1) {
perror("unlink");
// \f unlink fails, we leave the destination file in place to avoid data loss
exit(EXIT_FAILURE);

}

printf("File moved successfully!\n");

return 0;

}