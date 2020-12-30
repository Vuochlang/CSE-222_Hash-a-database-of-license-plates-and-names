#include "all.h"

extern int hashsize;

int main(int argc, char **argv)
{       char str[100],plate[100], firstname[100], lastname[100];  //initializing variables
        int returnvalue=0;
        int plateindex=0;
        char command[100], extra[100];
        int e=0, num=0;
        FILE *fp;
        
//check if user type in the valid input
	if(argc==1)//exit the program is there's not enough given arguments
        {       printf("Usage: %s database [hashsize]\n",argv[0]);
                        return 1;
        }
        else if(argc==2)//check if the given file is able to open to read or not, and exit the program if can't read
        {       hashsize=100;
                fp=fopen(argv[1],"r");
                if(fp==NULL)
                {       printf("Error: cannot open %s\n",argv[1]);
                        return 1;
                }

        }
        else if(argc==3)//check if the given arguments is valid
        {       fp=fopen(argv[1],"r");
                if(fp==NULL)//check and exit the progam if can't read the file
                {       printf("Error: cannot open %s\n",argv[1]);
                        return 1;
                }

                returnvalue=sscanf(argv[2],"%d",&hashsize);
                if(returnvalue==1 && hashsize<1)//check and exit if the given hashsize is not valid
                {       printf("ERROR: Hashsize should be at least 1\n");
                        fclose(fp);
                        return 1;
                }
                if(returnvalue!=1)
                {       printf("Usage: %s database [hashsize]\n",argv[0]);
                        fclose(fp);
                        return 1;
                }
        }
        else//if the user enter more arguments that 3
        {       printf("Usage: %s database [hashsize]\n",argv[0]);
                return 1;
        }

        hashEntry *hashTable=hashInit(hashsize);//initializing the hashTable with the given hashsize or the default(100) 
        while(fgets(str,100,fp)!=NULL)//loop to go through the given file and read line by line
        {       sscanf(str,"%s%s%s",plate,firstname,lastname);//read input into correct place
                hashAdd(hashTable,plate,firstname,lastname);//add data into the hashTable
        }
        fclose(fp);//close the given file after it reaches the end of the file

        printf("Enter command or plate: ");//start asking user to input command

        while(fgets(str,100,stdin)!=NULL)//while the user does not type ctrl+D which will return NULL to fgets
        {       e=0;
                e=sscanf(str,"%s%s%d",command,extra,&num);//read command from user
                if(e==2)
                {       if(strcmp(command,"*DUMP")==0 && str[5]==' ' && str[6]!=' ')//if user type *DUMP followed by one space and sth afterward
                        {       if(sscanf(str,"*DUMP %d", &num)==1)//if user input number after the one space
                                {       if(num>-1 && num<hashsize)//if the number is between hashsize range
                                        {       hashDump(hashTable,num);//dump the content of that specific hashTable
                                        }
                                        else//print error if user input number outside of the range
                                        {       printf("ERROR: cell must be between 0 and %d\n", hashsize-1);
                                        }
                                }
                                else//if instead of number, user input character or symbol after the one space
                                printf("Plate Not Found\n");
                        }
                        else//if the command is not *DUMP
                        {       printf("Plate Not Found\n");
                        }
                }
                else if(e==1)
                {       if(strcmp(command,"*DUMP")==0 && str[5]=='\n')//if user type *DUMP and ENTER key followed by that
                        {
                                        hashDump(hashTable,-1);//dump the contents of all hashTable
                        }
                        else if(strcmp(command,"*LOAD")==0 && str[5]=='\n')//if user type *LOAD and ENTER key followed by that
                        {              hashLoad(hashTable);
                        }
                        else if(hashFind(hashTable,command,firstname,lastname)==1 && str[7]=='\n')//if user type in a valid plate number
                        {       plateindex=hashplate(command);//find the index of the hashTable with that plate
                                hashEntry current,new;
                                current=hashTable[plateindex];
                                new=current->next;
                                while(strcmp(command,new->plate)!=0)//go through the list to find the exact plate
                                {       new=new->next;
                                }
                                printf("First name: %s \n",new->first);//print the name of that plate
                                printf("Last name: %s \n",new->last);
                        }
                        else//print error if the command does not meet any of the above statements
                        printf("Plate Not Found\n");
                }
                else//print error if it does not scan anything with the given format
                printf("Plate Not Found\n");
                printf("Enter plate: ");//ask user to enter again
        }
        hashFree(hashTable);//free all the memory befoer exit the program
        printf("\nFreeing memories\n");
return 0;
}

