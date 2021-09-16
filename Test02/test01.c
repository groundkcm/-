#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <windows.h>

int W_num = 0, B_num = 0;
int W1 = 0, B1 = 0;
int longest[19] = { 0 };
int baduk[19][19] = { 0 };

void Dline(int num)
{
	/*int a = 0, b = 0, c = 0, d = 0;
	if (num == 1) {
		b = 0, c = 0, d = a;
	} else if (num == 2) {
		b = 1, c = a, d = 0;
	} else if (num == 3) {
		b = 1, c = 0, d = a;
	} else {
		b = 1, c = a, d = 19;
	}*/
	printf("D%d ", num);
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
				printf("%2d ", B_num + 1);
			}
			else {
				printf("  ");
			}
			W_num = 0, B_num = 0;
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
				printf("%2d ", B_num + 1);
			}
			else {
				printf("  ");
			}
			W_num = 0, B_num = 0;
		}
		putchar('\n');
	}
	else if (num == 3) {
		for (int a = 0; a < 19; a++) {
			for (int i = 0, j = a; j < 0; i++, j--) {
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
				printf("%2d ", B_num + 1);
			}
			else {
				printf("  ");
			}
			W_num = 0, B_num = 0;
		}
		putchar('\n');
	}
	else {
		for (int a = 0; a < 19; a++) {
			for (int i = a, j = 19; j < 0; i++, j--) {
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
				printf("%2d ", B_num + 1);
			}
			else {
				printf("  ");
			}
			W_num = 0, B_num = 0;
		}
		putchar('\n');
	}
	/*if (num == 1 || num == 2) {
		for (a = b; a < 19; a++) {
			for (int i = c, j = d; i < 19; i++, j++) {
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
				printf("%2d ", B_num + 1);
			} else {
				printf("  ");
			}
			W_num = 0, B_num = 0;
		}
		putchar('\n');
	} else {
		for (a = b; a < 19; a++) {
			for (int i = c, j = d; j < 0; i++, j--) {
				if (baduk[i][j] == 1 && baduk[i + 1][j + 1] == 1) {
					W_num++;
				}
				else if (baduk[i][j] == 2 && baduk[i + 1][j + 1] == 2) {
					B_num++;
				}
			}
			if (W_num > B_num) {
				printf("%2dW", W_num + 1);
			}
			else if (W_num < B_num) {
				printf("%2dB", B_num + 1);
			}
			else if (W_num != 0 && W_num == B_num) {
				printf("%2d ", B_num + 1);
			}
			W_num = 0, B_num = 0;
		}
		putchar('\n');
	}*/
}

void display(int baduk[19][19])
{
	/*Dline(1);
	Dline(2);
	Dline(3);
	Dline(4);*/

	for (int a = 0; a < 19; a++) {
		for (int i = 0, j = a; i > a; i++, j--) {
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
			printf("%2d ", B_num + 1);
		}
		else {
			printf(" .");
		}
		W_num = 0, B_num = 0;
	}
	putchar('\n');

	printf("   +---------------------------------------\n");

	for (int i = 0; i < 19; ++i) {
		printf("   |");
		for (int j = 0; j < 19; ++j) {
			if (baduk[i][j] == 0)
				printf(" +");
			else if (baduk[i][j] == 1) {
				if (baduk[i][j + 1] == 1) {
					W_num++;
				}
				printf(" W");
				longest[j] = 1;
				W1++;
			}
			else {
				if (baduk[i][j + 1] == 2) {
					B_num++;
				}
				printf(" B");
				longest[j] = 2;
				B1++;
			}
		}
		printf(" (W:%d, B:%d)", W1, B1);
		if (W_num > B_num) {
			printf("/ W:%d ", W_num+1);
			for (int j = 0; j < 19; j++) {
				if (longest[j] == 1) {
					printf("(%d,%d) ", i, j);
				}
			}
		} else if(W_num < B_num) {
			printf("/ B:%d ", B_num+1);
			for (int j = 0; j < 19; j++) {
				if (longest[j] == 2) {
					printf("(%d,%d) ", i, j);
				}
			}
		}
		else if (W_num != 0 && W_num == B_num) {
			printf("/ W,B:%d ", B_num+1);
			for (int j = 0; j < 19; j++) {
				if (longest[j] == 2) {
					printf("(%d,%d) ", i, j);
				}
			}
		}
		W1 = 0, B1 = 0, W_num = 0, B_num = 0;
		for (int i=0;i<19;i++) longest[i] = 0;
		putchar('\n');
	}

	int count[2][19] = { 0 };
	int num_count[2][19] = { 0 };

	for (int i = 0; i < 19; ++i) {
		for (int j = 0; j < 19; ++j) {
			if (baduk[j][i] == 1) {
				if (baduk[j+1][i] == 1) {
					W_num++;
				}
				W1++;
			}
			else if (baduk[j][i] == 2) {
				if (baduk[j+1][i] == 2) {
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
		else if (W_num == B_num) {
			num_count[0][i] = W_num;
			num_count[1][i] = B_num;
		}
		W1 = 0, B1 = 0, W_num = 0, B_num = 0;
	}

	printf("W:  ");
	for (int i = 0; i < 19; i++) {
		printf("%2d", count[0][i]);
	}
	putchar('\n');
	printf("B:  ");
	for (int i = 0; i < 19; i++) {
		printf("%2d", count[1][i]);
	}
	putchar('\n');
	printf("************************************************************\n");
	printf("W:  ");
	for (int i = 0; i < 19; i++) {
		if (num_count[0][i] == 0) {
			printf("  ");
			continue;
		}
		printf("%2d", num_count[0][i]+1);
	}
	putchar('\n');
	printf("B:  ");
	for (int i = 0; i < 19; i++) {
		if (num_count[1][i] == 0) {
			printf("  ");
			continue;
		}
		printf("%2d", num_count[1][i]+1);
	}
	putchar('\n');

}

////1.*************************************************************************
//int main()
//{
//	int baduk[19][19] = { 0 };
//	display(baduk);
//
//	putchar('\n');
//
//	return 0;
//
//}

////2.*************************************************************************
//int main() {
//	int baduk[19][19] = { 0 };
//	int i = 0, j = 0;
//	int a = 1;
//
//
//	while (1) {
//		int r = scanf("%d %d", &i, &j);
//		if (r != 2 || i < 0 || j < 0 || i>18 || j>18) {
//			printf("put right numbers");
//			getchar();
//			putchar('\n');
//			continue;
//		}
//		if (a % 2 == 1)
//			baduk[i][j] = 1;
//		else
//			baduk[i][j] = 2;
//
//		display(baduk);
//		putchar('\n');
//		++a;
//
//	}
//}
//	
////3.*****************************************************************************
//int main() {
//	int baduk[19][19] = { 0 };
//	int i = 0, j = 0;
//	int a = 1;
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
//		if (a % 2 == 1)
//			baduk[i][j] = 1;
//		else
//			baduk[i][j] = 2;
//		display(baduk);
//		putchar('\n');
//		++a;
//	}
//
//}
//	
//4.*****************************************************************************
//5.*****************************************************************************
int main() {
	int W = 0, B = 0;
	
	int i = 0, j = 0;
	int a = 1;

	while (1) {
		printf("Num: ");
		int r = scanf("%d %d", &i, &j);
		if (r != 2 || (i < 0 || j < 0 || i>18 || j>18)) {
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
			++W;
		}

		else {
			baduk[i][j] = 2;
			++B;
		}
		system("cls");
		display(baduk);
		putchar('\n');
		printf("W: %d, B: %d", W, B);
		putchar('\n');

		++a;
	}
}

