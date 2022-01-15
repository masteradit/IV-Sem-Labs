#include <iostream>
#include <stdio.h>
using namespace std;
int n;              //number of items
double c;           //backpack capacity
double v[100];      //The value of each item　value
double w[100];      //The weight of each item　weight
double cw = 0.0;    //current weight of the backpack　current weight
double cp = 0.0;    //Total value of items in the current backpack　current value
double bestp = 0.0; //Current best value best price
double perp[100];   //unit item value (after sorting) per price
int order[100];     //Item number
int put[100];       //Set whether to load, when it is 1, it means to select this group of data to load, and 0 means not to select this group of data

//Sort by unit value
void knapsack()
{
    int i, j;
    int temporder = 0;
    double temp = 0.0;

    for (i = 1; i <= n; i++)
        perp[i] = v[i] / w[i]; //Calculate the unit value (the value of the item per unit weight)
    for (i = 1; i <= n - 1; i++)
    {
        for (j = i + 1; j <= n; j++)
            if (perp[i] < perp[j]) //Bubble sort perp[],order[],sortv[],sortw[]
            {
                temp = perp[i]; //bubble to sort perp[]
                perp[i] = perp[i];
                perp[j] = temp;

                temporder = order[i]; //bubble to sort order[]
                order[i] = order[j];
                order[j] = temporder;

                temp = v[i]; //bubble to sort v[]
                v[i] = v[j];
                v[j] = temp;

                temp = w[i]; //bubble to sort w[]
                w[i] = w[j];
                w[j] = temp;
            }
    }
}

//Backtracking function
void backtrack(int i)
{ //i is used to indicate the number of layers reached (the first step, starting from 0), and also indicate how many items are currently selected to play
    double bound(int i);
    if (i > n) //Judgment condition for the end of recursion
    {
        bestp = cp;
        return;
    }
    //If the left child node is feasible, search the left child tree directly;
    //For the right subtree, first calculate the upper bound function to determine whether to subtract it
    if (cw + w[i] <= c) //Put item i into the backpack and search the left subtree
    {
        cw += w[i]; //Update the weight of the current backpack synchronously
        cp += v[i]; //Update the total value of the current backpack simultaneously
        put[i] = 1;
        backtrack(i + 1); //Deep search enters the next layer
        cw -= w[i];       //Retroactive recovery
        cp -= v[i];       //Retroactive recovery
    }
    if (bound(i + 1) > bestp) //If the conditions are met, search the right subtree
        backtrack(i + 1);
}

//Calculate the upper bound function, the function is pruning
double bound(int i)
{                          //To judge the total value of the current backpack cp + the maximum value that the remaining capacity can hold <= the current optimal value
    double leftw = c - cw; //Remaining backpack capacity
    double b = cp;         //Record the total value cp of the current backpack, and finally find the upper bound
                           //Load items in descending order of unit weight value
    while (i <= n && w[i] <= leftw)
    {
        leftw -= w[i];
        b += v[i];
        i++;
    }
    //Full of backpacks
    if (i <= n)
        b += v[i] / w[i] * leftw;
    return b; //return the calculated upper bound
}

int main()
{
    int i;
    printf("Please enter the number of items and the capacity of the backpack:");
    scanf("%d %lf", &n, &c);
    /*printf("Please enter the weight and value of the item:\n");
    for(i=1;i<=n;i++)
    {
                 printf("The weight of the %d item:",i);
        scanf("%lf",&w[i]);
                 printf("The value of the %d item is:",i);
        scanf("%lf",&v[i]);
        order[i]=i;
    }*/
    printf("Please enter the weight of %d items in turn:\n", n);
    for (i = 1; i <= n; i++)
    {
        scanf("%lf", &w[i]);
        order[i] = i;
    }

    printf("Please enter the value of %d items in turn:\n", n);
    for (i = 1; i <= n; i++)
    {
        scanf("%lf", &v[i]);
    }

    knapsack();
    backtrack(1);

    printf("The best value is: %lf\n", bestp);
    printf("The item number that needs to be loaded is:");
    for (i = 1; i <= n; i++)
    {
        if (put[i] == 1)
            printf("%d ", order[i]);
    }
    return 0;
}