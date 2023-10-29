/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-29 20:13:51
 * filename    : 825-friends-of-appropriate-ages.cpp
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
private:
  int find_lower(vector<int> &a, int lower) {
    int l = 0, r = a.size() - 1;
    int ans = a.size();
    while (l <= r) {
      int m = (l + r) >> 1;
      if (a[m] > lower) {
        ans = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return ans;
  }
  int find_upper(vector<int> &a, int upper) {
    int l = 0, r = a.size() - 1;
    int ans = -1;
    while (l <= r) {
      int m = (l + r) >> 1;
      if (a[m] <= upper) {
        ans = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    return ans;
  }

public:
  int numFriendRequests(vector<int> &ages) {
    sort(vall(ages));
    int ans = 0;

    for (int i = 0, age; i < ages.size(); ++i) {
      age = ages[i];
      int lower = age / 2 + 7, upper = age;

      int l = find_lower(ages, lower);
      int r = find_upper(ages, upper);
      if (l <= r)
        ans += (r - l + 1);
      if (l <= i && i <= r)
        ans--;
    }
    return ans;
  }
};
