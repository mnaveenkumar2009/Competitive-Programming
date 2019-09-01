#include <bits/stdc++.h>
using namespace std;

void quick_sort(int a[],int n, int l, int r){
    if(r-l<1)
        return;
    int pivot=a[r];
    int start_index=l;
    for(int i=l; i<=r; i++){
        if(a[i] < pivot)
            swap(a[i], a[start_index++]);
    }
    swap(a[r],a[start_index]);
    quick_sort(a,n,l,start_index-1);
    quick_sort(a,n,start_index+1,r);
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    quick_sort(a,n,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
    cout<<'\n';
}