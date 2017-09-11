#include "CombinationPermutation.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<vector>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;

//**************排列组合模块**************//
vector<int> vec;
vector<vector<int>> arrange;
vector<vector<int>> combination;

/*枚举所有组合情况*/
void Combination(vector<int> &tmp, int need)
{
	if (need == 0) return;

	int coun = 0;
	vector<int> copy;
	copy.assign(tmp.begin(), tmp.end());

	while (coun != tmp.size())
	{
		vec.push_back(copy.back());
		copy.pop_back();
		Combination(copy, need - 1);
		if (need == 1)
			combination.push_back(vec);
		vec.pop_back();
		coun++;
	}
}

/*枚举法全排列*/
void FullPermutation(vector<int> &tmp)
{
	int size = tmp.size();
	if (size == 0) return;

	vector<int> copy;
	for (int i = 0; i < size; i++)
	{
		if (i > 0) vec.pop_back();

		copy.assign(tmp.begin(), tmp.end());
		vec.push_back(copy[i]);
		copy.erase(copy.begin() + i);

		FullPermutation(copy);
	}

	if (copy.empty())
		arrange.push_back(vec);

	vec.pop_back();
}

/*获得所有的组合排列情况*/
void Combination_Permutation2(vector<int> &tmp, int need)
{
	combination.clear();
	arrange.clear();

	if (tmp.size() > need)
	{
		Combination(tmp);
		for (int i = 0; i < combination.size(); i++)
			FullPermutation(combination[i]);
	}
	else
		FullPermutation(tmp);
}

/*随机获得一种组合情况*/
vector<int> Combination_Permutation1(vector<int> &waitCom, int n, int m)
{
	int coun = 0;
	int rng;
	/*srand((int)time(0));*/

	vector<int> comb;
	if (n == m)
		comb.assign(waitCom.begin(), waitCom.end());
	while (coun != m && m != n && waitCom.size() != 0)
	{
		rng = rand() % waitCom.size();
		comb.push_back(waitCom[rng]);
		waitCom.erase(waitCom.begin() + rng);
		coun++;
	}

	vector<int> perm;
	while (!comb.empty())
	{
		rng = rand() % comb.size();
		perm.push_back(comb[rng]);
		comb.erase(comb.begin() + rng);
	}

	return perm;
}
//**************排列组合模块**************//