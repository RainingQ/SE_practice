#include "DisplaySudo.h"
#include<iostream>
using namespace std;

//**************�������ģ��**************//
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
//**************�������ģ��**************//