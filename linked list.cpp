#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>
#include <conio.h>

struct Node{
	int data;
	Node *next;
};

void display(Node *first){
	Node *p = first;
	while (p != NULL){
		if (p == first){
			p =p->next;
		}
		printf("%d ",p->data);
		p = p->next;
	}
}

void del_last(Node* first){
	Node *p = first;
	while(p->next != NULL){
		p = p->next;
	}
	delete p;
}

int main(){
	Node *head = new Node();
	head->next = NULL;
	
	Node*p = head;
	for (int i = 6; i > 1; i--){
		Node *temp = new Node();
		p->next = temp;
		temp->data = i;
		p = p->next;
	}
	del_last(head);
	display(head);
}
