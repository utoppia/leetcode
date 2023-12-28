/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-11-19 13:52:58
 * filename    : 1018-binary-prefix-divisible-by-.cpp
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
  vector<bool> prefixesDivBy5(vector<int> &nums) {
    int n = nums.size();
    vector<bool> ans(n);
    int val = 0;

    for (int i = 0; i < n; ++i) {
      val = val * 2 + nums[i];
      val %= 5;
      if (val == 0)
        ans[i] = true;
      else
        ans[i] = false;
    }
    return ans;
  }
};
