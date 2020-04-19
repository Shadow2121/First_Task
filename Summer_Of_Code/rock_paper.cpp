#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
    char p1,p2;
    int c;
    do{
        cout << "Rock : r\nPaper : p\nScissors : s\n";
        cout << "Player 1 is first, enter your choice: ";
        cin >> p1;
        cout << "Player 2 enter your choice: ";
        cin >> p2;
        if(p1=='r'&&p2=='p')
            cout << "Player 2 win the round";
        if(p2=='r'&&p1=='p')
            cout << "Player 1 win the round";
        if(p1=='r'&&p2=='s')
            cout << "Player 1 win the round";
        if(p1=='s'&&p2=='r')
            cout << "Player 2 win the round";
        if(p1=='s'&&p2=='p')
            cout << "Player 1 win the round";
        if(p1=='p'&&p2=='s')
            cout << "Player 2 win the round";
        if(p1==p2)
            cout << "None ";
        else
            cout << "Invelid inputs!";
        cout << "\nIf you want to exit press 0 or and no. to continue.";
        cin >> c;
    }while(c!=0);
    getch();
    return 0;
}