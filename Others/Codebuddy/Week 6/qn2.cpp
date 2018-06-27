//O(nlogn)
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n,m;
        cin>>n>>m;

        int p[n],sum=0;

        for(int i=0;i<n;i++){
            cin>>p[i];
            sum+=p[i];
        }

        int low=1,high=sum,mid;
        while(low!=high){
            mid=(high+low)/2;
            int cur_sum=0,count=1;
            for(int i=0;i<n;i++){
                if(p[i]>mid){
                    count=m+1;
                    break;
                }
                cur_sum+=p[i];
                if(cur_sum>mid){
                    count++;
                    cur_sum=p[i];
                }
            }
            if(count<=m){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        cout<<low<<'\n';
    }
}

/*
    4
    8 7
    4 4 4 4 4 4 4 4
    8
    4 3
    8 7 7 8
    14
    4 2
    12 34 67 90
    113
    4 2
    90 67 34 12
    113
*/