#include<iostream>
#include<vector>
using namespace std;

double convert(double celsius){

    vector<double> convertTemperature(double celsius);

        double k = celsius + 273.15;
        double f = celsius * 1.80 + 32.00;

        vector<double> v;
        v.push_back(k);
        v.push_back(f);

        return v;
}

int main(){
    double c;
    cin >> c;

    convert(c);
}