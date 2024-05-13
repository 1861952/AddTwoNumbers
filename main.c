/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>


//  * Definition for singly-linked list.
  struct ListNode {
      int val;
      struct ListNode *next;
  };
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
    dummyHead->val = 0;
    dummyHead->next = NULL;
    struct ListNode* curr = dummyHead;
    int carry = 0;
    
    struct ListNode* p1 = l1;
    struct ListNode* p2 = l2;


    while (p1 != NULL || p2 != NULL || carry != 0)
    {
        int x = (p1 != NULL) ? p1->val : 0;
        int y = (p2 != NULL) ? p2->val : 0;
        int sum = x + y + carry;
        carry = sum/10;
        
        curr->next = malloc(sizeof(struct ListNode));
        curr->next->val = sum%10;
        curr->next->next = NULL;
        curr = curr->next;
        
        if (p1 != NULL) p1 = p1->next;
        if (p2 != NULL) p2 = p2->next;
        
    }
    
    struct ListNode* result = dummyHead->next;
    free(dummyHead);
    return result;
}

int main()
{
    // struct ListNode* List1 = malloc(sizeof(struct ListNode));
    // List1->val = 2;
    // List1->next = malloc(sizeof(struct ListNode));
    // List1->next->val = 4;
    // List1->next->next = malloc(sizeof(struct ListNode));
    // List1->next->next->val = 3;
    // List1->next->next->next = NULL;
    
    struct ListNode* List1 = malloc(sizeof(struct ListNode));
    List1->val = 2;
    List1->next = malloc(sizeof(struct ListNode));
    List1->next->val = 4;
    List1->next->next = NULL;
    
    struct ListNode* List2 = malloc(sizeof(struct ListNode));
    List2->val = 5;
    List2->next = malloc(sizeof(struct ListNode));
    List2->next->val = 6;
    List2->next->next = malloc(sizeof(struct ListNode));
    List2->next->next->val = 4;
    List2->next->next->next = NULL;
    
    struct ListNode* sum = addTwoNumbers(List1, List2);
    struct ListNode* ptr = sum;
    
    while(ptr != NULL)
    {
        printf("%d", ptr->val);
        ptr = ptr->next;
    }
    
    free(sum);
    free(List1);
    free(List2);
    
}
