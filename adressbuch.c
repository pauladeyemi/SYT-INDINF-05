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
    char adresse[101];
} ADRESSE;

typedef struct
{
    char vorname[50];
    char nachname[50];
    ADRESSE add;
} PERSON;

int size=0;

void addPerson(PERSON*);
void deletePerson(PERSON*);
void showPersons(PERSON*);

int main(int argc, const char * argv[])
{
    
    int check=0;
    char c;
    
    PERSON *pers=(PERSON*)malloc(size*sizeof(PERSON));
    
    
    do {
    
        printf("Auswahl:\n(a)Neue Person Hinzufügen\n(d)Person löschen\n(s)Alle Personen anzeigen\n(e)Beenden\n");
        scanf("%s",&c);
        fflush(stdin);
    
        switch (c) {
            case 'a':
                pers= (PERSON*)realloc(pers, (size+1)*sizeof(PERSON));
                addPerson(pers);
                break;
            case 'd':
                deletePerson(pers);
                break;
            case 's':
                showPersons(pers);
                break;
            case 'e':
                check=1;
                break;
            default:
                printf("Falsche Eingabe\n");
                break;
        }
    } while (check==0);

    free(pers);
    
}

void addPerson(PERSON *p){
    printf("Addresse: ");
    scanf("%s",p[size].add.adresse);
    printf("Vorname: ");
    scanf("%s",p[size].vorname);
    printf("Nachname: ");
    scanf("%s",p[size].nachname);
    
    size++;
}
void deletePerson(PERSON* p){
    int e;
    int i;
    printf("Index und Personen:\n");
    for (i=0; i<size; i++) {
        printf("%d : %s, %s, %s \n",i,p[i].vorname,p[i].nachname,p[i].add.adresse);
    }
    
    printf("Wievielten Eintrag Löschen?\nNr: ");
    scanf("%d",&e);
    fflush(stdin);
    while (e<size-1)
        p[e] = p[++e];
    size--;
    
}
void showPersons(PERSON *p){
    int i;
    if(size==0){
        printf("Addressbuch ist leer.\n");
    }else{
        for (i=0; i<size; i++) {
            printf("Vorname: %s, Nachname: %s, Addresse: %s \n",p[i].vorname,p[i].nachname,p[i].add.adresse);
        }
    }
}





