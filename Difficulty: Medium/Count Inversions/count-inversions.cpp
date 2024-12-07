//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    void merge(vector<int> &arr, int L, int R, int m, int &count, vector<int> &temp) {
        int i = L, j = m + 1, k = L;

        // Merge two sorted halves into the temporary array
        while (i <= m && j <= R) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                count += (m - i + 1); // Count inversions
            }
        }

        // Copy remaining elements from the left subarray
        while (i <= m) {
            temp[k++] = arr[i++];
        }

        // Copy remaining elements from the right subarray
        while (j <= R) {
            temp[k++] = arr[j++];
        }

        // Copy merged elements back into the original array
        for (int p = L; p <= R; p++) {
            arr[p] = temp[p];
        }
    }

    void mergeSort(vector<int> &arr, int L, int R, int &count, vector<int> &temp) {
        if (L < R) {
            int m = L + (R - L) / 2;

            // Sort the left and right halves
            mergeSort(arr, L, m, count, temp);
            mergeSort(arr, m + 1, R, count, temp);

            // Merge the sorted halves
            merge(arr, L, R, m, count, temp);
        }
    }

    int inversionCount(vector<int> &arr) {
        int count = 0;
        int n = arr.size();
        vector<int> temp(n); // Temporary array for merging
        mergeSort(arr, 0, n - 1, count, temp);
        return count;
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends