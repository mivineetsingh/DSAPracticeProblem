#include <iostream>
#include <string>

using namespace std;

void space20(char *str)
{
    int spaces = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            spaces += 1;
        }
    }
    int idx = strlen(str) + 2 * spaces;
    str[idx] = '\0';

    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            str[idx - 1] = '0';
            str[idx - 2] = '2';
            str[idx - 3] = '%';
            idx -= 3;
        }
        else
        {
            str[idx - 1] = str[i];
            idx--;
        }
    }
}

int main()
{
    char str[10000];
    cin.getline(str, 1000);

    space20(str); // no need to store the value as it's passed by address

    cout << str << endl;
}