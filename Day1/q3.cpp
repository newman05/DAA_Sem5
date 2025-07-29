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





/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decToBinary(int n, char *binary, int index) {
    if (index < 0) return;
    binary[index] = (n % 2) + '0';
    decToBinary(n / 2, binary, index - 1);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <n> <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    FILE *fin = fopen(argv[2], "r");
    FILE *fout = fopen(argv[3], "w");

    if (fin == NULL || fout == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int num, count = 0;
    while (count < n && fscanf(fin, "%d", &num) == 1) {
        char binary[17]; // 16 bits + null terminator
        binary[16] = '\0';
        decToBinary(num, binary, 15);

        fprintf(fout, "The binary equivalent of %d is %s\n", num, binary);
        count++;
    }

    fclose(fin);
    fclose(fout);

    // Reopen output file to display
    fout = fopen(argv[3], "r");
    if (fout == NULL) {
        printf("Error reading output file.\n");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), fout)) {
        printf("%s", line);
    }

    fclose(fout);
    return 0;
}
*/