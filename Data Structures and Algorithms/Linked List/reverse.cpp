#include "../../template.h"


struct Node{
    int value;
    struct Node *next;
};

void reverse(struct Node * node){
    
    struct Node* curr=node, *nex=node->next,*prev=0;

    while(curr){
        nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr= nex;
    }
}
void traverse(struct Node * node){
    cout<<(node->value);
    if(node->next!=0){
        cout<<"->";
        traverse(node->next);
    }
}

int main(){
    Node head,second,third;
    head.value=1;
    second.value=2;
    third.value=3;
    head.next=&second;
    second.next=&third;
    third.next=0;
    reverse(&head);
    traverse(&third);
    pc('\n');
}