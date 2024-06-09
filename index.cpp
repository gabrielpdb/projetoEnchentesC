#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<math.h>

void printInvalidOption() {
	system("cls");
	printf("Opção inválida! Tente novamente!\n");
	return;
}

int selectItem() {
	int selection = 0;
	
	do {
		printf("Escolha o item perdido na enchente\n\n");
		printf("1 - Carro\n");
		printf("2 - Geladeira\n");
		printf("3 - Freezer\n");
		printf("4 - Fogão\n");
		printf("5 - Máquina de lavar\n");
		printf("6 - Televisão\n");
		printf("7 - Computador\n");
		printf("8 - Video game\n");
		printf("9 - Celular\n");
		printf("10 - Cama\n");
		printf("11 - Guarda roupa\n");
		printf("12 - Mesa\n");;
		scanf("%d", &selection);
		
		if(selection < 1 || selection > 12){
			printInvalidOption();
		}
		
	} while (selection < 1 || selection > 12);

	return selection;	
}

const char* getItemById(int id){
	
	switch(id){
		case 1:
			return "Carro";
			break;
		case 2:
			return "Geladeira";
			break;
		case 3:
			return "Freezer";
			break;
		case 4:
			return "Fogão";
			break;
		case 5:
			return "Máquina de lavar";
			break;
		case 6:
			return "Televisão";
			break;
		case 7:
			return "Computador";
			break;
		case 8:
			return "Video game";
			break;
		case 9:
			return "Celular";
			break;
		case 10:
			return "Cama";
			break;
		case 11:
			return "Guarda roupa";
			break;
		case 12:
			return "Mesa";
			break;
	}
}

int setQuantityOfItem(int itemId) {
	int quantity = 0;
	
	do {
		printf("Qual quantidade de %s você perdeu? ", getItemById(itemId));
		scanf("%d", &quantity);
		
		if(quantity < 0){
			printInvalidOption();
		}
	} while (quantity < 0);
	
	return quantity;
}

int main(void){
	setlocale(LC_ALL, "");
	
	char name[30];

	printf("Informe seu nome: ");
	gets(name);
	
	printf("%s", getItemById(2));
	
	setQuantityOfItem(3);
	
	
	
	return 0;
}
