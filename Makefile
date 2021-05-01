# Para executar basta digitar no console make (enter) e depois ./exec (enter)
exec: main.c Labirinto.c Estudante.c
	gcc -o exec main.c Labirinto.c Estudante.c

clean:
	rm exec 
