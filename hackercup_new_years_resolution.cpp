// Facebook Hacker Cup 2015 Qualification Round
// #2 New Year's Resolution
// https://www.facebook.com/hackercup/problems.php?pid=1036037553088752&round=742632349177460

#include <cstdio>
#include <vector>
using namespace std;

struct Food {
	int p, c, f;
};

int gp, gc, gf;

// eaten: bit vector(32-bit int) for checking the eaten foods
bool f(vector<Food>& foods, int eaten, int sump, int sumc, int sumf)
{
	if (sump > gp || sumc > gc || sumf > gf) return false;
	if (sump == gp && sumc == gc  && sumf == gf) return true;
	if (eaten == ((1 << foods.size()) - 1)) return false;

	for (int next = 0; next < foods.size(); ++next)
	{
		if (eaten & (1 << next)) continue;
		if (f(foods, eaten + (1 << next), sump + foods[next].p, sumc + foods[next].c, sumf + foods[next].f))
			return true;
	}
	return false;
}

int main()
{
	FILE *in = fopen("input.txt", "r");
	FILE *out = fopen("output.txt", "w");

	int T;
	fscanf(in, "%d", &T);
	for (int t = 1; t <= T; ++t)
	{
		vector<Food> foods;
		int sump = 0, sumc = 0, sumf = 0;
		int n;
		fscanf(in, "%d %d %d %d", &gp, &gc, &gf, &n);
		for (int i = 0; i < n; ++i)
		{
			Food input;
			fscanf(in, "%d %d %d", &input.p, &input.c, &input.f);

			if (input.p <= gp && input.c <= gc && input.f <= gf)
				foods.push_back(input);
		}

		fprintf(out, "Case #%d: ", t);
		int i;
		for (i = 0; i < foods.size(); ++i)
		{
			if (f(foods, 1 << i, foods[i].p, foods[i].c, foods[i].f))
			{
				fprintf(out, "yes\n");
				break;
			}
		}
		if (i >= foods.size())
			fprintf(out, "no\n");
	}
	fclose(in);
	fclose(out);
	return 0;
}