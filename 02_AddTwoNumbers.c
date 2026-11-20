struct ListNode* addTwoNumbers(struct ListNode* l1,
                               struct ListNode* l2) {
    struct ListNode dummy = {0, NULL};
    struct ListNode *current = &dummy;
    int carry = 0;

    while(l1 || l2 || carry) {
        int sum = carry;

        if(l1) {
            sum += l1->val;
            l1 = l1->next;
        }

        if(l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;

        current->next = malloc(sizeof(struct ListNode));
        current = current->next;

        current->val = sum % 10;
        current->next = NULL;
    }

    return dummy.next;
}