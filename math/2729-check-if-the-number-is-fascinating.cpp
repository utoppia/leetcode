/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-22 02:13:14
 * filename    : 2729-check-if-the-number-is-fascinating.cpp
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
  bool isFascinating(int n) {
    int cnt[10];
    for (int i = 1; i < 10; ++i)
      cnt[i] = 0;
    auto f = [&cnt](int x) {
      while (x) {
        cnt[x % 10]++;
        x /= 10;
      }
    };
    f(n);
    f(2 * n);
    f(3 * n);
    for (int i = 1; i < 10; ++i)
      if (cnt[i] != 1)
        return false;
    return true;
  }
};
