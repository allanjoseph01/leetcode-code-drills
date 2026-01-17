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
    ListNode* rotateRight(ListNode* head, int k) {
        int siz=0;
        ListNode* temp = head;
        while(temp!=nullptr){
            siz++;
            temp = temp->next;
        }
        if(siz==0 || k==0){
            return head;
        }
        int n = k%siz;
        if(n==0){
            return head;
        }
        temp = head;
        for(int i=0;i<(siz-n-1);i++){
            temp = temp->next;
        }
        ListNode* newHead= temp->next;
        temp->next = nullptr;
        ListNode* temp2= newHead;
        while(temp2!=nullptr && temp2->next!=nullptr){
            temp2= temp2->next;
        }
        temp2->next = head;
        head= newHead;
        return head;
    }
};