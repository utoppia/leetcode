/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 21:13:37
 * filename    : 17-letter-combinations-of-a-phone-number.cpp
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
  void dfs(string digits, int n, string s, vector<string> &ans) {
    if (n == digits.length()) {
      ans.push_back(s);
      return;
    }
    switch (digits[n]) {
    case '1': {
      dfs(digits, n + 1, s, ans);
      break;
    }
    case '2': {
      dfs(digits, n + 1, s + "a", ans);
      dfs(digits, n + 1, s + "b", ans);
      dfs(digits, n + 1, s + "c", ans);
      break;
    }
    case '3': {
      dfs(digits, n + 1, s + "d", ans);
      dfs(digits, n + 1, s + "e", ans);
      dfs(digits, n + 1, s + "f", ans);
      break;
    }
    case '4': {
      dfs(digits, n + 1, s + "g", ans);
      dfs(digits, n + 1, s + "h", ans);
      dfs(digits, n + 1, s + "i", ans);
      break;
    }
    case '5': {
      dfs(digits, n + 1, s + "j", ans);
      dfs(digits, n + 1, s + "k", ans);
      dfs(digits, n + 1, s + "l", ans);
      break;
    }
    case '6': {
      dfs(digits, n + 1, s + "m", ans);
      dfs(digits, n + 1, s + "n", ans);
      dfs(digits, n + 1, s + "o", ans);
      break;
    }
    case '7': {
      dfs(digits, n + 1, s + "p", ans);
      dfs(digits, n + 1, s + "q", ans);
      dfs(digits, n + 1, s + "r", ans);
      dfs(digits, n + 1, s + "s", ans);
      break;
    }
    case '8': {
      dfs(digits, n + 1, s + "t", ans);
      dfs(digits, n + 1, s + "u", ans);
      dfs(digits, n + 1, s + "v", ans);
      break;
    }
    case '9': {
      dfs(digits, n + 1, s + "w", ans);
      dfs(digits, n + 1, s + "x", ans);
      dfs(digits, n + 1, s + "y", ans);
      dfs(digits, n + 1, s + "z", ans);
      break;
    }
    }
    return;
  }

public:
  vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if (digits.length() == 0)
      return ans;
    dfs(digits, 0, "", ans);
    return ans;
  }
};
