#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<windows.h>

#define SIZE 30

void sort_j(int i, int j);
int sortbyhp_max(int j, int max_sort);
void findmaxhp_print(int i, int max);

struct Champion {
	char name[15];
	int hp;
	int mp;
	int range;
	int speed;
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

void search(char name[], int num, int i)
{
	if (strcmp(name, list[i].name) == 0) {
		printf("Name:%10s, Hp:%5d, Mp:%5d, Range:%5d, Speed:%5d, Position:%5s", list[i].name, list[i].hp, list[i].mp, list[i].range, list[i].speed, list[i].position);
		putchar('\n');
		return;
	}
	else if (num == SIZE - 1) {
		printf("Put Right Name");
		return;
	}
	search(name, num + 1, i + 1);
}

void insert(int num, int i)
{
	if (list[i].hp == 0) {
		scanf("%s %d %d %d %d %s", name, &list[i].hp, &list[i].mp, &list[i].speed, &list[i].range, list[i].position);
		name_search(name, num, i);
		printf("Insert Complete");
		return;
	}
	else if (i == (SIZE - 1)) {
		printf("Data is Full");
		return;
	}
	insert(num , i + 1);
}

int name_search(char name[], int num, int i)
{
	if (strcmp(list[num].name, name) == 0) {
		printf("Already Used");
		return;
	}
	else if (num == SIZE - 1) {
		strcpy(list[i].name, name);
		return;
	}

	name_search(name, num + 1, i);
}

void delete(char name[], int num, int i)
{
	if (strcmp(name, list[i].name) == 0) {
		memcpy(&list[i], &list[SIZE - 1], sizeof(struct Champion));
		
		printf("Delete Complete");
		return;
	}
	else if (num == (SIZE - 1)) {
		printf("Put Right Name");
		return;
	}
	delete(name, num + 1, i + 1);
}

int deleteall(char position[], int num, int i)
{
	if (i == SIZE) {
		return num;
	}
	else if (strcmp(list[i].position, position) == 0) {
		memcpy(&list[i], &list[SIZE - 1], sizeof(struct Champion));
	}
	else {
		num++;
	}
	deleteall(position, num, i + 1);
}

void printall(int i)
{
	if (list[i].hp == 0) {
		return;
	}
	printf("%02d: Name:%10s, Hp:%5d, Mp:%5d, Range:%5d, Speed:%5d, Position:%5s", i + 1, list[i].name, list[i].hp, list[i].mp, list[i].range, list[i].speed, list[i].position);
	putchar('\n');

	printall(i + 1);

}

void findmaxhp(int i, int max)
{
	if (i == SIZE) {
		i = 0;
		findmaxhp_print(i, max);
		return;
	}
	else if (list[i].hp > max) {
		max = list[i].hp;
	}
	
	findmaxhp(i + 1, max);
}

void findmaxhp_print(int i, int max) 
{
	if (i == SIZE) {
		return;
	}
	else if (max == list[i].hp) {
		printf("Name:%10s, Hp:%5d, Mp:%5d, Range:%5d, Speed:%5d, Position:%5s", list[i].name, list[i].hp, list[i].mp, list[i].range, list[i].speed, list[i].position);
		putchar('\n');
	}
	findmaxhp_print(i + 1, max);
}

struct Champion temp;

void sortbyhp(int i,int j, int max_sort)
{
	if (i == SIZE-1) {
		return;
	}
	max_sort = i;
	j = i;
	max_sort = sortbyhp_max(j, max_sort);

	memcpy(&temp, &list[max_sort], sizeof(struct Champion));		
	memcpy(&list[max_sort], &list[i], sizeof(struct Champion));
	memcpy(&list[i], &temp, sizeof(struct Champion));

	sortbyhp(i + 1, j, max_sort);
}

int sortbyhp_max(int j, int max_sort)
{
	if (j == SIZE) {
		return max_sort;
	}
	else if (list[j].hp > list[max_sort].hp) {
		max_sort = j;
	}
	
	sortbyhp_max(j + 1, max_sort);
}

void sort(int i, int j)
{
	if (i == SIZE - 1) {
		return;
	}
	else if (list[i].hp == 0) {
		j = i + 1;
		sort_j(i, j);
	}
	
	sort(i + 1, j);
}

void sort_j(int i, int j)
{
	if (j == SIZE) {
		return;
	}
	else if (list[j].hp != 0) {
		memcpy(&list[i], &list[j], sizeof(struct Champion));
		memcpy(&list[j], &list[SIZE - 1], sizeof(struct Champion));
		return;
	}
	
	sort_j(i, j + 1);
}

int main()
{

	while (1) {
		char name[15], position[5];
		int choice = 0, i = 0, j = 0, num = 0;
		int max = list[0].hp;
		int max_sort = 0;

		printf("1. Search_R [name]\n2. Insert_R\n3. Delete_R [name]\n4. DeleteAll_R [position]\n5. PrintAll_R\n6. FindMaxHp_R\n7. SortByHp_R\n");
		printf("*************************\nEnter a Command: ");

		scanf("%d", &choice);
		getchar();

		switch (choice) {
		case 1:
			printf("Name: ");
			scanf("%s", name);
			search(name, num, i);

			getchar();
			getchar();
			system("cls");
			break;
		case 2:
			insert(num, i);

			getchar();
			getchar();
			system("cls");
			break;
		case 3:
			printf("Name: ");
			scanf("%s", name);
			delete(name, num, i);

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
				printf("put right position");
				getchar();
				getchar();
				system("cls");
				continue;
			}
			sort(i, j);
			printf("Delete Complete");
			getchar();
			getchar();
			system("cls");
			break;
		case 5:
			printf("***********************************************************************************\n");
			printall(i);
			printf("***********************************************************************************\n");
			getchar();
			break;
		case 6:
			findmaxhp(i, max);

			getchar();
			system("cls");
			break;
		case 7:
			sortbyhp(i, j, max_sort);

			printf("Sort Complete");
			getchar();
			system("cls");
			break;
		default:
			printf("Wrong Command");
			putchar('\n');
			getchar();
		}
	}
}