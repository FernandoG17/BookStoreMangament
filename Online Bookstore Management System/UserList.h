#include <iostream>
#include "User.h"
using namespace std;

#ifndef USERLIST_H
#define USERLIST_H

class UL{
private: 
    User **userList;
    int tableSize;
    int numberOfKeys;
    double loadFactorThreshold;

public: 
    
    UL(){
       tableSize = 10;
       numberOfKeys = 0;
       userList = new User*[tableSize];
       for(int i=0; i< tableSize; i++){
            userList[i] = nullptr;
       } 
       loadFactorThreshold = 0.75;
    }

    ~UL(){
        delete userList;
    }

    void Rehash(){
        int newSize = tableSize * 2;
        User **tempTable = new User*[newSize];
        for(int i =0; i<tableSize;i++){
            if(userList[i] !=nullptr){

                tempTable[i]->setName(userList[i]->getName());
                tempTable[i]->setAdress(userList[i]->getAddress());
                tempTable[i]->setPhoneN(userList[i]->getPhoneN());
                tempTable[i]->setEmail(userList[i]->getEmail());
                tempTable[i]->setPostCode(userList[i]->getPosCode());
                tempTable[i]->setPassword(userList[i]->getPassword());
                tempTable[i]->setUserName(userList[i]->getUserName());
            }
        }
        delete userList;
        userList = tempTable;
        tableSize = newSize;
    }

    void InsertNewUser(string Name, int phoneN, string address, string postCode, string email, string Pass, string UserName){
        double loadFactor = static_cast<double>(numberOfKeys) / tableSize;
        if (loadFactor > loadFactorThreshold) {
            Rehash();
        }

        User* user = new User(Name, phoneN, address, postCode, email, Pass, UserName);
        if(userList[1] == nullptr){
            userList[1] = user;
            numberOfKeys++;
        } else {
            LinearProbing(user);
            numberOfKeys++;
        }
        
    }

    void displayUsers(){
        for(int i = 0; i< tableSize;i ++){
            if(userList[i]!= nullptr){
            cout << "Name:      " << userList[i]->getName() << endl;
            cout << "Username:  " << userList[i]->getUserName() << endl;
            cout << "Email:     " << userList[i]->getEmail() << endl;
            cout << "Phone Num: " << userList[i]->getPhoneN() << endl;
            cout << "Address:   " << userList[i]->getAddress() << endl;
            cout << "---------------------------------------" << endl;
            }
            
        }
    }

    void LinearProbing(User *user){
        int probing = 2% tableSize;

        while(probing!= 1){
            if(userList[probing] == 0){
                userList[probing] = user;
                return;
            }
            probing = (probing + 1 ) % tableSize;
        }
    }

    bool LookForUser(string username){
        for(int i = 0; i< tableSize; i++){
            if(userList[i] !=nullptr && username == userList[i]->getUserName()){
                return true; //If username already exist in the system
            }
        }
        return false;
    }

    bool LookForPassword(string password){
        for(int i = 0 ; i<tableSize; i++){
            if(userList[i] !=nullptr && password == userList[i]->getPassword()){
                return true;
            }
        }
        return false;
    }

    bool LookEmail(string email){
        for(int i = 0; i< tableSize; i++){
            if(userList[i] != nullptr && email == userList[i]->getEmail()){
                return true;
            }
        }
        return false;
    }

     void getUserInfo(string username){
        for(int i = 0; i<tableSize; i++){
            if(userList[i] != nullptr && username == userList[i]->getUserName()){
                cout << "Name:             " << userList[i]->getName() << endl;
                cout << "E-mail:           " << userList[i]->getEmail() << endl;
                cout << "Phone Number:     " << userList[i]->getPhoneN() << endl;
                cout << "Address/Postal C: " << userList[i]->getAddress() << " " << userList[i]->getPosCode() << endl;
            }
        }
     }
};

#endif