#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int LongestBand(vector<int> arr)
{
    // O(NlogN)
    int result = 0;
    int currCount = 1;
    int maxCount = 0;

    std::sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i + 1] - arr[i] == 1)
        {
            currCount += 1;
        }
        else
        {
            currCount = 0;
        }
        maxCount = max(currCount, maxCount);
    }
    return maxCount;
}
int LongestBandOptimised(vector<int> arr)
{
    int lenOfLargestBand = 1;
    int n = arr.size();
    unordered_set<int> tempArr(arr.begin(), arr.end());

    for (auto element : arr)
    {
        int head = element - 1;
        if (tempArr.find(head) == tempArr.end())
        {
            // Head doesn't exists (means that element is only the head) -> find length of chain starting form the curr element

            int nextNum = element + 1;
            int count = 1;

            while (tempArr.find(nextNum) != tempArr.end())
            {
                // Till the next num exists
                nextNum++;
                count++;
            }

            lenOfLargestBand = max(count, lenOfLargestBand);
        }
    }
    return lenOfLargestBand;
}

int main()
{
    vector<int> arr{1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};
    cout << LongestBandOptimised(arr) << endl;
}