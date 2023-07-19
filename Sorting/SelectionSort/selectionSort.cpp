#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n-1; ++i) {
        int minIndex = i;
        for(int j = i + 1; j < n; ++j) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
int main() {
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    vector<int> arr(size);
    cout<<"Enter the elements: ";
    for(int i = 0; i < size; ++i) {
        cin>>arr[i];
    }
    selectionSort(arr);
    cout<<"Sorted array: ";
    for(int num:arr) {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
