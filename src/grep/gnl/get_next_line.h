#ifndef __GNL_H
#define __GNL_H

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef __S_LIST__
#define __S_LIST__
typedef struct s_list {
  void *content;
  struct s_list *next;
} t_list;
#endif

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

t_list *ft_lstnew1(void *content);
void ft_lstclear1(t_list **lst, void (*del)(void *));
void ft_lstadd_back1(t_list **lst, t_list *new);
char *ft_strdup1(char *str);
int ft_strlen1(char *str);
char *ft_strchr1(char *str, char c);
char *ft_lstjoin1(t_list *lst);

char *ft_get_next_line(int fd);

#endif // __GNL_H
