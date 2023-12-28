/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-12-28 23:25:52
 * filename    : 2843-count-symmetric-integers.cpp
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
private:
  bool check(int val) {
    vector<int> tmp;
    while (val) {
      tmp.pb(val % 10);
      val /= 10;
    }
    int n = tmp.size();
    if (n % 2 != 0)
      return false;
    int s = 0;
    for (int i = 0; i < n / 2; ++i)
      s += tmp[i];
    if (s * 2 == accumulate(vall(tmp), 0))
      return true;
    return false;
  }

public:
  int countSymmetricIntegers(int low, int high) {
    int ans = 0;
    for (int val = low; val <= high; val++)
      if (check(val))
        ans++;
    return ans;
  }
};
