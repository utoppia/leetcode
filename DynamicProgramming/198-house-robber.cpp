/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-13 00:53:17
 * filename    : 198-house-robber.cpp
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
#define eb emplace_back
#define fi first
#define snd second
#define sz size

#define ll long long
#define nMax 200005

#define MOD 998244353
using namespace std;

class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.sz();
    if (n == 0)
      return 0;
    vector<vector<int>> dp(n, {0, 0});

    dp[0][0] = nums[0];

    for (int i = 1; i < n; ++i) {
      dp[i][0] = dp[i - 1][1] + nums[i];
      dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
    }

    return max(dp[n - 1][0], dp[n - 1][1]);
  }
};
