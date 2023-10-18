/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-18 23:16:18
 * filename    : 2169-count-operations-to-obtain-zero.cpp
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
  int countOperations(int num1, int num2) {
    int n = 0;
    while (num1 && num2) {
      if (num1 >= num2)
        num1 -= num2;
      else
        num2 -= num1;
      n++;
    }
    return n;
  }
};
