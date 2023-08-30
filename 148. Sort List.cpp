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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* middle = findMiddle(head);
        ListNode* secondHalf = middle->next;
        middle->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(secondHalf);

        return merge(left, right);
    }

private:
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(0);
        ListNode* current = &dummy;

        while (left && right) {
            if (left->val < right->val) {
                current->next = left;
                left = left->next;
            } else {
                current->next = right;
                right = right->next;
            }
            current = current->next;
        }

        if (left)
            current->next = left;
        else if (right)
            current->next = right;

        return dummy.next;
    }
};
