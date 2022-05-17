#include <stdio.h>
#include "HugeFloatOperator.h"

HugeFloat* addHugeFloat (const HugeFloat* operand1, const HugeFloat* operand2) {
    HugeInt* exponentDifference = substractHugeInt (operand1->exponent, operand2->exponent);
    HugeFloat* result = createHugeFloat ();
    if (result != NULL) {
        HugeInt* tempOperand = createHugeInt ();
        if (tempOperand == NULL) {
            return NULL;
        }
        HugeInt* tempPowerOf10 = createHugeInt ();
        if (tempPowerOf10 == NULL) {
            return NULL;
        }
        tempPowerOf10->absoluteValue = createHugeUnsignedIntFromPowerOf10 (exponentDifference->absoluteValue);
        tempPowerOf10->sign = PLUS;
        if (exponentDifference->sign == PLUS) {
            tempOperand = multiplyHugeInt (operand1->significand, tempPowerOf10);
            result->significand = addHugeInt (tempOperand, operand2->significand);
            result->exponent = createHugeIntFromHugeInt (operand2->exponent, 0);
        } else {
            tempOperand = multiplyHugeInt (operand2->significand, tempPowerOf10);
            result->significand = addHugeInt (tempOperand, operand1->significand);
            result->exponent = createHugeIntFromHugeInt (operand1->exponent, 0);
        }
        deleteHugeInt (tempPowerOf10);
        deleteHugeInt (tempOperand);
        deleteHugeInt (exponentDifference);
    }
    simplifyHugeFloat (result);
    return result;
}

HugeFloat* substractHugeFloat (const HugeFloat* operand1, const HugeFloat* operand2) {
    return NULL;
}

HugeFloat* multiplyHugeFloat (const HugeFloat* operand1, const HugeFloat* operand2) {
    return NULL;
}

HugeFloat* simplifyHugeFloat (const HugeFloat* hugeFloat) {
    return NULL;
}
