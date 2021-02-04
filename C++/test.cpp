#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
int main(){
	int arr[4] = { 1,1,0,3 },n=0,t=0;
	std::vector<int> v{ 0, 1, 2, 3, 4 ,5,6,7,8,9,1,5,5,1};
	auto result = std::find(std::begin(v), std::end(v), arr[n]);
	while (result != std::end(v)) {
		if (result != std::end(v)) {
			std::cout << "v contains: " << t << '\n';
		}
		else {
			std::cout << "v does not contain: " << arr[n] << '\n';
		}
		result++;
	}
	system("PAUSE");
}