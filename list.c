#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void insert_node (struct song_node *s, struct song_node *backref, struct song_node *head) {
  //backref is passed as the head node initially
  struct song_node *cur_node = backref;

  if(backref == head) {



  }


}

void print_song(struct song_node *s) {
  if (s == NULL) {
    printf("Song doesn't exist! \n");
    return;
  }

  else {
    char * name = s->name;
    char * artist = s->artist;
    printf("%s -- %s \n", name, artist);
  }

}

void print_list(struct song_node *s) {
  if(n == NULL) {
    printf("[] \n");
    return;
  }

  while(n->next) {
    char * name = n->name;
    char * artist = n->artist;
    printf("[]", num);
    printf(" --> ");
    n = n->next;
  }

  printf("[ Value: %d ] \n", n->i);
  return;
}
