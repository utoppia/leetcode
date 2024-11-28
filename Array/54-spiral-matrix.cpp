/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-13 14:01:37
 * filename    : 54-spiral-matrix.cpp
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
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<vector<int>> xy({{0, 1}, {-1, 0}, {0, -1}, {1, 0}});
    int n = matrix.size(), m = matrix[0].size();
    int siz = n * m;
    vector<int> ans(siz);
    vector<bool> vis(siz, false);

    int x = 0, y = 0;
    int u, v;
    int cur = 0, cnt = 0;

    while (true) {
      ans[cnt++] = matrix[x][y];
      vis[x * m + y] = true;
      if (cnt >= siz)
        break;
      while (true) {
        u = x + xy[cur][0];
        v = y + xy[cur][1];
        if (u >= 0 && u < n && v >= 0 && v < m && !vis[u * m + v]) {
          x = u;
          y = v;
          break;
        }
        cur = (cur + 1) % 4;
      }
    }

    return ans;
  }
};
