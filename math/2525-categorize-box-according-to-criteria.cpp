/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-18 23:48:46
 * filename    : 2525-categorize-box-according-to-criteria.cpp
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
  string categorizeBox(int length, int width, int height, int mass) {
    bool bulky = (length >= 1e4 || width >= 1e4 || height >= 1e4 ||
                  (ll)length * width * height >= 1e9);
    bool heavy = mass >= 100;
    if (bulky && heavy)
      return "Both";
    if (bulky)
      return "Bulky";
    if (heavy)
      return "Heavy";
    return "Neither";
  }
};
