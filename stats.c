/*
 * histo.c
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "defs.h"
#include "stats.h"

int hist[ALPHABET_SIZE] = {0};

// TODO: function definitions for dealing with histogram below
int vfreq(char c[]){
   int len = strlen(c);
   char temp[MAX_INPUT_LEN];
   int vowCount = 0;
   
   for(int i=0; i<=len; i++){
    temp[i] = tolower(c[i]);
    if(temp[i]=='a' || temp[i]=='e'|| temp[i]=='i'||temp[i]=='o'||temp[i]=='u' && isalpha(temp[i])){
      vowCount++;
    }
   }
   return vowCount;
    
}

int cfreq(char c[]){
   
   int len = strlen(c);
   char temp[MAX_INPUT_LEN];
   int conCount = 0;
   
   for(int i=0; i<=len; i++){
    temp[i] = tolower(c[i]);
    if(temp[i]!='a' && temp[i]!='e' && temp[i]!='i' && temp[i] !='o' && temp[i] != 'u' && isalpha(temp[i])){
      conCount++;
    }
   }
   return conCount;
    
}

void histogram (char c[]){
  int index = 0;

  int len = strlen(c);
  for(int i=0; i<=len; i++){
    if(isalpha(c[i])){
      index = (int)tolower(c[i]) - 97;
      hist[index] = hist[index] + 1;
    }
  }

  printf("\n");

  int max = 0;
  for(int i=0; i<ALPHABET_SIZE; i++){
    if(hist[i]>hist[max]){
      max = i;
    }
  }

  for(int i=max; i>0; i--){
    for(int j=0; j<ALPHABET_SIZE; j++){
      if(hist[j] >= i){
        printf("* ");
      }
      else{
        printf("  ");
      }
    }
    printf("\n");
  }

  for (int i=0; i<ALPHABET_SIZE; i++) {
    printf("%c ", 'a' + i);
  }
  printf("\n");
  for(int i=0; i<ALPHABET_SIZE; i++){
    printf("%d ", hist[i]);
  }
  printf("\n");
}
  

