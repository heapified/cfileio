#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#define BUFSIZE 128

int main(int argc, char** argv) {
  if (argc < 3) {
    printf("Not enough arguents\n");
    return -1;
  }

  int srcfd, dstfd;

  if((srcfd = open(argv[1], O_RDONLY)) < 0) {
    perror("failed to open file");
    return -1;
  }

  if ((dstfd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)) < 0) {
    close(srcfd);
    perror("failed to open file");
    return -1;
  }

  char buf[BUFSIZE];
  int bytes_read;
  int bytes_written;

  while ((bytes_read = read(srcfd, buf, BUFSIZE)) > 0) {
    if ((bytes_written = write(dstfd, buf, bytes_read)) < bytes_read) {
      printf("failed to write");
      close(srcfd);
      close(dstfd);
      return -1;
    }
  }

  close(srcfd);
  close(dstfd);
  return 0;
}
