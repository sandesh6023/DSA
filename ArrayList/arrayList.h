typedef struct {
	void** base;
	int capacity;
	int length;
} ArrayList;

typedef int (*compareFunc)(void *value,void *searchValue);

ArrayList create(int capacity);

int insert(ArrayList *list, int index, void* data);
void* get(ArrayList *list, int index);
int add(ArrayList *list,void *data);
void dispose(ArrayList *list);
int search(ArrayList *list,void *searchValue,compareFunc comp);
int remove(ArrayList *list,void *value,compareFunc comp);