/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 20:42:09
 * filename    : 200-number-of-islands.cpp
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
  void dfs(int x, int y, vector<vector<char>> &grid, int n, int m) {
    if (x < 0 || x >= n || y < 0 || y >= m)
      return;
    if (grid[x][y] == '0')
      return;
    grid[x][y] = '0';
    dfs(x + 1, y, grid, n, m);
    dfs(x - 1, y, grid, n, m);
    dfs(x, y + 1, grid, n, m);
    dfs(x, y - 1, grid, n, m);
  }

public:
  int numIslands(vector<vector<char>> &grid) {
    int n = grid.sz(), m = grid[0].sz();
    int ans = 0;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j)
        if (grid[i][j] == '1') {
          dfs(i, j, grid, n, m);
          ans++;
        }
    }

    return ans;
  }
};
