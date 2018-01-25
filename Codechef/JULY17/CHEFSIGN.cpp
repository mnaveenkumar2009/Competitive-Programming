    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
     
    int main() {
        int i,q;
        cin>>q;
    while(q--)
    {  
        char s[100008];
        cin>>s;
        bool we=1;
        f(i,strlen(s))
        {
            
        if(s[i]=='<')
        {
            we=0;break;
        }
        if(s[i]=='>')
        {
            break;
        }
        
        }
        int len=0,maxi=0;
        f(i,strlen(s))
        {
            
            if((s[i]=='<'&&!we)||(s[i]=='>'&&we))
            {
                len++;
            }
            
            if((s[i]=='<'&&we)||(s[i]=='>'&&!we))
            {
                maxi=max(len,maxi);
                len=1;
                we=!we;
            }
        }
        maxi=max(len,maxi);
        printf("%d\n",maxi+1);
        
    }
    	return 0;
    } 