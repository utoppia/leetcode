/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-21 08:05:07
 * filename    : 136-single-number.cpp
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
  int singleNumber(vector<int> &nums) {
    int ans = 0;
    for (int val : nums)
      ans ^= val;
    return ans;
  }
};
