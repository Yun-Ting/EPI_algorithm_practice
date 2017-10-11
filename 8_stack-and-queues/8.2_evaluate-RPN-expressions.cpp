// 8.2_evaluate-RPN-expressions.cpp
// date: 10/10
#include <string>
#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

int Eval(const string& RPN_expression) {
	stack<int> intermediate_results;
	stringstream ss(RPN_expression);
	string token;
	const char kDelimiter = ',';

	while (getline(ss, token, kDelimieter)) {
		if (token == "+" || token == "-" || token == "*" || token == "/") {
			const int y = intermediate_results.top();
			intermediate_results.pop();
			const int x = intermediate_results.top();
			intermediate_results.pop();
			switch (token.front()) {
				case '+':
					intermediate_results.emplace(x + y);
					break;
				case '-':
					intermediate_results.emplace(x - y);
					break;
				case '*':
					intermediate_results.emplace(x * y);
					break;
				case '/':
					intermediate_results.emplace(x / y);
					break;

			}
		} else { // token is a number
			intermediate_results.emplace(stoi(token));
		}
	}
	return intermediate_results.top();
}