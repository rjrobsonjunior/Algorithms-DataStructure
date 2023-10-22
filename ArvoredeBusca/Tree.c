#include "Tree.h"

int Seach( SeachTree* t, int d)
{
    if( t == NULL )
    {
        return 0;
    }
    else if( d < t->data)
    {
        return Seach( t->left, d);
    }
    else if( d > t->data)
    {
        return Seach( t->right, d);
    }
    else
    {
        return 1;
    }
}

SeachTree* Insert( SeachTree* t, int d)
{
    if( t != NULL)
    {
        if( t->data > d )
        {
            t->left = Insert( t->left, d);
        }
        else
        {
            t->right = Insert(t->right, d);
        }
    }
    else
    {
        t = (SeachTree*)malloc(sizeof(SeachTree));
        t->data = d;
        t->left = NULL;
        t->right = NULL;
    }
    return t;
}

SeachTree* Remove(SeachTree* t, int d)
{
    if(t == NULL)
    {
        return t;
    }
    if( t->data > d)
    {
        t->left = Remove(t->left, d);
    }
    else if(t->data < d)
    {
        t->right = Remove(t->right, d);
    }
    else
    {
        //lower sheet 
        if(t->left == NULL && t->right == NULL)
        {
            free(t);
            t = NULL;
        }
        else if( t->left == NULL)
        {
            SeachTree* tmp = t;
            t = t->right;
            free(tmp);
        }
        else if( t->right == NULL)
        {
            SeachTree* tmp = t;
            t = t->left;
            free(tmp);
        }
        else
        {
            SeachTree* tmp;
            for(tmp = t->left; tmp->right != NULL; tmp->right);
            t->data = tmp->data;
            tmp->data = d;
            t->left = Remove(t->left, d);
        }
    }
    return t;
}

int Minimum (SeachTree *t)
{
    if( t == NULL)
    {
        return __INT_MAX__;
    }
    else
    {
        int min = Minimum(t->left);
        int min1 = Minimum(t->right);
        int min2 = t->data;
        if(min < min2 && min < min1)
        {
            return min;
        }
        if(min1 < min2 && min1 < min)
        {
            return min1;
        }
        else
        {
            return min2;
        }
    }
}

int Maximum (SeachTree *t)
{
    if( t == NULL)
    {
        return -1;
    }
    else
    {
        int max = Maximum(t->left);
        int max1 = Maximum(t->right);
        int max2 = t->data;
        if(max > max2 && max > max1)
        {
            return max;
        }
        if(max1 > max2 && max1 > max)
        {
            return max1;
        }
        else
        {
            return max2;
        }
    }
}

void DecrescentPrint( SeachTree* t)
{
    if(t != NULL)
    {
        DecrescentPrint(t->right);
        printf("%d ", t->data);
        DecrescentPrint(t->left);
    }
}

int BiggerBranch(SeachTree* t)
{
    if( t != NULL)
    {
        int left = BiggerBranch(t->left);
        int right = BiggerBranch(t->right);
        int bigger = (left > right) ? left : right;
        return ( t->data +  bigger );
    }
    else
    {
        return 0;
    }
}

void PreOrder(SeachTree* t)
{
    if (t != NULL) {
      printf("%d ", t->data);
      PreOrder (t->left);
      PreOrder (t->right);
   } 
}

SeachTree* makeSeachTree (void)
{
    return NULL;
}

void TreeFre (SeachTree* t) {
   if (t != NULL) {
      TreeFre (t->left);
      TreeFre (t->right);
      free(t);
   }
}