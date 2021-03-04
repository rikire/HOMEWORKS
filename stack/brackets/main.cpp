#include <iostream>
#include <stack>

using namespace std;

char reverse_bracket(char c){
    switch(c){
    case')':
        return '(';
    case'}':
        return '{';
    case']':
        return '[';
    case'>':
        return '<';
    }
}

bool is_good_brackets(string str){
    stack<char> st;
    for(char &c:str){
        switch(c){
        case'(':
        case'{':
        case'[':
        case'<':
            st.push(c);
            break;
        case')':
        case'}':
        case']':
        case'>':
            if(st.size()==0){
                return false;
            }
            if(st.top()==reverse_bracket(c)){
                st.pop();
            }
            else{
                return false;
            }
            break;
        default:
            cout<<"BAD BRACKET TOKEN"<<endl;
            return false;
        }
    }
    if(st.size()==0){
        return true;
    }
    return false;
}

int main()
{
    string s;
    // ctrl + z to exit
    while(cin>>s){
        if(is_good_brackets(s)){
            cout<<"ALL GOOD"<<endl;
        }
        else{
            cout<<"NOT GOOD"<<endl;
        }
    }
    return 0;
}
