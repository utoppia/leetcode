/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-28 10:48:42
 * filename    : 1870-minimum-speed-to-arrive-on-time.cpp
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
  int minSpeedOnTime(vector<int> &dist, double hour) {
    int l = 1, r = *max_element(vall(dist));
    r *= 100;
    int ans = -1;
    int m;
    int n = dist.size();
    int v;
    while (l <= r) {
      m = (l + r) / 2;
      v = 0;
      for (int i = 0; i < n - 1; ++i) {
        v += dist[i] / m + (dist[i] % m == 0 ? 0 : 1);
      }

      if (v + (double)dist[n - 1] / m > hour)
        l = m + 1;
      else {
        ans = m;
        r = m - 1;
      }
    }
    return ans;
  }
};
