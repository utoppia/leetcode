/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-17 00:51:54
 * filename    : self-dividing-numbers.cpp
 * language    : cpp
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
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
  vector<int> selfDividingNumbers(int left, int right) {
    auto check = [](int n) {
      if (n == 0)
        return false;
      int m = n;
      while (m > 0 && m % 10 != 0 && n % (m % 10) == 0)
        m /= 10;
      return m == 0;
    };

    vector<int> ans;
    for (int i = left; i <= right; ++i) {
      if (check(i))
        ans.pb(i);
    }
    return ans;
  }
};
