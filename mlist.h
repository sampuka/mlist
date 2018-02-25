#ifndef MLIST_H
#define MLIST_H

struct mlist
{
    struct mlist *next;
    void *data;
};

void mlist_prepend(struct mlist **list, void *data);

void mlist_append(struct mlist **list, void *data);

void mlist_map(struct mlist *list, void (*func)(void*));

int mlist_length(struct mlist *list);

void* mlist_index(struct mlist *list, int index);

void* mlist_remove(struct mlist **list, int index);

void* mlist_pop(struct mlist **list);

void mlist_destroy(struct mlist **list);

#endif
