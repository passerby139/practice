#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

typedef struct number {
	int num;
	struct number *next;
}number;

int add1, add2;

int create(number *head){
	number *p,*r;
	char c;
	int i = 0;

	r = (number *)malloc(sizeof(number));
	while (1){
		p = (number *)malloc(sizeof(number));
		scanf("%d", &p->num);
		if (head->next == NULL){
			head->next = p;
			r=p;
		}
		else{
			r->next =p;
			r=p;
		}
		i++;
		c = getchar();
		if (c == 41)
			break;
		getchar();
	}
	r->next = NULL;
	return i;
}

void add(number *list1, number *list2){
	number *r, *s;
	int i;



	r = (number *)malloc(sizeof(number));
	s = (number *)malloc(sizeof(number));

	r->next = list1->next;
	s->next = list2->next;


	while (1){

		r->next->num = r->next->num + s->next->num;              //ÎÊÌâ
		if (r->next->num >= 10){
			i = r->next->num / 10;
			r->next->num = r->next->num % 10;
			r->next->next->num = r->next->next->num + i;
		}
		if ((r->next->next == NULL) || (s->next->next == NULL))
			break;
		r = r->next;
		s = s->next;
	}
	s->next = list1->next;
	while (1){
		s = s->next;
		printf("%d", s->num);
		if (s->next == NULL)
			break;
	}
}

int main(int argc, char *argv[]) {
	number *list1,*list2;
	int i=0;

	list1 = (number *)malloc(sizeof(number));
	list1->next = NULL;
	list2 = (number *)malloc(sizeof(number));
	list2->next = NULL;
	
	getchar();
	add1=create(list1);
	getchar();
	getchar();
	add2=create(list2);
	if (add1 >= add2)
		add(list1, list2);
	else
		add(list2, list1);
	
	system("pause");
	return 0;
}