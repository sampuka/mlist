#include "mlist.h"

#include <stdio.h>
#include <stdlib.h>

void printint(void* data)
{
    printf("%d\n", *((int*)data));
}

void freeall(void* data)
{
    free(data);
}

int main()
{
    struct mlist *intlist = NULL;
    int *temp;

    temp = malloc(sizeof *temp);
    *temp = 7;
    mlist_prepend(&intlist, temp);

    temp = malloc(sizeof *temp);
    *temp = 8;
    mlist_prepend(&intlist, temp);

    temp = malloc(sizeof *temp);
    *temp = 9;
    mlist_prepend(&intlist, temp);
    
    printf("list is %d elements long\n", mlist_length(intlist));
    
    int len = mlist_length(intlist);

    for(int i = 0; i < len; i++)
    {
	printf("intlist[%d] = %d\n", i, *(int*)mlist_index(intlist, i));
    }

    temp = malloc(sizeof *temp);
    *temp = 1;
    mlist_append(intlist, temp);

    temp = malloc(sizeof *temp);
    *temp = 2;
    mlist_append(intlist, temp);

    temp = malloc(sizeof *temp);
    *temp = 3;
    mlist_append(intlist, temp);

    mlist_map(intlist, &printint);
    
    printf("list is %d elements long\n", mlist_length(intlist));

    free(mlist_remove(intlist, 1));

    mlist_map(intlist, &printint);

    free(mlist_pop(intlist));
    free(mlist_pop(intlist));

    mlist_map(intlist, &printint);

    mlist_map(intlist, &freeall);

    mlist_destroy(&intlist);

    return 0;
}
