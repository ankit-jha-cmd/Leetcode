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
ListNode* reverselist(ListNode* head){
    ListNode* temp=head;
    ListNode* prev=NULL;
    ListNode* next=temp;
    while(temp){
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    return prev;
}
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy= new ListNode(0);
        dummy->next=head;
        ListNode* temp=dummy;
        if(!head->next) return head;
        if(left==right) return head;
        int cnt=0;
        while(cnt < left-1){
            temp=temp->next;
            cnt++;
        }
        ListNode* endpoint1=temp;
        while(cnt!=right){
            temp=temp->next;
            cnt++;
        }
        ListNode* endpoint2=temp->next;
        temp->next=NULL;
        temp=endpoint1->next;
        ListNode* lastjoint=temp;
        endpoint1->next=reverselist(temp);
        lastjoint->next=endpoint2;
        ListNode* ans= dummy->next;
        delete dummy;
        return ans;
    }
};