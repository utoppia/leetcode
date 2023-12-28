/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-11-15 00:47:31
 * filename    : 933-number-of-recent-calls.cpp
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

class RecentCounter {
private:
  int cnt;
  vector<int> ts;

  int binary_find(int val) {
    int l = 0, r = cnt - 1;
    int ans = r;
    while (l <= r) {
      int m = (l + r) >> 1;
      if (ts[m] >= val) {
        ans = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return ans;
  }

public:
  RecentCounter() {
    cnt = 0;
    ts.clear();
  }

  int ping(int t) {
    cnt++;
    ts.pb(t);
    int j = binary_find(t - 3000);

    return cnt - j;
  }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
