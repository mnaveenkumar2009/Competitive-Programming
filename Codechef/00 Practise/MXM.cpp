#include <bits/stdc++.h>
using namespace std;

vector <int> a(100005);
int k;
void incl(int &l,vector <int> &b1,set <int> &setbits1, int &maxi1){
    l++;
    b1[a[l]]++;
    setbits1.insert(a[l]);
    int i=0;
    while(b1[a[l]+i]==k){
        b1[a[l]+i]=0;
        setbits1.erase(a[l]+i);
        i++;
        b1[a[l]+i]++;
        setbits1.insert(a[l]+i);
    }
    maxi1=max(a[l]+i,maxi1);
}
void decr(int &r,vector <int> &b2,set <int> &setbits2,int &maxi2){
    r--;
    b2[a[r]]++;
    setbits2.insert(a[r]);
    int i=0;
    while(b2[a[r]+i]==k){
        b2[a[r]+i]=0;
        setbits2.erase(a[r]+i);
        i++;
        b2[a[r]+i]++;
        setbits2.insert(a[r]+i);
    }
    maxi2=max(a[r]+i,maxi2);
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n>>k;
        vector <int> b1(200005,0),b2(200005,0);
        
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        int l=0,r=n-1;
        b1[a[0]]++;
        b2[a[n-1]]++;
        int maxi1=a[0],maxi2=a[n-1];

        set <int> setbits1{a[0]},setbits2{a[n-1]};
        
        while(r!=l+1){

            if(maxi1<maxi2)
                incl(l,b1,setbits1,maxi1);
            
            if(maxi2<maxi1)
                decr(r,b2,setbits2,maxi2);
            
            if(maxi1==maxi2){
                if(b1[maxi1]<b2[maxi1]){
                    incl(l,b1,setbits1,maxi1);
                }
                else{
                    if(b1[maxi2]>b2[maxi2]||maxi1==0)
                        decr(r,b2,setbits2,maxi2);                    
                }
            }
            
            while(maxi2==maxi1&&maxi1){

                int mini=min(b1[maxi1],b2[maxi1]);
                
                b1[maxi1]-=mini;
                b2[maxi1]-=mini;
                if(!b1[maxi1]){
                    setbits1.erase(maxi1);
                    if(setbits1.size())
                        maxi1=*setbits1.rbegin();
                    else
                        maxi1=0;
                }
                if(!b2[maxi2]){
                    setbits2.erase(maxi2);
                    if(setbits2.size())
                        maxi2=*setbits2.rbegin();
                    else
                        maxi2=0;
                }
            }
        }
        cout<<l+1<<'\n';
    }

    return 0;
}