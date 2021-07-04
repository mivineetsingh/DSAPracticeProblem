#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

bool isPresentBinarySearch(vector<int> arr, int num)
{
    std::sort(arr.begin(), arr.end());
    int start = 0;
    int end = arr.size() - 1;
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == num) return true;
        else if (arr[mid] < num) start = mid + 1;
        else end = mid - 1;
    }
    return false;
}

vector<int> pairSumBruteForce(vector<int> arr, int sum)
{
    // O(n^2)

    vector<int> result;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == sum)
            {
                result.push_back(arr[i]);
                result.push_back(arr[j]);
                return result;
            }
        }
    }
    return result;
}

vector<int> pairSumUsingBinarySearch(vector<int> arr, int sum)
{
    vector<int> result;
    for (int x : arr)
    {
        int reqNum = sum - x;
        if (isPresentBinarySearch(arr,reqNum) && reqNum!=x)
        {
            result.push_back(x);
            result.push_back(reqNum);
            return result;
        }
    }
    return result;
}

vector<int> pairSumOptimised(vector<int> arr, int sum)
{
    vector<int> result;
    unordered_set<int> tempSet;
    for (int x : arr)
    {
        int reqNum = sum - x;
        if (tempSet.find(reqNum) != tempSet.end())
        {
            result.push_back(reqNum);
            result.push_back(x);
            return result;
        }
        else tempSet.insert(x);
    }
    return result;
}

int main()
{
    vector<int> arr = { 10,5,2,3,-6,9,11 };
    int sum = 4;
    for (int x : pairSumOptimised(arr, 4))
    {
        cout << x << endl;
    }

    getchar();
}