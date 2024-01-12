/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 15:04:32
 * filename    : 2085-count-common-words-with-one-occurrence.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
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
  int countWords(vector<string> &words1, vector<string> &words2) {
    unordered_map<string, int> w1, w2;
    for (string w : words1)
      w1[w]++;
    for (string w : words2)
      w2[w]++;
    int ans = 0;
    for (auto it = w1.begin(); it != w1.end(); it++)
      if (it->second == 1 && w2[it->first] == 1)
        ans++;
    return ans;
  }
};
