/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-11-15 01:09:43
 * filename    : 944-delete-columns-to-make-sorted.cpp
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
public:
  int minDeletionSize(vector<string> &strs) {
    int n = strs.size();
    int m = strs[0].length();
    int ans = 0;

    for (int j = 0; j < m; ++j) {
      for (int i = 1; i < n; ++i) {
        if (strs[i][j] < strs[i - 1][j]) {
          ans++;
          break;
        }
      }
    }
    return ans;
  }
};
