#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    fprintf(stderr, "usage %s", argv[0]);
    exit(EXIT_FAILURE);
  }
  if (rename(argv[1], argv[2]) == -1)
  {
    perror("Error:");
    exit(EXIT_FAILURE);
  }
  printf("Moved %s to %s \n", argv[1], argv[2]);
  return 0;
}