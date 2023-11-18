#include<bits/stdc++.h>
using namespace std;
int checkprime(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return 0;
        }
    }
    return n > 1;
}
vector<long long> prime;
void ktao(int n){
    for(int i=0;i<=n;i++){
        if(checkprime(i)){
            prime.push_back(i);
        }
    }
}
int main(){
    ktao(1000001);
    int t;
    cin >> t;
    for(int test=1;test<=t;test++){
        cout << "Test " << test << ":\n";
        int n;
        cin >> n;
        int cnt=0;
        int h1=0,h2=n-1,c1=0,c2=n-1;
        vector<vector<long long>> a(n,vector<long long>(n,0));
        while(h1<=h2 && c1<=c2){
            for(int i=c1;i<=c2;i++){
                a[h1][i] = prime[cnt++];
            }
            ++h1;
            for(int i=h1;i<=h2;i++){
                a[i][c2] = prime[cnt++];
            }
            --c2;
            for(int i=c2;i>=c1;i--){
                a[h2][i] = prime[cnt++];
            }
            --h2;
            for(int i=h2;i>=h1;i--){
                a[i][c1] = prime[cnt++];
            }
            ++c1;
        }
        for(int i=0;i<n;++i) {
            for(int j=0;j<n;++j) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
