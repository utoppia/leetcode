/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-18 23:34:52
 * filename    : 2427-number-of-common-factors.cpp
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
  int commonFactors(int a, int b) {
    int ans = 0;
    for (int i = min(a, b); i >= 1; --i) {
      if (a % i == 0 && b % i == 0)
        ans++;
    }
    return ans;
  }
};
