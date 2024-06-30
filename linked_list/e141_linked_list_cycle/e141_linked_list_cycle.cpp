#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/* 
<-Description->
    Given a string s, find the length of the longest substring without repeating characters.

<-Constraints->
    0 <= s.length <= 5 * 104
    s consists of English letters, digits, symbols and spaces.
*/

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != nullptr && fast -> next != nullptr){
            fast = (fast->next)->next;
            slow = slow->next;
            if(fast == slow) return true;
        }
        return false;
    }
};

int main(){
    Solution solution;

    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;

    cout << boolalpha << solution.hasCycle(head);
}