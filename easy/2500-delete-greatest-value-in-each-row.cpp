/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-12-29 00:30:04
 * filename    : 2500-delete-greatest-value-in-each-row.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
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
  int deleteGreatestValue(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    for (int i = 0; i < n; ++i)
      sort(vall(grid[i]), greater<int>());
    int ans = 0;

    for (int j = 0, t; j < m; ++j) {
      t = grid[0][j];
      for (int i = 0; i < n; ++i)
        t = max(t, grid[i][j]);
      ans += t;
    }
    return ans;
  }
};
