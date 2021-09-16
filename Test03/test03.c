#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<windows.h>

#define SIZE 30

struct Champion {
	char name[10];
	int hp;
	int mp;
	int speed;
	int range;
	char position[5];
};

struct Champion list[30] = {
{"Ahri", 2090, 843, 550, 330, "MID"},
{"Qiyana", 2120, 1170, 150, 335, "MID"},
{"Senna", 1795, 1115, 600, 330, "STP"},
{"Talon", 2260, 1006, 125, 335, "MID"},
{"Viego", 2175, 0, 225, 345, "JGL"},
{"Irelia", 2195, 1200, 200, 335, "MID"},
{"Leona", 2055, 982, 125, 335, "STP"},
{"Sett", 2181, 0, 125, 340, "MID"},
{"Diana", 2185, 800, 120, 345, "MID"},
{"Kayn", 2030, 1260, 175, 340, "JGL"},
{"Elise", 2115, 1174, 550, 335, "JGL"},
{"Karma", 2149, 1224, 525, 335, "STP"},
{"Morgana", 2090, 1360, 450, 335, "STP"},
{"Ezreal", 2026, 1565, 550, 325, "BTM"},
{"Ashe", 2049, 824, 600, 325, "BTM"},
{"Quinn", 1978, 863, 525, 335, "TOP"},
{"KaiSa", 2096, 990, 525, 335, "BTM"},
{"Sona", 1789, 1105, 550, 325, "TOP"},
{"Taric", 2020, 1320, 150, 340, "STP"},
{"Rell", 2070, 1115, 175, 335, "STP"},
{"Sejuani", 2260, 1080, 150, 340, "JGL"},
{"Shen", 1985, 0, 125, 340, "TOP"}
};

void search(char name[]) 
{
	int num = 0;
	for (int i = 0; i < SIZE; ++i) {
		if (strcmp(name, list[i].name) == 0) {
			printf("Name:%10s, Hp:%5d, Mp:%5d, Speed:%5d, Range:%5d, Position:%5s", list[i].name, list[i].hp, list[i].mp, list[i].speed, list[i].range, list[i].position);
			break;
		}
		else if (num==(SIZE-1)) {
			printf("Put Right Name");
			getchar();
			getchar();
			system("cls");
			return;
		}
		num++;
	}

	getchar();
	getchar();
	system("cls");
}

void insert()
{
	for (int i = 0; i < SIZE; ++i) {
		if (list[i].hp == 0) {
			scanf("%s %d %d %d %d %s", list[i].name, &list[i].hp, &list[i].mp, &list[i].speed, &list[i].range, list[i].position);
			break;
		}
	}

	printf("Insert Complete");
	getchar();
	getchar();
	system("cls");
}

void delete(char name[])
{
	int num = 0;
	for (int i = 0; i < SIZE; ++i) {
		if (strcmp(name, list[i].name) == 0) {
			memcpy(&list[i], &list[SIZE - 1], sizeof(struct Champion));
			break;
		}
		else if (num == (SIZE - 1)) {
			printf("Put Right Name");
			getchar();
			getchar();
			system("cls");
			return;
		}
		num++;
	}
	sort();
	printf("Delete Complete");
	getchar();
	getchar();
	system("cls");
}

void deleteall(char position[])
{
	int num = 0;
	for (int i = 0; i < SIZE; ++i) {
		if (strcmp(position, list[i].position) == 0) {
			memcpy(&list[i], &list[SIZE - 1], sizeof(struct Champion));
		}
		else {
			num++;
		}
	}
	if (num == SIZE) {
		printf("Put Right Name");
		getchar();
		getchar();
		system("cls");
		return;
	}
	sort();
	printf("Delete %s Complete", position);
	getchar();
	getchar();
	system("cls");
}

void printall()
{
	printf("*********************************************************************************\n");
	for (int i = 0; i < SIZE; ++i) {
		if (list[i].hp == 0) {
			continue;
		}
		printf("%02d. Name:%10s, Hp:%5d, Mp:%5d, Speed:%5d, Range:%5d, Position:%5s", i + 1, list[i].name, list[i].hp, list[i].mp, list[i].speed, list[i].range, list[i].position);
		putchar('\n');
	}
	printf("*********************************************************************************\n");
	getchar();
}

void findmaxhp()
{
	int max = list[0].hp;
	for (int i = 0; i < SIZE; ++i) {
		if (list[i].hp > max) {
			max = list[i].hp;
		}
	}
	for (int i = 0; i < SIZE; ++i) {
		if (max == list[i].hp) {
			printf("Name:%10s, Hp:%5d, Mp:%5d, Speed:%5d, Range:%5d, Position:%5s", list[i].name, list[i].hp, list[i].mp, list[i].speed, list[i].range, list[i].position);
			putchar('\n');
		}
	}

	getchar();
	getchar();
	system("cls");
}

void sortbyhp()
{
	int max;
	struct Champion temp;
	for (int i = 0; i < SIZE-1; ++i) {
		max = i;
		for (int j = i; j < SIZE - 1; ++j) {
			if (list[j].hp > list[max].hp)
				max = j;
		}
		memcpy(&temp, &list[i], sizeof(struct Champion));
		memcpy(&list[i], &list[max], sizeof(struct Champion));
		memcpy(&list[max], &temp, sizeof(struct Champion));
	}

	printf("Sort Complete");
	getchar();
	system("cls");
}

int sort()
{
	for (int i = 0; i < SIZE - 1; ++i) {
		if (list[i].hp == 0) {
			for (int j = i + 1; j < SIZE - 1; ++j) {
				if (list[j].hp != 0) {
					memcpy(&list[i], &list[j], sizeof(struct Champion));
					memcpy(&list[j], &list[SIZE-1], sizeof(struct Champion));
					break;
				}
			}
		}
	}
}

int main()
{
	while (1) {
		char choice[15], name[10], position[5];
		
		printf("1. Search\n2. Insert\n3. Delete\n4. DeleteAll\n5. PrintAll\n6. FindMaxHp\n7. SortByHp\n");
		printf("**************************\nEnter a Command: ");

		scanf("%s", choice);
		getchar();

		if (strcmp(choice, "Search") == 0) {
			printf("Name: ");
			scanf("%s", name);
			search(name);
		}
		else if (strcmp(choice, "Insert") == 0) {
			insert();
		}
		else if (strcmp(choice, "Delete") == 0) {
			printf("Name: ");
			scanf("%s", name);
			delete(name);
		}
		else if (strcmp(choice, "DeleteAll") == 0) {
			printf("Position: ");
			scanf("%s", position);
			deleteall(position);
		}
		else if (strcmp(choice, "PrintAll") == 0) {
			printall();
		}
		else if (strcmp(choice, "FindMaxHp") == 0) {
			findmaxhp();
		}
		else if (strcmp(choice, "SortByHp") == 0) {
			sortbyhp();
		}
		else {
			printf("Wrong Command");
			putchar('\n');
		}
	}
}