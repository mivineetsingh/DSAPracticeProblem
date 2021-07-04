#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> tripletsBruteForce(vector<int> arr, int sum)
{
    vector<vector<int>> result;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i+1; j < arr.size(); j++)
        {
            for (int k = j+1; k < arr.size(); k++)
            {
                if (arr[i] + arr[j] + arr[k] == sum)
                {
                    result.push_back({ arr[i],arr[j],arr[k] });
                }
            }
        }
    }
    return result;
}

vector<int> pairSumTwoPointer(vector<int> arr,int sum)
{
    vector<int> result;
    int start = 0;
    int end = arr.size() - 1;
    while (start < end)
    {
        if (arr[start] + arr[end] == sum)
        {
            result.push_back(arr[start]);
            result.push_back(arr[end]);
            return result;
        }
        else if (arr[start] + arr[end] < sum) start += 1;
        else end -= 1;
    }
}

vector<vector<int>> tripletsOptimised(vector<int> arr, int sum)
{
    vector<vector<int>> result;
    int n = arr.size();
    // 1. Sort the array
    std::sort(arr.begin(), arr.end());
    // 2. Pick a[i], solve pair some problem for remaining
    for (int i = 0; i <= n - 3; i++)
    {
        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            int reqSum = sum - arr[i];
            if (arr[j] + arr[k] == reqSum)
            {
                result.push_back({ arr[i],arr[j],arr[k] });
                j += 1;
                k -= 1;
            }
            else if (arr[j] + arr[k] < reqSum) j += 1;
            else k -= 1;

        }
    }
    
    return result;
}

int main()
{
    vector<int> arr = { 1,2,3,4,5,6,7,8,9,15 };
    int sum = 18;
    for (auto x : tripletsOptimised(arr, sum))
    {
        for (auto y : x)
        {
            cout << y << ",";
        }
        cout << endl;
    }
    getchar();
}