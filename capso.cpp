#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int BIT[1000001];

void update(int i){
    for(;i<1000001;i+=i&-i){
        BIT[i]++;
    }
}

int get(int i){
    int sum=0;
    for(;i;i-=i&-i) sum+=BIT[i];
    return sum; 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    stack<int> st;
    int a[n+1];
    int ans=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n;i>0;i--){
        if(a[i]%2==0){
            ans+=get(a[i]-1);
            st.push(a[i]);
        }
        else{
            while(!st.empty()){
                update(st.top());
                st.pop();
            }
        }
    }
    cout<<ans;
  return 0;
}