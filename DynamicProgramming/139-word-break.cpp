/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-13 01:04:26
 * filename    : 139-word-break.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
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
  bool wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> S(vall(wordDict));
    int n = s.length();
    vector<bool> dp(n, false);

    for (int i = 0; i < n; ++i) {
      int j = i;
      string tmp = "";
      while (j >= 0) {
        tmp = s[j] + tmp;
        if ((j == 0 || dp[j - 1]) && S.count(tmp)) {
          dp[i] = true;
          break;
        }
        j--;
      }
    }

    return dp[n - 1];
  }
};
