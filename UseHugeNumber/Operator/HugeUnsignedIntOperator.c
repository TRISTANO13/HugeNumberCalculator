#include <stdio.h>
#include "HugeUnsignedIntOperator.h"

#define HUGE_NUMBER_SUPERIOR 1
#define HUGE_NUMBER_EQUAL 2
#define HUGE_NUMBER_INFERIOR 3

static unsigned int compareHugeUnsignedInts (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2);

HugeUnsignedInt* addHugeUnsignedInt (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2) {
    HugeUnsignedInt* result = createHugeUnsignedInt ();

    if (result != NULL) {
        Node* node1 = operand1->end;
        Node* node2 = operand2->end;
        Digit carry = 0;
        while (!isNodeEmpty (node1) || !isNodeEmpty (node2)) {
            Digit digitNode1 = isNodeEmpty (node1) ? 0 : node1->digit;
            Digit digitNode2 = isNodeEmpty (node2) ? 0 : node2->digit;
            Digit digitResult = (digitNode1 + digitNode2 + carry) % 10;
            carry = (digitNode1 + digitNode2 + carry) / 10;
            addDigitAtStart (result, digitResult);
            if (!isNodeEmpty (node1)) {
                node1 = node1->previous;
            }
            if (!isNodeEmpty (node2)) {
                node2 = node2->previous;
            }
        }
        if (carry > 0) {
            addDigitAtStart (result, carry);
        }
    }
    return result;
}

HugeInt* substractHugeUnsignedInt (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2) {
    return NULL;
}

HugeUnsignedInt* multiplyHugeUnsignedInt (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2) {
    return NULL;
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
