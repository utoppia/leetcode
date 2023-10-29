/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-29 19:48:33
 * filename    : 792-number-of-matching-subsequences.cpp
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
private:
  bool check(vector<vector<int>> &pos, string t) {
    int m = t.length();
    int i = -1;
    for (int j = 0, c, ans; j < m; ++j) {
      c = t[j] - 'a';
      ans = -1;
      int l = 0, r = pos[c].size() - 1;
      while (l <= r) {
        int m = (l + r) >> 1;
        if (pos[c][m] > i) {
          ans = pos[c][m];
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
      if (ans == -1)
        return false;
      i = ans;
    }
    return true;
  }

public:
  int numMatchingSubseq(string s, vector<string> &words) {
    int cnt = 0;
    vector<vector<int>> pos(26);
    for (int i = 0; i < s.length(); ++i) {
      pos[s[i] - 'a'].pb(i);
    }
    for (string t : words)
      if (check(pos, t))
        cnt++;
    return cnt;
  }
};
