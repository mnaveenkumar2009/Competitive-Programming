    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    #define ll long long
    int main(){
    	int t;
    	cin>>t;
    	while(t--){
    		ll m,x=0,y=1;
    		cin>>m>>x>>y;
    		ll yyy=m;
    		ll a=0,b=1;
    		ll k=2;
    		ll pos;
    		while(k!=m){
    		  pos=x*((k+2)/2);
    		  pos/=y;
    		  //pos was removed
    		  ll siz=k+2;
    		  if(a>=k/2){
    		      a-=k/2;
    		      a*=2;
    		      a++;
    		      if(pos<=a/2)a+=2;
    		  }
    		  else
    		  {
    		      a*=2;
    		      if(pos<=a/2)a+=2;
    		  }
    		  if(b>=k/2){
    		      b-=k/2;
    		      b*=2;
    		      b++;
    		      if(pos<=b/2)b+=2;
    		  }
    		  else
    		  {
    		      b*=2;
    		      if(pos<=b/2)b+=2;
    		  }
    		 // cout<<a<<" "<<b<<endl;
    		  
    		  k+=2;  
    		}
    		
    		cout<<((a+1)^(b+1))<<endl;
    			
    	}
    	return 0;
    } 