#include <iostream>
#include <memory>
using namespace std;

int main()
{
  unique_ptr<int> p(new int(5));
  unique_ptr<int> q = p;
  cout << "*p = " << *p << endl;
  return 0;
}

