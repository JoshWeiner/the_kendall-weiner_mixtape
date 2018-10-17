#ifndef LIST_H
#define LIST_H

struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

// returns new node
struct song_node * insert_front(struct song_node *head, char pname[100], char partist[100]);
// returns head
struct song_node * insert (struct song_node *head, char pname[100], char partist[100]);
void print_song(struct song_node *s);
struct song_node * find_song(char pname[100], char partist[100]);
struct song_node * find_first(char partist[100]);
void print_list(struct song_node *s);

struct song_node * get_node(struct song_node *head, int i);
int songcmp(struct song_node *n1, struct song_node *n2);
int list_length(struct song_node * head);
// print artist's song
// insert at front
// insert alphabetical



#endif
