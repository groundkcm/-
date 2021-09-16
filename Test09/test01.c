#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<time.h>

#define CLOCKS_PER_SEC 1000

typedef struct Champion {
	char position[20];
	char name[15];
	int hp;
	int sp;
	int dp;
}champ;

champ scan = { 0 };

typedef struct NODE {
	champ data;
	struct NODE* next;
}SL;

SL* head;
SL* tail;

typedef struct Champion_D {
	char position[20];
	char name[15];
	int hp;
	int sp;
	int dp;
}champ_d;
champ_d dscan = { 0 };

typedef struct NODE_D {
	champ_d data;
	struct NODE* next;
	struct NODE* front;
}DL;

DL* dhead;
DL* dtail;

void Array_SL()
{
	FILE* stream;
	int num = 0;
	stream = fopen("LOLDic.txt", "r");
	while(1) {
		SL* new = malloc(sizeof(SL));
		fscanf(stream, "%s%s%d%d%d", &scan.position, &scan.name, &scan.hp, &scan.sp, &scan.dp);
		if (num==10000000) {
			break;
		}
		else if (num == 0) {
			new->data = scan;
			new->next = new;
			head = new;
			tail = new;
			num++;
			continue;
		}
		new->data = scan;
		new->next = head;
		head = new;
		tail->next = new;
		num++;
	}
	fclose(stream);
}

void Array_DL()
{
	FILE* stream;
	int num = 0;
	stream = fopen("LOLDic.txt", "r");
	while (1) {
		DL* new = malloc(sizeof(DL));
		fscanf(stream, "%s%s%d%d%d", &dscan.position, &dscan.name, &dscan.hp, &dscan.sp, &dscan.dp);
		if (num == 10000000) {
			break;
		}
		else if (num == 0) {
			new->data = dscan;
			new->next = new;
			dhead = new;
			dtail = new;
			new->front = new;
			num++;
			continue;
		}
		new->data = dscan;
		dhead->front = new;
		new->next = dhead;
		dhead = new;
		new->front = dtail;
		dtail->next = new;
		num++;
	}
	fclose(stream);
}

void printall_SL()
{
	SL* p = head;
	printf("********************************************************************************\n");
	do {
		for (int i = 0; i < 1000000; i++) {
			p = p->next;
			if (p == head) {
				return;
			}
		}
		printf("Position:%17s, Name:%13s, Hp:%5d, Sp:%5d, Dp:%5d\n", p->data.position, p->data.name, p->data.hp, p->data.sp, p->data.dp);
		p = p->next;
	} while (p != head);
	printf("********************************************************************************\n");
}
void printall_DL()
{
	DL* p = dhead;
	printf("********************************************************************************\n");
	do {
		for (int i = 0; i < 1000000; i++) {
			p = p->next;
			if (p == dhead) {
				return;
			}
		}
		printf("Position:%17s, Name:%13s, Hp:%5d, Sp:%5d, Dp:%5d\n", p->data.position, p->data.name, p->data.hp, p->data.sp, p->data.dp);
		p = p->next;
	} while (p != dhead);
	printf("********************************************************************************\n");
}

void sortbyname_SL()
{
	SL* temp = malloc(sizeof(SL));
	SL* max;
	SL* t = head;
	do {
		max = t;
		for (SL* p = t->next; p != head; p = p->next) {
			if (strcmp(max->data.name, p->data.name) > 0) {
				max = p;
			}
		}
		temp->data = max->data;
		max->data = t->data;
		t->data = temp->data;
		t = t->next;
	} while (t != head);
}
void sortbyname_DL()
{
	DL* temp = malloc(sizeof(DL));
	DL* max;
	DL* t = dhead;
	do {
		max = t;
		for (DL* p = t->next; p != dhead; p = p->next) {
			if (strcmp(max->data.name, p->data.name) > 0) {
				max = p;
			}
		}
		temp->data = max->data;
		max->data = t->data;
		t->data = temp->data;
		t = t->next;
	} while (t != dhead);
}
clock_t start, end, start1, end1;
void findtarget_SL()
{
	char name[15];
	printf("Name: ");
	scanf("%s", name);
	start = clock();
	SL* p = head;
	do {
		if (strcmp(p->data.name, name) == 0) {
			printf("Position:%15s, Name:%10s, Hp:%5d, Sp:%5d, Dp:%5d\n", p->data.position, p->data.name, p->data.hp, p->data.sp, p->data.dp);
			return;
		}
		p = p->next;
	} while (p != head);
	printf("Not Exist\n");
}
void findtarget_DL()
{
	char name[15];
	printf("Name: ");
	scanf("%s", name);
	start1 = clock();
	DL* p = dhead;
	do {
		if (strcmp(p->data.name, name) == 0) {
			printf("Position:%15s, Name:%10s, Hp:%5d, Sp:%5d, Dp:%5d\n", p->data.position, p->data.name, p->data.hp, p->data.sp, p->data.dp);
			return;
		}
		p = p->next;
	} while (p != dhead);
	printf("Not Exist\n");
}
int main()
{
	Array_SL();
	Array_DL();
	double x, y = 0;
	putchar('\n');
	start = clock();
	printall_SL();
	end = clock();
	x = (end - start)/(double)CLOCKS_PER_SEC;
	start1 = clock();
	printall_DL();
	end1 = clock();
	y = (end1 - start1) / (double)CLOCKS_PER_SEC;
	printf("1. PrintAll_SL(): %lf(段), PrintAll_Dl(): %lf(段)", x, y);
	x, y = 0;
	getchar();
	/*
	start = time(NULL);
	sortbyname_SL();
	end = time(NULL);
	x = (double)(end - start)/CLOCKS_PER_SEC;
	start = time(NULL);
	sortbyname_DL();
	end = time(NULL);
	y = (double)(end - start)/CLOCKS_PER_SEC;
	printf("1. SortByName_SL(): %lf(段), SortByName_Dl(): %lf(段)", x, y);
	x, y = 0;
	getchar();
	*/
	findtarget_SL();
	end = clock();
	x = (end - start) / (double)CLOCKS_PER_SEC;
	findtarget_DL();
	end1 = clock();
	y = (end1 - start1) / (double)CLOCKS_PER_SEC;
	printf("1. FindTarget_SL(): %lf(段), FindTarget_Dl(): %lf(段)", x, y);
	x, y = 0;
}