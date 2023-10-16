/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-17 00:57:48
 * filename    : prime-number-of-set-bits-in-binary-representation.cpp
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
  int countPrimeSetBits(int left, int right) {
    // 2 ^ 20 > 10 ^ 6
    vector<bool> is_prime(21);
    is_prime.assign(21, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p < 21; ++p)
      if (is_prime[p]) {
        for (int i = p * p; i < 21; i += p)
          is_prime[i] = false;
      }

    int ans = 0;
    for (int x = left, cnt, y; x <= right; ++x) {
      cnt = 0;
      y = x;
      while (y) {
        cnt += (y & 1);
        y >>= 1;
      }
      ans += is_prime[cnt];
    }
    return ans;
  }
};
