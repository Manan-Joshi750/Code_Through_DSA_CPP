#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeDuplicates(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        unordered_set<int> seen;
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr != nullptr) {
            if (seen.find(curr->val) != seen.end()) {
                // Duplicate found, remove it
                prev->next = curr->next;
                delete curr;
            } else {
                // Not a duplicate, add to set
                seen.insert(curr->val);
                prev = curr;
            }
            curr = prev->next;
        }

        return head;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create an unsorted linked list: 4 -> 2 -> 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(4);

    cout << "Original list: ";
    printList(head);

    // Remove duplicates
    Solution solution;
    head = solution.removeDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head);

    // Clean up memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}