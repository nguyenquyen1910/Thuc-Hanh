#include<bits/stdc++.h>
using namespace std;
class DanhBa{
    public:
        string name,phone,day,ngay,ho,ten;
        DanhBa(){
            name=phone=day=ngay=ho=ten="";
        }
        friend ostream& operator << (ostream& out, DanhBa a){
            out << a.name << ": " << a.phone << " " << a.ngay << endl;
            return out;
        }
};
bool checkday(string s){
    return s.find("Ngay")!=string::npos;
}
bool checkphone(string s){
    for(int i=0;i<s.size();i++){
        if(!isdigit(s[i])){
            return false;
        }
    }
    return true;
}
string chdate(string s){
    string res="";
    for(int i=5;i<s.size();i++){
        res+=s[i];
    }
    if(res[1]=='/'){
        res="0"+res;
    }
    if(res[4]=='/'){
        res.insert(3,"0");
    }
    return res;
}
string chName(string s){
    string res="";
    string tmp;
    stringstream ss(s);
    while(ss >> tmp){
        res+=toupper(tmp[0]);
        for(int i=1;i<tmp.size();i++){
            res+=tolower(tmp[i]);
        }
        res+=" ";
    }
    res.pop_back();
    return res;
}
string getName(string s){
    vector<string> v;
    stringstream ss(s);
    string tmp;
    while(ss >> tmp){
        v.push_back(tmp);
    }
    return v[v.size()-1];
}
string getHo(string s){
    string res="";
    vector<string> v;
    stringstream ss(s);
    string tmp;
    while(ss >> tmp){
        v.push_back(tmp);
    }
    for(int i=0;i<v.size()-1;i++){
        res=res+v[i]+" ";
    }
    res.pop_back();
    return res;
}
bool cmp(DanhBa a,DanhBa b){
    if(a.ten!=b.ten){
        return a.ten<b.ten;
    }
    return a.ho<b.ho;
}
int main(){
    ifstream filein;
    filein.open("SOTAY.txt",ios_base::in);
    DanhBa a[1000];
    string s,prevdate;
    int cnt=0;
    while(getline(filein,s)){
        if(checkday(s)){
            a[cnt].day=s;
            prevdate=s;
        }
        else if(checkphone(s)){
            a[cnt].phone=s;
            if(a[cnt].day=="") a[cnt].day=prevdate;
            cnt++;
        }
        else{
            a[cnt].name=s;
        }
    }
    filein.close();
    ofstream fileout;
    fileout.open("DIENTHOAI.txt",ios_base::out);
    for(int i=0;i<cnt;i++){
        a[i].ngay=chdate(a[i].day);
        a[i].name=chName(a[i].name);
        a[i].ten=getName(a[i].name);
        a[i].ho=getHo(a[i].name);
    }
    sort(a,a+cnt,cmp);
    for(int i=0;i<cnt;i++){
        fileout << a[i];
    }
    fileout.close();
    return 0;
}