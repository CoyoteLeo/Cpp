#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>

void inverse(char a[], int* digit)
{
    // inverse the num
    *digit = strlen(a);
    if (a[0] == 45)
    {
        *digit = (*digit - 1) * -1;
        for (int i = 0; i < strlen(a); i++)
            a[i] = a[i + 1];
    }
    // char tmp[strlen(a)]={0};->較優
    char tmp[500] = {0};  //->zerojudge不允許用變數宣告陣列範圍
    for (int i = 0; i < strlen(a); i++)
    {
        tmp[i] = a[strlen(a) - 1 - i] - '0';
    }
    for (int i = 0; i < strlen(a); i++)
    {
        a[i] = tmp[i];
        // printf("%d",a[i]);
    }
    return;
}

void add(char a[], char b[], char c[], int digit)
{
    digit = abs(digit);
    for (int i = 0; i < digit; i++)
    {
        c[i + 1] += ((a[i] + b[i] + c[i]) / 10);
        c[i] = (a[i] + b[i] + c[i]) % 10;
    }
}

void difference(char a[], char b[], char c[], int digit)
{
    digit = abs(digit);
    for (int i = 0; i < digit; i++)
    {
        c[i + 1] += (-1 + (10 + c[i] + a[i] - b[i]) / 10);
        c[i] = (10 + c[i] + a[i] - b[i]) % 10;
    }
    if (c[digit] < 0)
    {
        printf("-");
        c[digit]++;
        c[0] = 10 - c[0];
        for (int i = 1; i < digit; i++)
            c[i] = 9 - c[i];
    }
}

void product(char a[], char b[], char c[])
{
    for (int i = 0; i < strlen(b); i++)
    {
        for (int j = 0; j < strlen(a); j++)
        {
            c[i + j + 1] += ((a[i] * b[j]) + c[i + j]) / 10;
            c[i + j] = (a[i] * b[j] + c[i + j]) % 10;
            // printf("c[%d]:%d c[%d]:%d\n", i+j+1,c[i+j+1],i+j,c[i+j]);
        }
    }
}

void quotient(char a[], char b[], char c[], int digit)
//未完成
{
    for (int i = strlen(a) - strlen(b); i >= 0; i--)
    {
        for (int counter = 0; i < 10; i++)
        {
            a[]
        }
        c[i]++;
    }
}

int main()
{
    char a[500] = {0}, b[500] = {0}, c[500] = {0}, op;
    // if digit<0 means the num is negative
    // abs(digit) means the num's digits
    int a_digit, b_digit;
    while (scanf("%s", a) > 0)
    {
        inverse(a, &a_digit);
        scanf("%s", &op);
        scanf("%s", b);
        inverse(b, &b_digit);
        switch (op)
        {
            case '+':
                if (a_digit >= 0 && b_digit >= 0)
                    add(a, b, c, a_digit > b_digit ? a_digit : b_digit);
                else if (a_digit >= 0 && b_digit < 0)
                    difference(a, b, c, a_digit > abs(b_digit) ? a_digit : b_digit);
                else if (a_digit < 0 && b_digit >= 0)
                    difference(b, a, c, abs(a_digit) > b_digit ? a_digit : b_digit);
                else
                {
                    printf("-");
                    add(a, b, c, a_digit > b_digit ? b_digit : a_digit);
                }
                break;
            case '-':
                if (a_digit >= 0 && b_digit >= 0)
                    difference(a, b, c, a_digit > b_digit ? a_digit : b_digit);
                else if (a_digit >= 0 && b_digit < 0)
                    add(a, b, c, a_digit > abs(b_digit) ? a_digit : b_digit);
                else if (a_digit < 0 && b_digit >= 0)
                {
                    printf("-");
                    add(a, b, c, abs(a_digit) > b_digit ? a_digit : b_digit);
                }
                else
                    difference(b, a, c, a_digit > b_digit ? b_digit : a_digit);
                break;
            case '*':
                if (a_digit * b_digit < 0)
                    printf("-");
                product(a, b, c);
                break;
            case '/':
                quotient(a, b, c);
                break;
        }
        // print the result
        int lead = 499;
        while (c[lead] == 0)
            --lead;
        if (lead < 0)
            printf("0");
        // printf("%d %d\n", lead,strlen(c));
        for (int i = lead; i >= 0; i--)
            printf("%d", c[i]);
        printf("\n");
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
    }
    return 0;
}