/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
/**
 * To test my code locally (not to get compile-time error), I add the ListNode struct here
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) {
    if (!head || !head->next) return head;
    struct ListNode *temp, *newhead, *mid;
    temp = head, mid = head->next, newhead = head->next->next;
    mid->next = temp;
    temp->next = swapPairs(newhead);
    return mid;
}
