#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> 
#include <ctime>
#include <iomanip>
#include "Book.h"
using namespace std;

#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory{
private: 
    vector<BooK>* inventory;

public:
    Inventory(){
        inventory = new vector<BooK>;
    }

    void addBook(string name, string author, string ISBN, double price, int quantity){
        int ID = productID();
        BooK* newBook = new BooK(name, author, ISBN, price, quantity, ID);
        inventory->push_back(*newBook);
    }

    int productID(){
       srand(time(0));

       while(true){
         int randomNum = 1000 + rand() % 9001;
            if(!SearchID(randomNum)){
            return randomNum;
            }
       }
    }

    bool SearchID(int newId){
        for(int i =0; i< inventory->size(); i++){
            if(newId == inventory->at(i).getID()){
                return true;
            }
        }
        return false;
    }

    int SearchBook(string info){
        for(int i =0; i< inventory->size();i++){
            if(info == inventory->at(i).getTitle() || info == inventory->at(i).getISBN()){
                return i;
            } 
        }
        
        return -1;
    }

    void displayBookInfo(string info){
        int index = SearchBook(info);

        if(index != -1){
            cout << "Name:       " << inventory->at(index).getTitle() << endl;
            cout << "ISBN:       " << inventory->at(index).getISBN() << endl;
            cout << "Price:      " << inventory->at(index).getPrice() << endl;
            cout << "Quantity:   " << inventory->at(index).getQuantity() << endl;
            cout << "Product ID: " << inventory->at(index).getID() << endl;
        } else {
            cout << "Book does not exists." << endl;
        }
    }

    void displayInventory(){
        int maxPriceWidth = 8;
        cout << left << setw(22) << "|Name" << setw(16) << "|ISBN" << setw(11) << "|Price" << setw(8) << "|Quantity|" << setw(8) << "PID" << "|" << endl;

        for(int i =0; i< inventory->size();i++){
            string title = inventory->at(i).getTitle().substr(0,20);
            cout << "|" << left << setw(20) << title << " | " << inventory->at(i).getISBN() << " | " << setw(maxPriceWidth) << fixed << setprecision(2) << inventory->at(i).getPrice() << " | " << setw(6) << inventory->at(i).getQuantity() << " | " << setw(7) << inventory->at(i).getID() << "|"<< endl;        }
    }

    void deleteBook(int id){
        for(int i =0; i<inventory->size();){
                if(inventory->at(i).getID() == id){
                    inventory->erase(inventory->begin()+i);
                } else{
                    i++;
                }
        }
    }

    void changeQuantity(int id, int newQuan){
        for(int i =0; i< inventory->size();i++){
            if(inventory->at(i).getID() == id){
                inventory->at(i).setQuantity(newQuan);
                break;
            } else {
                cout << "Book does not on file." << endl;
                break;
            }
        }
    }

    int checkQuantity(string name){
        for(int i = 0; i< inventory->size();i++){
            if(name == inventory->at(i).getISBN() || name == inventory->at(i).getTitle()){
                return inventory->at(i).getQuantity();
            }
        }
        return 0;
    }

    void decreateQ(string name, int quantity){
        for(int i = 0; i< inventory->size();i++){
            if(name == inventory->at(i).getISBN() || name == inventory->at(i).getTitle()){
                inventory->at(i).setQuantity(inventory->at(i).getQuantity() - quantity);
            }
        }
    }

   double getPrice(string name){
    double price = 0;
    for(int i = 0; i< inventory->size();i++){
            if(name == inventory->at(i).getISBN() || name == inventory->at(i).getTitle()){
                price = inventory->at(i).getPrice();
                return price;
            }
        }
        return price;
   }
};

#endif
