#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "library.h"


int main() {
  struct song_node *list = malloc(sizeof(struct song_node));
  strcpy(list->artist, "c");
  strcpy(list->name, "s0");
  // struct song_node *list2 = malloc(sizeof(struct song_node));
  // strcpy(list2->artist, "c");
  // strcpy(list2->name, "s10");
  // list2->next = 0x0;
  // printf("%d\n\n",songcmp(list,list2));

  print_song(list);
  print_list(list);

  list = insert_front(list,"s1","b");
  // print_song(list);
  print_list(list);

  list = insert(list,"s0","b");
  // print_song(list);
  print_list(list);

  list = insert(list,"s0","a");
  // print_song(list);
  print_list(list);

  list = insert(list, "s2","b");
  print_list(list);

  list = insert(list, "s2","b");
  print_list(list);

  print_song(find(list,"s2","b"));
  print_song(find(list,"gotem","whoa"));
  print_list(list);
  printf("\n\n" );

  print_song(find_first(list,"b"));
  print_song(random_node(list));
  printf("\n\n" );

  list=remove_song(list,"s0","a");
  print_list(list);

  list=remove_song(list,"s2","b");
  print_list(list);

  list=remove_song(list,"s1","b");
  print_list(list);

  list = free_list(list);
  print_list(list);
  printf("\n\n\n\n" );


  insert_song("s0","a");
  insert_song("s1","aba");
  insert_song("s120","aa");
  print_list(table[0]);
  print_song(search_song("s120","aa"));
  search_artist("a");
  search_artist("ba");
  print_letter("a");

  return 0;
}
