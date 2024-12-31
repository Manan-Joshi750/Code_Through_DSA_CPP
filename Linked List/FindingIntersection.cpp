#include <iostream>
using namespace std;
//FINDING THE INTERSECTION POINT FOR TWO LINKED LISTS.
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int length(ListNode *head) {
    int len = 0;
    ListNode *current = head;
    while (current != nullptr) {
        len++;
        current = current->next;
    }
    return len;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lenA = length(headA);
    int lenB = length(headB);  
    // Move the pointer of the longer list by the difference in lengths
    while (lenA > lenB) {
        headA = headA->next;
        lenA--;
    }  
    while (lenB > lenA) {
        headB = headB->next;
        lenB--;
    }   
    // Move both pointers until they meet at the intersection point
    while (headA != headB) {
        headA = headA->next;
        headB = headB->next;
    }
    
    return headA; // Return either headA or headB
}
// Helper function to create a linked list node
ListNode* createNode(int val) {
    return new ListNode(val);
}

int main() {
    // Creating linked lists
    ListNode *intersection = createNode(8);
    
    ListNode *headA = createNode(4);
    headA->next = createNode(1);
    headA->next->next = intersection;
    headA->next->next->next = createNode(4);
    headA->next->next->next->next = createNode(5);

    ListNode *headB = createNode(5);
    headB->next = createNode(0);
    headB->next->next = createNode(1);
    headB->next->next->next = intersection;

    ListNode *result = getIntersectionNode(headA, headB);
    if (result)
        cout << "Intersection point value: " << result->val << endl;
    else
        cout << "No intersection point found." << endl;

    return 0;
}
