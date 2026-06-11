#include "conversor.h"

float celsius_fahrenheit(float c)
{
    float conversao;

    conversao = c * 1.8 + 32;

    return conversao;
}

float fahrenheit_celsius(float f)
{
    float conversao;

    conversao = (f-32)/ 1.8;

    return conversao;
}