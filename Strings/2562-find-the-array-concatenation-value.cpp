/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-11-09 18:05:40
 * filename    : 2562-find-the-array-concatenation-value.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <set>
#include <string>
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
  long long findTheArrayConcVal(vector<int> &nums) {
    ll ans = 0ll;
    int n = nums.size();
    int i = 0, j = n - 1;
    while (i <= j) {
      string ret = "";
      ret += to_string(nums[i]);
      if (j != i)
        ret += to_string(nums[j]);
      ll tmp = 0;
      for (char c : ret) {
        tmp = tmp * 10 + c - '0';
      }
      ans += tmp;
      i++;
      j--;
    }
    return ans;
  }
};
