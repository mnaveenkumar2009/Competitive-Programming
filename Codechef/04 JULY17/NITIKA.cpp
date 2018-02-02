    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
     
    int main() 
    {
        int q,i;bool we=1;
        cin>>q;
        while(q--)
        {
        string s;
        if(we)
        cin.ignore(); 
        we=0;
        getline(cin,s);
            i=0;
        int pos[4]={-1,-2,-2,-2},siz=s.length(),j;
        int count=1;
        f(i,siz)
        {  
            if(s[i]==' ')
            {
                pos[count]=i;
                count++;
            }
        }
        
        f(i,3)
        if(pos[i]!=-2&&pos[i+1]!=-2)
        {printf("%c. ",toupper(s[pos[i]+1]));}
        else
        break;
        j=pos[i]+1;
        printf("%c",toupper(s[j]));
        for(j=pos[i]+2;j<siz;j++)
        {
        printf("%c",tolower(s[j]));
        }
        
        printf("\n");
        }
    	return 0;
    } 