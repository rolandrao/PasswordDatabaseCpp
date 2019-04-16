#include<iostream>
#include<iomanip>
#include<string.h>
#include<fstream>
#include<vector>
#include"/Users/rolandrao/Documents/PasswordDatabaseCpp/Header Files/Password.h"
#include"/Users/rolandrao/Documents/PasswordDatabaseCpp/Header Files/User.cpp"
using namespace std;
string credFile = "/Users/rolandrao/Documents/PasswordDatabaseCpp/Documents/credentials.txt";
string passfile;
int initial;
string delimiter = "|";
vector<User> users;
int currentUser;
void loadCreds();
bool login();
void addPassword();
void lookUp();
void edit();
void logout();
void loadPasswords();
void save();

int main(){
  loadCreds();
  bool loginSuccess = false;

  loginSuccess = login();

  if(loginSuccess){
    int choice;
    while(true){
      cout << "--------------------" << endl;
      cout << "|\t1 - Add Password\t|" << endl;
      cout << "|\t2 - Look Up Password\t|" << endl;
      cout << "|\t3 - Save\t" << endl;
      cout << "|\t4 - Edit Password\t" << endl;
      cout << "|\t5 - Logout\t" << endl;
      cout << "--------------------" << endl;
      cin >> choice;
      switch(choice){
        case 1:
          addPassword();
          break;
        case 2:
          lookUp();
          break;
        case 3:
          save();
          break;
        case 4:
          edit();
          break;
        case 5:
          logout();
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

void addPassword(){
  string u,p,w;
  cout << "Enter the website: ";
  cin >> w;
  cout << "Enter the username: ";
  cin >> u;
  cout << "Enter the password: ";
  cin >> p;

  users.at(currentUser).addPassword(u,p,w);
}

void loadCreds(){
  //int choice;
  ifstream input(credFile);
  string line,user,pass;
  cout << "Loading Credentials" << endl;

  while(getline(input,line)){
    user = line.substr(0,line.find(delimiter));
    pass = line.substr(line.find(delimiter)+1);
    cout << "User: " << user << "\t" << "Pass: " << pass << endl;
    User u(user,pass);
    users.push_back(u);
  }


}

bool login(){
  string u,p;
  cout << "Enter master username: ";
  cin >> u;
  cout << "Enter master password: ";
  cin >> p;
  for(int i = 0; i < users.size(); i++){
    if(users.at(i).getPassword() == p && users.at(i).getUsername() == u){
      currentUser = i;
      passfile = "/Users/rolandrao/Documents/PasswordDatabaseCpp/Documents/" + users.at(i).getUsername() + ".txt";
      cout << "boutta load stuff";
      loadPasswords();
      return true;
    }
  }
  return false;
}

void loadPasswords(){
  cout << "loading stuff";
  cout << passfile;
  ifstream in;
  int counter = 1;
  string line,user,pass,web;
  in.open(passfile);
  while(getline(in,line)){
    cout << "loading password number:" << counter;
    counter++;
    int start,end;
    end = line.find(delimiter);
    web = line.substr(0,end);
    start = end+1;
    end = line.find(delimiter,start);
    user = line.substr(start,end);
    start = end+1;
    pass = line.substr(start);

    cout << web << " " << user << " " << pass << endl;
    users.at(currentUser).addPassword(web,user,pass);
  }
  initial = counter;
}

void lookUp(){
  users.at(currentUser).listPasswords();

}

void save(){
  //cout << "Saving the DAY";
  //SAVING CREDENTIALS
  int counter = 0;
  ofstream writer;
  writer.open(credFile, ofstream::trunc);
  while(counter < users.at(currentUser).getSize()){
    writer << users.at(currentUser).getPassword(counter).getUser() << endl;
    counter++;
  }

  writer.close();

  //SAVING PASSWORDS
  ofstream pwriter;
  pwriter.open(passfile, ofstream::trunc);
  cout << users.at(currentUser).getSize();
  counter = 0;
  while(counter < users.at(currentUser).getSize()){
    pwriter << users.at(currentUser).getPassword(counter).getUser() << endl;
    counter++;
  }


  //for(int i = initial; i < users.at(currentUser).getSize()-1; i++){
    //pwriter << users.at(currentUser).getPassword(i).getWeb() << "|" << users.at(currentUser).getPassword(i).getUser() << "|" << users.at(currentUser).getPassword(i).getPass() << endl;
  //}

  pwriter.close();
}

void edit(){

}

void logout(){

}
