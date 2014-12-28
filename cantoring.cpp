// dovelet
// http://183.106.113.109/30stair/cantoring/cantoring.php?pname=cantoring

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string erase_bar(int begin, int end)
{
	if ((end - begin) == 1)
		return "-";
	int partition = (end - begin) / 3;
	string one = erase_bar(begin, begin + partition);
	string two(partition, ' ');
	string three = erase_bar(begin + partition*2, end);
	return one + two + three;
}

int main()
{
	int n;
	cin >> n;
	cout << erase_bar(0, pow(3, n)) << endl;
	return 0;
}