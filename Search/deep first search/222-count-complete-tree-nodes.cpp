/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-29 14:38:27
 * filename    : 222-count-complete-tree-nodes.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <set>
#include <stack>
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  int countNodes(TreeNode *root) {
    int cnt = 0;
    if (root == nullptr)
      return 0;

    stack<TreeNode *> q;
    q.push(root);

    while (q.size()) {
      TreeNode *u = q.top();
      q.pop();
      cnt++;
      if (u->left != nullptr)
        q.push(u->left);
      if (u->right != nullptr)
        q.push(u->right);
    }
    return cnt;
  }
};
