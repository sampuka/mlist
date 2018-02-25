#include "mlist.h"

#include <stdlib.h>
#include <stdio.h>

void mlist_prepend(struct mlist **list, void *data)
{
    struct mlist *newnode = malloc(sizeof (struct mlist));

    newnode->next = *list;

    newnode->data = data;

    *list = newnode;
}

void mlist_append(struct mlist *list, void *data)
{

    struct mlist *newnode = malloc(sizeof (struct mlist));
    newnode->data = data;

    newnode->next = NULL;

    struct mlist *cursor = list;

    while(cursor->next != NULL)
	cursor = cursor->next;

    cursor->next = newnode;
}

void mlist_map(struct mlist *list, void (*func)(void*))
{
    while(list != NULL)
    {
	func(list->data);
	list = list->next;
    }
}

int mlist_length(struct mlist *list)
{
    int count = 0;
    while(list != NULL)
    {
	list = list->next;
	count++;
    }

    return count;
}

void* mlist_index(struct mlist *list, int index)
{
    if (index < 0)
    {
	printf("mlist_index error: index is negative\n");
	return NULL;
    }

    if (index >= mlist_length(list))
    {
	printf("mlist_index error: out of bounds\n");
	return NULL;
    }
    
    while(index--)
    {
	list = list->next;
    }
    return list->data;
}

void* mlist_remove(struct mlist *list, int index)
{
    if (index < 0)
    {
	printf("mlist_remove error: index is negative\n");
	return NULL;
    }

    if (index >= mlist_length(list))
    {
	printf("mlist_remove error: out of bounds\n");
	return NULL;
    }
    
    struct mlist *cursor = list;

    index--;
    while(index--)
    {
	cursor = cursor->next;
    }
    
    struct mlist *todel = cursor->next;
    void *toreturn = todel->data;
    cursor->next = cursor->next->next;
    free(todel);
    return toreturn;
}

void* mlist_pop(struct mlist *list)
{
    return mlist_remove(list, mlist_length(list)-1);
}

void mlist_destroy(struct mlist **list)
{
    int len = mlist_length(*list);

    for (int i = 0; i < len-1; i++)
    {
	mlist_pop(*list);
    }

    (*list) = NULL;
}
