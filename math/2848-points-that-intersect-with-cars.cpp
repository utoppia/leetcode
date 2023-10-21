/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-21 20:06:29
 * filename    : 2848-points-that-intersect-with-cars.cpp
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
  int numberOfPoints(vector<vector<int>> &nums) {
    vector<int> vis(110);
    for (vector<int> c : nums) {
      for (int i = c[0]; i <= c[1]; ++i)
        vis[i] = 1;
    }
    int ans = 0;
    for (int i = 0; i < 110; ++i)
      if (vis[i])
        ans++;
    return ans;
  }
};
