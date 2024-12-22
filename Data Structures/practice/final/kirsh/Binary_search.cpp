/*implementing lower and upper bound using binary search

#include<bits/stdc++.h>
using namespace std;


int lower_bound(vector<int>&v , int element){ // in lower bound if element is found then its eindex will be returned if not then one higher index value will be returned
    int l = 0 , h = v.size()-1;
    int ans = v.size();
     
    while(l<=h){
       int mid = l + (h-l)/2;

       if(v[mid] >= element){
        ans = mid;
        h = mid-1;
       }
       else{
        l = mid+1;
       }
}

return ans;

}

int upper_bound(vector<int>&v , int element){ // in upper bound if elemnt is found or not it will return one higher index
    int l = 0 , h = v.size()-1;
    int ans = v.size();
    while(l<=h){
       int mid = l + (h-l)/2;

       if(v[mid] > element){
        ans = mid;
        h = mid-1;
       }
       else{
        l = mid+1;
       }
}

return ans;

}

int main(){
    int n;
    cin >> n;
    
 vector<int>v(n);

 for(int i = 0 ; i<n ; i++){
    cin >> v[i];
 }    

 int element;
 cin >> element;

 cout <<lower_bound(v , element) << endl;
 cout <<upper_bound(v , element) << endl;
}


*/


/* FIND PIVOT OF THE ELEMNT 


input = [7,9,1,2,3]
output = 2

input = [2,8,9,10,1]
output = 1;



#include<bits/stdc++.h>
using namespace std;


int getPivot(vector<int>&v){
    int s = 0;
    int e = v.size()-1;

    while(s<e){
        int mid = s + (e-s)/2;
        if(v[mid] >= v[0]){
            s = mid+1;
        }
        else{
            e = mid;
        }
    }

    return s;// return e;
}

int main(){
    vector<int> v= {7,9,1,2,3};
    cout << "PIVOT : " <<getPivot(v) << endl;
}

*/

/* Search in a rotated Array


APPROACH-1
int s = 0;
    int e = nums.size() - 1;

    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (nums[mid] == target) {
            return mid;
        }  
        if (nums[s] <= nums[mid]) {
            if (nums[s] <= target && target < nums[mid]) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        } else {
            if (nums[mid] < target && target <= nums[e]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
    }

        return -1;
        
    

    APPROACH-2

#include<bits/stdc++.h>
using namespace std;

int getPivot(vector<int>&v){
    int s = 0;
    int e = v.size()-1;

    while(s<e){
        int mid = s + (e-s)/2;
        if(v[mid] >= v[0]){
            s = mid+1;
        }
        else{
            e = mid;
        }
    }

    return s;// return e;
}


int BinarySearch(vector<int>&arr , int start , int end , int target){
   
   int s = start;
   int e = end;

   while(s <= e){
     int mid = s + (e-s)/2;

     if(arr[mid] == target)
     {
        return mid;
     }

     else if( arr[mid] < target)
     {
        s = mid+1;
     }
     else
     {
        e = mid-1;
     }
   }

   return -1;    // not found;
 }

int findPosition(vector<int>&arr ,int n, int k){
   int pivot = getPivot(arr);
   if(k >= arr[pivot]  && k <= arr[n-1])
   {
   return BinarySearch(arr , pivot , n-1 , k);
   }
   else{
      return BinarySearch(arr , 0 , pivot-1 , k);
   }

   return -1;

}



int main(){
  vector<int> v = {7,9,1,2,3};
  cout << findPosition(v , 5 , 7);


}

*/
