#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cstdlib>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;
#define height 25
#define width 50

int Life =5;
char ch = ' ';
vector<int> k;
char guess[10] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
char choice[10] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};

void gameLogic(string mini, char choice)
{
    int flag =0;
        for(int i=0; i<5;i++)
        {
            if(mini[i]==choice)
            {
                flag =1;
                //k.push_back(i);
                guess[i*2] = choice;
            }
        }
        if(flag ==0)
            Life --;
}
void gamewindow(string mini)
{
    system("CLS");
    int pos;
    for(int i=0; i<height;i++)
    {
        for(int j=0; j<width; j++)
            {
                if(i==0 || i==height-1 || j==0 || j==width-1)
                    cout<<"*";

                else if(i==1 && j==3)
                {
                    cout<<"GUESS THE WORD!!";
                    j = 18;
                }

                else if(i==2 && j>2 && j<19)
                {
                    cout<<"-";
                }

                else if(i==1 && (j==width-10))
                {
                    cout<<"LIFE = "<<Life;
                    cout<<" *";
                    break;
                }

                else if(i==9 && j>18 && j<29)
                {
                	for(int k=0; k<10;k++)
                	{
                		cout<<guess[k];
                		j++;
					}
					cout<<"  ";
				}

                else if(i==10 && j>18 && j<29)
                {
                    cout<<"-";
                    if(j!=28)
                    {
                        cout<<" ";
                        j++;
                    }
                }
                
                else if(i==13 && j==2)
                {
                    cout<<"Enter a character and guess the word!";
                    j = 38;
                }
                else if(Life<=5 && j==2 && (i>=14 && i<=23))
                {
                    cout<<choice[i-14];	
                }
                else
                cout<<" ";
            }
            cout<<endl;
    }
}
int main()
{
    srand(time(NULL));
    ifstream file("dict.txt");
    vector<string> word;
    string k;
    int flag =0;
   while(file >> k)
    {
        word.push_back(k);
    }
    int random = rand()%500+1;
    string mini;
    mini = word[random];
    int random_val= rand()%5;
    //cout<<"random_val = "<<random_val;
    //cout<<"random_val*2 = "<<random_val*2;
    guess[random_val*2] = mini[random_val];
    char temp = guess[random_val*2];
    for(int i=0; i<10;i++)
    {
    	if(mini[i]==temp)
    		guess[i*2] = mini[i];
	}
    int i=0;
    while(Life>0 && flag==0)
    {
    	gamewindow(mini);
    	cin>>choice[i];
    	gameLogic(mini,choice[i]);
    	i++;
    	int count =0;
    	for(int p=0; p<10;p++)
    	{
    		if(guess[p]==' ')
    			count++;
    	}
		if(count==4)
			flag =1;
	}
	gamewindow(mini);
	if(flag==0)
	{
		cout<<"\n\n**********You lost all chances!!**********";
		cout<<"\n\n**********Better Luck Next Time!**********";
		cout<<"\n\n----------The word was: "<<mini<<" ----------";
		cout<<"\n\nPress any key to exit\n";
		getch();		
	}
	else if(flag==1)
	{
		cout<<"\n\n**********Congratulations YOU WON!!**********";
		cout<<"\n\n----------The word is: "<<mini<<" ----------------";
		cout<<"\n\nPress any key to exit\n";
		getch();		
	}
return 0;
}
