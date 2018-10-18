#ifndef LIBRARY_H
#define LIBRARY_H
#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song_node * table[27];

// Insert song
void insert_song(char pname[100], char partist[100]);
// Delete song
// Shuffle
// Clear library
// Print (entries under certain letter)
void print_letter(char c[1]);
// Print songs of artist
// Print entire library
// search song given song and artist name
struct song_node * search_song(char pname[100], char partist[100]);
// search for an artist
void search_artist(char partist[100]);
// helper functions
int artistindex(char partist[100]);

#endif
