/*5.1 Aim of the program: Write a program to find the maximum profit nearest to but not
exceeding the given knapsack capacity using the Fractional Knapsack algorithm.
Notes# Declare a structure ITEM having data members item_id, item_profit, item_weight and
profit_weight_ratio. Apply heap sort technique to sort the items in non-increasing order,
according to their profit /weight.*/

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
using namespace std;

struct ITEM {
    int item_id;
    double item_profit;
    double item_weight;
    double profit_weight_ratio;
};

bool compare_a_b(ITEM a, ITEM b) {
    return a.profit_weight_ratio > b.profit_weight_ratio;
}

int main() {
    
    cout<<"Enter the number of items: ";
    nv
    

    vector<ITEM> items(n);
    for (int i = 0; i < n; i++) {
        cout<<"Enter the profit and weight of item no "<<i + 1<<": ";
        cin>>items[i].item_profit>>items[i].item_weight;
        items[i].item_id = i + 1;
        items[i].profit_weight_ratio = (items[i].item_profit / items[i].item_weight);
    }

    double capacity;
    cout<<"Enter the capacity of knapsack: ";
    cin>>capacity;

    sort(items.begin(), items.end(), compare_a_b);

    double total_profit = 0, remaining_capacity = capacity;

    cout<<"\nItem No\tprofit\t\tWeight\t\tAmount to be taken\n";

    cout<<fixed<<setprecision(6);

    for (int i = 0; i < n; i++) {
        if (items[i].item_weight <= remaining_capacity) {
            remaining_capacity -= items[i].item_weight;
            total_profit += items[i].item_profit;
            cout<<items[i].item_id<<"\t"<<items[i].item_profit<<"\t\t"<<items[i].item_weight<<"\t\t1.000000\n";
        } 
        else {
            double fraction = remaining_capacity / items[i].item_weight;
            total_profit += items[i].item_profit * fraction;
            cout<<items[i].item_id<<"\t"<<items[i].item_profit<<"\t\t"<<items[i].item_weight<<"\t\t"<<fraction<<"\n";
            remaining_capacity = 0;
            break; 
        }
    }
    cout<<endl ; 
    cout<<"Maximum profit: "<<total_profit<<endl;
    return 0;
}