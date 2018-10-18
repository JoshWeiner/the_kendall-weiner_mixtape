#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "library.h"

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

void print_letter(char c[1]) {
  int binnum = 0;
  for (int i = 0; i < sizeof(letters)/sizeof(char); i++) {
    if (strcmp(c,&letters[i]) < 0) break;
    binnum++;
  }
  print_list(table[binnum]);
}


int artistindex(char partist[100]) {
  int n = 0;
  for (int i = 0; i < sizeof(letters)/sizeof(char); i++) {
    if (strcmp(partist,&letters[i]) < 0) break;
    n++;
  }
  return n;
}
