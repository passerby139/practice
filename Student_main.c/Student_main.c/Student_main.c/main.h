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
//ʵ�����ļ��еĺϲ�����
void file();
//ʵ��������Ϣ¼���ı�
void add_file(Student *head, int x);
//���ҹ��ܵ�ʵ��
int find(Student *head);
//��ӹ��ܵ�ʵ��
Student* add(Student*head);
//ʵ��һ����ɼ��ϲ�����
void Mix();
//ɾ����ʵ��
Student* delete(Student *head);
//ʵ�ֹҿ�ѧ�����ҹ���
void lose();
//ʵ���˳�ϵͳ����
int quit();
//�����������򣬲�����������
Student* sort(Student *head);
//չʾ������Ϣ����
void show(Student *head);
//lʵ����������ͷβ����
Student * mix(Student *head1, Student *head2);
//��������ԭ�б�
Student* create();                                                 
#endif      // __DB_OPERATION_H__