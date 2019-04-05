#include<iostream>
#include<iomanip>
#include<string.h>
#include<fstream>
#include<vector>
#include"/Users/rolandrao/Documents/PasswordDatabaseCpp/Header Files/Password.h"
//#include<
using namespace std;
string credFile = "/Users/rolandrao/Documents/PasswordDatabaseCpp/Documents/credentials.txt";
string delimiter = "|";
vector<User> users;
User currentUser;
void loadCreds();
bool login();
void addPassword();
void lookUp();
void save();

int main(){
  loadCreds();
  bool loginSuccess = false;

  //loginSuccess = login();

  if(loginSuccess){
    int choice;
    while(true){
      cout << "--------------------" << endl;
      cout << "|\t1 - Add Password\t|" << endl;
      cout << "|\t2 - Look Up Password\t|";
      cout << "|\t3 - Save";
      cout << "--------------------";
      cin >> choice;
      switch(choice){
        case 1:
          //addPassword();
          break;
        case 2:
          //lookUp();
          break;
        case 3:
          //save();
          break;
      }
    }
  }





  /*
  string u,pa,w;
  cout << "Enter the username: ";
  cin >> u;
  cout << "Enter the password: ";
  cin >> pa;
  cout << "Enter the website: ";
  cin >> w;
  Password p(u,pa,w);
  p.print();

  */
}

void loadCreds(){
  ifstream input(credFile);
  string line;
  while(!input.eof){
    input >> line;
    string user = line.substr(0,line.find(delimiter)), pass = line.substr(line.find(delimiter)+1,line.length()-line.find(delimiter));
    users.push_back(new User(user,pass));
  }

}

bool login(){
  string u, p;
  cout << "Enter Master Username: ";
  cin >> u;
  cout << "Enter Master Password: ";
  cin >> p;
  for(int i = 0; i < users.size(); i++){
    if(users.at(i).confirm(u,p)){
      currentUser = users.at(i);
      return true;
    }
  }
  return false;

}

void lookUp(){
  int index;
  for(int i = 0; i < currentUser.size(); i++){
    currentUser.listPasswords();
  }
  cout << "Enter the index of the password you would like to view: ";
  cin >> index;
  currentUser.printPassword(index);
}

void save(){
  ofstream writer;
  writer.open(credFile, trunc);
  for(int i = 0; i < sizeof(creds); i++){
    creds[i].write();
  }
}
