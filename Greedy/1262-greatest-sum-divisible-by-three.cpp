/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-08 00:29:34
 * filename    : 1262-greatest-sum-divisible-by-three.cpp
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
  int maxSumDivThree(vector<int> &nums) {
    vector<int> mod_1, mod_2;
    int ret = 0;
    for (int v : nums) {
      if (v % 3 == 1)
        mod_1.pb(v);
      if (v % 3 == 2)
        mod_2.pb(v);
      ret += v;
    }
    if (ret % 3 == 0)
      return ret;
    sort(vall(mod_1));
    sort(vall(mod_2));
    if (ret % 3 == 1) {
      int minus = 100000;
      if (mod_1.size() > 0)
        minus = min(minus, mod_1[0]);
      if (mod_2.size() > 1)
        minus = min(minus, mod_2[0] + mod_2[1]);
      return ret - minus;
    }
    if (ret % 3 == 2) {
      int minus = 100000;
      if (mod_2.size() > 0)
        minus = min(minus, mod_2[0]);
      if (mod_1.size() > 1)
        minus = min(minus, mod_1[0] + mod_1[1]);
      return ret - minus;
    }
    return 0;
  }
};
