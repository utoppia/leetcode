/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-13 01:53:38
 * filename    : 416-partition-equal-subset-sum.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <numeric>
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
  bool canPartition(vector<int> &nums) {
    int n = accumulate(vall(nums), 0);
    if (n % 2 != 0)
      return false;
    n >>= 1;

    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int val : nums) {
      for (int i = n - val; i >= 0; --i)
        if (dp[i])
          dp[i + val] = true;
    }

    return dp[n];
  }
};
