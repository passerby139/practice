#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <windows.h>
#include "main.h"

int index(){
	//��ҳ����Ϣ
	printf("---------------XPUѧ������ϵͳ---------------\n\n");
	printf("		1.���ҹ���		\n");//*
	printf("		2.��ӹ���		\n");//*
	printf("		3.�ϲ�����		\n");//*
	printf("		4.ɾ������		\n");//*
	printf("		5.�鿴����ѧ����Ϣ		\n");//*
	printf("		6.�˳�ϵͳ		\n");//*
	printf("\n---------------XPUѧ������ϵͳ---------------\n");
	return 0;
}

int choice(){
	int i = 7;
	while (i != 6)
	{
		printf("\n\n��������ѡ��Ĺ���:");
		scanf("%d", &i);
		printf("\n��ѡ��Ĺ�����:");
		switch (i){
			//ʵ�в��ҹ���
		case 1:{
			printf("���ҹ���");//���ļ�
			//��ȡ�ļ�����
			//����ͷhead����������find����
			find(head);                                                                                  //��
			//�ر��ļ���������Ϣ
			break;
		}
			//ʵ����ӹ���
		case 2:{
			Student*new;
			new = (Student*)malloc(sizeof(Student));
			printf("��ӹ���");
			//���ļ�
			//��ȡ�ļ�����
			//����ͷhead����������add����
			new = add(head);                                                                              //��
			//�����Ϻ���ʾ�ܱ�
			show(new);
			//�ر��ļ���������Ϣ
			break;
		}
			//ʵ��ɾ������
		case 3:{
			printf("��ӹ���");
			Mix(head1,head2);
			break;
		}
			//ʵ�ֲ鿴����ѧ����Ϣ����
		case 4:{
			Student*new;
			new = (Student*)malloc(sizeof(Student));
			printf("�鿴����ѧ����Ϣ����");
			//���ļ�
			//��ȡ�ļ�����
			//����ͷhead����������lose����
			new = lose(head);                                                                              //��
			//�����Ϻ���ʾ�����±�
			show(new);
			//�ر��ļ���������Ϣ
			break;
		}
			//ʵ���˳�ϵͳ����
		case 5:{
			printf("�˳�ϵͳ\n");
			quit();
			break;
		}
			//ʵ�ַ������˵�����
		case 6:{
			printf("������ҳ�棡\n");
			break;
		}
		default:
			printf("��û���κ�ѡ��\n");
		}
	}
	return 0;
}

int find(Student *head){                                                                           //���ҹ��ܵ�ʵ��
	printf("\n(��ʵ�ֲ��ҹ���)");
	Student *s;
	int num;
	s = (Student *)mallic(sizeof(Student));
	s = head;
	
	printf("��������Ҫ���ҵ�ѧ����Ϣ��ѧ�ţ�");
	scanf("%d", num);

	while (s->next != NULL){
		s = s->next;
		if (s->number == num){
			printf("%s	%d	%d	%d	%d", s->name, s->number, s->chinese, s->math, s->english);
			if (s->chinese < 60 || s->math < 60 || s->english < 60)
				printf("(��ѧ���ѹҿƣ���)");
			else
				printf("(��ѧ��δ�ҿƣ���)")��
		}
	}
	return 0;
}

Student* add(Student*head){                                                                            //��ӹ��ܵ�ʵ��
	Student*s, *p;

	s = (Student *)malloc(sizeof(Student));
	p = (Student *)malloc(sizeof(Student));

	//printf("������Ҫ��ӵ�������");
	scanf("%s", &p->name);
	//printf("������Ҫ��ӵ�ѧ�ţ�");
	scanf("%d", &p->number);
	//printf("������Ҫ��ӵ����ĳɼ���");
	scanf("%d", &p->chinese);
	//printf("������Ҫ��ӵ���ѧ�ɼ���");
	scanf("%d", &p->math);
	//printf("������Ҫ��ӵ�Ӣ��ɼ���");
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

Student* delete(Student *head){                                                                           //ɾ����ʵ��
	printf("\n(��ʵ��ɾ������)");
	Student *s;
	int num;
	s = (Student *)mallic(sizeof(Student));
	s = head;

	printf("��������Ҫ���ҵ�ѧ����Ϣ��ѧ�ţ�");
	scanf("%d", num);

	while (s->next != NULL){
		s = s->next;
		if (s->next->number == num){
			s->next = s->next->next;
			printf("��ɾ����Ϣ����");
		}
	}
	return head;
}

Student* lose(Student *head){													                     	//ʵ�ֹҿ�ѧ�����ҹ���
	//ԭ���ѯ�ҿ���������������������ڹҿ�����
	Student *s, *p, *new, *end;
	int i = 1, j = 0, k;
	int mark;

	//����������ͷ��㣬β���
	new = (Student *)malloc(sizeof(Student));
	new->next = NULL;
	end = (Student *)malloc(sizeof(Student));
	s = (Student *)malloc(sizeof(Student));
	//ͳ�ƹҿ�������
	s = head->next;
	while (s->next){
		s = s->next;
		if (s->chinese<60 || s->math<60 || s->english<60)
			j++;
	}
	s = head;
	while (j){
		//�����ҵ��йҿƷ����Ľ��
		while (1){
			s = s->next;
			if (s->chinese < 60 || s->math < 60 || s->english < 60)
				break;
			if (s->next == NULL)
				break;
		}
		//��ԭ�����ֲ��������Ļָ�뵱��
		p = (Student *)malloc(sizeof(Student));
		for (i = 0; i < 10; i++)
			p->name[i] = s->name[i];
		p->number = s->number;
		p->math = s->math;
		p->chinese = s->chinese;
		p->english = s->english;
		p->add = s->add;
		//���ڽ�����������
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
	printf("\n(��ʵ���˳�ϵͳ����)");
	exit(0); // �˳�����
		return 0;
}

void show(Student *head){                                                                                      //չʾ������Ϣ����
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