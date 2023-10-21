/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-21 19:47:04
 * filename    : 260-single-number-iii.cpp
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
  vector<int> singleNumber(vector<int> &nums) {
    int ans = 0;
    for (int val : nums)
      ans ^= val;
    int pos = 0;
    while (((1 << pos) & ans) == 0)
      pos++;
    int a = 0, b = 0;
    for (int val : nums) {
      if ((1 << pos) & val)
        a ^= val;
      else
        b ^= val;
    }
    vector<int> ret(2);
    ret[0] = a, ret[1] = b;
    return ret;
  }
};
