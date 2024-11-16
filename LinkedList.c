#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Node {
	int value;
	struct Node* next;
};
void removeNode( int value);
struct Node* createNode(int value);
void printList();
int isEmpty();
void add( int value);
int getElement(int position);

struct Node *root = NULL;
int SIZE = 0;
int main() {

	add(1);
	add(2);
	add(3);
	printList();
	removeNode(1);
	printf("_______________________________________________\n");
	printList();
	printf("_______________________________________________\n");
	printf("%d", getElement(0));
	return 0;
}

struct Node* createNode(int value) {
	struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->next = NULL;
	ptr->value = value;
	return ptr;
}
void removeNode( int value) {
	if (root->value == value) {
		struct Node *auxPtr = root->next;
		free(root);
		root = auxPtr;
		SIZE--;
		return;
	}
	struct Node* auxPtr = root;
	while (auxPtr != NULL) {
		if (auxPtr->next != NULL && auxPtr->next->value == value) {
			struct Node *aux = auxPtr->next->next;
			free(auxPtr->next);
			auxPtr->next = aux;
			SIZE--;
			return;
		}
		auxPtr = auxPtr->next;
	}
}
void add(int value) {
	if (root == NULL) {
		root = createNode(value);
		SIZE++;
		return;
	}
	struct Node* ptrAux = root;

	while (1) {
		if (ptrAux->next == NULL) {
			ptrAux->next = createNode(value);
			SIZE++;
			return;
		}
		ptrAux = ptrAux->next;
	}
}
void printList() {
	if (root == NULL) {
		printf("List empty");
		return;
	}
	struct Node* ptrAux = root;
	while (ptrAux != NULL) {
		printf("%d\n", ptrAux->value);
		ptrAux = ptrAux->next;
	}
}

int getElement(int position) {
	if (position >= SIZE) {
		printf("Error in position\n");
		return NULL;
	}
	struct Node* auxPtr = root;
	while (position >= 0) {
		if (position == 0) {
			return auxPtr->value;
		}
		auxPtr = auxPtr->next;
		position--;
	}
	return NULL;
}

int isEmpty() {
	if (root == NULL) {
		return 1;
	}
	return 0;
}

