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
	if(parentData == NULL){ 			// inserting root node
		treenode = getTreeNode(parentData, data);
		tree->root = create();
		insert((List*)tree->root, 0, treenode);
		return 1;
	}
	parentNode = traverse((List*)tree->root, parentData,tree->cmp);
	treenode =  getTreeNode(parentNode, data);
	
	if(treenode == NULL) 
		return 0;
	insert(parentNode->children,0,treenode);
	return 1;
}