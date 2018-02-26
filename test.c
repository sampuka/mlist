#include "mlist.h"

#include <stdio.h>
#include <stdlib.h>

void printint(void* data)
{
    printf("%d", *((int*)data));
}

void printall(mlist head)
{
    printf("length %d: ", mlist_length(head));
    mlist_map(head, &printint);
    printf("\n");
}

void freeall(void* data)
{
    free(data);
}

int main()
{
    mlist intlist = NULL;
    int *temp;

    for (int i = 0; i < 10; i++)
    {
	temp = malloc(sizeof *temp);
	*temp = i;
	mlist_append(&intlist, temp);
    }

    printall(intlist);

    free(mlist_remove(&intlist, 0));

    free(mlist_remove(&intlist, 5));

    printall(intlist);

    printf("intlist[4] = %d\n", *(int*)mlist_index(intlist, 4));

    mlist_map(intlist, &freeall);
    mlist_destroy(&intlist);

    printall(intlist);

    printf("head = %p\n", intlist);

    return 0;
}
