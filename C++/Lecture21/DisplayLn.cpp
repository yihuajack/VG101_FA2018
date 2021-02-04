#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ifstream in("DisplayLn.cpp");
    string s;
    int n = 0;
    while (getline(in, s))
    {
        n++;
        cout << n << ": " << s << endl;
    }
    return 0;
}
