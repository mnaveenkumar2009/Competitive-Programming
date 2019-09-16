#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define ff first
#define ss second
long long summ(vector <long long> a){
    long long ret=0;
    for(auto it:a){
        ret+=it;
    }
    return ret;
}
int main() {

    #define int long long
    int n,m;
    cin>>n>>m;
    int k;
    cin>>k;
    pair <int,int> a[k];
    vector <int> row,col;
    vector <pair<int,int> > row_bricks,col_bricks;
    f(i,k){
        cin>>a[i].ff>>a[i].ss;
        if(a[i].ff==5000000){
            // row.push_back(a[i].ss);
            row_bricks.push_back({a[i].ss,i});
        }
        else{
            assert(a[i].ss==10000000);
            col_bricks.push_back({a[i].ff,i});
        }
    }
    // // cout<<row.size()<<'\n';
    // // cout<<col.size()<<'\n';
    // sort(col.begin(),col.end());
    // sort(row.begin(),row.end());
    sort(col_bricks.begin(),col_bricks.end());
    sort(row_bricks.begin(),row_bricks.end());
    // // for(auto it:row)cout<<it<<' ';cout<<'\n';
    // // for(auto it:col)cout<<it<<' ';cout<<'\n';
    // f(i,100){
    //     cout<<row[i]+row[199-i]<<' ';
    // }
    
    cout<<400<<'\n';
    f(i,100){
        //5e6*1e9
        cout<<row_bricks[i].ss<<' '<<i*(int)5e6<<' '<<0<<'\n';
        cout<<row_bricks[199-i].ss<<' '<<i*(int)5e6<<' '<<row_bricks[i].ff<<'\n';
    }
    f(i,100){
        //5e8*1e7
        cout<<col_bricks[i].ss<<' '<<500000000<<' '<<(int)((i*1e7))<<'\n';
        cout<<col_bricks[199-i].ss<<' '<<500000000+col_bricks[i].ff<<' '<<(int)((i*1e7))<<'\n';
    }

    return 0;
}
