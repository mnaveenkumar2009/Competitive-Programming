ll nob(ll i, ll n){
    if(n<=0)return 0;
    ll temp=log2(n);
    if(temp==i){
        return (n-(1LL<<temp))+1;
    }
    if(temp>i){
        return (1LL<<(temp-1))+nob(i,n-(1LL<<temp));
    }
    if(temp<i)return 0;
}