#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc;
    scanf("%d", &tc);
    while(tc--){
        pair<int,int> stick[5003];
        vector<pair<int,int> > v;
        int N;
        scanf("%d", &N);
        for(int i=0;i<N;++i)
            cin>>stick[i].first>>stick[i].second;
        
        sort(stick, stick+N);
        v.push_back(stick[N-1]);
        for(int i=N-2;i>=0;--i){
            int hi = v.size()-1, lo = 0, mid;
            while(lo <= hi){
                mid = (hi+lo)/2;
                if(v[mid].second < stick[i].second)
                    lo = mid+1;
                else
                    hi = mid-1;            
            }
            if(lo == v.size())
                v.push_back(stick[i]);
            else
                v[lo]= stick[i];
        }
        printf("%d\n", (int) v.size());
    }
    return 0;
}