#include<iostream> 
#include<string>
#include<vector> 
using namespace std; 

void display(vector<string>& board){

    for(int i= 0; i<board.size() ; i++){
        for(int j = 0 ; j<board.size() ; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

}

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
//checking Both Diagonal 
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

//checking horizontal 
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
//vertical col check 
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

    int c = 0;
    for(int i = 0 ; i<9 ; i++){
        cout<<"Player's 1 turn(x): ";
        cin>>player_1;

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


    // display(board);
    return 0;
}