#include <bits/stdc++.h>
using namespace std;

struct person {
    int id;
    string name;
    int age;
    int height;
    int weight; // in pounds
};

// ---------- Global Heaps ----------
vector<person> people;   // main storage
vector<person> minHeap;  // heap by age
vector<person> maxHeap;  // heap by weight

// ---------- Heap Comparators ----------
bool cmpMin(const person& a, const person& b) {
    return a.age > b.age;   // min-heap by age
}
bool cmpMax(const person& a, const person& b) {
    return a.weight < b.weight; // max-heap by weight
}

void createMinHeap() {
    minHeap = people;
    make_heap(minHeap.begin(), minHeap.end(), cmpMin);
    cout << "✅ Min-heap created based on age.\n";
}

void createMaxHeap() {
    maxHeap = people;
    make_heap(maxHeap.begin(), maxHeap.end(), cmpMax);
    cout << "✅ Max-heap created based on weight.\n";
}

void displayWeightOfYoungest() {
    if(minHeap.empty()) {
        cout << "⚠ Min-heap is empty. Create it first.\n";
        return;
    }
    person youngest = minHeap.front();
    double weightKg = youngest.weight * 0.453592; // pounds → kg
    cout << "Weight of youngest student: "
         << fixed << setprecision(2) << weightKg << " kg\n";
}

void insertPersonMinHeap(const person& p) {
    minHeap.push_back(p);
    push_heap(minHeap.begin(), minHeap.end(), cmpMin);
    cout << "✅ Inserted person " << p.name << " into min-heap.\n";
}

void deleteOldestPerson() {
    if(minHeap.empty()) {
        cout << "⚠ Heap empty.\n";
        return;
    }
    // find person with maximum age
    auto it = max_element(minHeap.begin(), minHeap.end(),
                          [](const person& a, const person& b){
                              return a.age < b.age;
                          });

    cout << "🗑 Deleting oldest person: " << it->name
         << " (Age: " << it->age << ")\n";

    minHeap.erase(it);
    make_heap(minHeap.begin(), minHeap.end(), cmpMin);
}

void displayPeople() {
    cout << "Id  Name             Age Height Weight\n";
    for(auto &p : people) {
        cout << p.id << "   " << setw(12) << left << p.name
             << " " << p.age << "   " << p.height
             << "   " << p.weight << "\n";
    }
}

// ---------- Main Menu ----------
int main() {
    int choice;

    while(true) {
        cout << "\nMAIN MENU (HEAP)\n";
        cout << "1. Read Data\n";
        cout << "2. Create a Min-heap based on the age\n";
        cout << "3. Create a Max-heap based on the weight\n";
        cout << "4. Display weight of the youngest person\n";
        cout << "5. Insert a new person into the Min-heap\n";
        cout << "6. Delete the oldest person\n";
        cout << "7. Exit\n";
        cout << "Enter option: ";
        cin >> choice;

        if(choice == 1) {
            int n;
            cout << "Enter number of students: ";
            cin >> n;
            people.clear();
            for(int i=0; i<n; i++) {
                person p;
                cout << "Enter Id Name Age Height Weight: ";
                cin >> p.id >> ws;
                string first, last;
                cin >> first >> last >> p.age >> p.height >> p.weight;
                p.name = first + " " + last;
                people.push_back(p);
            }
            cout << "\n✅ Data successfully read.\n";
            displayPeople();
        }
        else if(choice == 2) {
            createMinHeap();
        }
        else if(choice == 3) {
            createMaxHeap();
        }
        else if(choice == 4) {
            displayWeightOfYoungest();
        }
        else if(choice == 5) {
            person p;
            cout << "Enter Id Name Age Height Weight: ";
            cin >> p.id >> ws;
            string first, last;
            cin >> first >> last >> p.age >> p.height >> p.weight;
            p.name = first + " " + last;
            insertPersonMinHeap(p);
            people.push_back(p);
        }
        else if(choice == 6) {
            deleteOldestPerson();
        }
        else if(choice == 7) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "⚠ Invalid choice.\n";
        }
    }
    return 0;
}
