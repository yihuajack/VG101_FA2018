#include <iostream>
using namespace std;

int main()
{
  try
  {
    int a;
    cin >> a;
    if (a == 0) throw 10;
    else if (a == 1) throw 'a';
    else throw 1.1;
  }
  catch (int e) { cout << "int exception: " << e << endl; }
  catch (char ch) { cout << "char exception: " << ch << endl; }
  catch (...) { cout << "default exception" << endl; }
  return 0;
}

