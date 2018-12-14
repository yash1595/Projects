#include <stdio.h>

char* States[]={"Green\n","","Yellow\n","","Red\n"};

typedef enum{Green=0,Yellow=2,Red=4}lights;
typedef enum{GO,STOP}events;

typedef struct{
	lights c_light;		//Green
	events c_event;		//GO
	lights n_light;		//Green
}StateTransitions;

StateTransitions structTable[]={
	{Green,GO,Green},
	{Green,STOP,Yellow},
	{Yellow,GO,Yellow},
	{Yellow,STOP,Red},
	{Red,GO,Green},
	{Red,STOP,Red},
};

lights current_light = Green;
events input_event=0;
int i=0;

lights NextState;
lights TransitionHandler(void)
{
	current_light=structTable[current_light+input_event].n_light;
	return current_light;
}

int main(void)
{   while(1)
    {	
    	printf("Enter the next event:");
        scanf("%d",&input_event);
        NextState=TransitionHandler();
        printf("%s\n",(States[NextState])); 
    }
          
}

