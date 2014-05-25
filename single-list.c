#include <stdio.h>
#include <stdlib.h>

/**
 * @brief define the single list and it's basic oprations
 *
 * the list has a head node as a guard. 
 */
typedef struct _single_list {
	int data;
	struct _single_list *next;
}s_list, *ps_list;

void init_list( ps_list *p);
int is_empty( ps_list p);
void clear_list( ps_list p);
int length_list( ps_list p);
int is_enum_exist( ps_list p, int e);
void insert_list( ps_list p, int e);
void delete_list( ps_list p, int e);

/**
 * @brief init_list - initialize the list.
 * @param p the pointer to list head.
 * @return none.
 *
 * once initialized, the head pointer is stored in p.
 */
void
init_list( ps_list *p)
{
	ps_list *phead;

	phead = (ps_list) malloc( sizeof(s_list) );
	if ( !phead ) {
		printf("There is not enough memory space.\n");
		return;
	}
	phead->data = 0;
	phead->next = NULL;

	p = &phead;

	return;
}

/**
 * @brief is_empty - check whether the list is empty.
 * @param p the pointer to list head. 
 * @return 1 for empty.
 *	   0 for not empty.
 */
int
is_empty( ps_list p )
{
	if ( p->next )
		return 0;
	return 0;
}

/**
 * @brief clear_list - free all the space of list.
 * @param p the pointer to the list head.
 * @return none.
 */
void
clear_list( ps_list p )
{
	ps_list q = p->next;
	
	while ( p ) {
		free( p );
		p = q;
		q = q->next;
	}

	p = NULL;

	return;
}

/**
 * @brief length_list - calculate the length of the list.
 * @param p the pointer to the list head.
 * @return the length of list. 
 */
int
length_list( ps_list p )
{
	ps_list pl = p->next;
	int length = 0;

	for ( ; pl; ) {
		length++;
		pl = pl->next;
	}

	return length;
}

/**
 * @brief is_enum_exist - check out whether the data is existed.
 * @param p the pointer to the list head.
 * @param e the data enum of the list.
 * @return  1 for existence
 *	    0 for no existence
 */
int
is_enum_exist( ps_list p, int e)
{
	ps_list pl = p->next;
	for(;pl;) {
		if ( e == pl->data ) 
			return 1
		pl = pl->next;
	}

	return 0;
}

/**
 * @brief insert_list - insert a enum into the list.
 * @param p pointer to the list head.
 * @param e the enum to insert.
 * @return none.
 */
void
insert_list( ps_list p, int e)
{
	ps_list pl = p->next;
	ps_list pb = p;
	ps_list pc = NULL;

	/*
	 * indicate the list enum is ascended
	 */
	for(;pl;) {
		if ( pl->data <= e ) {
			pb = pl;
			pl = pl->next;
		} else {
			pc = (ps_list)malloc( sizeof(s_list) );
			if ( !pc ) {
				printf("No Memory!\n");
				return;
			}
			pc->data = e;
			pc->next = pl;
			pb->next = pc;
			return;
		}
	}
	/*
	 * insert opration is at the end of the list.
	 */
	pc = (ps_list)malloc( sizeof(s_list) );
	if ( !pc ) {
		printf("No Memory!\n");
		return;
	}
	pc->data = e;
	pc->next = pl;	/* pl == NULL */
	pb->next = pc;
	
	return;
}

/**
 * @brief delete_list - delete the node of list.
 * @param p pointer to the list head.
 * @param e the enum to insert.
 * @return none.
 */
void
delete_list( ps_list p, int e)
{
	ps_list pl = p->next;
	ps_list pb = p;

	for ( ;pl; ) {
		if ( pl->data != e ) {
			pb = pl;
			pl = pl->next;
		} else {
			pb = pl->next;
			if ( pl )
				free( pl );
			pl = NULL;
			return;
		}
	}
	printf("enum %d didn't exist.\n", e);

	return;
}
