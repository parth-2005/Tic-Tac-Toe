#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
using namespace std;

class Game{
    private:
    /*
    {0 1 2}
    {3 4 5}
    {6 7 8}
    */
    int winning_pos[8][3]={{0,4,8},{2,4,6},{0,3,6},{1,4,7},{2,5,8},{0,1,2},{3,4,5},{6,7,8}};
    public:
    char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};

    bool validMove(int usrinp, char *board){
        if (board[usrinp-1]=='x' || board[usrinp-1]=='o')
        {
            return 0;
        }
        return 1;
        
    }

char winning(char *board){
    for(int i=0; i<8; i++){
        if(board[winning_pos[i][0]]==board[winning_pos[i][1]] && board[winning_pos[i][1]]==board[winning_pos[i][2]]){
            return board[winning_pos[i][0]];
        }
    }
    return 'D';
}

void boardUpdate(int usrinp, char *board, char TOKEN){
    if(usrinp>0 && usrinp<10 && board[usrinp-1]!='x' && board[usrinp-1]!='o'){
        board[usrinp-1]=TOKEN;
    }
    else{
        cout<<"Enter valid integer!"<<endl;
    }
}
};

int main(){
    // bool condn=1;
    int usrinp;
    char TOKEN_0 = 'o', TOKEN_X='x', TOKEN;
    Game game;
    int counter=0;
    while (counter<9){
        
        if(counter%2==0){
            cout<<"X's turn"<<endl<<endl;
            TOKEN=TOKEN_X;
        }
        else{
            cout<<"O's turn"<<endl<<endl;
            TOKEN=TOKEN_0;
        }
        cout<<"     |     |     "<<endl;
        cout<<"  "<<game.board[0][0]<<"  |  "<<game.board[0][1]<<"  |  "<<game.board[0][2]<<"  "<<endl;
        cout<<"     |     |     "<<endl;
        cout<<"-----------------"<<endl;
        cout<<"     |     |     "<<endl;
        cout<<"  "<<game.board[1][0]<<"  |  "<<game.board[1][1]<<"  |  "<<game.board[1][2]<<"  "<<endl;
        cout<<"     |     |     "<<endl;
        cout<<"-----------------"<<endl;
        cout<<"     |     |     "<<endl;
        cout<<"  "<<game.board[2][0]<<"  |  "<<game.board[2][1]<<"  |  "<<game.board[2][2]<<"  "<<endl;
        cout<<"     |     |     "<<endl<<endl;
        cout<<"Enter grid number:"<<endl;
        cin>>usrinp;
        if (game.validMove(usrinp, *game.board))
        {
        game.boardUpdate(usrinp, *game.board, TOKEN);
        counter++;
        }
        system("clear");
        if(game.winning(*game.board)!='D'){
            cout<<endl<<endl<<game.winning(*game.board)<<" WINS!!"<<endl<<endl;
            break;
        }
    }
    return 0;
}