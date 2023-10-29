/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-28 10:27:55
 * filename    : 1394-find-lucky-integer-in-an-array.cpp
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
  int findLucky(vector<int> &arr) {
    vector<int> cnt(501);
    for (int c : arr)
      cnt[c]++;
    for (int i = 500; i > 0; --i)
      if (cnt[i] == i)
        return i;
    return -1;
  }
};
