#include <iostream>
#include <vector>

using namespace std;

int Rain(vector<int> arr)
{
    // We calculate the height of water each col can store
    // for that min(L[i],R[i]) - h[i]
    int result = 0;
    int n = arr.size();
    vector<int> left(n, 0), right(n, 0);

    left[0] = arr[0];
    right[n - 1] = arr[n - 1];

    // Construct 2 vectors of max at each pt left and right -> to avoid computing again at each point
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], arr[i]);
        right[n - 1 - i] = max(right[n - i], arr[n - i - 1]);
    }

    for (int i = 0; i < n; i++)
    {
        result += min(left[i], right[i]) - arr[i];
    }

    return result;
}

int main()
{
    vector<int> arr{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << Rain(arr) << endl;
}