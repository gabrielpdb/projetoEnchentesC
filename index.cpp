#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<math.h>
#include<cstring>
#include<iostream>
#include<string>

bool isValid = true;

void printInvalidOption() {
	printf("Opção inválida! Tente novamente!\n");
	return;
}

struct Item {
    int id;
    char description[20];

	// Construtor
    Item(int i, const char* d) : id(i) {
        strcpy(description, d);
    }
    
    void show() {
    	printf("%d - %s\n", id, description);
	}
};

Item items[10] = {
	        Item(1, "Carro"),
	        Item(2, "Geladeira"),
	        Item(3, "Fogão"),
	        Item(4, "Máquina de lavar"),
	        Item(5, "Televisão"),
	        Item(6, "Computador"),
	        Item(7, "Video game"),
	        Item(8, "Celular"),
	        Item(9, "Cama"),
	        Item(10, "Guarda roupa")
};

void listItems() {
	for(int i = 0; i < sizeof(items) / sizeof(items[0]); i++){
  		items[i].show();
	}
}

const char* getItemById(int id){
	for(int i = 0; i < 10; i++) {
		if(items[i].id == id) {
			return items[i].description;
		}
	}
}

struct Person {
	int id, people;
	char name[30];
	
	// Construtor padrão
	Person() : id(0), people(0) {
        strcpy(name, "");
    }
	
	// Construtor
    Person(int i, const char* n, int p) : id(i), people(p) {
        strcpy(name, n);
    }
    
    void show() {
    	printf("%d - %s, %d dependentes\n", id, name, people);
	}
};

Person people[100];
int peopleCount = 0;

const char* getPersonById(int id){	
	for(int i = 0; i < peopleCount; i++) {
		if(people[i].id == id) {
			return people[i].name;
		}
	}
}

struct ItemOfPerson {
	int id, personId, itemId;
	float value;
	
	// Construtor padrão
	ItemOfPerson() : id(0), personId(0), itemId(0), value(0) {}

	// Construtor
	ItemOfPerson(int i, int p, int o, float v) : id(i), personId(p), itemId(o), value(v) {}
	
	void show() {
		printf("%d - %s: R$%.2f\n", id, getItemById(itemId), value);
	}
};

ItemOfPerson itemsOfPerson[500];
int itemsOfPersonCount = 0;

ItemOfPerson createItemOfPerson(int personId){
	int itemId = 0;
	float value;
	
	do {
		system("cls");
		printf("Novo item nessa residência\n\n");
		if(isValid == false){
			printInvalidOption();
		}
		listItems();
		printf("\nEscolha o item: ");
		scanf("%d", &itemId);
		
		if(itemId <= 0 || itemId > 10){
			isValid = false;
		} else {
			isValid = true;
		}
		
	} while (!isValid);
	
	system("cls");
	printf("%s\n\n", getItemById(itemId));
	printf("Qual o valor aproximado do item? ");
	scanf("%f", &value);
	
	itemsOfPerson[itemsOfPersonCount] = ItemOfPerson(itemsOfPersonCount + 1, personId, itemId, value);
}

void setItemsOfPerson(int personId) {
	int select = 0;
	
	do {
		system("cls");
		printf("O que você deseja fazer agora %s?\n\n", getPersonById(personId));
		if(isValid == false) {
			printInvalidOption();
		}
		printf("1 - Ver items cadastrados\n");
		printf("2 - Cadastrar novo item\n");
		printf("3 - Alterar item\n");
		printf("4 - Excluir item\n\n");
		printf("0 - Sair do sistema\n");
		scanf("%d", &select);
		
		if(select < 0 || select > 4) {
			isValid = false;
		} else {
			isValid = true;
		}	
		
	} while (!isValid);
	
	switch(select){
		case 1:
			break;
		case 2:
			createItemOfPerson(personId);
			itemsOfPersonCount++;
			break;
		case 3:
			break;
		case 4:
			break;
		case 0:
			break;
	}	
}

void listItemsOfPerson(int personId) {
	for(int i = 0; i < itemsOfPersonCount; i++) {
		if(itemsOfPerson[i].personId == personId){
			itemsOfPerson[i].show();
		}
	}
}

void listPeople() {
	for(int i = 0; i < peopleCount; i++){
		people[i].show();
		printf("\nItens: \n");
		listItemsOfPerson(people[i].id);
	}
}

Person createPerson(int id) {
	char name[30];
	int nPeople = 0;
	
	system("cls");
	printf("Nova residência\n\n");
	printf("Informe seu nome: ");
	fflush(stdin);
	gets(name);
	printf("Quantas pessoas moram nessa casa? ");
	scanf("%d", &nPeople);

	return Person(id, name, nPeople);
}

int homeScreen() {
	int select = 0;
	
	system("cls");
	printf("Bem vindo à Calculadora dos Prejuízos das Enchentes do RS em 2024\n\n");
	if(isValid == false) {
		printInvalidOption();
	}
	printf("Aqui você pode escolher o que deseja fazer: \n");
	printf("1 - Ver residências cadastradas\n");
	printf("2 - Cadastrar nova residência afetada\n");
	printf("3 - Área de relatórios\n\n");
	printf("0 - Sair do sistema\n");
	scanf("%d", &select);
	
	if(select < 0 || select > 3) {
		isValid = false;
	} else {
		isValid = true;
		return select;
	}	
}

int main() {
    setlocale(LC_ALL, "");
    
    int home = 0;

	do {		
		home = homeScreen();
	} while (!isValid);	
	
	switch(home) {
		case 1:
			
			break;
		case 2:
			people[peopleCount] = createPerson(peopleCount+1);
			peopleCount++;			
			setItemsOfPerson(people[peopleCount - 1].id);
			
			
			break;
		case 0:
			break;
	}
	
	system("cls");	
	listPeople();

    return 0;
} 
