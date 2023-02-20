#include<iostream>
#include<math.h>
using namespace std;

float area(int r){
    return M_PI*r*r;
}

int main(){

    cout <<"Enter the radius of the circle\n";
    int r;
    cin >> r;

    float result = area(r);
    cout << result << endl;
}