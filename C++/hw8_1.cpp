#include<iostream>
#include<cmath>
using namespace std;
class MyPoint {
private:
	int x, y;
public:
	void sets(int x_, int y_) { x = x_; y = y_; }
	void gets(int &_x, int &_y) { _x = x; _y = y; }
	int distance(MyPoint*p2);
};
int MyPoint::distance(MyPoint*p2) {
	return sqrt(pow(x - p2->x, 2) + pow(y - p2->y, 2));
}
int main() {
	int x1, y1, x2, y2;
	cout << "Input: ";
	cin >> x1 >> y1 >> x2 >> y2;
	MyPoint p1, p2;
	p1.sets(x1, y1);p2.sets(x2, y2);
	cout << "distance = " << p1.distance(&p2) << endl;
	return 0;
}