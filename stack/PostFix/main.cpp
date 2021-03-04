#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
struct Token{
    // type: num - number, op - operator, b - bracket
    string type="none";
    double dvalue=0;
    char cvalue='N';
    int prec=0;
    Token(double value){
        type="num";
        dvalue=value;
    }
    Token(char op){
        if(op=='('||op==')'){
            type="b";
            cvalue=op;
        }
        else{
            if(op=='*' || op=='/') prec=2;
            else if(op=='+' || op=='-') prec=1;
            else prec=-1;
            cvalue=op;
            type="op";
        }
    }
};
vector<Token> CreateTS(istream &is){
    vector<Token> TS;
    char c;
    while(is>>c){
        if(isdigit(c)){
            is.putback(c);
            double i;
            is>>i;
            TS.push_back(Token(i));
        }
        else if(c=='('||c==')' || c=='*' || c=='/' || c=='+' || c=='-'){
            TS.push_back(Token(c));
        }
    }
    return TS;
}
vector<Token> InfixToPostfix(vector<Token> IN){
    vector<Token> OUT;
    stack<Token> st;
    for(Token t:IN){
        if(t.type=="num"){
            OUT.push_back(t);
        }
        else if(t.cvalue=='('){
            st.push(t);
        }
        else if(t.cvalue==')'){
            while(st.size()>0 && st.top().cvalue!='('){
                    OUT.push_back(st.top());
                    st.pop();
            }
            if(st.top().cvalue=='('){
                    st.pop();
            }
        }
        else{
            while(st.size()>0 && t.prec<=st.top().prec){
                OUT.push_back(st.top());
                st.pop();
            }
            st.push(t);
        }
    }
    while(st.size()>0){
        OUT.push_back(st.top());
        st.pop();
    }
    return OUT;
}
int CalcPostfix(vector<Token>IN){
    stack<double> st;
    for(Token t: IN){
        if(t.type=="num"){
            st.push(t.dvalue);
        }
        else{
            double a = st.top();
            st.pop();
            double b = st.top();
            st.pop();
            switch(t.cvalue){
            case'*':
                st.push(a*b);
                break;
            case'+':
                st.push(a+b);
                break;
            case'-':
                st.push(b-a);
                break;
            case'/':
                st.push(b/a);
                break;
            }
        }
    }
    if(st.size()==1){
        return st.top();
    }
    else{
        cout<<"error";
        return 0;
    }
}
int main()
{
    stringstream ss;
    string exp;
    cin>>exp;
    ss<<exp;
    vector<Token> TS = CreateTS(ss);
    TS = InfixToPostfix(TS);
    for(Token &t:TS){
        if(t.type=="num"){
            cout<<t.dvalue<<" ";
        }
        else{
            cout<<t.cvalue<<" ";
        }
    }
    cout<<endl<<CalcPostfix(TS);
    return 0;
}
