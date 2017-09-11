#include "SudoGenerator.h"
#include "CombinationPermutation.h"
#include "CheckBoxRepete.h"
#include "DisplaySudo.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<vector>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;

extern vector<vector<int>> arrange;

void getSeedBox(vector<int> &seedBox)
{
	seedBox = Combination_Permutation1(seedBox);

	for (int i = 0; i < 9; i++)
		if (seedBox[i] == 4)
		{
			swap(seedBox[i], seedBox[0]);
			break;
		}
}

void InitSudo(int(*sudo)[9], const vector<int> &seedBox, int coun)
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			sudo[i][j] = 0;

	for (int i = 0, k = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			sudo[i][j] = seedBox[k++];

	sudo[0][3] = arrange[coun][0];
	sudo[0][4] = arrange[coun][1];
	sudo[0][5] = arrange[coun][2];
}

void SudoGenerator(int N, int(*sudo)[9])
{
	/*����׼��*/
	vector<int> seedBox;
	vector<int> tmp;

	/*��ʼ�����ӹ�*/
	for (int i = 0; i < 9; i++)
		seedBox.push_back(i + 1);

	while (N != 0)
	{
		/*��ȡ���ظ������ӹ�*/
		getSeedBox(seedBox);
		if (!CheckBoxRepete(seedBox))
		{
			/*cout << "Box repete!" << endl;*/
			continue;
		}

		/*���ɲ��ظ��ĵ�������*/
		tmp.assign(seedBox.begin() + 3, seedBox.end());
		Combination_Permutation2(tmp);
		int coun = 0;

		while (N != 0)
		{
			if (coun < 120)
				InitSudo(sudo, seedBox, coun++);
			else
				break;

			for (int i = 1; i < 3; i++)
			{
				/*�޳�ͬ���ѳ��ֵ�����*/
				tmp.assign(seedBox.begin(), seedBox.end());
				tmp.erase(tmp.begin() + 3 * i);
				tmp.erase(tmp.begin() + 3 * i);
				tmp.erase(tmp.begin() + 3 * i);

				/*�޳��ѱ����е�����*/
				for (int j = 0; j < tmp.size(); j++)//i > 0
					if (tmp[j] == sudo[0][3] || tmp[j] == sudo[0][4]
						|| tmp[j] == sudo[0][5] || tmp[j] == sudo[1][3]
						|| tmp[j] == sudo[1][4] || tmp[j] == sudo[1][5])
						tmp.erase(tmp.begin() + (j--));

				/*������������*/
				if (tmp.size() == 6)
					tmp.erase(tmp.begin());
				if (tmp.size() == 5)
					tmp.erase(tmp.begin());
				if (tmp.size() == 4)
					tmp.erase(tmp.begin());

				/*�������*/
				tmp = Combination_Permutation1(tmp, tmp.size(), 3);

				sudo[i][3] = tmp[0];
				sudo[i][4] = tmp[1];
				sudo[i][5] = tmp[2];
			}

			/*������*/
			for (int i = 0; i < 3; i++)
			{
				/*�޳�ͬ�г��ֹ�������*/
				tmp.assign(seedBox.begin(), seedBox.end());
				for (int j = 0; j < tmp.size(); j++)
					if (tmp[j] == sudo[i][0] || tmp[j] == sudo[i][1]
						|| tmp[j] == sudo[i][2] || tmp[j] == sudo[i][3]
						|| tmp[j] == sudo[i][4] || tmp[j] == sudo[i][5])
						tmp.erase(tmp.begin() + (j--));

				/*ȫ����*/
				tmp = Combination_Permutation1(tmp, 3, 3);
				sudo[i][6] = tmp[0];
				sudo[i][7] = tmp[1];
				sudo[i][8] = tmp[2];
			}

			/*�������й���*/
			for (int i = 3; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if (j == 2 || j == 5 || j == 8)
						sudo[i][j] = sudo[i - 3][j - 2];
					else
						sudo[i][j] = sudo[i - 3][j + 1];
				}
			}

			/*�������*/
			display(sudo);

			N--;
			/*cout << "N = " << N << endl;*/
		}
	}
}