/**
 * @file create-list.c
 * @brief describe two ways to create the single link list.
 * @author watertiger <darkwkt@gmail.com>
 * @date 2014-05-25
 */
#include <stdio.h>
#include <stdlib.h>

/* self defined head file */
#include "single_list.h"
/**
 * @brief create_list1 - creating list by insert each node at head.
 * @param phead pointer to the head of list.
 * @param n the number of nodes.
 * @return none.
 *
 * the way to create the list likes a stack, the latter node is 
 * is inserted before the formmer node. Of course, the head node
 * is always at first.
 */
void
create_list1 (struct _single_list **phead, int n)
{
	ps_list *p;
	int i;

	*phead = (ps_list)malloc( sizeof(s_list) );
	if( !(*phead) ) {
		printf("No memory for head node!\n");
		return;
	}
	(*phead)->next = NULL;
	
	srand(time(NULL));
	for ( i = 0; i < n; i++ ) {
		p = (ps_list)malloc( sizeof(s_list) );
		if( !p ) {
			printf("No memory for node.\n");
			return;
		}
		p->data = rand()%100+1;
		p->next = (*phead)->next;
		(*phead)->next = p;
	}

	return;
}

/**
 * @brief create_list1 - creating list by insert each node at tail.
 * @param phead pointer to the head of list.
 * @param n the number of nodes.
 * @return none.
 *
 * the way to create the list likes a queue, the latter node is 
 * is inserted after the formmer node. Of course, the head node
 * is always at first.
 */
void
create_list2 (struct _single_list **phead, int n)
{
	ps_list *p, *pt;
	int i;

	*phead = (ps_list)malloc( sizeof(s_list) );
	if( !(*phead) ) {
		printf("No memory for head node!\n");
		return;
	}
	(*phead)->next = NULL;
	
	pt = (*phead);
	srand(time(NULL));
	for ( i = 0; i < n; i++ ) {
		p = (ps_list)malloc( sizeof(s_list) );
		if( !p ) {
			printf("No memory for node.\n");
			return;
		}
		p->data = rand()%100+1;
		p->next = NULL;
		pt->next = p;
		pt = p;
	}

	return;
}

