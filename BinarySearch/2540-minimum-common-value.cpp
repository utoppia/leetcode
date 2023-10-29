/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-30 01:19:43
 * filename    : 2540-minimum-common-value.cpp
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
  bool find_val(vector<int> &a, int val) {
    int l = 0, r = a.size() - 1;
    while (l <= r) {
      int m = (l + r) >> 1;
      if (a[m] == val)
        return true;
      if (a[m] < val) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    return false;
  }

public:
  int getCommon(vector<int> &nums1, vector<int> &nums2) {
    for (int c : nums1) {
      if (find_val(nums2, c))
        return c;
    }
    return -1;
  }
};
