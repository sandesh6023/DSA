#include "tree.h"
#include <stdlib.h>

typedef struct {
	void* data;
	List* children;
	void* parent;
} TreeNode;

Tree createTree(compare cmp){
	Tree tree;
	tree.root = NULL;
	tree.cmp = cmp;
	return tree;
}

TreeNode* getTreeNode(void* parentData,void* data){
	TreeNode* treenode = calloc(1, sizeof(TreeNode));
	treenode->children = create();
	treenode->data = data;
	treenode->parent = parentData;
	return treenode;
}

TreeNode* traverse(List *list, void* parentData,compare cmp){
	TreeNode* temp;
    Iterator it = getIterator(list);
        while(it.hasNext(&it)){
            temp = it.next(&it);
            if (1 == cmp(temp->data,parentData)){
                    return temp;
            }
            if(temp->children->head!= NULL){
                    return traverse(temp->children, parentData, cmp);
            }
        }
        return NULL;
}

int insertNode(Tree* tree,void* parentData,void* data){
	int index;
	TreeNode* treenode;
	TreeNode* parentNode;
	if(parentData == NULL){ 						// inserting root node
		treenode = getTreeNode(parentData, data);
		tree->root = create();
		insert((List*)tree->root, 0, treenode);
		return 1;
	}												// Inserting sub nodes
	parentNode = traverse((List*)tree->root, parentData,tree->cmp);
	treenode =  getTreeNode(parentNode, data);
	
	if(treenode == NULL) 
		return 0;
	insert(parentNode->children,0,treenode);
	return 1;
}

void* getChildrenData(Iterator* it){
        TreeNode* node;
        Iterator treeIt = getIterator(it->list);
        treeIt.position = it->position;
        node = treeIt.next(&treeIt);
        it->position++;
        return node->data;
}

Iterator getChildren(Tree* tree,  void* data){
        TreeNode* parentNode;
        Iterator it;
        parentNode = traverse((List*)tree->root, data,tree->cmp);
        it = getIterator(parentNode->children);
        it.next = getChildrenData;
        return it;
}

int search(Tree* tree, void *data){
	TreeNode* parentNode;
	parentNode = traverse((List*)tree->root,data,tree->cmp);
	if(parentNode == NULL) 
		return 0;
	return 1;	
}

int deleteNode(Tree* tree, void *data){
	TreeNode* treeNode;
	if(tree->root == NULL)
		return 0;
	treeNode = traverse((List*)tree->root, data, tree->cmp);
	if(treeNode == NULL)
		return 0;
}