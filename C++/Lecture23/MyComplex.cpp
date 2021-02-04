// if using g++, please use c++11 as
// g++ -std=c++11 MyComplex.cpp
// so that stod can be used

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

class MyComplex
{
	double real, imag;
public:
	// constructors
	MyComplex() {real = imag = 0;}
	MyComplex(double re, double im)
	{ real = re; imag = im;}
	MyComplex(string str);
	MyComplex(MyComplex* pc)
	{real = pc->real; imag = pc->imag;}
    // get real and imag
    double getRe() const{return real;}
    double getIm() const{return imag;}
	// Equal
	void Equal(MyComplex c2)
	{real = c2.real; imag = c2.imag;}
    // operator=
    MyComplex& operator=(const char* str)
    {
        *this = MyComplex(str);
        return *this;
    }

	string ToStr(); // for cout

	// Add
	MyComplex Add(MyComplex c2);
    // operator+
    MyComplex operator+(const MyComplex &c2)
    {return MyComplex(real+c2.real, imag+c2.imag);}
    // Minus
	MyComplex Minus(MyComplex c2);
    // operator-
    MyComplex operator-(const MyComplex &c2)
    {return MyComplex(real-c2.real, imag-c2.imag);}
};

string MyComplex::ToStr()
{
	char str2[255];
    if (imag > 0)
	    sprintf(str2, "%.f + %.fi", real, imag);
    else if (imag < 0)
	    sprintf(str2, "%.f - %.fi", real, -imag);
    else
        sprintf(str2, "%.f", real);
	string str = str2;
	return str;
}

MyComplex MyComplex::Add(MyComplex c2)
{
	return MyComplex(real + c2.real, imag + c2.imag);
}

MyComplex MyComplex::Minus(MyComplex c2)
{
	return MyComplex(real - c2.real, imag - c2.imag);
}

MyComplex::MyComplex(string str)
{
    int pos;
    // 1: erase spaces
    while ((pos = str.find(' ')) != string::npos)
        str.erase(pos, 1);
    // 2: erase i
    while ((pos = str.find('i')) != string::npos)
        str.erase(pos, 1);
    // 3: find '+', then real and imag
    pos = str.find('+');
    real = stod(str.substr(0, pos));
    imag = stod(str.substr(pos+1));
}

ostream& operator<<(ostream& os,
        const MyComplex& c)
{
    if (c.getIm() > 0)
        os << c.getRe()<< " + " << c.getIm() << "i";
    else if (c.getIm() < 0)
        os << c.getRe()<< " - " << -c.getIm() << "i";
    else
        os << c.getRe();
    return os;
}

int main()
{
	MyComplex c0, c1(1, 2), c2, c3(&c1);
    c2 = "3 + 4i";
	cout << "c0 = " << c0 << endl;
	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl;
	cout << "c3 = " << c3 << endl;
    c3 = c1 + c2;
//	c3.Equal(c1.Add(c2));
	cout << "c3 = c1 + c2 = " << c3 << endl;
    c3 = c1 - c2;
	//c3.Equal(c1.Minus(c2));
	cout << "c3 = c1 - c2 = " << c3 << endl;
	return 0;
}

