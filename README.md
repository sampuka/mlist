# mlist
Simple generic linked list for C
This is meant to be for personal usage in other C projects of mine, however anyone can use it as they wish.

# Dependencies
idk, makefile uses -std=c99

# Introduction
I made this to have a linked list in C. 
The nodes's data is a void pointer to whatever. This means that the linked list does not make a copy of the thing it contains. I use this in conjunction with dynamic memory. I malloc something, and save the pointer in the linked list.

If you actually cared to test this, I would be surprised if you didn't find a lot of bugs.

# Documentation
To create a linked list you do

struct mlist *head = NULL;

Congratulations you now have an empty list.

mlist_append takes a pointer to your linked list and a pointer to store in the new node.

mlist_append(&head, malloc(sizeof int));

figure out mlist_prepend yourself ;)

You can index with mlist_index, with warning printed to stdout in case of index range error

mlist_index(head, 6);

mlist_length returns the length of the list

mlist_length(head);

mlist_remove removes an element from the list and returns the data pointer.

mlist_remove(&head, 4);

mlist_pop(&head); performs remove on the last element

mlist_destroy(&head) destroys the list but will not free any data pointers

mlist_map() will perform a function to all data pointers of a list.

void freeptr(void *data)
{
	free(data);
}

mlist_map(head, &freeptr); will free all data pointers in the list, useful for dynamic memory before doing mlist_destroy(&head);

