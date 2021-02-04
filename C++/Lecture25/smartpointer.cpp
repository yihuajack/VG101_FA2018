#include <iostream>
using namespace std;

template<class T>
class SmartPtr
{
  T *ptr;
public:
  SmartPtr(){ ptr = NULL; } // constructor
  SmartPtr(T *p){ ptr = p; } // constructor
  T& operator*(){ return *ptr; } // operator*
  T* operator->(){ return ptr; } // operator->
  ~SmartPtr() { if (ptr) delete ptr; cout << "delete!" << endl; } // destructor
};

void func(SmartPtr<int>& p)
{
  throw 1;
}

int main()
{
  SmartPtr<int> p(new int);
  SmartPtr<int> q=p;
  *p = 5;
  cout << "*p = " << *p << endl;
  try
  {
    func(p);
    cout << "hello!" << endl;
  }
  catch(...) { cout << "exception!" << endl; }
  return 0;
}
