/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-13 01:48:53
 * filename    : 152-maximum-product-subarray.cpp
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
  int maxProduct(vector<int> &nums) {
    int n = nums.size();

    vector<vector<int>> dp(n, {0, 0});
    dp[0][0] = dp[0][1] = nums[0];
    int ans = dp[0][1];

    for (int i = 1; i < n; ++i) {
      dp[i][0] =
          min(nums[i], min(dp[i - 1][0] * nums[i], dp[i - 1][1] * nums[i]));
      dp[i][1] =
          max(nums[i], max(dp[i - 1][0] * nums[i], dp[i - 1][1] * nums[i]));
      ans = max(ans, dp[i][1]);
    }

    return ans;
  }
};
