#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Person{
    string name;
    string surname;
    int age;
    Person(){
        this->name = "simple name";
        this->surname= "simple surname";
        this->age = -1;
    }
    Person(string name,string surname, int age){
        this->name = name;
        this->surname= surname;
        this->age = age;
    }
};

Person read_person(istream &in){
    Person per;

    in.read((char*)&per.age,sizeof(per.age));

    size_t len;
    in.read((char*)&len,sizeof(len));
    char * buf = new char[len];
    in.read(buf,len);
    per.name = buf;

    in.read((char*)&len,sizeof(len));
    buf = new char[len];
    in.read(buf,len);
    per.surname = buf;

    return per;
}

void write_person(ostream &os,Person &per){
    os.write((char*)&per.age,sizeof(per.age));

    size_t len = per.name.length()+1;
    os.write((char*)&len,sizeof(len));
    os.write((char*)per.name.c_str(),len);

    len = per.surname.length()+1;
    os.write((char*)&len,sizeof(len));
    os.write((char*)per.surname.c_str(),len);
}
void read_vector(vector <Person> &v, string fname){
    ifstream in;
    in.open(fname,ios::binary);
    if(!in){
        throw "File open error";
    }
    size_t v_len=0;
    in.read((char*)&v_len,sizeof(v_len));
    for(size_t i=0; i<v_len;i++){
        v.push_back(read_person(in));
    }
}
void write_vector(vector <Person> &v, string fname){
    ofstream os;
    os.open(fname, ios::binary);
    if(!os){
        throw "File open error";
    }
    size_t v_len = v.size();
    os.write((char*)&v_len,sizeof(v_len));
    for(size_t i=0;i<v_len;i++){
        write_person(os,v[i]);
    }
}
void do_help(){
    cout<<"Insert: "<<endl;
    cout<<"\"show\" to see fields"<<endl;
    cout<<"\"add\" to add field"<<endl;
    cout<<"\"save\" to save file"<<endl;
    cout<<"\"delete ID\" to delete field"<<endl;
    cout<<"\"exit\" to exit"<<endl;
}
void show(vector <Person> &v){
    if(v.size()==0){
        cout<<"There is no persons"<<endl;
        return;
    }
    cout<<"List of persons: "<<endl;
    for(int i=0;i<v.size();i++){
        cout<<"ID: "<<i<<" ";
        cout<<"NAME: "<<v[i].name<<" SURNAME: "<<v[i].surname<<" AGE: "<<v[i].age<<endl;
    }
}
void add(vector<Person> &v){
    Person per;
    cout<<"Insert the name: ";
    cin>>per.name;
    cout<<"Insert the surname: ";
    cin>>per.surname;
    cout<<"Insert the age: ";
    cin>>per.age;
    v.push_back(per);
    cout<<"Person added, do not forget to save file!"<<endl;
}
void del(vector <Person> &v){
    int id;
    cin>>id;
    if(id>=0 && id<v.size()){
        v.erase(v.begin()+id);
    }
    else{
        cout<<"Bad ID"<<endl;
    }
    cout<<id<<"element was deleted, id's may be changed"<<endl;
}
int main()
{
    cout<<"Start of proggram"<<endl;
    cout<<"Insert \"help\" to get help"<<endl;
    vector <Person> v;
    string input;
    string fname = "database.dat";
    read_vector(v,fname);
    while(true){
        cin>>input;
        if(input=="help"){
            do_help();
        }
        else if(input=="show"){
            show(v);
        }
        else if(input=="add"){
            add(v);
        }
        else if(input=="save"){
            write_vector(v,fname);
            cout<<"File was saved!"<<endl;
        }
        else if(input=="delete"){
            del(v);
        }
        else if(input=="exit"){
            cout<<"the end";
            break;
        }
        else{
            cout<<"bad command"<<endl;
        }
    }
    return 0;
}
