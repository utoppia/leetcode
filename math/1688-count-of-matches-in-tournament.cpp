/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-18 12:47:20
 * filename    : 1688-count-of-matches-in-tournament.cpp
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
  int numberOfMatches(int n) {
    int ans = 0;
    while (n > 1) {
      ans += n / 2;
      if (n & 1) {
        n = n / 2 + 1;
      } else {
        n = n / 2;
      }
    }
    return ans;
  }
};
