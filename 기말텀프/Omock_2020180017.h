#pragma once
#include <stdio.h>
#include<stdlib.h>

#define BLACK 2
#define WHITE 1

int W_2020180017, B_2020180017;
int W_num_2020180017, B_num_2020180017;
int longest_2020180017[19];
int Dlongest_2020180017[19][19];
int warning_2020180017[19][19];
int next_2020180017[19][19];
int baduk_2020180017[19][19];
int max_2020180017;
int x_2020180017, y_2020180017;

void Dline_2020180017(int num)
{
	printf("D%d   ", num);
	if (num == 1) {
		for (int a = 0; a < 19; a++) {
			for (int i = 0, j = a; i < 19; i++, j++) {
				if (baduk_2020180017[i][j] == 1 && baduk_2020180017[i + 1][j + 1] == 1) {
					W_num_2020180017++;
					Dlongest_2020180017[i][j] = 1, Dlongest_2020180017[i + 1][j + 1] = 1;
					if (W_num_2020180017 == 2) {
						if (baduk_2020180017[i - 1][j - 1] == 0)
							warning_2020180017[i - 1][j - 1] = 2, warning_2020180017[i - 3][j - 3] = 2, warning_2020180017[i + 2][j + 2] = 2;
						else
							warning_2020180017[i + 2][j + 2] = 2, warning_2020180017[i - 2][j - 2] = 2;
					}
					else if (W_num_2020180017 == 3) {
						if (baduk_2020180017[i - 1][j - 1] == 0)
							warning_2020180017[i - 1][j - 1] = 2, warning_2020180017[i - 4][j - 4] = 2, warning_2020180017[i + 2][j + 2] = 2;
						else
							warning_2020180017[i + 2][j + 2] = 2, warning_2020180017[i - 3][j - 3] = 2;
					}
				}
				else if (baduk_2020180017[i][j] == 1 && baduk_2020180017[i + 1][j + 1] == 0 && baduk_2020180017[i + 2][j + 2] == 1) {
					W_num_2020180017++;
					Dlongest_2020180017[i][j] = 1, Dlongest_2020180017[i + 2][j + 2] = 1;
					if (W_num_2020180017 == 2)
						warning_2020180017[i + 1][j + 1] = 2, warning_2020180017[i + 3][j + 3] = 2, warning_2020180017[i - 2][j - 2] = 2;
					else if (W_num_2020180017 == 3)
						warning_2020180017[i + 1][j + 1] = 2, warning_2020180017[i + 3][j + 3] = 2, warning_2020180017[i - 3][j - 3] = 2;
				}
				if (baduk_2020180017[i][j] == 2 && baduk_2020180017[i + 1][j + 1] == 2) {
					B_num_2020180017++;
					Dlongest_2020180017[i][j] = 2, Dlongest_2020180017[i + 1][j + 1] = 2;
					if (B_num_2020180017 == 2) {
						if (baduk_2020180017[i - 1][j - 1] == 0)
							warning_2020180017[i - 1][j - 1] = 1, warning_2020180017[i - 3][j - 3] = 1, warning_2020180017[i + 2][j + 2] = 1;
						else
							warning_2020180017[i + 2][j + 2] = 1, warning_2020180017[i - 2][j - 2] = 1;
					}
					else if (B_num_2020180017 == 3) {
						if (baduk_2020180017[i - 1][j - 1] == 0)
							warning_2020180017[i - 1][j - 1] = 1, warning_2020180017[i - 4][j - 4] = 1, warning_2020180017[i + 2][j + 2] = 1;
						else
							warning_2020180017[i + 2][j + 2] = 1, warning_2020180017[i - 3][j - 3] = 1;
					}
				}
				else if (baduk_2020180017[i][j] == 2 && baduk_2020180017[i + 1][j + 1] == 0 && baduk_2020180017[i + 2][j + 2] == 2) {
					B_num_2020180017++;
					Dlongest_2020180017[i][j] = 2, Dlongest_2020180017[i + 2][j + 2] = 2;
					if (B_num_2020180017 == 2)
						warning_2020180017[i + 1][j + 1] = 1, warning_2020180017[i + 3][j + 3] = 1, warning_2020180017[i - 2][j - 2] = 1;
					else if (B_num_2020180017 == 3)
						warning_2020180017[i + 1][j + 1] = 1, warning_2020180017[i + 3][j + 3] = 1, warning_2020180017[i - 3][j - 3] = 1;
				}
			}
			W_num_2020180017 = 0, B_num_2020180017 = 0;
			for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++) Dlongest_2020180017[i][j] = 0;
		}
	}
	else if (num == 2) {
		for (int a = 0; a < 19; a++) {
			for (int i = a, j = 0; i < 19; i++, j++) {
				if (baduk_2020180017[i][j] == 1 && baduk_2020180017[i + 1][j + 1] == 1) {
					W_num_2020180017++;
					Dlongest_2020180017[i][j] = 1, Dlongest_2020180017[i + 1][j + 1] = 1;
					if (W_num_2020180017 == 2) {
						if (baduk_2020180017[i - 1][j - 1] == 0)
							warning_2020180017[i - 1][j - 1] = 2, warning_2020180017[i - 3][j - 3] = 2, warning_2020180017[i + 2][j + 2] = 2;
						else
							warning_2020180017[i + 2][j + 2] = 2, warning_2020180017[i - 2][j - 2] = 2;
					}
					else if (W_num_2020180017 == 3) {
						if (baduk_2020180017[i - 1][j - 1] == 0)
							warning_2020180017[i - 1][j - 1] = 2, warning_2020180017[i - 4][j - 4] = 2, warning_2020180017[i + 2][j + 2] = 2;
						else
							warning_2020180017[i + 2][j + 2] = 2, warning_2020180017[i - 3][j - 3] = 2;
					}
				}
				else if (baduk_2020180017[i][j] == 1 && baduk_2020180017[i + 1][j + 1] == 0 && baduk_2020180017[i + 2][j + 2] == 1) {
					W_num_2020180017++;
					Dlongest_2020180017[i][j] = 1, Dlongest_2020180017[i + 2][j + 2] = 1;
					if (W_num_2020180017 == 2)
						warning_2020180017[i + 1][j + 1] = 2, warning_2020180017[i + 3][j + 3] = 2, warning_2020180017[i - 2][j - 2] = 2;
					else if (W_num_2020180017 == 3)
						warning_2020180017[i + 1][j + 1] = 2, warning_2020180017[i + 3][j + 3] = 2, warning_2020180017[i - 3][j - 3] = 2;
				}
				if (baduk_2020180017[i][j] == 2 && baduk_2020180017[i + 1][j + 1] == 2) {
					B_num_2020180017++;
					Dlongest_2020180017[i][j] = 2, Dlongest_2020180017[i + 1][j + 1] = 2;
					if (B_num_2020180017 == 2) {
						if (baduk_2020180017[i - 1][j - 1] == 0)
							warning_2020180017[i - 1][j - 1] = 1, warning_2020180017[i - 3][j - 3] = 1, warning_2020180017[i + 2][j + 2] = 1;
						else
							warning_2020180017[i + 2][j + 2] = 1, warning_2020180017[i - 2][j - 2] = 1;
					}
					else if (B_num_2020180017 == 3) {
						if (baduk_2020180017[i - 1][j - 1] == 0)
							warning_2020180017[i - 1][j - 1] = 1, warning_2020180017[i - 4][j - 4] = 1, warning_2020180017[i + 2][j + 2] = 1;
						else
							warning_2020180017[i + 2][j + 2] = 1, warning_2020180017[i - 3][j - 3] = 1;
					}
				}
				else if (baduk_2020180017[i][j] == 2 && baduk_2020180017[i + 1][j + 1] == 0 && baduk_2020180017[i + 2][j + 2] == 2) {
					B_num_2020180017++;
					Dlongest_2020180017[i][j] = 2, Dlongest_2020180017[i + 2][j + 2] = 2;
					if (B_num_2020180017 == 2)
						warning_2020180017[i + 1][j + 1] = 1, warning_2020180017[i + 3][j + 3] = 1, warning_2020180017[i - 2][j - 2] = 1;
					else if (B_num_2020180017 == 3)
						warning_2020180017[i + 1][j + 1] = 1, warning_2020180017[i + 3][j + 3] = 1, warning_2020180017[i - 3][j - 3] = 1;
				}
			}
			W_num_2020180017 = 0, B_num_2020180017 = 0;
			for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++) Dlongest_2020180017[i][j] = 0;
		}
	}
	else if (num == 3) {
		for (int a = 0; a < 19; a++) {
			for (int i = 0, j = a; i <= a; i++, j--) {
				if (baduk_2020180017[i][j] == 1 && baduk_2020180017[i + 1][j - 1] == 1) {
					W_num_2020180017++;
					Dlongest_2020180017[i][j] = 1, Dlongest_2020180017[i + 1][j - 1] = 1;
					if (W_num_2020180017 == 2) {
						if (baduk_2020180017[i - 1][j + 1] == 0)
							warning_2020180017[i - 1][j + 1] = 2, warning_2020180017[i - 3][j + 3] = 2, warning_2020180017[i + 2][j - 2] = 2;
						else
							warning_2020180017[i + 2][j - 2] = 2, warning_2020180017[i - 2][j + 2] = 2;
					}
					else if (W_num_2020180017 == 3) {
						if (baduk_2020180017[i - 1][j + 1] == 0)
							warning_2020180017[i - 1][j + 1] = 2, warning_2020180017[i - 4][j + 4] = 2, warning_2020180017[i + 2][j - 2] = 2;
						else
							warning_2020180017[i + 2][j - 2] = 2, warning_2020180017[i - 3][j + 3] = 2;
					}
				}
				else if (baduk_2020180017[i][j] == 1 && baduk_2020180017[i + 1][j - 1] == 0 && baduk_2020180017[i + 2][j - 2] == 1) {
					W_num_2020180017++;
					Dlongest_2020180017[i][j] = 1, Dlongest_2020180017[i + 2][j - 2] = 1;
					if (W_num_2020180017 == 2)
						warning_2020180017[i + 1][j - 1] = 2, warning_2020180017[i + 3][j - 3] = 2, warning_2020180017[i - 2][j + 2] = 2;
					else if (W_num_2020180017 == 3)
						warning_2020180017[i + 1][j - 1] = 2, warning_2020180017[i + 3][j - 3] = 2, warning_2020180017[i - 3][j + 3] = 2;
				}
				if (baduk_2020180017[i][j] == 2 && baduk_2020180017[i + 1][j - 1] == 2) {
					B_num_2020180017++;
					Dlongest_2020180017[i][j] = 2, Dlongest_2020180017[i + 1][j - 1] = 2;
					if (B_num_2020180017 == 2) {
						if (baduk_2020180017[i - 1][j + 1] == 0)
							warning_2020180017[i - 1][j + 1] = 1, warning_2020180017[i - 3][j + 3] = 1, warning_2020180017[i + 2][j - 2] = 1;
						else
							warning_2020180017[i + 2][j - 2] = 1, warning_2020180017[i - 2][j + 2] = 1;
					}
					else if (B_num_2020180017 == 3) {
						if (baduk_2020180017[i - 1][j + 1] == 0)
							warning_2020180017[i - 1][j + 1] = 1, warning_2020180017[i - 4][j + 4] = 1, warning_2020180017[i + 2][j - 2] = 1;
						else
							warning_2020180017[i + 2][j - 2] = 1, warning_2020180017[i - 3][j + 3] = 1;
					}
				}
				else if (baduk_2020180017[i][j] == 2 && baduk_2020180017[i + 1][j - 1] == 0 && baduk_2020180017[i + 2][j - 2] == 2) {
					B_num_2020180017++;
					Dlongest_2020180017[i][j] = 2, Dlongest_2020180017[i + 2][j - 2] = 2;
					if (B_num_2020180017 == 2)
						warning_2020180017[i + 1][j - 1] = 1, warning_2020180017[i + 3][j - 3] = 1, warning_2020180017[i - 2][j + 2] = 1;
					else if (B_num_2020180017 == 3)
						warning_2020180017[i + 1][j - 1] = 1, warning_2020180017[i + 3][j - 3] = 1, warning_2020180017[i - 3][j + 3] = 1;
				}
			}
			W_num_2020180017 = 0, B_num_2020180017 = 0;
			for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++) Dlongest_2020180017[i][j] = 0;
		}
	}
	else if (num == 4) {
		for (int a = 0; a < 19; a++) {
			for (int i = a, j = 19; i <= a; i++, j--) {
				if (baduk_2020180017[i][j] == 1 && baduk_2020180017[i + 1][j - 1] == 1) {
					W_num_2020180017++;
					Dlongest_2020180017[i][j] = 1, Dlongest_2020180017[i + 1][j - 1] = 1;
					if (W_num_2020180017 == 2) {
						if (baduk_2020180017[i - 1][j + 1] == 0)
							warning_2020180017[i - 1][j + 1] = 2, warning_2020180017[i - 3][j + 3] = 2, warning_2020180017[i + 2][j - 2] = 2;
						else
							warning_2020180017[i + 2][j - 2] = 2, warning_2020180017[i - 2][j + 2] = 2;
					}
					else if (W_num_2020180017 == 3) {
						if (baduk_2020180017[i - 1][j + 1] == 0)
							warning_2020180017[i - 1][j + 1] = 2, warning_2020180017[i - 4][j + 4] = 2, warning_2020180017[i + 2][j - 2] = 2;
						else
							warning_2020180017[i + 2][j - 2] = 2, warning_2020180017[i - 3][j + 3] = 2;
					}
				}
				else if (baduk_2020180017[i][j] == 1 && baduk_2020180017[i + 1][j - 1] == 0 && baduk_2020180017[i + 2][j - 2] == 1) {
					W_num_2020180017++;
					Dlongest_2020180017[i][j] = 1, Dlongest_2020180017[i + 2][j - 2] = 1;
					if (W_num_2020180017 == 2)
						warning_2020180017[i + 1][j - 1] = 2, warning_2020180017[i + 3][j - 3] = 2, warning_2020180017[i - 2][j + 2] = 2;
					else if (W_num_2020180017 == 3)
						warning_2020180017[i + 1][j - 1] = 2, warning_2020180017[i + 3][j - 3] = 2, warning_2020180017[i - 3][j + 3] = 2;
				}
				if (baduk_2020180017[i][j] == 2 && baduk_2020180017[i + 1][j - 1] == 2) {
					B_num_2020180017++;
					Dlongest_2020180017[i][j] = 2, Dlongest_2020180017[i + 1][j - 1] = 2;
					if (B_num_2020180017 == 2) {
						if (baduk_2020180017[i - 1][j + 1] == 0)
							warning_2020180017[i - 1][j + 1] = 1, warning_2020180017[i - 3][j + 3] = 1, warning_2020180017[i + 2][j - 2] = 1;
						else
							warning_2020180017[i + 2][j - 2] = 1, warning_2020180017[i - 2][j + 2] = 1;
					}
					else if (B_num_2020180017 == 3) {
						if (baduk_2020180017[i - 1][j + 1] == 0)
							warning_2020180017[i - 1][j + 1] = 1, warning_2020180017[i - 4][j + 4] = 1, warning_2020180017[i + 2][j - 2] = 1;
						else
							warning_2020180017[i + 2][j - 2] = 1, warning_2020180017[i - 3][j + 3] = 1;
					}
				}
				else if (baduk_2020180017[i][j] == 2 && baduk_2020180017[i + 1][j - 1] == 0 && baduk_2020180017[i + 2][j - 2] == 2) {
					B_num_2020180017++;
					Dlongest_2020180017[i][j] = 2, Dlongest_2020180017[i + 2][j - 2] = 2;
					if (B_num_2020180017 == 2)
						warning_2020180017[i + 1][j - 1] = 1, warning_2020180017[i + 3][j - 3] = 1, warning_2020180017[i - 2][j + 2] = 1;
					else if (B_num_2020180017 == 3)
						warning_2020180017[i + 1][j - 1] = 1, warning_2020180017[i + 3][j - 3] = 1, warning_2020180017[i - 3][j + 3] = 1;
				}
			}
			W_num_2020180017 = 0, B_num_2020180017 = 0;
			for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++) Dlongest_2020180017[i][j] = 0;
		}
	}
}
void search_2020180017(int, int, int);
void new_2020180017(int color)
{
	if (W_2020180017==0 && WHITE == color) {
		while(1) {
			x_2020180017 = rand() % 19;
			y_2020180017 = rand() % 19;
			if (baduk_2020180017[x_2020180017][y_2020180017] == 0) {
				W_2020180017++;
				break;
			}
		}
	}
	else if (B_2020180017 == 0 && BLACK == color) {
		while (1) {
			x_2020180017 = rand() % 19;
			y_2020180017 = rand() % 19;
			if (baduk_2020180017[x_2020180017][y_2020180017] == 0) {
				B_2020180017++;
				break;
			}
		}
	}
	for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++) {
		if (baduk_2020180017[i][j] != 0)
			next_2020180017[i][j] = 0;
		if (warning_2020180017[i][j] == 1)
			next_2020180017[i][j] = 2;
		else if (warning_2020180017[i][j] == 2)
			next_2020180017[i][j] = 1;
	}
	if (WHITE==color) 
		for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++) {
			if (next_2020180017[i][j] == 1)
				search_2020180017(i, j, 1);
		}
	else if (BLACK==color) {
		for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++) {
			if (next_2020180017[i][j] == 2)
				search_2020180017(i, j, 2);
		}
	}
	max_2020180017 = 0;
}
void check_2020180017(int color)
{
	Dline_2020180017(1);
	Dline_2020180017(2);
	Dline_2020180017(3);
	Dline_2020180017(4);


	for (int i = 0; i < 19; ++i) {
		for (int j = 0; j < 19; ++j) {
			if (baduk_2020180017[i][j] == 1) {
				if (baduk_2020180017[i][j + 1] == 1) {
					W_num_2020180017++;
					longest_2020180017[j] = 1, longest_2020180017[j + 1] = 1;
					if (W_num_2020180017 == 1) {
						next_2020180017[i][j + 2] = 1, next_2020180017[i][j - 1] = 1;
					}
					if (W_num_2020180017 == 2) {
						if (baduk_2020180017[i][j - 1] == 0)
							warning_2020180017[i][j - 1] = 2, warning_2020180017[i][j - 3] = 2, warning_2020180017[i][j + 2] = 2;
						else
							warning_2020180017[i][j + 2] = 2, warning_2020180017[i][j - 2] = 2;
					}
					else if (W_num_2020180017 == 3) {
						if (baduk_2020180017[i][j - 1] == 0)
							warning_2020180017[i][j - 1] = 2, warning_2020180017[i][j - 4] = 2, warning_2020180017[i][j + 2] = 2;
						else
							warning_2020180017[i][j + 2] = 2, warning_2020180017[i][j - 3] = 2;
					}
				}
				else if (baduk_2020180017[i][j + 1] == 0 && baduk_2020180017[i][j + 2] == 1) {
					W_num_2020180017++;
					longest_2020180017[j] = 1, longest_2020180017[j + 2] = 1;
					if (W_num_2020180017 == 1) {
						next_2020180017[i][j + 3] = 1, next_2020180017[i][j + 1] = 1, next_2020180017[i][j - 1] = 1;
					}
					if (W_num_2020180017 == 2)
						warning_2020180017[i][j + 1] = 2, warning_2020180017[i][j + 3] = 2, warning_2020180017[i][j - 2] = 2;
					else if (W_num_2020180017 == 3)
						warning_2020180017[i][j + 1] = 2, warning_2020180017[i][j + 3] = 2, warning_2020180017[i][j - 3] = 2;
				}
				else if (W_2020180017==1 && W_num_2020180017 == 0) {
					int num = 0, num1 = 0;
					for (int a = i - 1; num < 3; a++, num++) {
						for (int b = j - 1; num1 < 3; b++, num1++) {
							next_2020180017[a][b] = 1;
						}
						num1 = 0;
					}
					W_2020180017++;
				}
			}
			else if (baduk_2020180017[i][j] == 2) {
				if (baduk_2020180017[i][j + 1] == 2) {
					B_num_2020180017++;
					longest_2020180017[j] = 2, longest_2020180017[j + 1] = 2;
					if (B_num_2020180017 == 1) {
						next_2020180017[i][j + 2] = 2, next_2020180017[i][j - 1] = 2;
					}
					if (B_num_2020180017 == 2) {
						if (baduk_2020180017[i][j - 1] == 0)
							warning_2020180017[i][j - 1] = 1, warning_2020180017[i][j - 3] = 1, warning_2020180017[i][j + 2] = 1;
						else
							warning_2020180017[i][j + 2] = 1, warning_2020180017[i][j - 2] = 1;
					}
					else if (B_num_2020180017 == 3) {
						if (baduk_2020180017[i][j - 1] == 0)
							warning_2020180017[i][j - 1] = 1, warning_2020180017[i][j - 4] = 1, warning_2020180017[i][j + 2] = 1;
						else
							warning_2020180017[i][j + 2] = 1, warning_2020180017[i][j - 3] = 1;
					}
				}
				else if (baduk_2020180017[i][j + 1] == 0 && baduk_2020180017[i][j + 2] == 2) {
					B_num_2020180017++;
					longest_2020180017[j] = 2, longest_2020180017[j + 2] = 2;
					if (B_num_2020180017 == 1) {
						next_2020180017[i][j + 3] = 2, next_2020180017[i][j + 1] = 2, next_2020180017[i][j - 1] = 2;
					}
					if (B_num_2020180017 == 2)
						warning_2020180017[i][j + 1] = 1, warning_2020180017[i][j + 3] = 1, warning_2020180017[i][j - 2] = 1;
					else if (B_num_2020180017 == 3)
						warning_2020180017[i][j + 1] = 1, warning_2020180017[i][j + 3] = 1, warning_2020180017[i][j - 3] = 1;
				}
				else if (B_2020180017==1 && B_num_2020180017 == 0) {
					int num = 0, num1 = 0;
					for (int a = i - 1; num < 3; a++, num++) {
						for (int b = j - 1; num1 < 3; b++, num1++) {
							next_2020180017[a][b] = 2;
						}
						num1 = 0;
					}
					B_2020180017++;
				}
			}
		}
		W_num_2020180017 = 0, B_num_2020180017 = 0;
		for (int i = 0; i < 19; i++) longest_2020180017[i] = 0;
	}

	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (baduk_2020180017[j][i] == 1) {
				if (baduk_2020180017[j + 1][i] == 1) {
					W_num_2020180017++;
					longest_2020180017[j] = 1, longest_2020180017[j + 1] = 1;
					if (W_num_2020180017 == 2) {
						if (baduk_2020180017[j - 1][i] == 0)
							warning_2020180017[j - 1][i] = 2, warning_2020180017[j - 3][i] = 2, warning_2020180017[j + 2][i] = 2;
						else
							warning_2020180017[j + 2][i] = 2, warning_2020180017[j - 2][i] = 2;
					}
					else if (W_num_2020180017 == 3) {
						if (baduk_2020180017[j - 1][i] == 0)
							warning_2020180017[j - 1][i] = 2, warning_2020180017[j - 4][i] = 2, warning_2020180017[j + 2][i] = 2;
						else
							warning_2020180017[j + 2][i] = 2, warning_2020180017[j - 3][i] = 2;
					}
				}
				else if (baduk_2020180017[j + 1][i] == 0 && baduk_2020180017[j + 2][i] == 1) {
					W_num_2020180017++;
					longest_2020180017[j] = 1, longest_2020180017[j + 2] = 1;
					if (W_num_2020180017 == 2)
						warning_2020180017[j + 1][i] = 2, warning_2020180017[j + 3][i] = 2, warning_2020180017[j - 2][i] = 2;
					else if (W_num_2020180017 == 3)
						warning_2020180017[j + 1][i] = 2, warning_2020180017[j + 3][i] = 2, warning_2020180017[j - 3][i] = 2;
				}
			}
			else if (baduk_2020180017[j][i] == 2) {
				if (baduk_2020180017[j + 1][i] == 2) {
					B_num_2020180017++;
					longest_2020180017[j] = 2, longest_2020180017[j + 1] = 2;
					if (B_num_2020180017 == 2) {
						if (baduk_2020180017[j - 1][i] == 0)
							warning_2020180017[j - 1][i] = 1, warning_2020180017[j - 3][i] = 1, warning_2020180017[j + 2][i] = 1;
						else
							warning_2020180017[j + 2][i] = 1, warning_2020180017[j - 2][i] = 1;
					}
					else if (B_num_2020180017 == 3) {
						if (baduk_2020180017[j - 1][i] == 0)
							warning_2020180017[j - 1][i] = 1, warning_2020180017[j - 4][i] = 1, warning_2020180017[j + 2][i] = 1;
						else
							warning_2020180017[j + 2][i] = 1, warning_2020180017[j - 3][i] = 1;
					}
				}
				else if (baduk_2020180017[j + 1][i] == 0 && baduk_2020180017[j + 2][i] == 2) {
					B_num_2020180017++;
					longest_2020180017[j] = 2, longest_2020180017[j + 2] = 2;
					if (B_num_2020180017 == 2)
						warning_2020180017[j + 1][i] = 1, warning_2020180017[j + 3][i] = 1, warning_2020180017[j - 2][i] = 1;
					else if (B_num_2020180017 == 3)
						warning_2020180017[j + 1][i] = 1, warning_2020180017[j + 3][i] = 1, warning_2020180017[j - 3][i] = 1;
				}
			}
		}
		W_num_2020180017 = 0, B_num_2020180017 = 0;
		for (int i = 0; i < 19; i++) longest_2020180017[i] = 0;
	}
	//warning
	for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++) {
		if (baduk_2020180017[i][j] != 0)
			warning_2020180017[i][j] = 0;
	}
	new_2020180017(color);
	for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++) warning_2020180017[i][j] = 0;
}

void search_2020180017(int i, int j, int color)
{
	int a = 0, b = 0;
	int num = 0, num1 = 0, num2 = 0;
	for (int a = i - 1; num1 < 3; a++, num1++) {
		for (int b = j - 1; num2 < 3; b++, num2++) {
			if (baduk_2020180017[a][b] == color)
				num++;
		}
		num2 = 0;
	}
	if (max_2020180017 < num) {
		max_2020180017 = num;
		y_2020180017 = i, x_2020180017 = j;
	}
}
void WhiteAttack_2020180017(int* x, int* y)
{
	check_2020180017(WHITE);
	*x = x_2020180017;
	*y = y_2020180017;
	baduk_2020180017[*y][*x] = WHITE;
}
void WhiteDefence_2020180017(int x, int y)
{
	baduk_2020180017[y][x] = BLACK;
}
void BlackAttack_2020180017(int* x, int* y)
{
	check_2020180017(BLACK);
	*x = x_2020180017;
	*y = y_2020180017;
	baduk_2020180017[*y][*x] = BLACK;
}
void BlackDefence_2020180017(int x, int y)
{
	baduk_2020180017[y][x] = WHITE;
}