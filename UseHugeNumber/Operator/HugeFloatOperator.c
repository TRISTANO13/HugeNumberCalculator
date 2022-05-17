#include <stdio.h>
#include "HugeFloatOperator.h"

HugeFloat* addHugeFloat (const HugeFloat* operand1, const HugeFloat* operand2) {
    return NULL;
}

HugeFloat* substractHugeFloat (const HugeFloat* operand1, const HugeFloat* operand2) {
    return NULL;
}

HugeFloat* multiplyHugeFloat (const HugeFloat* operand1, const HugeFloat* operand2) {
    return NULL;
}

HugeFloat* simplifyHugeFloat (HugeFloat* hugeFloat) {
    if (hugeFloat != NULL) {
        simplifyHugeInt (hugeFloat->significand);
        simplifyHugeInt (hugeFloat->exponent);
        char simplify = 1;
        while ((!isNodeEmpty (hugeFloat->significand->absoluteValue->end)) && simplify) {
            if ((hugeFloat->significand->absoluteValue->end->digit == 0)
                && (hugeFloat->significand->absoluteValue->end != hugeFloat->significand->absoluteValue->start)) {
                removeEndFromDoublyLinkedList (hugeFloat->significand->absoluteValue);
                incrementHugeUnsignedInt (hugeFloat->exponent->absoluteValue);
            } else {
                simplify = 0;
            }
        }
    }
    return hugeFloat;
}
