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
  User(string u,string p) : username(u), password(p)
  {

  }
  vector getPasswords(){
    return passwords;
  }
  bool confirm(string user, string pass){
    return (user == username && pass == password);
  }
  void addPassword(string u, string p, string w){
    passwords.push_back(new Password(u,p,w));
  }
  void listPasswords(){
    for(int i = 0; i < passwords.size(); i++){
      cout << "Index\tUsername\tWebsite" << endl;
      cout << i+1 << "\t" passwords.at(i).getUser << "\t" << passwords.at(i).getWeb << endl;
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
  ]
  void writeCreds(fstream writer){
    encrypt(credUsername,user,credUsername.length(),&euser);
    encrypt(credPassword,pass,credPassword.length(),&epass);
    writer << euser << "@" << epass << endl;
  }
}
