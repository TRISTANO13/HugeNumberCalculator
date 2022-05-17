#include <stdio.h>
#include "HugeIntOperator.h"

HugeInt* addHugeInt (const HugeInt* operand1, const HugeInt* operand2) {
    return NULL;
}

HugeInt* substractHugeInt (const HugeInt* operand1, const HugeInt* operand2) {
    HugeInt* result;
    HugeInt* tmpOperand2 = createHugeIntFromHugeInt (operand2, 0);

    if (tmpOperand2 == NULL) {
        return NULL;
    }
    if (tmpOperand2->sign == PLUS) {
        tmpOperand2->sign = MINUS;
    } else {
        tmpOperand2->sign = PLUS;
    }
    result = addHugeInt (operand1, tmpOperand2);
    deleteHugeInt (tmpOperand2);
    return result;
}

HugeInt* multiplyHugeInt (const HugeInt* operand1, const HugeInt* operand2) {
    HugeInt* result = createHugeInt ();
    if (result != NULL) {
        result->absoluteValue = multiplyHugeUnsignedInt (operand1->absoluteValue, operand2->absoluteValue);
        if (operand1->sign == operand2->sign) {
            result->sign = PLUS;
        } else {
            result->sign = MINUS;
        }
    }
    return result;
}

HugeInt* divideHugeInt (const HugeInt* operand1, const HugeInt* operand2) {
    return NULL;
}
