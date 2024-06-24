#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<math.h>
#include<cstring>
#include<iostream>
#include<string>

bool isValid = true;

void printInvalidOption() { //Função da mensagem de opção inválida nos menus
	printf("Opção inválida! Tente novamente!\n");
	return;
}

struct Item { //Declaração da struct de item
    int id;
    char description[20];

	// Construtor
    Item(int i, const char* d) : id(i) {
        strcpy(description, d);
    }
    
    void show() { //Função que exibe o item na tela
    	printf("%d - %s\n", id, description);
	}
};

Item items[10] = { //Declaração do array de itens
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

void listItems() { // Função que lista os itens e exibe na tela
	for(int i = 0; i < sizeof(items) / sizeof(items[0]); i++){
  		items[i].show();
	}
	return;
}

const char* getItemById(int id){ // Função que retorna nome do item pelo id informado
	for(int i = 0; i < 10; i++) {
		if(items[i].id == id) {
			return items[i].description;
		}
	}
}

struct Person { //Declaração da struct de pessoa, ou residência como é exibido em tela
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
    
    void show() { //Função que exibe em tela a residência
    	printf("%d - Residência de %s, %d moradores\n", id, name, people);
	}
};

Person people[100] = { // Declaração do array de pessoas
	Person(1, "João", 2),
	Person(2, "Maria", 4),
	Person(3, "Fernando", 5),
	Person(4, "Marco", 1),
	Person(5, "José", 3),
	Person(6, "Ana", 2),
	Person(7, "Carlos", 6),
	Person(8, "Beatriz", 3),
	Person(9, "Rafael", 4),
	Person(10, "Sofia", 5),
	Person(11, "Gabriel", 2),
	Person(12, "Juliana", 3),
	Person(13, "Roberto", 4),
	Person(14, "Laura", 2),
	Person(15, "Bruno", 3),
	Person(16, "Carla", 1),
	Person(17, "Eduardo", 5),
	Person(18, "Fernanda", 4),
	Person(19, "Leonardo", 3),
	Person(20, "Camila", 2),
	Person(21, "Pedro", 4),
	Person(22, "Renata", 3),
	Person(23, "Marcelo", 2),
	Person(24, "Patricia", 4),
	Person(25, "Thiago", 3),
	Person(26, "Mariana", 2),
	Person(27, "Rodrigo", 5),
	Person(28, "Aline", 1),
	Person(29, "Daniel", 3),
	Person(30, "Luciana", 4)
};
int peopleCount = 30;

int getTotalPeople() { // Função que retorna o número total de moradores informados em todas as residências
	int total = 0;
	
	for(int i = 0; i < peopleCount; i++){
		total = total + people[i].people;
	}
	
	return total;
}

const char* getPersonById(int id){	// Função que retorna o nome da residência pelo id informado
	for(int i = 0; i < peopleCount; i++) {
		if(people[i].id == id) {
			return people[i].name;
		}
	}
}

struct ItemOfPerson { // Declaração da struct de itens das residências
	int id, personId, itemId;
	float value;
	
	// Construtor padrão
	ItemOfPerson() : id(0), personId(0), itemId(0), value(0) {}

	// Construtor
	ItemOfPerson(int i, int p, int o, float v) : id(i), personId(p), itemId(o), value(v) {}
	
	void show() { // Função que exibe o item em tela
		printf("%d - %s: R$%.2f\n", id, getItemById(itemId), value);
	}
};

// Declaração do array de itens das residências. Chatgpt foi usado nessa declaração para gerar vários itens aleatoriamente e ter mais dados no relatório.
ItemOfPerson itemsOfPerson[500] = {
    ItemOfPerson(1, 1, 1, 52000),    // Carro
    ItemOfPerson(2, 1, 2, 2100),     // Geladeira
    ItemOfPerson(3, 1, 5, 2700),     // Televisão
    ItemOfPerson(4, 1, 3, 1000),     // Fogão
    ItemOfPerson(5, 1, 6, 7000),     // Computador
    ItemOfPerson(6, 1, 7, 4500),     // Video game
    ItemOfPerson(7, 1, 8, 8000),     // Celular
    ItemOfPerson(8, 1, 9, 4000),     // Cama
    ItemOfPerson(9, 2, 1, 54000),    // Carro
    ItemOfPerson(10, 2, 3, 800),     // Fogão
    ItemOfPerson(11, 2, 4, 1700),    // Máquina de lavar
    ItemOfPerson(12, 2, 5, 2500),    // Televisão
    ItemOfPerson(13, 2, 6, 7000),    // Computador
    ItemOfPerson(14, 2, 7, 4500),    // Video game
    ItemOfPerson(15, 2, 8, 8800),    // Celular
    ItemOfPerson(16, 2, 9, 3500),    // Cama
    ItemOfPerson(17, 3, 1, 53000),   // Carro
    ItemOfPerson(18, 3, 2, 2500),    // Geladeira
    ItemOfPerson(19, 3, 6, 7200),    // Computador
    ItemOfPerson(20, 3, 7, 4500),    // Video game
    ItemOfPerson(21, 3, 8, 8000),    // Celular
    ItemOfPerson(22, 3, 9, 4000),    // Cama
    ItemOfPerson(23, 3, 5, 2700),    // Televisão
    ItemOfPerson(24, 3, 3, 1000),    // Fogão
    ItemOfPerson(25, 4, 1, 61000),   // Carro
    ItemOfPerson(26, 4, 5, 3500),    // Televisão
    ItemOfPerson(27, 4, 7, 4200),    // Video game
    ItemOfPerson(28, 4, 8, 8800),    // Celular
    ItemOfPerson(29, 4, 9, 3500),    // Cama
    ItemOfPerson(30, 4, 2, 2100),    // Geladeira
    ItemOfPerson(31, 4, 4, 1700),    // Máquina de lavar
    ItemOfPerson(32, 4, 3, 800),     // Fogão
    ItemOfPerson(33, 5, 1, 62000),   // Carro
    ItemOfPerson(34, 5, 2, 2300),    // Geladeira
    ItemOfPerson(35, 5, 5, 3100),    // Televisão
    ItemOfPerson(36, 5, 4, 1950),    // Máquina de lavar
    ItemOfPerson(37, 5, 6, 7000),    // Computador
    ItemOfPerson(38, 5, 7, 4500),    // Video game
    ItemOfPerson(39, 5, 8, 8900),    // Celular
    ItemOfPerson(40, 5, 9, 4000),    // Cama
    ItemOfPerson(41, 6, 1, 54000),   // Carro
    ItemOfPerson(42, 6, 4, 1500),    // Máquina de lavar
    ItemOfPerson(43, 6, 6, 7000),    // Computador
    ItemOfPerson(44, 6, 7, 4500),    // Video game
    ItemOfPerson(45, 6, 8, 8800),    // Celular
    ItemOfPerson(46, 6, 9, 3500),    // Cama
    ItemOfPerson(47, 6, 5, 2700),    // Televisão
    ItemOfPerson(48, 6, 2, 2100),    // Geladeira
    ItemOfPerson(49, 7, 1, 58000),   // Carro
    ItemOfPerson(50, 7, 5, 3200),    // Televisão
    ItemOfPerson(51, 7, 7, 4200),    // Video game
    ItemOfPerson(52, 7, 8, 8000),    // Celular
    ItemOfPerson(53, 7, 9, 4000),    // Cama
    ItemOfPerson(54, 7, 6, 7000),    // Computador
    ItemOfPerson(55, 7, 4, 1700),    // Máquina de lavar
    ItemOfPerson(56, 7, 3, 800),     // Fogão
    ItemOfPerson(57, 8, 1, 65000),   // Carro
    ItemOfPerson(58, 8, 4, 1800),    // Máquina de lavar
    ItemOfPerson(59, 8, 5, 2700),    // Televisão
    ItemOfPerson(60, 8, 2, 2500),    // Geladeira
    ItemOfPerson(61, 8, 7, 4200),    // Video game
    ItemOfPerson(62, 8, 8, 8800),    // Celular
    ItemOfPerson(63, 8, 6, 7000),    // Computador
    ItemOfPerson(64, 8, 9, 3500),    // Cama
    ItemOfPerson(65, 9, 1, 70000),   // Carro
    ItemOfPerson(66, 9, 5, 3300),    // Televisão
    ItemOfPerson(67, 9, 8, 8800),    // Celular
    ItemOfPerson(68, 9, 6, 7000),    // Computador
    ItemOfPerson(69, 9, 7, 4500),    // Video game
    ItemOfPerson(70, 9, 4, 1700),    // Máquina de lavar
    ItemOfPerson(71, 9, 3, 800),     // Fogão
    ItemOfPerson(72, 9, 2, 2100),    // Geladeira
    ItemOfPerson(73, 10, 1, 62000),  // Carro
    ItemOfPerson(74, 10, 2, 2550),   // Geladeira
    ItemOfPerson(75, 10, 5, 3100),   // Televisão
    ItemOfPerson(76, 10, 4, 1600),   // Máquina de lavar
    ItemOfPerson(77, 10, 6, 7000),   // Computador
    ItemOfPerson(78, 10, 7, 4500),   // Video game
    ItemOfPerson(79, 10, 8, 8900),   // Celular
    ItemOfPerson(80, 10, 9, 4000),    // Cama
    ItemOfPerson(81, 11, 1, 63000),   // Carro
    ItemOfPerson(82, 11, 2, 2400),    // Geladeira
    ItemOfPerson(83, 11, 5, 2900),    // Televisão
    ItemOfPerson(84, 11, 6, 7000),    // Computador
    ItemOfPerson(85, 11, 7, 4500),    // Video game
    ItemOfPerson(86, 11, 8, 8800),    // Celular
    ItemOfPerson(87, 11, 9, 4000),    // Cama
    ItemOfPerson(88, 11, 4, 1800),    // Máquina de lavar
    ItemOfPerson(89, 12, 1, 67000),   // Carro
    ItemOfPerson(90, 12, 5, 3100),    // Televisão
    ItemOfPerson(91, 12, 8, 8900),    // Celular
    ItemOfPerson(92, 12, 6, 7000),    // Computador
    ItemOfPerson(93, 12, 7, 4200),    // Video game
    ItemOfPerson(94, 12, 2, 2100),    // Geladeira
    ItemOfPerson(95, 12, 4, 1600),    // Máquina de lavar
    ItemOfPerson(96, 12, 3, 1000),    // Fogão
    ItemOfPerson(97, 13, 1, 64000),   // Carro
    ItemOfPerson(98, 13, 5, 3000),    // Televisão
    ItemOfPerson(99, 13, 6, 7000),    // Computador
    ItemOfPerson(100, 13, 7, 4500),   // Video game
    ItemOfPerson(101, 13, 8, 8800),   // Celular
    ItemOfPerson(102, 13, 9, 3500),   // Cama
    ItemOfPerson(103, 13, 2, 2300),   // Geladeira
    ItemOfPerson(104, 13, 3, 800),    // Fogão
    ItemOfPerson(105, 14, 1, 69000),  // Carro
    ItemOfPerson(106, 14, 5, 3300),   // Televisão
    ItemOfPerson(107, 14, 8, 8900),   // Celular
    ItemOfPerson(108, 14, 6, 7200),   // Computador
    ItemOfPerson(109, 14, 7, 4500),   // Video game
    ItemOfPerson(110, 14, 4, 1700),   // Máquina de lavar
    ItemOfPerson(111, 14, 2, 2500),   // Geladeira
    ItemOfPerson(112, 14, 3, 1000),   // Fogão
    ItemOfPerson(113, 15, 1, 72000),  // Carro
    ItemOfPerson(114, 15, 2, 2600),   // Geladeira
    ItemOfPerson(115, 15, 5, 3100),   // Televisão
    ItemOfPerson(116, 15, 4, 1800),   // Máquina de lavar
    ItemOfPerson(117, 15, 6, 7000),   // Computador
    ItemOfPerson(118, 15, 7, 4200),   // Video game
    ItemOfPerson(119, 15, 8, 8800),   // Celular
    ItemOfPerson(120, 15, 9, 4000),   // Cama
    ItemOfPerson(121, 16, 1, 67000),  // Carro
    ItemOfPerson(122, 16, 2, 2300),   // Geladeira
    ItemOfPerson(123, 16, 5, 3100),   // Televisão
    ItemOfPerson(124, 16, 6, 7000),   // Computador
    ItemOfPerson(125, 16, 7, 4500),   // Video game
    ItemOfPerson(126, 16, 8, 8900),   // Celular
    ItemOfPerson(127, 16, 4, 1700),   // Máquina de lavar
    ItemOfPerson(128, 16, 3, 800),    // Fogão
    ItemOfPerson(129, 17, 1, 65000),  // Carro
    ItemOfPerson(130, 17, 5, 3200),   // Televisão
    ItemOfPerson(131, 17, 7, 4200),   // Video game
    ItemOfPerson(132, 17, 8, 8000),   // Celular
    ItemOfPerson(133, 17, 9, 4000),   // Cama
    ItemOfPerson(134, 17, 6, 7000),   // Computador
    ItemOfPerson(135, 17, 4, 1500),   // Máquina de lavar
    ItemOfPerson(136, 17, 3, 1000),   // Fogão
    ItemOfPerson(137, 18, 1, 70000),  // Carro
    ItemOfPerson(138, 18, 5, 3300),   // Televisão
    ItemOfPerson(139, 18, 8, 8800),   // Celular
    ItemOfPerson(140, 18, 6, 7000),   // Computador
    ItemOfPerson(141, 18, 7, 4500),   // Video game
    ItemOfPerson(142, 18, 2, 2100),   // Geladeira
    ItemOfPerson(143, 18, 4, 1700),   // Máquina de lavar
    ItemOfPerson(144, 18, 3, 800),    // Fogão
    ItemOfPerson(145, 19, 1, 68000),  // Carro
    ItemOfPerson(146, 19, 5, 3000),   // Televisão
    ItemOfPerson(147, 19, 6, 7200),   // Computador
    ItemOfPerson(148, 19, 7, 4500),   // Video game
    ItemOfPerson(149, 19, 8, 8900),   // Celular
    ItemOfPerson(150, 19, 2, 2500),   // Geladeira
    ItemOfPerson(151, 19, 4, 1600),   // Máquina de lavar
    ItemOfPerson(152, 19, 3, 1000),   // Fogão
    ItemOfPerson(153, 20, 1, 66000),  // Carro
    ItemOfPerson(154, 20, 5, 3100),   // Televisão
    ItemOfPerson(155, 20, 8, 8800),   // Celular
    ItemOfPerson(156, 20, 6, 7000),   // Computador
    ItemOfPerson(157, 20, 7, 4200),   // Video game
    ItemOfPerson(158, 20, 2, 2400),   // Geladeira
    ItemOfPerson(159, 20, 4, 1800),   // Máquina de lavar
    ItemOfPerson(160, 20, 3, 800),     // Fogão
    ItemOfPerson(161, 21, 1, 69000),  // Carro
    ItemOfPerson(162, 21, 5, 3300),   // Televisão
    ItemOfPerson(163, 21, 8, 8900),   // Celular
    ItemOfPerson(164, 21, 6, 7200),   // Computador
    ItemOfPerson(165, 21, 7, 4500),   // Video game
    ItemOfPerson(166, 21, 4, 1700),   // Máquina de lavar
    ItemOfPerson(167, 21, 2, 2500),   // Geladeira
    ItemOfPerson(168, 21, 3, 1000),   // Fogão
    ItemOfPerson(169, 21, 10, 1200),  // Guarda-roupa
    ItemOfPerson(170, 22, 1, 70000),  // Carro
    ItemOfPerson(171, 22, 5, 3400),   // Televisão
    ItemOfPerson(172, 22, 8, 8800),   // Celular
    ItemOfPerson(173, 22, 6, 7000),   // Computador
    ItemOfPerson(174, 22, 7, 4200),   // Video game
    ItemOfPerson(175, 22, 2, 2400),   // Geladeira
    ItemOfPerson(176, 22, 4, 1600),   // Máquina de lavar
    ItemOfPerson(177, 22, 3, 900),    // Fogão
    ItemOfPerson(178, 22, 10, 1500),  // Guarda-roupa
    ItemOfPerson(179, 23, 1, 68000),  // Carro
    ItemOfPerson(180, 23, 5, 3100),   // Televisão
    ItemOfPerson(181, 23, 8, 8700),   // Celular
    ItemOfPerson(182, 23, 6, 7200),   // Computador
    ItemOfPerson(183, 23, 7, 4400),   // Video game
    ItemOfPerson(184, 23, 4, 1800),   // Máquina de lavar
    ItemOfPerson(185, 23, 2, 2600),   // Geladeira
    ItemOfPerson(186, 23, 3, 1000),   // Fogão
    ItemOfPerson(187, 23, 10, 1300),  // Guarda-roupa
    ItemOfPerson(188, 24, 1, 71000),  // Carro
    ItemOfPerson(189, 24, 5, 3300),   // Televisão
    ItemOfPerson(190, 24, 8, 8800),   // Celular
    ItemOfPerson(191, 24, 6, 7000),   // Computador
    ItemOfPerson(192, 24, 7, 4600),   // Video game
    ItemOfPerson(193, 24, 2, 2300),   // Geladeira
    ItemOfPerson(194, 24, 4, 1700),   // Máquina de lavar
    ItemOfPerson(195, 24, 3, 900),    // Fogão
    ItemOfPerson(196, 24, 10, 1400),  // Guarda-roupa
    ItemOfPerson(197, 25, 1, 72000),  // Carro
    ItemOfPerson(198, 25, 5, 3200),   // Televisão
    ItemOfPerson(199, 25, 8, 8900),   // Celular
    ItemOfPerson(200, 25, 6, 7100),   // Computador
    ItemOfPerson(201, 25, 7, 4300),   // Video game
    ItemOfPerson(202, 25, 4, 1800),   // Máquina de lavar
    ItemOfPerson(203, 25, 2, 2400),   // Geladeira
    ItemOfPerson(204, 25, 3, 1000),   // Fogão
    ItemOfPerson(205, 25, 10, 1200),  // Guarda-roupa
    ItemOfPerson(206, 26, 1, 67000),  // Carro
    ItemOfPerson(207, 26, 5, 3100),   // Televisão
    ItemOfPerson(208, 26, 8, 8800),   // Celular
    ItemOfPerson(209, 26, 6, 7000),   // Computador
    ItemOfPerson(210, 26, 7, 4500),   // Video game
    ItemOfPerson(211, 26, 4, 1600),   // Máquina de lavar
    ItemOfPerson(212, 26, 2, 2500),   // Geladeira
    ItemOfPerson(213, 26, 3, 900),    // Fogão
    ItemOfPerson(214, 26, 10, 1300),  // Guarda-roupa
    ItemOfPerson(215, 27, 1, 68000),  // Carro
    ItemOfPerson(216, 27, 5, 3200),   // Televisão
    ItemOfPerson(217, 27, 8, 8700),   // Celular
    ItemOfPerson(218, 27, 6, 7200),   // Computador
    ItemOfPerson(219, 27, 7, 4400),   // Video game
    ItemOfPerson(220, 27, 4, 1700),   // Máquina de lavar
    ItemOfPerson(221, 27, 2, 2600),   // Geladeira
    ItemOfPerson(222, 27, 3, 1000),   // Fogão
    ItemOfPerson(223, 27, 10, 1400),  // Guarda-roupa
    ItemOfPerson(224, 28, 1, 71000),  // Carro
    ItemOfPerson(225, 28, 5, 3300),   // Televisão
    ItemOfPerson(226, 28, 8, 8800),   // Celular
    ItemOfPerson(227, 28, 6, 7000),   // Computador
    ItemOfPerson(228, 28, 7, 4600),   // Video game
    ItemOfPerson(229, 28, 2, 2300),   // Geladeira
    ItemOfPerson(230, 28, 4, 1800),   // Máquina de lavar
    ItemOfPerson(231, 28, 3, 900),    // Fogão
    ItemOfPerson(232, 28, 10, 1200),  // Guarda-roupa
    ItemOfPerson(233, 29, 1, 72000),  // Carro
    ItemOfPerson(234, 29, 5, 3200),   // Televisão
    ItemOfPerson(235, 29, 8, 8900),   // Celular
    ItemOfPerson(236, 29, 6, 7100),   // Computador
    ItemOfPerson(237, 29, 7, 4300),   // Video game
    ItemOfPerson(238, 29, 4, 1800),   // Máquina de lavar
    ItemOfPerson(239, 29, 2, 2400),   // Geladeira
    ItemOfPerson(240, 29, 3, 1000),   // Fogão
    ItemOfPerson(241, 29, 10, 1300),  // Guarda-roupa
    ItemOfPerson(242, 30, 1, 67000),  // Carro
    ItemOfPerson(243, 30, 5, 3100),   // Televisão
    ItemOfPerson(244, 30, 8, 8700),   // Celular
    ItemOfPerson(245, 30, 6, 7000),   // Computador
    ItemOfPerson(246, 30, 7, 4500),   // Video game
    ItemOfPerson(247, 30, 4, 1600),   // Máquina de lavar
    ItemOfPerson(248, 30, 2, 2500),   // Geladeira
    ItemOfPerson(249, 30, 3, 900),    // Fogão
    ItemOfPerson(250, 30, 10, 1400),   // Guarda-roupa
    ItemOfPerson(251, 1, 10, 1289),
    ItemOfPerson(252, 2, 10, 1734),
    ItemOfPerson(253, 3, 10, 1012),
    ItemOfPerson(254, 4, 10, 2156),
    ItemOfPerson(255, 5, 10, 1873),
    ItemOfPerson(256, 6, 10, 1423),
    ItemOfPerson(257, 7, 10, 1698),
    ItemOfPerson(258, 8, 10, 1325),
    ItemOfPerson(259, 9, 10, 1907),
    ItemOfPerson(260, 10, 10, 1546),
    ItemOfPerson(261, 11, 10, 1765),
    ItemOfPerson(262, 12, 10, 1987),
    ItemOfPerson(263, 13, 10, 1234),
    ItemOfPerson(264, 14, 10, 1345),
    ItemOfPerson(265, 15, 10, 1623),
    ItemOfPerson(266, 16, 10, 1456),
    ItemOfPerson(267, 17, 10, 1890),
    ItemOfPerson(268, 18, 10, 1776),
    ItemOfPerson(269, 19, 10, 1322),
    ItemOfPerson(270, 20, 10, 1678),
    ItemOfPerson(271, 21, 10, 1433),
    ItemOfPerson(272, 22, 10, 1555),
    ItemOfPerson(273, 23, 10, 1667),
    ItemOfPerson(274, 24, 10, 1989),
    ItemOfPerson(275, 25, 10, 1201),
    ItemOfPerson(276, 26, 10, 1349),
    ItemOfPerson(277, 27, 10, 1789),
    ItemOfPerson(278, 28, 10, 1567),
    ItemOfPerson(279, 29, 10, 1998),
    ItemOfPerson(280, 30, 10, 1444),
	ItemOfPerson(281, 1, 9, 2010),
    ItemOfPerson(282, 2, 9, 1850),
    ItemOfPerson(283, 3, 9, 1700),
    ItemOfPerson(284, 4, 9, 1945),
    ItemOfPerson(285, 5, 9, 2155),
    ItemOfPerson(286, 6, 9, 1820),
    ItemOfPerson(287, 7, 9, 2035),
    ItemOfPerson(288, 8, 9, 1988),
    ItemOfPerson(289, 9, 9, 1777),
    ItemOfPerson(290, 10, 9, 1923),
    ItemOfPerson(291, 11, 9, 2101),
    ItemOfPerson(292, 12, 9, 1888),
    ItemOfPerson(293, 13, 9, 2033),
    ItemOfPerson(294, 14, 9, 1956),
    ItemOfPerson(295, 15, 9, 1844),
    ItemOfPerson(296, 16, 9, 2067),
    ItemOfPerson(297, 17, 9, 1999),
    ItemOfPerson(298, 18, 9, 1789),
    ItemOfPerson(299, 19, 9, 2112),
    ItemOfPerson(300, 20, 9, 1876),
    ItemOfPerson(301, 21, 9, 2145),
    ItemOfPerson(302, 22, 9, 1911),
    ItemOfPerson(303, 23, 9, 2022),
    ItemOfPerson(304, 24, 9, 1800),
    ItemOfPerson(305, 25, 9, 1934),
    ItemOfPerson(306, 26, 9, 2090),
    ItemOfPerson(307, 27, 9, 1812),
    ItemOfPerson(308, 28, 9, 2077),
    ItemOfPerson(309, 29, 9, 1867),
    ItemOfPerson(310, 30, 9, 1980),
    ItemOfPerson(311, 1, 9, 2044),
    ItemOfPerson(312, 2, 9, 1901),
    ItemOfPerson(313, 3, 9, 1823),
    ItemOfPerson(314, 4, 9, 2123),
    ItemOfPerson(315, 5, 9, 1940),
    ItemOfPerson(316, 6, 9, 2075),
    ItemOfPerson(317, 7, 9, 1834),
    ItemOfPerson(318, 8, 9, 2001),
    ItemOfPerson(319, 9, 9, 1967),
    ItemOfPerson(320, 10, 9, 1881),
    ItemOfPerson(321, 1, 8, 7599.99),
    ItemOfPerson(322, 2, 8, 8399.50),
    ItemOfPerson(323, 3, 8, 6999.75),
    ItemOfPerson(324, 4, 8, 7899.00),
    ItemOfPerson(325, 5, 8, 6799.25),
    ItemOfPerson(326, 6, 8, 8999.50),
    ItemOfPerson(327, 7, 8, 4699.00),
    ItemOfPerson(328, 8, 8, 5499.99),
    ItemOfPerson(329, 9, 8, 7999.00),
    ItemOfPerson(330, 10, 8, 4399.50),
    ItemOfPerson(331, 11, 8, 5799.75),
    ItemOfPerson(332, 12, 8, 8699.00),
    ItemOfPerson(333, 13, 8, 6999.25),
    ItemOfPerson(334, 14, 8, 4899.50),
    ItemOfPerson(335, 15, 8, 7199.00),
    ItemOfPerson(336, 16, 8, 8899.99),
    ItemOfPerson(337, 17, 8, 6399.00),
    ItemOfPerson(338, 18, 8, 5299.50),
    ItemOfPerson(339, 19, 8, 4799.75),
    ItemOfPerson(340, 20, 8, 8199.00),
    ItemOfPerson(341, 21, 8, 5599.25),
    ItemOfPerson(342, 22, 8, 8299.50),
    ItemOfPerson(343, 23, 8, 4999.00),
    ItemOfPerson(344, 24, 8, 5899.99),
    ItemOfPerson(345, 25, 8, 6999.00),
    ItemOfPerson(346, 26, 8, 4699.50),
    ItemOfPerson(347, 27, 8, 5799.75),
    ItemOfPerson(348, 28, 8, 8699.00),
    ItemOfPerson(349, 29, 8, 6999.25),
    ItemOfPerson(350, 30, 8, 4899.50),
    ItemOfPerson(351, 1, 8, 7199.00),
    ItemOfPerson(352, 2, 8, 8899.99),
    ItemOfPerson(353, 3, 8, 6399.00),
    ItemOfPerson(354, 4, 8, 5299.50),
    ItemOfPerson(355, 5, 8, 4799.75),
    ItemOfPerson(356, 6, 8, 8199.00),
    ItemOfPerson(357, 7, 8, 5599.25),
    ItemOfPerson(358, 8, 8, 8299.50),
    ItemOfPerson(359, 9, 8, 4999.00),
    ItemOfPerson(360, 10, 8, 5899.99),
    ItemOfPerson(361, 1, 1, 180000.0),
    ItemOfPerson(362, 2, 1, 150000.0),
    ItemOfPerson(363, 3, 1, 120000.0),
    ItemOfPerson(364, 4, 1, 90000.0),
    ItemOfPerson(365, 5, 1, 170000.0),
    ItemOfPerson(366, 6, 1, 190000.0),
    ItemOfPerson(367, 7, 1, 130000.0),
    ItemOfPerson(368, 8, 1, 160000.0),
    ItemOfPerson(369, 9, 1, 140000.0),
    ItemOfPerson(370, 10, 1, 200000.0),
    ItemOfPerson(371, 11, 1, 100000.0),
    ItemOfPerson(372, 12, 1, 85000.0),
    ItemOfPerson(373, 13, 1, 175000.0),
    ItemOfPerson(374, 14, 1, 110000.0),
    ItemOfPerson(375, 15, 1, 195000.0)
};

int itemsOfPersonCount = 375;

ItemOfPerson createItemOfPerson(int personId){ // Função que cria um novo item numa residência
	int itemId = 0;
	float value;
	bool exit = false;
	
	do {
		system("cls");
		printf("Novo item nessa residência\n\n");
		if(isValid == false){
			printInvalidOption();
		}
		listItems();
		printf("\n0 - Voltar\n");
		printf("\nEscolha o item: ");
		scanf("%d", &itemId);
		
		if(itemId < 0 || itemId > 10){
			isValid = false;
		} else if(itemId == 0){
			exit = true;	
		} else {
			isValid = true;
		}
		
	} while (!isValid);
	
	if(!exit) {
		system("cls");
		printf("%s\n\n", getItemById(itemId));
		printf("Qual o valor aproximado do item? ");
		scanf("%f", &value);
		
		itemsOfPerson[itemsOfPersonCount] = ItemOfPerson(itemsOfPersonCount + 1, personId, itemId, value);	
	}
}

void listItemsOfPerson(int personId) { // Função que exibe em tela todos os itens de uma residência
	float total = 0;
	bool hasItems = false;
	
	for(int i = 0; i < itemsOfPersonCount; i++) {
		if(itemsOfPerson[i].personId == personId){
			hasItems = true;
			total = total + itemsOfPerson[i].value;
			itemsOfPerson[i].show();
		}
	}
	
	if(hasItems){
		printf("\nPrejuízo total: R$%.2f\n", total);
	} else {
		printf("Nenhum item cadastrado ainda!\n");
	}
	
	printf("\n");
}

float getTotalPrejudice() { // Função que retorna o valor total de prejuízo já cadastrado.
	float total = 0;
	
	for(int i = 0; i < itemsOfPersonCount; i++){
		total = total + itemsOfPerson[i].value;
	}
	
	return total;
}

float getTotalPrejudiceOfPerson(int personId) { // Função que retorna o total do prejuízo da residência pelo id informado.
	float total = 0;
	
	for(int i = 0; i < itemsOfPersonCount; i++) {
		if(itemsOfPerson[i].personId == personId){
			total = total + itemsOfPerson[i].value;
		}
	}
	
	return total;
}

void getHigherPrejudicePerson() { // Função que exibe a residência com maior prejuízo na tela.
	float higherPrejudice = 0;
	int personId;
	
	for(int j = 0; j < peopleCount; j++){
		int id = people[j].id;
		float prejudice = getTotalPrejudiceOfPerson(id);
		
		if (prejudice > higherPrejudice){
			higherPrejudice = prejudice;
			personId = id;
		}
	}
	
	printf("Residência mais afetada: %s (%d) - R$%.2f\n", getPersonById(personId), personId, higherPrejudice);
	return;
}

void printPrejudiceByItem() { // Função que exibe na tela todos os itens e o total de prejuízo de cada um deles.
	float totalPrejudice = getTotalPrejudice();
	
	for(int i = 0; i < 10; i++){
		float total = 0;
		int count = 0;
		
		for(int j = 0; j < itemsOfPersonCount; j++){
			if(itemsOfPerson[j].itemId == items[i].id) {
				total = total + itemsOfPerson[j].value;
				count++;
			}
		}
		
		printf("%d %s(s): R$%.2f (%.2f%%)\n", count, getItemById(items[i].id), total, total * 100 / totalPrejudice);
	}
	
	return;
}

void setItemsOfPerson(int personId) { // Função do menu de cadastro de uma residência. Aqui o usuário pode listar os itens ou cadastrar um novo.
	int select = 0;
	
	do {
		system("cls");
		printf("O que você deseja fazer agora %s?\n\n", getPersonById(personId));
		if(isValid == false) {
			printInvalidOption();
		}
		printf("1 - Ver itens cadastrados\n");
		printf("2 - Cadastrar novo item\n");
		printf("0 - Voltar\n");
		scanf("%d", &select);
		
		switch(select){
			case 1:
				system("cls");
				printf("Você tem estes itens cadastrados, %s:\n\n", getPersonById(personId));
				listItemsOfPerson(personId);
				isValid = true;
				system("pause");
				break;
			case 2:
				createItemOfPerson(personId);
				itemsOfPersonCount++;
				isValid = true;
				break;
			case 0:
				isValid = true;
				break;
			default:
				isValid = false;
				break;
		}	
		
	} while (select != 0);
	
	
}

void listPeople(bool showItems) { // Função que exibe na tela todas as residências cadastradas.
	for(int i = 0; i < peopleCount; i++){
		people[i].show();
		if(showItems){
			printf("\nItens: \n");
			listItemsOfPerson(people[i].id);	
		} else {
			printf("Prejuízo total: R$%.2f\n", getTotalPrejudiceOfPerson(people[i].id));
		}
		printf("\n");
	}
}

Person createPerson(int id) { // Função que junta as informações de uma residência e retorna elas para o cadastro de uma nova.
	char name[30];
	int nPeople = 0;
	
	system("cls");
	printf("Cadastrar nova residência\n\n");
	printf("Informe seu nome: ");
	fflush(stdin);
	gets(name);
	printf("Quantas pessoas moram nessa casa? ");
	scanf("%d", &nPeople);

	return Person(id, name, nPeople);
}

int main() {
    setlocale(LC_ALL, "");
    
    int select = 0;

	do {				
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
		
		int selectPerson = 0;
		
		switch(select) {
			case 1:
				
				do {
					system("cls");
					printf("Residências cadastradas\n\n");
					
					listPeople(false);
					
					printf("0 - Voltar\n\n");
					
					if(isValid == false) {
						printInvalidOption();
					}
					printf("Escolha	a residência para exibir os detalhes: ");
					scanf("%d", &selectPerson);
					
					if(selectPerson < 0 || selectPerson > peopleCount){
						isValid = false;
					} else if (selectPerson == 0) {
						isValid = true;
					} else {
						system("cls");
						printf("%s tem estes itens cadastrados:\n\n", getPersonById(selectPerson));
						listItemsOfPerson(selectPerson);
						system("pause");
						isValid = true;
					}		
				} while(selectPerson != 0);
			
				isValid = true;
				break;
			case 2:
				people[peopleCount] = createPerson(peopleCount+1);
				peopleCount++;			
				setItemsOfPerson(people[peopleCount - 1].id);
				isValid = true;				
				break;
			case 3:
				system("cls");
				printf("Relatórios\n\n");
				
				printf("Prejuízo total: R$%.2f\n\n", getTotalPrejudice());
				
				printf("Residências\n\n");
				printf("Total de residências afetadas: %d\n", peopleCount);
				printf("Total de pessoas afetadas: %d\n", getTotalPeople());
				printf("Média de pessoas por residência: %.0f\n\n", static_cast< float >(getTotalPeople()) / peopleCount);
				printf("Prejuízo médio por residência: R$%.2f\n", getTotalPrejudice() / peopleCount);
				printf("Prejuízo médio por pessoa: R$%.2f\n", getTotalPrejudice() / getTotalPeople());
				getHigherPrejudicePerson();
				
				printf("\nItens\n\n");
				printPrejudiceByItem();
				
				printf("\nConsiderações\n\n");
				printf("Dados da Pesquisa Nacional por Amostra de Domicílios (PNAD) Contínua, divulgados em 19 de abril de 2024 pelo IBGE apontam que o Rio Grande do Sul teve uma renda domiciliar per capita de R$2225,00 em 2023.\n");
				printf("Considerando essa renda para todas as pessoas afetadas cadastradas nesse software (%d), estima-se que esse prejuízo será recuperado em %.0f meses.\n", getTotalPeople(), getTotalPrejudice() / getTotalPeople() / 2225.0);
				printf("Lembrando que esse prejuízo refere-se somente a alguns bens materiais, desconsiderando residências irrecuperáveis, toda a indústria e infraestrutura afetada e ainda mais importante, as vidas perdidas na tragédia.\n");
				
				printf("\n");
				system("pause");
				isValid = true;
				break;
			case 0:
				isValid = true;
				break;
			default:
				isValid = false;
				break;
		}
	
	} while (select != 0);	
	
	system("cls");
	printf("Obrigado por usar o nosso sistema!\n");

    return 0;
} 
