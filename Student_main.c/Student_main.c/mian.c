#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <windows.h>
#define N 50
#include "main.h"
//�ֱ����һ��ѧ������ͷ�Ͷ���ѧ������ͷ
Student *temp1, *temp2;
int flag = 0;


//*****************************************************************************************************************************************************************************************************************
int index(){
	//��ҳ����Ϣ
	system("color cf ");
	printf("				---------------XPUѧ������ϵͳ---------------\n\n");
	printf("						0.¼����Ϣ		\n");//********
	printf("						1.���ҹ���		\n");
	printf("						2.��ӹ���		\n");//********
	printf("						3.�ϲ�����		\n");//********
	printf("						4.ɾ������		\n");//********
	printf("						5.�鿴����ѧ����Ϣ		\n");//*******
	printf("						6.�鿴�༶����ѧ����Ϣ����		\n");//********
	printf("						7.�˳�ϵͳ		\n");//**********
	printf("\n				---------------XPUѧ������ϵͳ---------------\n");
	return 0;
}
//*****************************************************************************************************************************************************************************************************************
int choice(){
	int i = 10;
	while (i != 7)
	{
		index();
		printf("\n\n��������ѡ��Ĺ���:");
		scanf("%d", &i);
		system("cls");
		printf("\n��ѡ��Ĺ�����:");
		switch (i){
			   //ʵ��һ����ɼ�¼�빦��
		case 0:{
				system("color af");
				printf("����>¼��һ����ĳɼ�!\n\n");
				printf("������һ���ѧ���ɼ�(ȫ������0��ʾ¼�����):\n");
				//����һ���ѧ����Ϣ����
				temp1 = create();
				//��д�õ���������1.txt
				add_file(temp1, 1);
				printf("����������ѧ���ɼ�(ȫ������0��ʾ¼�����):\n");
				//��������ѧ����Ϣ����
				temp2 = create();
				//��д�õ���������2.txt
				add_file(temp2, 2);
				printf("ϵͳ5���Ӻ󽫷�����ҳ�棡");
				//����5�뵹��ʱ��������������ҳ�溯��
				Sleep(5000);
				system("cls");
				break;
			}
				//ʵ�в��ҹ���
		case 1:{
			system("color 5b");
				printf("��ʵ�ֲ��ҹ��ܣ�");
				break;
			}
				//ʵ����ӹ���
			case 2:{
				system("color 5b");
				printf("��ӹ���\n\n");
				int i=5;
				//�ж��û���Ҫ���ĸ��༶����µ�ѧ����Ϣ
				while (i != 1 && i != 2){
					printf("��ѡ��Ҫ���ѧ���İ༶��1��2��:");
					scanf("%d", &i);
					if (i == 1){
						//��һ����Ӵ�ѧ����Ϣ��������������
						temp1 = add(temp1);
						printf("\n");
						//չʾ������İ༶ѧ��������
						printf("\n����	ѧ��	����	��ѧ	Ӣ��\n");
						show(temp1);
						//����������Ϣ����뱾���ı�
						add_file(temp1, 1);
					}
					else if (i == 2){
						//�������Ӵ�ѧ����Ϣ��������������
						temp2 = add(temp2);
						printf("\n");
						//չʾ������İ༶ѧ��������
						printf("\n����	ѧ��	����	��ѧ	Ӣ��\n");
						show(temp2);
						//����������Ϣ����뱾���ı�
						add_file(temp2, 2);
					}
					else
						//����������������ʾ������������
						printf("������󣡣����������룡\n");

					printf("ϵͳ5���Ӻ󽫷�����ҳ�棡");
					//����5�뵹��ʱ��������������ҳ�溯��
					Sleep(5000);
					system("cls");
				}
				break;
			}
				//�ϲ�1���2��ѧ����Ϣ����
			case 3:{
				system("color 5b");
				int c;
				printf("����>�ϲ�1���2��ѧ����Ϣ���ܣ�\n\n");
				//�ж�����¼��һ����ɼ�����ʾ��������ҳ��
				if (temp1->next == NULL && temp2->next == NULL){
					printf("һ����ѧ����Ϣ¼��Ϊ�գ��޷�������Ϣ�ϲ�����(ϵͳ����5���Ӻ󷵻���ҳ��)\n");
					Sleep(5000);
					system("cls");
					break;
				}
				else{
					printf("\n����	ѧ��	����	��ѧ	Ӣ��\n");
					//���úϲ�����
					Mix();
					printf("\n\n�����Ҫѧ���ɼ�����������'0':");
					scanf("%d", &c);
					//����ͻ���Ҫ������Ϣ������0������ֱ�ӷ���
					if (c == 0){
						//����ϲ��������������Ϣ
						Student *ADD = mix(temp1, temp2);
						//���ںϲ���������������
						ADD = sort(ADD);
						printf("\n");
						//չʾ�����ĳ�Ա��Ϣ
						printf("\n����	ѧ��	����	��ѧ	Ӣ��\n");
						show(ADD);
						flag = 1;
					}
					printf("\nϵͳ5���Ӻ󽫷�����ҳ�棡");
					//����5�뵹��ʱ��������������ҳ�溯��
					Sleep(5000);
					system("cls");
					break;
				}
			}
				//ʵ��ɾ������
			case 4:{
				system("color 5b");
				printf("����>ɾ��ѧ����Ϣ\n");
				int d = 5;
				//�ж�����¼��һ����ɼ�����ʾ��������ҳ��
				if (temp1->next == NULL && temp2->next == NULL){
					printf("һ����ѧ����Ϣ¼��Ϊ�գ��޷�������Ϣɾ������(ϵͳ����5���Ӻ󷵻���ҳ��)\n");
					Sleep(5000);
					system("cls");
					break;
				}
				else{
					//ѡ��Ҫɾ��ѧ���İ༶
					while (d != 1 && d != 2){
						printf("��ѡ��Ҫɾ��ѧ���İ༶��1��2��:");
						scanf("%d", &d);
						if (d == 1){
							//�����б���ɾ������
							temp1 = delete(temp1);
							printf("\n\n����	ѧ��	����	��ѧ	Ӣ��\n");
							//����ɾ��ѧ����Ϣ����ܱ���в鿴
							show(temp1);
							add_file(temp1, 1);
						}
						else if (d == 2){
							//�����б���ɾ������
							temp2 = delete(temp2);
							printf("\n\n����	ѧ��	����	��ѧ	Ӣ��\n");
							//����ɾ��ѧ����Ϣ����ܱ���в鿴
							show(temp2);
							add_file(temp2, 2);
						}
						else
							printf("������󣡣����������룡\n");
					}
					printf("\nϵͳ5���Ӻ󽫷�����ҳ�棡");
					//����5�뵹��ʱ��������������ҳ�溯��
					Sleep(5000);
					system("cls");
					break;
				}
			}
				//ʵ�ֲ鿴����ѧ����Ϣ����
			case 5:{
				system("color 5b");
				printf("����>�鿴����ѧ����Ϣ\n\n");
				//�ж�����¼��һ����ɼ�����ʾ��������ҳ��
				if (temp1->next == NULL && temp2->next == NULL){
					printf("һ����ѧ����Ϣ¼��Ϊ�գ��޷����в���ѧ����Ϣ�鿴����(ϵͳ����5���Ӻ󷵻���ҳ��)\n");
					Sleep(5000);
					system("cls");
					break;
				}
				else if (flag == 0){
					printf("һ����ѧ����Ϣδ���кϲ����޷����в���ѧ����Ϣ�鿴����(ϵͳ����5���Ӻ󷵻���ҳ��)\n");
					Sleep(5000);
					system("cls");
					break;
				}
				else{
					printf("\n����	ѧ��	����	��ѧ	Ӣ��\n");
					//����ɸѡѧ����Ϣ�ĺ���
					lose();
					printf("\nϵͳ5���Ӻ󽫷�����ҳ�棡");
					//����5�뵹��ʱ��������������ҳ�溯��
					Sleep(5000);
					system("cls");
					break;
				}
			}
			//�鿴�༶
			case 6:{
				system("color 5b");
				int L=6;
				printf("����>�鿴�༶����ѧ����Ϣ\n\n");
				//�ж�����¼��һ����ɼ�����ʾ��������ҳ��
				if (temp1->next == NULL && temp2->next == NULL){
					printf("һ����ѧ����Ϣ¼��Ϊ�գ��޷�������Ϣ�鿴����(ϵͳ����5���Ӻ󷵻���ҳ��)\n");
					Sleep(5000);
					system("cls");
					break;
				}
				else{
					//ѡ��Ҫ�鿴ѧ���İ༶
					while (L != 1 && L != 2){
						printf("��ѡ��Ҫ�鿴ѧ���İ༶��1��2��:");
						scanf("%d", &L);
						if (L == 1){
							printf("\n\n����	ѧ��	����	��ѧ	Ӣ��\n");
							//����ѧ����Ϣ���ܱ���в鿴
							show(temp1) ;
						}
						else if(L == 2){
							printf("\n\n����	ѧ��	����	��ѧ	Ӣ��\n");
							//����ѧ����Ϣ���ܱ���в鿴
							show(temp2);
						}
						else
							printf("������󣡣����������룡\n");
					}
					printf("\nϵͳ5���Ӻ󽫷�����ҳ�棡");
					//����5�뵹��ʱ��������������ҳ�溯��
					Sleep(5000);
					system("cls");
					break;
				}
			}
				//�˳�ϵͳ
			case 7:{
				printf("�˳�ϵͳ\n");
				quit();
				break;
			}
			default:
				printf("��û���κ�ѡ��\n");
			}
	}
	return 0;
}
//*****************************************************************************************************************************************************************************************************************
Student* create(){                                                 //��������ԭ�б�
	Student *head, *p, *end;
	//����ͷ��β���ָ��
	head = (Student *)malloc(sizeof(Student));
	head->next = NULL;
	end = (Student *)malloc(sizeof(Student));
	while (1){
		//���ο����½��
		p = (Student *)malloc(sizeof(Student));
		printf("\n������������");
		scanf("%s", &p->name);
		printf("������ѧ�ţ�");
		scanf("%d", &p->number);
		printf("���������ĳɼ���");
		scanf("%d", &p->chinese);
	    printf("��������ѧ�ɼ���");
		scanf("%d", &p->math);
		printf("������Ӣ��ɼ���");
		scanf("%d", &p->english);
		//�����������
		p->add = p->chinese + p->math + p->english;
		//�ж��˳�����
		if (p->english == 0)
			break;
		//ͷ���Ϊ��ʱ��β���
		if (head->next == NULL){
			head->next = p;
			end = p;
			end->next = NULL;
		}
		//ͷ��㲻Ϊ��ʱ��β���
		else{
			end->next = p;
			end = p;
			end->next = NULL;
		}
	}
	//���ش���������ͷ
	return head;
}
//*****************************************************************************************************************************************************************************************************************
void file(){               //ʵ�����ļ��еĺϲ�����
	FILE *fp, *p;
	Student look;

	//��ֻ����ʽ���ļ�
	fp = fopen("1.txt", "r+");
	//�ж��ļ������ڵ����
	if (NULL == fp)
		printf("���ļ���ʧ�ܣ�");
	//��д��ʽ���ļ�
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
void add_file(Student *head, int x){             //ʵ��������Ϣ¼���ı�
	FILE *fp;
	if (1 == x){
		fp = fopen("1.txt", "w");
		if (NULL == fp)
			printf("���ļ���ʧ�ܣ�");

		while (head->next != NULL){
			head = head->next;
			fprintf(fp, "%-6s	%-6d	%-6d	%-6d	%-6d\n", head->name, head->number, head->chinese, head->math, head->english);
		}
		fclose(fp);
		printf("��һ��ѧ����Ϣ��¼�룬��������1.txt���У�������\n\n");
	}
	if (2 == x){
		fp = fopen("2.txt", "w");
		if (NULL == fp)
			printf("���ļ���ʧ�ܣ�");

		while (head->next != NULL){
			head = head->next;
			fprintf(fp, "%-6s	%-6d	%-6d	%-6d	%-6d\n", head->name, head->number, head->chinese, head->math, head->english);
		}
		fclose(fp);
		printf("������ѧ����Ϣ��¼�룬��������2.txt���У�������\n\n");
	}
}
//*****************************************************************************************************************************************************************************************************************
int find(Student *head){                                                                           //���ҹ��ܵ�ʵ��
	printf("\n(��ʵ�ֲ��ҹ���)");
	Student *s;
	int num;
	s = (Student *)malloc(sizeof(Student));
	s = head;
	
	printf("��������Ҫ���ҵ�ѧ����Ϣ��ѧ�ţ�");
	scanf("%d", &num);

	while (s->next != NULL){
		s = s->next;
		if (s->number == num){
			printf("%s	%d	%d	%d	%d", s->name, s->number, s->chinese, s->math, s->english);
			if (s->chinese < 60 || s->math < 60 || s->english < 60)
				printf("(��ѧ���ѹҿƣ���)");
			else
				printf("(��ѧ��δ�ҿƣ���)");
		}
	}
	return 0;
}
//*****************************************************************************************************************************************************************************************************************
Student* add(Student*head){                                                                            //��ӹ��ܵ�ʵ��
	Student*s, *p;

	s = (Student *)malloc(sizeof(Student));
	p = (Student *)malloc(sizeof(Student));

	printf("������Ҫ��ӵ�������");
	scanf("%s", &p->name);
	printf("������Ҫ��ӵ�ѧ�ţ�");
	scanf("%d", &p->number);
	printf("������Ҫ��ӵ����ĳɼ���");
	scanf("%d", &p->chinese);
	printf("������Ҫ��ӵ���ѧ�ɼ���");
	scanf("%d", &p->math);
	printf("������Ҫ��ӵ�Ӣ��ɼ���");
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
void Mix(){                                       //ʵ��һ����ɼ��ϲ�����
	FILE *fp, *p;
	Student look;

	fp = fopen("1.txt", "r+");
	if (NULL == fp)
		printf("���ļ���ʧ�ܣ�");
	p = fopen("3.txt", "w");
	while (fscanf(fp, "%s%d%d%d%d", look.name, &look.number, &look.chinese, &look.math, &look.english) != EOF){
		fprintf(p, "%-6s	%-6d	%-6d	%-6d	%-6d\n", look.name, look.number, look.chinese, look.math, look.english);
		printf("%-6s	%-6d	%-6d	%-6d	%-6d\n", look.name, look.number, look.chinese, look.math, look.english);
	}
	fclose(fp);
	fp = fopen("2.txt", "r+");
	if (NULL == fp)
		printf("���ļ���ʧ�ܣ�");
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
Student* sort(Student *head){                                      //�����������򣬲�����������
	Student *s, *p, *new, *end;
	int i = 1, j = 1;
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
//*****************************************************************************************************************************************************************************************************************
Student* delete(Student *head){                                                                           //ɾ����ʵ��
	Student *s,*p;
	int num;
	s = (Student *)malloc(sizeof(Student));
	s = head;

	printf("��������Ҫ���ҵ�ѧ����Ϣ��ѧ�ţ�");
	scanf("%d", &num);

	while (s->next != NULL){
		if (s->next->number == num){
			p = s->next;
			s->next = s->next->next;
			free(p);
			printf("(��ɾ����Ϣ����)");
			break;
		}
		s = s->next;
	}
	return head;
}
//*****************************************************************************************************************************************************************************************************************
void lose(){													                     	//ʵ�ֹҿ�ѧ�����ҹ���
	FILE *fp, *p;
	Student look;

	fp = fopen("3.txt", "r+");
	if (NULL == fp)
		printf("���ļ���ʧ�ܣ�");
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
void show(Student *head){                          //չʾ������Ϣ����
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
	printf("\n(��ʵ���˳�ϵͳ����)");
	exit(0); // �˳�����
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