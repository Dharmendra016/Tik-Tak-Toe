#include<iostream> 
#include<string>
#include<vector>
#include<cstdlib> 
#include<time.h>
#include<Windows.h>
#include <unistd.h>

using namespace std; 


//Board for display
void display(vector<string>& board){

    for(int i= 0; i<board.size() ; i++){
        for(int j = 0 ; j<board.size() ; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

}
//checking both diagonal for X
bool diacheckX(vector<string>& board){
    int count = 0;
    for(int i = 0; i<9 ; i++){
        int s = i/3 ;
        int e = i%3 ;
        if( s == e ){
            if( board[s][e] == 'X'){
                count++;
            }
        }
    }
    
    int cnt = 0;
    int p = 0 ; 
    int q = 2;
    for(int i = 0; i<9 ; i++){
        int s = i/3 ;
        int e = i%3 ;

        if( s == p && e == q){
            if(board[s][e] == 'X'){
                cnt++;
            }
            p++;
            q--;
        }
    }

    if( count == 3 || (cnt == 3)){
        return true;
    }else{
        return false;
    }

}

//checking Diagonals for O 
bool diacheckO(vector<string>& board){
    int count = 0;
    for(int i = 0; i<9 ; i++){
        int s = i/3 ;
        int e = i%3 ;
        if( s == e ){
            if( board[s][e] == 'O'){
                count++;
            }
        }
    }
    
    int cnt = 0;
    int p = 0 ; 
    int q = 2;
    for(int i = 0; i<9 ; i++){
        int s = i/3 ;
        int e = i%3 ;

        if( s == p && e == q){
            if(board[s][e] == 'O'){
                cnt++;
            }
            p++;
            q--;
        }
    }

    if( count == 3 || (cnt == 3)){
        return true;
    }else{
        return false;
    }

}

//checking horizontal for x
bool horicheckX(vector<string>& board){
    int cnt = 0 ; 
    for(int i= 0; i<3 ; i++){
        for(int j= 0 ; j<3 ; j++){
            if(board[i][j] == 'X'){
                cnt++;
            }
        }
        if( cnt == 3){
            return true;
        }
        cnt = 0;
    }
    return false;
}
//checking horizontal for O
bool horicheckO(vector<string>& board){
    int cnt = 0 ; 
    for(int i= 0; i<3 ; i++){
        for(int j= 0 ; j<3 ; j++){
            if(board[i][j] == 'O'){
                cnt++;
            }
        }
        if( cnt == 3){
            return true;
        }
        cnt = 0;
    }
    return false;
}
//vertical col check  forx
bool colcheckX(vector<string>& board){
    int cnt = 0 ; 
    for(int i= 0; i<3 ; i++){
        for(int j= 0 ; j<3 ; j++){
            if(board[j][i] == 'X'){
                cnt++;
            }
        }
        if( cnt == 3){
            return true;
        }
        cnt = 0;
    }
    return false;
}
//checking coloum for o
bool colcheckO(vector<string>& board){
    int cnt = 0 ; 
    for(int i= 0; i<3 ; i++){
        for(int j= 0 ; j<3 ; j++){
            if(board[j][i] == 'O'){
                cnt++;
            }
        }
        if( cnt == 3){
            return true;
        }
        cnt = 0;
    }
    return false;
}

//for single player 
void randMove(vector<string>& board){
    sleep(0.5);
    srand(time(0));

    for(int i = 0 ; i<9 ;i++){
        int randNum = rand() % 9;

        if( board[randNum/3][randNum%3] != 'X' && board[randNum/3][randNum%3] != 'O'){
             board[randNum/3][randNum%3] = 'O';
             break;
        }

    }

}

void twoPlayer(int player_1 , int player_2 , vector<string> &board){

     int c = 0;

    // game logics 
    for(int i = 0 ; i<12 ; i++){
        cout<<"Player's 1 turn(x): ";
        cin>>player_1;

        //if  player-1 has select the same place as palyer-2 
        while( board[(player_1-1)/3][(player_1-1)%3] == 'X' || board[(player_1-1)/3][(player_1-1)%3] == 'O'){
            cout<<"Already filled . Please again choose another place:";
            cin>>player_1;
        }

        board[(player_1-1)/3][(player_1-1)%3] = 'X';
        c++;
        display(board);
        if( diacheckX(board) || horicheckX(board) || colcheckX(board)){
            cout<<endl;
            cout<<"player-1 wins "<<endl;
            break;
        }
        if( c == 9 ){
            cout<<"Draw !!";
            break;
        }
        cout<<endl;
        cout<<"Player's 2 turn(o): ";
        cin>>player_2;

        //if  player-2 has select the same place as palyer-1 
        while( board[(player_2-1)/3][(player_2-1)%3] == 'X' || board[(player_2-1)/3][(player_2-1)%3] == 'O'){
            cout<<"Already filled . Please again choose another place:";
            cin>>player_2;
        }


        board[(player_2-1)/3][(player_2-1)%3] = 'O';
        c++;
        display(board);
         if( diacheckO(board) || horicheckO(board) || colcheckO(board)){
            cout<<endl;
            cout<<"player-2 wins :"<<endl;
            break;
        }
        if( c == 9 ){
            cout<<"Draw !!";
            break;
        }
    }

}

void singlePlayer(int player_1 , int player_2 , vector<string>&board){
      int c = 0 ; 
    //single player mode --> inplement is on 
    for(int i = 0 ; i<9 ; i++){

        cout<<"Player's 1 turn(x): ";
        cin>>player_1;

        //if  player-1 has select the same place as palyer-2 
        while( board[(player_1-1)/3][(player_1-1)%3] == 'X' || board[(player_1-1)/3][(player_1-1)%3] == 'O'){
            cout<<"Already filled . Please again choose another place:";
            cin>>player_1;
        }

        board[(player_1-1)/3][(player_1-1)%3] = 'X';
        c++;
        display(board);
        if( diacheckX(board) || horicheckX(board) || colcheckX(board)){
            cout<<endl;
            cout<<"player-1 wins "<<endl;
            break;
        }
        if( c == 9 ){
            cout<<"Draw !!";
            break;
        }
        cout<<endl;

        //computer's turn  
        cout<<"Computer's Turn:"<<endl;;
        randMove(board);

        // while( board[(player_2-1)/3][(player_2-1)%3] == 'X' || board[(player_2-1)/3][(player_2-1)%3] == 'O'){
        //     cout<<"Already filled . Please again choose another place:";
        //     cin>>player_2;
        // }
        c++;
        display(board);
         if( diacheckO(board) || horicheckO(board) || colcheckO(board)){
            cout<<endl;
            cout<<"Computer own the game :"<<endl;
            break;
        }
        if( c == 9 ){
            cout<<"Draw !!";
            break;
        }

    }
}


int main(){
    int n = 3; 
    vector<string> board(n);

    //making board 
    for(int i= 0; i<board.size() ; i++){
        for(int j = 0 ; j<board.size() ; j++){
            board[i][j] = '-';
        }
    }

    //players 
    int player_1 ; 
    int player_2 ;

    
    cout<<"Please which mode your want to play:"<<endl<<"1.single player mode"<<endl<<"2.Two Player mode"<<endl;
    int chooseMode; 
    cin>>chooseMode; 

    display(board);
    cout<<endl;
    if( chooseMode == 1){
        singlePlayer(player_1 , player_2 , board);
    }else if( chooseMode == 2){
        twoPlayer(player_1 , player_2 , board);
    }


    return 0;
}