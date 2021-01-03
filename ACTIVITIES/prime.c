#include "prime.h"

int Prime_no(int num)
{
    for (int i = 2; i < num/2 ; i++)
    {
        if(num%i == 0)
        {
            return 0;
            break;
        }
        else
            return 1;
    }
    
}

