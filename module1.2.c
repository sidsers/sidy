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


void addPolynomial(Polynomial* poly1, Polynomial* poly2) {
    Term* term2 = poly2->head;
    while (term2 != NULL) {
        int exp2 = term2->exponent;
        int coeff2 = term2->coefficient;

        Term* term1 = poly1->head;
        int found = 0;

        while (term1 != NULL) {
            if (term1->exponent == exp2) {
                term1->coefficient += coeff2;
                found = 1;
                break;
            }
            term1 = term1->next;
        }

        if (!found) {
            
            addTerm(poly1, coeff2, exp2);
        }

        term2 = term2->next;
    }
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
    Polynomial* poly1 = createPolynomial();
    Polynomial* poly2 = createPolynomial();

    
    addTerm(poly1, 3, 2);
    addTerm(poly1, 5, 1);
    addTerm(poly1, 7, 0);

    
    int numTerms2;
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &numTerms2);

    for (int i = 0; i < numTerms2; i++) {
        int coeff2, exp2;
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff2, &exp2);
        addTerm(poly2, coeff2, exp2);
    }

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

   // printf("Polynomial 2: ");
    displayPolynomial(poly2);

    
    addPolynomial(poly1, poly2);

   // printf("Addition Result: ");
    displayPolynomial(poly1);


    free(poly1);
    free(poly2);

    return 0;
}
