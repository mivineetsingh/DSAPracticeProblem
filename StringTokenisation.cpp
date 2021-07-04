// "today is a sunny day" -> delimited by space -> "today","is","a","sunny","day"
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    string input;
    getline(cin, input);

    // Method 1 - StringStream class
    stringstream buffer(input);
    string token;
    vector<string> tokens;
    while (getline(buffer, token, ' '))
    {
        tokens.push_back(token);
    }
}