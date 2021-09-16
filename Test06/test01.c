#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<windows.h>

#define SIZE 30

typedef struct Champion {
	char name[15];
	int hp;
	int mp;
	int range;
	int speed;
	char position[5];
}champ;

typedef struct NODE {
	champ data;
	struct NODE* next;
}node;

node* head;
node* tail;
int memnum = 22;

struct Champion list[SIZE] = {
{"Ezreal", 2026, 1565, 550, 325, "BTM"},
{"Morgana", 2090, 1360, 450, 335, "STP"},
{"Taric", 2020, 1320, 150, 340, "STP"},
{"Kayn", 2030, 1260, 175, 340, "JGL"},
{"Karma", 2149, 1224, 525, 335, "STP"},
{"Irelia", 2195, 1200, 200, 335, "MID"},
{"Elise", 2115, 1174, 550, 335, "JGL"},
{"Qiyana", 2120, 1170, 150, 335, "MID"},
{"Rell", 2070, 1115, 175, 335, "STP"},
{"Senna", 1795, 1115, 600, 330, "STP"},
{"Sona", 1789, 1105, 550, 325, "TOP"},
{"Sejuani", 2260, 1080, 150, 340, "JGL"},
{"Talon", 2260, 1006, 125, 335, "MID"},
{"KaiSa", 2096, 990, 525, 335, "BTM"},
{"Leona", 2055, 982, 125, 335, "STP"},
{"Quinn", 1978, 863, 525, 335, "TOP"},
{"Ahri", 2090, 843, 550, 330, "MID"},
{"Ashe", 2049, 824, 600, 325, "BTM"},
{"Diana", 2185, 800, 120, 345, "MID"},
{"Sett", 2181, 0, 125, 340, "MID"},
{"Shen", 1985, 0, 125, 340, "TOP"},
{"Viego", 2175, 0, 225, 345, "JGL"}
};

void Array2LinkedList()
{
	int num = 0;
	for (int i = SIZE; i > 0; i--) {
		node* new = malloc(sizeof(node));
		if (list[i - 1].hp == 0) {
			continue;
		}
		else if (num == 0) {
			new->data = list[i - 1];
			new->next = new;
			head = new;
			tail = new;
			num++;
			continue;
		}
		new->data = list[i - 1];
		new->next = head;
		head = new;
		tail->next = new;
		num++;
	}
}

node* search(char str[])
{
	node* p = malloc(sizeof(node));
	int i;
	for (p = head, i = 0; i < memnum; p = p->next, i++) {
		if (strcmp(p->data.name, str)==0) {
			return p;
		}
	}
	printf("Not Exist\n");
	return NULL;
}

void search_SL(char name[])
{
	node* p = search(name);
	if (p == NULL) {
		return;
	}
	printf("Name:%10s, Hp:%5d, Mp:%5d, Speed:%5d, Range:%5d, Position:%5s\n", p->data.name, p->data.hp, p->data.mp, p->data.speed, p->data.range, p->data.position);
}

void insert_SL(char name[])
{
	//for루프 끝까지 안돔 외우면서 고치기
	node* p = NULL;
	p = search(name);
	if (p != NULL) {
		printf("Already Used\n");
	} else {
		node* new = malloc(sizeof(node));
		printf("Input Data: ");
		scanf("%s %d %d %d %d %s", new->data.name, &new->data.hp, &new->data.mp, &new->data.speed, &new->data.range, new->data.position);
		for (p = head; p->next != head; p = p->next) {
			if (p == head && (new->data.mp >= p->data.mp)) {
				new->next = head;
				head = new;
				tail->next = new;
				break;
			}
			else if (p->data.mp >= new->data.mp && new->data.mp >= p->next->data.mp) {
				new->next = p->next;
				p->next = new;
				break;
			}
			else if (p == tail && (p->data.mp >= new->data.mp)) {
				new->next = p->next;
				p->next = new;
				tail = new;
				break;
			}
		}
		memnum++;
		printf("Insert Complete");
	}
}

void delete_SL(char str[])
{
	node* p = malloc(sizeof(node));
	int i;
	for (p = tail->next, i = 0; i < memnum; p = p->next, i++) {
		if (strcmp(p->next->data.name, str) == 0) {
			delete(p);
			break;
		}
		for (int j = 0; j < memnum; j++) {
			if (strcmp(p->next->data.position, str) == 0) {
				delete(p);
				continue;
			}
			break;
		}
	}
	printf("Delete Complete");
}

int delete(node* p) 
{
	node* remove = p->next;
	if (p->next == head) {
		head = p->next->next;
	}
	else if (p->next == tail) {
		tail = p;
	}
	p->next = p->next->next;
	free(remove);
	memnum--;
}

void printall_SL()
{
	node* p;
	int i;
	printf("********************************************************************************\n");
	for (p = head, i = 0; i < memnum; p = p->next, i++) {
		printf("%02d.Name:%10s, Hp:%5d, Mp:%5d, Speed:%5d, Range:%5d, Position:%5s\n", i+1, p->data.name, p->data.hp, p->data.mp, p->data.speed, p->data.range, p->data.position);
	}
	printf("********************************************************************************\n");
}

void findmaxhp_SL()
{
	int max = head->data.hp;
	node* p;
	int i;
	for (p = head, i = 0; i < memnum; p = p->next, i++) {
		if (p->data.hp > max) {
			max = p->data.hp;
		}
	}
	for (p = head, i = 0; i < memnum; p = p->next, i++) {
		if (p->data.hp == max) {
			printf("Name:%10s, Hp:%5d, Mp:%5d, Speed:%5d, Range:%5d, Position:%5s\n", p->data.name, p->data.hp, p->data.mp, p->data.speed, p->data.range, p->data.position);
		}
	}
}

void sortbyhp_SL()
{
	node* temp = malloc(sizeof(node));
	node* max;
	node* t;
	int i;
	for (t = head, i = 0; i < memnum; t = t->next, i++) {
		max = t;
		for (node* p = t->next; p->next != head->next; p = p->next) {
			if (p->data.hp > max->data.hp) {
				max = p;
			}
		}
		temp->data = max->data;
		max->data = t->data;
		t->data = temp->data;
	}
	printf("Sort Complete");
}

int main()
{
	tail = malloc(sizeof(node));
	head = NULL;
	Array2LinkedList();

	while (1) {
		
		char name[15], position[5];
		int choice = 0;

		printf("1. Search_SL [name]\n2. Insert_SL\n3. Delete_SL [name]\n4. DeleteAll_SL [position]\n5. PrintAll_SL\n6. FindMaxHp_SL\n7. SortByHp_SL\n");
		printf("*************************\nEnter a Command: ");

		scanf("%d", &choice);
		getchar();

		switch (choice) {
		case 1:
			printf("Name: ");
			scanf("%s", name);
			search_SL(name);
			break;
		case 2:
			printf("Name: ");
			scanf("%s", name);
			insert_SL(name);
			break;
		case 3:
			printf("Name: ");
			scanf("%s", name);
			delete_SL(name);
			break;
		case 4:
			printf("Position: ");
			scanf("%s", position);
			delete_SL(position);
			break;
		case 5:
			system("cls");
			printall_SL();
			getchar();
			continue;
		case 6:
			findmaxhp_SL();
			break;
		case 7:
			sortbyhp_SL();
			break;
		default:
			printf("Wrong Number");
			break;
		}
		getchar();
		getchar();
		system("cls");
	}
}