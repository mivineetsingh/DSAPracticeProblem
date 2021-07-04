#include <iostream>
#include <vector>

using namespace std;

int highest_mountain(vector<int> arr)
{
    // O(n)
    int largest = 0;
    int n = arr.size();
    for (int i = 1; i <= n - 2;) // 1 can be peak and n-2 can be peak
    {
        // 1. Check if it's a peak or not
        if (arr[i] > arr[i - 1] and arr[i] > arr[i + 1])
        {
            // 2. Proceed only if it's a peak

            int count = 1;
            int j = i;

            // Backward
            while (j >= 1 and arr[j] > arr[j - 1])
            {
                count++;
                j--;
            }

            //Forward
            while (i <= n - 2 and arr[i] > arr[i + 1])
            {
                count++;
                i++;
            }

            largest = max(largest, count);
        }
        else
            i++;
    }
    return largest;
}

int main()
{
    vector<int> arr{5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};
    cout << highest_mountain(arr);
}
