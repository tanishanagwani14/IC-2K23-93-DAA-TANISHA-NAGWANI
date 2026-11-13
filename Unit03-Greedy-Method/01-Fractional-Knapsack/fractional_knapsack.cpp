#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Item { int value, weight; };

bool compareRatio(Item a, Item b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

double fractionalKnapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compareRatio);
    double totalValue = 0.0;
    for (const auto& item : items) {
        if (capacity >= item.weight) {
            capacity -= item.weight;
            totalValue += item.value;
        } else {
            totalValue += item.value * ((double)capacity / item.weight);
            break;
        }
    }
    return totalValue;
}

int main() {
    int capacity = 50;
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
    cout << fixed << setprecision(2) << "Max Value = " << fractionalKnapsack(capacity, items) << endl;
    return 0;
}
