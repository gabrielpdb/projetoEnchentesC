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

void printInvalidOption() {
	system("cls");
	printf("Op��o inv�lida! Tente novamente!\n");
	return;
}

int main() {
    setlocale(LC_ALL, "");

	Item items[10] = {
	        Item(1, "Carro"),
	        Item(2, "Geladeira"),
	        Item(3, "Fog�o"),
	        Item(4, "M�quina de lavar"),
	        Item(5, "Televis�o"),
	        Item(6, "Computador"),
	        Item(7, "Video game"),
	        Item(8, "Celular"),
	        Item(9, "Cama"),
	        Item(10, "Guarda roupa")
	};
    
  	for(int i = 0; i < sizeof(items) / sizeof(items[0]); i++){
  		printf("1");
	  }

    return 0;
}
