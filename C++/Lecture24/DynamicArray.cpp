#include <iostream>
#include <algorithm>
using namespace std;

template<class T>
class DynamicArray
{
    T *p;
    int size;
public:
    DynamicArray() {p = NULL;size=0;}
    DynamicArray(int n) {
        cout << "constructor called!" << endl;
        p = new T[n];
        size = n;
    }
    ~DynamicArray() {
        cout << "destructor called!" << endl;
        if (p!=NULL) delete[]p;
    }
    int& operator[](int i)
    {
        if (i<size) return p[i];
        else return p[0]; // return the 1st element
    }
    T* getDataPtr() // return the data pointer
    {
        return p;
    }
};

int main()
{
    // ask the user to input n
    int i, n;
    cout << "Input n: ";
    cin >> n;
    // create dynamic array with n elements
    DynamicArray<int> arr(n);
    // ask the user to input the elements
    for (i=0; i<n; i++)
    {
        cout << "Input arr[" << i << "]: ";
        cin >> arr[i];
    }
    // sorting
    sort(arr.getDataPtr(), arr.getDataPtr()+n);
    for (i=0; i<n; i++)
        cout << "arr[" << i << "]=" << arr[i] << endl;
    return 0;
}
