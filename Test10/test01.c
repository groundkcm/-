#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

#define CLOCKS_PER_SEC 1000
clock_t start, end;
double x = 0;

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

typedef struct TREE {
	champ data;
	struct TREE* left;
	struct TREE* right;
}BT;

BT* root = NULL;

void Array_SL()
{
	FILE* stream;
	int num = 0;
	stream = fopen("LOLDic.txt", "r");
	while (1) {
		SL* new = malloc(sizeof(SL));
		fscanf(stream, "%s%s%d%d%d", &scan.position, &scan.name, &scan.hp, &scan.sp, &scan.dp);
		if (feof(stream) != 0) {
			break;
		}
		else if (num == 0) {
			new->data = scan;
			new->next = NULL;
			head = new;
			num++;
			continue;
		}
		new->data = scan;
		new->next = head;
		head = new;
		num++;
	}
	fclose(stream);
}
SL* sortedmerge(SL* a, SL* b)
{
	if (a == NULL) {
		return (b);
	}
	else if (b == NULL) {
		return (a);
	}
	SL* result = NULL;
	if (strcmp(a->data.name, b->data.name) < 0) {
		result = a;
		a = a->next;
	}
	else {
		result = b;
		b = b->next;
	}
	SL* p = result;
	while (a != NULL && b != NULL) {
		if (strcmp(a->data.name, b->data.name) < 0) {
			p->next = a;
			a = a->next;
			p = p->next;
		}
		else {
			p->next = b;
			b = b->next;
			p = p->next;
		}
	}
	if (a == NULL) {
		p->next = b;
	}
	else {
		p->next = a;
	}
	return(result);
}
void fbsplit(SL* source, SL** front, SL** back)
{
	SL* fast;
	SL* slow;
	if (source == NULL || source->next == NULL) {
		*front = source;
		*back = NULL;
	}
	else {
		slow = source;
		fast = source->next;
		while (fast != NULL) {
			fast = fast->next;
			if (fast != NULL) {
				slow = slow->next;
				fast = fast->next;
			}
		}
		*front = source;
		*back = slow->next;
		slow->next = NULL;
	}
}
void sortbyname_SL(SL** headref)
{
	SL* head = *headref;
	SL* a;
	SL* b;
	if ((head == NULL) || (head->next == NULL)) {
		return;
	}
	fbsplit(head, &a, &b);
	sortbyname_SL(&a);
	sortbyname_SL(&b);
	*headref = sortedmerge(a, b);
}
void Tree()
{
	start = clock();
	SL* p = head;
	SL* d = malloc(sizeof(SL));
	do {
		root = insert_BT(root, p);
		d = p;
		p = p->next;
		free(d);
	} while (p != NULL);
	end = clock();
	x = (end - start) / (double)CLOCKS_PER_SEC;
	printf("Tree(): %lf(s)\n", x);
}
BT* search(BT* root, BT* new)
{
	if (!root) {
		printf("Not Exist\n");
		return NULL;
	}
	if (strcmp(root->data.name, new->data.name) == 0) {
		return root;
	}
	else {
		if (strcmp(root->data.name, new->data.name) > 0) {
			return search(root->left, new);
		}
		else {
			return search(root->right, new);
		}
	}
}
void searchbyname_BT(char name[])
{
	start = clock(); 
	BT* new = malloc(sizeof(BT));
	new->data.dp, new->data.hp, new->data.position, new->data.sp = NULL;
	strcpy(new->data.name, name);
	BT* p = search(root, new);
	if (p == NULL) {
		end = clock();
		return;
	}
	printf("Position:%10s, Name:%15s, Hp:%5d, Sp:%5d, Dp:%5d\n", p->data.position, p->data.name, p->data.hp, p->data.sp, p->data.dp);
	end = clock();
	x = (end - start) / (double)CLOCKS_PER_SEC;
	printf("SearchByName_BT(): %lf(s)\n", x);
}
int insert_BT(BT* root, BT* new)
{
	if (root == NULL) {
		root = (BT*)malloc(sizeof(BT));
		root->left = root->right = NULL;
		root->data = new->data;
		return root;
	}
	if (strcmp(root->data.name, new->data.name) == 0) {
		end = clock();
		printf("Already Used");
	}
	else if (strcmp(root->data.name, new->data.name) > 0) {
		root->left = insert_BT(root->left, new);
	}
	else {
		root->right = insert_BT(root->right, new);
	}
	return root;
}
void delete_BT(BT* root, BT* new)
{
	BT* r = NULL;
	BT* p = root;
	while (strcmp(p->data.name, new->data.name) != 0 && (p != NULL)) {
		r = p;
		if (strcmp(p->data.name, new->data.name) > 0)
			p = p->left;
		else if (strcmp(p->data.name, new->data.name) < 0)
			p = p->right;
	}
	if (p == NULL) {
		printf("NOT Exist");
		return;
	}
	if (p->right != NULL && p->left != NULL) {
		r = p;
		BT* tnode = p->left;
		while (tnode->right != NULL) {
			r = tnode;
			tnode = tnode->right;
		}
		if (r->left==tnode) {
			r->left = tnode->left;
		}
		else {
			r->right = tnode->right;
		}
		p->data = tnode->data;
		p = tnode;
	}
	else if (p->right == NULL && p->left == NULL) {
		if (r != NULL) {
			if (r->left == p) r->left = NULL;
			else r->right = NULL;
		}
		else root = NULL;
	}
	else {
		BT* child;
		if (p->left != NULL) child = p->left;
		else child = p->right;
		if (r != NULL) {
			if (r->left == p)r->left = child;
			else r->right = child;
		}
		else root = child;
	}
	free(p);
}
int i = 0;
void printall_BT(BT* root)
{
	if (root == NULL) {
		return;
	}
	BT* p = root;
	printall_BT(root->left);
	i++;
	if (i == 1000000) {
		printf("Position:%20s, Name:%15s, Hp:%5d, Sp:%5d, Dp:%5d\n", p->data.position, p->data.name, p->data.hp, p->data.sp, p->data.dp);
		i = 0;
	}
	printall_BT(root->right);
}
int main()
{
	Array_SL();/*
	start = clock();
	sortbyname_SL(&head);
	end = clock();
	x = (end - start) / (double)CLOCKS_PER_SEC;
	printf("SortByName_SL(): %lf(s)\n", x);*/
	Tree();
	BT* new;
	while (1) {
		char name[15];
		int choice = 0;

		printf("1. Search_BT [name]\n2. Insert_BT\n3. Delete_BT [name]\n4. PrintAll_BT\n");
		printf("*************************\nEnter a Command: ");

		scanf("%d", &choice);
		getchar();

		switch (choice) {
		case 1:
			printf("Name: ");
			scanf("%s", name);
			searchbyname_BT(name);
			break;
		case 2:
			new = malloc(sizeof(BT));
			printf("Input: ");
			scanf("%s%s%d%d%d", &new->data.position, &new->data.name, &new->data.hp, &new->data.sp, &new->data.dp);
			start = clock();
			root = insert_BT(root, new);
			end = clock();
			x = (end - start) / (double)CLOCKS_PER_SEC;
			printf("Insert_BT(): %lf(s)\n", x);
			break;
		case 3:
			printf("Name: ");
			scanf("%s", name);
			new = malloc(sizeof(BT));
			new->data.dp, new->data.hp, new->data.position, new->data.sp = NULL;
			strcpy(new->data.name, name);
			start = clock();
			delete_BT(root, new);
			end = clock();
			x = (end - start) / (double)CLOCKS_PER_SEC;
			printf("Delete_BT(): %lf(s)\n", x);
			break;
		case 4:
			start = clock();
			system("cls");
			printf("********************************************************************************\n");
			printall_BT(root);
			printf("********************************************************************************\n");
			end = clock();
			x = (end - start) / (double)CLOCKS_PER_SEC;
			printf("PrintAll_BT(): %lf(s)\n", x);
			continue;
		default:
			printf("Wrong Number");
			break;
		}
		getchar();
		getchar();
		system("cls");
	}
}