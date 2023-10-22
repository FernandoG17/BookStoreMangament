#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include "User.h"
#include "UserList.h"
#include "Inventory.h"
using namespace std; 

UL *userList = new UL;
Inventory inventory;

int createUser = 0;
string userName = "";
string password = "";
string password2 = "";
string email = "";
string postCode = "";
string address = "";
string phoneN = ""; 
string name = "";
int amount = 0;
string purchase;

void Populate(){
    //string Name, int phoneN, string address, string postCode, string email, string Pass, string UserName
    userList->InsertNewUser("Fernando Gonzalez", 23687700, "7227 Condor Street", "V5A 188", "test@gmail.com", "test@1", "Fernando17");
    userList->InsertNewUser("Ana Lopez", 60477675, "8950 Hamilton Avenue", "V5A 1A0", "test2@gmail.com", "test@2", "Ana5");
    userList->InsertNewUser("Jessie Morgan", 709094534, "3200 Eleonor Street", "V5A 1T0", "test3@gmail.com", "test@3", "Jessie70");
}

void PopulateB(){

    inventory.addBook("To Kill a Mockingbird", "Harper Lee", "9780061120084", 12.99, 15);
    inventory.addBook("1984", "George Orwell", "9780451524935", 9.99, 30);
    inventory.addBook("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565", 11.50, 13);
    inventory.addBook("The Catcher in the Rye", "J.D. Salinger", "9780316769488", 10.25, 15);
    inventory.addBook("Pride and Prejudice", "Jane Austen", "9780141439518", 8.99, 25);
    inventory.addBook("To the Lighthouse", "Virginia Woolf", "9780156907392", 14.75, 20);
    inventory.addBook("The Hobbit", "J.R.R. Tolkien", "9780345339683", 15.99, 15);
    inventory.addBook("Harry Potter and the Sorcerer's Stone", "J.K. Rowling", "9780590353427", 16.50, 42);
    inventory.addBook("The Hunger Games", "Suzanne Collins", "9780439023481", 9.75, 10);
    inventory.addBook("The Da Vinci Code", "Dan Brown", "9780307474278", 13.25, 34);
    inventory.addBook("The Alchemist", "Paulo Coelho", "9780061122415", 12.99, 15);
    inventory.addBook("Brave New World", "Aldous Huxley", "9780060850524", 10.99, 30);
    inventory.addBook("Gone with the Wind", "Margaret Mitchell", "9781416548898", 14.99, 26);
    inventory.addBook("The Road", "Cormac McCarthy", "9780307265432", 11.75, 20);
    inventory.addBook("The Lord of the Rings", " J.R.R. Tolkien", "9780618640157", 18.50, 15);

}

void LookForBook(){
    string LookFor;
    cout << "Plese enter the name of the book or the SIN number: "; 
    cin.ignore();
    getline(cin,LookFor);
    if(inventory.SearchBook(LookFor)>0){
       inventory.displayBookInfo(LookFor);
    } else {
        cout << "Book does not exists." << endl;
    }
}

bool checkCard(string &card){
    int sum = 0;
    bool doubleDigit = false;

    for (int i = card.length() - 1; i >= 0; i--) {
        int digit = card[i] - '0';

        if (doubleDigit) {
            digit *= 2;
            if (digit > 9) {
                digit -= 9;
            }
        }

        sum += digit;
        doubleDigit = !doubleDigit;
    }

    return (sum % 10 == 0);
}

int generateRandomNumber(int min, int max) {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(nullptr)));

    // Generate a random number in the specified range
    int randomNum = rand() % (max - min + 1) + min;
    
    return randomNum;
}

void SuccesfulCheck(){
    int minRange = 1;
    int maxRange = 10000;
    int randomNumber = generateRandomNumber(minRange, maxRange);
    cout << "Checkout has been successful!" << endl;
    userList->getUserInfo(userName);
    cout << "Order number: " << randomNumber << endl;

}

void checkOut(){
    string cardNumber; 
    int expireDate; 
    int securityCode; 

    while(true){
        cout << "Total is: " << (double)(inventory.getPrice(purchase) * amount) << endl;
        cout << "Enter credit card: "; 
        cin.ignore();
        getline(cin, cardNumber);
        if(!checkCard(cardNumber)){
            cout << "Please try again." << endl;
        }
        cout << "Enter expiry date (MMYYYY): "; 
        cin >> expireDate;
        cout << "Enter 3 digit security code: ";
        cin >> securityCode;
        if(checkCard(cardNumber)){
            SuccesfulCheck();
            break;
        }
    }
}

void PurchaseBook(){
    cout << "What book would you like to purchase? Enter SIN or name: ";
    cin.ignore();
    getline(cin, purchase);

    while(true){
        if(inventory.SearchBook(purchase)>0){
        cout << "There are " << inventory.checkQuantity(purchase) << " in stock." << endl;
        cout << "Price: $" << inventory.getPrice(purchase) << endl;
        cout << "Enter the amount you want to purchase: "; 
        cin >> amount;
        if(inventory.checkQuantity(purchase)> 0 || inventory.checkQuantity(purchase) >=amount){
            checkOut();
            inventory.decreateQ(purchase, amount);
            break;
        } else{
            cout << "Book is out of stock or you're trying to purchase more than there are available." << endl;
        }
    }
    }
}


void Options(){
    int option;
    while(true){
        cout << "1. Look for a book." << endl;
        cout << "2. Purchase a book." << endl; 
        cout << "3. Exit" << endl;
        cin >> option;

        switch(option){
            case 1: LookForBook();
                    break;
            case 2: PurchaseBook();
                    break;
            case 3: return;

            default: cout << "Option does not exists." << endl;

        }
    }
}
void Log(){
    while(true){
        cout << "Enter username: ";
        getline(cin, userName);

        cout << "Enter password: ";
        getline(cin, password);

        bool userExists = userList->LookForUser(userName);
        bool correctPassword = userExists && userList->LookForPassword(password);

        if (correctPassword) {
            cout << "Welcome!" << endl;
            Options();
            break;
        } else if (userExists) {
            cout << "Wrong password. Try again." << endl;
        } else {
            cout << "User does not exist." << endl;
        }
    }
}

void CreateUser(){
    int nU;
    while(true){
    cout << "Enter name: "; 
    cin.ignore();
    getline(cin, name);
    cout << "Enter an username: ";
    getline(cin, userName);
    cout << "Enter a password: ";
    getline(cin, password);
    cout << "Re enter the password: ";
    getline(cin, password2);
    cout << "Enter your email: ";
    getline(cin, email);
    cout << "Enter your address: "; 
    getline(cin, address);
    cout << "Enter your postal code: ";
    getline(cin, postCode);
    cout << "Enter phone number: ";
    getline(cin, phoneN);

    bool existName = userList->LookForUser(userName);
    bool existEmail = userList->LookEmail(email);

    if(existName){
        cout << "Username is already taken." << endl;
        cout << "Press 1 to login or 0 to try again" << endl;
        cin >> nU;
        if(nU == 1){
            Log();
            break;
        } 
    } else if(existEmail){
        cout << "Account already exists with that email account." << endl;
    } else if (password != password2){
        cout << "Passwords do not match" << endl;
    } else {
        cout << "Account created" << endl;
        break;
    }
    }
}

void Menu(){
    
    cout << "1. Create a user. " << endl; 
    cout << "2. Login" << endl;
    cin >> createUser;
    cin.ignore();

    switch(createUser){
        case 1: CreateUser();
                break;
        case 2: Log();
                break;
        }
}


 
int main(){
    PopulateB();
    Populate();
    Menu();

    return 0;
}
