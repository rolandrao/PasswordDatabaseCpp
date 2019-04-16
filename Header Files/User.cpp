#pragma once
#include<string.h>
#include<vector>
#include"/Users/rolandrao/Documents/PasswordDatabaseCpp/Header Files/Password.h"
using namespace std;

class User{
private:
  string credUsername, credPassword,euser,epass;
  vector<Password> passwords;
  char user[33], pass[33];
public:
  User(string u,string p) : credUsername(u), credPassword(p)
  {

  }
  User(){

  }
  string getUsername(){
    return credUsername;
  }
  string getPassword(){
    return credPassword;
  }
  Password getPasswords(int i){
    return passwords.at(i);
  }
  bool confirmUnique(string user){
    return user == credUsername;
  }
  bool confirm(string user, string pass){
    return (user == credUsername && pass == credPassword);
  }
  void addPassword(string u, string p, string w){
    Password temp(u,p,w);
    passwords.push_back(temp);
  }
  int getSize(){
    return passwords.size();
  }
  void listPasswords(){
    cout << "Index\tUsername\tWebsite" << endl;
    for(int i = 0; i < passwords.size(); i++){
      cout << i+1 << "\t" << passwords.at(i).getUser() << "\t" << passwords.at(i).getWeb() << endl;
    }
  }
  Password getPassword(int index){
    return passwords.at(index-1);
  }
  void printPassword(int index){
    cout << "Username: " << passwords.at(index).getUser() << endl;
    cout << "Password: " << passwords.at(index).getPass() << endl;
    cout << "Website: " << passwords.at(index).getWeb() << endl;
  }

  void writeCreds(fstream writer){
    encrypt(credUsername,user,credUsername.length(),&euser);
    encrypt(credPassword,pass,credPassword.length(),&epass);
    writer << euser << "@" << epass << endl;
  }
};
