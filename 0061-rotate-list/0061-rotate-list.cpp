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
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }
        ListNode* prev = NULL;
        ListNode* temp = head;

        int len = 1;

        while(temp -> next != NULL){
            temp = temp -> next;
            len++;
        }

        temp = head;

        // Edge case  (if k is greater than the length of the list)
        if(k > len){

            k = k % len;
        }
        if( k == 0) return head;

        int index = len - k;
        int element = 0;

        while( element != index){
            prev = temp;
            temp = temp -> next;

            element++;
        }


        ListNode* newhead = temp;

        if(element == 0) return newhead;
        
        else{
            
            prev -> next = NULL;

            while(temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = head;
        }

        return newhead;        
    }
};