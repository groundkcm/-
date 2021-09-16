#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>

int display(int baduk[19][19]) 
{
	for (int i = 0; i < 19; ++i) {
		for (int j = 0; j < 19; ++j) {
			if (baduk[i][j] == 0)
				putchar('+');
			else if (baduk[i][j] == 1)
				putchar('W');
			else
				putchar('B');
		}
		putchar('\n');
	}
	putchar('\n');
}

////1.************************************************************
//int main()
//{
//	int baduk[19][19] = { 0 };
//
//	display(baduk);
//	putchar('\n');
//}
//
////2.************************************************************
//int main()
//{
//	int i = 0, j = 0, a = 1;
//	int baduk[19][19] = { 0 };
//
//	while (1) {
//		int r = scanf("%d %d", &i, &j);
//		if (r != 2 || i < 0 || j < 0 || i>18 || j>18) {
//			printf("wrong input");
//			getchar();
//			putchar('\n');
//			continue;
//		}
//		if (a % 2 == 1) {
//			baduk[i][j] = 1;
//		}
//		else
//			baduk[i][j] = 2;
//
//		system("cls");
//		display(baduk);
//		++a;
//	}
//}
//
////3.************************************************************
//int main()
//{
//	int i = 0, j = 0, a = 1;
//	int baduk[19][19] = { 0 };
//
//	while (1) {
//		int r = scanf("%d %d", &i, &j);
//		if (r != 2 || i < 0 || j < 0 || i>18 || j>18) {
//			printf("wrong input");
//			getchar();
//			putchar('\n');
//			continue;
//		}
//		if (baduk[i][j] != 0) {
//			printf("already placed");
//			putchar('\n');
//			continue;
//		}
//		if (a % 2 == 1) {
//			baduk[i][j] = 1;
//		}
//		else
//			baduk[i][j] = 2;
//
//		system("cls");
//		display(baduk);
//		++a;
//	}
//}

////4.************************************************************
////5.************************************************************
int main()
{
	int W = 0, B = 0;
	int i = 0, j = 0, a = 1;
	int baduk[19][19] = { 0 };

	while (1) {
		int r = scanf("%d %d", &i, &j);
		if (r != 2 || i < 0 || j < 0 || i>18 || j>18) {
			printf("wrong input");
			getchar();
			putchar('\n');
			continue;
		}
		if (baduk[i][j] != 0) {
			printf("already placed");
			
			continue;
		}
		if (a % 2 == 1) {
			baduk[i][j] = 1;
			++W;
		}
		else {
			baduk[i][j] = 2;
			++B;
		}

		system("cls");
		display(baduk);
		printf("W:%d, B:%d", W, B);
		putchar('\n');

		++a;
	}
}

