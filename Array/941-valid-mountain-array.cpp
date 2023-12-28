/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-11-15 00:52:49
 * filename    : 941-valid-mountain-array.cpp
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
  bool validMountainArray(vector<int> &arr) {
    int n = arr.size();
    if (n < 3)
      return false;

    if (arr[0] > arr[1])
      return false;
    int i = 1;
    while (i < n && arr[i] > arr[i - 1])
      i++;
    if (i == n)
      return false;
    while (i < n && arr[i] < arr[i - 1])
      i++;
    if (i == n)
      return true;
    return false;
  }
};
