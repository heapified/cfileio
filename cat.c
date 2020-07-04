#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#define BUFSIZE 128

int main(int argc, char** argv) {
  if (argc < 2) {
    printf("Not enough arguents\n");
    return -1;
  }

  int fd;

  if((fd = open(argv[1], O_RDONLY)) < 0) {
    perror("failed to open file");
    return -1;
  }

  char buf[BUFSIZE];
  int bytes_read;

  while ((bytes_read = read(fd, buf, BUFSIZE-1)) > 0) {
    buf[bytes_read] = 0;
    printf("%s", buf);
  }

  close(fd);
  return 0;
}
