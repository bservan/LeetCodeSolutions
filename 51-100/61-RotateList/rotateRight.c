/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
 * To be able to compile this code, struct ListNode definition is added right below.
 */
#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k){
    struct ListNode *prev, *tail, *temp;

    if (!head || !(head->next)) return head;

    temp = head;
    int len = 0;

    while (temp) {
        len++;
        temp = temp->next;
        
        if (temp) tail = temp;
    }

    k = k % len;

    if (k == 0) return head;

    temp = head;
    
    while (temp) {
        prev = temp;

        if (k == (len--) - 1) {
            tail->next = head;
            head = prev->next;
            prev->next = NULL;

            return head;
        }

        temp = temp->next;
    }

    return head;
}
