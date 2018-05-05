#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>

#define num 13
#define len 5
char map[num][num];

struct Cor{
	int pos_x;
	int pos_y;
};

struct Snake{
	Cor head, tail;
	char dir;
}snake;


void display(){
	for (int i = 0; i < num; i++){
		for (int j = 0; j < num; j++){
			printf("%c ", map[i][j]);
		}
		printf("\n");
	}
}

void move(char dir, int pos_x_next, int pos_y_next){
	Cor temp = snake.head;
	
}

int main(){
	for (int i = 0; i < num; i++){
		for (int j = 0; j < num; j++){
			map[i][j] = '#';
		}
	}
	for (int i = 1; i < num-1; i++){
		for (int j = 1; j < num-1; j++){
			map[i][j] = ' ';
		}
	}
	
	
	for (int j = 1; j <= len; j++){
		map[3][j] = 'O';
	}
	snake.head.pos_x = 3; snake.head.pos_y = 6;
	snake.tail.pos_x = snake.head.pos_x; snake.tail.pos_y = snake.head.pos_y - len;
	
	while(1){
		
	}
	display();
}
