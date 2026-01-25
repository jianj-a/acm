#include <stdio.h>
#include<bits/stdc++.h>
#include<map>
using namespace std;
typedef struct Node {
    int data;
    struct Node *next;
} Node, *LinkedList;

LinkedList InitList() {
    LinkedList head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    return head;
}

bool InsertList(LinkedList head, int i, int e) {
    Node *p = head;
    int j = 0;
    if(i<=0)return false;
    while (p!= NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    
    if (p == NULL) {
        return false;
    }
    
    Node *s = (Node *)malloc(sizeof(Node));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}

bool DeleteList(LinkedList head, int i) {
    Node *p = head;
    Node *q;
    int j = 0;
    if(i<=0)return false;
    while (p!= NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if(p==NULL){
        return false;
    }
    q = p->next;
    if(q==NULL){
        return false;
    }
    int e=q->data;
    p->next = q->next;
    free(q);
    return true;
}
LinkedList move(LinkedList head){
    if(head->next==NULL){
        return head;
    }
     Node *p = head->next;
     Node *pre = NULL;
       Node *q = head->next; 
     while(p->next!=NULL){
        if(p->next->data<q->data){
            q=p->next;
            pre=p;
        }
        p=p->next;
     }
     if(q==head->next){
        return head;
     }
     pre->next=q->next;
     q->next=head->next;
     head->next=q;
     return head;
}
void PrintList(LinkedList head) {
    Node *p = head->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
void Delete(LinkedList head){
    Node*q=head->next;
    if(q==NULL){
        return ;
    }
    Node*p=head->next->next;
    while(p!=NULL){
        if(p->data==q->data){
            q->next=p->next;
            p=p->next;
        }
        else{
            q=q->next;
            p=p->next;
        }
    }
}
unordered_map<int,int>m;
void Delete1(LinkedList head){
    Node*q=head->next;
    if(q==NULL){
        return ;
    }

    Node*p=head->next->next;
    m[q->data]=1;
    while(p!=NULL){
        if(m.contains(p->data)){
            q->next=p->next;
            p=p->next;
        }
        else{
            m[p->data]=1;
            q=q->next;
            p=p->next;
        }
    }
}
int main() {
    LinkedList head = InitList();
    
    InsertList(head, 1, 10);
    InsertList(head, 2, 20);
    InsertList(head, 3, 20);
    InsertList(head, 4, 20);
    InsertList(head, 5, 30);
    InsertList(head, 6, 30);
    InsertList(head, 7, 10);
   PrintList(head);
   m.clear();       
   Delete1(head);
   PrintList(head);
    return 0;
}