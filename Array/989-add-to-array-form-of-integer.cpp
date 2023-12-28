/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-11-19 13:57:41
 * filename    : 989-add-to-array-form-of-integer.cpp
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
  vector<int> addToArrayForm(vector<int> &num, int k) {
    reverse(vall(num));
    vector<int> ret;
    int d = 0;
    for (int i = 0; i < num.size(); ++i) {
      d += num[i] + k % 10;
      ret.pb(d % 10);
      d /= 10;
      k /= 10;
    }

    while (k) {
      d += k % 10;
      ret.pb(d % 10);
      d /= 10;
      k /= 10;
    }

    while (d) {
      ret.pb(d % 10);
      d /= 10;
    }

    reverse(vall(ret));
    return ret;
  }
};
