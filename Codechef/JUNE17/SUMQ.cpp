    #include <stdio.h>
     
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    #define mod 1000000007
    int i,j;
    void merge(long long int arr[], int l, int m, int r)
    {
        int i, j, k;
        int n1 = m - l + 1;
        int n2 =  r - m;
     
        int L[n1], R[n2];
        for (i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (j = 0; j < n2; j++)
            R[j] = arr[m + 1+ j];
     k=l;i=0;j=0;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
     
        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    void mergeSort(long long int arr[], int l, int r)
    {
        if (l < r)
        {
            int m = l+(r-l)/2;
            mergeSort(arr, l, m);
            mergeSort(arr, m+1, r);
     
            merge(arr, l, m, r);
        }
    }
    int main() {
    	int t;
    	scanf("%d",&t);
    	while(t--)
    	{int p,q,r;
    	    scanf("%d%d%d",&p,&q,&r);
    	    long long a[p],b[q],c[r];
    	    f(i,p)
    	    {
    	        scanf("%lld",&a[i]);
    	    }
    	    f(i,q)
    	    {
    	        scanf("%lld",&b[i]);
    	    }
    	    f(i,r)
    	    {
    	        scanf("%lld",&c[i]);
    	    }
    	    
        mergeSort(a, 0, p- 1);
        
        mergeSort(b, 0, q- 1);
        
        mergeSort(c, 0, r- 1);
        int k;
        i=0;k=0;j=0;
        long long suma=0,sumc=0,sum=0;
        int countd=0,counte=0;
        
        f(j,q)
        {
            while((i<p&&(a[i]<=b[j]))||(k<r&&c[k]<=b[j]))
        {
            if(i<p&&a[i]<=b[j])
            {
                countd++;suma+=a[i];i++;
            }
            if(k<r&&c[k]<=b[j])
            {
                counte++;sumc+=c[k];k++;
            }
        }
      // cout<<d.size()<<" "<<e.size()<<endl;
       //cout<<suma<<" "<<sumc<<endl<<endl;
            sum+=(((suma+(countd*b[j]))%mod)*((sumc+(counte*b[j]))%mod))%mod;
        }
       printf("%lld\n",sum%mod);
    	}
    	return 0;
    } 