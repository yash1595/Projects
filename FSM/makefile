objects = FSM.o  a.out 
edit	:	$(objects)
FSM.o : FSM.c 
	cc -c FSM.c
		    gcc FSM.c -w	
																
a.out	: FSM.o 
		gcc FSM.c -w
		
clean: 
		rm edit $(objects)
