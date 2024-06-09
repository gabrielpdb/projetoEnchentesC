#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<math.h>
#include <cstring>

struct Item {
    int id;
    char description[20];

    Item(int i, const char* d) : id(i) {
        strcpy(description, d);
    }
};

struct Person {
	int id;
	char name[30];
	char address[50];
	
    void setId(int i) {
        id = i;
    }

    void setName(const char* n) {
        strcpy(name, n);
    }

    void setAddress(const char* a) {
        strcpy(address, a);
    }
};

void printInvalidOption() {
	system("cls");
	printf("Opção inválida! Tente novamente!\n");
	return;
}

int main() {
    setlocale(LC_ALL, "");

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
	
	Person people[100];
	int peopleCount = 0;
	
	char name[30], address[50];
	
	printf("Informe seu nome: ");
	gets(name);
	printf("Informe seu endereço: ");
	gets(address);
	
	people[peopleCount].setId(peopleCount + 1);
	people[peopleCount].setName(name);
	people[peopleCount].setAddress(address);
	peopleCount++;
    
  	for(int i = 0; i < peopleCount; i++){
  		printf("Pessoa %d\n", people[i].id);
  		printf("Nome: %s\n", people[i].name);
  		printf("Endereço: %s\n", people[i].address);
	}
	
	for(int i = 0; i < 10; i++){
  		printf("Item %d\n", items[i].id);
  		printf("Descrição: %s\n\n", items[i].description);
  		
	}

    return 0;
}
