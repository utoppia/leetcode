/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 20:12:46
 * filename    : 230-kth-samllest-element-in-a-bst.cpp
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
  int kthSmallest(TreeNode *root, int k) {
    // in-ordered traversal
    stack<TreeNode *> h;
    while (root != nullptr || h.size()) {
      while (root != nullptr) {
        h.push(root);
        root = root->left;
      }

      root = h.top();
      h.pop();
      k -= 1;
      if (k == 0)
        return root->val;
      root = root->right;
    }
    return -1;
  }
};
