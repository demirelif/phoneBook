//
//  main.cpp
//  Hw-3
//
//  Created by Elif Demir on 15.12.2018.
//  Copyright © 2018 Elif Demir. All rights reserved.
//

#include <iostream>
#include "SimplePerson.h"
#include "SimplePhoneBook.h"


int main(int argc, const char * argv[]) {
    PhoneBook book;
    book.addPerson("ayse");
    book.addPerson("AySe");
    book.addPerson("yusuf");
    book.addPerson("elif");
    book.removePerson("yusuf");
    book.displayPeople();
}

