#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string>
#include<stdlib.h>

using namespace std;
 
class chess
{
    private:
        char a[16][16];
        char Q1='E',Q2='H',Q3='C',Q4='K',Q5='Q',Q6='S';
        char q1='e',q2='h',q3='c',q4='k',q5='q',q6='s';
    public:
        int player=1,check=0;
        chess()
        {
            for(int i=0;i<8;i++)
            {
                for(int j=0;j<8;j++)
                {
                    if(i==0)
                    {
                        if(j==0)
                            a[i][j]=q1;
                        else if(j==1)
                            a[i][j]=q2;
                        else if(j==2)
                            a[i][j]=q3;
                        else if(j==3)
                            a[i][j]=q4;
                        else if(j==4)
                            a[i][j]=q5;
                        else if(j==5)
                            a[i][j]=q3;
                        else if(j==6)
                            a[i][j]=q2;
                        else if(j==7)
                            a[i][j]=q1;                                              
                    }
                    else if(i==1)
                        a[i][j]=q6;
                    else if(i==6)                                           
                        a[i][j]=Q6;                    
                    else if(i==7)
                    {
                        if(j==0)
                            a[i][j]=Q1;
                        else if(j==1)
                            a[i][j]=Q2;
                        else if(j==2)
                            a[i][j]=Q3;
                        else if(j==3)
                            a[i][j]=Q4;
                        else if(j==4)
                            a[i][j]=Q5;
                        else if(j==5)
                            a[i][j]=Q3;
                        else if(j==6)
                            a[i][j]=Q2;
                        else if(j==7)
                            a[i][j]=Q1;
                    }
                    else
                    {
                        a[i][j]=' ';
                    }  
                }          
            }    
            
        }
       /* void show()
        {
            for(int i=-1;i<8;i++)
            {
                for(int j=-1;j<8;j++)
                {
                        if(i==-1)
                        cout  << j << "   ";
                        else
                        {
                            if(j==-1)
                                cout << i << " ";
                            else 
                            cout << "| " << a[i][j] << " " ;
                        }
                    
                }
                cout << endl;
            }
        }*/
        void show()
        {
            for(int i=-1;i<8;i++)
            {
                for(int j=-1;j<8;j++)
                {
                        if(i==-1)
                        cout << "  " << j << "   ";
                        else
                        {
                            if(j==-1)
                                cout << "  " << i << "  ";
                            else 
                                cout << "|  " << a[i][j] << "  " ;                                
                        }
                    
                }
                cout << endl << "    _|_____|_____|_____|_____|_____|_____|_____|_____"<<endl;
                cout << "     |     |     |     |     |     |     |     |     "<<endl;
                
            }
        }
        void move()
        {
            int x,y,m;
            cout << "enter the location of peace you want to move : ";
            cin >> x >> y;
            if(x>=0 && x<8 &&y>=0 && y<8)
            {
                if(player==1)
                {
                    if(a[x][y]=='s')
                    {
                        if(x==1)
                        {
                            a[x+1][y]='*';
                            a[x+2][y]='*';
                        } 
                        else if(a[x+1][y]==' ')
                        {
                            
                            if((x+1)==7)
                            {
                                cout << "press \n1.Elephant\n2.Camel\n3.Horse\n4.quean\nEnter your choice : ";
                                int c;
                                if(c==1)
                                    a[x+1][y]='E';
                                else if(c==2)
                                    a[x+1][y]='C';
                                else if(c==3)
                                    a[x+1][y]='H';
                                else if(c==4)
                                    a[x+1][y]='Q';
                                else
                                    cout << "Invelid input!";
                            }
                            a[x+1][y]='*';
                        }
                        show();
                        if(a[x+1][y+1]!=' ' && x+1<8 && x+1>=0 && y+1<8 && y+1>=0)
                            if(a[x+1][y+1]=='S' || a[x+1][y+1]=='E' || a[x+1][y+1]=='C' || a[x+1][y+1]=='H' || a[x+1][y+1]=='K' || a[x+1][y+1]=='Q')
                            cout << "You can kill " << a[x+1][y+1] << "(" << x+1 << "," << y+1 << ")"  << endl;
                        if(a[x+1][y-1]!=' ' && x+1<8 && x+1>=0 && y-1<8 && y-1>=0)
                            if(a[x+1][y-1]=='S' || a[x+1][y-1]=='E' || a[x+1][y-1]=='C' || a[x+1][y-1]=='H' || a[x+1][y-1]=='K' || a[x+1][y-1]=='Q')
                            cout << "You can kill " << a[x+1][y-1] << "(" << x+1 << "," << y-1 << ")"  << endl;
                        int xs,ys;
                        char temp;
                        cout << "Enter the location you want to go to : ";
                        cin >> xs >> ys;
                        if(a[xs][ys]=='*')
                        {
                            temp=a[xs][ys];
                            a[xs][ys]=a[x][y];
                            a[x][y]=temp;
                        }
                        else
                        {
                            if(a[xs][ys]=='S')
                                {
                                    a[xs][ys]='s';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='E')
                                {
                                    a[xs][ys]='s';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='C')
                                {
                                    a[xs][ys]='s';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='H')
                                {
                                    a[xs][ys]='s';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='K')
                                {
                                    a[xs][ys]='s';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='Q')
                                {
                                    a[xs][ys]='s';
                                    a[x][y]=' ';
                                }
                                else
                                {
                                    cout << "Invelid input!";
                                    if (player==1)
                                        player=1;
                                    else
                                        player=2; 
                                    check=1;                           
                                }
                        }
                        for(int i=0;i<8;i++)
                        {
                            for(int j=0;j<8;j++)
                            {
                                if(a[i][j]=='*')
                                    a[i][j]=' ';
                            }
                        }
                        show();
                        if(check!=1)
                        {
                            if(player==1)
                                player=2;
                            else
                                player=1;
                        }  
                    }
                    else if(a[x][y]=='h')
                    {
                        int tempx=x,tempy=y;
                        if(a[x+1][y+2]==' ')
                            a[x+1][y+2]='*';
                        if(a[x+2][y+1]==' ')
                            a[x+2][y+1]='*';
                        if(a[x-1][y-2]==' ')
                            a[x-1][y-2]='*';
                        if(a[x-2][y-1]==' ')
                            a[x-2][y-1]='*';
                        if(a[x+1][y-2]==' ')
                            a[x+1][y-2]='*';
                        if(a[x+2][y-1]==' ')
                            a[x+2][y-1]='*';
                        if(a[x-1][y+2]==' ')
                            a[x-1][y+2]='*';
                        if(a[x-2][y+1]==' ')
                            a[x-2][y+1]='*';
                        show();
                        
                        char arr[6] = {'S','E','H','C','K','Q'};
                        if(a[x][y]=='h')
                        {
                            for(int i=0;i<6;i++)
                            {
                                if(a[x+1][y+2]==arr[i])
                                    cout << "You can kill " << a[x+1][y+2] << "(" << x+1 << "," << y+2 << ")"<< endl;
                                if(a[x+2][y+1]==arr[i])
                                    cout << "You can kill " << a[x+2][y+1]<< "(" << x+2 << "," << y+1 << ")"<< endl;
                                if(a[x-1][y-2]==arr[i])
                                    cout << "You can kill " << a[x-1][y-2] << "(" << x-1 << "," << y-2 << ")" << endl;
                                if(a[x-2][y-1]==arr[i])
                                    cout << "You can kill " << a[x-2][y-1] << "(" << x-2 << "," << y-1 << ")"<< endl;
                                if(a[x+1][y-2]==arr[i])
                                    cout << "You can kill " << a[x+1][y-2]<< "(" << x+1 << "," << y-2 << ")"<< endl;
                                if(a[x+2][y-1]==arr[i])
                                    cout << "You can kill " << a[x+2][y-1] <<  "(" << x+2 << "," << y-1 << ")" << endl;
                                if(a[x-1][y+2]==arr[i])
                                    cout << "You can kill " << a[x-1][y+2]<< "(" << x-1 << "," << y+2 << ")"<< endl;
                                if(a[x-2][y+1]==arr[i])
                                    cout << "You can kill " << a[x-2][y+1]<< "(" << x-2 << "," << y+1 << ")"<< endl;
                            }
                        } 
                        
                        /*if(a[x-1][y-2]=='k')
                            cout <<"You can kill " <<  a[x-1][y-2] << endl;
                        if(a[x-1][y+2]=='e')
                            cout <<"You can kill " <<  a[x-1][y+2] << endl;
                        if(a[x-2][y-1]=='k')
                            cout <<"You can kill " <<  a[x-2][y-1] << endl;*/

                        int xs,ys;
                        char temp;
                        cout << "Enter the location you want to go to : ";
                        cin >> xs >> ys;
                        if(a[xs][ys]=='*')
                        {
                            temp=a[xs][ys];
                            a[xs][ys]=a[x][y];
                            a[x][y]=temp;
                        }
                        else{
                            
                            if(a[x][y]=='h')
                            {
                                if(a[xs][ys]=='S')
                                {
                                    a[xs][ys]='h';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='E')
                                {
                                    a[xs][ys]='h';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='C')
                                {
                                    a[xs][ys]='h';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='H')
                                {
                                    a[xs][ys]='h';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='K')
                                {
                                    a[xs][ys]='h';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='Q')
                                {
                                    a[xs][ys]='h';
                                    a[x][y]=' ';
                                }
                                else
                                {
                                    cout << "Invelid input!";
                                    if (player==1)
                                        player=1;
                                    else
                                        player=2;  
                                    check=1;                          
                                }
                            }
                        }
                        for(int i=0;i<8;i++)
                        {
                            for(int j=0;j<8;j++)
                            {
                                if(a[i][j]=='*')
                                    a[i][j]=' ';
                            }
                        }
                        show();  
                        if(check!=1)
                        {
                            if(player==1)
                                player=2;
                            else
                                player=1;
                        }      
                    }
                    else if(a[x][y]=='e')
                    {
                        int tempx=x,tempy=y,xs,ys;
                        char temp;
                        x++;
                        while(a[x][y]==' ')
                        {
                            a[x][y]='*';
                            x++;
                        }
                        if(a[x][y]!=' ' && x<8 && x>=0 && y<8 && y>=0)
                            if(a[x][y]=='S' || a[x][y]=='E' || a[x][y]=='C' || a[x][y]=='H' || a[x][y]=='K' || a[x][y]=='Q')
                                cout << "You can kill " << a[x][y] << "(" << x << "," << y << ")" << endl;
                        x=tempx-1;
                        while(a[x][y]==' ')
                        {
                            a[x][y]='*';
                            x--;
                        }
                        if(a[x][y]!=' ' && x<8 && x>=0 && y<8 && y>=0)
                            if(a[x][y]=='S' || a[x][y]=='E' || a[x][y]=='C' || a[x][y]=='H' || a[x][y]=='K' || a[x][y]=='Q')
                                cout << "You can kill " << a[x][y] << "(" << x << "," << y << ")" << endl;
                        x=tempx;
                        y=tempy+1;
                        while(a[x][y]==' ')
                        {
                            a[x][y]='*';
                            y++;
                            
                        }
                        if(a[x][y]!=' ' && x<8 && x>=0 && y<8 && y>=0)
                            if(a[x][y]=='S' || a[x][y]=='E' || a[x][y]=='C' || a[x][y]=='H' || a[x][y]=='K' || a[x][y]=='Q')
                                cout << "You can kill " << a[x][y] << "(" << x << "," << y << ")" << endl;
                        y=tempy-1;
                        while(a[x][y]==' ')
                        {
                            a[x][y]='*';
                            y--;
                            
                        }
                        if(a[x][y]!=' ' && x<8 && x>=0 && y<8 && y>=0)
                            if(a[x][y]=='S' || a[x][y]=='E' || a[x][y]=='C' || a[x][y]=='H' || a[x][y]=='K' || a[x][y]=='Q')
                                cout << "You can kill " << a[x][y] << "(" << x << "," << y << ")" << endl;
                        x=tempx;
                        y=tempy;
                        show();
                        cout << "If can kill some-one it will show above\n" ;
                        cout << "Enter the location you want to go to : ";
                        cin >> xs >> ys;
                        if(a[xs][ys]=='*')
                        {
                            temp=a[xs][ys];
                            a[xs][ys]=a[x][y];
                            a[x][y]=temp;
                        }
                        else{
                            if(a[x][y]=='e')
                            {
                                if(a[xs][ys]=='S')
                                {
                                    a[xs][ys]='e';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='E')
                                {
                                    a[xs][ys]='e';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='C')
                                {
                                    a[xs][ys]='e';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='H')
                                {
                                    a[xs][ys]='e';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='K')
                                {
                                    a[xs][ys]='e';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='Q')
                                {
                                    a[xs][ys]='e';
                                    a[x][y]=' ';
                                }
                                else
                                {
                                    cout << "Invelid input!";
                                    if (player==1)
                                        player=1;
                                    else
                                        player=2;  
                                    check=1;                          
                                }
                            }
                        }
                        for(int i=0;i<8;i++)
                        {
                            for(int j=0;j<8;j++)
                            {
                                if(a[i][j]=='*')
                                    a[i][j]=' ';
                            }
                        }
                        show(); 
                        if(check!=1)
                        {
                            if(player==1)
                                player=2;
                            else
                                player=1;
                        }  
                    }
                    else if(a[x][y]=='k')
                    {
                        if(a[x-1][y-1]==' ')
                            a[x-1][y-1]='*';
                        if(a[x-1][y]==' ')
                            a[x-1][y]='*';
                        if(a[x-1][y+1]==' ')
                            a[x-1][y+1]='*';
                        if(a[x][y-1]==' ')
                            a[x][y-1]='*';
                        if(a[x][y+1]==' ')
                            a[x][y+1]='*';
                        if(a[x+1][y-1]==' ')
                            a[x+1][y-1]='*';
                        if(a[x+1][y]==' ')
                            a[x+1][y]='*';
                        if(a[x+1][y+1]==' ')
                            a[x+1][y+1]='*';
                        show();
                        
                        char arr[6] = {'S','E','H','C','K','Q'};
                        if(a[x][y]=='k')
                        {
                            for(int i=0;i<6;i++)
                            {
                                if(a[x-1][y-1]==arr[i])
                                    cout << "You can kill " << a[x-1][y-1] << "(" << x-1 << "," << y-1 << ")" << endl;
                                if(a[x-1][y]==arr[i])
                                    cout << "You can kill " << a[x-1][y]<< "(" << x-1 << "," << y << ")" << endl;
                                if(a[x-1][y+1]==arr[i])
                                    cout << "You can kill " << a[x-1][y+1]<< "(" << x-1 << "," << y+1 << ")" << endl;
                                if(a[x][y-1]==arr[i])
                                    cout << "You can kill " << a[x][y-1]<< "(" << x << "," << y-1 << ")" << endl;
                                if(a[x][y+1]==arr[i])
                                    cout << "You can kill " << a[x][y+1]<< "(" << x << "," << y+1 << ")" << endl;
                                if(a[x+1][y-1]==arr[i])
                                    cout << "You can kill " << a[x+1][y-1]<< "(" << x+1 << "," << y-1 << ")" << endl;
                                if(a[x+1][y]==arr[i])
                                    cout << "You can kill " << a[x+1][y]<< "(" << x+1 << "," << y << ")" << endl;
                                if(a[x+1][y+1]==arr[i])
                                    cout << "You can kill " << a[x+1][y+1]<< "(" << x+1 << "," << y+1 << ")" << endl;
                            }
                        }

                        int xs,ys;
                        char temp;
                        cout << "Enter the location you want to go to : ";
                        cin >> xs >> ys;
                        if(a[xs][ys]=='*')
                        {
                            temp=a[xs][ys];
                            a[xs][ys]=a[x][y];
                            a[x][y]=temp;
                        }
                        else{
                            
                            if(a[x][y]=='k')
                            {
                                if(a[xs][ys]=='S')
                                {
                                    a[xs][ys]='k';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='E')
                                {
                                    a[xs][ys]='k';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='C')
                                {
                                    a[xs][ys]='k';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='H')
                                {
                                    a[xs][ys]='k';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='K')
                                {
                                    a[xs][ys]='k';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='Q')
                                {
                                    a[xs][ys]='k';
                                    a[x][y]=' ';
                                }
                                else
                                {
                                    cout << "Invelid input!";
                                    if (player==1)
                                        player=1;
                                    else
                                        player=2;   
                                    check=1;                         
                                }
                            }
                        }
                        for(int i=0;i<8;i++)
                        {
                            for(int j=0;j<8;j++)
                            {
                                if(a[i][j]=='*')
                                    a[i][j]=' ';
                            }
                        }
                        show(); 
                        if(check!=1)
                        {
                            if(player==1)
                                player=2;
                            else
                                player=1;
                        }  
                    }
                    
                    else if(a[x][y]=='q')
                    {
                        int tempx=x,tempy=y;
                        x++;
                        y++;
                        while(a[x][y]==' ')
                        {
                            a[x][y]='*';
                            x++;
                            y++;
                        }
                        if(a[x][y]!=' ' && x<8 && x>=0 && y<8 && y>=0) 
                                if(a[x][y]=='S'||a[x][y]=='E' || a[x][y]=='C' || a[x][y]=='H' || a[x][y]=='K' || a[x][y]=='Q')
                                    cout << "You can kill " << a[x][y] << "(" << x << "," << y << ")" << endl;
                        x=tempx;
                        y=tempy;
                        x--;
                        y--;
                        while(a[x][y]==' ')
                        {
                            a[x][y]='*';
                            x--;
                            y--;
                        }
                        if(a[x][y]!=' ' && x<8 && x>=0 && y<8 && y>=0) 
                                if(a[x][y]=='S'||a[x][y]=='E' || a[x][y]=='C' || a[x][y]=='H' || a[x][y]=='K' || a[x][y]=='Q')
                                    cout << "You can kill " << a[x][y] << "(" << x << "," << y << ")" << endl;
                        x=tempx;
                        y=tempy;
                        x--;
                        y++;
                        while(a[x][y]==' ')
                        {
                            a[x][y]='*';
                            x--;
                            y++;
                        }
                        if(a[x][y]!=' ' && x<8 && x>=0 && y<8 && y>=0) 
                                if(a[x][y]=='S'||a[x][y]=='E' || a[x][y]=='C' || a[x][y]=='H' || a[x][y]=='K' || a[x][y]=='Q')
                                    cout << "You can kill " << a[x][y] << "(" << x << "," << y << ")" << endl;
                        x=tempx;
                        y=tempy;
                        x++;
                        y--;
                        while(a[x][y]==' ')
                        {
                            a[x][y]='*';
                            x++;
                            y--;
                        }
                        if(a[x][y]!=' ' && x<8 && x>=0 && y<8 && y>=0) 
                                if(a[x][y]=='S'||a[x][y]=='E' || a[x][y]=='C' || a[x][y]=='H' || a[x][y]=='K' || a[x][y]=='Q')
                                    cout << "You can kill " << a[x][y] << "(" << x << "," << y << ")" << endl;
                        x=tempx;
                        y=tempy;
                        char temp;
                        x++;
                        while(a[x][y]==' ')
                        {
                            a[x][y]='*';
                            x++;
                        }
                        if(a[x][y]!=' ' && x<8 && x>=0 && y<8 && y>=0)
                            if(a[x][y]=='S' || a[x][y]=='E' || a[x][y]=='C' || a[x][y]=='H' || a[x][y]=='K' || a[x][y]=='Q')
                                cout << "You can kill " << a[x][y] << "(" << x << "," << y << ")" << endl;
                        x=tempx-1;
                        while(a[x][y]==' ')
                        {
                            a[x][y]='*';
                            x--;
                        }
                        if(a[x][y]!=' ' && x<8 && x>=0 && y<8 && y>=0)
                            if(a[x][y]=='S' || a[x][y]=='E' || a[x][y]=='C' || a[x][y]=='H' || a[x][y]=='K' || a[x][y]=='Q')
                                cout << "You can kill " << a[x][y] << "(" << x << "," << y << ")" << endl;
                        x=tempx;
                        y=tempy+1;
                        while(a[x][y]==' ')
                        {
                            a[x][y]='*';
                            y++;
                            
                        }
                        if(a[x][y]!=' ' && x<8 && x>=0 && y<8 && y>=0)
                            if(a[x][y]=='S' || a[x][y]=='E' || a[x][y]=='C' || a[x][y]=='H' || a[x][y]=='K' || a[x][y]=='Q')
                                cout << "You can kill " << a[x][y] << "(" << x << "," << y << ")" << endl;
                        y=tempy-1;
                        while(a[x][y]==' ')
                        {
                            a[x][y]='*';
                            y--;
                            
                        }
                        if(a[x][y]!=' ' && x<8 && x>=0 && y<8 && y>=0)
                            if(a[x][y]=='S' || a[x][y]=='E' || a[x][y]=='C' || a[x][y]=='H' || a[x][y]=='K' || a[x][y]=='Q')
                                cout << "You can kill " << a[x][y] << "(" << x << "," << y << ")" << endl;
                        x=tempx;
                        y=tempy;
                        show();
                        cout << "If can kill some-one it will show above\n" ;
                        int xs,ys;
                        cout << "Enter the location you want to go to : ";
                        cin >> xs >> ys;
                        if(a[xs][ys]=='*')
                        {
                            temp=a[xs][ys];
                            a[xs][ys]=a[x][y];
                            a[x][y]=temp;
                        }
                        else
                        {
                            if(a[x][y]=='q')
                            {
                                if(a[xs][ys]=='S')
                                {
                                    a[xs][ys]='q';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='E')
                                {
                                    a[xs][ys]='q';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='C')
                                {
                                    a[xs][ys]='q';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='H')
                                {
                                    a[xs][ys]='q';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='K')
                                {
                                    a[xs][ys]='q';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='Q')
                                {
                                    a[xs][ys]='q';
                                    a[x][y]=' ';
                                }
                                else
                                {
                                    cout << "Invelid input!";
                                    if (player==1)
                                        player=1;
                                    else
                                        player=2;   
                                    check=1;                         
                                }
                            }
                        }
                        
                        for(int i=0;i<8;i++)
                        {
                            for(int j=0;j<8;j++)
                            {
                                if(a[i][j]=='*')
                                    a[i][j]=' ';
                            }
                        }
                        show();
                        if(check!=1)
                        {
                            if(player==1)
                                player=2;
                            else
                                player=1;
                        }      
                    }
                    else if(a[x][y]=='c')
                    {
                        int tempx=x,tempy=y;
                        x++;
                        y++;
                        while(a[x][y]==' ')
                        {
                            a[x][y]='*';
                            x++;
                            y++;
                        }
                        if(a[x][y]!=' ' && x<8 && x>=0 && y<8 && y>=0) 
                                if(a[x][y]=='S'||a[x][y]=='E' || a[x][y]=='C' || a[x][y]=='H' || a[x][y]=='K' || a[x][y]=='Q')
                                    cout << "You can kill " << a[x][y] << "(" << x << "," << y << ")" << endl;
                        x=tempx;
                        y=tempy;
                        x--;
                        y--;
                        while(a[x][y]==' ')
                        {
                            a[x][y]='*';
                            x--;
                            y--;
                        }
                        if(a[x][y]!=' ' && x<8 && x>=0 && y<8 && y>=0) 
                                if(a[x][y]=='S'||a[x][y]=='E' || a[x][y]=='C' || a[x][y]=='H' || a[x][y]=='K' || a[x][y]=='Q')
                                    cout << "You can kill " << a[x][y] << "(" << x << "," << y << ")" << endl;
                        x=tempx;
                        y=tempy;
                        x--;
                        y++;
                        while(a[x][y]==' ')
                        {
                            a[x][y]='*';
                            x--;
                            y++;
                        }
                        if(a[x][y]!=' ' && x<8 && x>=0 && y<8 && y>=0) 
                                if(a[x][y]=='S'||a[x][y]=='E' || a[x][y]=='C' || a[x][y]=='H' || a[x][y]=='K' || a[x][y]=='Q')
                                    cout << "You can kill " << a[x][y] << "(" << x << "," << y << ")" << endl;
                        x=tempx;
                        y=tempy;
                        x++;
                        y--;
                        while(a[x][y]==' ')
                        {
                            a[x][y]='*';
                            x++;
                            y--;
                        }
                        if(a[x][y]!=' ' && x<8 && x>=0 && y<8 && y>=0) 
                                if(a[x][y]=='S'||a[x][y]=='E' || a[x][y]=='C' || a[x][y]=='H' || a[x][y]=='K' || a[x][y]=='Q')
                                    cout << "You can kill " << a[x][y] << "(" << x << "," << y << ")" << endl;
                        x=tempx;
                        y=tempy;
                        show();
                        cout << "If can kill some-one it will show above\n" ;
                        int xs,ys;
                        char temp;
                        cout << "Enter the location you want to go to : ";
                        cin >> xs >> ys;
                        if(a[xs][ys]=='*')
                        {
                            temp=a[xs][ys];
                            a[xs][ys]=a[x][y];
                            a[x][y]=temp;
                        }
                        else
                        {
                            if(a[x][y]=='c')
                            {
                                if(a[xs][ys]=='S')
                                {
                                    a[xs][ys]='c';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='E')
                                {
                                    a[xs][ys]='c';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='C')
                                {
                                    a[xs][ys]='c';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='H')
                                {
                                    a[xs][ys]='c';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='K')
                                {
                                    a[xs][ys]='c';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='Q')
                                {
                                    a[xs][ys]='c';
                                    a[x][y]=' ';
                                }
                                else
                                {
                                    cout << "Invelid input!";
                                    if (player==1)
                                        player=1;
                                    else
                                        player=2; 
                                    check=1;                           
                                }
                            }
                        }
                        
                        for(int i=0;i<8;i++)
                        {
                            for(int j=0;j<8;j++)
                            {
                                if(a[i][j]=='*')
                                    a[i][j]=' ';
                            }
                        }
                        show();  
                        if(check!=1)
                        {
                            if(player==1)
                                player=2;
                            else
                                player=1;
                        }         
                    }
                    else
                    {
                        cout << "There is nothing to move!!\n";
                    }
                }
                else
                {
                    if(a[x][y]=='S')
                    {
                        if(x==6)
                        {
                            a[x-1][y]='*';
                            a[x-2][y]='*'; 
                        }
                        else if(a[x-1][y]==' ')
                        {
                            
                            if((x-1)==0)
                            {
                                cout << "press \n1.Elephant\n2.Camel\n3.Horse\n4.quean\nEnter your choice : ";
                                int c;
                                if(c==1)
                                    a[x-1][y]='E';
                                else if(c==2)
                                    a[x-1][y]='C';
                                else if(c==3)
                                    a[x-1][y]='H';
                                else if(c==4)
                                    a[x-1][y]='Q';
                                else
                                    cout << "Invelid input!";
                            }
                            a[x-1][y]='*';
                        }
                        show();
                        if(a[x-1][y+1]!=' ' && x-1<8 && x-1>=0 && y+1<8 && y+1>=0)
                            if(a[x-1][y+1]=='S' || a[x-1][y+1]=='E' || a[x-1][y+1]=='C' || a[x-1][y+1]=='H' || a[x-1][y+1]=='K' || a[x-1][y+1]=='Q')
                            cout << "You can kill " << a[x-1][y+1] << "(" << x-1 << "," << y+1 << ")"  << endl;
                        if(a[x-1][y-1]!=' ' && x-1<8 && x-1>=0 && y-1<8 && y-1>=0)
                            if(a[x-1][y-1]=='S' || a[x-1][y-1]=='E' || a[x-1][y-1]=='C' || a[x-1][y-1]=='H' || a[x-1][y-1]=='K' || a[x-1][y-1]=='Q')
                            cout << "You can kill " << a[x-1][y-1] << "(" << x-1 << "," << y-1 << ")"  << endl;
                        int xs,ys;
                        char temp;
                        cout << "Enter the location you want to go to : ";
                        cin >> xs >> ys;
                        if(a[xs][ys]=='*')
                        {
                            temp=a[xs][ys];
                            a[xs][ys]=a[x][y];
                            a[x][y]=temp;
                        }
                        else
                        {
                            if(a[xs][ys]=='s')
                                {
                                    a[xs][ys]='S';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='e')
                                {
                                    a[xs][ys]='S';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='c')
                                {
                                    a[xs][ys]='S';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='h')
                                {
                                    a[xs][ys]='S';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='k')
                                {
                                    a[xs][ys]='S';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='q')
                                {
                                    a[xs][ys]='S';
                                    a[x][y]=' ';
                                }
                                else
                                {
                                    cout << "Invelid input!";
                                    if (player==1)
                                        player=1;
                                    else
                                        player=2;     
                                    check=1;                       
                                }
                        }
                        
                        for(int i=0;i<8;i++)
                        {
                            for(int j=0;j<8;j++)
                            {
                                if(a[i][j]=='*')
                                    a[i][j]=' ';
                            }
                        }
                        show();
                        if(check!=1)
                        {
                            if(player==1)
                                player=2;
                            else
                                player=1;
                        }  
                    }
                    
                    else if(a[x][y]=='E')
                    {
                        int tempx=x,tempy=y,xs,ys;
                        char temp;
                        x++;
                        while(a[x][y]==' ')
                        {
                            a[x][y]='*';
                            x++;
                        }
                        if(a[x][y]!=' ' && x<8 && x>=0 && y<8 && y>=0)
                            if(a[x][y]=='s' || a[x][y]=='e' || a[x][y]=='c' || a[x][y]=='h' || a[x][y]=='k' || a[x][y]=='q')
                                cout << "You can kill " << a[x][y] << "(" << x << "," << y << ")" << endl;
                        x=tempx-1;
                        while(a[x][y]==' ')
                        {
                            a[x][y]='*';
                            x--;
                        }
                        if(a[x][y]!=' ' && x<8 && x>=0 && y<8 && y>=0)
                            if(a[x][y]=='s' || a[x][y]=='e' || a[x][y]=='c' || a[x][y]=='h' || a[x][y]=='k' || a[x][y]=='q')
                                cout << "You can kill " << a[x][y] << "(" << x << "," << y << ")" << endl;
                        x=tempx;
                        y=tempy+1;
                        while(a[x][y]==' ')
                        {
                            a[x][y]='*';
                            y++;
                            
                        }
                        if(a[x][y]!=' ' && x<8 && x>=0 && y<8 && y>=0)
                            if(a[x][y]=='s' || a[x][y]=='e' || a[x][y]=='c' || a[x][y]=='h' || a[x][y]=='k' || a[x][y]=='q')
                                cout << "You can kill " << a[x][y] << "(" << x << "," << y << ")" << endl;
                        y=tempy-1;
                        while(a[x][y]==' ')
                        {
                            a[x][y]='*';
                            y--;
                            
                        }
                        if(a[x][y]!=' ' && x<8 && x>=0 && y<8 && y>=0)
                            if(a[x][y]=='s' || a[x][y]=='e' || a[x][y]=='c' || a[x][y]=='h' || a[x][y]=='k' || a[x][y]=='q')
                                cout << "You can kill " << a[x][y] << "(" << x << "," << y << ")" << endl;
                        x=tempx;
                        y=tempy;
                        show();
                        cout << "If can kill some-one it will show above\n" ;
                        cout << "Enter the location you want to go to : ";
                        cin >> xs >> ys;
                        if(a[xs][ys]=='*')
                        {
                            temp=a[xs][ys];
                            a[xs][ys]=a[x][y];
                            a[x][y]=temp;
                        }
                        else{
                            if(a[x][y]=='E')
                            {
                                if(a[xs][ys]=='s')
                                {
                                    a[xs][ys]='E';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='e')
                                {
                                    a[xs][ys]='E';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='c')
                                {
                                    a[xs][ys]='E';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='h')
                                {
                                    a[xs][ys]='E';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='k')
                                {
                                    a[xs][ys]='E';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='q')
                                {
                                    a[xs][ys]='E';
                                    a[x][y]=' ';
                                }
                                else
                                {
                                    cout << "Invelid input!";
                                    if (player==1)
                                        player=1;
                                    else
                                        player=2;  
                                    check=1;                          
                                }
                            }                    
                        }
                        for(int i=0;i<8;i++)
                        {
                            for(int j=0;j<8;j++)
                            {
                                if(a[i][j]=='*')
                                    a[i][j]=' ';
                            }
                        }
                        show();
                        if(check!=1)
                        {
                            if(player==1)
                                player=2;
                            else
                                player=1;
                        }   
                    }

                    else if(a[x][y]=='K')
                    {
                        if(a[x-1][y-1]==' ')
                            a[x-1][y-1]='*';
                        if(a[x-1][y]==' ')
                            a[x-1][y]='*';
                        if(a[x-1][y+1]==' ')
                            a[x-1][y+1]='*';
                        if(a[x][y-1]==' ')
                            a[x][y-1]='*';
                        if(a[x][y+1]==' ')
                            a[x][y+1]='*';
                        if(a[x+1][y-1]==' ')
                            a[x+1][y-1]='*';
                        if(a[x+1][y]==' ')
                            a[x+1][y]='*';
                        if(a[x+1][y+1]==' ')
                            a[x+1][y+1]='*';
                        show();
                        char ar[6] = {'s','e','h','c','k','q'};
                        if(a[x][y]=='K')
                        {
                            for(int i=0;i<6;i++)
                            {
                                if(a[x-1][y-1]==ar[i])
                                    cout << "You can kill " << a[x-1][y-1] << "(" << x-1 << "," << y-1 << ")" << endl;
                                if(a[x-1][y]==ar[i])
                                    cout << "You can kill " << a[x-1][y]<< "(" << x-1 << "," << y << ")" << endl;
                                if(a[x-1][y+1]==ar[i])
                                    cout << "You can kill " << a[x-1][y+1]<< "(" << x-1 << "," << y+1 << ")" << endl;
                                if(a[x][y-1]==ar[i])
                                    cout << "You can kill " << a[x][y-1]<< "(" << x << "," << y-1 << ")" << endl;
                                if(a[x][y+1]==ar[i])
                                    cout << "You can kill " << a[x][y+1]<< "(" << x << "," << y+1 << ")" << endl;
                                if(a[x+1][y-1]==ar[i])
                                    cout << "You can kill " << a[x+1][y-1]<< "(" << x+1 << "," << y-1 << ")" << endl;
                                if(a[x+1][y]==ar[i])
                                    cout << "You can kill " << a[x+1][y]<< "(" << x+1 << "," << y << ")" << endl;
                                if(a[x+1][y+1]==ar[i])
                                    cout << "You can kill " << a[x+1][y+1]<< "(" << x+1 << "," << y+1 << ")" << endl;
                            }
                        }
                        int xs,ys;
                        char temp;
                        cout << "Enter the location you want to go to : ";
                        cin >> xs >> ys;
                        if(a[xs][ys]=='*')
                        {
                            temp=a[xs][ys];
                            a[xs][ys]=a[x][y];
                            a[x][y]=temp;
                        }
                        else{
                            if(a[x][y]=='K')
                            {
                                if(a[xs][ys]=='s')
                                {
                                    a[xs][ys]='K';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='e')
                                {
                                    a[xs][ys]='K';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='c')
                                {
                                    a[xs][ys]='K';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='h')
                                {
                                    a[xs][ys]='K';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='k')
                                {
                                    a[xs][ys]='K';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='q')
                                {
                                    a[xs][ys]='K';
                                    a[x][y]=' ';
                                }
                                else
                                {
                                    cout << "Invelid input!";
                                    if (player==1)
                                        player=1;
                                    else
                                        player=2;                            
                                }
                            }                                                
                        }
                        for(int i=0;i<8;i++)
                        {
                            for(int j=0;j<8;j++)
                            {
                                if(a[i][j]=='*')
                                    a[i][j]=' ';
                            }
                        }
                        show(); 
                        if(check!=1)
                        {
                            if(player==1)
                                player=2;
                            else
                                player=1;
                        }  
                    }
                    
                    
                    else if(a[x][y]=='Q')
                    {
                        int tempx=x,tempy=y;
                        x++;
                        y++;
                        while(a[x][y]==' ')
                        {
                            a[x][y]='*';
                            x++;
                            y++;
                        }
                        if(a[x][y]!=' ' && x<8 && x>=0 && y<8 && y>=0) 
                                if(a[x][y]=='s'||a[x][y]=='e' || a[x][y]=='c' || a[x][y]=='h' || a[x][y]=='k' || a[x][y]=='q')
                                    cout << "You can kill " << a[x][y] << "(" << x << "," << y << ")" << endl;
                        x=tempx;
                        y=tempy;
                        x--;
                        y--;
                        while(a[x][y]==' ')
                        {
                            a[x][y]='*';
                            x--;
                            y--;
                        }
                        if(a[x][y]!=' ' && x<8 && x>=0 && y<8 && y>=0) 
                                if(a[x][y]=='s'||a[x][y]=='e' || a[x][y]=='c' || a[x][y]=='h' || a[x][y]=='k' || a[x][y]=='q')
                                    cout << "You can kill " << a[x][y] << "(" << x << "," << y << ")" << endl;
                        x=tempx;
                        y=tempy;
                        x--;
                        y++;
                        while(a[x][y]==' ')
                        {
                            a[x][y]='*';
                            x--;
                            y++;
                        }
                        if(a[x][y]!=' ' && x<8 && x>=0 && y<8 && y>=0) 
                                if(a[x][y]=='s'||a[x][y]=='e' || a[x][y]=='c' || a[x][y]=='h' || a[x][y]=='k' || a[x][y]=='q')
                                    cout << "You can kill " << a[x][y] << "(" << x << "," << y << ")" << endl;
                        x=tempx;
                        y=tempy;
                        x++;
                        y--;
                        while(a[x][y]==' ')
                        {
                            a[x][y]='*';
                            x++;
                            y--;
                        }
                        if(a[x][y]!=' ' && x<8 && x>=0 && y<8 && y>=0) 
                                if(a[x][y]=='s'||a[x][y]=='e' || a[x][y]=='c' || a[x][y]=='h' || a[x][y]=='k' || a[x][y]=='q')
                                    cout << "You can kill " << a[x][y] << "(" << x << "," << y << ")" << endl;
                        x=tempx;
                        y=tempy;
                        x++;
                        while(a[x][y]==' ')
                        {
                            a[x][y]='*';
                            x++;
                        }
                        if(a[x][y]!=' ' && x<8 && x>=0 && y<8 && y>=0)
                            if(a[x][y]=='s' || a[x][y]=='e' || a[x][y]=='c' || a[x][y]=='h' || a[x][y]=='k' || a[x][y]=='q')
                                cout << "You can kill " << a[x][y] << "(" << x << "," << y << ")" << endl;
                        x=tempx-1;
                        while(a[x][y]==' ')
                        {
                            a[x][y]='*';
                            x--;
                        }
                        if(a[x][y]!=' ' && x<8 && x>=0 && y<8 && y>=0)
                            if(a[x][y]=='s' || a[x][y]=='e' || a[x][y]=='c' || a[x][y]=='h' || a[x][y]=='k' || a[x][y]=='q')
                                cout << "You can kill " << a[x][y] << "(" << x << "," << y << ")" << endl;
                        x=tempx;
                        y=tempy+1;
                        while(a[x][y]==' ')
                        {
                            a[x][y]='*';
                            y++;
                            
                        }
                    if(a[x][y]!=' ' && x<8 && x>=0 && y<8 && y>=0)
                            if(a[x][y]=='s' || a[x][y]=='e' || a[x][y]=='c' || a[x][y]=='h' || a[x][y]=='k' || a[x][y]=='q')
                                cout << "You can kill " << a[x][y] << "(" << x << "," << y << ")" << endl;
                        y=tempy-1;
                        while(a[x][y]==' ')
                        {
                            a[x][y]='*';
                            y--;
                            
                        }
                        if(a[x][y]!=' ' && x<8 && x>=0 && y<8 && y>=0)
                            if(a[x][y]=='s' || a[x][y]=='e' || a[x][y]=='c' || a[x][y]=='h' || a[x][y]=='k' || a[x][y]=='q')
                                cout << "You can kill " << a[x][y] << "(" << x << "," << y << ")" << endl;
                        x=tempx;
                        y=tempy;
                        show();
                        cout << "If can kill some-one it will show above\n" ;
                        cout << "Enter the location you want to go to : ";
                        int xs,ys;
                        char temp;
                        cin >> xs >> ys;
                        if(a[xs][ys]=='*')
                        {
                            temp=a[xs][ys];
                            a[xs][ys]=a[x][y];
                            a[x][y]=temp;
                        }
                        else{
                            if(a[x][y]=='Q')
                            {
                                if(a[xs][ys]=='s')
                                {
                                    a[xs][ys]='Q';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='e')
                                {
                                    a[xs][ys]='Q';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='c')
                                {
                                    a[xs][ys]='Q';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='h')
                                {
                                    a[xs][ys]='Q';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='k')
                                {
                                    a[xs][ys]='Q';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='q')
                                {
                                    a[xs][ys]='Q';
                                    a[x][y]=' ';
                                }
                                else
                                {
                                    cout << "Invelid input!";
                                    if (player==1)
                                        player=1;
                                    else
                                        player=2;
                                    check=1;                            
                                }
                            }                    
                        }
                        for(int i=0;i<8;i++)
                        {
                            for(int j=0;j<8;j++)
                            {
                                if(a[i][j]=='*')
                                    a[i][j]=' ';
                            }
                        }
                        show(); 
                        if(check!=1)
                        {
                            if(player==1)
                                player=2;
                            else
                                player=1;
                        }  
                    }

                    
                    else if(a[x][y]=='C')
                    {
                        int tempx=x,tempy=y;
                        x++;
                        y++;
                        while(a[x][y]==' ')
                        {
                            a[x][y]='*';
                            x++;
                            y++;
                        }
                        if(a[x][y]!=' ' && x<8 && x>=0 && y<8 && y>=0) 
                                if(a[x][y]=='s'||a[x][y]=='e' || a[x][y]=='c' || a[x][y]=='h' || a[x][y]=='k' || a[x][y]=='q')
                                    cout << "You can kill " << a[x][y] << "(" << x << "," << y << ")" << endl;
                        x=tempx;
                        y=tempy;
                        x--;
                        y--;
                        while(a[x][y]==' ')
                        {
                            a[x][y]='*';
                            x--;
                            y--;
                        }
                        if(a[x][y]!=' ' && x<8 && x>=0 && y<8 && y>=0) 
                                if(a[x][y]=='s'||a[x][y]=='e' || a[x][y]=='c' || a[x][y]=='h' || a[x][y]=='k' || a[x][y]=='q')
                                    cout << "You can kill " << a[x][y] << "(" << x << "," << y << ")" << endl;
                        x=tempx;
                        y=tempy;
                        x--;
                        y++;
                        while(a[x][y]==' ')
                        {
                            a[x][y]='*';
                            x--;
                            y++;
                        }
                        if(a[x][y]!=' ' && x<8 && x>=0 && y<8 && y>=0) 
                                if(a[x][y]=='s'||a[x][y]=='e' || a[x][y]=='c' || a[x][y]=='h' || a[x][y]=='k' || a[x][y]=='q')
                                    cout << "You can kill " << a[x][y] << "(" << x << "," << y << ")" << endl;
                        x=tempx;
                        y=tempy;
                        x++;
                        y--;
                        while(a[x][y]==' ')
                        {
                            a[x][y]='*';
                            x++;
                            y--;
                        }
                        if(a[x][y]!=' ' && x<8 && x>=0 && y<8 && y>=0) 
                                if(a[x][y]=='s'||a[x][y]=='e' || a[x][y]=='c' || a[x][y]=='h' || a[x][y]=='k' || a[x][y]=='q')
                                    cout << "You can kill " << a[x][y] << "(" << x << "," << y << ")" << endl;
                        x=tempx;
                        y=tempy;
                        show();
                        cout << "If can kill some-one it will show above\n" ;
                        int xs,ys;
                        char temp;
                        cout << "Enter the location you want to go to : ";
                        cin >> xs >> ys;
                        if(a[xs][ys]=='*')
                        {
                            temp=a[xs][ys];
                            a[xs][ys]=a[x][y];
                            a[x][y]=temp;
                        }
                        else
                        {
                            if(a[x][y]=='C')
                            {
                                if(a[xs][ys]=='S')
                                {
                                    a[xs][ys]='C';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='e')
                                {
                                    a[xs][ys]='C';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='c')
                                {
                                    a[xs][ys]='C';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='h')
                                {
                                    a[xs][ys]='C';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='k')
                                {
                                    a[xs][ys]='C';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='q')
                                {
                                    a[xs][ys]='C';
                                    a[x][y]=' ';
                                }
                                else
                                {
                                    cout << "Invelid input!";
                                    if (player==1)
                                        player=1;
                                    else
                                        player=2;  
                                    check=1;                          
                                }
                            }                    
                        }
                        
                        for(int i=0;i<8;i++)
                        {
                            for(int j=0;j<8;j++)
                            {
                                if(a[i][j]=='*')
                                    a[i][j]=' ';
                            }
                        }
                        show();
                        if(check!=1)
                        {
                            if(player==1)
                                player=2;
                            else
                                player=1;
                        }           
                    }
                    else if(a[x][y]=='H')
                    {
                        int tempx=x,tempy=y;
                        if(a[x+1][y+2]==' ')
                            a[x+1][y+2]='*';
                        if(a[x+2][y+1]==' ')
                            a[x+2][y+1]='*';
                        if(a[x-1][y-2]==' ')
                            a[x-1][y-2]='*';
                        if(a[x-2][y-1]==' ')
                            a[x-2][y-1]='*';
                        if(a[x+1][y-2]==' ')
                            a[x+1][y-2]='*';
                        if(a[x+2][y-1]==' ')
                            a[x+2][y-1]='*';
                        if(a[x-1][y+2]==' ')
                            a[x-1][y+2]='*';
                        if(a[x-2][y+1]==' ')
                            a[x-2][y+1]='*';
                        show();
                        char ar[6] = {'s','e','h','c','k','q'};
                        if(a[x][y]=='H')
                        {
                            for(int i=0;i<6;i++)
                            {
                                if(a[x+1][y+2]==ar[i])
                                    cout << "You can kill " << a[x+1][y+2] << "(" << x+1 << "," << y+2 << ")" << endl;
                                if(a[x+2][y+1]==ar[i])
                                    cout << "You can kill " << a[x+2][y+1]<< "(" << x+2 << "," << y+1 << ")" << endl;
                                if(a[x-1][y-2]==ar[i])
                                    cout << "You can kill " << a[x-1][y-2]<< "(" << x-1 << "," << y-2 << ")" << endl;
                                if(a[x-2][y-1]==ar[i])
                                    cout << "You can kill " << a[x-2][y-1]<< "(" << x-2 << "," << y-1 << ")" << endl;
                                if(a[x+1][y-2]==ar[i])
                                    cout << "You can kill " << a[x+1][y-2]<< "(" << x+1 << "," << y-2 << ")" << endl;
                                if(a[x+2][y-1]==ar[i])
                                    cout << "You can kill " << a[x+2][y-1]<< "(" << x+2 << "," << y-1 << ")" << endl;
                                if(a[x-1][y+2]==ar[i])
                                    cout << "You can kill " << a[x-1][y+2]<< "(" << x-1 << "," << y+2 << ")" << endl;
                                if(a[x-2][y+1]==ar[i])
                                    cout << "You can kill " << a[x-2][y+1]<< "(" << x-2 << "," << y+1 << ")" << endl;
                            }
                        } 
                        int xs,ys;
                        char temp;
                        cout << "Enter the location you want to go to : ";
                        cin >> xs >> ys;
                        if(a[xs][ys]=='*')
                        {
                            temp=a[xs][ys];
                            a[xs][ys]=a[x][y];
                            a[x][y]=temp;
                        }
                        else
                        {
                            if(a[x][y]=='H')
                            {
                                if(a[xs][ys]=='s')
                                {
                                    a[xs][ys]='H';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='e')
                                {
                                    a[xs][ys]='H';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='c')
                                {
                                    a[xs][ys]='H';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='h')
                                {
                                    a[xs][ys]='H';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='k')
                                {
                                    a[xs][ys]='H';
                                    a[x][y]=' ';
                                }
                                else if(a[xs][ys]=='q')
                                {
                                    a[xs][ys]='H';
                                    a[x][y]=' ';
                                }
                                else
                                {
                                    cout << "Invelid input!";
                                    if (player==1)
                                        player=1;
                                    else
                                        player=2;                            
                                }
                            }
                        }
                        for(int i=0;i<8;i++)
                        {
                            for(int j=0;j<8;j++)
                            {
                                if(a[i][j]=='*')
                                    a[i][j]=' ';
                            }
                        }
                        show();  
                        if(check!=1)
                        {
                            if(player==1)
                                player=2;
                            else
                                player=1;
                        }     
                    }
                    else
                    {
                        cout << "There is nothing to move!!\n";
                    }
                    
                }
            }
            else
            {
                cout << "There is no location like this!!\n\n";
            }
            
        }
        bool finish()
        { 
            int c=0;
            for(int i=0;i<8;i++)
            {
                for(int j=0;j<8;j++)
                {
                    if(a[i][j]=='k' || a[i][j]=='K')
                        c++;
                }
            }
            if(c==2)
                return true;
            else
                return false;
        }

        
};


int main()
{
    chess c;
    c.show();
    while(c.finish())
    {
        //cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        system("cls");
        c.check=0;
        c.show();
        cout << "It's player " << c.player << "'s turn.\n";
        
        c.move();
        cout<< "press any key to continue!!";
        getch();
       // cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    }
    if(c.player==2)
        cout << "Player " << c.player << " wins.";
    else
        cout << "Player " << c.player << " wins.";
    getch();
    return 0;
}