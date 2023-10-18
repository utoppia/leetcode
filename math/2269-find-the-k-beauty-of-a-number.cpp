/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-18 23:26:34
 * filename    : 2269-find-the-k-beauty-of-a-number.cpp
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
  int divisorSubstrings(int num, int k) {
    int n = num;
    int t = 1, base = 1;
    int val = n % 10;
    n /= 10;
    while (t < k) {
      base *= 10;
      val += (n % 10) * base;
      t++;
      n /= 10;
    }
    int ans = 0;
    if (val && num % val == 0)
      ans++;
    while (n) {
      val /= 10;
      val += (n % 10) * base;
      n /= 10;
      if (val != 0 && num % val == 0)
        ans++;
    }
    return ans;
  }
};
