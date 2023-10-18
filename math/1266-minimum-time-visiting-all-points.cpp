/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-18 12:33:08
 * filename    : 1266-minimum-time-visiting-all-points.cpp
 * language    : cpp
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdlib>
#include <ios>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

#define all(v) v.begin(), v.end()
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
  int minTimeToVisitAllPoints(vector<vector<int>> &points) {
    int ans = 0;
    int n = points.size();
    int x, y;
    for (int i = 1; i < n; ++i) {
      x = abs(points[i][0] - points[i - 1][0]);
      y = abs(points[i][1] - points[i - 1][1]);
      ans += min(x, y) + abs(x - y);
    }
    return ans;
  }
};
