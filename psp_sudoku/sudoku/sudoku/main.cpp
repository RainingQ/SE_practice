#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<vector>
#include<algorithm>
#include<string.h>
#include<math.h>
#include "CombinationPermutation.h"
#include "DisplaySudo.h"
#include "CheckBoxRepete.h"
#include "SudoGenerator.h"
using namespace std;

extern vector<vector<int>> arrange;
extern vector<vector<int>> combination;

int main(int argc, char** argv)
{
	srand((int)time(0));
	freopen("sudoku.txt", "w", stdout);

	/*�������*/
	if (strcmp(argv[1], "-c") != 0)
	{
		printf("��������\n");
		return -1;
	}

	int N = 0;
	for (int i = 0; i < strlen(argv[2]); i++)
	{
		if (argv[2][i] < 48 || argv[2][i] > 57)
		{
			printf("��������ȷ��N��\n");
			return -2;
		}
		else
			N = N + (argv[2][i] - 48) * pow(10, (strlen(argv[2]) - i - 1));
	}

	if (N < 0 || N > 1000000)
	{
		printf("NֵԽ�磡");
		return -3;
	}

	/*cout << "N = " << N << endl;*/

	/*����׼��*/
	int sudo[9][9];//vector<vector<int>> sudo[9];

	/*������������*/
	SudoGenerator(N, sudo);

	return 0;
}