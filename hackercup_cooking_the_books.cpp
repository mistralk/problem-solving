// Facebook Hacker Cup 2015 Qualification Round
// #1 Cooking the Books
// https://www.facebook.com/hackercup/problems.php?pid=582062045257424&round=742632349177460

#include <cstdio>
int main()
{
	FILE *fi = fopen("input.txt", "r");
	FILE *fo = fopen("output.txt", "w");
	int T;
	fscanf(fi, "%d", &T);
	for (int i = 1; i <= T; ++i)
	{
		int N;
		fscanf(fi, "%d", &N);
		int n = N;


		fprintf(fo, "Case #%d: ", i);
		if (N == 0) {
			fprintf(fo, "0 0\n", i);
			continue;
		}
		unsigned int number[9] = { 0 };
		int digit = 0;
		for (; N; N /= 10)
			number[digit++] = N % 10;

		// Min
		int min = digit - 1;
		for (int j = digit - 2; j >= 0; --j)
		{
			if (number[min] > number[j] && number[j] != 0)
				min = j;
		}
		if (min == digit - 1) fprintf(fo, "%d ", n);
		else
		{
			int temp = number[min];
			number[min] = number[digit - 1];
			number[digit - 1] = temp;
			for (int j = digit - 1; j >= 0; --j)
				fprintf(fo, "%d", number[j]);
			fprintf(fo, " ");

			temp = number[min];
			number[min] = number[digit - 1];
			number[digit - 1] = temp;
		}

		// Max
		for (int j = digit - 1; j >= 0; --j)
		{
			int max = j;
			for (int k = j - 1; k >= 0; --k)
			{
				if (number[max] < number[k])
					max = k;
			}
			if (max != j)
			{
				int temp = number[j];
				number[j] = number[max];
				number[max] = temp;
				break;
			}
		}
		for (int j = digit - 1; j >= 0; --j)
			fprintf(fo, "%d", number[j]);
		fprintf(fo, "\n");
	}
	fclose(fi);
	fclose(fo);
	return 0;
}