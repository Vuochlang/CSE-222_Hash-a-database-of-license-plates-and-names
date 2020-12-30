#include "all.h"

int hashsize=100;//set default hashsize as 100 if user did not input anything for the size

void hashAdd(hashEntry* hashTable, char *platenumber, char* firstname, char* lastname)//add the given information to the hashTable
{       int plateindex=0;
        plateindex=hashplate(platenumber);//get the index for the hashTable from hashplate function
        listAdd(hashTable[plateindex],platenumber,firstname,lastname);//add the given information to the hashTable with the index
}

void hashLoad(hashEntry *hashTable)//count the length of every hashTable
{       hashEntry currentTable, temp;
        int count=0;
        for(int i=0; i<hashsize; i++)
        {       printf("Entry %d: length=%d\n",i,listLen(hashTable[i]));//called listLen to count the length of each hashTable
        }
}

int hashFind(hashEntry* hashTable, char*plate, char*first, char*last)//find the given plate number
{       int plateindex=hashplate(plate);//get the index from hashplate
        int result=listFind(hashTable[plateindex],plate,first,last);//give te index and find the exact plate in the hashTable[index]
        if(result==1)//if the plate is found
        return 1;
        if(result==0)//if the plate is not found
        return 0;
}

void hashDump(hashEntry* hashTable, int cellnum)//dump the content of the hashTable
{       hashEntry temp;
        if(cellnum==-1)//if user did not given a specific number to dump
        {       for(int i=0; i<hashsize; i++)//dump every hashTable
                {       printf("Contents of cell %d \n",i);
                        listPrint(hashTable[i]);
                }
                return;
        }
        else//if user give a specific number to dump
        {       printf("Contents of cell %d \n",cellnum);
                listPrint(hashTable[cellnum]);
        }
}

int hashplate(char *plate)//hash the plate with the given formula and the given hashsize to return an index to store in the hashTable
{       int platelen=0;
        int index=0, sum=0, i=0;
        while(plate[i]!='\0')//loop to go through each character of the plate and add everything up to NULL
        {       sum=sum+((i+5)*(plate[i]));
                i++;
        }
        index=sum%hashsize;
return(index);
}

void hashFree(hashEntry* hashTable)
{       for(int i=0; i<hashsize; i++)//loop to go through each hashTable
        {       listFree(hashTable[i]);//free the given hashTable
        }
        free(hashTable);
}

hashEntry* hashInit(int Size)//initializing the hashTable with the given hashsize
{       hashsize=Size;
	hashEntry* hashTable=malloc(hashsize*(sizeof(hashEntry)));
        for(int i=0; i<hashsize; i++)
        {       hashTable[i]=listInit();//initializing the sentinel node for each table
                hashTable[i]->plate=0;
                hashTable[i]->next=NULL;
        }
return (hashTable);
}

