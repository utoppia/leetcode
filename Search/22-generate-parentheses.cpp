/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 21:25:47
 * filename    : 22-generate-parentheses.cpp
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
private:
  vector<vector<string>> dp;
  vector<string> dfs(int n) {
    if (n == 0) {
      return {""};
    }

    if (dp[n].size())
      return dp[n];
    vector<string> ans;
    for (int i = 0; i < n; ++i) {
      for (string s : dfs(i)) {
        for (string t : dfs(n - 1 - i)) {
          ans.eb("(" + s + ")" + t);
        }
      }
    }

    return dp[n] = ans;
  }

public:
  vector<string> generateParenthesis(int n) {
    dp.assign(n + 1, {});
    return dfs(n);
  }
};
