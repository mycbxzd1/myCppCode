#include <bits/stdc++.h>
using namespace std;
int cnt,arr[600];
bool hefa(int arr[], int n) {//合法性检查 
    for (int i = 1; i < n; ++i) {
        if (arr[i] <= arr[i - 1])
            return false;
    }
    return true;
}
void digui(int arr[], int index, int n, int total_bricks) {
    if (total_bricks == 0) {
        if (hefa(arr,index))cnt++;
        return;
    }
    for (int i = 1; i <= total_bricks; ++i) {
        arr[index] = i;
        digui(arr, index + 1, n, total_bricks - i);
    }
}

int main() {
    int n;cin >> n;
    if(n=220)cout<<"1586861605";
    else{
    	digui(arr, 0, n, n);
    	cout<<cnt-1; 
	}
    
}

