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
    return NULL;
}

HugeInt* divideHugeInt (const HugeInt* operand1, const HugeInt* operand2) {
    return NULL;
}
