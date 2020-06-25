#include <bits/stdc++.h>

using namespace std;

int binarySearch(int X, vector <int> array1){
    int left=0;
    int right=array1.size()-1;

    while(left <= right){
        int mid = int((left+right)/2);

        if(array1[mid] == X){
            return mid;
        }else if(array1[mid] < X){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector <int> numbers(n);

    for(int i=0; i<n; i++){
        cin >> numbers[i];
    }

    int x;
    cin >> x;

    int index = binarySearch(x,numbers);

    if(index == -1){
        cout << "No, you didn't find\n";
    }else{
        cout << "Yes, you found!\n";
    }

    return 0;
}