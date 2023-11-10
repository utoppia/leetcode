/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-11-09 17:57:05
 * filename    : 2570-merge-two-2d-arrays-by-summing-values.cpp
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
  vector<vector<int>> mergeArrays(vector<vector<int>> &nums1,
                                  vector<vector<int>> &nums2) {
    vector<vector<int>> ret;
    int i = 0, j = 0;
    int n = nums1.size(), m = nums2.size();

    while (i < n && j < m) {
      if (nums1[i][0] == nums2[j][0]) {
        vector<int> tmp(2);
        tmp[0] = nums1[i][0];
        tmp[1] = nums1[i][1] + nums2[j][1];
        ret.pb(tmp);
        i++;
        j++;
      } else if (nums1[i][0] < nums2[j][0]) {
        vector<int> tmp(2);
        tmp[0] = nums1[i][0];
        tmp[1] = nums1[i][1];
        ret.pb(tmp);
        i++;
      } else {
        vector<int> tmp(2);
        tmp[0] = nums2[j][0];
        tmp[1] = nums2[j][1];
        ret.pb(tmp);
        j++;
      }
    }

    while (i < n) {
      ret.pb(nums1[i]);
      i++;
    }
    while (j < m) {
      ret.pb(nums2[j]);
      j++;
    }
    return ret;
  }
};
