
#include "../src/list.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

int main (int argc, char * argv [])
{
   list (int, list);
   memset (&list, 0, sizeof (list));

   assert (list_length (list) == 0);

   list_push (list, 5);
   list_push (list, 6);
   list_push (list, 7);
   list_push (list, 8);
   list_push (list, 9);
   list_push (list, 10);

   assert (list_length (list) == 6);
   
   list_push_front (list, 4);
   list_push_front (list, 3);
   list_push_front (list, 2);
   list_push_front (list, 1);
   list_push_front (list, 0);

   assert (list_length (list) == 11);

   list_each (list, value)
   {
      printf ("%d ", value);
   }

   printf ("\n");

   assert (!list_find (list, 11));
   assert (list_find (list, 5));

   list_remove (list, 5);

   assert (list_length (list) == 10);
   assert (!list_find (list, 5));

   list_each_iter (list, iter)
   {
       if (list_iter_value (iter) % 2 != 0)
           list_iter_remove (iter);
   }

   assert (list_length (list) == 6);

   list_each_r (list, value)
   {
      printf ("%d ", value);
   }

   printf ("\n");

   list_clear (list);

   assert (list_length (list) == 0);

   return 0;
}


