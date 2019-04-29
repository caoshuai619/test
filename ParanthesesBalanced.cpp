#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
bool Match(char a, char b) {
	if (a == '(' && b == ')') return true;
	else if (a == '{' && b == '}') return true;
	else if (a == '[' && b == ']') return true;
	else
		return false;
}
bool AreParanthesesBalanced(string exp)
{
	stack<char> s;
	int length = exp.size();
	for (int i = 0; i < length; i++)
	{
		if (exp[i] == '[' || exp[i] == '{' || exp[i] == '(')
		{
			s.push(exp[i]);
		}
		else if (exp[i] =='}' || exp[i]==']' ||exp[i]==')')
		{
			if (s.empty() || !Match(s.top(), exp[i])) {
				return false;
			}
			else {
				s.pop();
			}
		}
		
	}
	return s.empty() ? true : false;
}

int main()
{
	cout << "inpute a string :";
	string exp;
	cin >> exp;
	cout << "is_right:" << AreParanthesesBalanced(exp) << endl;
	return 0;
}