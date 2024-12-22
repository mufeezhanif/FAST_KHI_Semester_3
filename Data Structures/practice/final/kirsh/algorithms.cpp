#include <iostream>
using namespace std;

int binarySearch(int arr[], int arrsize, int target) {
    int left = 0;
    int right = arrsize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1; 
}

int interpolationSearch(int arr[], int arrsize, int target) {
    int left = 0;
    int right = arrsize - 1;

    while (left <= right && target >= arr[left] && target <= arr[right]) {
        // Avoid division by zero, check if array elements at left and right are the same
        if (arr[left] == arr[right]) {
            if (arr[left] == target) return left;
            else return -1;
        }

        // Calculate position using the interpolation formula
        int pos = left + ((target - arr[left]) * (right - left) / (arr[right] - arr[left]));

        if (arr[pos] == target) {
            return pos;}
        else if (arr[pos] < target) {
            left = pos + 1;}
        else {
            right = pos - 1;}
    }

    return -1; // If the target is not present in the array
}

int getMax(int arr[], int n) { //finds max
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max; 
}

// Counting sort function to sort the array based on the digit represented by 'place'
void countingSort(int arr[], int n, int place) {
    int *output = new int[n];  // Output array to store sorted elements
    int count[10] = {0};  // Count array to store count of digits (0-9)

    // Count the occurrences of each digit
    for (int i = 0; i < n; i++) {
        count[(arr[i] / place) % 10]++;
    }

    for (int i = 1; i < 10; i++) { // Calculate cumulative frequency for stable sorting
        count[i] += count[i - 1];
    }

    // Place the elements in sorted order based on the current digit
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / place) % 10] - 1] = arr[i];
        count[(arr[i] / place) % 10]--;
    }

    // Copy the sorted elements into the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);  // Find the maximum element in the array

    // Apply counting sort to sort elements based on place value
    for (int place = 1; max / place > 0; place *= 10) {
        countingSort(arr, n, place);
    }
}

int main(){
    const int arrsize = 5;
    int arr[arrsize] = {1,90, 3, 7, 4};
    bool noSwaps;

    //bubble sort
    for (int i = 0; i < arrsize - 1; i++) {
        noSwaps = true;
        for (int j = 0; j < arrsize - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                noSwaps = false; 
            }
        }
        if (noSwaps) {break;}
    }

    for (int k = 0; k < arrsize; k++) {
        cout << arr[k] << " "; 
    }
    cout << endl;


    //selection sort: finds minimum from whole remaining array and bring to front at every iteration
    for (int i = 0; i < arrsize - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < arrsize; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];  //swapping the found minimum element with the element at index i
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    for (int k = 0; k < arrsize; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;

    //insertion sort: compares 2 elements at a time and swaps 
    for (int i = 1; i < arrsize; i++) {
        int key = arr[i];
        int j = i - 1;

        //move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    for (int k = 0; k < arrsize; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;


    int result = binarySearch(arr, arrsize, 7);

    if (result != -1) {
        cout << "Element 7"  << " found at index " << result << endl;} 
    else {
        cout << "Element 7"  << " not found in the array" << endl;}

    result = interpolationSearch(arr, arrsize, 90);

    if (result != -1) {
        cout << "Element 90" << " found at index " << result << endl;} 
    else {
        cout << "Element 90" << " not found in the array" << endl;}

    int arr1[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    radixSort(arr1, n);

    cout << "\nAfter applying Radix sort, the array elements are: " << endl;
    for (int k = 0; k < n; k++) {
            cout << arr1[k] << " ";
    }
    cout << endl;

    return 0;
}
