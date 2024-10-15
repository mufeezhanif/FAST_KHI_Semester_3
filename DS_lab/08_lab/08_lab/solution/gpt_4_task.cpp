#include <iostream>
#include <string>

using namespace std;

class Product {
public:
    string name;
    double price;
    string description;
    bool isAvailable;

    Product(string name, double price, string description, bool isAvailable) 
        : name(name), price(price), description(description), isAvailable(isAvailable) {}

    Product() : name(""), description(""), price(0), isAvailable(false) {}
};

int partition(Product arr[], int left, int right) {
    double pivot = arr[left].price; // Use the leftmost element as pivot
    int i = left + 1; // Start scanning from the next element

    for (int j = left + 1; j <= right; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j].price <= pivot) {
            swap(arr[i], arr[j]); // Swap elements
            i++; // Increment index of the smaller element
        }
    }
    swap(arr[left], arr[i - 1]); // Place the pivot in the correct position
    return i - 1; // Return the partition index
}

void quickSort(Product arr[], int left, int right) {
    if (left < right) {
        int partIndex = partition(arr, left, right);
        quickSort(arr, left, partIndex - 1);
        quickSort(arr, partIndex + 1, right);
    }
}

int main() {
    int n = 3;
    Product arr[n];
    arr[0] = {"Product1", 10.99, "This is product 1", true};
    arr[1] = {"Product2", 5.99, "This is product 2", false};
    arr[2] = {"Product3", 2.99, "This is product 3", true};

    quickSort(arr, 0, n - 1);
    cout << "Products sorted by price:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << arr[i].name << " - $" << arr[i].price << endl;
    }
    return 0;
}
