/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-11-19 13:47:17
 * filename    : 1013-partition-array-into-three-parts-with-equal-sum.cpp
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
  bool canThreePartsEqualSum(vector<int> &arr) {
    ll s = 0ll;
    for (int val : arr)
      s += val;
    if (s % 3 != 0)
      return false;

    s /= 3;
    int i = 0;
    ll t = 0ll;
    int n = arr.size();
    for (i = 0; i < n; ++i) {
      t += arr[i];
      if (t == s)
        break;
    }
    i++;
    if (i >= n)
      return false;
    t = 0ll;
    for (; i < n; ++i) {
      t += arr[i];
      if (t == s)
        break;
    }
    i++;
    if (i >= n)
      return false;
    return true;
  }
};
