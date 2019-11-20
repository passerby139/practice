#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#define MAX 20

typedef int Vertex;
Vertex visit[MAX] = { 0 };
Vertex visit2[MAX] = { 0 };
int arr[MAX] = { 0 };
int top=0;
int bottom=0;

typedef struct GNode{
	int NV;
	int Ne;
	int G[MAX][MAX];
}*PtrToGNode;
typedef PtrToGNode MGraph;

typedef struct ENode{
	Vertex V1, V2;
	int weight;
}*PtrToEGNode;
typedef PtrToEGNode Edge;

MGraph CreateGraph(int VertexNum){
	Vertex V, W;
	MGraph Graph;

	Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->NV = VertexNum;
	Graph->Ne = 0;
	for (V = 0; V < Graph->NV; V++)
		for (W = 0; W < Graph->NV; W++)
			Graph->G[V][W] = 0;
	return Graph;
}

void InsertEdge(MGraph Graph, Edge E){
	Graph->G[E->V1][E->V2] = E->weight;
	Graph->G[E->V2][E->V1] = E->weight;
}

MGraph BuildGraph(){ 
	MGraph Graph;
	Edge E;
	Vertex v;
	int Nv, i;
	printf("请输入图的总顶点数：");
	scanf("%d", &Nv);
	Graph = CreateGraph(Nv);
	printf("请输入图的总边数：");
	scanf("%d", &(Graph->Ne));
	if (Graph->Ne != 0){
		E = (Edge)malloc(sizeof(struct ENode));
		for (i = 0; i < Graph->Ne; i++){
			printf("请输入第%d条边的三个参数（弧尾下标，弧头下标，权值）：",i+1);
			scanf("%d%d%d", &E->V1, &E->V2, &E->weight);
			InsertEdge(Graph, E);
		}
	}
	return Graph;
}

void DFS(Vertex v,MGraph Graph){
	int j;
	visit2[v] = 1;
	printf("%d\n", v);
	for (j = 0; j < Graph->NV; j++){
		if (Graph->G[v][j] == 1 && visit2[j] == 0)
			DFS(j, Graph);
	}
}

void BFS(Vertex v, MGraph Graph){
	int j;
	
	if (visit[v]==0)
		printf("%d\n", v);
	visit[v] = 1;
	 
	for (j = 0; j < Graph->NV; j++){
		if (Graph->G[v][j] == 1 && visit[j] == 0){
			arr[top++] = j;
			visit[j] = 1;
			printf("%d\n",j);
		}
	}
	if (top == bottom)
		return 1;
	BFS(arr[bottom++], Graph);
}

int main(){
	MGraph i;
	Vertex v;
	i = BuildGraph();
	printf("请输入遍历的起点：");
	scanf("%d",&v);
	printf("领接矩阵的深度遍历为：\n");
	DFS(v, i);
	printf("领接矩阵的广度遍历为：\n");
	BFS(v, i);
	system("pause");
	return 0;
}