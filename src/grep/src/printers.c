#include "../ft_grep.h"

void print_prifix(t_grep *arg, char *str, char *file_path) {
  (void)str;

  if (check_flag(arg, F_MULTFILE) && !check_flag(arg, 'l')) {
    if (check_flag(arg, F_COLORED))
      printf("%s%s%s:%s", S21_MAGENTA, file_path, S21_CYAN, S21_WHITE);
    else
      printf("%s:", file_path);
  }
  if (check_flag(arg, 'n') && !check_flag(arg, 'l')) {
    if (check_flag(arg, F_COLORED))
      printf("%s%d%s:%s", S21_GREEN, arg->c_lines, S21_CYAN, S21_WHITE);
    else
      printf("%d:", arg->c_lines);
  }
}

void print_matches_lines(t_grep *arg, char *str, t_list *matches,
                         char *file_path) {
  t_list *p;
  (void)arg;
  (void)file_path;
  if (str == NULL) return;
  print_prifix(arg, str, file_path);
  p = matches;
  while (p) {
    regmatch_t *rm = p->content;
    for (int i = 0; i < rm->rm_so && *str; i++) putc(*str++, stdout);
    if (check_flag(arg, F_COLORED)) fputs(S21_RED, stdout);
    for (int i = rm->rm_so; i < rm->rm_eo && *str; i++) putc(*str++, stdout);
    if (check_flag(arg, F_COLORED)) fputs(S21_WHITE, stdout);
    p = p->next;
  }
  if (*str) {
    printf("%s", str);
  }
  putc('\n', stdout);
}

void print_matches_clean(t_grep *arg, char *str, t_list *matches,
                         char *file_path) {
  t_list *p;

  if (str == NULL) return;
  p = matches;
  while (p) {
    regmatch_t *rm = p->content;
    if (check_flag(arg, 'o') && rm->rm_eo == 0) {
      p = p->next;
      continue;
    }
    print_prifix(arg, str, file_path);
    for (int i = 0; i < rm->rm_so && *str; i++, str++)
      ;
    if (check_flag(arg, F_COLORED)) fputs(S21_RED, stdout);
    for (int i = rm->rm_so; i < rm->rm_eo && *str; i++) putc(*str++, stdout);
    if (check_flag(arg, F_COLORED)) fputs(S21_WHITE, stdout);
    putc('\n', stdout);
    p = p->next;
  }
}

void print_args(t_grep *arg) {
  t_list *p;

  ft_putnbr_base_fd(arg->flags, "01", 1);

  printf("\npatterns : %s\n", arg->patterns);

  printf("patterns_path :\n");
  p = arg->patterns_path;
  while (p) {
    printf("\t|%s|\n", (char *)p->content);
    p = p->next;
  }
  printf("files : \n");
  p = arg->files;
  while (p) {
    printf("\t|%s|\n", (char *)p->content);
    p = p->next;
  }
  printf("patterns_list :\n");
  p = arg->patterns_list;
  while (p) {
    printf("\t|%s|\n", (char *)p->content);
    p = p->next;
  }
  printf("------------------------------------\n");
}
