#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

struct song_node * insert(struct song_node *head, char pname[100], char partist[100]) {
  struct song_node *new_song = malloc(sizeof(struct song_node));
  strcpy(new_song->name,pname);
  strcpy(new_song->artist,partist);

  // before head
  if (strcmp(new_song->artist,head->artist) < 0) {
        return insert_front(head, pname, partist);
      }
  if (strcmp(new_song->artist,head->artist) == 0
      && strcmp(new_song->name,head->name) < 0) {
        return insert_front(head, pname, partist);
      }

  struct song_node *prev = malloc(sizeof(struct song_node));
  prev->next = head->next;
  strcpy(prev->artist,head->artist);
  strcpy(prev->name,head->name);
  // need to deal with pass by reference (we are actually USING prev)
  // need to free current node?
  // CHECK for nulls

  while (strcmp(new_song->artist,prev->artist) > 0) {
    prev = prev->next;
    // print_song(prev);
  }
  printf("here!\n" );
  if (strcmp(new_song->artist,prev->artist) == 0) {
    printf("here!\n" );
    while (strcmp(new_song->name,prev->name) >= 0) {
      if (strcmp(new_song->artist,prev->next->artist) != 0) break;
      prev = prev->next;
      print_song(prev);
    }
    printf("here!\n" );
    if (strcmp(new_song->name,prev->name) != 0) {
      print_song(prev);
      print_song(new_song);
      printf("here!\n" );
      new_song->next = prev->next;
      prev->next = new_song;
    }
  }
  else {
    printf("here!\n" );
    new_song->next = prev->next;
    prev->next = new_song;
  }
  return head;
}

struct song_node * insert_front(struct song_node *head, char pname[100], char partist[100]) {
  struct song_node *s = malloc(sizeof(struct song_node));
  s->next = head;
  strcpy(s->name,pname);
  strcpy(s->artist,partist);
  return s;
}

void print_song(struct song_node *s) {
  if (s == NULL) {
    printf("Song doesn't exist! \n");
    return;
  }

  else {
    char * name = s->name;
    char * artist = s->artist;
    printf("%s -- %s \n", artist, name);
  }

}

void print_list(struct song_node *s) {
  if(s == NULL) {
    // printf("[] \n");
    return;
  }
  while(s) {
    char * name = s->name;
    char * artist = s->artist;
    printf("[%s: %s] | ", artist, name);
    s = s->next;
  }
  printf("\n" );

  // printf("[ Name:  , Artist: ] \n");
  return;
}

//Helper function - return length of list
int list_length(struct song_node * head){
  if (head == 0) {
    return 0;
  }

  return 1 + list_length(head->next);
}

//Helper function - return node at index
struct song_node * get_node(struct song_node *head, int i){
  if (i == 0) {
    return head;
  }

  else if (head->next) {
    return get_node(head->next, i - 1);
  }

  else {
    return 0;
  }
}

//Helper function - return integer comparison value for songs
int songcmp(struct song_node *n1, struct song_node *n2){
  int art_comp = strcmp(n1->artist, n2->artist);

  if (art_comp == 0) {
    return art_comp;
  }

  return strcmp(n1->name, n2->name);
}
