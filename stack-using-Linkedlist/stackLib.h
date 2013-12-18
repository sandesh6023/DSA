#include "doublyLinkedLib.h"
typedef struct {
	int id;
	int balance;
}Account;

typedef char String[256];

int push(List *stack,void *element);
int pop(List *stack);