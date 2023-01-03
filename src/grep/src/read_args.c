#include "../ft_grep.h"

void read_args(t_grep *arg, int argc, char **argv) {
  int i;
  char *parm;
  char *p;

  if (!arg || !argv) return;
  i = 1;
  // read the flags first
  while (i < argc) {
    parm = argv[i];

    if (*parm && (ft_strncmp(parm, "-", ft_strlen(parm)) == 0 ||
                  ft_strncmp(parm, "--", ft_strlen(parm)) == 0)) {
      ft_lstadd_back(&(arg->files), ft_lstnew(ft_strdup(argv[i++])));
    } else if (parm[0] == '-' && parm[1] == '-') {
      if (ft_strncmp(parm, "--file=", ft_strlen("--file=")) == 0) {
        p = ft_strchr(parm, '=') + 1;
        ft_lstadd_back(&(arg->patterns_path), ft_lstnew(ft_strdup(p)));
      } else if (ft_strncmp(parm, "--file", ft_strlen(parm)) == 0) {
        i++;
        if (i == argc)
          exit_msg(
              "grep: option '--file' \
                requires an argument\n",
              2, 1);
        ft_lstadd_back(&(arg->patterns_path), ft_lstnew(ft_strdup(argv[i])));
        argv[i] = "---empty-arg";
      } else if (ft_strncmp(parm, "--regexp=", ft_strlen("--regexp=")) == 0) {
        p = ft_strchr(parm, '=') + 1;
        if (*p)
          ft_lstadd_back(&(arg->patterns_list), ft_lstnew(ft_strdup(p)));
        else
          set_flag(arg, F_EMPTLINE);
      } else if (ft_strncmp(parm, "--regexp", ft_strlen(parm)) == 0) {
        i++;
        if (i == argc)
          exit_msg(
              "grep: option '--regexp' \
                    requires an argument\n",
              2, 1);
        ft_lstadd_back(&(arg->patterns_list), ft_lstnew(ft_strdup(argv[i])));
        argv[i] = "---empty-arg";
        if (argv[i][0] == 0) set_flag(arg, F_EMPTLINE);
      } else
        set_long_flag(arg, parm);
    } else if (parm[0] == '-') {
      parm++;
      while (*parm) {
        if (*parm == 'f') {
          parm++;
          if (*parm) {
            ft_lstadd_back(&(arg->patterns_path), ft_lstnew(ft_strdup(parm)));
          } else {
            i++;
            if (i == argc) {
              exit_msg(
                  "grep: option requires an \
                            argument--'f'\n",
                  2, 1);
            }
            ft_lstadd_back(&(arg->patterns_path),
                           ft_lstnew(ft_strdup(argv[i])));
            argv[i] = "---empty-arg";
          }
          break;
        } else if (*parm == 'e') {
          parm++;
          if (*parm) {
            ft_lstadd_back(&(arg->patterns_list), ft_lstnew(ft_strdup(parm)));
          } else {
            i++;
            if (i == argc)
              exit_msg(
                  "grep: option requires an \
                            argument  --  'e'\n",
                  2, 1);
            ft_lstadd_back(&(arg->patterns_list),
                           ft_lstnew(ft_strdup(argv[i])));
            argv[i] = "--empty-arg";
            if (argv[i][0] == 0) set_flag(arg, F_EMPTLINE);
          }
          break;
        } else {
          set_flag(arg, *parm);
        }
        parm++;
      }
    }
    i++;
  }
  i = 1;
  while (i < argc) {
    parm = argv[i];
    if (*parm == '-' && *(parm + 1) && i++) continue;
    if (!arg->patterns && !arg->patterns_path && !arg->patterns_list) {
      if (*parm == 0) set_flag(arg, F_EMPTLINE);
      ft_lstadd_back(&(arg->patterns_list), ft_lstnew(ft_strdup(parm)));
    } else {
      ft_lstadd_back(&(arg->files), ft_lstnew(ft_strdup(parm)));
    }
    i++;
  }

  if (!arg->patterns && !arg->patterns_path && !arg->patterns_list &&
      !check_flag(arg, F_EMPTLINE))
    exit_msg("Usage: grep [OPTION]... PATTERNS [FILE]...\n", 2, 1);
  // set flag X to 1 if there are multiple files and not flag -h
  if (arg->files && arg->files->next && !check_flag(arg, 'h'))
    set_flag(arg, F_MULTFILE);
}

void read_argss(t_grep *arg, int argc, char **argv) {
  int i;

  if (!arg || !argv) return;
  i = 1;
  // read the flags first
  while (i < argc && argv[i][0] == '-') {
    set_flag(arg, argv[i][1]);
    if (argv[i][2]) {
      if (argv[i][1] == 'f') {
        ft_lstadd_back(&(arg->patterns_path),
                       ft_lstnew(ft_strdup(argv[i] + 2)));
      } else if (argv[i][1] == 'e') {
        ft_lstadd_back(&(arg->patterns_list),
                       ft_lstnew(ft_strdup(argv[i] + 2)));
      } else {
        arg->patterns = ft_strdup(argv[i] + 2);
        i++;
        break;
      }
    } else if (argv[i][1] == 'f') {
      if (++i == argc)
        exit_msg("grep: option requires an argument -- 'f'\n", 2, 1);
      ft_lstadd_back(&(arg->patterns_path), ft_lstnew(ft_strdup(argv[i])));
    } else if (argv[i][1] == 'e') {
      if (++i == argc)
        exit_msg("grep: option requires an argument -- 'e'\n", 2, 1);
      ft_lstadd_back(&(arg->patterns_list), ft_lstnew(ft_strdup(argv[i])));
    }
    i++;
  }
  if (!arg->patterns && !arg->patterns_path && !arg->patterns_list &&
      i < argc) {
    if (*argv[i] == 0) set_flag(arg, F_EMPTLINE);
    arg->patterns = ft_strdup(argv[i++]);
  }
  // save the rest as files
  while (i < argc) {
    if (ft_strncmp(argv[i], "-", ft_strlen(argv[i])) == 0 ||
        ft_strncmp(argv[i], "-", ft_strlen(argv[i])) == 0)
      ft_lstadd_back(&(arg->files), ft_lstnew(ft_strdup(argv[i++])));
    i++;
  }
  if (!arg->patterns && !arg->patterns_path && !arg->patterns_list)
    exit_msg("Usage: grep [OPTION]... PATTERNS [FILE]...\n", 2, 1);
  // set flag X to 1 if there are multiple files and not flag -h
  if (arg->files && arg->files->next && !check_flag(arg, 'h'))
    set_flag(arg, F_MULTFILE);
}
