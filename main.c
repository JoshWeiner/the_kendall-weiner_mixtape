#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "library.h"


int main() {
  struct song_node * head = malloc(sizeof(struct song_node));
  strcpy(head->artist, "c");
  strcpy(head->name, "s0");
  // struct song_node *list2 = malloc(sizeof(struct song_node));
  // strcpy(head2->artist, "c");
  // strcpy(head2->name, "s10");
  // list2->next = 0x0;
  // printf("%d\n\n",songcmp(head,list2));

  print_song(head);
  print_list(head);

  head = insert_front(head,"s1","b");
  // print_song(head);
  print_list(head);

  head = insert(head,"s0","b");
  // print_song(head);
  print_list(head);

  head = insert(head,"s0","a");
  // print_song(head);
  print_list(head);

  head = insert(head, "s2","b");
  print_list(head);

  head = insert(head, "s2","b");
  print_list(head);

  print_song(find(head,"s2","b"));
  print_song(find(head,"gotem","whoa"));
  print_list(head);
  printf("\n\n" );

  print_song(find_first(head,"b"));
  print_song(random_node(head));
  printf("\n\n" );

  head =remove_song(head,"s0","a");
  print_list(head);

  head =remove_song(head,"s2","b");
  print_list(head);

  head =remove_song(head,"s1","b");
  print_list(head);

  head = free_list(head);
  print_list(head);
  printf("\n\n\n\n" );


  insert_song("s0","a");
  insert_song("s1","aba");
  insert_song("s120","aa");
  // printf("%d", sizeof(table[0]));
  // print_list(table[0]);
  print_song(table[0]->next);
  // print_song(search_song("s120","aa"));
  // search_artist("a");
  // search_artist("ba");
  // print_letter("a");

  return 0;
}
