#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

struct TPair{
    string word;
    int counter;
    TPair(){this->word="";this->counter=0;}
    TPair(string word,int counter){
        this->word = word;
        this->counter = counter;
    }
};

int Find(vector<TPair> &L,string s){
    if (L.size()==0){
        return 0;
    }
    int mid = 0;
    int left = 0;
    int right = L.size();
    while(true){
        mid = (left + right)/2;
        if(s < L[mid].word){
            right = mid;
        }
        else if(s > L[mid].word){
            left = mid;
        }
        else{
            return mid;
        }
        if(left == right - 1){
            return right;
        }
    }
}
bool comp_counters(TPair &left, TPair &right){
    return (left.counter < right.counter);
}
void sort_by_counter(vector<TPair> &L){
    sort(L.begin(),L.end(),comp_counters);
}
int main()
{
    string s;
    int p;
    vector<TPair> L;
    ifstream in;
    in.open("input.txt");
    while(in>>s){
        p = Find(L,s);
        if(L.size()==0){
            L.push_back(TPair(s,1));
            continue;
        }
        if(L[p].word == s){
            L[p].counter++;
        }
        else{
            L.insert(L.begin() + p, TPair(s,1));
        }
    }
    sort_by_counter(L);
    for(TPair &tp:L){
        cout<<tp.word<<" "<<tp.counter<<endl;
    }
    in.close();
    return 0;
}
