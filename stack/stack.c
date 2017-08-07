/*
 * =====================================================================================
 *
 *       Filename:  stack.c
 *
 *    Description:  栈的API实现 
 *
 *        Version:  1.0
 *        Created:  08/06/2017 07:44:05 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Caiwh (471113744@qq.com), 
 *   Organization:  geek
 *
 * =====================================================================================
 */

#ifndef __STACK_C__
#define __STACK_C__
#include<stdio.h>
#include<malloc.h>
#include "stack.h"
#endif

// API1.初始化栈
pSeqStack initStack()
{
   pSeqStack pbottom;
   pbottom=(pSeqStack)malloc(sizeof(pSeqStack));
   if(!pbottom)
   {
       printf("空间不足\n");
       return NULL;
   }else{
       pbottom->top = -1;
       return pbottom;
   }
}

// API2.判断是否栈空
int isEmpty(pSeqStack stack)
{
   if(stack->top == -1)
   {
       return 1;
   }else{
       return 0;
   }
}

// API3.判断是否栈满
int isFulled(pSeqStack stack)
{
    if(stack->top == MaxSize)
    {
        return 1;  
    }else
    {
        return 0;
    }
}

// API4.进栈
int Push(pSeqStack stack,int data)
{
    if(isFulled(stack))
    {
        printf("栈满\n");

        return 0;
    }

    stack->top++;
    stack->data[stack->top] = data;
    return 1;
}

// API5.出栈
int Pop(pSeqStack stack)
{
    if(isEmpty(stack))
    {
        printf("栈内无数据\n");
        return 0;
    }

    stack->top--;
    return stack->data[stack->top+1];
}

// API6.打印栈内元素
void printfStack(pSeqStack stack)
{
    int i;
    for(i=stack->top;i>=0;i--)
    {
        printf("%d\n",stack->data[i]);
    }
}

// 额外API7.让特定的值出栈
int PopToData(pSeqStack stack,int data)
{
   int i;
   int tmp; 
    // 用一个辅助栈来记录不匹配的数据，用于回插入原栈
    pSeqStack sup_stack;
    sup_stack = (pSeqStack)malloc(sizeof(pSeqStack));
    sup_stack = initStack();
       while(!isEmpty(stack))
       {
        i = Pop(stack);
        if(i == data)
        {
           while(!isEmpty(sup_stack))
           {
                tmp = Pop(sup_stack);
                Push(stack,tmp);
           }
           return data;
        }else{
            Push(sup_stack,i);
            printf("%d",i);
         }
       }
}
