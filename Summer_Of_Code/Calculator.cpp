#include<iostream>

using namespace std;

void add()
{
    int a,b,c;
    cout << "Enter two numbers:\n";
    cin >> a >> b;
    c=a+b;
    cout << "Ans:  " << c << endl;
}
void sub()
{
    int a,b,c;
    cout << "Enter two numbers:\n";
    cin >> a >> b;
    c=a-b;
    cout << "Ans:  " << c << endl;
}
void mul()
{
    int a,b,c;
    cout << "Enter two numbers:\n";
    cin >> a >> b;
    c=a*b;
    cout << "Ans:  " << c << endl;
}
void div()
{
    float a,b;
    float c;
    cout << "Enter two numbers:\n";
    cin >> a >> b;
    c=a/b;
    cout << "Ans:  " << c << endl;
}
void mod()
{
    float c,a,b;
    cout << "You have to insert two numbers M and N. \nmeans M% of N\nEnter two numbers:\n";
    cin >> a >> b;
    c=(b*a)/100;
    cout << "Ans:  " << c << endl; 
}

int main()
{
    int c;
    do{
        cout <<"\n\n\n1. +\n2. -\n3. *\n4. /\n5. %\n6. EXIT\n";
        cout << "Enter your choice:";
        cin >> c;
        switch (c)
        {
            case 1:
                add();
                break;
            
            case 2:
                sub();
                break;

            case 3:
                mul();
                break;
            
            case 4:
                div();
                break;
            
            case 5:
                mod();
                break;

            case 6:
                break;
            
            default:
                break;
        };
    }while(c!=6);
    return 0;
}