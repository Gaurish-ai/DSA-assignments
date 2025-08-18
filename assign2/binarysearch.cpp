#include <iostream>
using namespace std;

int binarysearch(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            cout << "Element found at index: " << mid << endl;
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else // arr[mid] > target
        {
            right = mid - 1;
        }
    }
    cout << "Element not found" << endl;
    return -1;
}

int main()
{
    int target;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Enter the value to find: ";
    cin >> target;
    int result = binarysearch(arr, size, target);
    cout << "Result: " << result << endl;
    return 0;
}
