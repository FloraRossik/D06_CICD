#include "../ft_grep.h"

void compile_patterns(t_grep *arg) {
  regex_t *re;
  t_list *p;
  int f;

  if (arg == NULL) return;
  f = check_flag(arg, 'i') ? REG_ICASE : 0;
  f |= check_flag(arg, 'E') ? REG_EXTENDED : 0;
  p = arg->patterns_list;
  while (p) {
    re = malloc(sizeof(regex_t));
    if (!re) exit_perror("allocation t_regex: ", 2, 1);
    if (regcomp(re, p->content, f) != 0) exit_perror("regcomp error: ", 2, 1);
    free(p->content);
    p->content = re;
    p = p->next;
  }
}
