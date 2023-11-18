#include<bits/stdc++.h>
using namespace std;
int findcanbang(int *a,int n,int sum){
    long long sum1=0;
    for(int i=0;i<n;i++){
        sum1+=a[i];
        if(sum1==sum-sum1+a[i]){
            return i+1;
        }
    }
    return -1;
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int a[n];
        long long sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        cout << findcanbang(a,n,sum) << endl;
    }
    return 0;
}