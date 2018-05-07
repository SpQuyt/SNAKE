#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>
#include <conio.h>
#include <time.h>

#define num 15
int len = 0;     //length of body = score
int row, col;	// coordination of food
char map[num][num];
char wish[400] = {" HAPPY BIRTHDAY TO YOU. \nI know this could be awkward, but today is your special day. \nDo you still remember the email you wrote to me on M45's Boys day? \nThat you hoped we could be friend again, no matter what happened after the break-up, right? \nHope to see news from you soon. \nBest wishes, Zhang UK."};

struct Data{
	int pos_x;
	int pos_y;
};

struct Node{
	Data cor;
	Node *prev;
};

void announce_happybirthday(){
	int i = 0;
	while(wish[i] != '\0'){
		if (wish[i] != '.' && wish[i] != ',' && wish[i] != '?'){
			printf("%c", wish[i]);
			_sleep(50);
		}
		else{
			printf("%c\n", wish[i]);
			sleep(2);
		}
		i++;
	}
}

void init_map(){
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
	
	while (1){
		srand(time(NULL));
		row = rand() % (num-2) + 1;
		col = rand() % (num-2) + 1;
		if (map[row][col] != 'O' && map[row][col] != 'X'){		//check if a part of snake's body is there?
				map[row][col] = '+';
				break;
		}
	}
}

void display(){
	system ("cls");
	for (int i = 0; i < num; i++){
		for (int j = 0; j < num; j++){
			printf("%c ", map[i][j]);
		}
		printf("\n");
	}
	_sleep(50); // delaying time
}

void delete_last(Node *first){   //delete the tail
	Node *aft = first;
	Node *to_del =first;
	while(to_del->prev != NULL){
		aft = to_del;
		to_del = to_del->prev;
	}
	map[to_del->cor.pos_x][to_del->cor.pos_y] = ' ';
	aft->prev = NULL;
	free(to_del);

}

void init_snake(Node *first){
	Node *p = first;
	for (int i = 2; i > 1; i--){
		Node *temp = new Node();
		p->prev = temp;
		temp->cor.pos_y = i;
		temp->cor.pos_x = 1;
		p = p->prev;
	}
}


void update_snake(Node *first){
	Node *p = first;
	while (p != NULL){
		if (p == first){
			p = p->prev;
			map[p->cor.pos_x][p->cor.pos_y] = 'X';    //head of the snake
			p = p->prev;
		}
		else{
			map[p->cor.pos_x][p->cor.pos_y] = 'O';	  //body of the snake
			p = p->prev;	
		}
	}
	system ("cls");
	display();
}

void move(Node *first, int dx, int dy){
	Node *temp = new Node();                          //
	temp->cor.pos_x = first->prev->cor.pos_x + dx;
	temp->cor.pos_y = first->prev->cor.pos_y + dy;
	temp->prev = first->prev;
	first->prev = temp;                                // move the head
	
	if (map[temp->cor.pos_x][temp->cor.pos_y] != '+'){		//if the snake hasn't eaten the food
		delete_last(first);  							// delete the tail
	}
	else{														//else
		while (1){
			row = rand() % (num-2) + 1;
			col = rand() % (num-2) + 1;
			if (map[row][col] != 'O' && map[row][col] != 'X'){
					map[row][col] = '+';
					len++;
					break;
			}
		}
	}
	
	update_snake(first);
	display();	
}

void running(Node *&head){								// create a reference
	char dir;
	while((head->prev->cor.pos_y != num-1 && head->prev->cor.pos_y != 0 && head->prev->cor.pos_x != num-1 && head->prev->cor.pos_x != 0) && (map[head->prev->cor.pos_x][head->prev->cor.pos_y] != 'O')){
			if (len == 1){
				system ("cls");
				sleep(1);
				announce_happybirthday();
				break;
			}
			else{
				if (kbhit()){
					if (GetAsyncKeyState(VK_UP)){
						dir = 'w';
					}
					else if (GetAsyncKeyState(VK_DOWN)){
						dir = 's';
					}
					else if (GetAsyncKeyState(VK_RIGHT)){
						dir = 'd';
					}
					else if (GetAsyncKeyState(VK_LEFT)){
						dir = 'a';
					}
				}
				switch (dir){
					case 'a':
						move(head,0,-1);break;
					case 'd':
						move(head,0,1); break;
					case 'w':
						move(head,-1,0); break;
					case 's':
						move (head,1,0); break;
				}				
			}
	}
}

void announce_over(){
	display();
	printf("\n\n	GAME OVER. \n\n     Your score is %d.", len);
}


void intro(){
	printf("== THIS IS A SNAKE GAME ==\n");
	printf("== IF YOU HAVE 15 SCORES, A GIFT WILL BE GIVEN TO YOU ==\n");
	printf("== IF YOU ARE READY, PRESS ENTER AND GO ==");
	getch();
}

int main(){
	//char dir;

	Node *head = new Node();
	head->prev = NULL;

	intro();
	init_map();	
	init_snake(head);
	update_snake(head);
	
	display();
	running(head);
	return 0;
	//announce_over();		this is for the game
	

}
