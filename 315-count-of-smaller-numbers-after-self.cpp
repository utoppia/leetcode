/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-17 20:12:31
 * filename    : 315-count-of-smaller-numbers-after-self.cpp
 * language    : cpp
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <map>
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

struct BIT {
  vector<int> c;
  int size;
  BIT(int _size) : size(_size), c(_size + 1) {}
  inline int lowbit(int x) { return x & -x; }
  void add(int index, int val) {
    while (index <= size) {
      c[index] += val;
      index += lowbit(index);
    }
  }
  int getSum(int index) {
    int ret = 0;
    while (index > 0) {
      ret += c[index];
      index -= lowbit(index);
    }
    return ret;
  }

  void make_tree(vector<int> nums) {
    size = nums.size();
    c.resize(size + 1, 0);
    for (int i = 1; i <= size; ++i) {
      add(i, nums[i - 1]);
    }
  }
};

class Solution {
public:
  vector<int> countSmaller(vector<int> &nums) {
    int n = nums.size();
    set<int> S;
    for (auto c : nums)
      S.insert(c);
    map<int, int> dik;
    int cnt = 0;
    for (auto it = S.begin(); it != S.end(); ++it) {
      dik[*it] = ++cnt;
    }

    vector<int> ans(n);
    BIT b(n);
    for (int i = n - 1; i >= 0; --i) {
      ans[i] = b.getSum(dik[nums[i]] - 1);
      b.add(dik[nums[i]], 1);
    }
    return ans;
  }
};
