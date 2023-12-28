/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-12-28 21:09:54
 * filename    : 2965-find-missing-and-repeated-values.cpp
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
  vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid) {
    int n = grid.size();
    vector<int> ans(2);
    vector<int> vis(n * n + 1);
    for (int i = 0; i < n; ++i) {
      for (int val : grid[i])
        if (vis[val] == 1)
          ans[0] = val;
        else
          vis[val] = 1;
    }
    for (int i = 1; i <= n * n; ++i)
      if (vis[i] == 0)
        ans[1] = i;
    return ans;
  }
};
