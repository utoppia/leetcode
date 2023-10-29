/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-28 12:28:17
 * filename    : 1031-maximum-sum-of-two-non-overlapping-subarrays.cpp
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
  int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen) {
    int n = nums.size();
    vector<int> pref1(n), pref2(n), suffMax1(n), suffMax2(n);

    for (int i = 0; i < firstLen; ++i)
      pref1[0] += nums[i];
    for (int i = 1; i + firstLen <= n; ++i) {
      pref1[i] = pref1[i - 1] - nums[i - 1] + nums[i + firstLen - 1];
    }
    suffMax1[n - 1] = pref1[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      suffMax1[i] = max(suffMax1[i + 1], pref1[i]);
    }

    for (int i = 0; i < secondLen; ++i)
      pref2[0] += nums[i];
    for (int i = 1; i + secondLen <= n; ++i) {
      pref2[i] = pref2[i - 1] - nums[i - 1] + nums[i + secondLen - 1];
    }
    suffMax2[n - 1] = pref2[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      suffMax2[i] = max(suffMax2[i + 1], pref2[i]);
    }

    int ans = 0;
    for (int i = 0; i + firstLen < n; ++i) {
      ans = max(ans, pref1[i] + suffMax2[i + firstLen]);
    }
    for (int i = 0; i + secondLen < n; ++i) {
      ans = max(ans, pref2[i] + suffMax1[i + secondLen]);
    }

    return ans;
  }
};
