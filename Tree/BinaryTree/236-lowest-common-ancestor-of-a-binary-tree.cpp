/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-13 12:39:46
 * filename    : 236-lowest-common-ancestor-of-a-binary-tree.cpp
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
  void dfs(TreeNode *root, vector<int> &dep, vector<TreeNode *> &fa,
           unordered_map<TreeNode *, int> &hs, int &cnt, int cur) {
    if (root == nullptr)
      return;
    hs[root] = cnt++;
    dep[hs[root]] = cur;
    if (root->left != nullptr) {
      dfs(root->left, dep, fa, hs, cnt, cur + 1);
      fa[hs[root->left]] = root;
    }
    if (root->right != nullptr) {
      dfs(root->right, dep, fa, hs, cnt, cur + 1);
      fa[hs[root->right]] = root;
    }
    return;
  }

public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    unordered_map<TreeNode *, int> hs;
    vector<int> dep(nMax, 0);
    vector<TreeNode *> fa(nMax, nullptr);
    int n = 0;

    dfs(root, dep, fa, hs, n, 0);

    while (p != q) {
      if (dep[hs[p]] > dep[hs[q]]) {
        p = fa[hs[p]];
      } else if (dep[hs[p]] < dep[hs[q]]) {
        q = fa[hs[q]];
      } else {
        p = fa[hs[p]];
        q = fa[hs[q]];
      }
    }

    return p;
  }
};
