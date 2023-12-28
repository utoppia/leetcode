/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-12-29 00:52:26
 * filename    : 2553-separate-the-digits-in-an-array.cpp
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
  vector<int> separateDigit(int val) {
    vector<int> ret;
    while (val) {
      ret.pb(val % 10);
      val /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }

public:
  vector<int> separateDigits(vector<int> &nums) {
    vector<int> ans;
    for (int val : nums) {
      vector<int> tmp = separateDigit(val);
      for (int v : tmp) {
        ans.pb(v);
      }
    }
    return ans;
  }
};
