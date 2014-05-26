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
 * @brief create_loop_list - create loop in a no-loop list.
 * @param phead pointer to the head of list.
 * @param n the position of list node which is the loop entry.
 * @return none.
 *
 * first, find the loop entry, then find the last node of list,
 * and make its next pointer point to loop entry node.
 */
void
create_loop_list ( ps_list phead, int n )
{
	ps_list p = phead;
	ps_list ploop = NULL;
	int i = 0;

	for ( ; p->next; ) {
		i++;
		p = p->next;
		if ( i == n ) {
			ploop = p;
			break;
		}
	}
	if ( !ploop ) {
		printf("The number %d is not in correct scope\n", n);
		return;
	}
	for ( ;p->next; ) 
		p = p->next;
	p->next = ploop;

	return;
}

/**
 * @brief check_loop_list1 - check whether loop exists.
 * @param phead pointer to the head of list.
 * @return 1 for existence
 *	   0 for no existence
 *
 * this way use two pointers to test, pointer p1 moves by one step
 * and pointer p2 moves by 2 steps or more, if a loop is existed,
 * then the two pointer would encounter, that is, p1 and p2 point
 * to the same node.
 * it can't locate the loop entry of the list. it can only find one
 * node in the loop.
 */
int
check_loop_list1 (ps_list phead)
{
	ps_list p1 = phead;
	ps_list p2 = phead->next;

	for ( ; p1 && p2 && p2->next; ) {
		p1 = p1->next;
		p2 = p2->next->next;
		if ( p1 == p2 ) {
			printf("Loop exists.\n");
			return 1;
		}
	}
	printf("Loop does not exists.\n");

	return 0;
}

/**
 * @brief check_loop_list2 - check whether loop exists.
 * @param phead pointer to the head of list.
 * @return 1 for existence
 *	   0 for no existence
 *
 * this way use two pointers and two length to one node  to test,
 * if the list does not exist loop, then each node's length (use
 * two ways to calculate) is equal. Otherwise, the two length is
 * unequal.
 * it can locate the loop entry of the list.
 */
int
check_loop_list2 (ps_list phead)
{
	ps_list p1 = phead->next;
	ps_list p2 = phead->next;
	int len1 = 0, len2 = 0;

	for ( ; p1 ; p1 = p1->next ) {
		len1++;
		for ( p2 = phead->next, len2 = 0; p2 ;\
			 p2 = p2->next ) {
			len2++;
			if ( p1 == p2 ) {
				if ( len1 == len2 ) {
					break;
				} else {
					printf("Loop exists. Its entry is 0x%p.\n", p1);
					return 1;
				}
			}
		}
	}
	printf("Loop does not exists.\n");

	return 0;
}

int
main()
{
	ps_list p = NULL;
	ps_list pret = NULL;
	int ret = 0;
	
	create_list1( &p, 10);
	tranverse_list( p );
	
	create_loop_list( p, 4);
	check_loop_list1( p );
	check_loop_list2( p );

	return 0;
}
