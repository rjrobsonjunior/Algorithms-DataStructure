#include "TreeAVL.h"

Tree* Insert( Tree* t, char d)
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
        t = (Tree*)malloc(sizeof(Tree));
        t->data = d;
        t->left = NULL;
        t->right = NULL;
    }
    return t;
}

Tree* Remove(Tree* t, char d)
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
            Tree* tmp = t;
            t = t->right;
            free(tmp);
        }
        else if( t->right == NULL)
        {
            Tree* tmp = t;
            t = t->left;
            free(tmp);
        }
        else
        {
            Tree* tmp;
            for(tmp = t->left; tmp->right != NULL; tmp->right);
            t->data = tmp->data;
            tmp->data = d;
            t->left = Remove(t->left, d);
            t = Balance(t);
        }
    }
    return t;
}

Tree* Balance(Tree* t)
{

    if( t != NULL )
    {
        t->left = Balance(t->left);
        t->right = Balance(t->right);
        t-> heigth = HeightCalculate(t);

        int tleft = (t->left != NULL) ? t->left->heigth : -1;
        int tright = (t->right != NULL) ? t->right->heigth : -1;
        int balancing = tright - tleft;
        if( abs(balancing) > 1)
        {
            //unbalanced to right
            if( balancing > 0)
            {
                if (t->right->f_balancing > 0)
                {
                    // simple rotation
                }
                else
                {
                    // double rotation 
                }
            }
            //unbalanced to left
            else
            {
                if (t->right->f_balancing < 0)
                {
                    // simple rotation
                }
                else
                {
                    // double rotation 
                }
            }
        }
    }
    else
    {
        return NULL;
    }
}



int HeightCalculate(Tree* t)
{
    if( t == NULL)
    {
        return -1;
    }
    else
    {
        int right = HeightCalculate(t->right);
        int left = HeightCalculate(t->left);
        t->heigth = (right > left) ? (right + 1) : (left + 1);
        return t->heigth;
    }
}

Tree* RotationLeft( Tree* t)
{
    Tree* ass = t->right;
    t->right = ass->left;
    ass->left = t;
}

Tree* RotationRight( Tree* t)
{
    Tree* ass = t->left;
    t->right = ass->right;
    ass->left = t;
}

int BalancingCalculate(Tree* t)
{

}

void PreOrder(Tree* t)
{
    if (t != NULL) {
      printf("%d ", t->data);
      PreOrder (t->left);
      PreOrder (t->right);
   } 
}
