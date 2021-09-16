#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<windows.h>

#define ONE_SECOND 1000

int printAStar()
{
	putchar('*');
}

int printStars(int n)
{
	for (int j = 0; j < n; ++j) {
		putchar('*');
		Sleep(ONE_SECOND);
	}
}


int Recursive(int i, int num)
{
	for (int j = 0; j < i; ++j) {
		putchar('*');
		Sleep(ONE_SECOND);
	}
	putchar('\n');

	if (num == i) return 1;

	Recursive(i+1, num);
}

int main() 
{
	//******************************************************************************
	
	printf("1.\n");

	for (int i=0; i<4; ++i) {
		for (int j = 0; j < i + 1; ++j) {
			putchar('*');
			Sleep(ONE_SECOND);
		}
		putchar('\n');
	}
	putchar('\n');
	//************************************************************************************************

	printf("2.\n");

	int num = 0;
	scanf("%d", &num); 

	for (int i = 0; i < num; ++i) {
		for (int j = 0; j < i + 1; ++j) {
			putchar('*');
			Sleep(ONE_SECOND);
		}
		putchar('\n');
	}
	putchar('\n');
	//**************************************************************************************************

	printf("3.\n");

	
	scanf("%d", &num); 

	for (int i = 1; i < num + 1; ++i) {
		for (int j = 1; j < i + 1; ++j) {
			printf("%d", j);
			Sleep(ONE_SECOND);
		}
		putchar('\n');
	}
	putchar('\n');
	//******************************************************************************************************
	
	printf("4.\n");

	
	scanf("%d", &num); 

	for (int i = 0; i < num; ++i) {
		for (int j = 0; j < i + 1; ++j) {
			printAStar();
			Sleep(ONE_SECOND);
		}
		putchar('\n');
	}
	putchar('\n');
	//******************************************************************************************

	printf("5.\n");

	int n = 0;
	scanf("%d", &num); 

	for (int i = 0; i < num; ++i) {
		++n;
		printStars(n);
		putchar('\n');
	}
	putchar('\n');
	//****************************************************************************************************

	printf("6.\n");

	
	int i = 1;
	scanf("%d", &num); 

	Recursive(i, num);

	return 0;
}