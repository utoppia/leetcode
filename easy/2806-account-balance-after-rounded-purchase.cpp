/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-12-28 23:11:44
 * filename    : 2806-account-balance-after-rounded-purchase.cpp
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
  int accountBalanceAfterPurchase(int purchaseAmount) {
    int k = purchaseAmount % 10;
    if (k < 5)
      return 100 - purchaseAmount + k;
    else
      return 100 - purchaseAmount - 10 + k;
  }
};
