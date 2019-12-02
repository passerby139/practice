#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

typedef struct Student {
	char name[10];
	int number;
	int chinese;
	int math;
	int english;
	int add;
	struct Student *next;
}Student;

Student* create(){
	Student *head,*p,*end;                                  //创建头，尾，活动指针

	head = (Student *)malloc(sizeof(Student));
	head->next = NULL;
	end = (Student *)malloc(sizeof(Student));
	while (1){
		p = (Student *)malloc(sizeof(Student));                   //依次开辟新结点
		//printf("请输入姓名：");
		scanf("%s", &p->name);
		//printf("请输入学号：");
		scanf("%d", &p->number);
		//printf("请输入语文成绩：");
		scanf("%d", &p->chinese);
		//printf("请输入数学成绩：");
		scanf("%d", &p->math);
	//	printf("请输入英语成绩：");
		scanf("%d", &p->english);
		p->add = p->chinese + p->math + p->english;           //保存个人数据
		if (p->english == 0)                                                        //判断退出条件
			break;
		if (head->next == NULL){                                              //头结点为空时如何操作
			head->next =p;
			end = p;
			end->next = NULL;
		}
		else{                                                                               //头结点不为空时如何操作
			end->next = p;
			end = p;
			end->next = NULL;
		}
	}
	return head;                                                                      //返回创建的链表头
}


Student* sort(Student *head){                                      
	Student *s,*p,*new,*end;                                               //创建新链表头，尾，活动结点
	int i = 1,j=1;
	int max = 0;
	int mark;

	//创建新链表头结点，尾结点
	new = (Student *)malloc(sizeof(Student));
	new->next = NULL;
	end = (Student *)malloc(sizeof(Student));
	s = (Student *)malloc(sizeof(Student));

	s = head->next;

	while (s->next){
		s = s->next;
		j++;
	}
	while (j){
		s = head;
		mark = 0;
		i = 1;
		//遍历找到总分最高的结点
		while (1){
			s = s->next;
			if (s->add > max){
				max = s->add;
				mark = i;
			}
			if (s->next == NULL)
				break;
			//记录最高分所在结点数
			i++;                                             
		} 
		//指针移向总分最高的结点
		s = head;
		while (mark){
			mark--;
			s = s->next;
		}

		//将原结点移植到新链表的活动指针当中
		p = (Student *)malloc(sizeof(Student));
		for (i = 0; i < 10; i++)
			p->name[i] = s->name[i];
		p->number = s->number;
		p->math = s->math;
		p->chinese = s->chinese;
		p->english = s->english;
		p->add = s->add;
		//将原结点总分清零
		s->add = 0;
		//对于结点插入新链表
		if (new->next == NULL){
			new->next = p;
			end = p;
			end->next = NULL;
		}
		else{
			end->next = p;
			end = p;
			end->next = NULL;
		}
		j--;
		//比较值清零
		max = 0;
	}
		return new;
}

void show(Student *head){
	Student *s;
	s = (Student *)malloc(sizeof(Student));
	s = head;
	while (1){
		s = s->next;
		printf("%s	", s->name);
		printf("%d	", s->number);
		printf("%d	", s->chinese);
		printf("%d	", s->math);
		printf("%d	\n", s->english);
		if (s->next == NULL)
			break;
	}
}

int main(){
	Student *head,*temp;
	head = create();
	show(head);
	temp = sort(head);
	printf("=============================");
	show(temp);
	system("pause");
	return 0;
}




/*
张明明
01
67
78
82
李成友
02
78
91
88
张辉灿
03
68
82
56
0
0
0
0
0
*/