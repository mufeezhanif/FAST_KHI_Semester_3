#include <bits/stdc++.h>

using namespace std;
class Product
{
public:
    string name;
    double price;
    string description;
    bool isAvailable;
    Product(string name, double price, string description, bool isAvailable) : name(name), price(price), description(description), isAvailable(isAvailable) {}
    Product()
    {
        name = "";
        description = "";
        price = 0;
        isAvailable = false;
    }
};
int partition(Product arr[], int left, int right)
{
    int i = left;
    int j = right;
    double pivot = arr[left].price;
    Product pivotElement = arr[left];
    while (i < j)
    {
        while (arr[i].price <= pivot && i <= right - 1)
        {
            ++i;
        }
        while (arr[j].price > pivot && j >= left - 1)
        {
            --j;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
        cout << "In loop" << endl;
    }
    swap(arr[left], arr[j]);
    return j;
}
void quickSort(Product arr[], int left, int right)
{
    if (left < right)
    {
        cout << "in quick sort" << left << " " << right << endl;
        int partIndex = partition(arr, left, right);
        quickSort(arr, left, partIndex - 1);
        quickSort(arr, partIndex + 1, right);
    }
}
int main()
{
    int n = 3;
    Product arr[n];
    arr[0] = {"Product1", 10.99, "This is product 1", true};
    arr[1] = {"Product2", 5.99, "This is product 2", false};
    arr[2] = {"Product3", 2.99, "This is product 3", true};

    quickSort(arr, 0, n - 1);
    cout << "products sorted by price :" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i].name << " - $" << arr[i].price << endl;
    }
    cout << endl;
    return 0;
}
