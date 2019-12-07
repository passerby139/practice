#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <windows.h>
#define N 50
#include "main.h"
//分别代表一班学生链表头和二班学生链表头
Student *temp1, *temp2;
int flag = 0;


//*****************************************************************************************************************************************************************************************************************
int index(){
	//主页面信息
	system("color cf ");
	printf("				---------------XPU学生管理系统---------------\n\n");
	printf("						0.录入信息		\n");//********
	printf("						1.查找功能		\n");
	printf("						2.添加功能		\n");//********
	printf("						3.合并功能		\n");//********
	printf("						4.删除功能		\n");//********
	printf("						5.查看补考学生信息		\n");//*******
	printf("						6.查看班级整体学生信息功能		\n");//********
	printf("						7.退出系统		\n");//**********
	printf("\n				---------------XPU学生管理系统---------------\n");
	return 0;
}
//*****************************************************************************************************************************************************************************************************************
int choice(){
	int i = 10;
	while (i != 7)
	{
		index();
		printf("\n\n请输入您选择的功能:");
		scanf("%d", &i);
		system("cls");
		printf("\n您选择的功能是:");
		switch (i){
			   //实现一二班成绩录入功能
		case 0:{
				system("color af");
				printf("——>录入一二班的成绩!\n\n");
				printf("请输入一班的学生成绩(全部输入0表示录入结束):\n");
				//创造一班的学生信息链表
				temp1 = create();
				//将写好的链表保存于1.txt
				add_file(temp1, 1);
				printf("请输入二班的学生成绩(全部输入0表示录入结束):\n");
				//创造二班的学生信息链表
				temp2 = create();
				//将写好的链表保存于2.txt
				add_file(temp2, 2);
				printf("系统5秒钟后将返回主页面！");
				//进入5秒倒计时后，清屏，调用主页面函数
				Sleep(5000);
				system("cls");
				break;
			}
				//实行查找功能
		case 1:{
			system("color 5b");
				printf("已实现查找功能！");
				break;
			}
				//实现添加功能
			case 2:{
				system("color 5b");
				printf("添加功能\n\n");
				int i=5;
				//判断用户想要在哪个班级添加新的学生信息
				while (i != 1 && i != 2){
					printf("请选择要添加学生的班级（1或2）:");
					scanf("%d", &i);
					if (i == 1){
						//向一班添加此学生信息，并返回新链表
						temp1 = add(temp1);
						printf("\n");
						//展示添加完后的班级学生总名单
						printf("\n姓名	学号	语文	数学	英语\n");
						show(temp1);
						//将新链表信息添加入本地文本
						add_file(temp1, 1);
					}
					else if (i == 2){
						//向二班添加此学生信息，并返回新链表
						temp2 = add(temp2);
						printf("\n");
						//展示添加完后的班级学生总名单
						printf("\n姓名	学号	语文	数学	英语\n");
						show(temp2);
						//将新链表信息添加入本地文本
						add_file(temp2, 2);
					}
					else
						//如果错误输入给出提示，并重新输入
						printf("输入错误！！请重新输入！\n");

					printf("系统5秒钟后将返回主页面！");
					//进入5秒倒计时后，清屏，调用主页面函数
					Sleep(5000);
					system("cls");
				}
				break;
			}
				//合并1班和2班学生信息功能
			case 3:{
				system("color 5b");
				int c;
				printf("——>合并1班和2班学生信息功能！\n\n");
				//判断若无录入一二班成绩则提示并返回主页面
				if (temp1->next == NULL && temp2->next == NULL){
					printf("一二班学生信息录入为空，无法进行信息合并！！(系统将于5秒钟后返回主页面)\n");
					Sleep(5000);
					system("cls");
					break;
				}
				else{
					printf("\n姓名	学号	语文	数学	英语\n");
					//调用合并函数
					Mix();
					printf("\n\n如果需要学生成绩排名请输入'0':");
					scanf("%d", &c);
					//如果客户需要排名信息则输入0，否则直接返回
					if (c == 0){
						//乱序合并两个班的链表信息
						Student *ADD = mix(temp1, temp2);
						//对于合并后的链表进行排序
						ADD = sort(ADD);
						printf("\n");
						//展示排序后的成员信息
						printf("\n姓名	学号	语文	数学	英语\n");
						show(ADD);
						flag = 1;
					}
					printf("\n系统5秒钟后将返回主页面！");
					//进入5秒倒计时后，清屏，调用主页面函数
					Sleep(5000);
					system("cls");
					break;
				}
			}
				//实现删除功能
			case 4:{
				system("color 5b");
				printf("——>删除学生信息\n");
				int d = 5;
				//判断若无录入一二班成绩则提示并返回主页面
				if (temp1->next == NULL && temp2->next == NULL){
					printf("一二班学生信息录入为空，无法进行信息删除！！(系统将于5秒钟后返回主页面)\n");
					Sleep(5000);
					system("cls");
					break;
				}
				else{
					//选择要删除学生的班级
					while (d != 1 && d != 2){
						printf("请选择要删除学生的班级（1或2）:");
						scanf("%d", &d);
						if (d == 1){
							//调用列表结点删除函数
							temp1 = delete(temp1);
							printf("\n\n姓名	学号	语文	数学	英语\n");
							//对于删除学生信息后的总表进行查看
							show(temp1);
							add_file(temp1, 1);
						}
						else if (d == 2){
							//调用列表结点删除函数
							temp2 = delete(temp2);
							printf("\n\n姓名	学号	语文	数学	英语\n");
							//对于删除学生信息后的总表进行查看
							show(temp2);
							add_file(temp2, 2);
						}
						else
							printf("输入错误！！请重新输入！\n");
					}
					printf("\n系统5秒钟后将返回主页面！");
					//进入5秒倒计时后，清屏，调用主页面函数
					Sleep(5000);
					system("cls");
					break;
				}
			}
				//实现查看补考学生信息功能
			case 5:{
				system("color 5b");
				printf("——>查看补考学生信息\n\n");
				//判断若无录入一二班成绩则提示并返回主页面
				if (temp1->next == NULL && temp2->next == NULL){
					printf("一二班学生信息录入为空，无法进行补考学生信息查看！！(系统将于5秒钟后返回主页面)\n");
					Sleep(5000);
					system("cls");
					break;
				}
				else if (flag == 0){
					printf("一二班学生信息未进行合并，无法进行补考学生信息查看！！(系统将于5秒钟后返回主页面)\n");
					Sleep(5000);
					system("cls");
					break;
				}
				else{
					printf("\n姓名	学号	语文	数学	英语\n");
					//调用筛选学生信息的函数
					lose();
					printf("\n系统5秒钟后将返回主页面！");
					//进入5秒倒计时后，清屏，调用主页面函数
					Sleep(5000);
					system("cls");
					break;
				}
			}
			//查看班级
			case 6:{
				system("color 5b");
				int L=6;
				printf("——>查看班级整体学生信息\n\n");
				//判断若无录入一二班成绩则提示并返回主页面
				if (temp1->next == NULL && temp2->next == NULL){
					printf("一二班学生信息录入为空，无法进行信息查看！！(系统将于5秒钟后返回主页面)\n");
					Sleep(5000);
					system("cls");
					break;
				}
				else{
					//选择要查看学生的班级
					while (L != 1 && L != 2){
						printf("请选择要查看学生的班级（1或2）:");
						scanf("%d", &L);
						if (L == 1){
							printf("\n\n姓名	学号	语文	数学	英语\n");
							//对于学生信息的总表进行查看
							show(temp1) ;
						}
						else if(L == 2){
							printf("\n\n姓名	学号	语文	数学	英语\n");
							//对于学生信息的总表进行查看
							show(temp2);
						}
						else
							printf("输入错误！！请重新输入！\n");
					}
					printf("\n系统5秒钟后将返回主页面！");
					//进入5秒倒计时后，清屏，调用主页面函数
					Sleep(5000);
					system("cls");
					break;
				}
			}
				//退出系统
			case 7:{
				printf("退出系统\n");
				quit();
				break;
			}
			default:
				printf("您没有任何选择！\n");
			}
	}
	return 0;
}
//*****************************************************************************************************************************************************************************************************************
Student* create(){                                                 //创建生成原列表
	Student *head, *p, *end;
	//创建头，尾，活动指针
	head = (Student *)malloc(sizeof(Student));
	head->next = NULL;
	end = (Student *)malloc(sizeof(Student));
	while (1){
		//依次开辟新结点
		p = (Student *)malloc(sizeof(Student));
		printf("\n请输入姓名：");
		scanf("%s", &p->name);
		printf("请输入学号：");
		scanf("%d", &p->number);
		printf("请输入语文成绩：");
		scanf("%d", &p->chinese);
	    printf("请输入数学成绩：");
		scanf("%d", &p->math);
		printf("请输入英语成绩：");
		scanf("%d", &p->english);
		//保存个人数据
		p->add = p->chinese + p->math + p->english;
		//判断退出条件
		if (p->english == 0)
			break;
		//头结点为空时如何操作
		if (head->next == NULL){
			head->next = p;
			end = p;
			end->next = NULL;
		}
		//头结点不为空时如何操作
		else{
			end->next = p;
			end = p;
			end->next = NULL;
		}
	}
	//返回创建的链表头
	return head;
}
//*****************************************************************************************************************************************************************************************************************
void file(){               //实现两文件夹的合并功能
	FILE *fp, *p;
	Student look;

	//以只读方式打开文件
	fp = fopen("1.txt", "r+");
	//判断文件不存在的情况
	if (NULL == fp)
		printf("该文件打开失败！");
	//以写方式打开文件
	p = fopen("3.txt", "w");
	while (fscanf(fp, "%s%d%d%d%d", look.name, &look.number, &look.chinese, &look.math, &look.english) != EOF){
		fprintf(p, "%-6s	%-6d	%-6d	%-6d	%-6d\n", look.name, look.number, look.chinese, look.math, look.english);
		printf("%-6s	%-6d	%-6d	%-6d	%-6d\n", look.name, look.number, look.chinese, look.math, look.english);
	}
	fclose(fp);
	fp = fopen("2.txt", "r+");
	while (fscanf(fp, "%s%d%d%d%d", look.name, &look.number, &look.chinese, &look.math, &look.english) != EOF){
		fprintf(p, "%-6s	%-6d	%-6d	%-6d	%-6d\n", look.name, look.number, look.chinese, look.math, look.english);
		printf("%-6s	%-6d	%-6d	%-6d	%-6d\n", look.name, look.number, look.chinese, look.math, look.english);
	}
	fclose(fp);
	fclose(p);
}
//*****************************************************************************************************************************************************************************************************************
void add_file(Student *head, int x){             //实现链表信息录入文本
	FILE *fp;
	if (1 == x){
		fp = fopen("1.txt", "w");
		if (NULL == fp)
			printf("该文件打开失败！");

		while (head->next != NULL){
			head = head->next;
			fprintf(fp, "%-6s	%-6d	%-6d	%-6d	%-6d\n", head->name, head->number, head->chinese, head->math, head->english);
		}
		fclose(fp);
		printf("（一班学生信息已录入，并保存于1.txt当中！！！）\n\n");
	}
	if (2 == x){
		fp = fopen("2.txt", "w");
		if (NULL == fp)
			printf("该文件打开失败！");

		while (head->next != NULL){
			head = head->next;
			fprintf(fp, "%-6s	%-6d	%-6d	%-6d	%-6d\n", head->name, head->number, head->chinese, head->math, head->english);
		}
		fclose(fp);
		printf("（二班学生信息已录入，并保存于2.txt当中！！！）\n\n");
	}
}
//*****************************************************************************************************************************************************************************************************************
int find(Student *head){                                                                           //查找功能的实现
	printf("\n(已实现查找功能)");
	Student *s;
	int num;
	s = (Student *)malloc(sizeof(Student));
	s = head;
	
	printf("请输入需要查找的学生信息的学号：");
	scanf("%d", &num);

	while (s->next != NULL){
		s = s->next;
		if (s->number == num){
			printf("%s	%d	%d	%d	%d", s->name, s->number, s->chinese, s->math, s->english);
			if (s->chinese < 60 || s->math < 60 || s->english < 60)
				printf("(此学生已挂科！！)");
			else
				printf("(此学生未挂科！！)");
		}
	}
	return 0;
}
//*****************************************************************************************************************************************************************************************************************
Student* add(Student*head){                                                                            //添加功能的实现
	Student*s, *p;

	s = (Student *)malloc(sizeof(Student));
	p = (Student *)malloc(sizeof(Student));

	printf("请输入要添加的姓名：");
	scanf("%s", &p->name);
	printf("请输入要添加的学号：");
	scanf("%d", &p->number);
	printf("请输入要添加的语文成绩：");
	scanf("%d", &p->chinese);
	printf("请输入要添加的数学成绩：");
	scanf("%d", &p->math);
	printf("请输入要添加的英语成绩：");
	scanf("%d", &p->english);
	p->add = p->chinese + p->math + p->english;

	s = head;
	while (s->next != NULL)
		s = s->next;
	s->next = p;
	p->next = NULL;
		return head;
}
//*****************************************************************************************************************************************************************************************************************
void Mix(){                                       //实现一二班成绩合并功能
	FILE *fp, *p;
	Student look;

	fp = fopen("1.txt", "r+");
	if (NULL == fp)
		printf("该文件打开失败！");
	p = fopen("3.txt", "w");
	while (fscanf(fp, "%s%d%d%d%d", look.name, &look.number, &look.chinese, &look.math, &look.english) != EOF){
		fprintf(p, "%-6s	%-6d	%-6d	%-6d	%-6d\n", look.name, look.number, look.chinese, look.math, look.english);
		printf("%-6s	%-6d	%-6d	%-6d	%-6d\n", look.name, look.number, look.chinese, look.math, look.english);
	}
	fclose(fp);
	fp = fopen("2.txt", "r+");
	if (NULL == fp)
		printf("该文件打开失败！");
	while (fscanf(fp, "%s%d%d%d%d", look.name, &look.number, &look.chinese, &look.math, &look.english) != EOF){
		fprintf(p, "%-6s	%-6d	%-6d	%-6d	%-6d\n", look.name, look.number, look.chinese, look.math, look.english);
		printf("%-6s	%-6d	%-6d	%-6d	%-6d\n", look.name, look.number, look.chinese, look.math, look.english);
	}
	fclose(fp);
	fclose(p);
}
//*****************************************************************************************************************************************************************************************************************
Student * mix(Student *head1, Student *head2){
	Student *s;
	s = head1;
	while (s->next != NULL)
		s = s->next;
	s->next = head2->next;
	head2 = head1;
	return head1;
}
//*****************************************************************************************************************************************************************************************************************
Student* sort(Student *head){                                      //乱序链表排序，并生成新链表
	Student *s, *p, *new, *end;
	int i = 1, j = 1;
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
//*****************************************************************************************************************************************************************************************************************
Student* delete(Student *head){                                                                           //删除的实现
	Student *s,*p;
	int num;
	s = (Student *)malloc(sizeof(Student));
	s = head;

	printf("请输入需要查找的学生信息的学号：");
	scanf("%d", &num);

	while (s->next != NULL){
		if (s->next->number == num){
			p = s->next;
			s->next = s->next->next;
			free(p);
			printf("(已删除信息！！)");
			break;
		}
		s = s->next;
	}
	return head;
}
//*****************************************************************************************************************************************************************************************************************
void lose(){													                     	//实现挂科学生查找功能
	FILE *fp, *p;
	Student look;

	fp = fopen("3.txt", "r+");
	if (NULL == fp)
		printf("该文件打开失败！");
	p = fopen("4.txt", "w");
	while (fscanf(fp, "%s%d%d%d%d", look.name, &look.number, &look.chinese, &look.math, &look.english) != EOF){
		if (look.chinese<60 || look.math<60 || look.english<60){
			fprintf(p, "%-6s	%-6d	%-6d	%-6d	%-6d\n", look.name, look.number, look.chinese, look.math, look.english);
			printf("%-6s	%-6d	%-6d	%-6d	%-6d\n", look.name, look.number, look.chinese, look.math, look.english);
		}
	}
	fclose(fp);
	fclose(p);
}
//*****************************************************************************************************************************************************************************************************************
void show(Student *head){                          //展示链表信息函数
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
//*****************************************************************************************************************************************************************************************************************
int quit(){
	printf("\n(已实现退出系统功能)");
	exit(0); // 退出程序
		return 0;
}
//*****************************************************************************************************************************************************************************************************************


int main(){
	temp1 = (Student *)malloc(sizeof(Student));
	temp1->next = NULL;
	temp2 = (Student *)malloc(sizeof(Student));
	temp2->next = NULL;
	choice();
	system("pause");
	return 0;
}