/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-18 23:44:33
 * filename    : 2485-find-the-pivot-integer.cpp
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
  int pivotInteger(int n) {
    int s = n * (n + 1) / 2;
    for (int i = 1; i <= n; ++i) {
      if (i * (i + 1) == s + i)
        return i;
    }
    return -1;
  }
};
