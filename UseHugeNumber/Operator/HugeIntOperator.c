#include <stdio.h>
#include "HugeIntOperator.h"

HugeInt* addHugeInt (const HugeInt* operand1, const HugeInt* operand2) {
    HugeInt* result;
    if (operand1->sign == operand2->sign) {
        result = createHugeInt ();
        if (result == NULL) {
            return NULL;
        }
        result->absoluteValue = addHugeUnsignedInt (operand1->absoluteValue, operand2->absoluteValue);
        result->sign = operand1->sign;
    } else if (operand1->sign == PLUS) {
        result = substractHugeUnsignedInt (operand1->absoluteValue, operand2->absoluteValue);
    } else {
        result = substractHugeUnsignedInt (operand2->absoluteValue, operand1->absoluteValue);
    }
    return result;
}

HugeInt* substractHugeInt (const HugeInt* operand1, const HugeInt* operand2) {
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

HugeInt* multiplyHugeInt (const HugeInt* operand1, const HugeInt* operand2) {
    return NULL;
}

HugeInt* divideHugeInt (const HugeInt* operand1, const HugeInt* operand2) {
    return NULL;
}
