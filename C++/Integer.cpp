#include <iostream>
using namespace std;
class Integer{
	int i;
	public:
	Integer() : i(0) {}
	Integer(int ii) : i(ii) {}
	int get() { return i; }
	const Integer
	operator+(const Integer& rv) const{
		return Integer(i+ rv.i);
	}
};
int main(){
	Integer ii(1), jj(2), kk;
	kk= ii + jj;
	cout<< "kk= " << kk.get() << endl;
}