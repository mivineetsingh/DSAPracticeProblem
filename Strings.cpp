#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s; // A dynamic array -> Size can be changed at run time

    s = "Vineet";
    s.append("S"); // Size can be changed

    string s1("Vineet"); // Calling a constructor to have string

    getline(cin, s); // takes input till new line and assigns to s

    getline(cin, s, "."); //takes input till it finds .

    string para("Hello I am a parapgraph am");
    cout << para.find("am") << endl;    // Returns the first occurence of "am", if not present returns very large val
    size_t index = para.find("State");  // as size_t is unsigned so index becomes -1
    index = para.find("am", index + 1); // finds the next index
    if (index == -1)
    {
        cout << "String not found" << endl;
    }

    cout << s << endl;
}