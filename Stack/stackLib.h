typedef struct{
	void *elements;
	int elementSize;
	int top;
	int noOfElements;
}Stack;
typedef char String[256];

Stack* create(int typesize, int length);
int push(Stack *stack, void *inputElement);
void* pop(Stack *stack);
void* top(Stack *stack);
int isFull(Stack *stack);