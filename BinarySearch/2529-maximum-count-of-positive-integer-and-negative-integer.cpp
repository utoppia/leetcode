/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-30 01:15:32
 * filename    : 2529-maximum-count-of-positive-integer-and-negative-integer.cpp
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
  int maximumCount(vector<int> &nums) {
    int neg = -1;
    int l = 0, r = nums.size() - 1;

    while (l <= r) {
      int m = (l + r) >> 1;
      if (nums[m] < 0) {
        neg = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    neg++;

    l = 0, r = nums.size() - 1;
    int pos = r + 1;
    while (l <= r) {
      int m = (l + r) >> 1;
      if (nums[m] > 0) {
        pos = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    pos = nums.size() - pos;

    return max(neg, pos);
  }
};
