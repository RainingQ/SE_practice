#include "DisplaySudo.h"
#include<iostream>
using namespace std;

//**************终盘输出模块**************//
void display(int(*sudo)[9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << sudo[i][j] << " ";
		cout << endl;
	}

	cout << endl;
}
//**************终盘输出模块**************//