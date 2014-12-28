// JMBook

#include <iostream>
#include <string>
using namespace std;

string decompress(string::iterator& it)
{
	char head = *it;
	++it;
	if (head == 'b' || head == 'w')
		return string(1, head);
	string upperLeft = decompress(it);
	string upperRight = decompress(it);
	string lowerLeft = decompress(it);
	string lowerRight = decompress(it);
	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main()
{
	int C;
	cin >> C;
	while (C--)
	{
		string input;
		cin >> input;

		string::iterator it = input.begin();
		cout << decompress(it) << endl;
	}
	return 0;
}