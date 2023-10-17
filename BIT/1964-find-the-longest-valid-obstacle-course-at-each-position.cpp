/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-17 22:22:30
 * filename    : find-the-longest-valid-obstacle-course-at-each-position
 * language    : cpp
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
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
  vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles) {
    int n = obstacles.size();
    vector<int> ans(n), st(n);
    int m = 0, r;
    for (int i = 0, c; i < n; ++i) {
      c = obstacles[i];
      r = find(st, m, c);
      if (m == r) {
        st[m++] = c;
      } else {
        st[r] = c;
      }
      ans[i] = r + 1;
    }
    return ans;
  }
  int find(vector<int> &st, int m, int val) {
    int ret = -1;
    int l = 0, r = m - 1, mid;
    while (l <= r) {
      mid = (l + r) >> 1;
      if (st[mid] <= val) {
        ret = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return ret + 1;
  }
};
