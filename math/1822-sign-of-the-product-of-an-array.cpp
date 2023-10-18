/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-18 13:01:44
 * filename    : 1822-sign-of-the-product-of-an-array.cpp
 * language    : cpp
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <ios>
#include <iostream>
#include <queue>
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
private:
  static int signFunc(int x) {
    if (x < 0)
      return -1;
    if (x > 0)
      return 1;
    return 0;
  }

public:
  int arraySign(vector<int> &nums) {
    return transform_reduce(nums.begin(), nums.end(), 1, std::multiplies<>{},
                            signFunc);
  }
};
