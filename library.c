#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "list.h"
#include "library.h"

void insert_song(char pname[100], char partist[100]) {
  int binnum = artistindex(partist);

  if(table[binnum]){
    table[binnum] = insert(table[binnum], pname, partist);
    return;
  }
  else {
    struct song_node * new = malloc(sizeof(struct song_node));
    new = NULL;
    table[binnum] = insert(new, pname, partist);
    // print_list(table[binnum]);
    return;
  }
}

void search_song(char pname[100], char partist[100]) {
  int binnum = artistindex(partist);
  if(find(table[binnum],pname,partist)) {
    printf("Song found! \n");
    print_song(find(table[binnum],pname,partist));
  }
  else {
    printf("Song not found! \n");
  }
}

void search_artist(char partist[100]) {
  int binnum = artistindex(partist);
  struct song_node *first = find_first(table[binnum],partist);
  if (first) {
    printf("artist found!\n" );
    print_list(first);
  }
  else {
    printf("artist not found!\n" );
  }
}

void print_letter(char c) {
  int i = c - 'A';
  if (table[i]) {
    printf("%c \n", 'A' + i);
    print_list(table[i]);
  }
}

void print_letterlist(int i) {
    if (table[i]) {
      printf("%c \n", 'A' + i);
      print_list(table[i]);
    }
  // printf("%s \n", c);
}

void print_songs(char partist[100]) {
  int binnum = artistindex(partist);
  struct song_node *cur = find_first(table[binnum],partist);
  while (cur && strcmp(cur->artist,partist)==0) {
    print_song(cur);
    cur = cur->next;
  }
}

void print_library() {
  for (int i = 0; i < 27; i++) {
    print_letterlist(i);
  }
}

void shuffle() {
  int counter = 0;
  while (counter < 6) {
    int randbin = (rand()) % 27;
    // printf("random number: %d\n", randbin);
    if (table[randbin]) {
      print_song(random_node(table[randbin]));
      counter++;
    }
  }
}

void song_delete(char pname[100], char partist[100]) {
  int binnum = artistindex(partist);
  table[binnum] = remove_song(table[binnum],pname,partist);
}

void clear_library() {
  for (int i = 0; i < 27; i++) {
    table[i]=free_list(table[i]);
  }
}


int artistindex(char partist[100]) {
  int num = 0;

  if(partist[0] - 'A' > 25){
    num = 26;
  }

  return partist[0] - 'A';
}
