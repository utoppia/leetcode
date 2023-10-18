/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-18 12:57:14
 * filename    : 1742-maximum-number-of-balls-in-a-box.cpp
 * language    : cpp
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
  int countBalls(int lowLimit, int highLimit) {
    map<int, int> m;
    auto f = [](int x) {
      int ans = 0;
      while (x) {
        ans += x % 10;
        x /= 10;
      }
      return ans;
    };
    int ans = 0;
    for (int x = lowLimit, val; x <= highLimit; ++x) {
      val = f(x);
      m[val]++;
      ans = max(ans, m[val]);
    }
    return ans;
  }
};
