/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-29 14:49:55
 * filename    : 240-search-a-2d-matrix-ii.cpp
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
  bool check(int il, int ir, int jl, int jr, vector<vector<int>> &matrix,
             int target, int n, int m) {
    if (il > ir || jl > jr)
      return false;
    if (matrix[il][jl] == target)
      return true;
    int im = (il + ir) / 2, jm = (jl + jr) / 2;
    bool flag = false;

    if (matrix[il][jl] <= target && matrix[im][jm] >= target)
      flag |= check(il, im, jl, jm, matrix, target, n, m);

    if (im + 1 < n && matrix[im + 1][jl] <= target && matrix[ir][jm] >= target)
      flag |= check(im + 1, ir, jl, jm, matrix, target, n, m);

    if (jm + 1 < m && matrix[il][jm + 1] <= target && matrix[im][jr] >= target)
      flag |= check(il, im, jm + 1, jr, matrix, target, n, m);

    if (im + 1 < n && jm + 1 < m && matrix[im + 1][jm + 1] <= target &&
        matrix[ir][jr] >= target)
      flag |= check(im + 1, ir, jm + 1, jr, matrix, target, n, m);

    return flag;
  }
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    return check(0, n - 1, 0, m - 1, matrix, target, n, m);
  }
};
