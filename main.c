#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "library.h"

int main() {
  struct song_node *list = malloc(sizeof(struct song_node));
  strcpy(list->artist, "c");
  strcpy(list->name, "s0");
  list->next = 0x0;
  print_song(list);
  print_list(list);

  list = insert_front(list,"s1","b");
  print_song(list);
  print_list(list);

  list = insert(list,"s0","b");
  print_song(list);
  print_list(list);

  list = insert(list,"s0","a");
  print_song(list);
  print_list(list);

  list = insert(list, "s2","b");
  print_list(list);

  list = insert(list, "s2","b");
  print_list(list);
  //
  // list = insert(list, "s1","a");
  // print_list(list);

  // list = insert(list, "s3","b");
  // print_list(list);

  return 0;
}
