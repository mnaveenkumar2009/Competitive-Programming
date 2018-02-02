    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
     
    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {int i;
            string c;
            int coup=0,codown=0;bool we;
            cin>>c;
            if(c[0]=='U')
            coup=1,we=1;
            else
            codown=1,we=0;
            f(i,c.length()-1)
            {
                
                if(c[i]!=c[i+1])
                {
                    we=!we;
                    if(we)
                    {
                        coup++;
                    }
                    else
                    codown++;
                }
            }
            cout<< min(codown,coup)<<endl;
        }
     return 0;   
    } 