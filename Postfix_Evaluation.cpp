#include <bits/stdc++.h>
using namespace std;
int op(char op, int a, int b)
{
    switch(op)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}

int evalPostfix(string s)
{
    stack<int> st;
    int res = 0;
    string temp = "";
    int n = s.length();
    char c;
    for(int i = 0; i < n; i++)
    {
        if(s[i] != ' '){
            c = s[i];
            temp += c;
            if(i != n - 1)
                continue;
        }

        if(temp == "")
            continue;
        
        if(temp !=  "+" && temp != "-" && temp != "*" && temp != "/")
            st.push(stoi(temp));
        else
        {
            if(st.size() < 2)
                return INT_MIN;
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            res = op(c, op1, op2);
            st.push(res);
        }
        temp = "";
    }

    if(st.size() > 1)
        return INT_MIN;
    return st.top();
}

int main()
{
    cout << "Enter a postfix expression with operators and operands separated by a single space: ";
    string s;
    getline(cin, s);
    int val = evalPostfix(s);
    if(val == INT_MIN)
        cout << endl << "Invalid expression!" << endl;
    else
        cout << endl << "Evaluated value: " << val;
    return 0;
}