/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-11-29 00:04:56
 * filename    : lcp-07-chuan-di-xin-xi.cpp
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
  int numWays(int n, vector<vector<int>> &relation, int k) {
    const vector<int> tmp(n, 0);
    vector<vector<int>> dp(k + 1, tmp);
    dp[0][0] = 1;
    for (int i = 1; i <= k; i++) {
      for (auto u : relation) {
        dp[i][u[1]] += dp[i - 1][u[0]];
      }
    }
    return dp[k][n - 1];
  }
};
