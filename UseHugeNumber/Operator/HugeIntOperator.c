#include <stdio.h>
#include "HugeIntOperator.h"

HugeInt* addHugeInt (const HugeInt* operand1, const HugeInt* operand2) {
    return NULL;
}

HugeInt* substractHugeInt (const HugeInt* operand1, const HugeInt* operand2) {
    return NULL;
}

HugeInt* multiplyHugeInt (const HugeInt* operand1, const HugeInt* operand2) {
    return NULL;
}

HugeInt* divideHugeInt (const HugeInt* operand1, const HugeInt* operand2) {
    HugeInt* result = createHugeIntFromString ("0");
    if (result != NULL) {
        result->absoluteValue = divideHugeUnsignedInt (operand1->absoluteValue, operand2->absoluteValue);
        if (operand1->sign == operand2->sign) {
            result->sign = PLUS;
        } else {
            result->sign = MINUS;
        }
    }
    return result;
}
