#include <iostream>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

// return true if ch is an operator, false otherwise
bool IsOperator(char ch)
{
	if (ch == '+' || ch == '-'
		|| ch == '*' || ch == '/'
		|| ch == '^')
		return true;
	else
		return false;
}

// if op1 has precedence over op2, return true
// otherwise return false
bool precedence(char op1, char op2)
{
	if (op1 == '^' && op2 != '^') return true;
	if (op1 == '*' && (op2 == '+' || op2 == '-')) return true;
	if (op1 == '/' && (op2 == '+' || op2 == '-')) return true;
	return false;
}

// Evaluate simple expression
double Eval(double num1, char op, double num2)
{
	switch (op)
	{
	case '+':
		return num1 + num2;
	case '-':
		return num1 - num2;
	case '*':
		return num1 * num2;
	case '/':
		return num1 / num2;
	case '^':
		return pow(num1, num2);
	default:
		return 0; // unrecognized
	}
}

// Evaluate all numbers and operators
double EvalAll(stack<double>& st1, stack<char>& st2)
{
	double num, num1, num2;
	char op;
	while (!st2.empty())
	{
		num1 = st1.top(); st1.pop();
		num2 = st1.top(); st1.pop();
		op = st2.top(); st2.pop();
		num = Eval(num2, op, num1);
		st1.push(num);
	}
	num = st1.top(); st1.pop(); // clear st1
	return num;
}

// evaluate simple expressions, support +,-,*,/
// suppose all the numbers are double type
// and the input is always correct
double EvalExpression(const string& str)
{
	stack<double> st1; // stack for operands
	stack<char> st2; // stack for operators
	int i, j, len = str.length();
	double num, num1, num2; // numbers
	char op, op_stack; // operators

	i = j = 0; // start and end of an operand or an operator
	while (j < len)
	{
		// find the next operator
		while (j < len && !IsOperator(str[j])) j++;
		if (j < len) // find an operator
		{
			// get the operand and operator
			num = stod(str.substr(i, j - i));
			op = str[j];
			i = ++j; // update i, j
			// push the operand into stack
			st1.push(num);
			// compare the operator with the one at the top of st2
			if (st2.empty()) st2.push(op); // empty st2
			else
			{
				op_stack = st2.top();
				while (!precedence(op, op_stack))
				{
					st2.pop(); // pop op_stack out
					// do the calculation
					num1 = st1.top(); st1.pop();
					num2 = st1.top(); st1.pop();
					num = Eval(num2, op_stack, num1);
					st1.push(num);
					if (st2.empty()) break; // st2 is empty
					op_stack = st2.top();
				}
				st2.push(op);
			}
		}
		else // reach the end
		{
			// push the last number into st1
			num = stod(str.substr(i, j - i));
			st1.push(num);
			// evaluate all
			num = EvalAll(st1, st2);
			st1.push(num);
		}
	}
	return st1.top();
}

int main()
{
	string str;// = "1.5+2.4*3.1/4";
	cout << "Expression? ";
	cin >> str;
	cout << EvalExpression(str) << endl;
	return 0;
}
