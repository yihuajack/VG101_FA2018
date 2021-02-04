#include <iostream>
#include <memory>
using namespace std;

int main()
{
  shared_ptr<int> p = make_shared<int>(5);
  shared_ptr<int> q = p;
  cout << "*p = " << *p << endl;
  cout << "*q = " << *q << endl;
  return 0;
}

