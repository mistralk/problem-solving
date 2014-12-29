// dovelet
// http://183.106.113.109/30stair/color/color.php?pname=color&stair=20

#include <iostream>
using namespace std;

int paper[129][129];
int pink, white;

int cut(int l, int r, int t, int b)
{
	int size = r - l;
	if (size == 1)
		return paper[t][l];

	int upperLeft = cut(l, l + size/2, t, t + size/2);
	int upperRight = cut(l + size/2, r, t, t + size/2);
	int lowerLeft = cut(l, l + size/2, t + size/2, b);
	int lowerRight = cut(l + size/2, r, t + size/2, b);
	int minus = 0;
	int sum = 0;

	if (upperLeft >= 0)
		sum += upperLeft;
	else minus += upperLeft;
	if (upperRight >= 0)
		sum += upperRight;
	else minus += upperRight;
	if (lowerLeft >= 0)
		sum += lowerLeft;
	else minus += lowerLeft;
	if (lowerRight >= 0)
		sum += lowerRight;
	else minus += lowerRight;

	if (sum == 4)
		return 1;
	else if (sum == 0 && minus == 0)
		return 0;
	else
	{
		pink += sum;
		white += (4 - sum + minus);
		return -1;
	}
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			cin >> paper[i][j];
	}
	int result = cut(0, N, 0, N);
	if (result == 1) { pink = 1; white = 0; }
	else if (result == 0) { pink = 0; white = 1; }
	
	cout << white << endl << pink << endl;
	return 0;
}
