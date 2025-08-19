

#include<bits/stdc++.h>

#define ll long long
#define nline '\n' 
#define FOR vector<int>v(n) ;for(int i = 0 ;i < n ; i++) cin>>v[i];
#define nv int n ; cin>>n ; 
#define sot sort(v.begin() , v.end()) ;
#define tos sort(v.begin() , v.end() , greater<int>()) ;
#define pfs vector<int>pf(n) ;pf[0] = v[0]; for (int i = 1; i < n; i++) pf[i] = pf[i - 1] + v[i];
#define stt  set<int>st ; st.insert(v.begin() , v.end());
#define pb push_back
#define SUM  long long vsum = accumulate(v.begin(), v.end(), 0LL);
#define kcod ios_base::sync_with_stdio(false); cin.tie(NULL);
#define co cout<<
#define ed <<endl ;
#define INF 1000000000000000000LL
#define freqmap  unordered_map<int , int> mpp ; for(int i = 0 ; i < n ; i++) mpp[v[i]]++ ;
// conc // string str = string(1 , s[i]) + s[i + 1] + s[i + 2] + s[i + 3] + 
// overflow // int mid = l + (r - l) / 2;
const ll mod = 1e9 + 7;
 
using namespace std ;

int main(){ ;

kcod


nv
FOR
// stt
// int cnt = 0 ; 
// co st.size() ed
// for(auto it : st) {
//   cout<<it<<" " ; 
// }
// cout<<nline ; 

sot

int curr = v[0] ; 
int cnt = 1; 
vector<int>res ; 
res.pb(v[0]) ; 
int maxi = 0 ; 
int mx =0  ;
int ok = 1 ; 
for(int i = 1 ; i < n ; i++) {
  if(v[i] == curr) {
    ok++ ; 
    // co "why" ed 
  }
  else {
    curr = v[i] ;
    if(ok >= maxi ) {
            // co "HI" ed
            // co maxi ed 
            // co ok ed 

        maxi = ok ;
      mx = v[i - 1] ; 
      
    } 
    ok = 1 ;
    res.pb(curr) ; 
    cnt++ ;  
  }
}

   if(ok >= maxi ) {
            // co "HI" ed
            // co maxi ed 
            // co ok ed 

        maxi = ok ;
      mx = v[n - 1] ; 
      
    } 

co mx ed 

co cnt ed 

for(auto x : res){
  cout<<x<<" " ; 
}
cout<<nline ; 

return 0 ;
}