#include<iostream>
#include<unordered_map>
using namespace std;

int main(){

    // Creation
    unordered_map<string, int> m;

    // Insertion
    pair<string, int> p = make_pair("Scorpio", 9);
    m.insert(p);

    pair<string, int> p2("Alto", 2);
    m.insert(p2);

    m["fortuner"] = 10;

    cout << m.at("alto") << endl;

    // Search
    cout << m.count("Scorpio") << endl;
    if(m.find("fortuner") != m.end()){
        cout << "Fortuner found";
    }
    else{
        cout << "Fortuner not found";
    }

    cout << "Printing all entries: "<< endl;
    for(auto i : m){
        cout << i.first << "->" << i.second<< endl;
    }
    
    return 0;
}