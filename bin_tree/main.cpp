#include <iostream>
#include <stack>
#include <string>
using namespace std;

string double_to_str(double d){
    if(d==0){
        return "0";
    }
    string s = to_string(d);
    while(s[s.size()-1]=='0' || s[s.size()-1]=='.'){
        s.erase(s.size()-1);
    }
    return s;
}

struct Node{
    double dvalue=0;
    char cvalue='N';
    string type="nontype"; // may be dvalue or char
    Node(double value){
        dvalue = value;
        type = "double";
    }
    Node(char value){
        cvalue = value;
        type = "char";
    }
    Node *right;
    Node *left;
};

Node *Create_Tree(string exp){
    if(exp.size()>2 && exp[0]=='('&&exp[exp.size()-1]==')'){
        exp = exp.substr(1,exp.size()-2);
    }
    int idx1=0;
    int idx2=0;
    for(int i=0;i<exp.size();i++){
        if(exp[i]=='('){
            i=exp.rfind(')');
        }
        if(exp[i]=='*'||exp[i]=='/'){
            idx2 = i;
        }
        if(exp[i]=='+'||exp[i]=='-'){
            idx1 = i;
        }
    }
    if(idx1==0){
        if(idx2==0){
            return new Node(atof(exp.c_str()));
        }
        else{
            idx1=idx2;
        }
    }
    Node *n = new Node(exp[idx1]);
    n->left = Create_Tree(exp.substr(0,idx1));
    n->right = Create_Tree(exp.substr(idx1+1,exp.size()-idx1-1));
    return n;
}
Node *Count_Tree(Node *node){
    if(node->type=="double"){
        return node;
    }
    Node *n1 = Count_Tree(node->left);
    Node *n2 = Count_Tree(node->right);
    switch (node->cvalue){
case'+':
    return new Node(n1->dvalue+ n2->dvalue);
case'-':
    return new Node(n1->dvalue - n2->dvalue);
case'*':
    return new Node(n1->dvalue * n2->dvalue);
case'/':
    return new Node(n1->dvalue / n2->dvalue);
    }
}

string prefix(Node *root){
    string s = "";
    if(root->type=="double"){
        double d = root->dvalue;
        s += double_to_str(d);
        s += ' ';
        return s;
    }
    s += root->cvalue;
    s += ' ';
    return s + prefix(root->left) + prefix(root->right);
}
string infix(Node *root){
    string s = "";
    if(root->type=="double"){
        double d = root->dvalue;
        s += double_to_str(d);
        s += ' ';
        return s;
    }
    s += root->cvalue;
    s += ' ';
    return infix(root->left)+ s + infix(root->right);
}
string postfix(Node *root){
    string s = "";
    if(root->type=="double"){
        double d = root->dvalue;
        s += double_to_str(d);
        s += ' ';
        return s;
    }
    s += root->cvalue;
    s += ' ';
    return postfix(root->left) + postfix(root->right) + s;
}

string clear_spaces(string s){
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            s = s.substr(0,i) + s.substr(i+1,s.size()-1);
        }
    }
    return s;
}

int main()
{
    string exp;
    cout<<"INSERT EXP:"<<endl;
    getline(cin, exp);
    exp = clear_spaces(exp);
    Node *tree = Create_Tree(exp);
    Node *res = Count_Tree(tree);
    cout<<endl<<res->dvalue;
    cout<<endl<<prefix(tree);
    cout<<endl<<infix(tree);
    cout<<endl<<postfix(tree);
    // обработку ошибок лень делать

    return 0;
}
