/******************************************
 * author      : utoppia
 * description : solution for leecode
 * updated at  : 2023-12-28 21:13:33
 * filename    : 2769-find-the-maximum-achievable-number.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

#define vall(v) v.begin(), v.end()
#define pir pair<int, int>

#define pb push_back
#define fi first
#define snd second

#define ll long long
#define nMax 200005

#define MOD 998244353
using namespace std;

class Solution {
public:
  int theMaximumAchievableX(int num, int t) { return num + 2 * t; }
};
