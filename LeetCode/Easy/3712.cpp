// https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/?envType=daily-question&envId=2025-11-01

#include <bits/stdc++.h>
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

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Using Unordered set as it has better space complexity
        unordered_set<int> s(nums.begin(), nums.end());
        while(head && s.count(head->val)) 
            head = head->next;
        ListNode* ans = head;
        while(head && head->next) {
            if(s.count(head->next->val))
                head->next = head->next->next;
            else 
                head = head->next;
        }
        return ans;
    }
};
