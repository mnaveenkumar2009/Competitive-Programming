#include "../../template.h"

struct Node{
    int value;
    struct Node *next;
};

void swap(struct Node * node,int x,int y){
    struct Node *i=node,*ip=0,*j=node,*jp=0;
    while(i->value!=x){
        ip=i;
        i=i->next;
    }
    while(j->value!=y){
        jp=j;
        j=j->next;
    }
    Node *temp;
    if(ip){
        ip->next=j;
        temp = j->next;
        j->next=i->next;
    }
    if(jp){
        jp->next=i;
        i->next=temp;
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
    Node nodes[10];
    int i;
    f(i,10){
        nodes[i].value=i;
        if(i!=9)
            nodes[i].next=&nodes[i+1];
        else
            nodes[i].next=0;
    }
    Node *head=&nodes[0];
    int x=uscan(),y=uscan();
    swap(head,x,y);
    traverse(head);
    pc('\n');
}