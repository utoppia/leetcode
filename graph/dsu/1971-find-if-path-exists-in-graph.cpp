/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-14 03:21:55
 * filename    : 1971-find-if-path-exists-in-graph.cpp
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

// 并查集
struct dsu {
  vector<size_t> fa, size;
  explicit dsu(size_t size_) : fa(size_), size(size_, 1) {
    iota(fa.begin(), fa.end(), 0);
  }

  size_t find(size_t x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

  void unite(size_t x, size_t y) {
    x = find(x);
    y = find(y);
    if (x == y)
      return;
    if (size[x] < size[y])
      swap(x, y);
    fa[y] = x;
    size[x] += size[y];
  }
};

class Solution {
public:
  bool validPath(int n, vector<vector<int>> &edges, int source,
                 int destination) {
    dsu d(n);
    for (auto e : edges) {
      d.unite(e[0], e[1]);
    }

    return d.find(source) == d.find(destination);
  }
};
