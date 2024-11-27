#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum DataType {
	Integer,
	Character,
	String,
	Real
};
union Value;
struct Node;
void removeNode( int value);
struct Node* createNodeInt(int value);
struct Node* createNodeChar(char value);
struct Node* createNodeString(char value[]);
struct Node* createNodeFloat(float value);
void printList();
int isEmpty();
void addInt(int value);
void addChar(char value);
void addString(char value[]);
void addFloat(float value);
int getElement(int position);

struct Node *root = NULL;
int SIZE = 0;
enum DataType dataType = Integer;
int main() {
	printList();
	return 0;
}

union ValueNode {
	int integer;
	char character;
	char *string;
	float real;
};
struct Node {
	union ValueNode* value;
	struct Node* next;
};

struct Node* createNodeInt(int value) {
	if (dataType != Integer) {
		
		printf("Operação invalida!!\nTodos elementos da lista devem ser do mesmo tipo");
		return NULL;
	}
	struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->next = NULL;
	ptr->value = (union ValueNode*)malloc(sizeof(union ValueNode));
	ptr->value->integer = value;
	return ptr;
}
struct Node* createNodeChar(char value) {
	if (dataType != Character) {
		printf("Operação invalida!!\nTodos elementos da lista devem ser do mesmo tipo");
		return NULL;
	}
	struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->next = NULL;
	ptr->value = (union ValueNode*)malloc(sizeof(union ValueNode));
	ptr->value->character = value;
	return ptr;
}
struct Node* createNodeString(char value[]) {
	if (dataType != String) {
		printf("Operação invalida\nTodos os elementos da lista devem ser do mesmo tipo");
		return NULL;
	}
	struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->next = NULL;
	ptr->value = (union ValueNode*)malloc(sizeof(union ValueNode));
	char* auxChar = (char*)calloc(30, sizeof(char));
	if (auxChar == NULL)return NULL;
	for (int i = 0;i < 30 - 1;i++) {
		if (value[i] == '\0') {
			auxChar[i] = value[i];
			break;
		}
		auxChar[i] = value[i];
	}
	
	ptr->value->string = auxChar;
	return ptr;
}
struct Node* createNodeFloat(float value) {
	if (dataType != Real) {
		printf("Operação invalida!!\nTodos elementos da lista devem ser do mesmo tipo");
		return NULL;
	}
	struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->next = NULL;
	ptr->value = (union ValueNode*)malloc(sizeof(union ValueNode));
	ptr->value->real = value;
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
void addInt(int value) {
	if (root == NULL) {
		dataType = Integer;
		root = createNodeInt(value);
		SIZE++;
		return;
	}
	struct Node* ptrAux = root;

	while (1) {
		if (ptrAux->next == NULL) {
			ptrAux->next = createNodeInt(value);
			SIZE++;
			return;
		}
		ptrAux = ptrAux->next;
	}
}
void addChar(char value) {
	if (root == NULL) {
		dataType = Character;
		root = createNodeChar(value);
		SIZE++;
		return;
	}
	struct Node* ptrAux = root;

	while (1) {
		if (ptrAux->next == NULL) {
			ptrAux->next = createNodeChar(value);
			SIZE++;
			return;
		}
		ptrAux = ptrAux->next;
	}
}
void addString(char value[]) {
	if (root == NULL) {
		dataType = String;
		root = createNodeString(value);
		SIZE++;
		return;
	}
	struct Node* ptrAux = root;

	while (1) {
		if (ptrAux->next == NULL) {
			ptrAux->next = createNodeString(value);
			SIZE++;
			return;
		}
		ptrAux = ptrAux->next;
	}
}
void addFloat(float value) {
	if (root == NULL) {
		dataType = Real;
		root = createNodeFloat(value);
		SIZE++;
		return;
	}
	struct Node* ptrAux = root;

	while (1) {
		if (ptrAux->next == NULL) {
			ptrAux->next = createNodeFloat(value);
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
		switch (dataType)
		{
		case Integer:
			printf("%d\n", ptrAux->value->integer);
			break;
		case Character:
			printf("%c\n", ptrAux->value->character);
			break;
		case String:
			printf("%s\n", ptrAux->value->string);
			break;
		case Real:
			printf("%f\n", ptrAux->value->real);
			break;
		default:
			
			break;
		}
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

