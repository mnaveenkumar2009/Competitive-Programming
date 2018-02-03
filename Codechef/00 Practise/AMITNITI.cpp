    #include <bits/stdc++.h>
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    #define sd(n) scanf("%d",&n)
    #define sc(n) scanf("%c",&n)
    #define slld(n) scanf("%lld",&n)
    using namespace std;
     
    int main()
    {
        int t,i;
        sd(t);
        vector <long long> s,s1(17),s2(16);
        s.pb(2);
        s.pb(7);
        f(i,33)
        {
            if(i>1)
            {
                if(i%2==0)
                {
                    s.pb(s[i-1]+(3*s[i-2]));
                }
                else
                {
                    s.pb(s[i-1]+7);
                }
            }
            //cout<<s[i]<<endl;
        }
        f(i,17)
        {
            s1[i]=s[i];
            //cout<<s1[i]<<endl;
        }
        f(i,16){s2[i]=s[i+17];
        //cout<<s2[i]<<endl;
            
        }
        vector <long long> perm1,perm2;
        long long k=0;
        
        f(k,pow(2,18))
        {   long long y=0,k2=k;;i=0;
            while(k2!=0)
            {
                y+=s1[i]*(k2%2);
                k2/=2;i++;
            }
            perm1.pb(y);
        }
        f(k,pow(2,17))
        {   long long y=0,k2=k;i=0;
            while(k2!=0)
            {
                y+=s2[i]*(k2%2);
                k2/=2;i++;
            }
            perm2.pb(y);
        }
        //cout<<perm1.size()<<endl;
        //f(i,20)cout<<perm1[i]<<endl;
        while(t--)
        {
            long long n;
            cin>>n;
            bool we=0;
            f(k,perm1.size())
            {
                if( (n-perm1[k]==0) || binary_search(perm2.begin(),perm2.end(),(n-perm1[k])) )we=1;
            }
            if(we)
            {
                cout<<"YES\n";
            }
            else
            {
                cout<<"NO\n";
            }
        }
     
        return 0;
    } 