#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int kkk=1;kkk<=t;kkk++){
        string s;
        cin>>s;
        if(s.length()==1){
            if(s=="5"){
                cout<<"Case #"<<kkk<<": "<<"2 3\n";
                continue;
            }
            cout<<"Case #"<<kkk<<": "<<1<<' '<<(--s[0])<<'\n';
        }
        else{
            int n=s.length();
            string s2=s;
            int i;
            for(int i=0;i<n;i++){
                s2[i]='0';
                if(s[i]=='4'){
                    s[i]='2';
                    s2[i]='2';
                }
            }
            for(i=0;i<n;i++)
                if(s2[i]!='0')
                    break;
            s2=s2.substr(i,s.length()-i);

            if(s2.size()==0){
                s2=s;
                for(int i=0;i<n;i++){
                    s2[i]='0';
                    if(s[i]>'1'){
                        if(s[i]=='5'){
                            s[i]='2';
                            s2[i]='3';
                        }
                        else{
                            s[i]--;
                            s2[i]='1';
                        }
                    }
                }
                for(i=0;i<n;i++)
                    if(s2[i]!='0')
                        break;
                s2=s2.substr(i,s.length()-i);
                if(s2.size()==0){
                    for(i=0;i<n;i++)
                        if(s[n-i-1]!='0'){
                            s[n-i-1]='0';
                            break;
                        }
                        else{
                            s[n-i-1]='9';
                        }

                    
                    for(i=0;i<n;i++)
                        if(s[i]!='0')
                            break;
                    s=s.substr(i,s.length()-i);

                    cout<<"Case #"<<kkk<<": "<<1<<' '<<s<<'\n';
                }
            }
            cout<<"Case #"<<kkk<<": "<<s<<' '<<s2<<'\n';
        }
    }

}