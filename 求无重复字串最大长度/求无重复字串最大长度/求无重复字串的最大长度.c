#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>

int find(char *s){
	int i, j, k;
	int add = 1;
	int x;

	x = strlen(s);
	if (x == 2)
		add = 0;
	for (i = 2,j = 1; i <= (x - 1);i++){
		for (k = j; k < i; k++){
			if (add < (i - j))
				add = i - j;
			if (*(s+i)==*(s+k)){
				j++;
				i = j ;
				break;
			}
			else
				continue;
		}
	}
	return add;
}

int main(){
	int add;
	char arr[15],*s;
	int x;
	
	gets(arr);
	s = &arr[0];

	add=find(s);
	printf("%d\n", add);

	system("pause");
	return 0;
}