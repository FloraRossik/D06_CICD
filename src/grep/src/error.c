#include "../ft_grep.h"

void exit_perror(char *msg, int status, int mask) {
  if (msg && mask) perror(msg);
  exit(status);
}

void exit_msg(char *msg, int status, int mask) {
  if (msg && mask) ft_putstr_fd(msg, 2);
  exit(status);
}

void print_error(char *msg, int status, int mask) {
  if (msg && mask) perror(msg);
  exit_status = status;
}