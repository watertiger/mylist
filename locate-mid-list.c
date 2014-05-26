/**
 * @file locate-mid-list.c
 * @brief describe how to find the middle node in single link list.
 * @author watertiger <darkwkt@gmail.com>
 * @date 2014-05-26
 */
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
	ps_list p;
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
 * @brief tranverse_list - visit list node one by one.
 * @param phead pointer to the head of list.
 * @return none.
 */
void
tranverse_list( ps_list phead)
{
	ps_list p = phead->next;

	for( ; p ; ) {
		printf("%-4d", p->data);
		p = p->next;
	}
	printf("\n");

	return;
}

/**
 * @brief locate_mid_list - find the position of middle node.
 * @param phead pointer to the head of list.
 * @return the pointer to the node which we need.
 *
 * use two pointer to get this realized, make point p1 move one
 * step once, and make pointer p2 move 2 steps once. When p2 moves
 * to the end of the list, p1 point to the middle node needed.
 *
 * if the length of list is an odd, eg:3, then return the 2nd node 
 * pointer, otherwise it'a an even, eg:8, then return the 4th node
 * pointer of list.
 */
ps_list locate_mid_list( ps_list phead)
{
	ps_list p1 = phead;
	ps_list p2 = phead->next;
	for ( ; p2 ; ) {
		p1 = p1->next;
		if ( p2->next )
			p2 = p2->next->next;
		else
			p2 = NULL;	
	}

	return p1;
}

int
main()
{
	ps_list p = NULL;
	ps_list pt = NULL;
	
	create_list1( &p, 4);
	tranverse_list( p );
	pt = locate_mid_list( p );
	if( pt ) {
		printf("%d.\n",pt->data);
	}	

	return 0;
}
