#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

string infix_to_postfix(string s)
{
    unordered_map<char, int> operator_precedence; // stores operator precedence
    operator_precedence['+'] = 0;
    operator_precedence['-'] = 0;
    operator_precedence['*'] = 1;
    operator_precedence['/'] = 1;
    operator_precedence['^'] = 2;
    unordered_set<int> operator_set = {'+', '-', '*', '/', '^', '(', ')'};
    int n = s.length();
    stack<char> st; // stores operators while scanning the expression
    string res = "";

    for(char c: s)
    {
        if(operator_set.find(c) != operator_set.end())
        {
            if(st.empty() || st.top() == '(' || c == '(')
                st.push(c);
            else if(c == ')')
            {
                while(!st.empty() && st.top() != '(')
                {
                    res += st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while(!st.empty() && operator_precedence[st.top()] >= operator_precedence[c])
                {
                    res += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        else
            res += c;
    }
        
    while(!st.empty())
    {
        if(st.top() != '(')
            res += st.top();
        st.pop();
    }

    return res;
}

int main()
{
    string exp;
    cout << "Enter a valid Infix Expression: ";
    cin >> exp;
    cout << endl << "Corresponding Postfix Expression: " << infix_to_postfix(exp) << endl;
    return 0;
}