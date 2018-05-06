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
	Node *pre = first;
	Node *to_del =first;
	while(to_del->next != NULL){
		pre = to_del;
		to_del = to_del->next;
	}
	pre->next = NULL;
	free(to_del);
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
