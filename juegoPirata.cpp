#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_table(int a[10][10]) {
	for(int i = 0; i < 10 ;i++) {
		for(int j = 0; j < 10 ;j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void game(int a[10][10]) {
	int i = 0, j = 0, s = 0;
	
	while (1) {
		printf("Elegir el movimiento, arriba = 1, abajo = 2, derecha = 3, izquierda = 4\n");
		int c = 0;
		scanf("%d", &c);
		switch(c){
			case 1:
				if (a[i-1][j] != 0) {
					a[i-1][j] = 2;
					a[i][j] = 1;
					i-=1;
					print_table(a);	
				} else s = 1;
				break;
				
			case 2:
				if (a[i+1][j] != 0) {
					a[i+1][j] = 2;
					a[i][j] = 1;
					i+=1;
					print_table(a);	
				} else s = 1;
				break;
			case 3:
				if (a[i][j+1] != 0) {
					a[i][j+1] = 2;
					a[i][j] = 1;
					j+=1;
					print_table(a);	
				} else s = 1;
				break;
			case 4:
				if (a[i][j-1] != 0) {
					a[i][j-1] = 2;
					a[i][j] = 1;
					j-=1;
					print_table(a);	
				} else s = 1;
				break;
		}
		if (s) {
			printf("Perdiste\n");
			break;
		}
		if (a[9][9] == 2) {
			printf("Ganaste!\n");
			break;
		}
	}
}

void zero(int a[10][10]) {
	a[0][0] = 2;
	for(int k = 0; k < 3; k++) {
		if (a[0][0] == 0 || a[9][9] == 0) {
			a[0][0] = 2;
			a[9][9] = 1;
		}
		a[rand() % 10][rand() % 10]= 0;
	}
}

void fill(int a[10][10]) {
	for(int i = 0; i < 10 ;i++) {
		for(int j = 0; j < 10 ;j++) {
			a[i][j] = 1;
		}
	}
}

int main(){	
	srand(time(NULL));
	int a[10][10];
	
	
	fill(a);
	zero(a);
	print_table(a);
	game(a);
	


	return 0;
}
