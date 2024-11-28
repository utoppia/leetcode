/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-13 13:53:17
 * filename    : 48-rotate-image.cpp
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
  void rotate(vector<vector<int>> &matrix) {
    // (i, j) -> (j, n-i-1) -> (n-i-1,n-j-1) -> (n-j-1,i)
    int n = matrix.size();

    for (int i = 0; i < n / 2; ++i) {
      for (int j = i; j < n - 1 - i; ++j) {
        int tmp = matrix[n - j - 1][i];
        matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
        matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
        matrix[j][n - i - 1] = matrix[i][j];
        matrix[i][j] = tmp;
      }
    }

    return;
  }
};
