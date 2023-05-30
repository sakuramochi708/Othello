#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Display_board
void display(int board[][8]){
  int z, y;
  printf("   0 1 2 3 4 5 6 7 \n");
  for(z = 0; z < 8; z++){
    printf("%d[", z);
    for(y = 0; y < 8; y++){
      printf(" %d", board[z][y]);
    }
    printf(" ]\n");
  }
}

// execute_othello
void move_othello(int board[][8]){
  int di[8] = {-1, -1,  0, +1, +1 ,+1,  0, -1};
  int dj[8] = { 0, -1, -1, -1,  0, +1, +1, +1};
  int z, t, s, i, j, p;
  bool anyflip;
  int count = 1;
  int giveup_cnt = 0;
//round
  for(count = 1; count <= 64; count++){
    TURN_BEGIN:
    if(giveup_cnt == 2){ break; }
    display(board);
//select_player
    if(count % 2 == 1){
      printf("player 1? > "); scanf("%d %d", &i, &j); p = 1;
    }else{
      printf("player 2? > "); scanf("%d %d", &i, &j); p = 2;
    }
//cannot_play
    if(i == -1 && j == -1){
      giveup_cnt = giveup_cnt + 1;
      continue;
    }
//reverse_number
    if(board[i][j] != 1 && board[i][j] != 2){
      anyflip = false;
      for(z = 0; z < 8; z++){
        if     (i + di[z] == -1 || i + di[z] == 8){ continue; }
        else if(j + dj[z] == -1 || j + dj[z] == 8){ continue; }
        else if(board[i + di[z]][j + dj[z]] == 0 ||
              board[i + di[z]][j + dj[z]] == p){ continue; }
        else{
          for(t = 1;; t++){
            if     (i + t*di[z] == -1 || i + t*di[z] == 8)
              { goto NEXT_DIRECTION; }
            else if(j + t*dj[z] == -1 || j + t*dj[z] == 8)
              { goto NEXT_DIRECTION; }
            else if(board[i + t*di[z]][j + t*dj[z]] == 0) 
              { goto NEXT_DIRECTION; }
            else if(board[i + t*di[z]][j + t*dj[z]] == 3 - p){ continue; }
            else if(board[i + t*di[z]][j + t*dj[z]] == p){
              board[i][j] = p;
              anyflip = true;
              giveup_cnt = 0;
              for(s = 1; s <= t; s++){
                board[i + s*di[z]][j + s*dj[z]] = p;
              }
              goto NEXT_DIRECTION;
            }        
          } 
        }
      NEXT_DIRECTION: {}
      }
    }
    if(!anyflip){ printf("can't place here.\n"); goto TURN_BEGIN; }
    TURN_END: {}
  }
}

//score_count
int count(int board[][8], int *p1, int *p2){
  int i, j;
  *p1 = 0;
  *p2 = 0;
  for(i = 0; i < 8; i++){
    for(j = 0; j < 8; j++){
      if(board[i][j] == 1){
        *p1 = *p1 + 1;
      }else if(board[i][j] == 2){
        *p2 = *p2 + 1;
      }
    }
  }
  if(*p1 > *p2){ return 1; }
  else if(*p1 < *p2){ return 2; }
  else if(*p1 == *p2){ return 3; }
  }
}

int main(){
  int board[8][8] ={{0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 2, 0, 0, 0},
                    {0, 0, 0, 2, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}};
// play  
  move_othello(board);
// result
  display(board);
  int p1, p2;
  int answer = count(board, &p1, &p2);
  printf("player 1 -> %d, player 2 -> %d\n", p1, p2);
  if(answer == 1){ printf("Winner is player 1!\n"); }
  else if(answer == 2){ printf("Winner is player 2!\n"); }
  else if(answer == 3){ printf("Draw\n"); }
  else{ printf("Error\n");}
  return 0;
}
