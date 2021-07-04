#include <iostream>
#include <vector>

using namespace std;

bool OutOfOrder(vector<int> arr, int i)
{
    int n = arr.size();
    if (i == 0)
        return arr[0] > arr[1];
    if (i == n - 1)
        return arr[i] < arr[i - 1];
    return arr[i] > arr[i + 1] or arr[i] < arr[i - 1];
}

vector<int> SubArraySort(vector<int> arr)
{
    vector<int> result;
    int n = arr.size();

    vector<int> tempArr(arr);
    std::sort(tempArr.begin(), tempArr.end());

    // Comparison from left to right
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != tempArr[i])
        {
            result.push_back(i);
            break;
        }
    }
    // Comparison from right to left
    for (int i = n; i > 0; i--)
    {
        if (arr[i] != tempArr[i])
        {
            result.push_back(i);
            break;
        }
    }
    return result;
}

pair<int, int> SubArraySortOptimised(vector<int> arr)
{
    int smallest = INT_MAX;
    int largest = INT_MIN;

    int n = arr.size();

    // find the smallest and largest number out of order
    for (int i = 0; i < n; i++)
    {
        if (OutOfOrder(arr, i))
        {
            smallest = min(smallest, arr[i]);
            largest = max(largest, arr[i]);
        }
    }

    // If they are already sorted all number will be in correct position
    if (smallest == INT_MAX)
        return {-1, -1};

    // find where they can be placed
    int left = 0;
    int right = n - 1;

    while (smallest >= arr[left])
        left++;
    while (largest <= arr[right])
        right--;

    return {left, right};
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
    auto p = SubArraySortOptimised(arr);
    cout << p.first << "," << p.second;
}