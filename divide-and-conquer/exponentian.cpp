#include <bits/stdc++.h>
using namespace std;

long long int findexponent(long long int a,long long int k){
    if(k==1){return a;}
    long long int m=k/2;
    long long int ans=findexponent(a,m);
    ans=ans*ans;
    if(k%2!=0){ans=ans*a;}
    return ans;
}


int main(){
    long long int a,k;cin>>a>>k;
    cout<<a<<" power "<<k<<" is "<<findexponent(a,k)<<endl;
    return 0;
}
