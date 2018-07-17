#include "../../template.h"

struct Node;

struct Node{
    int value;
    struct Node *next;
};

int main(){
    Node head,second,third;
    head.value=1;
    second.value=2;
    third.value=3;
    head.next=&second;
    second.next=&third;
    third.next=0;
    
    cout<<(*second.next).value<<'\n';
}