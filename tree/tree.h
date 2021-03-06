#include "doublyLinkedLib.h"
typedef int (*compare)(void* ID, void* data);

typedef struct{
	void* root;
	compare cmp;
} Tree;

Tree createTree(compare comp);
int insertNode(Tree* tree,void* parentData,void* data);
Iterator getChildren(Tree* tree,  void* data);
int search(Tree* tree, void *data);
int deleteNode(Tree* tree, void *data);
void disposeTree(Tree *tree);