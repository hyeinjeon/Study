#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE_R 10   
#define ARR_SIZE_C 10  
#define WIN_NUMBER 5   

int display(void);     
int omok_play(void);     

int set_pan(char [][ARR_SIZE_C]);       
int print_pan(char [][ARR_SIZE_C]);      
int input_player(int*, int*, int*, char [][ARR_SIZE_C]); 
int input_check(int, int, char [][ARR_SIZE_C]);   
int win_check(int, int, int, char [][ARR_SIZE_C]);    
int horizontal_check(char, int, int, char [][ARR_SIZE_C]);  
int vertical_check(char, int, int, char [][ARR_SIZE_C]);  
int diagonal1_check(char, int, int, char [][ARR_SIZE_C]); 
int diagonal2_check(char, int, int, char [][ARR_SIZE_C]); 

int retry_game(void);  

int main(void)
{
 display();  

 omok_play();  

 return 0;
}

int display(void)
{
 puts("  =========================================");
 printf("\t     오 목 게 임 (%d X %d)\n", ARR_SIZE_R, ARR_SIZE_C);
 puts("  =========================================\n");

 return 0;
}

int omok_play(void)
{
 char omok_pan[ARR_SIZE_R][ARR_SIZE_C];   
 int panIdx_r=0, panIdx_c=0, play=1, initialize=1, win, sPlayer, ckCnt; 

 while(play)  
 {
  if(initialize) 
  {
   set_pan(omok_pan);  
   sPlayer = 1;    
   win = 0;     
   ckCnt = 1;    
   initialize = 0;    
   
  }  

  print_pan(omok_pan); 
  
  if(win == 0)  
  {
   input_player(&sPlayer, &panIdx_r, &panIdx_c, omok_pan); 
   
   if(ckCnt >= (WIN_NUMBER*2)-1)   
    win = win_check(sPlayer, panIdx_r-1, panIdx_c-1, omok_pan); 
  }
  else    
  {
   printf("%s이 승리 하였습니다.\n\n", (win == 1)?"검은돌":"하얀돌"); 
 
   play = retry_game();  

   if(play == 1)  
   {
    initialize = 1; 
   }
  }

  if(win == 0 && sPlayer == 1)   
   sPlayer = 2;
  else if(win == 0 && sPlayer == 2) 
   sPlayer = 1;

  ckCnt++;   

  if(play == 1)    
   system("cls");  
 }

 return 0;
}


int set_pan(char omok_pan[][ARR_SIZE_C])
{
 int nIdx_r, nIdx_c;

 for(nIdx_r=0; nIdx_r<ARR_SIZE_R; nIdx_r++)
 {
  for(nIdx_c=0; nIdx_c<ARR_SIZE_C; nIdx_c++)
  {
   omok_pan[nIdx_r][nIdx_c] = '_'; 
  }
 }

 return 0;
}

int print_pan(char omok_pan[][ARR_SIZE_C])
{
 int nIdx_r, nIdx_c, nCnt;

 puts("  -----------------------------------------");
 puts("\t\t오목판 상황");
 puts("  -----------------------------------------\n");

 for(nCnt=1; nCnt<=ARR_SIZE_C; nCnt++)  
 { 
  if(nCnt == 1)
  {
   printf("    ");
  }

  printf("%3d ", nCnt);
 }

 puts("\n");

 for(nIdx_r=0; nIdx_r<ARR_SIZE_R; nIdx_r++)   
 {
  printf("%3d ", nIdx_r+1);

  for(nIdx_c=0; nIdx_c<ARR_SIZE_C; nIdx_c++)
  {
   printf(" %2c ", omok_pan[nIdx_r][nIdx_c]);
  }
  puts("\n");
 }

 return 0;
}

int input_player(int* sPlayer, int* pIdx_r, int* pIdx_c, char omok_pan[][ARR_SIZE_C])
{
 int inFlag=0;   

 while(inFlag == 0)  
 {
  printf("\n%s돌을 입력할 위치를 입력하시오[행 열] : ", (*sPlayer == 1)?"검은[X]":"하얀[O]");  

  scanf("%d %d", pIdx_r, pIdx_c);   

  inFlag = input_check(*pIdx_r, *pIdx_c, omok_pan);  

  if(inFlag)  
   omok_pan[*pIdx_r-1][*pIdx_c-1] = (*sPlayer == 1)?'X':'O'; 
  else   
   puts("입력할 곳에 이미 돌이 있거나 범위를 벗어났습니다.");
 }

 return 0;
}

