    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    #define sd(n) scanf("%d",&n)
    #define sc(n) scanf("%c",&n)
    #define slld(n) scanf("%lld",&n)
    #define mod 1000000007
    #define mp make_pair
    #define ff first
    #define ss second
    #define ll long long
     
     
     
     
    int main()
    {
        
    	int t=1;
    	sd(t);
    	while(t--){
    	    int n,k;
    	    cin>>n>>k;
    	    string s;
    	    char a[k];
    	    a[0]='a';
    	    
    	    int i;
    	    f(i,k-1)a[i+1]=a[i]+1;
    	    if(k!=2){
    	        f(i,n){
    	            s.pb(a[i%k]);
    	        }
    	        if(k!=1)
    	        cout<<1<<" "<<s<<endl;
    	        else
    	        cout<<n<<" "<<s<<endl;
    	    }
    	    else
    	    {  
    	        if(n==3){
    	            printf("2 abb\n");
    	            continue;
    	        }
    	        if(n==4){
    	            printf("2 aabb\n");
    	            continue;
    	        }
    	        
    	        if(n<9){
    	        if(n==1){
    	            printf("1 a\n");
    	            continue;
    	        }
    	        f(i,n){
    	            if(i<n/2)
    	            s.pb('a');
    	            else
    	            s.pb('b');
    	        }
    	        f(i,n-1){
    	            if(s[i]!=s[i+1])break;
    	        }
    	        swap(s[i],s[i+1]);
    	        int xxx=1;
    	        if(n>2)
    	        xxx=3;
    	        xxx=max(xxx,max(i,n-(i+2)));
    	        cout<<xxx<<" "<<s<<endl;
    	    }
    	        else
    	    {
    	        s.pb('a');
    	        while(1){
    	           string x="bbaaba";
    	           s+=x;
    	           if(s.length()>=n)break;
    	        }
    	        cout<<4<<" ";
    	        f(i,n)printf("%c",s[i]);
    	        cout<<endl;
    	    }
    	    }
    	    
    	}
    	
    	return 0;
    }  