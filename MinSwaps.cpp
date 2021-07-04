#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minSwaps(vector<int> arr)
{
    // Know the actual position of elements and store its current position
    int n = arr.size();
    pair<int, int> a[n];

    for (int i = 0; i < n; i++)
    {
        a[i].first = arr[i];
        a[i].second = i;
    }
}

int main()
{
    vector<int> arr{5, 4, 3, 2, 1};
    cout << minSwaps(arr) << endl;
}