//  Taschenrechner
//  taschenrechhner.c
//
//  Die Klasse liest eine Rechenoperation ein (+,-,*,/) und gibt das Ergebnis aus.
//  Created by Nikolaus Schrack on 2/11/13.
//
//

#include <stdio.h>
#include <stdlib.h>

/*Prototyp*/
int addition(int,int);
int subtraktion(int,int);
int division(int,int);
int multiplikation(int,int);
int (*fp[4])(int,int);

int main(int argc, const char * argv[])
{
    char op;
    int a ,b ,opn ,result;
    
    fp[0] = addition;
    fp[1] = subtraktion;
    fp[2] = division;
    fp[3] = multiplikation;
    
    printf("Gib die gewünschte Rechenoperation ein\n"
           "zb:'3+4'\n");
    do{
        scanf("%d %c %d",&a,&op,&b);
    }while(op!='+'&op!='-'&op!='*'&op!='/');
    
    switch (op) {
        case '+':opn = 0;break;
        case '-':opn = 1;break;
        case '/':opn = 2;break;
        case '*':opn = 3;break;
    }
    
    result = (*fp[opn])(a,b);
    printf("Das Ergebnis ist %d",result);
    
     return EXIT_SUCCESS;
}


/********************************************
 *                                          *
 * Die Funktion addiert.                    *
 * Parameter1   : int n 1. Nummer           *
 * Parameter2   : int m 2. Nummer           *
 * Rückgabewert : int Ergebnis der Addition *
 *                                          *
 *******************************************/
int addition(int n,int m){
    return n+m;
}

/************************************************
 *                                              *
 * Die Funktion subtrahiert.                    *
 * Parameter1   : int n 1. Nummer               *
 * Parameter2   : int m 2. Nummer               *
 * Rückgabewert : int Ergebnis der Subtraktion  *
 *                                              *
 ***********************************************/
int subtraktion(int n,int m){
    return n-m;
}

/********************************************
 *                                          *
 * Die Funktion dividiert.                  *
 * Parameter1   : int n 1. Nummer           *
 * Parameter2   : int m 2. Nummer           *
 * Rückgabewert : int Ergebnis der Division *
 *                                          *
 *******************************************/
int division(int n,int m){
    return n/m;
}

/**************************************************
 *                                                *
 * Die Funktion multipliziert.                    *
 * Parameter1   : int n 1. Nummer                 *
 * Parameter2   : int m 2. Nummer                 *
 * Rückgabewert : int Ergebnis der Multiplikation *
 *                                                *
 *************************************************/
int multiplikation(int n,int m){
    return n*m;
}