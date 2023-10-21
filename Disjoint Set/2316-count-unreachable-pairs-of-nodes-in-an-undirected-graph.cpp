/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-21 07:52:49
 * filename    :
 *2316-count-unreachable-pairs-of-nodes-in-an-undirected-graph.cpp language    :
 *cpp editor      : Emacs 27.1
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
  long long countPairs(int n, vector<vector<int>> &edges) {
    dsu d(n);
    for (vector<int> e : edges) {
      d.unite(e[0], e[1]);
    }
    set<int> s;
    ll ans = (ll)n * (n + 1) / 2;
    for (int x = 0, y; x < n; ++x) {
      y = d.find(x);
      if (s.count(y) == 0) {
        ans -= (ll)d.size[y] * (d.size[y] + 1) / 2;
        s.insert(y);
      }
    }
    return ans;
  }
};
