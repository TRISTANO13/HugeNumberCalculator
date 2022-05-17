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
    return NULL;
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
