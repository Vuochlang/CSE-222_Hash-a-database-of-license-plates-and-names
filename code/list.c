#include "all.h"

struct node *listInit()//malloc spaces and return a sentinel node
{       struct node* sentinel=malloc(sizeof(struct node));
        return (sentinel);
}

void listFree(struct node*sent)//go through the list of the given sentinel to free everything
{       struct node *current;
        struct node*new=sent->next;
        while(new!=NULL)
        {       current=new;
                free(current->plate);
                free(current->last);
                free(current->first);
                free(current);
                new=new->next;
        }
        free(new);
        free(sent);
}

void listAdd(struct node* sentinel, char *platenumber, char* firstname, char* lastname)//add the given data to the given sentinel
{       hashEntry temp;
        temp=malloc(sizeof(struct node));//malloc spaces to store the given data
        if(sentinel->next!=NULL)//if the sentinel does not point to NULL, add the temp node after sentinel and let temp points to what sentinel points to
        {       temp->next=sentinel->next;
                sentinel->next=temp;
        }
        else//if sentinel points to NULL, let sentinel points to temp
        {
        temp->next=NULL;
        sentinel->next=temp;
        }
        temp->plate=malloc(sizeof(platenumber));//malloc space and copy the given string into the temp node
        strcpy(temp->plate,platenumber);
        temp->first=malloc(sizeof(firstname));
        strcpy(temp->first,firstname);
        temp->last=malloc(sizeof(lastname));
        strcpy(temp->last,lastname);

}

void listPrint(struct node*sent)//go through list in the given sentinel to print out the plate, firstname and lastname of each node 
{       struct node *temp;
        temp=sent->next;
        while(temp!=NULL)
        {       printf("Plate: <%s>  ",temp->plate);
                printf("Name: %s, ",temp->last);
                printf("%s\n", temp->first);
                temp=temp->next;
        }
        printf("--------------------------------------------\n");
}

int listFind(struct node* sentinel,char*plate, char* first, char*last)//go through the list in the sentinel to find the exact plate number and get the name
{       struct node*temp=sentinel->next;
        if(temp==NULL)
        return 0;
        while(temp!=NULL)
        {       if(strcmp(plate,temp->plate)==0)
                {       first=temp->first;
                        last=temp->last;
                        return 1;
                }
                temp=temp->next;
        }
return 0;
}

int listLen(struct node*sentinel)//run through the given sentinel to count how many list are there
{       int count=0;
        struct node* temp;
        temp=sentinel->next;
        while(temp!=NULL)
        {       count++;
                temp=temp->next;
        }
return count;
}

