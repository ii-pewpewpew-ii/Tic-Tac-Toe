#include <bits/stdc++.h>
using namespace std;
class gameBoard
{
    char board[3][3];
public:

    gameBoard()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                board[i][j] = '_';
            }
        }
    }
    void clear()
    {
        for(int i=0;i<3;i++)
        {
            for(int j = 0;j<3;j++)
            {
                board[i][j] = '_';
            }
        }
    }
    void boardDisplay()
    {
        for(int i=0;i<3;i++)
            {
                cout<<"\t\t\t\t\t\t\t";
                for(int j =0 ;j<3;j++)
                {
                   cout<<board[i][j]<<"  |  ";
                }
                cout<<endl;
            }
    }

    int gameOver()
    {
        // Checking the board for an X win
        if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
        {
            return 1;
        }
        if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] =='X')
        {
            return 1;
        }
        if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
        {
            return 1;
        }
        if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
        {
            return 1;
        }
        if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
        {
            return 1;
        }
        if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')
        {
            return 1;
        }
        if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
        {
            return 1;
        }
        if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
        {
            return 1;
        }
        // Checking for a O win
        if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
        {
            return -1;
        }
        if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')
        {
            return -1;
        }

        if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
        {
            return -1;
        }
        if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
        {
            return -1;
        }
        if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
        {
            return -1;
        }
        if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')
        {
            return -1;
        }
        if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
        {
            return -1;
        }
        if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
        {
            return -1;
        }
        // Check for a tie (No more moves available)
        for(int i=0;i<3;i++)
        {
            for(int j = 0;j<3;j++)
            {
                if(board[i][j]=='_')
                    return 4;
            }
            

        }
        return 0;
    }
    void fillSpace(int space,char turn)
    {
        switch (space)
        {
        case (1):
            board[0][0] = turn;
            break;
        case (2):
            board[0][1] = turn;
            break;
        case (3):
            board[0][2] = turn;
            break;
        case (4):
            board[1][0] = turn;
            break;
        case (5):
            board[1][1] = turn;
            break;
        case (6):
            board[1][2] = turn;
            break;
        case (7):
            board[2][0] = turn;
            break;
        case (8):
            board[2][1] = turn;
            break;
        case (9):
            board[2][2] = turn;
            break;
        }
    }
    int isEmpty(int space)
    {
        space -=1;
        if(board[space/3][space%3] == '_')
            return 1;
        else 
            return 0;

    }
     
};

gameBoard board;
int minMax(gameBoard board,int maximisersTurn,int depth = 0)
{
    int score;
    score = board.gameOver();
    if(score!=4)
    {
        return score;
    }
    if(maximisersTurn==1)
    {
        int best = -1000;
        int score2;
        char turn = 'X';
        int empty =0;
        for(int i=1;i<10;i++)
        {
            if(board.isEmpty(i) == 1)
            {
                board.fillSpace(i,turn);
                score2 = minMax(board,0,depth+1);
                best = max(score2,best);
                board.fillSpace(i,'_');
            }
        }
        return best;
    }
    else
    {
        int best = 1000;
        int empty = 0;
        int score2;
        char turn = 'O';
        for(int i =1;i<=9;i++)
        {
            if(board.isEmpty(i) == 1)
            {
                board.fillSpace(i,turn);
                score2 = minMax(board,1,depth+1);
                best = min(score2,best);
                board.fillSpace(i,'_');
            }
        }
        return best;
    }   
}
int findOptimalMove(gameBoard board)
{
    int bestValue = -1000;
    int moveValue;
    int place;
    char ai = 'X';
    for(int i=1;i<10;i++)
    {
       if(board.isEmpty(i) == 1)
       {
            board.fillSpace(i,ai);
            moveValue = minMax(board,0,0);
            board.fillSpace(i,'_');
            if(moveValue>bestValue)
            {
                bestValue = moveValue;
                place = i;
            }
       }
    }
    return place;
}
void game(gameBoard &board)
{
    char cont = 'Y';
    while(cont == 'Y' )   
    {
        int userMove;
        int gameStatus = 3;
        char user = 'O',choice;
        cout<<"\t\t\t\t\t\t\tDo you want to go First? : (y/n) ";
        cin>>choice;
        if(choice == 'n')
                while(true)
                    {
                        int x = findOptimalMove(board);
                        cout<<"\n\t\t\t\t\t\t\tAI's move : "<<x<<endl;
                        board.fillSpace(x,'X');
                        if(board.gameOver()==1)
                        {
                            board.boardDisplay();
                            cout<<"\n\t\t\t\t\t\t\tAI has won\n";
                            break;    
                        }     
                        board.boardDisplay(); 
                        cout<<endl; 
                        if(board.gameOver()==0)
                        {
                            cout<<"\n\t\t\t\t\t\t\tGame has ended in a draw"<<endl;
                            break;
                        }
                        wrong :
                        cout<<"\n\t\t\t\t\t\t\tEnter your choice of position : ";
                        cin>>x; 
                        if(board.isEmpty(x)==0)
                        {
                            cout<<"\t\t\t\t\t\t\tInvalid choice\n";
                            goto wrong;
                        }
                        cout<<endl;
                        board.fillSpace(x,user);
                        
                        if(board.gameOver()==-1)
                        {
                            board.boardDisplay();
                            cout<<"\n\t\t\t\t\t\t\tCongratulations you have won\n";
                            break;
                        }
                        board.boardDisplay();
                        cout<<endl;
                        if(board.gameOver()==0)
                        {
                            board.boardDisplay();
                            cout<<"\n\t\t\t\t\t\t\tGame has ended in a draw\n";
                            break;
                        }
                    }
        else
        {
            while(true)
                    {
                        int x;
                        wrong2 :
                        cout<<"\n\t\t\t\t\t\t\tEnter your choice of position : ";
                        cin>>x; 
                        if(board.isEmpty(x)==0)
                        {
                            cout<<"\t\t\t\t\t\t\tInvalid choice\n";
                            goto wrong2;
                        }
                        board.fillSpace(x,user);
                        board.boardDisplay();
                        cout<<endl;
                        x = findOptimalMove(board);
                        cout<<"\n\t\t\t\t\t\t\tAI's move : "<<x<<endl;
                        board.fillSpace(x,'X');
                        if(board.gameOver()==1)
                        {
                            board.boardDisplay();
                            cout<<"\n\t\t\t\t\t\t\tAI has won\n";
                            break;    
                        }     
                        board.boardDisplay(); 
                        cout<<endl; 
                        if(board.gameOver()==0)
                        {
                            cout<<"\n\t\t\t\t\t\t\tGame has ended in a draw"<<endl;
                            break;
                        }
                        if(board.gameOver()==-1)
                        {
                            board.boardDisplay();
                            cout<<"\n\t\t\t\t\t\t\tCongratulations you have won\n";
                            break;
                        }
                        
                        if(board.gameOver()==0)
                        {
                            board.boardDisplay();
                            cout<<"\n\t\t\t\t\t\t\tGame has ended in a draw\n";
                            break;
                        }
                    }
        }
        cout<<"\t\t\t\t\t\t\t---------------------------------------------------------------\n";
        board.clear();
        cout<<"\n\t\t\t\t\t\t\tDo you want to play another Round?(Y/N)";
        cin>>cont;
    }
}



int main()
{ 
    game(board);
    return 0;
}