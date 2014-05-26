/**
 * @file reverse-list.c
 * @brief describe the way to reverse the single link list.
 * @author watertiger <darkwkt@gmail.com>
 * @date 2014-05-25
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
		printf("%-4d", p->data);
		p->next = (*phead)->next;
		(*phead)->next = p;
	}
	printf("\n");

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
 * @brief reverse_list - the realization of reverse opration.
 * @param phead pointer to the head of list.
 * @return none.
 */
void
reverse_list( ps_list phead)
{
	ps_list pb = NULL, pc, pa;
	
	if ( !phead->next ) {
		printf("List is empty.\n");
		return;
	}
	pc = phead->next;

	for ( ; pc; ) {
		pa = pc->next; /* save the latter node pointer */
		pc->next = pb; /* modify its following node,pointer to the former node */
		pb = pc; /* move the former node pointer to current node */
		pc = pa; /* move current node pointer to the latter one */
	}
	
	phead->next = pb;

	return;
}

int
main()
{
	ps_list p = NULL;
	
	create_list1( &p, 4);
	tranverse_list( p );
	reverse_list( p );
	tranverse_list( p );

	return 0;
}
