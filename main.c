/*
 * main.c
 *
 *  Created on: Jun 15, 2015
 *      Author: dchiu
 */
#include <stdio.h>
#include <string.h>
#include "defs.h"
#include "stats.h"
#include "menu.h"

/**
 * @brief Main function
 *
 * @param argc Ignore
 * @param argv Igno
 * @return int
 */

int charCount = 0;
int vows = 0;
int cons = 0;
int main(int argc, char *argv[]) {
	char str[MAX_INPUT_LEN];
	char tempstr[MAX_INPUT_LEN];
	// declare and initialize the histogram
	

	// TODO: start by getting strings from users until # is input
	printf("Enter strings (# to stop): \n");
	while(tempstr[0] != '#'){
		fgets(tempstr, MAX_INPUT_LEN, stdin);
		strcat(str,tempstr);
		vows = vows + vfreq(tempstr);
		cons = cons + cfreq(tempstr);
		charCount = vows + cons;
	}
	
	
	

	// TODO: after # is input, print menu options
	
	int opt = getMenuOption();
	while (opt != 4){
		while(opt <0 || opt >5){
			printf("Error: Unknown option %d.\n", opt);
			opt = getMenuOption();
		}
		if(opt == 1){
			float vowPer = ((float)vows/charCount)*100;
			float conPer = ((float)cons/charCount)*100;

		printf("\nVowels: %d (%.2f%%), Consonants: %d (%.2f%%), Total: %d\n\n", vows, vowPer, cons, conPer, charCount);
		}
		if(opt == 2){
			histogram(str);
		}
		if(opt == 3){
			printf("Enter strings (# to stop): \n");
			tempstr[0] = 's';
			while(tempstr[0] != '#'){
				fgets(tempstr, MAX_INPUT_LEN, stdin);
				strcat(str,tempstr);
				vows = vows + vfreq(tempstr);
				cons = cons + cfreq(tempstr);
				charCount = vows + cons;
			}
		}
		opt = getMenuOption();
	}
	
	printf("Exiting...\n");
	return 0;
}
