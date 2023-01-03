#include "../s21_cat.h"

void ft_init_flags(t_cat *flags) {
  flags->files = s21_NULL;
  flags->flags = 0;
  flags->c_n = 1;
  flags->c_b = 1;
}

int check_flag(t_cat *arg, int flag) // AbeEnstTuv
{
  if (arg == NULL)
    return (0);
  switch (flag) {
  case 'b':
    return ((arg->flags & 1) != 0);
  case 'E':
    return ((arg->flags & 1 << 1) != 0);
  case 'n':
    return ((arg->flags & 1 << 2) != 0);
  case 's':
    return ((arg->flags & 1 << 3) != 0);
  case 'T':
    return ((arg->flags & 1 << 4) != 0);
  case 'u':
    return ((arg->flags & 1 << 5) != 0);
  case 'v':
    return ((arg->flags & 1 << 6) != 0);
  case F_HELP:
    return ((arg->flags & 1 << 7) != 0);
  case F_VERSION:
    return ((arg->flags & 1 << 8) != 0);
  default:
    return (0);
  }
}

void set_flag(t_cat *arg, int flag) // AbeEnstTuv
{
  if (arg == NULL)
    return;
  switch (flag) {
  case 'A':
    arg->flags |= 1 << 6;
    arg->flags |= 1 << 1;
    arg->flags |= 1 << 4;
    break;
  case 'b':
    arg->flags |= 1 << 0;
    break;
  case 'e':
    arg->flags |= 1 << 1;
    arg->flags |= 1 << 6;
    break;
  case 'E':
    arg->flags |= 1 << 1;
    break;
  case 'n':
    arg->flags |= 1 << 2;
    break;
  case 's':
    arg->flags |= 1 << 3;
    break;
  case 't':
    arg->flags |= 1 << 4;
    arg->flags |= 1 << 6;
    break;
  case 'T':
    arg->flags |= 1 << 4;
    break;
  case 'u':
    break;
  case 'v':
    arg->flags |= 1 << 6;
    break;
  case F_HELP:
    arg->flags |= 1 << 7;
    break;
  case F_VERSION:
    arg->flags |= 1 << 8;
    break;
  default:
    s21_exit("invalid flag\n", 1);
  }
}

void ft_set_long_flag(t_cat *arg, char *flag) {
  if (s21_strcmp(flag, "--show-all") == 0)
    set_flag(arg, 'A');
  else if (s21_strcmp(flag, "--number-nonblank") == 0)
    set_flag(arg, 'b');
  else if (s21_strcmp(flag, "--show-ends") == 0)
    set_flag(arg, 'E');
  else if (s21_strcmp(flag, "--number") == 0)
    set_flag(arg, 'n');
  else if (s21_strcmp(flag, "--squeeze-blank") == 0)
    set_flag(arg, 's');
  else if (s21_strcmp(flag, "--show-tabs") == 0)
    set_flag(arg, 'T');
  else if (s21_strcmp(flag, "--show-nonprinting") == 0)
    set_flag(arg, 'v');
  else if (s21_strcmp(flag, "--version") == 0)
    set_flag(arg, F_VERSION);
  else if (s21_strcmp(flag, "--help") == 0)
    set_flag(arg, F_HELP);
  else
    s21_exit("invalid long param", 1);
}
