#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

void do_help(){
    cout<<"insert \"1\" to show average score"<<endl;
    cout<<"insert \"2\" to show max sum of scores "<<endl;
    cout<<"insert \"3\" to show max summary scores students"<<endl;
    cout<<"insert \"4\" to show two-score students"<<endl;
    cout<<"insert \"quit\" to quit "<<endl;
}

int str_to_int(string str){
    return atoi(str.c_str());
}

struct Student{
    string name = "0";
    string second_name = "0";
    int rus_lang = 0;
    int alg = 0;
    int phys = 0;
    int hist = 0;
};

Student make_student(string s){
    Student temp_student;
    int k = s.find(",");
    temp_student.second_name = s.substr(0,k);
    s.erase(0,k+1);
    k = s.find(",");
    temp_student.name = s.substr(0,k);
    s.erase(0,k+1);
    k = s.find(",");
    temp_student.alg = str_to_int(s.substr(0,k));
    s.erase(0,k+1);
    k = s.find(",");
    temp_student.rus_lang = str_to_int(s.substr(0,k));
    s.erase(0,k+1);
    k = s.find(",");
    temp_student.phys = str_to_int(s.substr(0,k));
    s.erase(0,k+1);
    k = s.find(",");
    temp_student.hist = str_to_int(s.substr(0,k));
    s.erase(0,k+1);
    return temp_student;
}

void show_average(vector <Student> &student_list){
    double avg_alg = 0;
    double avg_rus = 0;
    double avg_phys = 0;
    double avg_hist = 0;
    int k = student_list.size();
    for(int i=0;i<k;i++){
        avg_alg += student_list[i].alg;
        avg_rus += student_list[i].rus_lang;
        avg_phys += student_list[i].phys;
        avg_hist += student_list[i].hist;
    }
    avg_alg/=k;
    avg_rus/=k;
    avg_phys/=k;
    avg_hist/=k;
    cout<<"Average scores: "<<endl;
    cout<<"Algebra : "<<avg_alg<<endl;
    cout<<"Rus lan : "<<avg_rus<<endl;
    cout<<"Physics : "<<avg_phys<<endl;
    cout<<"History : "<<avg_hist<<endl;
}

int max_sum(vector <Student> &s_l){
    int sum=0;
    int max_sum=0;
    int len = s_l.size();
    for(int i=0;i<len;i++){
        sum = s_l[i].rus_lang + s_l[i].alg + s_l[i].phys + s_l[i].hist;
        if(max_sum<sum){
            max_sum = sum;
        }
    }
    return max_sum;
}

void show_max_sum(vector <Student> &s_l){
    cout<<"Max summary score: "<<max_sum(s_l)<<endl;
}

void show_max_sum_students(vector <Student> &s_l){
    int sum=0;
    int m_sum = max_sum(s_l);
    vector <string> max_students;
    for(int i=0;i< s_l.size();i++){
        sum = s_l[i].rus_lang + s_l[i].alg + s_l[i].phys + s_l[i].hist;
        if(m_sum == sum){
            max_students.push_back(s_l[i].second_name + " " + s_l[i].name);
        }
    }
    sort(max_students.begin(),max_students.end());
    cout<<"The coolest max summars: "<<endl;
    for(int i=0;i<max_students.size();i++){
        cout<<max_students[i]<<endl;
    }
}

void show_two_score_students(vector <Student> &s_l){
    vector <string> max_students;
    for(int i=0;i< s_l.size();i++){
        if(s_l[i].rus_lang==2 || s_l[i].alg==2
           || s_l[i].phys==2 || s_l[i].hist==2)
        {
            max_students.push_back(s_l[i].second_name + " " + s_l[i].name);
        }
    }
    sort(max_students.begin(),max_students.end());
    cout<<"The coolest two-score students: "<<endl;
    for(int i=0;i<max_students.size();i++){
        cout<<max_students[i]<<endl;
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    vector <Student> student_list;
    string line;
    fstream file;
    file.open("marks.csv");
    if(file){
        while(getline(file,line)){
            student_list.push_back(make_student(line));
        }
        cout<<"insert \"help\" to get help"<<endl;
        string c;
        while(true){
            cin>>c;
            if(c=="help"){
                do_help();
            }
            else if(c=="1"){
                show_average(student_list);
                cout<<endl;
            }
            else if(c=="2"){
                show_max_sum(student_list);
                cout<<endl;
            }
            else if(c=="3"){
                show_max_sum_students(student_list);
                cout<<endl;
            }
            else if(c=="4"){
                show_two_score_students(student_list);
                cout<<endl;
            }
            else if(c=="quit"){
                cout<<"The end";
                break;
            }
            else{
                cout<<"BAD COMMAND, TRY AGAIN";
            }
        }
    }
    else{
        cout<<"ERROR: FILE NOT OPEN T_T";
    }
    file.close();
    return 0;
}
