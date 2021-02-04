#include <iostream>
using namespace std;

int main()
{
  int a = 1, b = 0;
  try
  {
    a = a/b;
  }
  catch(...) {cout << "exception!" << endl;}
  cout << "hello!" << endl;
  return 0;
}


