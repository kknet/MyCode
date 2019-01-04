#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

void deal_vector(){
    int cnt = 0;
    string s;
    cin>>s;
    for(auto item:s){
        if(item>='0' && item<='9') cout<<item,cnt++;
        else if(item==',') cout<<" ";
    }
    cout<<endl;
    cout<<cnt<<endl;
}

int main(){
    deal_vector();
    deal_vector();
    return 0;
}