/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-29 13:00:19
 * filename    : 633-sum-of-square-numbers.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
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
  bool judgeSquareSum(int c) {
    if (c % 4 == 3)
      return false;

    for (ll i = 0ll; i * i <= c; i++) {
      int p = c - i * i;
      int s = (int)sqrt(p);
      if (s < i)
        break;
      if (s * s == p)
        return true;
    }
    return false;
  }
};
