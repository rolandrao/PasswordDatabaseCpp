#pragma once
#include<iostream>
#include<string.h>
#include<bitset>
#include<stdio.h>
#include<stdlib.h>
#include"/Users/rolandrao/Documents/PasswordDatabaseCpp/Header Files/functions.h"
using namespace std;

class Password {
private:
  string password, username, website,epassword,eusername,ewebsite;
  char user[33], pass[33], web[33];

  //char encrypted[33];

public:
  Password(string u, string p, string w) : username(u), password(p), website(w)
  {
    epassword = "";
    eusername = "";
    ewebsite = "";
    stringToCString(username,user,username.length(),&eusername);
    stringToCString(password,pass,password.length(), &epassword);
    stringToCString(website,web,website.length(), &ewebsite);

    //encrypted = encrypt(password,&encrypted);
  }

  void print(){
    cout << "Username: " << username << endl;
    cout << "Password: " << password << endl;
    cout << "Website: " << website << endl;
    cout << "\n\n";
    //cout << "Username decimal: " << user;
    cout << "Username encrypted: " << eusername << endl;


  }




  ~Password(){

  }

  string getEncrypted(){
    return encrypted;
  }

  string getUser(){
    return username;
  }

  string getPass(){
    return password;
  }

  string getWeb(){
    return website;
  }
};
