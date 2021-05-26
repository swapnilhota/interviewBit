/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    
    
     ListNode* temp=A;
     
     int n=0;
     
     while(temp->next)
     {
         n++;
         temp=temp->next;
     }
     
     n++;
     B=B%n;
     if(B==0)
     {
         return A;
     }
     
     temp->next=A;
     
     int cnt=n-B;
     temp=A;
     while(cnt>1)
     {
         temp=temp->next;
         cnt--;
     }
     
     A = temp->next;
     temp->next=NULL;
     
     return A;
    
}
