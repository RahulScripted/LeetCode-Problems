// Given the head of a linked list with even length, return the maximum twin sum of the linked list.





#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        int count = 0; 
        ListNode* temp = head; 
        while(temp) {
            count++; 
            temp = temp->next; 
        }
        
        int i = 0, m = 0;
        temp = head;  
        vector<int> hash; 
        
        while(temp) {
            if(i < count / 2) hash.push_back(temp->val); 
            else {
                hash[count - i - 1] += temp->val; 
                m = max(m, hash[count - i - 1]); 
            }
            i++; 
            temp = temp->next;
        }
        return m; 
    }
};

// Create a linked list from a vector of values
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

int main() {
    vector<int> values = {4, 2, 2, 4};
    ListNode* head = createLinkedList(values);

    Solution solution;
    int result = solution.pairSum(head);

    cout << "The maximum twin sum is: " << result << endl;

    ListNode* temp;
    while (head) {
        temp = head->next;
        delete head;
        head = temp;
    }

    return 0;
}