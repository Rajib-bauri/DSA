
/*
LeetCode 2: Add Two Numbers
Solution 1: Using Vectors
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v1, v2, ans;

        ListNode* temp = l1;
        while (temp) {
            v1.push_back(temp->val);
            temp = temp->next;
        }

        temp = l2;
        while (temp) {
            v2.push_back(temp->val);
            temp = temp->next;
        }

        int m = v1.size(), n = v2.size();
        int sum = 0, carry = 0;
        int len = max(m, n);

        for (int i = 0; i < len; i++) {
            int a = (i < m) ? v1[i] : 0;
            int b = (i < n) ? v2[i] : 0;

            sum = a + b + carry;
            ans.push_back(sum % 10);
            carry = sum / 10;
        }

        if (carry > 0) {
            ans.push_back(carry);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        for (int digit : ans) {
            tail->next = new ListNode(digit);
            tail = tail->next;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};

/*
Solution 2: Direct Linked List Traversal

Submit this class separately on LeetCode.
*/

// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* dummyHead = new ListNode(0);
//         ListNode* curr = dummyHead;
//         int carry = 0;
//
//         while (l1 != nullptr || l2 != nullptr || carry != 0) {
//             int x = l1 ? l1->val : 0;
//             int y = l2 ? l2->val : 0;
//             int sum = carry + x + y;
//
//             carry = sum / 10;
//             curr->next = new ListNode(sum % 10);
//             curr = curr->next;
//
//             l1 = l1 ? l1->next : nullptr;
//             l2 = l2 ? l2->next : nullptr;
//         }
//
//         ListNode* result = dummyHead->next;
//         delete dummyHead;
//         return result;
//     }
// };
