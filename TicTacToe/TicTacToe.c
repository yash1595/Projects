#include <stdio.h>
#define ROW	3
#define	COL	3	


typedef enum{No=0,Yes=1}Winner;
char lookUpPlayer[2]={'X','O'};
char matrix[ROW][COL] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int player = 0;
int playerchanged=0;
int count=0;
char Names[2][10];

void Display(void);
int MoveCursor(void);
int EnterValue(char,int,int);
int CheckWinner(void);
void PlayerTurn(void);
void PlayerNames(void);

int main(void)
{	

	Winner winner=0;
	Display();
	PlayerNames();
	while(1)
	{
		playerchanged=MoveCursor();
		while(playerchanged)
		{
			playerchanged=MoveCursor();
		}
		winner = CheckWinner();
		if(count==9 && !winner){printf("No Winner!\n");break;}
		if(winner)
		{
		    printf("%s Wins!\n",Names[player]);
		    break;
		}
		else PlayerTurn();
	}
	
	return 0;
}

void PlayerNames()
{
	printf("Player 1 Enter your name:");
	scanf("%s",&Names[0]);
	printf("Player 2 Enter your name:");
	scanf("%s",&Names[1]);

}
void Display()
{
	static int i=0,j=0;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			printf("%c|",matrix[i][j]);
		}
		printf("\n");
		printf("- - -");
		printf("\n");
	}
}

void PlayerTurn()
{
	player^=1;
}

int MoveCursor()
{	
	int cursor = 0;
	char input = 0;
	int x=0,y=0;
	printf("%s enter the box and value %c:",Names[player],lookUpPlayer[player]);
	scanf("%d %c",&cursor,&input);
	switch(cursor)
	{
		case 1: x=0;
				y=0;
				playerchanged=EnterValue(input,x,y);
				Display();
				break;
		case 2: x=0;
				y=1;
				playerchanged=EnterValue(input,x,y);
				Display();
				break;
		case 3: x=0;
				y=2;
				playerchanged=EnterValue(input,x,y);
				Display();
				break;
		case 4: x=1;
				y=0;
				playerchanged=EnterValue(input,x,y);
				Display();
				break;
		case 5: x=1;
				y=1;
				playerchanged=EnterValue(input,x,y);
				Display();
				break;
		case 6: x=1;
				y=2;
				playerchanged=EnterValue(input,x,y);
				Display();
				break;
		case 7: x=2;
				y=0;
				playerchanged=EnterValue(input,x,y);
				Display();
				break;
		case 8: x=2;
				y=1;
				playerchanged=EnterValue(input,x,y);
				Display();
				break;
		case 9: x=2;
				y=2;
				playerchanged=EnterValue(input,x,y);
				Display();
				break;
	}
	return playerchanged;

}
	
int EnterValue(char input,int x,int y)
{   
	if(input!=lookUpPlayer[player]){PlayerTurn();return playerchanged=1;}
	matrix[x][y]=input;
	//printf("%c",matrix[x][y]);
	return playerchanged=0;
}

int CheckWinner()
{	
	if(count!=9)
	{
	     if((matrix[0][0]==matrix[0][1]) && (matrix[0][1]==matrix[0][2]) && (matrix[0][0]=='X' || matrix[0][0]=='O')){count++;return 1; }
	else if((matrix[1][0]==matrix[1][1]) && (matrix[1][1]==matrix[1][2]) && (matrix[1][0]=='X' || matrix[1][0]=='O')){count++;return 1; }
	else if((matrix[2][0]==matrix[2][1]) && (matrix[2][1]==matrix[2][2]) && (matrix[2][0]=='X' || matrix[2][0]=='O')){count++;return 1; }

	else if((matrix[0][0]==matrix[1][0]) && (matrix[1][0]==matrix[2][0]) && (matrix[1][0]=='X' || matrix[1][0]=='O')){count++;return 1; }
	else if((matrix[0][1]==matrix[1][1]) && (matrix[1][1]==matrix[2][1]) && (matrix[0][1]=='X' || matrix[0][1]=='O')){count++;return 1; }
	else if((matrix[0][2]==matrix[1][2]) && (matrix[1][2]==matrix[2][2]) && (matrix[0][2]=='X' || matrix[0][2]=='O')){count++;return 1;}

	else if((matrix[0][0]==matrix[1][1]) && (matrix[1][1]==matrix[2][2]) && (matrix[0][0]=='X' || matrix[0][0]=='O')){count++;return 1;}
	else if((matrix[0][2]==matrix[1][1]) && (matrix[1][1]==matrix[2][0]) && (matrix[0][2]=='X' || matrix[0][2]=='O')){count++;return 1;}
	}
	count+=1;
	return No;

}
