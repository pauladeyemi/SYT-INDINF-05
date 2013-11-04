//
//  adressbuch.c
//  Adressbuch
//
//  Created by Paul Adeyemi on 16.10.13.
//  Copyright (c) 2013 Paul Adeyemi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX 2

typedef struct
{
    char *adresse;
} ADRESSE;

typedef struct
{
    char *vorname;
    char *nachname;
    ADRESSE add;
} PERSON;

PERSON pers[MAX];
int counter=0;

void setPerson(char*,char*,char*);

int main(int argc, const char * argv[])
{
    char vorname[50];
    char nachname[50];
    char addresse[50];

    while(counter<MAX){
        scanf("%s",&(*vorname));
        scanf("%s",&(*nachname));
        scanf("%s",&(*addresse));
        setPerson(vorname,nachname,addresse);
        
    }
    printf("%s",pers[counter-1].vorname);
    
    
}

void setPerson(char *firstname,char *lastname,char *adresse){
    ADRESSE adr;
    adr.adresse=adresse;
    pers[counter].vorname=firstname;
    pers[counter].nachname=lastname;
    pers[counter].add=adr;
    counter++;
}