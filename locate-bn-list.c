/**
 * @file locate-bn-list.c
 * @brief describe how to find the bottom n in single link list.
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
 * @brief locate_bn_list - find the position of bottom n node.
 * @param phead pointer to the head of list.
 * @param n the bottom number.
 * @return the pointer to the node which we need.
 *
 * use two pointer to get this realized, first make pointer p1 to
 * move n steps, then make p1 point to the first node (not the
 * head node), and then make p1 and p2 move synchronously until
 * the list's end.
 */
ps_list locate_bn_list( ps_list phead, int n )
{
	ps_list p1 = phead->next;
	ps_list p2;
	int i = 0;

	for ( ; p1 && (i < n-1); ) {
		i++;
		p1 = p1->next;
	}
	i++;
	if ( (!p1) || (i != n) ) {
		printf("The number %d is not in a correct scope.\n", n);
		return NULL;
	}
	
	p2 = phead->next;
	for ( ; p1->next ; ) {
		p1 = p1->next;
		p2 = p2->next;	
	}

	return p2;
}

int
main()
{
	ps_list p = NULL;
	ps_list pt = NULL;
	
	create_list1( &p, 10);
	tranverse_list( p );
	pt = locate_bn_list( p, 11);
	if( pt ) {
		printf("%d.\n",pt->data);
	}	

	return 0;
}
