/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-10 00:52:21
 * filename    : 1855-maximum-distance-between-a-pair-of-values.cpp
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
  int maxDistance(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size(), m = nums2.size();

    int ans = 0;
    int i = 0, j;
    for (int j = 0; j < m; ++j) {
      while (i < n && nums1[i] > nums2[j]) {
        i++;
      }
      if (i == n)
        break;
      ans = max(ans, j - i);
    }
    return ans;
  }
};
