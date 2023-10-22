#include <iostream>
#include "UserList.h"
using namespace std;

UL *newList = new UL;

void Populate(){
    //string Name, int phoneN, string address, string postCode, string email, string Pass, string UserName
    newList->InsertNewUser("Fernando Gonzalez", 23687700, "7227 Condor Street", "V5A 188", "test@gmail.com", "test@1", "Fernando@Test.com");
    newList->InsertNewUser("Ana Lopez", 60477675, "8950 Hamilton Avenue", "V5A 1A0", "test2@gmail.com", "test@2", "Ana@Test.com");
    newList->InsertNewUser("Jessie Morgan", 709094534, "3200 Eleonor Street", "V5A 1T0", "test3@gmail.com", "test@3", "Jessie@Test.com");
}

int main(){
    Populate();
    newList->displayUsers();

}