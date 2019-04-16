#pragma once
#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;
void CStringToBinaryString(string*,char*,int);
string charToBinaryString(char);


void encrypt(string in, char *ptr, int size, string *s){ // takes in string to encrypt, address of cstring, size of cstring, address to put encrypted string
  strcpy(ptr,in.c_str());
  CStringToBinaryString(s,ptr,size); // takes in location of encyrpted string var, the converted cstring
}

void CStringToBinaryString(string *s, char *ptr, int size){
  for(int i = 0; i < size; i++){
    *s = *s + charToBinaryString(*ptr) + "|";
    ptr++;
  }
}
string charToBinaryString(char c){
  int convertFromCopy, digit, convertTo = 2;
  unsigned int convertFrom = (int) c;
  string stringDigit, answer;


  convertFromCopy = convertFrom;

  while (convertFrom != 0){
      digit = convertFrom % convertTo;

      if (digit < 10)
          stringDigit = '0' + digit;
      else
          stringDigit = digit - 10 + 'A';

      answer = stringDigit + answer;

      convertFrom /= convertTo;
  }


  return answer;
}
