#include<iostream>
using namespace std;

class Hacker{
    public:
    Hacker(){
        cout << "I love to code" <<endl;
    }

};

class hack2{
    public: 
    hack2(){
        cout << "I love hackerearth"<<endl;
    }
};

class hack3: public hack2{};

class hack4: public Hacker, public hack2{};

int main(){
    hack4 obj2;
    return 0;
}