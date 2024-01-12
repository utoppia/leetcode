/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 13:51:23
 * filename    : 368-largest-divisible-subset.cpp
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
  vector<int> largestDivisibleSubset(vector<int> &nums) {
    sort(vall(nums));

    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> pre(n, -1);
    int maxLength = 1, cur = 0;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
          dp[i] = dp[j] + 1;
          pre[i] = j;
        }
      }
      if (dp[i] > maxLength) {
        maxLength = dp[i];
        cur = i;
      }
    }
    vector<int> ans;
    while (cur != -1) {
      ans.pb(nums[cur]);
      cur = pre[cur];
    }
    return ans;
  }
};
