/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-18 13:09:38
 * filename    : 1863-sum-of-all-subset-xor-totals.cpp
 * language    : cpp
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

#define all(v) v.begin(), v.end()
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
  int subsetXORSum(vector<int> &nums) {
    int n = nums.size();
    int ans = 0;
    for (int i = 0, tmp; i < (1 << n); ++i) {
      tmp = 0;
      for (int j = 0; j < n; ++j) {
        if (i & (1 << j))
          tmp ^= nums[j];
      }
      ans += tmp;
    }
    return ans;
  }
};
