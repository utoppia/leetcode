/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-13 18:17:43
 * filename    : 207-course-schedule.cpp
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
#define nMax 2005

#define MOD 998244353
using namespace std;

using Graph = vector<vector<int>>; // 邻接表

struct TopoSort {
  enum class Status : uint8_t { to_visit, visiting, visited };

  const Graph &graph;
  const int n;
  vector<Status> status;
  vector<int> order;
  vector<int>::reverse_iterator it;

  TopoSort(const Graph &graph)
      : graph(graph), n(graph.size()), status(n, Status::to_visit), order(n),
        it(order.rbegin()) {}

  bool sort() {
    for (int i = 0; i < n; ++i) {
      if (status[i] == Status::to_visit && !dfs(i))
        return false;
    }
    return true;
  }

  bool dfs(const int u) {
    status[u] = Status::visiting;
    for (const int v : graph[u]) {
      if (status[v] == Status::visiting)
        return false;
      if (status[v] == Status::to_visit && !dfs(v))
        return false;
    }
    status[u] = Status::visited;
    *it++ = u;
    return true;
  }
};

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    Graph dis(nMax);
    for (auto e : prerequisites)
      dis[e[0]].pb(e[1]);

    TopoSort topo(dis);

    return topo.sort();
  }
};
