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
void song_delete(char pname[100], char partist[100]);
// Shuffle
void shuffle();
// Clear library
void clear_library();
// Print (entries under certain letter)
void print_letter(char c);
void print_letterlist(int i);
// Print songs of artist
void print_songs(char partist[100]);
// Print entire library
void print_library();
// search song given song and artist name
void search_song(char pname[100], char partist[100]);
// search for an artist
void search_artist(char partist[100]);
// helper functions
int artistindex(char partist[100]);

#endif
