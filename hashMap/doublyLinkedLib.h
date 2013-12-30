
typedef struct node{
	void* data;
	struct node *next;
	struct node *previous;
} Node;

typedef struct {
	int length;
	Node* head;
} List;

List* createList();
int insertNode(List* start, int index, void* data);
int removeNode(List *list,int index);
void dispose(List* start);
int isEmpty(List* start);
