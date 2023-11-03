﻿#include <stdio.h>
#include <malloc.h>

#define MAX_STRING 100

typedef struct {
	int num;
	char numString[MAX_STRING];
} element;

typedef struct StackNode {
	element item;
	struct StackNode* link;
} StackNode;

typedef struct {
	StackNode* top;
} LinkedStackType;

void init(LinkedStackType* s) {
	s->top = NULL;
}

int is_empty(LinkedStackType* s) {
	return (s->top == NULL);
}

int is_full(LinkedStackType* s) { // 항상 거짓을 반환
	return 0;
}

// 맨 위에 노드 삽입
void push(LinkedStackType* s, element item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	if (temp == NULL) {
		fprintf(stderr, "메모리 할당 에러\n");
		return;
	}
	else {
		temp->item = item; // temp에 item을 넣음
		temp->link = s->top; // temp가 맨 첫 번째 노드를 가리키게 함
		s->top = temp; // top이 temp를 가리키게 함
	}
}

// 맨 위 노드 삭제
element pop(LinkedStackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어 있음\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top; // temp = 맨 위 노드
		element item = temp->item; // 반환할 item에 맨 위 노드의 item을 넣음.
		s->top = s->top->link; // top = top이 링크하고 있는 것(두 번째 노드)
		free(temp); // temp 반환
		return item;
	}
}

element peek(LinkedStackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else
		return s->top->item;
}

void stack_print(LinkedStackType* s) {
	StackNode* temp = s->top;
	if (is_empty(s))
		printf("<empty>\n");
	else {
		printf("[%d, %s] <- top\n", temp->item.num, temp->item.numString);
		while (temp->link != NULL) {
			temp = temp->link;
			printf("[%d, %s]\n", temp->item.num, temp->item.numString);
		}
	}
	printf("--\n");
}

int main(void) {
	LinkedStackType s;
	element e;

	init(&s);
	stack_print(&s);

	e.num = 10;
	strcpy(e.numString, "ten");
	push(&s, e);
	stack_print(&s);

	e.num = 20;
	strcpy(e.numString, "twenty");
	push(&s, e);
	stack_print(&s);

	e.num = 30;
	strcpy(e.numString, "thirty");
	push(&s, e);
	stack_print(&s);

	e.num = 40;
	strcpy(e.numString, "forty");
	push(&s, e);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	e.num = 50;
	strcpy(e.numString, "fifty");
	push(&s, e);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	return 0;
}