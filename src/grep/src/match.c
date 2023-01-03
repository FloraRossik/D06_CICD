#include "../ft_grep.h"

int match(t_grep *arg, char *str, regmatch_t pmatch[], t_list **matches) {
  t_list *p;
  regmatch_t min, *tmp;
  int out;

  if (!arg || !arg->patterns_list || !str) return (0);
  out = 0;
  if (*str == 0 && check_flag(arg, F_EMPTLINE)) return (1);
  do {
    p = arg->patterns_list;
    min.rm_so = __INT32_MAX__;
    min.rm_eo = -1;
    while (p) {
      if (regexec(p->content, str, 1, pmatch, 0) == 0) {
        out = 1;
        if (check_flag(arg, 'l')) return (1);
        if (pmatch[0].rm_so == 0 && pmatch[0].rm_eo == 0) {
          tmp = ft_allocate(sizeof(regmatch_t));
          tmp->rm_eo = 0;
          tmp->rm_so = 0;
          ft_lstadd_back(matches, ft_lstnew(tmp));
        } else if (pmatch[0].rm_so != -1 && pmatch[0].rm_so < min.rm_so) {
          ft_memcpy(&min, &pmatch[0], sizeof(regmatch_t));
        } else if (pmatch[0].rm_so != -1 && pmatch[0].rm_so == min.rm_so &&
                   pmatch[0].rm_eo > min.rm_eo) {
          ft_memcpy(&min, &pmatch[0], sizeof(regmatch_t));
        }
      }
      p = p->next;
    }
    if (min.rm_so != __INT32_MAX__ && min.rm_eo != -1) {
      tmp = ft_allocate(sizeof(regmatch_t));
      ft_memcpy(tmp, &min, sizeof(regmatch_t));
      ft_lstadd_back(matches, ft_lstnew(tmp));
      str += min.rm_eo;
    } else
      break;
  } while (*str);
  return (out);
}

int check_stdin(char *file_path) {
  if (file_path == NULL) return (1);
  if (*file_path) {
    return (ft_strncmp(file_path, "-", ft_strlen(file_path)) == 0 ||
            ft_strncmp(file_path, "--", ft_strlen(file_path)) == 0);
  }
  return (0);
}

int match_file(t_grep *arg, char *file_path) {
  int fd;
  char *line;
  regmatch_t pmatch[2];
  t_list *matches;

  if (arg == NULL) return (0);

  if (check_flag(arg, 'v') && check_flag(arg, F_EMPTLINE)) return (0);

  if (check_stdin(file_path)) {
    fd = STDIN_FILENO;
    file_path = "(standard input)";
  } else if ((fd = open(file_path, O_RDONLY)) < 0) {
    print_error("s21_grep: ", 2, check_flag(arg, 's') == 0);
    return (0);
  }
  matches = NULL;
  while ((line = ft_get_next_line(fd)) != NULL) {
    if (match(arg, line, pmatch, &matches) != check_flag(arg, 'v')) {
      arg->c_matches++;
      if (!check_flag(arg, 'c') && !check_flag(arg, 'l')) {
        if (check_flag(arg, 'o'))
          print_matches_clean(arg, line, matches, file_path);
        else
          print_matches_lines(arg, line, matches, file_path);
      }
      if (check_flag(arg, 'l')) {
        if (check_flag(arg, F_COLORED))
          printf("%s%s%s\n", S21_MAGENTA, file_path, S21_WHITE);
        else
          printf("%s\n", file_path);
        free(line);
        break;
      }
      if (exit_status == EXIT_FAILURE) exit_status = EXIT_SUCCESS;
    }
    free(line);
    ft_lstclear(&matches, free);
    arg->c_lines++;
  }
  if (!check_flag(arg, 'l') && check_flag(arg, 'c') && arg->c_lines) {
    if (check_flag(arg, F_MULTFILE)) {
      if (check_flag(arg, F_COLORED))
        printf("%s%s%s:%s", S21_MAGENTA, file_path, S21_CYAN, S21_WHITE);
      else
        printf("%s:", file_path);
    }
    printf("%d\n", arg->c_matches);
  }
  if (fd) close(fd);
  return (arg->c_matches);
}

void match_files_list(t_grep *arg) {
  t_list *p;

  if (arg == NULL) return;
  p = arg->files;
  if (p == NULL) match_file(arg, NULL);
  while (p) {
    arg->c_lines = 1;
    arg->c_matches = 0;
    match_file(arg, p->content);
    p = p->next;
  }
}
