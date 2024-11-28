/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-13 19:39:33
 * filename    : 133-clone-graph.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <set>
#include <unordered_map>
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

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
  Node *cloneGraph(Node *node) {
    if (node == nullptr)
      return nullptr;
    vector<Node *> arr;
    int n = 1;
    unordered_map<Node *, int> hs;
    hs[node] = 0;
    Node *pt;
    pt = new Node(node->val);
    arr.pb(pt);

    queue<Node *> q;
    q.push(node);

    while (!q.empty()) {
      Node *u = q.front();
      q.pop();

      for (Node *v : u->neighbors) {
        if (hs.count(v) == 0) {
          hs[v] = n++;
          pt = new Node(v->val);
          arr.pb(pt);
          q.push(v);
        }
        arr[hs[u]]->neighbors.pb(arr[hs[v]]);
        // arr[hs[v]]->neighbors.pb(arr[hs[u]]);
      }
    }

    return arr[0];
  }
};
