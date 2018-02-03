//6 points solution
    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    #define ll long long
    int main()
    {
        
        ll n;
        cin>>n;
        vector <ll> a(40000018,0);
        ll i,j;
        vector <ll> b;
        
        for(i=2;i<=4000018;i++){
            if(i*i>40000018){
                break;
            }
            if(a[i*i]==0){
                for(j=1;(j*i*i)<=40000018;j++){
                    a[j*i*i]=1;
                }
            }
        }
        
        for(i=2;i<=40000018;i++){
            if(a[i])b.pb(i);
        }
        //f(i,20)cout<<b[i]<<" ";cout<<endl;
        cout<<b[n-1]<<endl;
    	return 0;
    } 