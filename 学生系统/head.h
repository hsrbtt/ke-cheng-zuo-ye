#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct student{
	int stunum;
	char name[20];
	int score; 
}student;//����ѧ����Ϣ 

typedef struct node{
	student student;
	struct node*next;
}node;//����ڵ���Ϣ 
void output();
void inputstudent(node*head);
void putoutstudent(node*head);
void countstudent(node*head);
void findstudent(node*head);
void modstudent(node*head);
void delstudent(node*head);
void sortstudent(node*head);
void savestudent(node*head);
node*readstudent(node*p);
