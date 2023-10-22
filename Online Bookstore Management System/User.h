#include<iostream>

using namespace std;

#ifndef USER_H
#define USER_H

class User{
private: 
    string name;
    int phoneN;
    string address; 
    string postCode; 
    string email;
    string password;
    string userName;

public: 
    User(string Name, int phoneN, string address, string postCode, string email, string Pass, string UserName){
        name = Name;
        this->phoneN = phoneN;
        this->address = address;
        this->postCode = postCode;
        this->email = email;
        password = Pass;
        userName = UserName;
    }


    string getName(){
        return name;
    }

    int getPhoneN(){
        return phoneN;
    }

    string getAddress(){
        return address;
    }

    string getPosCode(){
        return postCode;
    }

    string getEmail(){
        return email;
    }

    string getPassword(){
        return password;
    }

    string getUserName(){
        return userName;
    }

    void setName(string Name){
        name = Name;
    }

    void setPhoneN(int Number){
        phoneN = Number;
    }

    void setAdress(string Address){
        address = Address;
    }

    void setPostCode(string postC){
        postCode = postC;
    }

    void setEmail(string Email){
        email = Email;
    }

    void setPassword(string Password){
        password = Password;
    }

    void setUserName(string UserName){
        userName = UserName;
    }

    void SaveToDataBase(const User& user){

    }
};

#endif