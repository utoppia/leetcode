/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-11-09 12:12:34
 * filename    : 905-sort-array-by-parity.cpp
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
  vector<int> sortArrayByParity(vector<int> &nums) {
    int n = nums.size();
    vector<int> ret(n);
    int cnt = 0;
    for (int val : nums) {
      if (val & 1)
        continue;
      ret[cnt++] = val;
    }
    for (int val : nums) {
      if (val & 1) {
        ret[cnt++] = val;
      }
    }
    return ret;
  }
};
