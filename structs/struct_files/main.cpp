#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <map>
using namespace std;

void do_help(){
    cout<<"1 - to show amount of file types"<<endl;
    cout<<"2 - to show ten biggest files sorted by name"<<endl;
    cout<<"3 - to show presentations with limited access that was changed in 2012 and sorted by names"<<endl;
    cout<<"4 - to show videos that size bigger than 100 Mb and created in second half of 2011 sorted by size"<<endl;
    cout<<"quit - to exit"<<endl;
}

int str_to_int(string str){
    return atoi(str.c_str());
}

struct File_struct{
    string name = "";
    int size = 0;
    string type = "";
    string create_date = "";
    string chage_date = "";
    string access = "";
};

File_struct make_File_struct(string s){
    File_struct temp_File_struct;
    int k = s.find(",");
    temp_File_struct.name = s.substr(0,k);
    s.erase(0,k+1);
    k = s.find(",");
    temp_File_struct.size = str_to_int(s.substr(0,k));
    s.erase(0,k+1);
    k = s.find(",");
    temp_File_struct.type= s.substr(0,k);
    s.erase(0,k+1);
    k = s.find(",");
    temp_File_struct.create_date = s.substr(0,k);
    s.erase(0,k+1);
    k = s.find(",");
    temp_File_struct.chage_date = s.substr(0,k);
    s.erase(0,k+1);
    k = s.find(",");
    temp_File_struct.access = s.substr(0,k);
    s.erase(0,k+1);
    return temp_File_struct;
}

void show_file_types(vector <File_struct> File_struct_list){
    cout<<"Amount of file types:"<<endl;
    map<string,int> m;
    for(File_struct i:File_struct_list){
        if(m.find(i.type) != m.end()){
            m[i.type]++;
        }
        else{
            m[i.type]=0;
        }
    }
    for(const auto& [key, value] : m) {
        cout << key << " = " << value << "; "<<endl;
    }
}

bool is_smaller_size(File_struct &left,File_struct &right){
    return left.size < right.size;
}

void sort_by_size(vector <File_struct> &File_struct_list){
    sort(File_struct_list.begin(),File_struct_list.end(),is_smaller_size);
}

bool name_comp(File_struct &left,File_struct &right){
    return left.name < right.name;
}

void sort_by_name(vector <File_struct> &File_struct_list){
    sort(File_struct_list.begin(),File_struct_list.end(),name_comp);
}

void show_ten_biggers_files(vector <File_struct> File_struct_list){
    cout<<"Ten biggest files sorted by name: "<<endl;
    sort_by_size(File_struct_list);
    vector <File_struct> ten_biggest;
    int len = File_struct_list.size();
    for(int i=len-1;i>=len-10;i--){
        ten_biggest.push_back(File_struct_list[i]);
    }
    sort_by_name(ten_biggest);
    len = ten_biggest.size();
    for(int i=0;i<len;i++){
        cout<<i+1<<" "<<ten_biggest[i].name<<" "<<ten_biggest[i].size<<" Kb"<<endl;
    }
}

void show_presentations_with_limited_access_of_2012_year_sorted_by_names(vector <File_struct> &File_struct_list){
    cout<<"Presentations with limited access that was changed in 2012 and sorted by names: "<<endl;
    vector <File_struct> presentations;
    for(File_struct i: File_struct_list){
        if((i.access == "ограничен")&&(i.chage_date.substr(6,4)=="2012")
           &&(i.type=="презентация")){
            presentations.push_back(i);
        }
    }
    sort_by_name(presentations);
    for(File_struct i: presentations){
        cout<<i.name<<endl;
    }
}

bool is_second_half_of_2011(string date){
    string month = date.substr(3,2);
    string year = date.substr(6,4);
    return (year=="2011") && (str_to_int(month) > 6);
}
bool is_size_bigger_100Mb(int size){
    return ((size/1024) > 100);
}
void show_videos_size_bigger_100Mb_created_second_half_2011_sorted_by_size(vector <File_struct> &File_struct_list){
    cout<<"Videos that size bigger than 100 Mb and created in second half of 2011 sorted by size: "<<endl;
    vector <File_struct> videos;
    for(File_struct i: File_struct_list){
        if((i.type=="видео")&&(is_second_half_of_2011(i.create_date))&&is_size_bigger_100Mb(i.size)){
            videos.push_back(i);
        }
    }
    sort_by_size(videos);
    reverse(videos.begin(),videos.end());
    for(File_struct i: videos){
        cout<<i.name<<" "<<i.size<<" Kb"<<endl;
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    vector <File_struct> File_struct_list;
    string line;
    fstream file;
    file.open("files.csv");
    if(file){
        while(getline(file,line)){
            File_struct_list.push_back(make_File_struct(line));
        }
        cout<<"insert \"help\" to get help"<<endl;
        string c;
        while(true){
            cout<<endl<<"<< ";
            cin>>c;
            cout<<endl;
            if(c=="help"){
                do_help();
            }
            else if(c=="1"){
                show_file_types(File_struct_list);
            }
            else if(c=="2"){
                show_ten_biggers_files(File_struct_list);
            }
            else if(c=="3"){
                show_presentations_with_limited_access_of_2012_year_sorted_by_names(File_struct_list);
            }
            else if(c=="4"){
                show_videos_size_bigger_100Mb_created_second_half_2011_sorted_by_size(File_struct_list);
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
