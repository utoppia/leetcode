/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 19:43:28
 * filename    : 101-symmetric-tree.cpp
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
private:
  bool check(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr)
      return true;
    if (p == nullptr || q == nullptr)
      return false;

    return p->val == q->val && check(p->left, q->right) &&
           check(p->right, q->left);
  }

public:
  bool isSymmetric(TreeNode *root) { return check(root, root); }
};
