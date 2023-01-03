#include "../ft_grep.h"

void split_patterns(t_grep *arg) {
  char **spt;
  char **p;
  char *line;
  int fd;
  t_list *tmp;

  if (arg == NULL) return;
  if (arg->patterns) {
    spt = ft_split(arg->patterns, '\n');
    p = spt;
    while (*p) ft_lstadd_back(&(arg->patterns_list), ft_lstnew(*p++));
    free(spt);
  } else if (arg->patterns_path) {
    tmp = arg->patterns_path;
    while (tmp) {
      if (((char *)tmp->content)[0] == '-' && ((char *)tmp->content)[1] == 0)
        fd = STDIN_FILENO;
      else if ((fd = open(tmp->content, O_RDONLY)) < 0)
        exit_perror("error reading patterns file:", 2,
                    check_flag(arg, 's') == 0);
      while ((line = ft_get_next_line(fd))) {
        if (*line == 0) {
          set_flag(arg, F_EMPTLINE);
          free(line);
          continue;
        }
        ft_lstadd_back(&(arg->patterns_list), ft_lstnew(line));
      }
      if (fd != STDIN_FILENO) close(fd);
      tmp = tmp->next;
    }
  }
}
