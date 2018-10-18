#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "library.h"
#include <time.h>

char letters[] = "abcdefghijklmnopqrstuvwxyz";



void insert_song(char pname[100], char partist[100]) {
  int binnum = artistindex(partist);

  table[binnum] = insert(table[binnum],pname,partist);
}

struct song_node * search_song(char pname[100], char partist[100]) {
  int binnum = artistindex(partist);
  return find(table[binnum],pname,partist);
}

void search_artist(char partist[100]) {
  int binnum = artistindex(partist);
  struct song_node *first = find_first(table[binnum],partist);
  if (first) {
    printf("artist not found!\n" );
  }
  else {
    printf("artist found!\n" );
  }
}

void print_letterlist(char c[1]) {
  int binnum = 0;
  for (int i = 0; i < sizeof(letters)/sizeof(char); i++) {
    if (strcmp(c,&letters[i]) < 0) break;
    binnum++;
  }
  print_list(table[binnum]);
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
  // why is this in the wrong order?
  for (int i = 0; i < 27; i++) print_letterlist(&letters[i]);
}

// CURRENTLY NOT FUNCTIONING
void shuffle() {
  srand(time(NULL));
  int counter = 0;
  int randbin;
  while (counter < 5) { // could change if more songs
    randbin = rand() % 27;
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
  int n = 0;
  for (int i = 0; i < sizeof(letters)/sizeof(char); i++) {
    if (strcmp(partist,&letters[i]) < 0) break;
    n++;
  }
  return n;
}
