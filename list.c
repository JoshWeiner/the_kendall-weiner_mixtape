#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "list.h"


struct song_node * insert(struct song_node *head, char pname[100], char partist[100]) {
  struct song_node *new_song = malloc(sizeof(struct song_node));
  strncpy(new_song->name,pname,100);
  strncpy(new_song->artist,partist,100);
  new_song->next = NULL;

  if (head == NULL) {
    return new_song;
  }
  if (songcmp(new_song,head) <= 0) {
    new_song->next = head;
    return new_song;
  }
  struct song_node *prev = head;
  struct song_node *cur = head->next;
  while (cur != NULL) {
    if (songcmp(new_song,cur) <= 0) {
      if (songcmp(new_song,cur) != 0) {
        new_song->next = cur;
        prev->next = new_song;
      }
      return head;
    }
    prev = cur;
    cur = cur->next;
  }
  prev->next = new_song;
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
  while(s->next) {
    char * name = s->name;
    char * artist = s->artist;
    printf("%s : %s | ", artist, name);
    s = s->next;
  }
  char * name = s->name;
  char * artist = s->artist;
  printf("%s : %s \n", artist, name);
  return;
}

struct song_node * find(struct song_node *head, char pname[100], char partist[100]) {
  struct song_node * cur = head;
  while (cur) {
    if (strcmp(cur->artist,partist)==0 && strcmp(cur->name,pname)==0) {
      return cur;
    }
    cur = cur->next;
  }
  return NULL;
}

struct song_node * find_first(struct song_node *head, char partist[100]) {
  struct song_node * cur = head;
  while (cur) {
    if (!strcmp(cur->artist, partist)) {
      return cur;
    }
    cur = cur->next;
  }
  return NULL;
}

struct song_node * random_node(struct song_node *head) {
  int randy = rand() % list_length(head);
  return get_node(head, randy);
}

struct song_node * remove_song(struct song_node *head, char pname[100], char partist[100]) {
  if (find(head,pname,partist) == NULL) return head;
  if (songcmp(find(head,pname,partist),head)==0) {
    struct song_node *temp = head->next;
    free(head);
    return temp;
  }
  struct song_node *prev = head;
  struct song_node *cur = head->next;
  while (songcmp(cur, find(head,pname,partist))) {
    prev=cur;
    cur=cur->next;
  }
  prev->next=cur->next;
  free(cur);
  return head;
}

struct song_node * free_list(struct song_node *head) {
  struct song_node *cur = head;
  while (cur) {
    struct song_node *nxt = cur->next;
    printf("Freeing %s : %s \n", cur->name, cur->artist);
    free(cur);
    cur = nxt;
  }
  return cur;
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
  // print_song(n1);
  // print_song(n2);
  int art_comp = strcmp(n1->artist, n2->artist);
  if (art_comp != 0) {
    return art_comp;
  }
  return strcmp(n1->name, n2->name);
}
