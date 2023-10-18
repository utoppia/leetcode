/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-18 12:39:14
 * filename    : 1486-xor-operation-in-an-array.cpp
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
  int xorOperation(int n, int start) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = ans ^ (start + 2 * i);
    }
    return ans;
  }
};
