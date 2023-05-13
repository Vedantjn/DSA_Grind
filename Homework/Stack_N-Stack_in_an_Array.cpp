#include<iostream>
using namespace std;

// Push X into mth stack
class Nstack{
    int *a, *top, *next;
    int n; // no. of stacks
    int size; // size of main array
    int freeSpot; // tells free space in main array

    public:
    Nstack(int _n, int _s) : n(_n), size(_s)
    {
        freeSpot = 0;
        a = new int[size];
        top = new int[n];
        next = new int[size];

        for(int i = 0; i < n; i++){
            top[1] = -1;
        }

        for(int i = 0; i < size; i++){
            next[i] = i+1;
        }

        next[size-1] = -1;
    }

    bool push(int X, int m){
        if(freeSpot == -1){
            return false; // Stack overflow
        }

        // 1. find index
        int index = freeSpot;

        // 2. Update freeSpot
        freeSpot = next[index];

        //  3. insert
        a[index] = X;

        // 4. Update next
        next[index] = top[m-1];

        // 5. Update top
        top[m-1] = index;

        return true; // Push success
    }

    // Pop from mth stack
    int pop(int m){
        if(top[m-1] == -1){
            return -1; // Stack underflow
        }

        int index = top[m-1];
        top[m-1] = next[index];
        int poppedElement = a[index];
        next[index] = freeSpot;
        freeSpot = index;
        return poppedElement;
    }

    ~Nstack(){
        delete[] a;
        delete[] top;
        delete[] next;
    }
};  


int main(){
    Nstack s(3, 6);

    cout << s.push(10, 1) << endl;
    
    return 0;
}