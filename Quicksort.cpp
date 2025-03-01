#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

void quickSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int pivot = arr[left], i = left, j = right;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j) swap(arr[i++], arr[j--]);
    }

    quickSort(arr, left, j);
    quickSort(arr, i, right);
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
        quickSort(v, 0, v.size() - 1);
        auto end = high_resolution_clock::now();
        
        auto duration = duration_cast<milliseconds>(end - start).count();
        cout << "Thoi gian thuc thi file "<<file_name<<": " << duration << " ms" << endl;
    }
    return 0;
}
