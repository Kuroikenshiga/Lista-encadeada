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

struct Node *root = NULL;

int main() {

	add(1);
	add(2);
	add(3);
	printList();
	removeNode(5);
	printf("_______________________________________________\n");
	printList();

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
		return;
	}
	struct Node* auxPtr = root;
	while (auxPtr != NULL) {
		if (auxPtr->next != NULL && auxPtr->next->value == value) {
			struct Node *aux = auxPtr->next->next;
			free(auxPtr->next);
			auxPtr->next = aux;
			return;
		}
		auxPtr = auxPtr->next;
	}
}
void add(int value) {
	if (root == NULL) {
		root = createNode(value);
		return;
	}
	struct Node* ptrAux = root;

	while (1) {
		if (ptrAux->next == NULL) {
			ptrAux->next = createNode(value);
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

int isEmpty() {
	if (root == NULL) {
		return 1;
	}
	return 0;
}

