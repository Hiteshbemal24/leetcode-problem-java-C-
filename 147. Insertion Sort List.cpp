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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)
            return head;  
        
        ListNode* sorted = nullptr;  
        ListNode* curr = head;      
        
        while (curr) {
            ListNode* next = curr->next;  
            
            if (!sorted || sorted->val > curr->val) {
                curr->next = sorted; 
                sorted = curr;       
            } else {
                ListNode* search = sorted;
                while (search->next && search->next->val < curr->val) {
                    search = search->next; 
                }
                curr->next = search->next;  
                search->next = curr;
            }
            
            curr = next;  
        }
        
        return sorted;
    }
};
