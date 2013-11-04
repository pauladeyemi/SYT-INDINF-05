//
//  adressbuch.c
//  Adressbuch
//
//  Created by Paul Adeyemi on 16.10.13.
//  Copyright (c) 2013 Paul Adeyemi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char* vorname;
    char* nachname;
} PERSON;
typedef struct
{
    char adresse[256];
} ADRESSE;
typedef struct
{
    PERSON person;
    ADRESSE Adresse;
    
} ADRESSBUCH;

void setName(char*,char*);
void setAdresse(char*);

int main(int argc, const char * argv[])
{
    
}

void setName(char* firstname,char* lastname){
    PERSON pers;
    pers.vorname=firstname;
    pers.nachname=lastname;
}