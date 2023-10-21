/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-22 01:54:17
 * filename    : 2600-k-items-with-the-maximum-sum.cpp
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
  int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
    int ans = 0;
    ans += min(numOnes, k);
    k -= numOnes;
    if (k <= 0)
      return ans;
    k -= numZeros;
    if (k <= 0)
      return ans;
    ans -= min(numNegOnes, k);
    return ans;
  }
};
