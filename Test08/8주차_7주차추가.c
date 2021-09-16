#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

int W = 0, B = 0;
int W1 = 0, B1 = 0;
int W_num = 0, B_num = 0;
int longest[19] = { 0 };
int baduk[19][19] = { 0 };

typedef struct STACK {
	int x;
	int y;
	int color;
	struct STACK* next;
}st;

st* sp_u;
st* sp_r;

void Push_U(int x, int y, int color) 
{
	st* new = malloc(sizeof(st));
	new->x = x;
	new->y = y;
	new->color = color;
	if (sp_u == NULL) {
		sp_u = new;
		new->next = NULL;
	}
	else {
		new->next = sp_u;
		sp_u = new;
	}
}

void Push_R(int x, int y, int color)
{
	st* new = malloc(sizeof(st));
	new->x = x;
	new->y = y;
	new->color = color;
	if (sp_r == NULL) {
		sp_r = new;
		new->next = NULL;
	}
	else {
		new->next = sp_r;
		sp_r = new;
	}
}

st* Pop_U()
{
	st* target = NULL;
	if (sp_u == NULL) {
		return NULL;
	}
	target = sp_u;
	sp_u = sp_u->next;
	target->next = NULL;
	return target;
}

st* Pop_R()
{
	st* target = NULL;
	if (sp_r == NULL) {
		return NULL;
	}
	target = sp_r;
	sp_r = sp_r->next;
	target->next = NULL;
	return target;
}

void Dline(int num)
{
	printf("D%d   ", num);
	if (num == 1) {
		for (int a = 0; a < 19; a++) {
			for (int i = 0, j = a; i < 19; i++, j++) {
				if (baduk[i][j] == 1 && baduk[i + 1][j + 1] == 1) {
					W_num++;
				}
				else if (baduk[i][j] == 2 && baduk[i + 1][j + 1] == 2) {
					B_num++;
				}
			}
			if (W_num > B_num) {
				printf("%dW", W_num + 1);
			}
			else if (W_num < B_num) {
				printf("%dB", B_num + 1);
			}
			else if (W_num != 0 && W_num == B_num) {
				printf("%2d", W_num + 1);
			}
			else {
				printf("  ");
			}
			W1 = 0, B1 = 0, W_num = 0, B_num = 0;
		}
		putchar('\n');
	}
	else if (num == 2) {
		for (int a = 0; a < 19; a++) {
			for (int i = a, j = 0; i < 19; i++, j++) {
				if (baduk[i][j] == 1 && baduk[i + 1][j + 1] == 1) {
					W_num++;
				}
				else if (baduk[i][j] == 2 && baduk[i + 1][j + 1] == 2) {
					B_num++;
				}
			}
			if (W_num > B_num) {
				printf("%dW", W_num + 1);
			}
			else if (W_num < B_num) {
				printf("%dB", B_num + 1);
			}
			else if (W_num != 0 && W_num == B_num) {
				printf("%2d", W_num + 1);
			}
			else {
				printf("  ");
			}
			W1 = 0, B1 = 0, W_num = 0, B_num = 0;
		}
		putchar('\n');

	}
	else if (num == 3) {
		for (int a = 0; a < 19; a++) {
			for (int i = 0, j = a; i <= a; i++, j--) {
				if (baduk[i][j] == 1 && baduk[i + 1][j - 1] == 1) {
					W_num++;
				}
				else if (baduk[i][j] == 2 && baduk[i + 1][j - 1] == 2) {
					B_num++;
				}
			}
			if (W_num > B_num) {
				printf("%dW", W_num + 1);
			}
			else if (W_num < B_num) {
				printf("%dB", B_num + 1);
			}
			else if (W_num != 0 && W_num == B_num) {
				printf("%2d", W_num + 1);
			}
			else {
				printf("  ");
			}
			W1 = 0, B1 = 0, W_num = 0, B_num = 0;
		}
		putchar('\n');

	}
	else if (num == 4) {
		for (int a = 0; a < 19; a++) {
			for (int i = a, j = 19; i <= a; i++, j--) {
				if (baduk[i][j] == 1 && baduk[i + 1][j - 1] == 1) {
					W_num++;
				}
				else if (baduk[i][j] == 2 && baduk[i + 1][j - 1] == 2) {
					B_num++;
				}
			}
			if (W_num > B_num) {
				printf("%dW", W_num + 1);
			}
			else if (W_num < B_num) {
				printf("%dB", B_num + 1);
			}
			else if (W_num != 0 && W_num == B_num) {
				printf("%2d", W_num + 1);
			}
			else {
				printf("  ");
			}
			W1 = 0, B1 = 0, W_num = 0, B_num = 0;
		}
		putchar('\n');

	}
}

