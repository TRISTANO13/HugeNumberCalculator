#include <stdio.h>
#include "HugeFloatOperator.h"

HugeFloat* addHugeFloat (const HugeFloat* operand1, const HugeFloat* operand2) {
    return NULL;
}

HugeFloat* substractHugeFloat (const HugeFloat* operand1, const HugeFloat* operand2) {
    HugeFloat* result;
    HugeFloat* tmpOperand2 = createHugeFloatFromHugeFloat (operand2, 0);

    if (tmpOperand2 == NULL) {
        return NULL;
    }
    if (tmpOperand2->significand->sign == PLUS) {
        tmpOperand2->significand->sign = MINUS;
    } else {
        tmpOperand2->significand->sign = PLUS;
    }
    result = addHugeFloat (operand1, tmpOperand2);
    deleteHugeFloat (tmpOperand2);
    simplifyHugeFloat (result);
    return result;
}

HugeFloat* multiplyHugeFloat (const HugeFloat* operand1, const HugeFloat* operand2) {
    HugeFloat* result = createHugeFloat ();
    if (result != NULL) {
        result->significand = multiplyHugeInt (operand1->significand, operand2->significand);
        result->exponent = addHugeInt (operand1->exponent, operand2->exponent);
    }
    simplifyHugeFloat (result);
    return result;
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
