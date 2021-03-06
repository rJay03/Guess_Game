#include<iostream>
#include<string>                                                               // Needed to use strings
#include<cstdlib>                                                              // Needed to use random numbers
#include<ctime>
using namespace std;
class GuessGame{
                private:
                        string PlayerName;
                        int Balance;                                            // stores player's balance
                        int BettingAmount;
                        int Guess;
                        int Dice;                                               // stores the random number
                        char Choice;
                public:
                        void StartGame();
                        void GameRules();
                        void GamePlay();
};

void GuessGame :: StartGame()
{
    cout << "\n\t\t=x=x=x= ONE2FIVE WORLD =x=x=x=\n\n";
    cout << "\n\n What's your Name : ";
    getline(cin, PlayerName);
    cout << "\n\nEnter the starting balance to play game : ₹";
    cin >> Balance;
}

void GuessGame :: GameRules()
{
    cout << "\n\n\t=x=x=x= ONE2FIVE GAME RULES! =x=x=x=\n\n";
    cout << "\t1. Choose a number between 1 to 5\n";
    cout << "\t2. Winner gets 10 times of the money bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";
}

void GuessGame :: GamePlay()
{
        srand(time(0));                                                         // used to "Seed" the random generator
    do
    {  
        cout<<"\n\nYour current Balance is ₹"<<Balance<<"\n";
               
        do
        {
            cout<<"Hey there "<<PlayerName<<", Enter the amount to bet :₹";     // Get player's betting balance
            cin>>BettingAmount;
           
            if(BettingAmount>Balance)
           
            cout<<"Betting Amount can't be more than current Balance!\n"
            <<"\nRe-enter Betting amount\n";
        }while(BettingAmount > Balance);                                        // Get player's numbers
               
        do
        {
            cout<<"\nEnter any Number between 1 & 5 to Bet on!\n";
            cin>>Guess;
           
            if(Guess <= 0 || Guess > 5)
            {
                cout<<"The number should be between 1 & 5!"
                <<"\nRe-enter a Valid Number\n";
            }
        }while(Guess <= 0 || Guess >5);
               
                Dice = rand()%5 + 1;
               
        if(Dice == Guess)
        {
            cout<<"\n\nYou're In Luck!!! You have WON ₹"<< BettingAmount * 10;
            Balance = Balance + BettingAmount * 10;
        }
        else
        {
            cout<<"Oops, better Luck next time :) || You Lost ₹"<<BettingAmount;
            Balance = Balance - BettingAmount;
        }
            cout<<"\nThe Winning Number was : "<<Dice<<"\n";
            cout<<"\n"<<PlayerName<<" ,You have a Balance of ₹"<<Balance<<"\n";
           
        if(Balance == 0)
        {
            cout<<"You have insufficient Balance to play";
            break;
        }
       
            cout<<"\n\n-> Do you want to Play again (Y/N)?";
            cin >> Choice;
       
    }while(Choice == 'Y' || Choice == 'y');
       
            cout<<"\n\n\n";
            cout<<"\nThanks for Playing the game, Your Balance is ₹"<<Balance<<"\n\n";
}

int main()
{
    GuessGame g;
   
    g.StartGame();
    g.GameRules();
    g.GamePlay();
   
    return 0;
}