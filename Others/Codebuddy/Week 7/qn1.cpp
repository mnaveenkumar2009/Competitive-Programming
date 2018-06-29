/*
Question 1: Given a string S composed of 0 and 1. Find the minimum splits such that the substring is a binary representation of the power of 4 or 6 with no leading zeros. Print -1 if no such partitioning is possible.
Input: 100110110
Output: 3
The string can be split into a minimum of
three substrings 100(power of 4), 110
(power of 6) and 110(power of 6).Input : 00000
Output : -1
0 is not a power of  4 or 6.
*/

// n^2
#include <bits/stdc++.h>
using namespace std;

vector <string> po4,po6;

string add(string a,string b){
    string result = b;
    if(a.length()<b.length())// max mismatch = 1
        a = "0" + a;
    int n=b.length();
    result[0]=a[0]+b[0]-(2*'0');

    for(int i=n-1;i>0;i--)
        result[i]=0;
    
    for(int i=n-1;i>0;i--){
        result[i]+=a[i]+b[i]-(2*'0');
        while(result[i]>1){
            result[i]-=2;
            result[i-1]++;
        }
    }
    
    for(int i=0;i<result.length();i++)
        result[i]+='0';
    
    if(result[0]>='2'){
        result="1"+result;
        result[1]-=2;
    }

    return result;
}
void precompute(){
    string s="100";
    while(s.length()<10000){
        po4.push_back(s);
        s.push_back('0');
        s.push_back('0');
    }
    
    s="110";
    while(s.length()<10000){
        po6.push_back(s);
        s.push_back('0');
        string temp = add(s,s);
        s= add(s,temp);
    }
    
}

#define INIT INT_MAX-10009
vector <int> found[10009];
vector <int> dp(10009,INIT); // to avoid overflow
int n;
int ans(int pos){
    if(dp[pos]!=INIT)
        return dp[pos];

    if(pos==n)
        return 0;
    
    for(int i=0;i<found[pos].size();i++)
        dp[pos]=min( dp[pos],1+ans(pos+found[pos][i]) );
    
    return dp[pos];
}

int main(){
    precompute();
    
    string s;
    cin>>s;
    n=s.length();

    for(int i=0;i<po4.size();i++){
        int fnd = s.find(po4[i]);

        while(fnd!=string::npos){
            found[fnd].push_back(po4[i].size());
            // cout<<fnd<<' '<<po4[i]<<"das\n";
            fnd = s.find(po4[i],fnd+1);
        }
    }
    
    for(int i=0;i<po6.size();i++){
        int fnd = s.find(po6[i]);

        while(fnd!=string::npos){
            found[fnd].push_back(po6[i].size());
            // cout<<fnd<<' '<<po6[i]<<"das\n";
            fnd = s.find(po6[i],fnd+1);
        }
    }

    cout<<ans(0);
    
}
