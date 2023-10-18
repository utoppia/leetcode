/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-18 23:57:56
 * filename    : 2544-alternating-digit-sum.cpp
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
  int alternateDigitSum(int n) {
    int ans = 0;
    int i = 0;
    while (n) {
      if (i & 1)
        ans += (n % 10);
      else
        ans -= (n % 10);
      n /= 10;
      i++;
    }
    if (i & 1)
      ans = -ans;
    return ans;
  }
};
