/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-28 11:04:01
 * filename    : 2187-minimum-time-to-complete-trips.cpp
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
  long long minimumTime(vector<int> &time, int totalTrips) {
    ll l = 1ll, r = (ll)(*min_element(vall(time))) * totalTrips;
    ll m;
    ll ans = r;
    while (l <= r) {
      m = (l + r) / 2ll;
      ll c = 0ll;
      for (int t : time) {
        c += m / t;
      }
      if (c >= totalTrips) {
        r = m - 1;
        ans = m;
      } else {
        l = m + 1;
      }
    }
    return ans;
  }
};