int input_check(int pIdx_r, int pIdx_c, char omok_pan[][ARR_SIZE_C])
{
 int inFlag=0;   

 if((pIdx_r-1>=0 && pIdx_r-1<ARR_SIZE_R) && (pIdx_c-1>=0 && pIdx_c-1<ARR_SIZE_C))   

 {
  if(omok_pan[pIdx_r-1][pIdx_c-1] == '_')  
   inFlag=1; 
  else    
   inFlag = 0;  
 }
 else 
 {
  inFlag = 0;  
 }

 return inFlag;  
}

int win_check(int sPlayer, int panIdx_r, int panIdx_c, char omok_pan[][ARR_SIZE_C])
{
 char cStone = (sPlayer == 1)?'X':'O';  
 int win=0;  

 if(sPlayer == 1)  
 {
  
  if((horizontal_check(cStone, panIdx_r, panIdx_c, omok_pan) == WIN_NUMBER) || 
   (vertical_check(cStone, panIdx_r, panIdx_c, omok_pan) == WIN_NUMBER) ||  

   (diagonal1_check(cStone, panIdx_r, panIdx_c, omok_pan) == WIN_NUMBER) ||  

   (diagonal2_check(cStone, panIdx_r, panIdx_c, omok_pan) == WIN_NUMBER))  

  {
   win = 1;  
  }
 }
 else if(sPlayer == 2)  
 {
  
  if((horizontal_check(cStone, panIdx_r, panIdx_c, omok_pan) >= WIN_NUMBER) ||  
   (vertical_check(cStone, panIdx_r, panIdx_c, omok_pan) >= WIN_NUMBER) ||  
 
   (diagonal1_check(cStone, panIdx_r, panIdx_c, omok_pan) >= WIN_NUMBER) ||  

   (diagonal2_check(cStone, panIdx_r, panIdx_c, omok_pan) >= WIN_NUMBER))  

  {
   win = 2;
  }
 }
 
 return win;
}

int horizontal_check(char cStone, int panIdx_r, int panIdx_c, char omok_pan[][ARR_SIZE_C])
{ 
 int winCnt=0, pIdx_c, mIdx_c;

 pIdx_c = mIdx_c = panIdx_c;  

 while(omok_pan[panIdx_r][pIdx_c--] == cStone) 
 {
  winCnt++; 
 }
 while(omok_pan[panIdx_r][++mIdx_c] == cStone)  
 {
  winCnt++;
 }

 return winCnt;
}

int vertical_check(char cStone, int panIdx_r, int panIdx_c, char omok_pan[][ARR_SIZE_C])
{
 
 int winCnt=0, pIdx_r, mIdx_r;

 pIdx_r = mIdx_r = panIdx_r;  

 while(omok_pan[mIdx_r--][panIdx_c] == cStone)   
 {
  winCnt++; 
 }
 while(omok_pan[++pIdx_r][panIdx_c] == cStone)  
 {
  winCnt++; 
 }

 return winCnt;
}

int diagonal1_check(char cStone, int panIdx_r, int panIdx_c, char omok_pan[][ARR_SIZE_C])
{
 
 int winCnt=0, pIdx_r, mIdx_r, pIdx_c, mIdx_c;

 pIdx_r = mIdx_r = panIdx_r;
 pIdx_c = mIdx_c = panIdx_c;  

 while(omok_pan[mIdx_r--][mIdx_c--] == cStone)  
 {
  winCnt++;  
 }
 while(omok_pan[++pIdx_r][++pIdx_c] == cStone)   
 {
  winCnt++; 
 }

 return winCnt;
}

int diagonal2_check(char cStone, int panIdx_r, int panIdx_c, char omok_pan[][ARR_SIZE_C])
{
 
 int winCnt=0, pIdx_r, mIdx_r, pIdx_c, mIdx_c;

 pIdx_r = mIdx_r = panIdx_r;  
 pIdx_c = mIdx_c = panIdx_c;  

 while(omok_pan[mIdx_r--][pIdx_c++] == cStone) 
 {
  winCnt++; 
 }
 while(omok_pan[++pIdx_r][--mIdx_c] == cStone)  
 {
  winCnt++;  
 }

 return winCnt;
}

int retry_game(void)
{
 char cRetry;   
 int reNum=0; 

 fflush(stdin); 

 puts("오목 게임을 계속 하시겠습니까?");
 
 do
 {
  printf("계속 하시려면[Y(y)], 종료하려면[N(n)]을 눌러주십시오 : ");
  scanf("%c", &cRetry);
 }
 while((cRetry != 'Y') && (cRetry != 'y') && (cRetry != 'N') && (cRetry != 'n'));  

 puts("");

 if((cRetry == 'Y') || (cRetry == 'y')) 
 {
  reNum = 1;
 }
 else if((cRetry == 'N') || (cRetry == 'n'))  
 {
  puts("오목 게임을 종료합니다.");

  reNum = 0;
 }

 return reNum;
}