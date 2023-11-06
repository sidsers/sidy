#include <stdio.h>
#include <stdlib.h>


typedef struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
} Term;

typedef struct Polynomial {
    Term* head;
} Polynomial;


Term* createTerm(int coefficient, int exponent) {
    Term* newTerm = (Term*)malloc(sizeof(Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}


Polynomial* createPolynomial() {
    Polynomial* poly = (Polynomial*)malloc(sizeof(Polynomial));
    poly->head = NULL;
    return poly;
}


void addTerm(Polynomial* poly, int coefficient, int exponent) {
    Term* newTerm = createTerm(coefficient, exponent);
    if (poly->head == NULL) {
        poly->head = newTerm;
    } else {
        Term* current = poly->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTerm;
    }
}


Polynomial* simplifyPolynomial(Polynomial* poly) {
    Polynomial* result = createPolynomial();
    Term* current = poly->head;

    while (current != NULL) {
        int coeff = current->coefficient;
        int exp = current->exponent;
        int combinedCoeff = coeff;

        
        Term* runner = current->next;
        while (runner != NULL) {
            if (runner->exponent == exp) {
                combinedCoeff += runner->coefficient;
            }
            runner = runner->next;
        }

        
        if (combinedCoeff != 0) {
            addTerm(result, combinedCoeff, exp);
        }

        current = current->next;
    }

    return result;
}


void displayPolynomial(Polynomial* poly) {
    Term* current = poly->head;
    if (current == NULL) {
        printf("0\n");
        return;
    }

    while (current != NULL) {
        if (current->coefficient != 0) {
            printf("%d", current->coefficient);
            if (current->exponent != 0) {
                printf("x^%d", current->exponent);
            }
            if (current->next != NULL && current->next->coefficient > 0) {
                printf(" + ");
            } else if (current->next != NULL && current->next->coefficient < 0) {
                printf(" - ");
            }
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    Polynomial* poly = createPolynomial();

    
    addTerm(poly, 3, 2);
    addTerm(poly, 5, 1);
    addTerm(poly, -2, 2);
    addTerm(poly, 7, 0);
    addTerm(poly, 2, 1);

    printf("Original Polynomial: ");
    displayPolynomial(poly);

    
    Polynomial* simplifiedPoly = simplifyPolynomial(poly);

    printf("Simplified Polynomial: ");
    displayPolynomial(simplifiedPoly);

    
    free(poly);
    free(simplifiedPoly);

    return 0;
}
