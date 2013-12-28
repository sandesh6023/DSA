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

TreeNode* traverse(Tree* tree, void* parentData){
	TreeNode* treeNode = ((TreeNode*)((List*)tree->root)->head->data);
	void* temp = ((TreeNode*)((List*)tree->root)->head->data)->data;
	if(tree->cmp(temp,parentData))
		return treeNode;
	return NULL;
}

int insertNode(Tree* tree,void* parentData,void* data){
	TreeNode* treenode;
	TreeNode* parentNode;
	if(parentData == NULL){
		treenode = getTreeNode(parentData, data);
		tree->root = create();
		insert((List*)tree->root, 0, treenode);
		return 1;
	}
	parentNode = traverse(tree, parentData);
	treenode =  getTreeNode(parentNode, data);
	insert(parentNode->children, 0, treenode);
	return 1;
}

