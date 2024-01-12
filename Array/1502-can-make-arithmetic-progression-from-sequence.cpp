/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 14:25:18
 * filename    : 1502-can-make-arithmetic-progression-from-sequence.cpp
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
  bool canMakeArithmeticProgression(vector<int> &arr) {

    sort(vall(arr));

    int n = arr.size();
    if (n <= 1)
      return true;
    int d = arr[1] - arr[0];
    for (int i = 2; i < n; ++i)
      if (arr[i] - arr[i - 1] != d)
        return false;
    return true;
  }
};
