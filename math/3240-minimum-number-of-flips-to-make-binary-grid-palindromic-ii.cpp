/******************************************
 * author      : utoppia
 * description : 3240-minimum-number-of-flips-to-make-binary-grid-palindromic-ii
 * updated at  : 2024-11-17 00:58:10
 * filename    :
 *3240-minimum-number-of-flips-to-make-binary-grid-palindromic-ii.cpp language
 *: cpp editor      : Emacs 27.1
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
  int minFlips(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;
    for (int i = 0; i < n / 2; ++i) {
      for (int j = 0; j < m / 2; ++j) {
        int p = grid[i][j] + grid[i][m - 1 - j] + grid[n - 1 - i][j] +
                grid[n - 1 - i][m - 1 - j];
        ans = abs(p) < 4 - abs(p) ? abs(p) : 4 - abs(p);
      }
    }
    if (m % 2 == 1) {
      for (int i = 0; i < n / 2; ++i) {
        int p = grid[i][m / 2] + grid[n - 1 - i][m / 2];
        ans += abs(p) < 2 - abs(p) ? abs(p) : 2 - abs(p);
      }
    }
    if (n % 2 == 1) {
      for (int j = 0; j < m / 2; ++j) {
        int p = grid[n / 2][j] + grid[n / 2][m - 1 - j];
        ans += abs(p) < 2 - abs(p) ? abs(p) : 2 - abs(p);
      }
    }
    return ans;
  }
};
