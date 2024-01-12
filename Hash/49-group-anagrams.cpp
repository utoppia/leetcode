/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 15:29:29
 * filename    : 49-group-anagrams.cpp
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
#define eb emplace_back
#define fi first
#define snd second

#define ll long long
#define nMax 200005

#define MOD 998244353
using namespace std;

class Solution {
private:
  string anagram_string(string s) {
    sort(vall(s));
    return s;
  }

public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> hash;

    for (string s : strs) {
      hash[anagram_string(s)].eb(s);
    }
    vector<vector<string>> ans;
    for (auto it = hash.begin(); it != hash.end(); it++)
      ans.eb(it->second);
    return ans;
  }
};
