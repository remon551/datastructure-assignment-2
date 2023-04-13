#include<iostream>
#include<string>
#include<sstream>
#include<cctype>
#include"stack.cpp"
using namespace std;

int degree_of(char ch)
{
    if(ch == '+' || ch == '-')
    {
        return 1;
    }
    else if(ch == '*' || ch == '/')
    {
        return 2;
    }
    else if(ch == '^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}

int main()
{
    /*
    first example: X^Y / (5*Z) + 2
    result: XY^5Z* /2+

    second example: A + B * C + D
    result: A B C * + D +

    third example: (A + B) * (C + D)
    result: A B + C D + *
    */
    string infix, postfix = "";
    stack<char> s;
    getline(cin, infix);
    for(char ch : infix)
    {
        if(ch == ' ')
        {
            continue;
        }
        else if(isalpha(ch) || isdigit(ch))
        {
            postfix += ch;
        }
        else if(ch == '(')
        {
            s.push(ch);
        }
        else if(ch == ')')
        {
            while(s.stackSize() && s.top() != '(')
            {
                char x = s.pop();
                postfix += x;
            }
            s.pop(); // to pop (
        }
        else if(ch == '^')
        {
            s.push(ch);
        }
        else
        {
            while(s.stackSize() && degree_of(ch) <= degree_of(s.top()))
            {
                postfix += s.pop();
            }
            s.push(ch);
        }
    }
    while(s.stackSize())
    {
        postfix += s.pop();
    }
    cout << postfix;
}