#include "get_next_line.h"

char *ft_get_next_line(int fd) {
  static char *rest;
  size_t size;
  char *buff;
  char *p;
  char *tmp;
  t_list *out;

  if (BUFFER_SIZE < 2)
    return (NULL);
  buff = malloc(BUFFER_SIZE);
  if (buff == NULL)
    return (NULL);
  out = NULL;
  tmp = NULL;
  if (rest != NULL) {
    p = ft_strchr1(rest, '\n');
    if (p) {
      *p = 0;
      if (*(p + 1))
        tmp = ft_strdup1(p + 1);
      p = ft_strdup1(rest);
      free(rest);
      free(buff);
      rest = tmp;
      return (p);
    }
    ft_lstadd_back1(&out, ft_lstnew1(ft_strdup1(rest)));
    free(rest);
    rest = NULL;
  }
  while (1) {
    size = read(fd, buff, BUFFER_SIZE - 1);
    if (size <= 0)
      break;
    buff[size] = 0;
    p = ft_strchr1(buff, '\n');
    if (p) {
      *p = 0;
      if (*(p + 1))
        rest = ft_strdup1(p + 1);
      ft_lstadd_back1(&out, ft_lstnew1(ft_strdup1(buff)));
      break;
    }
    ft_lstadd_back1(&out, ft_lstnew1(ft_strdup1(buff)));
  }

  p = ft_lstjoin1(out);
  ft_lstclear1(&out, free);
  free(buff);
  return (p);
}
