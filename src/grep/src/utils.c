#include "../ft_grep.h"

void *ft_allocate(size_t n) {
  void *out;

  if (n < 1) return (NULL);
  out = malloc(n);
  if (out == NULL) exit_perror("malloc: ", 2, 1);
  return (out);
}

int check_flag(t_grep *arg, int flag) {
  if (arg == NULL) return (0);
  switch (flag) {
    case 'e':
      return ((arg->flags & 1) != 0);
    case 'i':
      return ((arg->flags & 1 << 1) != 0);
    case 'v':
      return ((arg->flags & 1 << 2) != 0);
    case 'c':
      return ((arg->flags & 1 << 3) != 0);
    case 'l':
      return ((arg->flags & 1 << 4) != 0);
    case 'n':
      return ((arg->flags & 1 << 5) != 0);
    case 'h':
      return ((arg->flags & 1 << 6) != 0);
    case 's':
      return ((arg->flags & 1 << 7) != 0);
    case 'f':
      return ((arg->flags & 1 << 8) != 0);
    case 'o':
      return ((arg->flags & 1 << 9) != 0);
    case 'E':
      return ((arg->flags & 1 << 10) != 0);
    case F_EMPTLINE:
      return ((arg->flags & 1 << 11) != 0);
    case F_MULTFILE:
      return ((arg->flags & 1 << 12) != 0);
    case F_COLORED:
      return ((arg->flags & 1 << 13) != 0);
    default:
      return (0);
  }
}

void set_flag(t_grep *arg, int flag) {
  if (arg == NULL) return;
  switch (flag) {
    case 'e':
      arg->flags |= 1 << 0;
      break;
    case 'i':
      arg->flags |= 1 << 1;
      break;
    case 'v':
      arg->flags |= 1 << 2;
      break;
    case 'c':
      arg->flags |= 1 << 3;
      break;
    case 'l':
      arg->flags |= 1 << 4;
      break;
    case 'n':
      arg->flags |= 1 << 5;
      break;
    case 'h':
      arg->flags |= 1 << 6;
      break;
    case 's':
      arg->flags |= 1 << 7;
      break;
    case 'f':
      arg->flags |= 1 << 8;
      break;
    case 'o':
      arg->flags |= 1 << 9;
      break;
    case 'E':
      arg->flags |= 1 << 10;
      break;
    case F_EMPTLINE:
      arg->flags |= 1 << 11;
      break;
    case F_MULTFILE:
      arg->flags |= 1 << 12;
      break;
    case F_COLORED:
      arg->flags |= 1 << 13;
      break;
    default:
      exit_msg("grep: invalid option\n", 2, 1);
  }
}

void set_long_flag(t_grep *arg, char *flag) {
  if (arg == NULL || flag == NULL) return;
  if (ft_strncmp("--ignore-case", flag, ft_strlen(flag) + 1) == 0)
    set_flag(arg, 'i');
  else if (ft_strncmp("--invert-match", flag, ft_strlen(flag) + 1) == 0)
    set_flag(arg, 'v');
  else if (ft_strncmp("--count", flag, ft_strlen(flag) + 1) == 0)
    set_flag(arg, 'c');
  else if (ft_strncmp("--files-with-matches", flag, ft_strlen(flag) + 1) == 0)
    set_flag(arg, 'l');
  else if (ft_strncmp("--line-number", flag, ft_strlen(flag) + 1) == 0)
    set_flag(arg, 'n');
  else if (ft_strncmp("--no-filename", flag, ft_strlen(flag) + 1) == 0)
    set_flag(arg, 'h');
  else if (ft_strncmp("--no-messages", flag, ft_strlen(flag) + 1) == 0)
    set_flag(arg, 's');
  else if (ft_strncmp("--only-matching", flag, ft_strlen(flag) + 1) == 0)
    set_flag(arg, 'o');

  else
    exit_msg("grep: unrecognized option\n", 2, 1);
}