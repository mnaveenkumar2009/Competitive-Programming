#include <iostream>
using namespace std;
struct Node{
    int value;
    struct Node *next;
    Node(){
        value=-1;
    }
};

int main(){
    Node *head,*second;
    head = new Node;
    second = new Node;
    head->value=1;
    second->value=2;
    head->next=second;
    second->next=0;
    
    cout<<(head->next)->value<<'\n';
}