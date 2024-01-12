/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 20:20:29
 * filename    : 114-flatten-binnary-tree-to-linked-list.cpp
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
  void flatten(TreeNode *root) {
    if (root == nullptr)
      return;

    TreeNode *pre = nullptr;
    while (root != nullptr) {
      pre = root->left;

      if (pre != nullptr) {
        while (pre->right != nullptr)
          pre = pre->right;

        pre->right = root->right;
        root->right = root->left;
        root->left = nullptr;
      }

      root = root->right;
    }
  }
};
