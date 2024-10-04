#include <iostream>
#include <vector>
#include <thread>
using namespace std;

void merge(int left, int mid, int right, vector<int> &arr)
{
    // Initialize pointers to left part and right part of array
    int i = left;
    int j = mid + 1;
    int k = 0;

    // Intiliaze result array for storing sorted arary
    vector<int> result(right - left + 1);

    // Append elements in sorted manner
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            result[k] = arr[i];
            i++;
        }
        else
        {
            result[k] = arr[j];
            j++;
        }
        k++;
    }

    // Append remainig elements of left part of array
    while (i <= mid)
    {
        result[k] = arr[i];
        i++;
        k++;
    }

    // Append remaining elements of right part of array
    while (j <= right)
    {
        result[k] = arr[j];
        j++;
        k++;
    }

    // Update original array
    for (int temp = 0; temp < k; temp++)
    {
        arr[left + temp] = result[temp];
    }

    return;
}

const int THRESHOLD = 100; // Threshold for small subarrays

void mergeSort(int left, int right, vector<int> &arr)
{
    // Base Case : Only single element is there, it is already sorted
    if (left >= right)
    {
        return;
    }

    // Calculate mid index for dividing array equally in two parts left and right
    int mid = left + (right - left) / 2;

    if (right - left < THRESHOLD)
    {
        // Sequential sorting for small arrays
        mergeSort(left, mid, arr);
        mergeSort(mid + 1, right, arr);
    }
    else
    {
        // Create two threads for the left and right parts of the array
        thread leftThread(mergeSort, left, mid, ref(arr));
        thread rightThread(mergeSort, mid + 1, right, ref(arr));

        // Wait for both threads to complete before merging
        leftThread.join();
        rightThread.join();
    }

    // Merge sorted left part and right part of array
    merge(left, mid, right, arr);

    return;
}

int main()
{
    // Take array size as input
    int n;
    cin >> n;

    // Initialize array of size taken as input
    vector<int> arr(n);

    // Generate array elements
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % n;
    }

    // Display array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Invoke Merge Sort function for Sorting
    mergeSort(0, n - 1, arr);

    // Display sorted result array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
