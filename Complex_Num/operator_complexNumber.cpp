#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Complex
{
public:
	int a, b;
	//void input(string s)
	//{
	//	int v1 = 0;
	//	int i = 0;
	//	while (s[i] != '+')
	//	{
	//		v1 = v1 * 10 + s[i] - '0';
	//		i++;
	//	}
	//	while (s[i] == ' ' || s[i] == '+' || s[i] == 'i')
	//	{
	//		i++;
	//	}
	//	int v2 = 0;
	//	while (i < s.length())
	//	{
	//		v2 = v2 * 10 + s[i] - '0';
	//		i++;
	//	}
	//	a = v1;
	//	b = v2;
	//}
	void input(string s)
	{
		stringstream ss(s);
		string value;
		while (getline(ss, value, '+'))
		{
			if (value[0] == 'i')
			{
				string value2 = value.substr(1, value.length() - 1);
				b = stoi(value2);
			}
			if (value[0] != 'i')
				a = stoi(value);
			
		}
	}
};

ostream& operator<<(ostream& os, const Complex& out)
{
	return os << out.a << "+i" << out.b;
}

Complex& operator + (Complex& x, const Complex& y)
{
	x.a = x.a + y.a;
	x.b = x.b + y.b;
	return x;
}

int main()
{
	Complex x, y;
	string s1, s2;
	cin >> s1;
	cin >> s2;
	x.input(s1);
	y.input(s2);
	Complex result = x + y;
	cout << "Result = " << result << endl;
	return 0;
}