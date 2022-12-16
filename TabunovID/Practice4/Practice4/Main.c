
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

float getCheck(int reg[], float price[], float discount[], int products[][10]);

int main() {
	int arr[100];
	int counter = 0;
	int get_check = 0;
	float grand_total = 0;
	const char products[][10] = {"potatoes","rice","buckwheat","chicken", "fish", "pork", "salad", "juice", "water","tea"};
	int code[10] = { 0000, 1010, 1111, 1212, 1313, 1414, 1515, 1616, 1717, 1818 };
	float price[10] = { 50.00, 60.00, 70.00, 150.00, 200.00, 250.00, 150.00, 100.00, 50.00, 250.00 };
	float discount[10] = { 0.05, 0.10, 0.20, 0.40, 0.10, 0.05, 0.05, 0.15, 0.30, 0.40 };
	int reg[10] = { 0,0,0,0,0,0,0,0,0,0 };

	while (get_check == 0) {
		int tmp = 0, barcode = 0;
		printf("enter product code\n");

		for (int i = 0; i <= 3; i++) {
			scanf_s("%d", &tmp);
			barcode += tmp;
			if (barcode < 999) {
				barcode *= 10;
			}
		}

		arr[counter] = barcode;
		counter++;

		printf("want a check? 1/0\n");
		printf("1 - yes, 0 - no\n");
		scanf_s("%d", &get_check);
	}

	for (int i = 0; i <= counter; i++) {
		for (int j = 0; j < 10; j++) {
			if (code[j] == arr[i]) {
				reg[j] += 1;
			}
		}
	}

	printf("your check:\n");

	grand_total = getCheck(reg, price, discount, products);

	printf("************************\n");
	printf(" grand total: %f\n", grand_total);
	return 0;
}

float getCheck(int reg[], float price[], float discount[], int products[][10]) {
	float grand_total=0;
	for (int i = 0; i < 10; i++) {
		if (reg[i] > 0) {
			printf("************************\n");

			float discount_price = price[i] * (1 - discount[i]);
			grand_total = (grand_total + discount_price)*reg[i];
			printf("product: %s \n", products[i]);
			printf("price: %f \n", price[i]);
			printf("discount: %f \n", discount[i]);
			printf("discount price: %f \n", discount_price);
			printf("number : %d \n", reg[i]);
		}
	}
	return grand_total;
}




/*#include<stdio.h>
#define LENGTH (sizeof(price)/sizeof(price[0]))
float price[] = { 50.00, 60.00, 70.00, 150.00, 200.00, 250.00, 150.00, 100.00, 50.00, 250.00};
const char* products[] = { "potatoes","rice","buckwheat","chicken", "fish", "pork", "salad", "juice", "water","tea" };
const char* barcodes[] = { 0000, 1010, 1111, 1212, 1313, 1414, 1515, 1616, 1717, 1818 };
float skidka[] = { 4.50, 7.00, 5.00, 6.55, 21.35, 12.50, 5.00, 13.90, 42.10, 51.30 };
const char* infos[] = { "Country of origin: Russia","Country of origin: Russia\nFat content of milk - 3,2%","Country of origin: Russia\nCategory of eggs - C0","Country of origin: Russia\nGreen apples","Country of origin: Russia\nMountain honey", "Country of origin: Russia\nOlive oil","Country of origin: Russia\nRye bread","Country of origin: Russia\nBleak tea","Country of origin: Russia\nCheese smoked sausage","Country of origin: Russia\nCheese with blue mold" };
int count[LENGTH] = { 0 };

void intro() {
	printf("Scan your barcodes below\n");
	printf("Enter \"print\" when you are done\n");
}

void description(int num) {
	printf("%s, price: %.2f, discount: %.2f\n", products[num], price[num], skidka[num]);
	printf("%s\n", infos[num]);
}
void line() {
	for (int i = 0; i < 50; i++) {
		printf("-");
	}
	printf("\n");
}
void scan() {
	static int tmp = 0;
	char* entered[6];
	int counts[LENGTH] = { 0 };
	printf("Enter barcode\n");
	gets(entered);
	if (strcmp(entered, "print")) {
		for (int i = 0; i < LENGTH; i++) {
			if (strcmp(barcodes[i], entered) == 0) {
				description(i);
				count[i] += 1;
				tmp = 1;
			}
		}
		if (tmp == 0)
			printf("Couldn't find this barcode, please try again\n");
		scan();
	}
}

void print_check() {
	float cost = 0.0;
	printf("Your check:\n");
	line();
	for (int i = 0; i < LENGTH; i++) {
		if (count[i] != 0) {
			printf("%s, price with discount - %.2f, %d\n", products[i], price[i] - skidka[i], count[i]);
			line();
			cost += (price[i] - skidka[i]) * count[i];
		}
	}
	printf("Price - %.2f\n", cost);
}

int main() {
	intro();
	scan();
	print_check();
	return 0;
}*/
