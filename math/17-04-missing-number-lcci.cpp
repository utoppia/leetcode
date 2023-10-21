/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-21 19:50:58
 * filename    : 17-04-missing-number-lcci.cpp
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
  int missingNumber(vector<int> &nums) {
    int n = nums.size();
    ll s = (ll)n * (n + 1) / 2;
    for (int val : nums)
      s -= val;
    return (int)s;
  }
};
