#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>
#include <iostream>
#include <conio.h>

#define num 13   // kich co map
#define len 5   //do dai con ran
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

void moveDown(){
	Cor temp = snake.head;
	map[snake.tail.pos_x][snake.tail.pos_y] = ' ';
	map[snake.head.pos_x + 1][snake.head.pos_y + 0] = 'O';
	if (snake.tail.pos_y == temp.pos_y){
		snake.head.pos_x++;
		snake.tail.pos_x++;
	}
	else{
		snake.head.pos_x++;
		snake.tail.pos_y++;
	}
	system ("cls");
	display();
	sleep(1);
}

void moveRight(){
	Cor temp = snake.head;
	map[snake.tail.pos_x][snake.tail.pos_y] = ' ';
	map[snake.head.pos_x + 0][snake.head.pos_y + 1] = 'O';
	if (snake.tail.pos_x == temp.pos_x){
		snake.head.pos_y++;
		snake.tail.pos_y++;
	}
	else{
		snake.head.pos_y++;
		snake.tail.pos_x++;
	}
	system ("cls");
	display();
	sleep(1);
}

int main(){
	char key;
	
	for (int i = 0; i < num; i++){       // make a new map
		for (int j = 0; j < num; j++){
			map[i][j] = '#';
		}
	}
	for (int i = 1; i < num-1; i++){
		for (int j = 1; j < num-1; j++){
			map[i][j] = ' ';
		}
	}
	
	
	for (int j = 1; j <= len; j++){  // make a new snake
		map[3][j] = 'O';
	}
	snake.head.pos_x = 3; snake.head.pos_y = 5;
	snake.tail.pos_x = snake.head.pos_x; snake.tail.pos_y = snake.head.pos_y - len + 1;
	
	display();
	sleep(1);
	while(snake.head.pos_y != num-1 && snake.head.pos_y != 0 && snake.head.pos_x != num-1 && snake.head.pos_x != 0){
		if (kbhit()){
			if (GetAsyncKeyState(VK_UP)){
				snake.dir = 'w';
			}
			else if (GetAsyncKeyState(VK_DOWN)){
				snake.dir = 's';
			}
			else if (GetAsyncKeyState(VK_RIGHT)){
				snake.dir = 'd';
			}
			else{
				snake.dir = 'a';
			}
		}
		switch (snake.dir){
			case 'd':
				moveRight(); break;
			case 's':
				moveDown(); break;

		}
	}
}
