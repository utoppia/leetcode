/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-13 00:58:01
 * filename    : 279-perfect-squares.cpp
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
  int numSquares(int n) {
    vector<int> perfectSquare(101);
    for (int i = 0; i < 101; ++i)
      perfectSquare[i] = i * i;

    vector<int> dp(n + 1);
    iota(vall(dp), 0);

    for (int j : perfectSquare) {
      for (int i = j; i <= n; ++i)
        dp[i] = min(dp[i], dp[i - j] + 1);
    }

    return dp[n];
  }
};
