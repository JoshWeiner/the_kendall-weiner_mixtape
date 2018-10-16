#ifndef LIST_H
#define LIST_H

struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

void insert_node (struct song_node *s, struct song_node *head);

// print artist's song
// insert at front
// insert alphabetical



#endif
