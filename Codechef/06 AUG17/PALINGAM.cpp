    #include <bits/stdc++.h>
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    #define sd(n) scanf("%d",&n)
    #define sc(n) scanf("%c",&n)
    #define slld(n) scanf("%lld",&n)
    using namespace std;
     
    int main()
    {
        int t;
        sd(t);
        while(t--)
        {
          string s,t2;int i;
          cin>>s>>t2;
          vector <int> c1(26,0),c2(26,0);
          f(i,s.length())
          {
              c1[s[i]-'a']++;
              c2[t2[i]-'a']++;
          }
          bool we=0;
          f(i,26)
          {
              if(c1[i]>1&&c2[i]==0)we=1;
          }bool we2=0;
          if(!we){
              
          f(i,26)
          {
              if(c1[i]==1&&c2[i]==0)we2=1;
          }
          if(we2)
          {
              we=1;
            f(i,26)
            {
                if(c2[i]&&!c1[i])we=0;
            }
          }
          
          }
          if(we)
          {
              printf("A\n");
          }
          else
          {
              printf("B\n");
          }
        }
     
        return 0;
    } 