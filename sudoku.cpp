#include <iostream>
using namespace std;
int sudoku[10][10];
bool checkPos(int x, int y, int num){
  for(int i = 0; i < 9; i++){
    if(sudoku[i][y] == num || sudoku[x][i] == num){
      return false;
    }
  }
  int stx = (x / 3) * 3;
  int sty = (y / 3) * 3;
  for(int i = 0; i <= 2; i++){
    for(int j = 0; j <= 2; j++){
      if(sudoku[stx+i][sty+j] == num){
        return false;
      }
    }
  }
  return true;
}
void solve(){
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      if(sudoku[i][j] == 0){
        for(int n = 1; n <= 9; n++){
          if(checkPos(i, j, n)){
            sudoku[i][j] = n;
            solve();
            sudoku[i][j] = 0;
          }
        }
        return;
      }
    }
  }
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      cout << sudoku[i][j] << " ";
    }
    cout << '\n';
  }
}
int main(){
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      cin >> sudoku[i][j];
    }
  }
  cout << '\n';
  solve();
}
