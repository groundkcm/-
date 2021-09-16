#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int W = 0, B = 0;
int W1 = 0, B1 = 0;
int W_num = 0, B_num = 0;
int longest[19] = { 0 };
int longest_d[19][19] = { 0 };
int warning[19][19] = { 0 };
int hint_arr[19][19] = { 0 };
int baduk[19][19] = { 0 };

void hint()
{
	if (W == 1)
		for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++) {
			if (baduk[i][j] == 1 && j + 1 < 19)
				hint_arr[i][j + 1] = 2;
			else if (baduk[i][j] == 1)
				hint_arr[i][j - 1] = 2;
		}
	else if (B == 1)
		for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++) {
			if (baduk[i][j] == 1 && i + 1 < 19)
				hint_arr[i + 1][j] = 1;
			else if (baduk[i][j] == 1)
				hint_arr[i - 1][j] = 1;
		}
	for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++) {
		if (warning[i][j] == 1)
			hint_arr[i][j] = 2;
		else if (warning[i][j] == 2)
			hint_arr[i][j] = 1;
	}
}
void pre()
{
	
}

void Dline(int num)
{
	printf("D%d   ", num);
	if (num == 1) {
		for (int a = 0; a < 19; a++) {
			for (int i = 0, j = a; i < 19; i++, j++) {
				if (baduk[i][j] == 1 && baduk[i + 1][j + 1] == 1) {
					W_num++;
					longest_d[i][j]=1, longest_d[i + 1][j + 1] = 1;
					if (W_num == 2) {
						if (baduk[i - 1][j - 1] == 0)
							warning[i - 1][j - 1]=2, warning[i - 3][j - 3]=2, warning[i + 2][j + 2] = 2;
						else
							warning[i + 2][j + 2]=2, warning[i - 2][j - 2] = 2;
					}
					else if (W_num == 3) {
						if (baduk[i - 1][j - 1] == 0)
							warning[i - 1][j - 1]=2, warning[i - 4][j - 4]=2, warning[i + 2][j + 2] = 2;
						else
							warning[i + 2][j + 2]=2, warning[i - 3][j - 3] = 2;
					}
				}
				else if (baduk[i][j] == 1 && baduk[i + 1][j + 1] == 0 && baduk[i + 2][j + 2] == 1) {
					W_num++;
					longest_d[i][j]=1, longest_d[i + 2][j + 2] = 1;
					if (W_num == 2) 
						warning[i + 1][j + 1]=2, warning[i+3][j+3]=2, warning[i - 2][j - 2] = 2;
					else if (W_num == 3) 
						warning[i + 1][j + 1]=2, warning[i + 3][j + 3]=2, warning[i - 3][j - 3] = 2;
				}
				if (baduk[i][j] == 2 && baduk[i + 1][j + 1] == 2) {
					B_num++;
					longest_d[i][j]=2, longest_d[i + 1][j + 1] = 2;
					if (B_num == 2) {
						if (baduk[i - 1][j - 1] == 0)
							warning[i - 1][j - 1]=1, warning[i - 3][j - 3]=1, warning[i + 2][j + 2] = 1;
						else
							warning[i + 2][j + 2]=1, warning[i - 2][j - 2] = 1;
					}
					else if (B_num == 3) {
						if (baduk[i - 1][j - 1] == 0)
							warning[i - 1][j - 1]=1, warning[i - 4][j - 4]=1, warning[i + 2][j + 2] = 1;
						else
							warning[i + 2][j + 2]=1, warning[i - 3][j - 3] = 1;
					}
				}
				else if (baduk[i][j] == 2 && baduk[i + 1][j + 1] == 0 && baduk[i + 2][j + 2] == 2) {
					B_num++;
					longest_d[i][j]=2, longest_d[i + 2][j + 2] = 2;
					if (B_num == 2)
						warning[i + 1][j + 1]=1, warning[i + 3][j + 3]=1, warning[i - 2][j - 2] = 1;
					else if (B_num == 3)
						warning[i + 1][j + 1]=1, warning[i + 3][j + 3]=1, warning[i - 3][j - 3] = 1;
				}
			}
			if (W_num > B_num) {
				printf("%dW", W_num + 1);
				for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++)
					if (longest_d[i][j] == 1)
						printf("(%d,%d) ", i, j);
			}
			else if (W_num < B_num) {
				printf("%dB", B_num + 1);
				for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++)
					if (longest_d[i][j] == 2)
						printf("(%d,%d) ", i, j);
			}
			else if (W_num != 0 && W_num == B_num) {
				printf("%2d", W_num + 1);
				for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++)
					if (longest_d[i][j] == 1 || longest_d[i][j] == 2)
						printf("(%d,%d) ", i, j);
			}
			else {
				printf("  ");
			}
			W1 = 0, B1 = 0, W_num = 0, B_num = 0;
			for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++) longest_d[i][j] = 0;
		}
		putchar('\n');
	}
	else if (num == 2) {
		for (int a = 0; a < 19; a++) {
			for (int i = a, j = 0; i < 19; i++, j++) {
				if (baduk[i][j] == 1 && baduk[i + 1][j + 1] == 1) {
					W_num++;
					longest_d[i][j] = 1, longest_d[i + 1][j + 1] = 1;
					if (W_num == 2) {
						if (baduk[i - 1][j - 1] == 0)
							warning[i - 1][j - 1] = 2, warning[i - 3][j - 3] = 2, warning[i + 2][j + 2] = 2;
						else
							warning[i + 2][j + 2] = 2, warning[i - 2][j - 2] = 2;
					}
					else if (W_num == 3) {
						if (baduk[i - 1][j - 1] == 0)
							warning[i - 1][j - 1] = 2, warning[i - 4][j - 4] = 2, warning[i + 2][j + 2] = 2;
						else
							warning[i + 2][j + 2] = 2, warning[i - 3][j - 3] = 2;
					}
				}
				else if (baduk[i][j] == 1 && baduk[i + 1][j + 1] == 0 && baduk[i + 2][j + 2] == 1) {
					W_num++;
					longest_d[i][j] = 1, longest_d[i + 2][j + 2] = 1;
					if (W_num == 2)
						warning[i + 1][j + 1] = 2, warning[i + 3][j + 3] = 2, warning[i - 2][j - 2] = 2;
					else if (W_num == 3)
						warning[i + 1][j + 1] = 2, warning[i + 3][j + 3] = 2, warning[i - 3][j - 3] = 2;
				}
				if (baduk[i][j] == 2 && baduk[i + 1][j + 1] == 2) {
					B_num++;
					longest_d[i][j] = 2, longest_d[i + 1][j + 1] = 2;
					if (B_num == 2) {
						if (baduk[i - 1][j - 1] == 0)
							warning[i - 1][j - 1] = 1, warning[i - 3][j - 3] = 1, warning[i + 2][j + 2] = 1;
						else
							warning[i + 2][j + 2] = 1, warning[i - 2][j - 2] = 1;
					}
					else if (B_num == 3) {
						if (baduk[i - 1][j - 1] == 0)
							warning[i - 1][j - 1] = 1, warning[i - 4][j - 4] = 1, warning[i + 2][j + 2] = 1;
						else
							warning[i + 2][j + 2] = 1, warning[i - 3][j - 3] = 1;
					}
				}
				else if (baduk[i][j] == 2 && baduk[i + 1][j + 1] == 0 && baduk[i + 2][j + 2] == 2) {
					B_num++;
					longest_d[i][j] = 2, longest_d[i + 2][j + 2] = 2;
					if (B_num == 2)
						warning[i + 1][j + 1] = 1, warning[i + 3][j + 3] = 1, warning[i - 2][j - 2] = 1;
					else if (B_num == 3)
						warning[i + 1][j + 1] = 1, warning[i + 3][j + 3] = 1, warning[i - 3][j - 3] = 1;
				}
			}
			if (W_num > B_num) {
				printf("%dW", W_num + 1);
				for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++)
					if (longest_d[i][j] == 1)
						printf("(%d,%d) ", i, j);
			}
			else if (W_num < B_num) {
				printf("%dB", B_num + 1);
				for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++)
					if (longest_d[i][j] == 2)
						printf("(%d,%d) ", i, j);
			}
			else if (W_num != 0 && W_num == B_num) {
				printf("%2d", W_num + 1);
				for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++)
					if (longest_d[i][j] == 1 || longest_d[i][j] == 2)
						printf("(%d,%d) ", i, j);
			}
			else {
				printf("  ");
			}
			W1 = 0, B1 = 0, W_num = 0, B_num = 0;
			for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++) longest_d[i][j] = 0;
		}
		putchar('\n');

	}
	else if (num == 3) {
		for (int a = 0; a < 19; a++) {
			for (int i = 0, j = a; i <= a; i++, j--) {
				if (baduk[i][j] == 1 && baduk[i + 1][j - 1] == 1) {
					W_num++;
					longest_d[i][j]=1, longest_d[i + 1][j - 1] = 1;
					if (W_num == 2) {
						if (baduk[i - 1][j + 1] == 0)
							warning[i - 1][j + 1]=2, warning[i - 3][j + 3]=2, warning[i + 2][j - 2] = 2;
						else
							warning[i + 2][j - 2]=2, warning[i - 2][j + 2] = 2;
					}
					else if (W_num == 3) {
						if (baduk[i - 1][j + 1] == 0)
							warning[i - 1][j + 1]=2, warning[i - 4][j + 4]=2, warning[i + 2][j - 2] = 2;
						else
							warning[i + 2][j - 2]=2, warning[i - 3][j + 3] = 2;
					}
				}
				else if (baduk[i][j] == 1 && baduk[i + 1][j - 1] == 0 && baduk[i + 2][j - 2] == 1) {
					W_num++;
					longest_d[i][j]=1, longest_d[i + 2][j - 2] = 1;
					if (W_num == 2)
						warning[i + 1][j - 1]=2, warning[i + 3][j - 3]=2, warning[i - 2][j + 2] = 2;
					else if (W_num == 3)
						warning[i + 1][j - 1]=2, warning[i + 3][j - 3]=2, warning[i - 3][j + 3] = 2;
				}
				if (baduk[i][j] == 2 && baduk[i + 1][j - 1] == 2) {
					B_num++;
					longest_d[i][j]=2, longest_d[i + 1][j - 1] = 2;
					if (B_num == 2) {
						if (baduk[i - 1][j + 1] == 0)
							warning[i - 1][j + 1]=1, warning[i - 3][j + 3]=1, warning[i + 2][j - 2] = 1;
						else
							warning[i + 2][j - 2]=1, warning[i - 2][j + 2] = 1;
					}
					else if (B_num == 3) {
						if (baduk[i - 1][j + 1] == 0)
							warning[i - 1][j + 1]=1, warning[i - 4][j + 4]=1, warning[i + 2][j - 2] = 1;
						else
							warning[i + 2][j - 2]=1, warning[i - 3][j + 3] = 1;
					}
				}
				else if (baduk[i][j] == 2 && baduk[i + 1][j - 1] == 0 && baduk[i + 2][j - 2] == 2) {
					B_num++;
					longest_d[i][j]=2, longest_d[i + 2][j - 2] = 2;
					if (B_num == 2)
						warning[i + 1][j - 1]=1, warning[i + 3][j - 3]=1, warning[i - 2][j + 2] = 1;
					else if (B_num == 3)
						warning[i + 1][j - 1]=1, warning[i + 3][j - 3]=1, warning[i - 3][j + 3] = 1;
				}
			}
			if (W_num > B_num) {
				printf("%dW", W_num + 1);
				for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++)
					if (longest_d[i][j] == 1)
						printf("(%d,%d) ", i, j);
			}
			else if (W_num < B_num) {
				printf("%dB", B_num + 1);
				for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++)
					if (longest_d[i][j] == 2)
						printf("(%d,%d) ", i, j);
			}
			else if (W_num != 0 && W_num == B_num) {
				printf("%2d", W_num + 1);
				for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++)
					if (longest_d[i][j] == 1 || longest_d[i][j] == 2)
						printf("(%d,%d) ", i, j);
			}
			else {
				printf("  ");
			}
			W1 = 0, B1 = 0, W_num = 0, B_num = 0;
			for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++) longest_d[i][j] = 0;
		}
		putchar('\n');

	}
	else if (num == 4) {
		for (int a = 0; a < 19; a++) {
			for (int i = a, j = 19; i <= a; i++, j--) {
				if (baduk[i][j] == 1 && baduk[i + 1][j - 1] == 1) {
					W_num++;
					longest_d[i][j] = 1, longest_d[i + 1][j - 1] = 1;
					if (W_num == 2) {
						if (baduk[i - 1][j + 1] == 0)
							warning[i - 1][j + 1] = 2, warning[i - 3][j + 3] = 2, warning[i + 2][j - 2] = 2;
						else
							warning[i + 2][j - 2] = 2, warning[i - 2][j + 2] = 2;
					}
					else if (W_num == 3) {
						if (baduk[i - 1][j + 1] == 0)
							warning[i - 1][j + 1] = 2, warning[i - 4][j + 4] = 2, warning[i + 2][j - 2] = 2;
						else
							warning[i + 2][j - 2] = 2, warning[i - 3][j + 3] = 2;
					}
				}
				else if (baduk[i][j] == 1 && baduk[i + 1][j - 1] == 0 && baduk[i + 2][j - 2] == 1) {
					W_num++;
					longest_d[i][j] = 1, longest_d[i + 2][j - 2] = 1;
					if (W_num == 2)
						warning[i + 1][j - 1] = 2, warning[i + 3][j - 3] = 2, warning[i - 2][j + 2] = 2;
					else if (W_num == 3)
						warning[i + 1][j - 1] = 2, warning[i + 3][j - 3] = 2, warning[i - 3][j + 3] = 2;
				}
				if (baduk[i][j] == 2 && baduk[i + 1][j - 1] == 2) {
					B_num++;
					longest_d[i][j] = 2, longest_d[i + 1][j - 1] = 2;
					if (B_num == 2) {
						if (baduk[i - 1][j + 1] == 0)
							warning[i - 1][j + 1] = 1, warning[i - 3][j + 3] = 1, warning[i + 2][j - 2] = 1;
						else
							warning[i + 2][j - 2] = 1, warning[i - 2][j + 2] = 1;
					}
					else if (B_num == 3) {
						if (baduk[i - 1][j + 1] == 0)
							warning[i - 1][j + 1] = 1, warning[i - 4][j + 4] = 1, warning[i + 2][j - 2] = 1;
						else
							warning[i + 2][j - 2] = 1, warning[i - 3][j + 3] = 1;
					}
				}
				else if (baduk[i][j] == 2 && baduk[i + 1][j - 1] == 0 && baduk[i + 2][j - 2] == 2) {
					B_num++;
					longest_d[i][j] = 2, longest_d[i + 2][j - 2] = 2;
					if (B_num == 2)
						warning[i + 1][j - 1] = 1, warning[i + 3][j - 3] = 1, warning[i - 2][j + 2] = 1;
					else if (B_num == 3)
						warning[i + 1][j - 1] = 1, warning[i + 3][j - 3] = 1, warning[i - 3][j + 3] = 1;
				}
			}
			if (W_num > B_num) {
				printf("%dW", W_num + 1);
				for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++)
					if (longest_d[i][j] == 1)
						printf("(%d,%d) ", i, j);
			}
			else if (W_num < B_num) {
				printf("%dB", B_num + 1);
				for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++)
					if (longest_d[i][j] == 2)
						printf("(%d,%d) ", i, j);
			}
			else if (W_num != 0 && W_num == B_num) {
				printf("%2d", W_num + 1);
				for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++)
					if (longest_d[i][j] == 1 || longest_d[i][j] == 2)
						printf("(%d,%d) ", i, j);
			}
			else {
				printf("  ");
			}
			W1 = 0, B1 = 0, W_num = 0, B_num = 0;
			for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++) longest_d[i][j] = 0;
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
					longest[j]=1, longest[j + 1] = 1;
					if (W_num == 1)
						hint_arr[i][j - 1] = 1, hint_arr[i][j + 2] = 1;
					else if (W_num == 2) {
						if (baduk[i][j - 1] == 0)
							warning[i][j - 1]=2, warning[i][j - 3]=2, warning[i][j + 2] = 2;
						else
							warning[i][j + 2]=2, warning[i][j - 2] = 2;
					}
					else if (W_num == 3) {
						if (baduk[i][j - 1] == 0)
							warning[i][j - 1]=2, warning[i][j - 4]=2, warning[i][j + 2] = 2;
						else
							warning[i][j + 2]=2, warning[i][j - 3] = 2;
					}
				}
				else if (baduk[i][j + 1] == 0 && baduk[i][j + 2] == 1) {
					W_num++;
					longest[j] = 1 , longest[j + 2] = 1;
					if (W_num == 1)
						hint_arr[i][j - 1] = 1, hint_arr[i][j + 1] = 1, hint_arr[i][j + 3] = 1;
					else if (W_num == 2)
						warning[i][j + 1]=2, warning[i][j + 3]=2, warning[i][j - 2] = 2;
					else if (W_num == 3)
						warning[i][j + 1]=2, warning[i][j + 3]=2, warning[i][j - 3] = 2;
				}
				printf(" W");
				W1++;
				W++;
			}
			else if (baduk[i][j] == 2) {
				if (baduk[i][j + 1] == 2) {
					B_num++;
					longest[j]=2, longest[j + 1] = 2;
					if (B_num == 1)
						hint_arr[i][j - 1] = 2, hint_arr[i][j + 2] = 2;
					else if (B_num == 2) {
						if (baduk[i][j - 1] == 0)
							warning[i][j - 1]=1, warning[i][j - 3]=1, warning[i][j + 2] = 1;
						else
							warning[i][j + 2]=1, warning[i][j - 2] = 1;
					}
					else if (B_num == 3) {
						if (baduk[i][j - 1] == 0)
							warning[i][j - 1]=1, warning[i][j - 4]=1, warning[i][j + 2] = 1;
						else
							warning[i][j + 2]=1, warning[i][j - 3] = 1;
					}
				}
				else if (baduk[i][j + 1] == 0 && baduk[i][j + 2] == 2) {
					B_num++;
					longest[j]=2, longest[j + 2] = 2;
					if (B_num == 1)
						hint_arr[i][j - 1] = 2, hint_arr[i][j + 1] = 2, hint_arr[i][j + 3] = 2;
					else if (B_num == 2)
						warning[i][j + 1]=1, warning[i][j + 3]=1, warning[i][j - 2] = 1;
					else if (B_num == 3)
						warning[i][j + 1]=1, warning[i][j + 3]=1, warning[i][j - 3] = 1;
				}
				printf(" B");
				B1++;
				B++;
			}
			else {
				printf(" *");
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
	int longest_arr[19][19] = { 0 };

	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (baduk[j][i] == 1) {
				if (baduk[j + 1][i] == 1) {
					W_num++;
					longest[j]=1, longest[j + 1] = 1;
					if (W_num == 1)
						hint_arr[j - 1][i] = 1, hint_arr[j + 2][i] = 1;
					else if (W_num == 2) {
						if (baduk[j - 1][i] == 0)
							warning[j - 1][i]=2, warning[j - 3][i]=2, warning[j + 2][i] = 2;
						else
							warning[j + 2][i]=2, warning[j - 2][i] = 2;
					}
					else if (W_num == 3) {
						if (baduk[j - 1][i] == 0)
							warning[j - 1][i]=2, warning[j - 4][i]=2, warning[j + 2][i] = 2;
						else
							warning[j + 2][i]=2, warning[j - 3][i] = 2;
					}
				}
				else if (baduk[j + 1][i] == 0 && baduk[j + 2][i] == 1) {
					W_num++;
					longest[j]=1, longest[j + 2] = 1;
					if (W_num == 2)
						warning[j + 1][i]=2, warning[j + 3][i]=2, warning[j - 2][i] = 2;
					else if (W_num == 3)
						warning[j + 1][i]=2, warning[j + 3][i]=2, warning[j - 3][i] = 2;
				}
				W1++;
			}
			else if (baduk[j][i] == 2) {
				if (baduk[j + 1][i] == 2) {
					B_num++;
					longest[j]=2, longest[j + 1] = 2;
					if (B_num == 2) {
						if (baduk[j - 1][i] == 0)
							warning[j - 1][i]=1, warning[j - 3][i]=1, warning[j + 2][i] = 1;
						else
							warning[j + 2][i]=1, warning[j - 2][i] = 1;
					}
					else if (B_num == 3) {
						if (baduk[j - 1][i] == 0)
							warning[j - 1][i]=1, warning[j - 4][i]=1, warning[j + 2][i] = 1;
						else
							warning[j + 2][i]=1, warning[j - 3][i] = 1;
					}
				}
				else if (baduk[j + 1][i] == 0 && baduk[j + 2][i] == 2) {
					B_num++;
					longest[j]=2, longest[j + 2] = 2;
					if (B_num == 2)
						warning[j + 1][i]=1, warning[j + 3][i]=1, warning[j - 2][i] = 1;
					else if (B_num == 3)
						warning[j + 1][i]=1, warning[j + 3][i]=1, warning[j - 3][i] = 1;
				}
				B1++;
			}
		}
		count[0][i] = W1;
		count[1][i] = B1;
		if (W_num > B_num) {
			num_count[0][i] = W_num;
			for (int j = 0; j < 19; j++)
				if (longest[j] == 1)
					longest_arr[j][i] = 1;
		}
		else if (W_num < B_num) {
			num_count[1][i] = B_num;
			for (int j = 0; j < 19; j++)
				if (longest[j] == 2)
					longest_arr[j][i] = 2;
		}
		else if (W_num != 0 && W_num == B_num) {
			num_count[0][i] = W_num;
			num_count[1][i] = B_num;
			for (int j = 0; j < 19; j++)
				if (longest[j] == 1 || longest[j] == 2)
					longest_arr[j][i] = longest[j];
		}
		W1 = 0, B1 = 0, W_num = 0, B_num = 0;
		for (int i = 0; i < 19; i++) longest[i] = 0;
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
	for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++)
		if (longest_arr[i][j] == 1)
			printf("(%d,%d) ", i, j);
	putchar('\n');
	for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++)
		if (longest_arr[i][j] == 2)
			printf("(%d,%d) ", i, j);
	putchar('\n');
	printf("---------------------------------------------------\n");
	printf("Warning: ");
	for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++) {
		if (baduk[i][j] != 0)
			warning[i][j] = 0;
		else if (warning[i][j] == 1)
			printf("W(%d,%d) ", i, j);
		else if (warning[i][j] == 2)
			printf("B(%d,%d) ", i, j);
	}
	for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++) warning[i][j] = 0;
	for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++) longest_arr[i][j] = 0;
	putchar('\n');
}
int main()
{
	int i = 0, j = 0, a = 1;
	i = rand() % 19;
	j = rand() % 19;

	while (1) {
		for (int a = 0; a < 19; a++) for (int b = 0; b < 19; b++)
			if (baduk[a][b] == 3)
				i = a, j = b;
		if (baduk[i][j] != 0) {
			continue;
		}

		if (a % 2 == 1) {
			baduk[i][j] = 1;
		}
		else {
			baduk[i][j] = 2;
		}
		hint();
		pre();
		system("cls");
		display(baduk);
		printf("W: %d, B: %d", W, B);
		W = 0, B = 0;
		putchar('\n');
		getchar();
		++a;
	}
}
