/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-13 00:34:05
 * filename    : 215-kth-largest-element-in-an-array.cpp
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
#define eb emplace_back
#define fi first
#define snd second
#define sz size

#define ll long long
#define nMax 200005

#define MOD 998244353
using namespace std;

class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    vector<int> h;

    for (int val : nums) {
      if (h.sz() < k) {
        h.eb(-val);
        push_heap(vall(h));
      } else if (-h[0] < val) {
        pop_heap(vall(h));
        h.pop_back();
        h.eb(-val);
        push_heap(vall(h));
      }
    }

    return -h[0];
  }
};
