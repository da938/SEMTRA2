#include <bits/stdc++.h>
using namespace std;
 
void arrange(string str)
{
    string w = "";
    for (auto x : str) 
    {
        if (x == ' ')
        {
            cout << w << endl;
            w = "";
        }
        if (x == '\t')
        {
            cout << w << endl;
            w = "";
        }
        else {
            w = w + x;
        }
    }
    cout << w << endl;
}
int main()
{
    string str = "I   like    to  play   cricket";
    arrange(str);
    return 0;
}