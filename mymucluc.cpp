#include<bits/stdc++.h>
using namespace std;
class MucLuc{
    public:
        string name;
        int page,level;
        MucLuc(){
            name="";
            page=level=0;
        }
        friend ostream& operator << (ostream& out, MucLuc a){
            for(int i=0;i<a.level;i++){
                out << ">";
            }
            out << a.name << "--- ";
            out << a.page << endl;
            return out;
        }
};
bool checkPage(string s){
    return s.find("Page")!=string::npos;
}
bool checkLevel(string s){
    return s.find("Level")!=string::npos;
}
int main(){
    ifstream filein;
    filein.open("VANBAN.txt",ios_base::in);
    MucLuc a[1000];
    string s;
    int cnt=0,id;
    while(getline(filein,s)){
        if(checkPage(s)){
            id=s[5]-'0';
        }
        else if(checkLevel(s)){
            a[cnt].page=id;
            a[cnt].level=s[5]-'0';
            string nametmp="";
            for(int i=8;i<s.size();i++){
                nametmp+=s[i];
            }
            a[cnt].name=nametmp;
            cnt++;
        }
    }
    filein.close();
    ofstream fileout;
    fileout.open("MUCLUC.txt",ios_base::out);
    for(int i=0;i<cnt;i++){
        fileout << a[i];
    }
    return 0;
}