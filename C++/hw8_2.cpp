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
class Triangle {
	MyPoint point1, point2, point3;
public:
	Triangle() { point1.sets(0, 0); point2.sets(1, 0); point3.sets(0, 1); }
	Triangle(MyPoint p1, MyPoint p2, MyPoint p3) { point1 = p1; point2 = p2; point3 = p3; }
	int getArea(MyPoint p1, MyPoint p2, MyPoint p3);
	int getPerimeter(MyPoint p1, MyPoint p2, MyPoint p3);
};
int Triangle::getPerimeter(MyPoint p1, MyPoint p2, MyPoint p3) {
	int s1 = p2.distance(&p1), s2 = p3.distance(&p2), s3 = p1.distance(&p3);
	return s1 + s2 + s3;
}
int Triangle::getArea(MyPoint p1, MyPoint p2, MyPoint p3) {
	int s1 = p2.distance(&p1), s2 = p3.distance(&p2), s3 = p1.distance(&p3);
	int p = s1 + s2 + s3;
	return sqrt(p / 2 * (p / 2 - s1)*(p / 2 - s2)*(p / 2 - s3));
}
int main() {
	int x1, x2, x3, y1, y2, y3;
	cout << "Input: ";
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	MyPoint p1, p2, p3;
	p1.sets(x1, y1); p2.sets(x2, y2); p3.sets(x3, y3);
	Triangle tri(p1, p2, p3);
	cout << "area = " << tri.getArea(p1, p2, p3) << "\nperimeter = " << tri.getPerimeter(p1, p2, p3) << endl;
}