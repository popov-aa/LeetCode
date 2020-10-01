// https://leetcode.com/problems/add-two-numbers/

#include <iostream>

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * root = nullptr;
        ListNode * prev = nullptr;
        int residual = 0;
        do {
            ListNode * l = new ListNode(residual);
            if (root == nullptr) {
                root = l;
            }
            if (prev != nullptr) {
                prev->next = l;
            }
            if (l1 != nullptr) {
                l->val += l1->val;
            }
            if (l2 != nullptr) {
                l->val += l2->val;
            }
            int _residual = 0;
            if (l->val > 9) {
                _residual = l->val / 10;
                l->val %= 10;
            }
            ListNode* l1Next = nullptr;
            if (l1) {
                l1Next = l1->next;
            }
            ListNode* l2Next = nullptr;
            if (l2) {
                l2Next = l2->next;
            }
            l1 = l1Next;
            l2 = l2Next;
            residual = _residual;
            prev = l;
        } while (l1 != nullptr || l2 != nullptr || residual != 0);
        return root;
    }
};

int main() {
    ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    Solution s;
    ListNode * result = s.addTwoNumbers(l1, l2);
    while (result != nullptr) {
        std::cout << result->val << " ";
        result = result->next;
    }
    std::cout << std::endl;
}