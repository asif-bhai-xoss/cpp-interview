#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    if (s.length() % 2 != 0)
    {
        return false;
    }
    stack<char> st;
    for (int i = 0; s[i] != '\0'; i++)
    {
        char x = s[i];
        if (x == '(' || x == '{' || x == '[')
        {
            cout << "Push = " << i << x << endl;
            st.push(x);
        }
        else if (st.empty())
        {
            return false;
        }
        else
        {
            char y = st.top();
            if ((x - y) == 1 || (x - y) == 2)
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return st.empty();
}

int main()
{

    bool result = isValid("([}}])");
    cout << result << endl;
    // print_stack();

    return 0;
}