/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-11-09 18:21:20
 * filename    : 2441-largest-positive-integer-that-exists-with-its-negative.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
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
  int findMaxK(vector<int> &nums) {
    vector<int> vis(1001);
    int ans = -1;

    for (int val : nums) {
      if (val > 0) {
        if (vis[val] == -1)
          ans = max(ans, val);
        vis[val] = 1;
      }
      if (val < 0) {
        if (vis[-val] == 1)
          ans = max(ans, -val);
        vis[-val] = -1;
      }
    }
    return ans;
  }
};
