/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Name: 		VUOCHLANG CHANG										                                                //
//	Class: 		CSE 222	WINTER 2020									                                                //
//	Assignment:	PA3 - PLATE										                                                    //
//	Date: 		2/13/2020										                                                    //
//	Description:	This code will read an existing file from the user and add the data into the hashTable 	        //
//			seperating by the index of the table. Each index of the table will act as the sentinel 	                //
//			node that point to the list(s). User can interact with the program by typing:		                    //
//				*DUMP-----to see all the data in the hashTable					                                    //
//				*DUMP n---to see the data in the hashTable at the index(n)			                                //
//				*LOAD-----to see the legnth of each hashTable					                                    //
//				(PLATE)---to see the owner of the plate(PLATE)				 	                                    //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
        char *plate;
        char *first;
        char *last;
        struct node *next;
        };

typedef struct node* hashEntry;

hashEntry * hashInit(int);
struct node* listInit();
int hashplate(char *);
void hashAdd(hashEntry*, char*, char*, char*);
void listAdd(struct node*, char*, char*, char*);
void hashDump(hashEntry *, int);
int hashFind(hashEntry*, char*, char*, char*);
int listFind(struct node*, char*, char*, char*);
void hashFree(hashEntry*);
void hashLoad(hashEntry*);
int listLen(struct node *);
void listPrint(struct node *);
void listFree(struct node *);

