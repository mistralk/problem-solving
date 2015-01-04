// dovelet
// http://183.106.113.109/30stair/dfreq/dfreq.php?pname=dfreq

#include <iostream>
using namespace std;

int main()
{
	int n, m, cnt = 0, z = 1, prev = 0;
	cin >> n >> m;
	const int origin_n = n;

	while (n)
	{
		int digit = n % 10;
		if (digit > m)
		{
			if (n / 10 == 0 && m == 0)
				break;
			cnt += (n / 10 + 1) * z;
		}
		else if (digit == m)
		{
			if (n == origin_n && m == 0)
				cnt += n / 10;
			else if (m == 0)
				cnt += (n / 10 - 1) * z + prev + 1;
			else
				cnt += n / 10 * z + prev + 1;
		}
		else if (digit < m)
		{
			cnt += n / 10 * z;
		}
		prev += digit * z;
		n /= 10;
		z *= 10;
	}

	cout << cnt;
	return 0;
}