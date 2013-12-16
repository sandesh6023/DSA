typedef struct node
{
	void *data;
	struct node *previous;
	struct node *next;	
} Node;

typedef struct{
	Node *head;
	int top;
}List;

typedef struct {
	int id;
	int balance;
}Account;


typedef char String[256];

List *create();
Node *createNode(void *element ,Node *previous,Node *next);
int pop(List *list);
int push(List *list,void *element);