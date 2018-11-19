// compile using "g++ LOAD_DISTRIBUTION.cpp -o LOAD_DIST" in linux
// RUN : "./LOAD_DIST <INPUT >OUTPUT"

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {

    int n;
    cin>>n; // number of loads
    ll L[n],R[n],T[n],W[n];
    // L[i] = start time of load i
    // R[i] = end time of load i
    // T[i] = number of hours load i must run
    // W[i] = load weight
    long double num[n],den[n];
    ll P[24]={4, 4 ,10 ,10, 4, 4, 4, 4, 4, 4, 4 ,10, 10, 10, 4, 4 ,4, 4, 4, 4, 4 ,4 ,4 ,4};
    // P[i] = cost for hour i
    vector <bool> PeakOff(24,0);
    for(int i=0;i<24;i++){
        if(P[i]==4)
            PeakOff[i]=1;
    }
    for(int i=0;i<n;i++){
        cin>>L[i];
    }
    for(int i=0;i<n;i++){
        cin>>R[i];
    }
    for(int i=0;i<n;i++){
        cin>>T[i];
    }
    for(int i=0;i<n;i++){
        cin>>W[i];
    }
    for(int i=0;i<n;i++){
        num[i]=T[i];
        den[i]=0;
        for(int j=0;j<24;j++){
            if(PeakOff[j]){
                if((j<=R[i]-1)&&(j>=L[i]-1))
                    den[i]++;// denominator is the number of slots available in Peak off time
            }
        }
    }
    
    ll Total_Cost=0;

    ll LIMIT=10; // maximum load per hour

    vector <int> hours[24]; // hours[i] stores the load indices that operate at hour i
    
    for(int i=0;i<24;i++){
        if(PeakOff[i]){
            vector <pair <long double,ll> > ratio;
            for(int j=0;j<n;j++){
                if((i<=R[j]-1)&&(i>=L[j]-1))
                    if(num[j])
                    ratio.push_back(make_pair(num[j]/den[j],j));
            }
            sort(ratio.rbegin(), ratio.rend());  // sort using reverse iterators, sorts it in descending order

            ll lim=LIMIT;

            for(int j=0;j<ratio.size();j++){
                if(!(ratio[j].first))break;
                ll pos=ratio[j].second;
                if(lim>=W[pos]){
                    hours[i].push_back(pos);
                    lim-=W[pos];
                    Total_Cost+=4*W[pos];
                    num[pos]--;
                }
            }
            for(int j=0;j<ratio.size();j++){
                den[ratio[j].second]--;
            }
        }
    }

    // change denominator to available slots in peak on time
    for(int i=0;i<n;i++){
        den[i]=0;
        for(int j=0;j<24;j++){
            if(!PeakOff[j]){
                if((j<=R[i]-1)&&(j>=L[i]-1))
                    den[i]++;
            }
        }
    }

    for(int i=0;i<24;i++){
        if(!PeakOff[i]){
            vector < pair <long double,ll> > ratio;
            for(int j=0;j<n;j++){
                if((i<=R[j]-1)&&(i>=L[j]-1))
                    if(num[j])
                        ratio.push_back(make_pair(num[j]/den[j],j));
            }
            sort(ratio.rbegin(), ratio.rend());  // sort using reverse iterators, sorts it in descending order

            ll lim=LIMIT;
            for(int j=0;j<ratio.size();j++){
                if(!(ratio[j].first))break;
                ll pos=ratio[j].second;
                if(lim>=W[pos]){
                    hours[i].push_back(pos);
                    lim-=W[pos];
                    Total_Cost+=4*W[pos];
                    num[pos]--;
                }
            }
            for(int j=0;j<ratio.size();j++){
                den[ratio[j].second]--;
            }
        }
    }

    printf("Allocated Loads by Hour:\n");
    for(int i=0;i<24;i++){
        printf("Hour %2d: ",i+1);
        for(auto it:hours[i]){
            printf("%3d ",it+1);
        }
        cout<<'\n';
    }
    
    printf("\nTotal Cost:\n%lld\n",Total_Cost);
	return 0;
}

/*

IN:
6
2 4 6 4 5 11
4 18 8 12 10 19
3 3 3 3 6 4
4 4 4 5 5 6

OUT:
Allocated Loads by Hour:
Hour  1: 
Hour  2:   1 
Hour  3:   1 
Hour  4:   1 
Hour  5:   5   4 
Hour  6:   5   3 
Hour  7:   5   3 
Hour  8:   5   3 
Hour  9:   5   4 
Hour 10:   5   4 
Hour 11:   6   2 
Hour 12: 
Hour 13: 
Hour 14: 
Hour 15:   6   2 
Hour 16:   6   2 
Hour 17:   6 
Hour 18: 
Hour 19: 
Hour 20: 
Hour 21: 
Hour 22: 
Hour 23: 
Hour 24: 

Total Cost:
420

*/