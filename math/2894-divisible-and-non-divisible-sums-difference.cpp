/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-21 20:00:33
 * filename    : 2894-divisible-and-non-divisible-sums-difference.cpp
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
  int differenceOfSums(int n, int m) {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      if (i % m == 0)
        ans -= i;
      else
        ans += i;
    }
    return ans;
  }
};
