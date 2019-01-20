//
//  SimplePhoneBook.cpp
//  Hw-3
//
//  Created by Elif Demir on 15.12.2018.
//  Copyright © 2018 Elif Demir. All rights reserved.
//
#include <stdio.h>
#include <cstddef>
#include <algorithm>
#include "SimplePhoneBook.h"
#include <iostream>
using namespace std;

PhoneBook :: PhoneBook(){
    head = NULL;
    numberOfPeople = 0;
    
}

PhoneBook :: ~PhoneBook(){
    while ( numberOfPeople > 0){
        PersonNode *cur = head;
        head = cur -> next;
        delete cur;
        numberOfPeople--;
    }
}

PhoneBook :: PhoneBook( const PhoneBook &phoneBookToCopy ) {
    numberOfPeople = phoneBookToCopy.numberOfPeople;
    if ( phoneBookToCopy.head == NULL ){
        head = NULL;
    }
    
    else {
        // copy first
        head = new PersonNode;
        head -> t = phoneBookToCopy.head-> t;
        
        // copy rest
        PersonNode *cur = head;
        for ( PersonNode* origPtr = phoneBookToCopy.head -> next; origPtr!=NULL; origPtr = origPtr -> next){
            cur -> next = new PersonNode;
            cur = cur -> next;
            cur -> t = origPtr -> t;
        }
        cur -> next = NULL;
    }
}

void PhoneBook::operator=( const PhoneBook &right ){
    if ( &right != this ){
        PersonNode *cur = head;
        if ( numberOfPeople == right.numberOfPeople ){
            for ( PersonNode *rightCur = right.head; rightCur != NULL; rightCur = rightCur -> next){
                cur -> t = rightCur -> t;
                rightCur = rightCur -> next;
            }
        }
        
        if ( numberOfPeople > right.numberOfPeople ){
            for ( PersonNode *rightCur = right.head; rightCur != NULL; rightCur = rightCur -> next){
                cur -> t = rightCur -> t;
                rightCur = rightCur -> next;
            }
            while ( cur != NULL ){
                PersonNode *del = cur -> next;
                cur = del -> next;
                del = NULL;
                delete del;
            }
        }
        
        if ( numberOfPeople < right.numberOfPeople ){
            PersonNode *rightCur = right.head;
            for ( cur = head; (cur -> next) != NULL; cur = cur -> next){
                
                cur -> t = rightCur -> t;
                rightCur = rightCur -> next;
            }
            for ( int i = numberOfPeople; i < right.numberOfPeople; i++ ){
                cur -> next = new PersonNode;
                cur = cur -> next;
                cur -> t = rightCur -> t;
                rightCur = rightCur -> next;
                
            }
            cur = NULL; 
            rightCur = NULL;
            delete rightCur;
        }
        numberOfPeople = right.numberOfPeople;
        cur = NULL;
        delete cur;
    }
}

bool PhoneBook:: addPerson( const string name ){ // pointer
    if ( findPerson(name) == NULL ){
        PersonNode *newPerson = new PersonNode;
        newPerson -> t = Person(name);
        // increase size
        numberOfPeople++;
        
        if ( head == NULL ){
            newPerson -> next = head;
            head = newPerson;
        }
        else {
            PersonNode *cur = head;
            while ( cur -> next != NULL ){
                cur = cur -> next;
            }
            cur -> next = newPerson;
            newPerson -> next = NULL;
            cur = NULL; 
        }
        newPerson = NULL;

        return true;
    }
    return false;
}


bool PhoneBook:: removePerson(const string name){
    if ( findPerson( name ) == NULL ) {
        return false;
    }
    PersonNode *cur = head;
    if (cur == findPerson( name ) ){
        head = cur -> next;
        delete cur;
    }
    else {
        while ( ( cur -> next ) != findPerson(name) ){
            cur = cur -> next;
        }
        PersonNode *deleted = cur -> next;
        cur -> next = deleted ->next;
        deleted -> next = NULL;
        delete deleted;
        deleted = NULL;
    }
    numberOfPeople--;
    cur = NULL;
    return true;
}

void PhoneBook:: displayPeople(){
    if ( numberOfPeople == 0 ){
        cout << "--EMPTY--" << endl;
    }
    else {
        PersonNode *cur = head;
        for ( int i = 0; i < numberOfPeople; i++ ){
            cout << (cur -> t).getName() << endl;
            cur = cur ->next;
        }
        cur = NULL;
        delete cur;
    }
}

PhoneBook::PersonNode *PhoneBook:: findPerson(string name){
    string findStr = name;
    transform(findStr.begin(), findStr.end(), findStr.begin(),::tolower);
    PersonNode *cur = head;
    if ( cur == NULL ){
        return NULL;
    }
    
    for ( int i = 0; i < numberOfPeople; i++ ){
        string myStr = ( cur -> t).getName();
        transform(myStr.begin(), myStr.end(), myStr.begin(),::tolower);
        if ( myStr == findStr ) {
            return cur;
        }
        cur = cur -> next;
    }
    return NULL;
}

