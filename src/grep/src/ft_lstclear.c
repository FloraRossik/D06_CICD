#include "../ft_grep.h"

void ft_lstclear(t_list **lst, void (*del)(void *)) {
  t_list *p;

  if (*lst == NULL) return;
  while (*lst) {
    p = *lst;
    *lst = (*lst)->next;
    del(p->content);
    free(p);
  }
  free(*lst);
  *lst = NULL;
}
