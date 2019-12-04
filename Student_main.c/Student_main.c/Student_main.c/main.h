#ifndef     __DB_OPERATION_H__
#define     __DB_OPERATION_H__
typedef struct Student {
	char name[10];
	int number;
	int chinese;
	int math;
	int english;
	int add;
	struct Student *next;
}Student;

//主菜单
int index();
//选择功能
int choice();
//实现两文件夹的合并功能
void file();
//实现链表信息录入文本
void add_file(Student *head, int x);
//查找功能的实现
int find(Student *head);
//添加功能的实现
Student* add(Student*head);
//实现一二班成绩合并功能
void Mix();
//删除的实现
Student* delete(Student *head);
//实现挂科学生查找功能
void lose();
//实现退出系统功能
int quit();
//乱序链表排序，并生成新链表
Student* sort(Student *head);
//展示链表信息函数
void show(Student *head);
//l实现两个链表头尾相连
Student * mix(Student *head1, Student *head2);
//创建生成原列表
Student* create();                                                 
#endif      // __DB_OPERATION_H__