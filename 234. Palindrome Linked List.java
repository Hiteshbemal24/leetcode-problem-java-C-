/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
         if(head.next == null) return true;
    int n = 0;
    ListNode H2 = head, temp = head;
    while(temp != null){
        if(temp.next == null){
            H2 = H2.next; break;
        }
        H2 = H2.next; temp = temp.next.next;
    }
    if(H2 != null){
        ListNode newH = null, newNode = null;
        while(H2 != null){
            newNode = H2;
            H2 = H2.next;
            newNode.next = newH;
            newH = newNode;
        }
        H2 = newH;
    }
    while(H2 != null){
        if(H2.val != head.val) return false;
        H2 = H2.next; head = head.next;
    }
    return true;
    }
}
