#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

void merge(vector<int>& arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}


int main(){
    freopen("output.txt", "w", stdout); 

    vector<string> input_files = {"Test_1.txt", "Test_2.txt", "Test_3.txt", "Test_4.txt", "Test_5.txt", "Test_6.txt", "Test_7.txt", "Test_8.txt", "Test_9.txt", "Test_10.txt", };
    for (const string& file_name : input_files){
        freopen(file_name.c_str(), "r", stdin);
        vector<int> v;
        int n=1e6;
        for(int i = 1; i <= n; i++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        cout<<endl;
        auto start = high_resolution_clock::now();
        mergeSort(v,0,v.size()-1);
        auto end = high_resolution_clock::now();
        
        auto duration = duration_cast<milliseconds>(end - start).count();
        cout << "Thoi gian thuc thi file "<<file_name<<": " << duration << " ms" << endl;
    }
    return 0;
}
