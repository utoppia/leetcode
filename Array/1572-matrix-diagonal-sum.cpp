/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 14:46:16
 * filename    : 1572-matrix-diagonal-sum.cpp
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
  int diagonalSum(vector<vector<int>> &mat) {
    int n = mat.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += mat[i][i] + mat[i][n - 1 - i];
    }
    if (n % 2 == 1)
      ans -= mat[n / 2][n / 2];
    return ans;
  }
};
