#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>
#include <conio.h>

#define num 13
#define len 3
char map[num][num];

struct Data{
	int pos_x;
	int pos_y;
};

struct Node{
	Data cor;
	Node *prev;
};


void display(){
	system ("cls");
	for (int i = 0; i < num; i++){
		for (int j = 0; j < num; j++){
			printf("%c ", map[i][j]);
		}
		printf("\n");
	}
	sleep(1);
}

void delete_last(Node *first){
	Node *pre = first;
	Node *to_del =first;
	while(to_del->prev != NULL){
		pre = to_del;
		to_del = to_del->prev;
	}
	map[to_del->cor.pos_x][to_del->cor.pos_y] = ' ';
	pre->prev = NULL;
	free(to_del);
}

void init_snake(Node *first){
	Node *p = first;
	for (int i = 6; i > 3; i--){
		Node *temp = new Node();
		p->prev = temp;
		temp->cor.pos_y = i;
		temp->cor.pos_x = 3;
		p = p->prev;
	}
}


void update_snake(Node *first){
	Node *p = first;
	while (p != NULL){
		if (p == first){
			p = p->prev;
		}
		else{
			map[p->cor.pos_x][p->cor.pos_y] = 'O';
			p = p->prev;	
		}
	}
}

void move(Node *first, int dx, int dy){
	delete_last(first);
	Node *temp = new Node();
	temp->cor.pos_x = first->prev->cor.pos_x + dx;
	temp->cor.pos_y = first->prev->cor.pos_y + dy;
	temp->prev = first->prev;
	first->prev = temp;
	update_snake(first);
	display();	
}

int main(){
	Node *head = new Node();
	head->prev = NULL;
	head->cor.pos_x = head->cor.pos_y = 0;
	
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
	
	init_snake(head);
	
	update_snake(head);
	display();
	while(1){
		move(head,0,1);
		move(head,1,0);
	}	

		
	

}
