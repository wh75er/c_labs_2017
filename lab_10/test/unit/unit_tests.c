#include "gtest/gtest.h"
#include <limits.h>
#include "../../struct.h"
#include "../../nodeProcessing.h"
#include "../../smallFunctions/sub_func.h"



node_t *TEST_1_POP_FRONT = NULL;

node_t *TEST_2_INSERT = NULL;
node_t *TEST_3_INSERT = NULL;

int cmpN(const void *a, const void*b)
{
	if(*((int*)a) > *((int*)b))
		return 1;
	if(*((int*)a) == *((int*)b))
		return 0;
	if(*((int*)a) < *((int*)b))
		return -1;
}

int cmpLinkedList(node_t *a, node_t *b) {
	if(!b && !a)
		return 1;
	if(!b && a)
		return 0;
	if(b && !a)
		return 0;

	node_t *tmp_a = a, *tmp_b = b;
	while(tmp_a || tmp_b) {
		if(cmpN(tmp_a->data, tmp_b->data))
			return 0;
		tmp_b = tmp_b->next;
		tmp_a = tmp_a->next;
	}
	if(tmp_a && !tmp_b)
		return 0;
	if(!tmp_a && tmp_b)
		return 0;

	return 1;
}

/*
TEST (pop_front, POP_ELEMENT) {
	push(&TEST_1_POP_FRONT, 6);		//TEST INIT
	push(&TEST_1_POP_FRONT, 5);
	push(&TEST_1_POP_FRONT, 3);

	node_t *result = NULL;		//RESULT
	push(&result, 5);
	push(&result, 3);

	pop_front(&TEST_1_POP_FRONT);

	ASSERT_EQ(cmpLinkedList(TEST_1_POP_FRONT, result), 1);

	freeMem(&result);
	freeMem(&TEST_1_POP_FRONT);
}
*/
TEST (insert, INSERT_ELEMENT) {
	push(&TEST_2_INSERT, 6);       	//TEST INIT
	push(&TEST_2_INSERT, 5);
	push(&TEST_2_INSERT, 3);
	
	node_t *result = NULL;     	//RESULT
	push(&result, 6);
	push(&result, 5);
	push(&result, 9);
	push(&result, 3);

	node_t *elem = (node_t*)malloc(sizeof(node_t));
	elem->data = malloc(sizeof(int));
	*((int*)elem->data) = 9;

	insert(&TEST_2_INSERT, elem,TEST_2_INSERT->next->next);
/*
	ASSERT_EQ(cmpLinkedList(TEST_2_INSERT, result), 1);
*/	
	freeMem(&result);
	freeMem(&TEST_2_INSERT);
	free(elem->data);
	free(elem);
}
/*
TEST (insert, INSERT_ELEMENT_BEFORE_HEAD) {
	push(&TEST_3_INSERT, 6);       	//TEST INIT
	push(&TEST_3_INSERT, 5);
	push(&TEST_3_INSERT, 3);
	
	node_t *result = NULL;     	//RESULT
	push(&result, 9);
	push(&result, 6);
	push(&result, 5);
	push(&result, 3);

	node_t *elem = (node_t*)malloc(sizeof(node_t));
	elem->data = malloc(sizeof(int));
	*((int*)elem->data) = 9;

	insert(&TEST_3_INSERT, elem,TEST_3_INSERT);

	ASSERT_EQ(cmpLinkedList(TEST_3_INSERT, result), 1);
	
	
	freeMem(&result);
	freeMem(&TEST_3_INSERT);
	free(elem->data);
	free(elem);
}
*/
