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
    char adresse[101];
} ADRESSE;

typedef struct
{
    char vorname[50];
    char nachname[50];
    ADRESSE add;
} PERSON;

//Globale Variablen
int size=0;

//Prototypen
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
                //Reservierten Speicher erhöhen
                pers= (PERSON*)realloc(pers, (size+1)*sizeof(PERSON));
                addPerson(pers);
                break;
            case 'd':
                deletePerson(pers);
                //Reservierten Speicher reduzieren
                pers= (PERSON*)realloc(pers, (size)*sizeof(PERSON));
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
        fflush(stdin);
    } while (check==0);
    
    //Reservierten speicher Freigeben
    free(pers);
    
}
/**
 * Funktion: addPerson
 * Fragt User nach Addresse,Vor- und Zuname einer neuen Person
 *
 * Parameter:
 * *p: Pointer in den eine neue Person hinzugefügt werden soll.
 */
void addPerson(PERSON *p){
    printf("Addresse: ");
    scanf("%s",p[size].add.adresse);
    printf("Vorname: ");
    scanf("%s",p[size].vorname);
    printf("Nachname: ");
    scanf("%s",p[size].nachname);
    
    size++;
}
/**
 * Funktion: deletePerson
 * Fragt User welcher Eintrag gelöscht werden soll
 *
 * Parameter:
 * *p: Pointer aus dem eine Person gelöscht werden soll
 */
void deletePerson(PERSON* p){
    int e;
    int i;
    
    //Zeigt alle Person und ihren index an
    printf("Index und Personen:\n");
    for (i=0; i<size; i++) {
        printf("%d : %s %s, %s \n",i,p[i].vorname,p[i].nachname,p[i].add.adresse);
    }
    
    printf("Wievielten Eintrag Löschen?\nNr: ");
    scanf("%d",&e);
    fflush(stdin);
    while (e<size-1)
        p[e] = p[++e];
    size--;
    
}
/**
 * Funktion: showPerson
 * Zeigt alle Personen an
 *
 * Parameter:
 * *p: Auszugebender Pointer
 */
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





