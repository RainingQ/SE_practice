#include "CheckBoxRepete.h"
#include<iostream>
#include<vector>
using namespace std;

//**************重复检验模块**************//
int seedku[10000][8];
int finalsudo = 0;

bool CheckBoxRepete(const vector<int> &seedBox)
{
	for (int i = finalsudo - 1; i > -1; i--)
	{
		for (int j = 0, coun = 8; j < 8; j++)
		{
			if (seedBox[j + 1] == seedku[i][j]) coun--;
			else break;
			if (coun == 0) return false;
		}
	}

	for (int i = 1; i < 9; i++)
		seedku[finalsudo][i - 1] = seedBox[i];

	finalsudo++;
	return true;
}
//**************重复检验模块**************//