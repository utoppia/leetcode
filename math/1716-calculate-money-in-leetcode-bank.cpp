/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-18 12:50:48
 * filename    : 1716-calculate-money-in-leetcode-bank.cpp
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
  int totalMoney(int n) {
    int m = n / 7;
    int ans = m * (1 + 7) * 7 / 2;
    ans += 7 * (m - 1) * m / 2;
    n %= 7;
    while (n) {
      m++;
      ans += m;
      --n;
    }
    return ans;
  }
};
