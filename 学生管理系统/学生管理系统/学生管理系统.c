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
	Student *head,*p,*end;                                  //����ͷ��β���ָ��

	head = (Student *)malloc(sizeof(Student));
	head->next = NULL;
	end = (Student *)malloc(sizeof(Student));
	while (1){
		p = (Student *)malloc(sizeof(Student));                   //���ο����½��
		//printf("������������");
		scanf("%s", &p->name);
		//printf("������ѧ�ţ�");
		scanf("%d", &p->number);
		//printf("���������ĳɼ���");
		scanf("%d", &p->chinese);
		//printf("��������ѧ�ɼ���");
		scanf("%d", &p->math);
	//	printf("������Ӣ��ɼ���");
		scanf("%d", &p->english);
		p->add = p->chinese + p->math + p->english;           //�����������
		if (p->english == 0)                                                        //�ж��˳�����
			break;
		if (head->next == NULL){                                              //ͷ���Ϊ��ʱ��β���
			head->next =p;
			end = p;
			end->next = NULL;
		}
		else{                                                                               //ͷ��㲻Ϊ��ʱ��β���
			end->next = p;
			end = p;
			end->next = NULL;
		}
	}
	return head;                                                                      //���ش���������ͷ
}


Student* sort(Student *head){                                      
	Student *s,*p,*new,*end;                                               //����������ͷ��β������
	int i = 1,j=1;
	int max = 0;
	int mark;

	//����������ͷ��㣬β���
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
		//�����ҵ��ܷ���ߵĽ��
		while (1){
			s = s->next;
			if (s->add > max){
				max = s->add;
				mark = i;
			}
			if (s->next == NULL)
				break;
			//��¼��߷����ڽ����
			i++;                                             
		} 
		//ָ�������ܷ���ߵĽ��
		s = head;
		while (mark){
			mark--;
			s = s->next;
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
		//��ԭ����ܷ�����
		s->add = 0;
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
		//�Ƚ�ֵ����
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
������
01
67
78
82
�����
02
78
91
88
�ŻԲ�
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