#include <bits/stdc++.h>
using namespace std;
#define N 100005
int root[N],siz[N];
void init(){
    for(int i=0;i<N;i++){
        root[i]=i;
        siz[i]=1;
    }
}
void merge(int a, int b){
    while(a!=root[a])
        a = root[a];
    while(b!=root[b])
        b = root[b];
    if(siz[a]<siz[b]){
        root[a]=b;
        siz[b]+=siz[a];
    }
    else{
        root[b]=a;
        siz[a]+=siz[b];
    }
}
int main(){
}