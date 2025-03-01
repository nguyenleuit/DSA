#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

void heapify(vector<int>& arr, int n, int i){

    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr){
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
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
        heapSort(v);
        auto end = high_resolution_clock::now();
        
        auto duration = duration_cast<milliseconds>(end - start).count();
        cout << "Thoi gian thuc thi file "<<file_name<<": " << duration << " ms" << endl;
    }
    return 0;
}
