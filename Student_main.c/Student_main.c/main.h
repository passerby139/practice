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

//���˵�
int index();
//ѡ����
int choice();
int find();
int add();
int delete();
int lose_look();
int quit();
#endif      // __DB_OPERATION_H__