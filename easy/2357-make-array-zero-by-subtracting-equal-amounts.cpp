/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-12-28 23:34:09
 * filename    : 2357-make-array-zero-by-subtracting-equal-amounts.cpp
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
  int minimumOperations(vector<int> &nums) {
    set<int> S;
    for (int val : nums)
      if (val != 0)
        S.insert(val);
    return S.size();
  }
};
