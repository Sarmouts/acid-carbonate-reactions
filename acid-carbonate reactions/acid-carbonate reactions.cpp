#include <iostream>
#include <string>
using namespace std;

string replace(string str)
{
	string final = "";
	for (int i = 0; i <= str.length(); i++)
	{
		if (str[i] != '1')
		{
			final += str[i];
		}
	}
	return final;
}
string parenthesis(string str, int v)
{
	string final = "(" + str + ")";
	if (str == "OH" && v != 1)
	{
		return final;
	}
	else if (str.length() != 3 || v == 1)
	{
		return str;
	}
	return final;
}

int main()
{
	cout << "Welcome to MathFlare's early access acid-carbonate reaction calculator" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	while (true)
	{
		string X, Y, answer;
		int  z, v;
		cout << "X2CO3z + HvY" << endl;
		cout << "Enter Element X (metals)" << endl;
		cin >> X;
		cout << "Enter number z" << endl;
		cin >> z;
		cout << "Enter number v" << endl;
		cin >> v;
		cout << "Enter Element N (non-metals)" << endl;
		cin >> Y;
		if (z <= 0 || v <= 0)
		{
			cout << "Please enter a valid value" << endl;
			cout << "======================================================================================" << endl;
		}
		else if (z > 3 || v > 3)
		{
			cout << "The value of z or v cannot be more than 3" << endl;
			cout << "======================================================================================" << endl;
		}
		else
		{
			if (z == v)
			{
				if (z == 2)
				{// XCO3 + HvY --> XY + H2O + CO2
					answer = X + "CO3" + " + " + "H" + to_string(v) + Y + " --> " + X + Y + " + " + "H2O + " + "CO2";
					cout << replace(answer) << endl;
					cout << "============================================================================================" << endl;
				}
				else
				{// X2CO3Z + 2HvY --> 2XY + vH2O + zCO2
					answer = X + "2" + parenthesis("CO3", z) + to_string(z) + " + 2H" + to_string(v) + Y + " --> 2" + X + Y + " + " + to_string(v) + "H2O + " + to_string(z) + "CO2";
					cout << replace(answer) << endl;
					cout << "============================================================================================" << endl;
				}
			}
			else if (v == 2)
			{// X2CO3z + zHvY --> XvYz + zH2O + zCO2
				answer = X + "2" + parenthesis("CO3", z) + to_string(z) + " + " + to_string(z) + "H" + to_string(v) + Y + " --> " + X + to_string(v) + parenthesis(Y, z) + to_string(z) + " + " + to_string(z) + "H2O + " + to_string(z) + "CO2";
				cout << replace(answer) << endl;
				cout << "============================================================================================" << endl;
			}
			else if (z == 2)
			{// vXCO3 + zHvY --> XvYz + vH2O + vCO2
				answer = to_string(v) + X + "CO3" + " + " + to_string(z) + "H" + to_string(v) + Y + " --> " + X + to_string(v) + parenthesis(Y, z) + to_string(z) + " + " + to_string(v) + "H2O + " + to_string(v) + "CO2";
				cout << replace(answer) << endl;
				cout << "============================================================================================" << endl;
			}
			else
			{// vX2CO3z + 2*zHvY --> 2XvYz + v*zH2O + v*zCO2
				answer = to_string(v) + X + "2" + parenthesis("CO3", z) + to_string(z) + " + " + to_string(2 * z) + "H" + to_string(v) + Y + " --> 2" + X + to_string(v) + parenthesis(Y, z) + to_string(z) + " + " + to_string(v * z) + "H2O + " + to_string(v * z) + "CO2";
				cout << replace(answer) << endl;
				cout << "============================================================================================" << endl;
			}
		}
	}
	return 0;
}

