/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-12-28 20:48:14
 * filename    : 2923-find-champion-i.cpp
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
  int findChampion(vector<vector<int>> &grid) {
    int n = grid.size();

    for (int i = 0; i < n; ++i) {
      int cnt = 0;
      for (int val : grid[i]) {
        cnt += val;
      }
      if (cnt == n - 1)
        return i;
    }

    return -1;
  }
};
