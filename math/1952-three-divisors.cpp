/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-18 13:17:38
 * filename    : 1952-three-divisors.cpp
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
  bool isThree(int n) {
    // n must be p * p, where p is
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
      if (n % i == 0)
        cnt++;
    return cnt == 3;
  }
};
