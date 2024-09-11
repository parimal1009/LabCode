#include <iostream>

using namespace std;

int linearsearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {  // Correct comparison
            return i;         // Return index where key is found
        }
    }
    return -1;  // Return -1 if key is not found
}

int main() {
    int n;
    cout << "Enter the number of elements: " << endl;
    cin >> n;
    
    int arr[n];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the key to search: " << endl;
    cin >> key;

    int result = linearsearch(arr, n, key);
    cout << "Result is " << result << endl;

    if (result != -1) {  // Check if key was found
        cout << "Found at index " << result << endl;
    } else {
        cout << "Result not found" << endl;
    }

    return 0;
}
