#include "get_next_line.h"

int ft_strlen1(char *str) {
  int out;

  out = 0;
  while (*str++)
    out++;
  return (out);
}

char *ft_strdup1(char *str) {
  char *out;
  int i;

  if (str == NULL)
    return (NULL);
  out = malloc(ft_strlen1(str) + 1);
  if (out == NULL)
    return (NULL);
  i = 0;
  while (*str)
    out[i++] = *str++;
  out[i] = 0;
  return (out);
}

t_list *ft_lstnew1(void *content) {
  t_list *out;

  if (content == NULL)
    return (NULL);
  out = malloc(sizeof(t_list));
  if (out == NULL)
    return (NULL);
  out->content = content;
  out->next = NULL;
  return (out);
}

void ft_lstadd_back1(t_list **lst, t_list *new) {
  t_list *tmp;

  if (lst == NULL || new == NULL)
    return;
  if (*lst == NULL)
    *lst = new;
  else {
    tmp = *lst;
    while (tmp->next)
      tmp = tmp->next;
    tmp->next = new;
  }
}

void ft_lstclear1(t_list **lst, void (*del)(void *)) {
  t_list *p;

  if (*lst == NULL)
    return;
  while (*lst) {
    p = *lst;
    *lst = (*lst)->next;
    del(p->content);
    free(p);
  }
  free(*lst);
  *lst = NULL;
}

char *ft_lstjoin1(t_list *lst) {
  int size;
  t_list *tmp;
  char *out;
  char *p;
  int j;

  if (lst == NULL)
    return (NULL);
  size = 0;
  tmp = lst;
  while (tmp) {
    size += ft_strlen1(tmp->content);
    tmp = tmp->next;
  }
  out = malloc(size + 1);
  if (out == NULL)
    return (NULL);
  j = 0;
  while (lst) {
    p = lst->content;
    while (*p)
      out[j++] = *p++;
    lst = lst->next;
  }
  out[j] = 0;
  return (out);
}

char *ft_strchr1(char *str, char c) {
  if (str == NULL)
    return (NULL);
  while (*str) {
    if (*str == c)
      return (str);
    str++;
  }
  if (c == *str)
    return (str);
  return (NULL);
}