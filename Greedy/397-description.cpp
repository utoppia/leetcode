/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-07 20:03:05
 * filename    : 397-description.cpp
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
  int integerReplacement(int m) {
    int ans = 0;
    ll n = (ll)m;
    while (n != 1) {
      if (n % 2 == 0) {
        ans++;
        n >>= 1;
      } else {
        if ((n & 3) == 3 && n != 3)
          n++;
        else
          n--;
        ans++;
      }
    }
    return ans;
  }
};
