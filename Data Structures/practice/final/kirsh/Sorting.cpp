#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
//Selection Sort  
void selection_sort(int *arr , int n){

    for(int i = 0  ; i< n-1 ; i++){
        int minInd = i;

        for(int j = i+1 ; j<n ; j++)
        { 
            if(arr[j] < arr[minInd]){
                minInd = j;
            }
        }
        swap(arr[minInd] , arr[i]);
    }
}


//BUBBLE SORT
void Bubble_sort(int *arr , int n){
    bool swapped ;
    for(int i = 0 ; i<n-1 ; i++)
    {     
        swapped = false;

        for(int j = 0 ; j< n-i-1 ; j++)
        {
            if(arr[j] > arr[j+1])
            swap(arr[j] , arr[j+1]);
            swapped = true;
        }

        if(!swapped) break;
    }
}

//We can optmize thw bubble sort by placing  flag to check if the array is already sorted then we just break the loops and return



//INSERTION SORT -> compares 2 elements at a time and swaps 
void insertion_sort(int*arr , int n){
    for(int i = 1 ; i<n ; i++)
    {
        int key = arr[i];
        int  j = i-1;
        
//move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while(j >=0 && arr[j] > key){
           arr[j+1] =  arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

//MERGE SORT
// with VECTOR
void merge(vector<int>&arr , int low , int mid , int high){
    vector<int>temp;
    int left = low;
    int right = mid+1;

    while(left <= mid    && right <= high){
          if(arr[left] <= arr[right]){
                    temp.push_back(arr[left]);
                    left++;
          }
          else{
            temp.push_back(arr[right]);
            right++;
          }
    }

   while(left <= mid){
       temp.push_back(arr[left]);
       left++;
    }

    while(right<= high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low ; i<=high ; i++)
    {
        arr[i] = temp[i-low];
    }
}


void merge_sort(vector<int>&arr , int low , int high){   // pass the reference : always
    if(low>=high) return ;

     int mid = (low+high)/2;
    merge_sort(arr , low , mid);
    merge_sort(arr , mid+1 , high);
    merge(arr , low , mid , high);

}

//MERGE SORT WITH ARRAY
void merge(int *arr , int low , int mid  , int high){
    int left = low;
    int right = mid +1;
    int k = 0;

    int *result = new int[high-low + 1];

    while(left <= mid && right <= high){
          if(arr[left] < arr[right]){
            result[k++] = arr[left];
            left++;
          }
          else{
            result[k++] = arr[right];
            right++;
          }
    }

    while( left <= mid){
        result[k++] = arr[left];
            left++;
    }
    while( right <= high){
        result[k++] = arr[right];
        right++;
    }

    for(int i =  low ; i <= high ; i++){
        arr[i] = result[i-low];
    }

   // delete result;
}

void merge_sort(int*arr , int n , int low , int high){
    if(low >= high) 
       return;
    
    int mid = (low + high)/2;
    merge_sort(arr , n , low , mid); // left
    merge_sort(arr , n , mid+1 , high);  //right
    merge(arr ,  low , mid , high);
}


// QUICK SORT
int Partition(vector<int>&arr , int low , int high){
  int i = low;
  int j = high;
  int pivot = arr[low];


  while(i<j){
      while(arr[i] <= pivot && i < high)   // it will move the ith pointer to the position of the first element greater then the pivot
       {
            i++;
       }
      while(arr[j] > pivot  && j > low)   // it will move the jth pointer to the position of the first element lesser then the pivot
       {
            j--;
       }
        if(i<j){
            swap(arr[i] , arr[j]);
        }
  }
    swap(arr[low] , arr[j]); //will put pivot to its correct position

  return j; // pivot index
}


void quick_sort(vector<int>&arr , int low , int high){
    if(low < high){
       int Pt_index = Partition(arr,low,high);
       quick_sort(arr , low , Pt_index-1); // less part
       quick_sort(arr ,  Pt_index+1 , high); // greater part
    }
}
// Shell Sort
//if swapping is done , then compare it with the previous eleemnt  

void shellSort(vector<int>& arr) {
    int N = arr.size();

    for (int gap = N / 2; gap >= 1 ; gap /= 2) {   // Number of Passes 

        for (int i = gap; i < N; i++) {

            for (int j = i-gap; j >= 0; j -= gap) {

                   if(arr[j] > arr[j+gap]){
                    swap(arr[j], arr[j+gap]);
                   }

            }
        }
    }
}

// COUNT SORT
void countSort(int arr[], int n) {
    int k = arr[0];
    for (int i = 1; i < n; i++) {
        k = max(k, arr[i]);
    }

    int* count = new int[k + 1]{0};

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i <= k; i++) {
        count[i] += count[i - 1];
    }


    int* result = new int[n];
    for (int i = n - 1; i >= 0; i--) {
        int val = arr[i];
        count[val]--;
        result[count[val]] = val;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = result[i];
    }

}
// Counting sort based on the digit at position `pos`
void count_radix_sort(int arr[], int n, int pos) {
    
    int count[10] = {0}; // size is 10 because count is an array to "count the frequencies of digist" ->  digits range from 0-9
    for (int i = 0; i < n; i++) {
        int ind = (arr[i] / pos) % 10;
        count[ind]++;
    }

    // Modify 
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }


    int* result = new int[n];
    for (int i = n - 1; i >= 0; i--) {
        int ind = (arr[i] / pos) % 10;
        count[ind]--;
        result[count[ind]] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = result[i];
    }

    delete[] result;
}


void radix_sort(int arr[], int n) {
 
    int k = arr[0];
    for(int i = 1 ; i<n ; i++){
        k = max(k, arr[i]);
    }

    for (int pos = 1; k / pos > 0; pos *= 10) {
        count_radix_sort(arr, n, pos);
    }
}


//INTERPOLATION SEARCH
bool interpolation_search(int arr[] , int arrSize , int key){

      int left = 0;
      int right = arrSize - 1;

      while(left <= right   &&  key >= arr[left]   && key <= arr[right]){
            
            int pos =  left + ((key - arr[left])*(right-left) / (arr[right] - arr[left]));

            if(arr[pos] == key){
                return true;
            }
            else if(arr[pos] < key){
                left = pos + 1;
            }
            else{
                right = pos -1;
            }
      }

      return false;
}

int main() {
    vector<int> arr  = {8,2,7,5,6,7,8,9};
    
      quick_sort(arr , 0 , arr.size()-1);
      for(int i : arr){
        cout << i << " ";
      }
}
