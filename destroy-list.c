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

void
destroy_list( ps_list *p)
{
	ps_list pl = *p;
	ps_list pa = NULL;

	for ( ;pl; ) {
		/*
		 * the dangerous way to free the memory space.
		 */
/*
		printf("before free:0x%p.\n", pl);
		free( pl );
		printf("after free1:0x%p.\n", pl);
		pl = pl->next;
		printf("after free2:0x%p.\n", pl);
*/
		/*
		 * the right way to free the node memory space.
		 */
		printf("before free1:pl-0x%p,pa-0x%p.\n", pl, pa);
		pa = pl->next;
		printf("before free2:pl-0x%p,pa-0x%p.\n", pl, pa);
		free( pl );
		printf("after  free1:pl-0x%p,pa-0x%p.\n", pl, pa);
		pl = pa;
		printf("after  free2:pl-0x%p,pa-0x%p.\n", pl, pa);
	}
	*p = NULL;

	return;
}

int
main()
{
	ps_list p = NULL;
	
	create_list1( &p, 4);

	destroy_list( &p );

	return 0;
}
