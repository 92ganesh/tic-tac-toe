#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include "resource.h"
#include <conio.h>
void display(int choice_int);
void win_check();
void announce_winner();
void reset_all();
using namespace std;
class choice
{  public:
     int choice_int;

}c;
class players
{   public:
    string name;
    bool win_status;
    int moves_count;
}p1,p2;


char opt[10];
int winning_line[10];
int main()        // --------------------------------------------------------------main()
{   reset_all();
    int player=1,menu; // setting player 1 as first player
    system("color 60");
    
 //welcome
 cout<<"\t\t\t\t*****************\t\t\n";
 
    cout<<"\t\t\t\t*\t\t*\t\t\n";
 cout<<"\t\t\t\t*   WELCOME !!  *\t\t\n";
 
    cout<<"\t\t\t\t*\t\t*\t\t\n";
 cout<<"\t\t\t\t*****************\t\t\n";
    cout<<"\n\n\t\t\t\t   TIC-TAC-TOE\n\t\t";

    cout<<"\n\n\t\t\t Press any key to start the game\n\t\t";

    getch ();
    system("cls");
   
 // getting info of players
    cout<<"\n\n\n\tEnter the name of the players \n";
    cout<<"\n\tplayer1 whose symbol will be 'X': ";
    getline(cin,p1.name);
    cout<<"\tplayer2 whose symbol will be 'O': ";
    getline(cin,p2.name);
    system("cls");
    system("color 1E");
    while(1)
    {
        display(c.choice_int);
        if(player==1)
         {  while(1)
            { cout<<p1.name<<" enter your choice: ";
              cin.clear();
              fflush(stdin);
              cin>>c.choice_int;
              p1.moves_count++;
              if(c.choice_int>=1&&c.choice_int<=9&&(opt[c.choice_int]!='X'&&opt[c.choice_int]!='O'))
               { opt[c.choice_int]='X';
                 break;
               }
              else
               { cout<<"\t\tINVALID  CHOICE"<<endl;
                 p1.moves_count--;
               }
            }
            system("cls");
            player=2;
         }
        else if(player==2)
        {   while(1)
            { cout<<p2.name<<" enter your choice: ";
              cin.clear();
              fflush(stdin);
              cin>>c.choice_int;  p2.moves_count++;
              if(c.choice_int>=1&&c.choice_int<=9&&(opt[c.choice_int]!='X'&&opt[c.choice_int]!='O'))
               { opt[c.choice_int]='O';
                 break;
               }
              else
                { cout<<"\t\tINVALID  CHOICE"<<endl;
                  p2.moves_count--;
                }
            }
            system("cls");
            player=1;
        }
        win_check();
        if(p1.win_status==true||p2.win_status==true||p1.moves_count+p2.moves_count==9)
        { cout<<"press 1:Restart Game"<<endl;
          cout<<"      2:Quit Game"<<endl;
          while(1)
          {cin.clear();
           fflush(stdin);
           cin>>menu;
           if(menu==1)
           {  reset_all();
              break;
           }else if(menu==2)
               exit(0);
            else
               cout<<"\t\tINVALID CHOICE\n\tPlease enter again"<<endl;
          }
        }
   }
        return 0;
}

//----------------------------------------------------------------------  To display whole block
void display(int choice_int)
{   if(p1.win_status==false&&p2.win_status==false&&p1.moves_count+p2.moves_count!=9)
    { cout<<"Player1 is "<<p1.name<<"(X)"<<endl;
      cout<<"Player2 is "<<p2.name<<"(O)"<<endl;
    }
    cout<<"\n"<<endl;
    int j=1;
    for(int i=1;i<=3;i++)
    {  cout<<"\t\t\t"<<"\t|"<<"\t"<<"\t|"<<"\t"<<endl;  //for upper spacing
       cout<<"\t\t";
       for(int k=1;k<=3;k++)
       {   if(j==choice_int||winning_line[j])  // To indicate last move and winner line
              cout<<"     ->"<<opt[j]<<"<-\t";
           else
              cout<<"\t"<<opt[j]<<"\t";
           j++;
           if(k!=3)
             cout<<"|";
           else
             cout<<endl;
       }
       cout<<"\t\t\t"<<"\t|"<<"\t"<<"\t|"<<"\t"<<endl;   //for lower spacing
       if(i!=3)
          cout<<"\t\t-------------------------------------------------"<<endl;
       else
          cout<<"\n";
    }
}

void win_check() //--------------------------------------------------------- win_check()
{  int win=0;
    // DRAW check
    if(p1.moves_count+p2.moves_count==9)
        announce_winner();
    // vertical check
    for(int i=1;i<=3;i++)
    {  if(opt[i]==opt[i+3]&&opt[i]==opt[i+6])
        {   if(opt[i]=='X')
            {   p1.win_status=true;
            }else if(opt[i]=='O')
            {    p2.win_status=true;
            }
            win = 1;
            winning_line[i]=1;
            winning_line[i+3]=1;
            winning_line[i+6]=1;
        }
    }

    // Horizontal check
    if(win==0)
    { for(int i=1;i<=7;i=i+3)
        { if(opt[i]==opt[i+1]&&opt[i]==opt[i+2])
          {   if(opt[i]=='X')
            {  p1.win_status=true;
            }else if(opt[i]=='O')
            {  p2.win_status=true;
            }
            win = 1;
            winning_line[i]=1;
            winning_line[i+3]=1;
            winning_line[i+6]=1;
          }

        }
    }

    // Digonal check
    if(win==0)
    { if(opt[1]==opt[5]&&opt[5]==opt[9])  // for '/'
          {   if(opt[5]=='X')
            {   p1.win_status=true;
            }else if(opt[5]=='O')
            {   p2.win_status=true;
            }
            win = 1;
            winning_line[1]=1;
            winning_line[5]=1;
            winning_line[9]=1;
          }
    }
    if(win==0)
     { if(opt[3]==opt[5]&&opt[5]==opt[7])  // for '\'
          {   if(opt[5]=='X')
            {   p1.win_status=true;
            }else if(opt[5]=='O')
            {   p2.win_status=true;
            }
            winning_line[3]=1;
            winning_line[5]=1;
            winning_line[7]=1;
          }
    }

   // announcing winners
   if(p1.win_status==true||p2.win_status==true)
        announce_winner();

}


void announce_winner() //------------------------------------------------  announce_winner()
{   system("color F2");
    string winner;
    if(p1.win_status==true)
        winner=p1.name;
    else
        winner=p2.name;
    cout<<"\n\n\n"<<endl;
    cout<<"\t\t   ------------- GAME  OVER -------------"<<endl;
    if(p1.win_status==true||p2.win_status==true)
        cout<<"\n\t\t\t  The winner is "<<winner<<"\n"<<endl;
    else
      { cout<<"\n\t\t\t         -> DRAW <-"<<"\n"<<endl;
        cout<<"\t    Both of the players are too smart or else can read mind"<<"\n"<<endl;
      }
    display(0);  // displaying block without indication of last move
}

void reset_all()
{   p1.win_status=false;
    p1.moves_count=0;
    p2.win_status=false;
    p2.moves_count=0;
    c.choice_int=0;
    int i=1;
    for(char c='1';c<='9';c++)
      { opt[i]=c;
        i++;
      }
    for(i=1;i<=9;i++)
    {   winning_line[i]=0;
    }
    system("cls");
}









