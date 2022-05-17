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
    HugeInt* result = createHugeInt ();

    if (result != NULL) {
        Node* node1;
        Node* node2;
        Digit carry = 0;

        if (isHugeUnsignedIntSuperior (operand1, operand2)) {
            node1 = operand1->end;
            node2 = operand2->end;
            result->sign = PLUS;
        } else {
            node1 = operand2->end;
            node2 = operand1->end;
            result->sign = MINUS;
        }

        while (!isNodeEmpty (node1) || !isNodeEmpty (node2)) {
            Digit digitResult;
            Digit digitNode1 = isNodeEmpty (node1) ? 0 : node1->digit;
            Digit digitNode2 = isNodeEmpty (node2) ? 0 : node2->digit;
            if (((digitNode1 == 0) && (carry > 0)) || ((digitNode1 - carry) < digitNode2)) {
                digitNode1 += 10 - carry;
                carry = 1;
            } else {
                digitNode1 -= carry;
                carry = 0;
            }
            digitResult = (digitNode1 - digitNode2) % 10;
            addDigitAtStart (result->absoluteValue, digitResult);
            if (!isNodeEmpty (node1)) {
                node1 = node1->previous;
            }
            if (!isNodeEmpty (node2)) {
                node2 = node2->previous;
            }
        }
    }
    simplifyHugeInt (result);
    return result;
}

HugeUnsignedInt* multiplyHugeUnsignedInt (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2) {
    if ((operand1 == NULL) || (operand2 == NULL)) {
        return NULL;
    }
    HugeUnsignedInt* result = createHugeUnsignedInt ();
    if (result == NULL) {
        return NULL;
    }
    unsigned int column = 0;
    for (Node* node2 = operand2->end; !isNodeEmpty (node2); node2 = node2->previous, column++) {
        Digit carry = 0;
        HugeUnsignedInt* temp = createHugeUnsignedInt ();
        if (temp == NULL) {
            return NULL;
        }
        for (Node* node1 = operand1->end; !isNodeEmpty (node1); node1 = node1->previous) {
           Digit digitNode1 = node1->digit;
            Digit digitNode2 = node2->digit;
            Digit digitResult = ((digitNode1 * digitNode2) + carry) % 10;
            carry = ((digitNode1 * digitNode2) + carry) / 10;
            addDigitAtStart (temp, digitResult);
        }
        if (carry > 0) {
            addDigitAtStart (temp, carry);
        }
        for (unsigned int i = 0; i < column; i++) {
            addDigitAtEnd (temp, 0);
        }
        HugeUnsignedInt* tmpResult = addHugeUnsignedInt (result, temp);
        deleteHugeUnsignedInt (result);
        result = tmpResult;
        deleteHugeUnsignedInt (temp);
    }

    simplifyHugeUnsignedInt (result);
    return result;
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
