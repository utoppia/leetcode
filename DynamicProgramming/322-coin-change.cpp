/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-13 01:02:13
 * filename    : 322-coin-change.cpp
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
  int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, -1);
    dp[0] = 0;

    for (int a : coins) {
      for (int i = 1; i <= amount; ++i) {
        if (i - a >= 0 && dp[i - a] != -1) {
          if (dp[i] == -1)
            dp[i] = dp[i - a] + 1;
          else
            dp[i] = min(dp[i], dp[i - a] + 1);
        }
      }
    }

    return dp[amount];
  }
};
