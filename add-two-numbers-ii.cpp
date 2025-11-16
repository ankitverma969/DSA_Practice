/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2;
        
        ListNode* head = nullptr;
        int carry = 0;

        while(l1){
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2=l2->next;
        }

        while(!s1.empty() || !s2.empty() || carry){
            int x=0;
            int y=0;

            if(!s1.empty()){
                x=s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                y=s2.top();
                s2.pop();
            }

            int sum = x+y+carry;
            carry = sum/10;
            ListNode* newNode = new ListNode(sum % 10);
            newNode->next = head;
            head = newNode;
        }

        return head;

    }
};