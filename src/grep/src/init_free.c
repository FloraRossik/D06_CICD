#include "../ft_grep.h"

void init_grep(t_grep *arg) {
  if (arg == NULL) return;
  arg->files = NULL;
  arg->patterns_path = NULL;
  arg->patterns_list = NULL;
  arg->patterns = NULL;
  arg->flags = 0;
  if (isatty(1)) set_flag(arg, F_COLORED);
  arg->c_lines = 1;
  arg->c_matches = 0;
}

void free_split(char ***arr) {
  char **p;

  if (!arr || !*arr) return;
  p = *arr;
  while (p)
    if (*p) free(*p++);
  free(*arr);
}

void free_reg(void *re) {
  if (re) {
    regfree(re);
    free(re);
  }
}

void free_args(t_grep *arg) {
  if (arg == NULL) return;
  if (arg->patterns) free(arg->patterns);
  if (arg->patterns_path) ft_lstclear(&(arg->patterns_path), free);
  if (arg->files) ft_lstclear(&(arg->files), free);
  if (arg->patterns_list) ft_lstclear(&(arg->patterns_list), free_reg);
}
