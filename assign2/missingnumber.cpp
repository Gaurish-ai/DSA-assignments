#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    for (int i = 1; i < n; i++) {
        if (nums[i] != nums[i - 1] + 1) {
            cout << "Missing number: " << nums[i - 1] + 1 << endl;
            return 0;
        }
    }

    cout << "No missing number found" << endl;
    return 0;
}
