/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-28 10:13:28
 * filename    : 2527-find-xor-beauty-of-array.cpp
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
  int xorBeauty(vector<int> &nums) {
    int ans = 0;
    int n = nums.size();

    for (int i = 0; i < 30; ++i) {
      int cnt1 = 0, cnt0 = 0;
      int p = (1 << i);
      for (int val : nums) {
        if (val & p)
          cnt1++;
        else
          cnt0++;
      }
      if (((n - cnt0) & 1) && (cnt1 & 1)) {
        ans += p;
      }
    }
    return ans;
  }
};
