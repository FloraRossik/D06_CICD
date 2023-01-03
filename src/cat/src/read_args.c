#include "../s21_cat.h"

int read_args(t_cat *flag, int argc, char **argv) {
  char *str;
  char **file_name;
  int count;
  int i;
  int j;

  i = 1;
  count = 0;
  while (i < argc) {
    str = argv[i];
    if (*str != '-' || s21_strcmp(str, "-") == 0 ||
        s21_strcmp(str, "--") == 0) {
      count++;
    } else if (str[0] == '-' && str[1] == '-') {
      ft_set_long_flag(flag, str);
    } else {
      str++;
      while (*str)
        set_flag(flag, *str++);
    }
    i++;
  }
  file_name = malloc(((count) + 1) * sizeof(char *));
  if (file_name == s21_NULL)
    s21_exit("unable to allocate memory\n", 1);
  j = 1;
  i = 0;
  while (j < argc) {
    str = argv[j];
    if (*str != '-' || s21_strcmp(str, "-") == 0 ||
        s21_strcmp(str, "--") == 0) {
      file_name[i] = str;
      i++;
    }
    j++;
  }
  file_name[i] = s21_NULL;
  flag->files = file_name;
  return (-1);
}
