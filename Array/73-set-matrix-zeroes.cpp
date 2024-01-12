/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 18:20:34
 * filename    : 73-set-matrix-zeroes.cpp
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
  void setZeroes(vector<vector<int>> &matrix) {
    int n = matrix.sz(), m = matrix[0].sz();
    bool v_flag = false, h_flag = false;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;

          if (i == 0)
            h_flag = true;
          if (j == 0)
            v_flag = true;
        }
      }
    }

    for (int i = 1; i < n; ++i)
      if (matrix[i][0] == 0) {
        for (int j = 0; j < m; ++j)
          matrix[i][j] = 0;
      }

    for (int j = 1; j < m; ++j)
      if (matrix[0][j] == 0) {
        for (int i = 0; i < n; ++i)
          matrix[i][j] = 0;
      }

    if (h_flag)
      for (int j = 0; j < m; ++j)
        matrix[0][j] = 0;
    if (v_flag)
      for (int i = 0; i < n; ++i)
        matrix[i][0] = 0;
  }
};
