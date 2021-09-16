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

struct Champion list[SIZE] = {
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

void search(char name[], int i)
{
	if (strcmp(name, list[i].name) == 0) {
		printf("Name:%10s, Hp:%5d, Mp:%5d, Speed:%5d, Range:%5d, Position:%5s\n", list[i].name, list[i].hp, list[i].mp, list[i].speed, list[i].range, list[i].position);
		return;
	}
	else if (i == SIZE - 1) {
		printf("Put Right Name");
		return;
	}

	search(name, i + 1);
}

void insert(int i)
{
	char name[10];
	int num = 0;

	if (list[i].hp==0) {
		scanf("%s %d %d %d %d %s", name, &list[i].hp, &list[i].mp, &list[i].speed, &list[i].range, list[i].position);
		name_search(name, num, i);
		return;
	}
	else if (i == SIZE - 1) {
		printf("Put Right Name");
		return;
	}

	insert(i + 1);
}

int name_search(char name[], int num, int i)
{
	if (num == SIZE) {
		strcpy(list[i].name, name);
		printf("Insert Complete");
		return;
	}
	else if (strcmp(name, list[num].name) == 0) {
		printf("Already Used");
		memcpy(&list[i], &list[SIZE - 1], sizeof(struct Champion));
		return;
	}
	name_search(name, num + 1, i);
}

void delete(char name[], int i)
{
	if (strcmp(name, list[i].name) == 0) {
		memcpy(&list[i], &list[SIZE - 1], sizeof(struct Champion));
		printf("Delete Complete");
		return;
	}
	else if (i == SIZE - 1) {
		printf("Put Right Name");
		return;
	}

	delete(name, i + 1);
}

int deleteall(char position[], int num, int i)
{
	if (i == SIZE) {
		return num;
	}
	else if (strcmp(position, list[i].position) == 0) {
		memcpy(&list[i], &list[SIZE - 1], sizeof(struct Champion));
	}
	else {
		num++;
	}

	deleteall(position,num, i + 1);
}

void printall(int i)
{
	if (list[i].hp == 0) {
		return;
	}
	printf("%02d. Name:%10s, Hp:%5d, Mp:%5d, Speed:%5d, Range:%5d, Position:%5s\n", i+1, list[i].name, list[i].hp, list[i].mp, list[i].speed, list[i].range, list[i].position);

	printall(i + 1);
}

void findmaxhp(int max, int i)
{
	if (i == SIZE) {
		i = 0;
		findmaxhp_print(max, i);
		return;
	}
	else if (list[i].hp>max) {
		max = list[i].hp;
	}
	findmaxhp(max, i+1);
}

int findmaxhp_print(int max, int i)
{
	if (i == SIZE) {
		return;
	}
	else if (list[i].hp == max) {
		printf("Name:%10s, Hp:%5d, Mp:%5d, Speed:%5d, Range:%5d, Position:%5s\n", list[i].name, list[i].hp, list[i].mp, list[i].speed, list[i].range, list[i].position);
	}
	findmaxhp_print(max, i+1);
}

struct Champion temp;

void sortbyhp(int max_sort, int i, int j)
{
	if (i == SIZE) {
		printf("Sort Complete");
		return;
	}
	max_sort = i;
	j = i;
	max_sort = sortbyhp_max(max_sort, j);

	memcpy(&temp, &list[i], sizeof(struct Champion));
	memcpy(&list[i], &list[max_sort], sizeof(struct Champion));
	memcpy(&list[max_sort], &temp, sizeof(struct Champion));
	
	
	sortbyhp(max_sort, i + 1, j);
}

int sortbyhp_max(int max_sort, int j)
{
	if (j == SIZE) {
		return max_sort;
	}
	else if (list[j].hp > list[max_sort].hp) {
		max_sort = j;
	}

	sortbyhp_max(max_sort, j + 1);
}

void sort(int i, int j)
{
	if (i == SIZE) {
		return;
	}
	else if (list[i].hp == 0) {
		j = i + 1;
		sort_j(i, j);
	}

	sort(i + 1, j);
}

int sort_j(int i, int j)
{
	if (j == SIZE) {
		return;
	}
	else if (list[j].hp != 0) {
		memcpy(&list[i], &list[j], sizeof(struct Champion));
		memcpy(&list[j], &list[SIZE-1], sizeof(struct Champion));
		return;
	}

	sort_j(i, j + 1);
}

int main()
{
	while (1) {
		int i = 0, j = 0, choice = 0, num = 0;
		char name[10], position[5];
		int max = list[0].hp, max_sort = 0;

		printf("1. Search_R\n2. Insert_R\n3. Delete_R\n4. DeleteAll_R\n5. PrintAll_R\n6. FindMaxHp_R\n7. SortByHp_R\n");
		printf("******************\nEnter a Number: ");

		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("Name: ");
			scanf("%s", name);
			search(name, i);

			getchar();
			getchar();
			system("cls");
			break;
		case 2:
			insert(i);

			getchar();
			getchar();
			system("cls");
			break;
		case 3:
			printf("Name: ");
			scanf("%s", name);
			delete(name, i);

			sort(i, j);
			getchar();
			getchar();
			system("cls");
			break;
		case 4:
			printf("Position: ");
			scanf("%s", position);
			num = deleteall(position, num, i);

			if (num == SIZE) {
				printf("Put Right Position");
				getchar();
				getchar();
				system("cls");
				continue;
			}

			printf("Delete %s Complete", position);
			sort(i, j);
			getchar();
			getchar();
			system("cls");
			break;
		case 5:
			printf("*****************************************************************************\n");
			printall(i);
			printf("*****************************************************************************\n");

			getchar();
			getchar();
			system("cls");
			break;
		case 6:
			findmaxhp(max, i, j);
			getchar();
			getchar();
			system("cls");
			break;
		case 7:
			sortbyhp(max_sort, i, j);
			getchar();
			getchar();
			system("cls");
			break;
		default:
			printf("Wrong Number");
			getchar();
			getchar();
			system("cls");
		}
	}
}