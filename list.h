void insert_node (struct song *s, struct song *head);

struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

// print artist's song
// insert at front
// insert alphabetical
