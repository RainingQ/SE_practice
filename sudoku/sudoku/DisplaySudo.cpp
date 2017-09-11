#include "DisplaySudo.h"
#include<stdio.h>
#include<iostream>
using namespace std;

//**************终盘输出模块**************//
void display(int(*sudo)[9])
{
	for (int i = 0; i < 9; i++)
	{
		printf("%d", sudo[i][0]);
		for (int j = 1; j < 9; j++)
			printf(" %d", sudo[i][j]);
		printf("\n");
	}

	printf("\n");
}
//**************终盘输出模块**************//