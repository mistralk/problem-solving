// deqnotes
// http://www.deqnotes.net/acmicpc/1978/ja

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	while (1)
	{
		int n, r;
		cin >> n >> r;
		if (n == 0 && r == 0)
			break;

		vector<int> cards;
		for (int j = n; j >= 0; --j)
			cards.push_back(j);

		for (int i = 0; i < r; ++i)
		{
			int p, c;
			cin >> p >> c;

			vector<int> shuffled;
			shuffled.insert(shuffled.begin(), cards.begin() + p - 1, cards.begin() + p + c - 1);
			cards.erase(cards.begin() + p - 1, cards.begin() + p + c - 1);
			cards.insert(cards.begin(), shuffled.begin(), shuffled.end());
		}
		cout << cards[0] << endl;
	}
	return 0;
}