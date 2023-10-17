/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-18 01:14:49
 * filename    : 1175-prime-arrangements.cpp
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
  int numPrimeArrangements(int n) {
    vector<bool> vis(n + 1);
    for (int i = 2; i <= n; ++i)
      if (!vis[i]) {
        for (int j = i * i; j <= n; j += i)
          vis[j] = true;
      }
    int p = 0;
    for (int i = 2; i <= n; ++i)
      if (!vis[i])
        ++p;
    ll ans = 1ll;
    const int mod = 1000000007;
    n -= p;
    while (p) {
      ans = ans * p % mod;
      p--;
    }
    while (n) {
      ans = ans * n % mod;
      n--;
    }
    return (int)ans;
  }
};
