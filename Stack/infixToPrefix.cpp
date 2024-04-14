#include<iostream>
#include<stack>
#include<string>
using namespace std;

int presentCharacterPrecedence(char c) {
    if(c=='^') {
        return 3;
    } else if(c=='*' || c=='/') {
        return 2;
    } else if(c=='+' || c=='-') {
        return 1;
    } else {
        return -1;
    }
}

string infixToPostfix(string s) {
    stack<char> st;
    string res;
    
    for(int i=0; i<s.length(); i++) {
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) {
            res+=s[i];
        } else if(s[i]=='(') {
            st.push(s[i]);
        } else if(s[i]==')') {
            while(!st.empty() && st.top()!='(') {
                res+=st.top();
                st.pop();
            }
            if(!st.empty()) {
                st.pop();
            }
        } else {
            while(!st.empty() && presentCharacterPrecedence(st.top())>presentCharacterPrecedence(s[i])) {
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()) {
        res+=st.top();
        st.pop();
    }
    return res;
}

int main() {
    stack<int> s;
    string str = "(a+b)*c/d+(e+f)";
    
    cout<<infixToPostfix(str);

    return 0;
}