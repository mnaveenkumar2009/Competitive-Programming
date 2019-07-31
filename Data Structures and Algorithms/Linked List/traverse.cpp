#include "../../template.h"


struct Node{
    int value;
    struct Node *next;
};

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
    traverse(&head);
    pc('\n');
}