#include<bits/stdc++.h>
using namespace std;

bool isoperand(char c)
{
    if((c>= 'a' && c<='z') || (c>='A' && c<='Z'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

string postfixtoinfix(string postfix)
{
    stack <string> s;
    for(int i=0; i<postfix.length(); i++)
    {
        if(isoperand(postfix[i]))
        {
            string op(1, postfix[i]);
            s.push(op);
        }
        else
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            s.push("(" + op2 + postfix[i] + op1 + ")");
        }
    }
    return s.top();
}
int main()
{
    string infix, postfix;

    cout<<"Enter a postfix: "<<endl;
    cin>>postfix;

    cout<<"POSTFIX EXPRESSION: "<<postfix<<endl;
    infix = postfixtoinfix(postfix);
    cout<<"INFIX EXPRESSION "<<infix<<endl;


    return 0;
}
