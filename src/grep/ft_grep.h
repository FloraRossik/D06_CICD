#ifndef __FT_GREP_H__
#define __FT_GREP_H__

#ifndef __S_LIST__
#define __S_LIST__
typedef struct s_list {
  void *content;
  struct s_list *next;
} t_list;
#endif

typedef struct s_grep {
  t_list *patterns_list;
  t_list *files;
  t_list *patterns_path;
  char *patterns;
  int flags; // eivclnhsfoE
  int c_lines;
  int c_matches;
} t_grep;

#include "gnl/get_next_line.h"
#include <fcntl.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define F_MULTFILE 200
#define F_EMPTLINE 201
#define F_COLORED 300

#define S21_WHITE "\x1b[0m"
#define S21_RED "\x1b[1;91m" // Bold Red
#define S21_GREEN "\x1b[32m"
#define S21_YELLOW "\x1b[33m"
#define S21_BLUE "\x1b[34m"
#define S21_MAGENTA "\x1b[35m"
#define S21_CYAN "\x1b[36m"

extern int exit_status;

int ft_lstsize(t_list *lst);
t_list *ft_lstnew(void *content);
void ft_lstclear(t_list **lst, void (*del)(void *));
void ft_lstadd_back(t_list **lst, t_list *new);
char **ft_split(char const *s, char c);
size_t ft_strlen(const char *s);
char *ft_strdup(const char *s1);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char *ft_strnstr(const char *haystack, const char *needle, size_t len);
int ft_tolower(int c);
void *ft_memcpy(void *dst, const void *src, size_t n);
char *ft_strchr(const char *s, int c);
void ft_putstr_fd(char *s, int fd);
void ft_putnbr_base_fd(int nb, const char *base, int fd);
void *ft_memset(void *b, int c, size_t len);
void exit_perror(char *msg, int status, int mask);
void *ft_allocate(size_t n);
void exit_msg(char *msg, int status, int mask);
void print_error(char *msg, int status, int mask);
int check_flag(t_grep *arg, int flag);
void set_flag(t_grep *arg, int flag);
void set_long_flag(t_grep *arg, char *flag);
void init_grep(t_grep *arg);
void read_args(t_grep *arg, int argc, char **argv);
void split_patterns(t_grep *arg);
void compile_patterns(t_grep *arg);
int match(t_grep *arg, char *str, regmatch_t pmatch[], t_list **matches);
void print_prifix(t_grep *arg, char *str, char *file_path);
void print_matches_lines(t_grep *arg, char *str, t_list *matches,
                         char *file_path);
void print_matches_clean(t_grep *arg, char *str, t_list *matches,
                         char *file_path);
int match_file(t_grep *arg, char *file_path);
void match_files_list(t_grep *arg);
void free_split(char ***arr);
void free_reg(void *re);
void free_args(t_grep *arg);
void print_args(t_grep *arg);

#endif //__FT_GREP_H__