#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define ff first
#define ss second
int main() {
    #define int long long
    int n,m;
    cin>>n>>m;
    int k;
    cin>>k;
    pair <int,int> a[k];
    vector <int> sqa;
    vector <pair <int,int> > sqa_p;
    unordered_map <int,int> sqamap,row,col;
    f(i,k){
        cin>>a[i].ff>>a[i].ss;
        if(a[i].ff==a[i].ss){
            sqa.push_back(a[i].ff);
            sqamap[a[i].ff] = i;
        }
        else{
            row[a[i].ff] = i;
            col[a[i].ss] = i;
        }
    }
    f(i,101){
        sqa_p.push_back({sqa[i]+a[row[sqa[i]]].ss,sqa[i]});
    }
    sort(sqa_p.begin(),sqa_p.end());
    reverse(sqa_p.begin(),sqa_p.end());
    f(i,101){
        sqa[i] = sqa_p[i].ss;
    }
    cout<<k<<'\n';
    int curpos=0;
    f(i,100){
        cout<<sqamap[sqa[i]]<<' '<<curpos<<' '<<curpos<<'\n';
        cout<<col[sqa[i]]<<' '<<curpos+sqa[i]<<' '<<curpos<<'\n';
        cout<<row[sqa[i]]<<' '<<curpos<<' '<<curpos+sqa[i]<<'\n';
        curpos+=sqa[i];
    }
    cout<<sqamap[sqa[100]]<<' '<<curpos<<' '<<curpos<<'\n';

    return 0;
}
