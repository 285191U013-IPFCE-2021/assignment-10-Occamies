#include "linked_list.h"
/*
 * Linked list
 */

#include <stdio.h>		/* printf */
#include <stdlib.h>		/* malloc, free */
#include <assert.h>		/* assert */

/* functions to create lists */
node *make_node (int v, node * q)
{
  node *p = malloc (sizeof (node));
  p->value = v;

  if (q == NULL)
    p->next = NULL;
  else
    p->next = q;
  return p;
}

/* free all nodes in the list p */
void free_list (node * p)
{
  node *q = p;
  while (q != NULL)
    {
      node *t = q->next;
      free (q);
      q = t;
    }
}


/* print list to console */
void print_list (node * p)
{
  printf("[");
  if ( p-> next == NULL){
   printf("]");
}
    else{
      printf("%d", p->value);
      print_list(p->value);
  }

}

int sum_squares (node * p)
{
    if (p -> next != NULL)
    return(square (p->value)+ sum_squares (p->next));
    else
    return (p->value*p->value);
}

node *map (node * p, int (*f) (int))
{
if(p!=NULL){
  node *item =malloc(sizeof(node));
  item->value = f(p->value);
  item->value = map(p->next, f);
  return item;
}
  else{
    return NULL;
  }
}


int square (int x)
{
  return x * x;
}