int display(int baduk[19][19])
{
	Dline(1);
	Dline(2);
	Dline(3);
	Dline(4);

	printf("   +---------------------------------------\n");

	for (int i = 0; i < 19; ++i) {
		printf("   |");
		for (int j = 0; j < 19; ++j) {
			if (baduk[i][j] == 0) {
				printf(" +");
			}
			else if (baduk[i][j] == 1) {
				if (baduk[i][j + 1] == 1) {
					W_num++;
					longest[j] = 1;
					longest[j+1] = 1;
				}
				printf(" W");
				W1++;
				W++;
			}
			else {
				if (baduk[i][j + 1] == 2) {
					B_num++;
					longest[j] = 2;
					longest[j + 1] = 2;
				}
				printf(" B");
				B1++;
				B++;
			}
		}
		printf(" (W:%d,B:%d)", W1, B1);
		if (W_num > B_num) {
			printf(" / W:%d", W_num + 1);
			for (int j = 0; j < 19; j++) {
				if (longest[j] == 1) {
					printf(", (%d,%d)", i, j);
				}
			}
		}
		else if (W_num < B_num) {
			printf(" / B:%d", B_num + 1);
			for (int j = 0; j < 19; j++) {
				if (longest[j] == 2) {
					printf(", (%d,%d)", i, j);
				}
			}
		}
		else if (W_num != 0 && W_num == B_num) {
			printf(" / W,B:%d", W_num + 1);
			for (int j = 0; j < 19; j++) {
				if (longest[j] == 1) {
					printf(", (%d,%d)", i, j);
				}
			}
			for (int j = 0; j < 19; j++) {
				if (longest[j] == 2) {
					printf(", (%d,%d)", i, j);
				}
			}
		}
		W1 = 0, B1 = 0, W_num = 0, B_num = 0;
		for (int i = 0; i < 19; i++) longest[i] = 0;
		putchar('\n');
	}

	int count[2][19] = { 0 };
	int num_count[2][19] = { 0 };

	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (baduk[j][i] == 1) {
				if (baduk[j + 1][i] == 1) {
					W_num++;
				}
				W1++;
			}
			else if (baduk[j][i] == 2) {
				if (baduk[j + 1][i] == 2) {
					B_num++;
				}
				B1++;
			}
		}
		count[0][i] = W1;
		count[1][i] = B1;
		if (W_num > B_num) {
			num_count[0][i] = W_num;
		}
		else if (W_num < B_num) {
			num_count[1][i] = B_num;
		}
		else if (W_num != 0 && W_num == B_num) {
			num_count[0][i] = W_num;
			num_count[1][i] = B_num;
		}
		W1 = 0, B1 = 0, W_num = 0, B_num = 0;
	}

	printf("W:   ");
	for (int i = 0; i < 19; i++) {
		printf("%2d", count[0][i]);
	}
	putchar('\n');
	printf("B:   ");
	for (int i = 0; i < 19; i++) {
		printf("%2d", count[1][i]);
	}
	putchar('\n');
	printf("*************************************************\n");
	printf("W:   ");
	for (int i = 0; i < 19; i++) {
		if (num_count[0][i] == 0) {
			printf("  ");
			continue;
		}
		printf("%2d", count[0][i]);
	}
	putchar('\n');
	printf("B:   ");
	for (int i = 0; i < 19; i++) {
		if (num_count[1][i] == 0) {
			printf("  ");
			continue;
		}
		printf("%2d", count[1][i]);
	}
	putchar('\n');
	putchar('\n');
}
////1.*************************************************************************
//int main()
//{
//	int baduk[19][19] = { 0 };
//
//	display(baduk);
//
//}
////2.*************************************************************************
//int main()
//{
//	int i = 0, j = 0, a = 1;
//	int baduk[19][19] = { 0 };
//
//	while (1) {
//		int r = scanf("%d %d", &i, &j);
//		if (r != 2 || i < 0 || j < 0 || i>18 || j>18) {
//			printf("put right numbers");
//			getchar();
//			putchar('\n');
//			continue;
//		}
//
//		if (a % 2 == 1) {
//			baduk[i][j] = 1;
//		}
//		else {
//			baduk[i][j] = 2;
//		}
//		system("cls");
//		display(baduk);
//		++a;
//	}
//	
//
//}
////3.*************************************************************************
//int main()
//{
//	int i = 0, j = 0, a = 1;
//	int baduk[19][19] = { 0 };
//
//	while (1) {
//		int r = scanf("%d %d", &i, &j);
//		if (r != 2 || i < 0 || j < 0 || i>18 || j>18) {
//			printf("put right numbers");
//			getchar();
//			putchar('\n');
//			continue;
//		}
//		if (baduk[i][j] != 0) {
//			printf("already placed");
//			putchar('\n');
//			continue;
//		}
//
//		if (a % 2 == 1) {
//			baduk[i][j] = 1;
//		}
//		else {
//			baduk[i][j] = 2;
//		}
//		system("cls");
//		display(baduk);
//		++a;
//	}
//}
////4.*************************************************************************
//5.*************************************************************************
int main()
{
	FILE* stream;
	sp_u = NULL;
	sp_r = NULL;
	int num = 0;
	int i = 0, j = 0, a = 1;
	

	while (1) {
		char command[5];
		printf("1.Save\n2.Load\n3.U\n4.R\n5.Put\n");
		printf("**********\nEnter a Command: ");
		scanf("%s", command);
		if (strcmp(command, "Save") == 0) {
			stream = fopen("baduk.txt", "w");
			for (int i = 0; i < 19; i++) {
				for (int j = 0; j < 19; j++) {
					fputc(baduk[i][j], stream);
				}
			}
			fclose(stream);
			stream = fopen("stack_u.txt", "w");
			for (st* p = sp_u; p != NULL; p = p->next) {
				fprintf(stream, "%d %d %d ", p->x, p->y, p->color);
			}
			fclose(stream);
			stream = fopen("stack_r.txt", "w");
			for (st* p = sp_r; p != NULL; p = p->next) {
				fprintf(stream, "%d %d %d ", p->x, p->y, p->color);
			}
			fclose(stream);
		} else if (strcmp(command, "Load") == 0) {
			st* d;
			st* p = sp_u;
			while (p != NULL) {
				d = p;
				p = p->next;
				free(d);
			}
			p = sp_r;
			while (p != NULL) {
				d = p;
				p = p->next;
				free(d);
			}
			sp_u = NULL;
			sp_r = NULL;
			stream = fopen("baduk.txt", "r");
			for (int i = 0; i < 19; i++) {
				for (int j = 0; j < 19; j++) {
					baduk[i][j] = fgetc(stream);
				}
			}
			fclose(stream);
			stream = fopen("stack_u.txt", "r");
			while(1) {
				st* new = malloc(sizeof(st));
				fscanf(stream, "%d %d %d ", &new->x, &new->y, &new->color);
				if (new->color != 1 && new->color != 2) {
					free(new);
					break;
				}
				else if (num == 0) {
					sp_u = new;
				}
				else {
					p->next = new;
				}
				p = new;
				new->next = NULL;
				num++;
			}
			fclose(stream);
			if (num % 2 == 1) {
				a = 2;
			}
			else {
				a = 1;
			}
			num = 0;
			stream = fopen("stack_r.txt", "r");
			while (1) {
				st* new = malloc(sizeof(st));
				fscanf(stream, "%d %d %d ", &new->x, &new->y, &new->color);
				if (new->color != 1 && new->color != 2) {
					free(new);
					break;
				}
				else if (num == 0) {
					sp_r = new;
				}
				else {
					p->next = new;
				}
				p = new;
				new->next = NULL;
				num++;
			}
			fclose(stream);
		}
		else if (strcmp(command, "U") == 0) {
			st* target = Pop_U();
			if (target == NULL) {
				printf("Stack is Empty\n");
				continue;
			}
			baduk[target->x][target->y] = 0;
			Push_R(target->x, target->y, target->color);
		}
		else if (strcmp(command, "R") == 0) {
			st* target = Pop_R();
			if (target == NULL) {
				printf("Stack is Empty\n");
				continue;
			}
			baduk[target->x][target->y] = target->color;
			Push_U(target->x, target->y, target->color);
		}
		else if (strcmp(command, "Put") == 0) {
			printf("Num: ");
			int r = scanf("%d %d", &i, &j);
			if (r != 2 || i < 0 || j < 0 || i>18 || j>18) {
				printf("put right numbers");
				getchar();
				putchar('\n');
				continue;
			}
			if (baduk[i][j] != 0) {
				printf("already placed");
				putchar('\n');
				continue;
			}

			if (a % 2 == 1) {
				baduk[i][j] = 1;
				Push_U(i, j, 1);
			}
			else {
				baduk[i][j] = 2;
				Push_U(i, j, 2);
			}
			++a;
		}
		else {
			printf("Wrong Command");
			getchar();
		}
		system("cls");
		display(baduk);
		printf("W: %d, B: %d", W, B);
		W = 0, B = 0;
		putchar('\n');
	}
}
