#pragma once
#ifndef __COMBINATIONPERMUTATION_H_
#define __COMBINATIONPERMUTATION_H_
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<vector>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;

void Combination( vector<int> &tmp, int need = 3);
void FullPermutation( vector<int> &tmp);//枚举法全排列
void Combination_Permutation2( vector<int> &tmp, int need = 3);//获得所有的组合排列情况
vector<int> Combination_Permutation1(vector<int> &waitCom, int n = 9, int m = 9);//随机获得一种组合情况

#endif