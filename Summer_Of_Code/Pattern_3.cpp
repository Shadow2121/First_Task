#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            cout << " ";
        }
        if(i<3)
        {
            for(int j=0;j<i+1;j++)
                cout << "*" << " ";
            
        }
        else
        {
            cout << "*";
            for(int k=0;k<=i-2;k++)
                cout << " ";
            cout << "*";
            for(int k=0;k<=i-2;k++)
                cout << " ";
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}