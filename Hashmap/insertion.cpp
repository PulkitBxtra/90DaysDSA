#include<iostream>
#include<unordered_map>
using namespace std;

int main(){


    // initialisation
    unordered_map<string,int> m;


    //method1
    pair<string,int> p=make_pair("pulkit",69);
    m.insert(p);


    // method2
    pair<string,int> p2("batra",96);
    m.insert(p2);
    

    // method3
    m["mera"]=2;
    m["tera"]=3;

    



    cout<<"mera "<<m["mera"]<<endl;
    cout<<"tera "<<m["tera"]<<endl;
    cout<<"pulkit "<<m["pulkit"]<<endl;
    cout<<"batra "<<m["batra"]<<endl;

    cout<<m["unknown"]<<endl;
    cout<<m.at("unknown")<<endl;

    cout<<m.size()<<endl;
    cout<<m.count("pulkit")<<endl;



    //output
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    //output using interator
    unordered_map<string,int> :: iterator it=m.begin();

    while(it != m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }


}
