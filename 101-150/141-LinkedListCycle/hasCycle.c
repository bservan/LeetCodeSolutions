#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    if (!head || !head->next) return false;
    struct ListNode* slow = head->next;
    struct ListNode* fast = head->next;
    if (fast && fast->next) fast = fast->next;
    else return false;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
        if (fast && fast->next) fast = fast->next;
        else return false;
    }
    return true;
}
