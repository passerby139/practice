#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

typedef struct tree{
	int data;
	struct tree *left;
	struct tree *right;
}Tree,*tree;

tree createTree(){
	tree root;
	char str;
	str = getchar();
	if (str == '#'){
		root = NULL;
	}
	else{
		root = (tree)malloc(sizeof(Tree));
		root->data = str;
		root->left = createTree();
		root->right = createTree();
	}
	return root;
}


//先序遍历二叉树
void perOrder(tree root){
	if (root != NULL){
		printf("%c", root->data);
		perOrder(root->left);
		perOrder(root->right);
	}
}
//中序遍历二叉树
void perOrder1(tree root){
	if (root != NULL){
		perOrder1(root->left);
		printf("%c", root->data);
		perOrder1(root->right);
	}
}
//后序遍历二叉树
void perOrder2(tree root){
	if (root != NULL){
		perOrder2(root->left);
		perOrder2(root->right);
		printf("%c", root->data);
	}
}
int main(){
	tree root = createTree();

	printf("先序遍历此二叉树: ");
	perOrder(root);
	printf("\n");
	
	printf("中序遍历此二叉树: ");
	perOrder1(root);
	printf("\n");

	printf("后序遍历此二叉树: ");
	perOrder2(root);
	printf("\n");

	system("pause");
	return 0;
}