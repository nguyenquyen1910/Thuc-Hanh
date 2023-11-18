#include<bits/stdc++.h>
using namespace std;
class NhanVien{
    public:
        string id,name,chucvu;
        long long luong,day,thuong,luongtong,phucap,thunhap;
        NhanVien(){
            id=name=chucvu="";
            luong=day=thuong=luongtong=phucap=thunhap=0;
        }
        friend istream& operator >> (istream&, NhanVien&);
        friend ostream& operator << (ostream&, NhanVien);
};
int cnt=0;
istream& operator >> (istream& in, NhanVien& a){
    cnt++;
    a.id="NV"+string(2-to_string(cnt).size(),'0')+to_string(cnt);
    getline(in,a.name);
    in>>a.luong>>a.day>>a.chucvu;
    if(a.chucvu=="GD"){
        a.phucap=250000;
    }
    else if(a.chucvu=="PGD"){
        a.phucap=200000;
    }
    else if(a.chucvu=="TP"){
        a.phucap=180000;
    }
    else a.phucap=150000;
    a.luongtong=a.luong*a.day;
    if(a.day>=25){
        a.thuong=a.luongtong*0.2;
    }
    else if(a.day>=22 && a.day<25){
        a.thuong=a.luongtong*0.1;
    }
    else a.thuong=0;
    a.thunhap=a.luongtong+a.thuong+a.phucap;
    return in;
}
ostream& operator << (ostream& out, NhanVien a){
    out << a.id << " " << a.name << " " << a.luongtong << " " << a.thuong << " " << a.phucap << " " << a.thunhap << endl; 
    return out;
}
int main(){
    NhanVien a;
    cin>>a;
    cout << a;
    return 0;
}