#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<malloc.h>
#define MAXSIZE 100
typedef char dataType;
//�������ṹ
typedef struct bnode{
	dataType data;
	struct bnode *lChild, *rChild;
}Bnode, *BTree;
//���нṹ
typedef struct {
	BTree data[MAXSIZE];
	int front, rear;
}SeqQueue, *PSeqQueue;
//ջ�Ľṹ
typedef struct {
	BTree data[MAXSIZE];
	int top;
}SeqStack, *PSeqStack;

//���еĳ�ʼ��
PSeqQueue initSeqQueue(){
	PSeqQueue  queue;
	queue = (PSeqQueue)malloc(sizeof(SeqQueue));
	if (queue){
		queue->front = queue->rear = 0;
	}
	return queue;
}
//�ж϶����Ƿ�Ϊ��
int emptyQueue(PSeqQueue queue){
	if (queue && queue->front == queue->rear){
		return 1;
	}
	else{
		return 0;
	}
}
//�����
int pushQueue(PSeqQueue queue, Bnode *node){
	if ((queue->rear + 1) % MAXSIZE == queue->front){//�ж϶����Ƿ�����
		return -1;
	}
	else{
		queue->rear = (queue->rear + 1) % MAXSIZE;//λ��Ϊ0�ĵ�ַ�ռ䲻�ã������ж��Ƿ�Ϊ��
		queue->data[queue->rear] = node;
		return 1;
	}
}
//������
int popQueue(PSeqQueue queue, BTree *node){
	if (emptyQueue(queue)){
		return -1;
	}
	else{
		queue->front = (queue->front + 1) % MAXSIZE;
		*node = queue->data[queue->front];
		return 1;
	}
}
//��ȡ��ͷԪ��
int frontQueue(PSeqQueue queue, BTree *node){
	if (queue->rear == queue->front){
		return -1;
	}
	else{
		*node = queue->data[(queue->front + 1) % MAXSIZE];
		return 1;
	}
}
//���ٶ���
void destroyQueue(PSeqQueue *queue){
	if (*queue){
		free(*queue);
		*queue = NULL;
	}
}
//ջ�ĳ�ʼ��
PSeqStack initStack(){
	PSeqStack stack;
	stack = (PSeqStack)malloc(sizeof(SeqStack));
	if (stack){
		stack->top = -1;
	}
	return stack;
}
//�ж�ջ�Ƿ�Ϊ��    1,��;0,�ǿ�
int emptyStack(PSeqStack stack){
	if (stack->top == -1){
		return 1;
	}
	else{
		return 0;
	}
}
//��ջ
int pushStack(PSeqStack stack, Bnode *node){
	if (stack->top == MAXSIZE - 1){
		return 0;
	}
	else{
		stack->top++;
		stack->data[stack->top] = node;
		return 1;
	}
}
//��ջ
int popStack(PSeqStack stack, BTree *node){
	if (emptyStack(stack) == 1){
		return 0;
	}
	else{
		*node = stack->data[stack->top];
		stack->top--;
		return 1;
	}
}
//��ӡԪ��
void visit(char ch){
	printf("%c \t", ch);
}

//�������Ľ���
BTree createTree(){
	BTree tree;
	dataType str;
	str = getchar();
	if (str == '#'){
		tree = NULL;
	}
	else{
		tree = (BTree)malloc(sizeof(Bnode));
		tree->data = str;
		tree->lChild = createTree();
		tree->rChild = createTree();
	}
	return tree;
}
//�������������
void perOrder(BTree tree){
	PSeqStack stack;
	BTree p = tree;
	stack = initStack();
	while (p || !emptyStack(stack)){
		if (p){
			visit(p->data);
			pushStack(stack, p);
			p = p->lChild;
		}
		else{
			popStack(stack, &p);
			p = p->rChild;
		}
	}
}
//��������˶�����
void inOrder(BTree tree){
	PSeqStack stack;
	BTree p = tree;
	stack = initStack();
	while (p || !emptyStack(stack)){
		if (p){
			pushStack(stack, p);
			p = p->lChild;
		}
		else{
			popStack(stack, &p);
			visit(p->data);
			p = p->rChild;
		}
	}
}

//���������ӡԪ��
void postOrder(BTree tree){
	PSeqStack s1, s2;
	BTree p = tree;
	s1 = initStack();
	s2 = initStack();
	while (p || !emptyStack(s2)){
		if (p){
			pushStack(s1, p);
			pushStack(s2, p);
			p = p->rChild;
		}
		else{
			popStack(s2, &p);
			p = p->lChild;
		}
	}
	while (!emptyStack(s1)){
		popStack(s1, &p);
		visit(p->data);
	}
}
//��α���������
void levelOrder(BTree tree){
	BTree p = tree;
	PSeqQueue queue = initSeqQueue();
	if (p){
		pushQueue(queue, p);
		while (!emptyQueue(queue)){
			popQueue(queue, &p);
			visit(p->data);
			if (p->lChild){
				pushQueue(queue, p->lChild);
			}
			if (p->rChild){
				pushQueue(queue, p->rChild);
			}
		}
	}
}
//��������ĸ߶�
int height(BTree tree){
	int h1, h2;
	if (tree == NULL){
		return 0;
	}
	else{
		h1 = height(tree->lChild);
		h2 = height(tree->rChild);
		if (h1>h2){
			return h1 + 1;
		}
		else{
			return h2 + 1;
		}
	}
}
//��������ÿ��ڵ�ĸ���
void levelCount(BTree tree, int l, int num[]){
	if (tree){
		num[l]++;
		levelCount(tree->lChild, l + 1, num);
		levelCount(tree->rChild, l + 1, num);
	}
}
//���������ڵ�����
int countTree(BTree tree){
	int lCount, rCount;
	if (tree == NULL){
		return 0;
	}
	lCount = countTree(tree->lChild);
	rCount = countTree(tree->rChild);
	return lCount + rCount + 1;
}

int main(){
	BTree tree = createTree();
	int i = 0;
	int countNum[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, l = 1, treeHeight, treeCount;//��¼ÿ��Ľڵ���,l��1��ʼ,�������

	treeHeight = height(tree);
	printf("\n�˶����������Ϊ: %d\n", treeHeight);

	treeCount = countTree(tree);
	printf("�˶������Ľڵ�����Ϊ: %d\n", treeCount);

	levelCount(tree, l, countNum);
	printf("�˶���������Ľڵ���Ϊ: ");
	for (i = 1; i <= treeHeight; i++){
		printf("��%d����Ŀ: %d,  ", i, countNum[i]);
	}
	printf("\n\n");

	printf("��������˶�����: ");
	perOrder(tree);
	printf("\n");

	printf("��������˶�����: ");
	inOrder(tree);
	printf("\n");

	printf("��������˶�����: ");
	postOrder(tree);
	printf("\n");

	printf("��α����˶�����: ");
	levelOrder(tree);
	printf("\n");
	system("pause");
	return 0;
}