/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-18 23:46:42
 * filename    : 2520-count-the-digits-that-divide-a-number.cpp
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
  int countDigits(int num) {
    int ans = 0;
    for (int n = num; n; n /= 10) {
      if (num % (n % 10) == 0)
        ans++;
    }
    return ans;
  }
};
