#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
long long summ(vector <long long> a){
    long long ret=0;
    for(auto it:a){
        ret+=it;
    }
    return ret;
}
int main() {

    #define int long long
    // cout<<"2\n191 0 0\n192 998832694 0\n";
    int n,m;
    cin>>n>>m;
    int xxx;
    int k;
    cin>>k;
    pair <int,int> a[k];
    int b[k];
    unordered_map <int,int> pos,done;

    f(i,k){
        cin>>xxx>>a[i].first;
        pos[a[i].first] = i + 1;
        a[i].second = i;
        b[i] = a[i].first;
    }
    sort(a,a+k);
    vector < vector <int> > ans;
    int r = k-1;
    while(ans.size()<=333){
        // cout<<r<<'\n';
        if(done[a[r].second]){
            if(!r)break;
            r--;
            continue;
        }
        f(i,r){
            if(!done[a[i].second]){
                if(pos[m - a[r].first - a[i].first]){
                    vector <int> temmm;
                    temmm.push_back(a[i].second);
                    temmm.push_back(a[r].second);
                    temmm.push_back(pos[m - a[r].first - a[i].first]-1);
                    ans.push_back(temmm);
                    // cout<<a[i].second<<' '<<a[r].second<<' '<<pos[m - a[r].first - a[i].first]-1<<'\n';
                    done[a[i].second]=1;
                    done[a[r].second]=1;
                    done[pos[m - a[r].first - a[i].first]-1]=1;
                    break;
                }
            }
        }
        r--;
    }
    // cout<<ans.size()<<'\n';
    // return 0;
    cout<<999<<'\n';
    int col=0;
    for(auto paks:ans){
        int sss=0;
        if(col==n)break;
        for(auto cur:paks){
            cout<<cur<<' '<<col<<' '<<sss<<'\n';
            sss+=b[cur];
        }
        // cout<<sss<<'\n';
        // break;
        col++;
    }
    return 0;
}
