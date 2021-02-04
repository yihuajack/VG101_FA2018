#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string reverse_words(string str)
{
	string str2, word;
	vector<string> vstr;
	int i, start;
	// start from the first non-space character
	for (i = 0; str[i] == ' '; i++);
	// separate words
	for(start = i; i<str.length(); i++)
	{
		if (str[i] == ' ')
		{
			vstr.push_back(str.substr(start, i-start));
			start = i+1;
		}
	}
	vstr.push_back(str.substr(start, i-start));
	// reverse
	reverse(vstr.begin(), vstr.end());
	for (str2 = vstr[0], i=1; i<vstr.size(); i++)
		str2 += " " + vstr[i];
	return str2;
}
int main()
{
	string str;
	cout << "Input a string: ";
	getline(cin, str);
	cout << reverse_words(str) << endl;
}
