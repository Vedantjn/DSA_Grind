#include <iostream>
using namespace std;
int main()
{
    int k, n;
    cout << "Enter the number of rows : ";
    cin >> n;
    cout << " ";

    for (int i=1; i<=n; i++)
    {
    for (int j=1; j<=n-i; j++)
    cout << " ";

    for (int j=1,k=2*i-1; j<=2*i-1; j++,k--)
    {
    if (j <= k)
        cout << j;
    else
        cout << k;
    }
    cout << endl;

    cout << " ";

    }
    return 0;
}