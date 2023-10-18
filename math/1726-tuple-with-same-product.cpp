/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-19 00:07:15
 * filename    : 1726-tuple-with-same-product.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

#define all(v) v.begin(), v.end()
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
  int tupleSameProduct(vector<int> &nums) {
    map<int, int> d;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        d[nums[i] * nums[j]]++;
      }
    }
    int ans = 0;
    for (pir c : d) {
      ans += 4 * c.snd * (c.snd - 1);
    }
    return ans;
  }
};
