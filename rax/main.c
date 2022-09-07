#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <math.h>

#include "rax.h"

/* We are going to write a simple code to test the different functions written in rax.c */

int main()
{
    rax *rt = raxNew();
    void *data;
    printf("********************Main Menu********************\n");
    printf("1. Insert an element\n");
    printf("2. Delete an element\n");
    printf("3. Research an element\n");
    printf("4. Visualize\n");

    int choix;
    char tnp = 'o';
    int test;
    char insert[1000];
    char supress[1000];
    char search[1000];
    
    do{ 
        printf("Please enter yoour choice : ");
        scanf("%d", &choix);

        switch (choix)
        {  
            case 1:
                printf("\nEnter the string to be insert : ");
                scanf("%s", &insert);
                test = raxInsert(rt,(unsigned char*)insert,strlen(insert),NULL,NULL);
                if (test == 1)
                {
                    printf("\n%s has been inserted!\n", insert);
                    printf("Insertion succeed!\n");
                }
                else
                {
                    //printf("\n%s has not been inserted!\n", insert);
                    printf("\nInsertion failed...\n");
                }
                break;
            case 2:
                printf("\nEnter the string to be deleted : ");
                scanf("%s", &supress);
                test = raxRemove(rt, supress, strlen(supress), NULL);
                if (test == 1)
                {
                    printf("\n%s has been supressed!\n", supress);
                    printf("Supression succeed\n!");
                }
                else
                {
                    printf("\n%s has not been supressed!\n", supress);
                    printf("Supression failed!\n");
                }
                break;
            case 3:
                printf("\nEnter the string to be searched : ");
                scanf("%s", &search);
                data = raxFind(rt,search, strlen(search));
                if (data == raxNotFound) {
                    printf("\n%s, is not in the tree\n", search);
                }
                else {
                    printf("\n%s, is in the tree\n", search);
                }
                break;
                case 4:
                    raxShow(rt);
                    break;
            default:
                break;
        }
        printf("Do you want  to continue? y/n : ");
        scanf("%s", &tnp);
    } while (tnp == 'y');

    return 0;
}