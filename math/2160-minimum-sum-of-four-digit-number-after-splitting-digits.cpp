/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-18 23:12:44
 * filename    : minimum-sum-of-four-digit-number-after-splitting-digits
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
  int minimumSum(int num) {
    vector<int> c;
    for (int i = 0; i < 4; ++i)
      c.pb(num % 10), num /= 10;
    sort(all(c));
    return 10 * (c[0] + c[1]) + c[2] + c[3];
  }
};
