#include <stdio.h>
#include "HugeUnsignedIntOperator.h"

#define HUGE_NUMBER_SUPERIOR 1
#define HUGE_NUMBER_EQUAL 2
#define HUGE_NUMBER_INFERIOR 3

static unsigned int compareHugeUnsignedInts (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2);

HugeUnsignedInt* addHugeUnsignedInt (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2) {
    return NULL;
}

HugeInt* substractHugeUnsignedInt (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2) {
    return NULL;
}

HugeUnsignedInt* multiplyHugeUnsignedInt (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2) {
    return NULL;
}

HugeUnsignedInt* divideHugeUnsignedInt (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2) {
    if ((operand1 == NULL) || (operand2 == NULL)) {
        return NULL;
    }
    HugeUnsignedInt* result = createHugeUnsignedIntFromString ("0");
    if (result == NULL) {
        return NULL;
    }
    unsigned int operand1Length = getHugeUnsignedIntLength (operand1);
    unsigned int operand2Length = getHugeUnsignedIntLength (operand2);
    unsigned int place = operand2Length;
    HugeInt* remainder = createHugeInt ();
    remainder->absoluteValue = createHugeUnsignedIntFromHugeUnsignedInt (operand1, operand2Length);
    while (place <= operand1Length) {
        HugeInt* keepForDelete;
        HugeUnsignedInt* quotient;
        HugeUnsignedInt* multiplyResult;
        quotient = createHugeUnsignedIntFromString ("1");
        multiplyResult = multiplyHugeUnsignedInt (quotient, operand2);
        unsigned int compareResult = compareHugeUnsignedInts (remainder->absoluteValue, multiplyResult);
        while (compareResult == HUGE_NUMBER_SUPERIOR) {
            deleteHugeUnsignedInt (multiplyResult);
            incrementHugeUnsignedInt (quotient);
            multiplyResult = multiplyHugeUnsignedInt (quotient, operand2);
            compareResult = compareHugeUnsignedInts (remainder->absoluteValue, multiplyResult);
        }
        keepForDelete = remainder;
        if (compareResult == HUGE_NUMBER_INFERIOR) {
            decrementHugeUnsignedInt (quotient);
            deleteHugeUnsignedInt (multiplyResult);
            multiplyResult = multiplyHugeUnsignedInt (quotient, operand2);
        }
        addDigitAtEnd (result, quotient->start->digit);
        remainder = substractHugeUnsignedInt (remainder->absoluteValue, multiplyResult);

        deleteHugeUnsignedInt (multiplyResult);
        deleteHugeInt (keepForDelete);
        deleteHugeUnsignedInt (quotient);
        if (place < operand1Length) {
            addDigitAtEnd (remainder->absoluteValue, getDigitByPlaceFromStart (operand1, place));
            simplifyHugeInt (remainder);
        }
        place++;
    }
    simplifyHugeUnsignedInt (result);
    return result;
}


unsigned int compareHugeUnsignedInts (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2) {
    return 0;
}

unsigned int isHugeUnsignedIntStrictlySuperior (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2) {
    return 0;
}

unsigned int isHugeUnsignedIntSuperior (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2) {
    return 0;
}

unsigned int isHugeUnsignedIntEqual (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2) {
    return 0;
}

unsigned int isHugeUnsignedIntInferior (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2) {
    return 0;
}

unsigned int isHugeUnsignedIntStrictlyInferior (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2) {
    return 0;
}

HugeUnsignedInt* createHugeUnsignedIntFromPowerOf10 (const HugeUnsignedInt* exponent) {
    return NULL;
}

void incrementHugeUnsignedInt (HugeUnsignedInt* hugeUnsignedInt) {
}

void decrementHugeUnsignedInt (HugeUnsignedInt* hugeUnsignedInt) {
}
