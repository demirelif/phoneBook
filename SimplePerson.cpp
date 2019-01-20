//
//  SimplePerson.cpp
//  Hw-3
//
//  Created by Elif Demir on 15.12.2018.
//  Copyright © 2018 Elif Demir. All rights reserved.
//
#include "SimplePerson.h"
#include <iostream>
using namespace std; 

Person :: Person( const string name ){
    this -> name = name;
}

Person :: ~Person() {
}

Person :: Person( const Person &personToCopy ){
    name = personToCopy.name;
}

void Person :: operator=( const Person &right ){
    if ( this != &right ){
        if ( right.name != "" )
            name = right.name;
    }
}
string Person :: getName() {
    return name;
}
