/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-18 23:22:09
 * filename    : 2180-count-integers-with-even-digit-sum.cpp
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
private:
  bool sumIsEven(int n) {
    int cnt = 0;
    while (n)
      cnt += n % 10, n /= 10;
    return cnt % 2 == 0;
  }

public:
  int countEven(int num) {
    int ans = 0;
    for (int i = 1; i <= num; ++i)
      if (sumIsEven(i))
        ans++;
    return ans;
  }
};
