#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct ITEM {
    int item_id;
    double item_profit;
    double item_weight;
    double profit_weight_ratio;
};

bool compare(ITEM a, ITEM b) {
    return a.profit_weight_ratio > b.profit_weight_ratio;
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<ITEM> items(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter the profit and weight of item no " << i + 1 << ": ";
        cin >> items[i].item_profit >> items[i].item_weight;
        items[i].item_id = i + 1;
        items[i].profit_weight_ratio = items[i].item_profit / items[i].item_weight;
    }

    double capacity;
    cout << "Enter the capacity of knapsack: ";
    cin >> capacity;

    sort(items.begin(), items.end(), compare);

    double total_profit = 0, remaining_capacity = capacity;

    cout << "\nItem No\tprofit\t\tWeight\t\tAmount to be taken\n";

    cout << fixed << setprecision(6);

    for (int i = 0; i < n; i++) {
        if (items[i].item_weight <= remaining_capacity) {
            remaining_capacity -= items[i].item_weight;
            total_profit += items[i].item_profit;
            cout << items[i].item_id << "\t" << items[i].item_profit
                 << "\t\t" << items[i].item_weight << "\t\t1.000000\n";
        } else {
            double fraction = remaining_capacity / items[i].item_weight;
            total_profit += items[i].item_profit * fraction;
            cout << items[i].item_id << "\t" << items[i].item_profit
                 << "\t\t" << items[i].item_weight << "\t\t" << fraction << "\n";
            remaining_capacity = 0;
            break;
        }
    }

    cout << "\nMaximum profit: " << total_profit << endl;
    return 0;
}