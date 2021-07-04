#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> productArray(vector<int> arr)
{

    //Create an output Array
    int n = arr.size();
    vector<int> output(n, 1);

    //update the output array and return
    //complete the code
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    left[0] = arr[0];
    right[n - 1] = arr[n - 1];

    for (int i = 1; i < n; i++)
    {
        left[i] = left[i - 1] * arr[i];
        right[n - 1 - i] = right[n - i] * arr[n - 1 - i];
    }
    output[0] = right[1];
    output[n - 1] = left[n - 2];
    for (int i = 1; i < n - 1; i++)
    {
        output[i] = left[i - 1] * right[i + 1];
    }

    return output;
}

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    // unordered_set<int> s;
    // s.insert(1);
    // s.insert(2);
    // s.insert(3);

    // cout << (s.find(5) == s.end()) << endl;
    vector<pair<int, int>> activities{{7, 9}, {0, 10}, {4, 5}, {8, 9}, {4, 10}, {5, 7}};

    sort(activities.begin(), activities.end(), compare);

    for (auto x : activities)
    {
        cout << x.first << "," << x.second << endl;
    }
}