// dovelet
// http://183.106.113.109/30stair/catch_cow/catch_cow.php?pname=catch_cow&stair=14

#include <iostream>
#include <queue>
using namespace std;

int isVisited[100001];
queue < int > path;

void visit(int to, int from)
{
	if (!isVisited[to])
	{
		path.push(to);
		isVisited[to] = isVisited[from] + 1;
	}
	else
	{
		if (isVisited[to] > isVisited[from] + 1)
			isVisited[to] = isVisited[from] + 1;
	}
}

int main()
{
	int n, k;
	cin >> n >> k;

	path.push(n);
	while (n != k)
	{
		n = path.front();
		path.pop();

		if (n - 1 >= 0)
			visit(n - 1, n);

		if (n + 1 <= 100000)
			visit(n + 1, n);

		if (n * 2 <= 100000)
			visit(n * 2, n);
	}

	cout << isVisited[k];

	return 0;
}