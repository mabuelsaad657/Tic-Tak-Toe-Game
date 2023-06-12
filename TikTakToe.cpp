#include <iostream>
#include<iomanip>
#include<string>
#include <cstdlib>
using namespace std;
void askQuestion();
void printBoard(int,int,char[][5]);
bool playGame(char[][5], char, char, int);
bool checkWinner(char[][5],char, bool);

int main() {
  srand(time(0));
//Variables
char board[5][5] = {{'.','|','.','|','.'},
                    {'-','+','-','+','-'},
                    {'.','|','.','|','.'},
                    {'-','+','-','+','-'},
                    {'.','|','.','|','.'}};
  string anwser = "";
  char Player1 = 'X';
    char Player2 = 'O';
  char slot;
  int a = 5;
  int b = 5;
  int count = 0;
  bool won = false;
  int random;
  bool holder;
  bool an = false;

  //Function calls
  askQuestion();
  cin >> anwser;   
  printBoard(a,b,board);

  //Start here
    do{
       cout << "From 1-9 which slot does Player 1 want to pick " << endl;
      cin >> slot;
      
    an = playGame(board,Player1,slot,count);
      
      while(an == false){
        cout << "Please make sure the number you enter is           between 1-9" << endl;
        cout << "From 1-9 which slot does Player 2 want to           pick " << endl;
      cin >> slot;
        an = playGame(board,Player1,slot,count);
      }
      
    holder = checkWinner(board,Player1,won);
    if(holder == true){
      cout << "Congrats Player1 has won the game" << endl;
    }
      
   count++;
    printBoard(a,b,board);
    cout << "=== " << count << " ====" << endl;
    if(count<9 && holder == false){
      cout << "From 1-9 which slot does Player 2 want to pick " << endl;
      cin >> slot;
      an = playGame(board,Player2,slot,count);
      
      while(an == false){
        cout << "Please make sure the number you enter is between 1-9" << endl;
        cout << "From 1-9 which slot does Player 2 want to pick " << endl;
      cin >> slot;
        an = playGame(board,Player1,slot,count);
      }
      holder = checkWinner(board,Player2,won);
      if(holder == true){
        cout << "Player 2 has won the game" << endl;
      }
    count++;
    printBoard(a,b,board);
    cout << "=== " << count << " ====" << endl;
    }
      
    }while(count<9 && holder == false); 
  //End here
    
}

  
  
void askQuestion(){
    cout<<"Press any key to play" << endl;
  }

void printBoard(int d, int e, char f[][5]){
  for(int i = 0; i<d;i++){
    for(int j = 0; j<e; j++){
      cout << f[i][j];
      if(j==4){
        cout << endl;
      }
    }
    
  }
}
bool playGame(char f[][5], char q, char inp, int co){
   if(inp == '1'){
    f[0][0] = q; 
     return true;
  }
     
  else if(inp == '2'){
    f[0][2] = q;
    return true;
  }
    
  else if(inp == '3'){
    f[0][4] = q;
    return true;
  }
    
  else if(inp == '4'){
    f[2][0] = q;
    return true;
  }
  else if(inp == '5'){
    f[2][2] = q;
    return true;
  }
  else if(inp == '6'){
    f[2][4] = q;
    return true;
  }
  else if(inp == '7'){
    f[4][0] = q;
    return true;
  }
  else if(inp == '8'){
    f[4][2] = q;
    return true;
  }
  else if(inp == '9'){
    f[4][4] = q;
    return true;
  }
  else{
    cout << "Please make sure the number is between 1-9" << endl;
  return false;
  }
  

} 
bool checkWinner(char a[][5], char n, bool c){
  if(a[0][0] == n && a[0][2] == n && a[0][4] == n){
   return true;
  }
  else if(a[2][0] == n && a[2][2] == n && a[2][4] == n){
   return true;
  }
  else if(a[4][0] == n && a[4][2] == n && a[4][4] == n){
    return true;
  }
  else if(a[0][0] == n && a[2][0] == n && a[4][0] == n){
   return true;
  }
  else if(a[2][0] == n && a[2][2] == n && a[2][4] == n){
    return true;
  }
  else if(a[4][0] == n && a[4][2] == n && a[4][4] == n){
    return true;
  }
  else if(a[0][0] == n && a[2][2] == n && a[4][4] == n){
   return true;
  }
  else if(a[0][4] == n && a[2][2] == n && a[4][0] == n){
    return true;
  }
  else{
    return false;
  }
  
}
// wory about how to -- if user enters number outside of 0, ai section, no repeats make sure computer can't take friends number, if user enters nither computer or friend


//If we make it into a bolean function and return false if user enters wrong boundries and then do a while loop to check that the code will keep running if its false