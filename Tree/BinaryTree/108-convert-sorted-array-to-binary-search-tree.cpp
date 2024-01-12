/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 20:01:49
 * filename    : 108-convert-sorted-array-to-binary-search-tree.cpp
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
  TreeNode *divideArray(vector<int> &nums, int l, int r) {
    if (l > r)
      return nullptr;
    int mid = (l + r) >> 1;

    TreeNode *node = new TreeNode(nums[mid]);
    TreeNode *left = divideArray(nums, l, mid - 1);
    TreeNode *right = divideArray(nums, mid + 1, r);
    node->left = left;
    node->right = right;
    return node;
  }

public:
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    return divideArray(nums, 0, nums.sz() - 1);
  }
};
