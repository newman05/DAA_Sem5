/*
1.2 Aim of the program: Given an array arr[] of size N, find the prefix sum of the array. A prefix
sum array is another array prefixSum[] of the same size, such that the value of prefixSum[i] is
arr[0] + arr[1] + arr[2] . . . arr[i].
*/



#include<bits/stdc++.h>

using namespace std ;

int main(){ ;

 int n ;
 cin>>n ; 

 vector<int>v(n); 
 for(int i = 0; i < n ; i++) {
  cin>>v[i] ; 
 }

 vector<int>pf(n) ;
 pf[0] = v[0]; 
 for (int i = 1; i < n; i++) {
  pf[i] = pf[i - 1] + v[i];
 }

 cout<<"Input array is "<<endl ; 

 for(auto x : v){
  cout<<x<<" " ; 
 }
 cout<<endl ; 

   cout<<"Output array is "<<endl ; 
 for(auto x : pf) {
  cout<<x<<" " ; 
 }
 cout<<endl ;

 



return 0 ;
}