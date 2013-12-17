typedef struct{
	void **arrayOfAddresses;
	int top;
	int noOfElements;
}Stack;
typedef char String[256];

Stack *create(int noOfElements);
int push(Stack *stack,void *element);
void *pop(Stack *stack);
int isEmpty(Stack *stack);
void *top(Stack *stack);