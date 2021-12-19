#include <stdio.h>
#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
using namespace std;


ll coin(ll arr[],ll n, ll x){
    if(x<0){
        return 0;
    }
    else if(x==0){
        return 1;
    }

    return coin(arr,n,x-arr[n-1])+coin(arr,n,x-arr[n-2])+coin(arr,n,x-arr[n-3]);
}


int main(){

ll n,x;
cin>>n>>x;
vector<ll>arr(n);

for(ll i=0;i<n;i++){
    cin>>arr[i];
}
vector<ll> dp(x+1,0);
for(int i=0;i<x+1;i++){
    dp[i]=0;
}

dp[0]=1;
for(int i=1;i<x+1;i++){

   for(int j=0;j<n;j++){
       if(i-arr[j]<0){
        continue;
       }
       dp[i]=(dp[i] + dp[i-arr[j]])%MOD;
   }
}
cout<<dp[x]%MOD;
return 0;
}