#include <iostream>
#include <string>
using namespace std; 

#ifndef BOOK_H
#define BOOK_H

class BooK{
private: 
    string title;
    string author; 
    string isbn;
    double price;
    int quantity;
    int productId;

public: 
    BooK(){
        title = "";
        author = "";
        isbn = "";
        price = 0.0;
        quantity = 0;
    }

    BooK(string Title, string Author, string ISBN, double Price, int Quantity, int id){
        title = Title;
        author = Author;
        isbn = ISBN;
        price = Price;
        quantity = Quantity;
        productId = id;
    }

    string getTitle() const{
        return title;
    }

    string getAuthor()const{
        return author;
    }

    string getISBN() const {
        return isbn;
    }

    double getPrice() const {
        return price;
    }

    int getQuantity() const{
        return quantity;
    } 

    int getID() const {
        return productId;
    }

    void setTitle(const string &Title){
        title = Title;
    }

    void setAuthor(const string &Author){
        author = Author;
    }

    void setISBN(const string &ISBN){
        isbn = ISBN;
    }

    void setPrice(const double &Price){
        price = Price;
    }

    void setQuantity(const int &Quantity){
        quantity = Quantity;
    }

    void setID(const int &ID){
        productId = ID;
    }



};

#endif