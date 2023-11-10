/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-11-09 17:53:16
 * filename    : 2511-maximum-enemy-forts-that-can-be-captured.cpp
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
  int captureForts(vector<int> &forts) {
    int i, j;
    int ans = 0;
    for (int i = 0; i < forts.size();)
      if (forts[i]) {
        int j = i + 1;
        while (j < forts.size() && forts[j] == 0)
          j++;
        if (j < forts.size() && forts[i] + forts[j] == 0) {
          ans = max(ans, j - i - 1);
        }
        i = j;
      } else
        i++;
    return ans;
  }
};
