/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-22 01:39:21
 * filename    : 2582-pass-the-pillow.cpp
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
  int passThePillow(int n, int time) {
    ++time;
    time %= (2 * n - 2);
    if (time == 0)
      time = 2 * n - 2;
    if (time <= n)
      return time;
    return 2 * n - time;
  }
};
