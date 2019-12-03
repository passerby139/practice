#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <windows.h>
#include "main.h"

int index(){
	//主页面信息
	printf("---------------XPU学生管理系统---------------\n\n");
	printf("		1.查找功能		\n");//*
	printf("		2.添加功能		\n");//*
	printf("		3.合并功能		\n");//*
	printf("		4.删除功能		\n");//*
	printf("		5.查看补考学生信息		\n");//*
	printf("		6.退出系统		\n");//*
	printf("\n---------------XPU学生管理系统---------------\n");
	return 0;
}

int choice(){
	int i = 7;
	while (i != 6)
	{
		printf("\n\n请输入您选择的功能:");
		scanf("%d", &i);
		printf("\n您选择的功能是:");
		switch (i){
			//实行查找功能
		case 1:{
			printf("查找功能");//打开文件
			//读取文件链表
			//将表头head做参数传入find函数
			find(head);                                                                                  //改
			//关闭文件并保存信息
			break;
		}
			//实现添加功能
		case 2:{
			Student*new;
			new = (Student*)malloc(sizeof(Student));
			printf("添加功能");
			//打开文件
			//读取文件链表
			//将表头head做参数传入add函数
			new = add(head);                                                                              //改
			//添加完毕后显示总表
			show(new);
			//关闭文件并保存信息
			break;
		}
			//实现删除功能
		case 3:{
			printf("添加功能");
			Mix(head1,head2);
			break;
		}
			//实现查看补考学生信息功能
		case 4:{
			Student*new;
			new = (Student*)malloc(sizeof(Student));
			printf("查看补考学生信息功能");
			//打开文件
			//读取文件链表
			//将表头head做参数传入lose函数
			new = lose(head);                                                                              //改
			//添加完毕后显示生成新表
			show(new);
			//关闭文件并保存信息
			break;
		}
			//实现退出系统功能
		case 5:{
			printf("退出系统\n");
			quit();
			break;
		}
			//实现返回主菜单界面
		case 6:{
			printf("返回主页面！\n");
			break;
		}
		default:
			printf("您没有任何选择！\n");
		}
	}
	return 0;
}

int find(Student *head){                                                                           //查找功能的实现
	printf("\n(已实现查找功能)");
	Student *s;
	int num;
	s = (Student *)mallic(sizeof(Student));
	s = head;
	
	printf("请输入需要查找的学生信息的学号：");
	scanf("%d", num);

	while (s->next != NULL){
		s = s->next;
		if (s->number == num){
			printf("%s	%d	%d	%d	%d", s->name, s->number, s->chinese, s->math, s->english);
			if (s->chinese < 60 || s->math < 60 || s->english < 60)
				printf("(此学生已挂科！！)");
			else
				printf("(此学生未挂科！！)")；
		}
	}
	return 0;
}

Student* add(Student*head){                                                                            //添加功能的实现
	Student*s, *p;

	s = (Student *)malloc(sizeof(Student));
	p = (Student *)malloc(sizeof(Student));

	//printf("请输入要添加的姓名：");
	scanf("%s", &p->name);
	//printf("请输入要添加的学号：");
	scanf("%d", &p->number);
	//printf("请输入要添加的语文成绩：");
	scanf("%d", &p->chinese);
	//printf("请输入要添加的数学成绩：");
	scanf("%d", &p->math);
	//printf("请输入要添加的英语成绩：");
	scanf("%d", &p->english);
	p->add = p->chinese + p->math + p->english;

	s = head;
	while (1){
		s = s->next;
		if (p->add >= s->next->add){
			p->next = s->next;
			s->next = p;
			break;
		}
		else if (s->next == NULL){
			s->next = p;
			p->next = NULL;
			break;
		}
		else
			continue;
	}
	return head;
}

Student* Mix(Student* head1, Student* head2){
	Student *s;
	s = (Student *)mallic(sizeof(Student));

	s = head1;
	while (s->next != NULL);
	s->next = head2->next;
	head2 = head1;
	return head1;
}

Student* delete(Student *head){                                                                           //删除的实现
	printf("\n(已实现删除功能)");
	Student *s;
	int num;
	s = (Student *)mallic(sizeof(Student));
	s = head;

	printf("请输入需要查找的学生信息的学号：");
	scanf("%d", num);

	while (s->next != NULL){
		s = s->next;
		if (s->next->number == num){
			s->next = s->next->next;
			printf("已删除信息！！");
		}
	}
	return head;
}

Student* lose(Student *head){													                     	//实现挂科学生查找功能
	//原表查询挂科人数，并生成新链表关于挂科人数
	Student *s, *p, *new, *end;
	int i = 1, j = 0, k;
	int mark;

	//创建新链表头结点，尾结点
	new = (Student *)malloc(sizeof(Student));
	new->next = NULL;
	end = (Student *)malloc(sizeof(Student));
	s = (Student *)malloc(sizeof(Student));
	//统计挂科总人数
	s = head->next;
	while (s->next){
		s = s->next;
		if (s->chinese<60 || s->math<60 || s->english<60)
			j++;
	}
	s = head;
	while (j){
		//遍历找到有挂科分数的结点
		while (1){
			s = s->next;
			if (s->chinese < 60 || s->math < 60 || s->english < 60)
				break;
			if (s->next == NULL)
				break;
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
	}
	return new;
}

int quit(){
	printf("\n(已实现退出系统功能)");
	exit(0); // 退出程序
		return 0;
}

void show(Student *head){                                                                                      //展示链表信息函数
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
	index();
	choice();
	system("pause");
	return 0;
}