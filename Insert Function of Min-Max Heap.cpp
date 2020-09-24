///You all know that min-max heap is an important element 
in DATA STRUCTURES & ALGORITHMS. 
Many have problem in creating or understanding the Insert Function for this data structure.
So, I am sharing here an easy code of mine, which will clear the ideas, I hope.///

//code in C++

//all you have to do is, insert the new value to the end of the array (creating a new position, i.e. increasing the size of the array)
and check if it's position is okay in the heap structure (if min/max properties hold for every previous nodes in the branch of the tree).
//

#include<bits/stdc++.h>
using namespace std;

int a[10005],b[10005];

void swap_it(int x,int y)
{
    int tmp=a[x];
    a[x]=a[y];
    a[y]=tmp;
}

int getparindex(int i)
{
    if((i/2)>0) return i/2;
    return -1;
}

int getgrandindex(int i)
{
    if((i/4)>0) return i/4;
    return -1;
}

int getlevel(int i)
{
    return log2(i)+1;
}

void check_max(int v)
{
    int grandv=getgrandindex(v);
    if(grandv>0)
    {
        if(a[v]>a[grandv])
        {
            swap_it(v,grandv);
            check_max(grandv);
        }
    }
}

void check_min(int v)
{
    int grandv=getgrandindex(v);
    if(grandv>0)
    {
        if(a[v]<a[grandv])
        {
            swap_it(v,grandv);
            check_min(grandv);
        }
    }
}

void insertValue(int value,int curindex)
{
    a[curindex]=value;
    int parindex=getparindex(curindex);
    int grandindex=getgrandindex(curindex);
    int level=getlevel(curindex);
    //if even->min
    if(level%2)
    {
        if(parindex>0)
        {
            if(a[curindex]>a[parindex])
            {
                swap_it(curindex,parindex);
                check_max(parindex);
            }
            else
            {
                if(grandindex>0)
                {
                    check_min(curindex);
                }
            }
        }
    }
    //if odd->max
    if(!(level%2))
    {
        if(parindex>0)
        {
            if(a[curindex]<a[parindex])
            {
                swap_it(curindex,parindex);
                check_min(parindex);
            }
            else
            {
                if(grandindex>0)
                {
                    check_max(curindex);
                }
            }
        }
    }
}

int main()
{
    a[0]=-100000;
    int N,i,j;
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    {
        scanf("%d",&j);
        insertValue(j,i);
    }
    for(i=1;i<=N;i++)
    {
        printf("%d",a[i]);
        if(i!=N) printf("->");
    }
    printf("\n");
    return 0;
}

///This code has been written by Alif Ruslan, Undergraduate Student, Department of Computer Science & Engineering, University of Dhaka, Bangladesh.
///This code is under copyright issue. You can check the functions and use it to learn and share, but copying and reusing anything from here is strictly prohibited.
///Thank you <3

