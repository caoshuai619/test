#include "iostream"
#include "stack"
#include "string"
using namespace std;
//�ж��Ƿ��ǲ�����
bool IsOperand(char c);
//�ж��Ƿ��ǲ�����
bool IsOperator(char c);
//���������Ӹ�Ȩ�أ����ڱȽ�
int OperatorWeight(char c);
//�жϲ����������ȼ�
bool HigherOperatorPrority(char c1,char c2);

string InfixToPostfix(string expr)
{
	string res = ""; //���ַ�������������
	stack<char> s; 
	for(size_t i=0;i<expr.size();i++)
	{
		
		if(expr[i]==' ' || expr[i] ==',') continue;  //�������Щ�����Թ�
		
		if(IsOperand(expr[i])){
			res+=expr[i];
		}
		else if(IsOperator(expr[i]))
		{
			while(!s.empty()&& s.top()!='(' && HigherOperatorPrority(s.top(),expr[i]))
			{
				res+=s.top();
				s.pop();
			}
			s.push(expr[i]);
		}
		else if(expr[i] =='(')
		{
			s.push(expr[i]);
		}
		else if(expr[i] == ')')
		{
			while(!s.empty() && s.top()!='(')
			{
				res+=s.top();
				s.pop();
			}
			s.pop();
		}
		
	}
	while(!s.empty())
	{
		res+=s.top();
		s.pop();
	}
	return res;
}



bool IsOperand(char c)
{
	if(c >= '0' && c<='9') return true;
	else if(c>='a' && c<='z') return true;
	else if(c>='A' && c<='Z') return true;
	else return false;
}

bool IsOperator(char c)
{
	if(c == '+' || c=='-' || c=='*' || c=='/')
	{
		return true;
	}
	return false;
}
int OperatorWeight(char c)
{
	int weight;
	switch(c)
	{
		case '+':
		case '-':weight=1;break;
		case '*':
		case '/':weight = 2;break;
	}
	return weight;
}

bool HigherOperatorPrority(char c1,char c2)
{
	int c1Weight = OperatorWeight(c1);
	int c2Weight = OperatorWeight(c2);
	if(c1Weight-c2Weight>0)
	{
		return true;
	}
	return false;
}
int main()
{
	string expr ;
	cout<<"��������ʽ:";
	cin>>expr;
	string res = InfixToPostfix(expr);
	cout<<res<<endl;
	return 0;
}
 


