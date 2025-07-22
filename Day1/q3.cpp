/*
1.3 Aim of the program: Write a program to read ‘n’ integers from a disc file that must contain
some duplicate values and store them into an array. Perform the following operations on the
array.

a) Find out the total number of duplicate elements.
b) Find out the most repeating element in the array.
*/



#include<bits/stdc++.h>

using namespace std ;

int main(){ ;

  int n ; 
  cin>>n ; 

  vector<int>v(n) ; 
  unordered_map<int , int>mpp ; 

  for(int i = 0; i < n ; i++){
    cin>>v[i] ; 
  }

  for(auto x : v) {
    mpp[x]++ ; 
  }

  int duplicates = 0;
  int most_frequent_ele =0 ; 
  int mx = 0; 
  
  for(auto it : mpp) {
    if(it.second > 1 ){
      duplicates++ ; 
    }
    if(it.second > mx) {
      mx = it.second ; 
      most_frequent_ele = it.first ; 
    }
  }

  cout<<"Input array is "<<endl ; 

 for(auto x : v){
  cout<<x<<" " ; 
 }
 cout<<endl ;

  cout<<"The number of duplicates are: " ; 
  cout<<duplicates<<endl ;
  cout<<"The most frequent duplicate element is: " ;
  cout<<most_frequent_ele<<endl ; 



return 0 ;
}