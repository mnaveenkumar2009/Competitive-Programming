    #include <bits/stdc++.h>
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    using namespace std;
    int i,j;
    int main() 
    {
    	int t;
    	cin>>t;
    	while(t--)
    	{int n,k;
    	cin>>n>>k;
    	 bool a[n][k];
    	 f(i,n)
    	 {
    	     f(j,k)
    	     {
    	         a[i][j]=0;
    	     }
    	 }
    	  vector < vector <int> > c(k,vector <int> (0,0));
        f(i,n)
        {int l;
           cin>>l;
           while(l--)
           {
               int g;
               cin>>g;
               a[i][g-1]=1;
               c[g-1].pb(i);
           }
        }
      //  f(i,n)    {        f(j,k)        {            cout<<a[i][j]<<" ";        }cout<<endl;    }
       
        int min1=0;
        if(n==1)
        {
            cout<<"0\n";continue;
        }
        if(k==1)
        {
            cout<<(n*(n-1)/2)<<endl;continue;
        }
            
        // f(i,k)    {        f(j,c[i].size())        {            cout<<c[i][j]<<" ";        }cout<<endl;    }
        f(i,k)
        {
            sort(c[i].begin(),c[i].end());
        }
        if(1)
        {int count=0,K;
            f(i,k)
            {
            if(c[i].size()<=c[min1].size()&&i!=min1)
            {
                min1=i;
                
            }
            }
            vector <bool> done(n);
            f(i,n)
            {
                done[i]=0;
            }
           // cout<<min1<<min2<<endl;
          f(i,c[min1].size())
          {done[c[min1][i]]=1;
         
              f(j,n)
              {int we=1;
              if(done[j])
              {
                  we=0;continue;
              }
                    f(K,k)
                    {
                        if(!(a[c[min1][i]][K]||a[j][K]))
                        we=0;
                    }
                  if(we)
                    {
                        count++;}
              }
          }
            
            
            cout<<count<<endl;
        }
        else
        {int count=0,K;
            //brute force
            f(i,n)
            {
                for(j=i+1;j<n;j++)
                {int we=1;
                    f(K,k)
                    {
                        if(!(a[i][K]||a[j][K]))
                        we=0;
                    }
                    if(we)
                    {
                        count++;
                    }
                }
            }
            cout<<count<<endl;
        }
    	}
    } 