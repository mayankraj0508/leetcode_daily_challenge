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
    int pow(int  a,int b,int ans){
        if(b==0){
            return 1;
        }
        if(b%2==0){
            ans =  pow(a,b/2,ans)*pow(a,b/2,ans);
        }
        else if(b%2!=0){
            ans =  pow(a,b/2,ans)*pow(a,b/2,ans)*a;

        }
        return ans;
        
    }
    int getDecimalValue(ListNode* head) {
        int size = 0;
        ListNode*slow = head;
        while(slow){
            size++;
            slow = slow->next;
        }
        slow = head;
        int ans = 0;
        while(slow){
            size--;
            ans = ans + slow->val*pow(2,size,0);
            slow = slow->next;

        }
        return ans;
        
    }
};
