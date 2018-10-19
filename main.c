#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "list.h"
#include "library.h"


int main() {
  srand( time(NULL));
  struct song_node * head = malloc(sizeof(struct song_node));
  head = NULL;

  printf("==============================================\n LINKED LIST TESTS \n==============================================\n");
  printf("Inserting in the front: Alex Sensation -- Que Va \n");
  printf("Printing list \n");
  head = insert_front(head,"Que Va","Alex Sensation");
  // print_song(head);
  print_list(head);
  printf("==============================================\n");

  printf("Inerting in alphabetical order: Weezer -- Buddy Holly && Cage The Elephant -- Mess Around\n");
  head = insert(head,"Buddy Holly","Weezer");
  print_list(head);

  head = insert(head, "Mess Around", "Cage The Elephant");
  print_list(head);
  printf("==============================================\n");

  struct song_node * searched = find(head,"Buddy Holly", "Weezer");
  printf("Searching for Buddy Holly -- Weezer (exists): ");
  print_song(searched);
  searched = find(head,"Whoa", "Gottem");
  printf("Searching for Whoa -- Gottem (does not exist): ");
  print_song(searched);
  printf("==============================================\n");

  printf("\nAdding a few more songs...\n");
  head = insert(head,"Mexican Fender","Weezer");
  head = insert(head,"Amarillion","Datarock");
  head = insert(head, "Kvish Hachof", "Static and Bel El Tavori");
  head = insert(head,"Ready To Go","Republica");
  head = insert(head, "Tudo Bom", "Static and Bel El Tavori");

  print_list(head);
  printf("==============================================\n");
  printf("Testing find_first (Weezer) ");
  print_song(find_first(head,"Weezer"));

  printf("\n");
  printf("Testing find_first (Cage The Elephant) ");
  print_song(find_first(head,"Cage The Elephant"));
  printf("==============================================\n");
  printf("Testing song comparison on: (Tudo Bom -- Static and Bel El Tavori) and (Kvish Hachof -- Static and Bel El Tavori)\n");
  struct song_node * comp1 = malloc(sizeof(struct song_node));
  comp1 = find(head, "Tudo Bom", "Static and Bel El Tavori");
  struct song_node * comp2 = malloc(sizeof(struct song_node));
  comp2 = find(head, "Kvish Hachof", "Static and Bel El Tavori");
  printf("Result (Should be 9): %d \n", songcmp(comp1, comp2));

  printf("\nTesting song comparison on randomly chosen songs: \n" );
  comp1 = random_node(head);
  comp2 = random_node(head);
  print_song(comp1);
  print_song(comp2);
  printf("Result: %d \n", songcmp(random_node(head), random_node(head)));


  printf("==============================================\n");
  printf("Retrieving a random song from the list: ");
  print_song(random_node(head));
  printf("\n" );
  printf("Retrieving another random song from the list: ");
  print_song(random_node(head));
  printf("==============================================\n");

  printf("Removing Que Va : Alex Sensation \n");
  head =remove_song(head,"Que Va","Alex Sensation");
  print_list(head);
  printf("Removing Ready To Go : Republica \n");
  head =remove_song(head,"Ready To Go","Republica");
  print_list(head);
  printf("==============================================\n");

  printf("Freeing list \n");
  head = free_list(head);
  printf("List after free_list: \n");
  print_list(head);

  printf("\n");
  printf("==============================================\n LIBRARY TESTS \n==============================================\n");

  // struct song_node * table[27];
  insert_song("Busy Earnin'","Jungle");
  insert_song("Uproar","Lil' Wayne");
  insert_song("I Won't Back Down","Tom Petty");
  insert_song("You Don't Know How It Feels","Tom Petty");
  insert_song("True Stories","Datarock");
  insert_song("Caroline","Amine");
  insert_song("Give My Heart A Little Break","Summer Salt");
  insert_song("Again","Lenny Kravitz");


  // printf("%d", sizeof(table[0]));
  printf("Testing print library: \n");
  print_library();

printf("==============================================\n");
  printf("Testing print_letter (T): \n");
  print_letter('T');
  printf("\n");

  printf("Testing print_letter (L): \n");
  print_letter('L');
  printf("==============================================\n");

  printf("Testing search artist (Tom Petty) \n");
  search_artist("Tom Petty");

  printf("Testing search artist (Mr. DW) \n");
  search_artist("Mr. DW");

  printf("==============================================\n");
  printf("Testing find song (Caroline -- Amine) \n");
  search_song("Caroline", "Amine");
  printf("Testing find song (My Song -- Me) \n");
  search_song("My Song", "Me");

  printf("==============================================\n");
  printf("Testing print artist (Tom Petty) \n");
  print_songs("Tom Petty");
  printf("\n");
  printf("Testing print artist (Me) [should be none]\n");
  print_songs("Me");
  printf("==============================================\n");
  printf("Testing shuffle \n");
  shuffle();
  printf("\n");

  printf("Testing shuffle again\n");
  shuffle();

  printf("==============================================\n");
  printf("Deleting song (Caroline -- Amine) \n");
  song_delete("Caroline", "Amine");

  printf("Deleting song (You Don't Know How It Feels -- Tom Petty) \n");
  song_delete("You Don't Know How It Feels", "Tom Petty");

  printf("\n");
  printf("Printing changed library: \n");
  print_library();

  printf("==============================================\n");
  printf("Clearing (Freeing) Library \n");
  clear_library();
  printf("\n");

  printf("Printing library (should be empty) \n");
  print_library();

  // print_song(search_song("s120","aa"));
  // search_artist("a");
  // search_artist("ba");
  // print_letterlist("a");
  // print_songs("a");
  // print_library();
  // printf("Testing shuffle \n");
  // shuffle();
  // song_delete("s120","aa");
  // print_library();
  // clear_library();
  // print_library();
  //
  // printf("\n\nTHINGS STILL NEEDED TO BE DONE:\n" );
  // printf("Shuffle, check insert_song, valid print tests\n" );

  return 0;
}
