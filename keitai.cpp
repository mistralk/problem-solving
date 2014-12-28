// http://www.deqnotes.net/acmicpc/

#include <iostream>
#include <string>
using namespace std;

char one[] = ".,!? ";
char two[] = "abc";
char three[] = "def";
char four[] = "ghi";
char five[] = "jkl";
char six[] = "mno";
char seven[] = "pqrs";
char eight[] = "tuv";
char nine[] = "wxyz";

inline void print(char* str, int clicked)
{
	cout << str[(clicked - 1) % strlen(str)];
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		string input;
		cin >> input;

		int clicked = 0;
		char num;
		for (char it : input)
		{
			if (it == '0')
			{
				if (clicked == 0)
					continue;
				else
				{
					switch (num)
					{
					case '1': print(one, clicked); break;
					case '2': print(two, clicked); break;
					case '3': print(three, clicked); break;
					case '4': print(four, clicked); break;
					case '5': print(five, clicked); break;
					case '6': print(six, clicked); break;
					case '7': print(seven, clicked); break;
					case '8': print(eight, clicked); break;
					case '9': print(nine, clicked); break;
					}
					clicked = 0;
				}
			}
			else
			{
				num = it;
				++clicked;
			}
		}
		cout << endl;
	}
	return 0;
}