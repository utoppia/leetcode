/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 23:36:27
 * filename    : 74-search-a-2d-matrix.cpp
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
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int n = matrix.sz(), m = matrix[0].sz();
    int l = 0, r = n * m - 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      int x = mid / m, y = mid % m;
      if (matrix[x][y] == target)
        return true;
      if (matrix[x][y] < target)
        l = mid + 1;
      else
        r = mid - 1;
    }
    return false;
  }
};
