/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-18 12:36:30
 * filename    : 1290-convert-binary-number-in-a-linked-list-to-integer.cpp
 * language    : cpp
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

#define all(v) v.begin(), v.end()
#define pir pair<int, int>

#define pb push_back
#define fi first
#define snd second

#define ll long long
#define nMax 200005

#define MOD 998244353
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  int getDecimalValue(ListNode *head) {
    int ans = 0;
    while (head != nullptr) {
      ans = (ans << 1) + head->val;
      head = head->next;
    }
    return ans;
  }
};
