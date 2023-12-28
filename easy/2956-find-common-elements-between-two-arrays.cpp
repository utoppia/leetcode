/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-12-28 20:56:07
 * filename    : 2956-find-common-elements-between-two-arrays.cpp
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
  vector<int> findIntersectionValues(vector<int> &nums1, vector<int> &nums2) {
    vector<int> cnt(101);
    for (int val : nums2)
      cnt[val] = 1;

    vector<int> ret(2);

    for (int val : nums1)
      if (cnt[val] == 1)
        ret[0]++;

    cnt.assign(101, 0);
    for (int val : nums1)
      cnt[val] = 1;
    for (int val : nums2)
      if (cnt[val] == 1)
        ret[1]++;

    return ret;
  }
};
