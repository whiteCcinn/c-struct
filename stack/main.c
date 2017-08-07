/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  栈的实现 
 *
 *        Version:  1.0
 *        Created:  08/06/2017 11:26:53 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Caiwh (471113744@qq.com), 
 *   Organization:  geek 
 *
 * =====================================================================================
 */

#ifndef __STACK_C__
#include "stack.c"
#endif

void main()
{
    pSeqStack stack;
    int expect,num,i = 0;
    int result,popNum;

    stack =  initStack();

    printf("栈初始化完成\n");

    printf("请输入你希望入栈的数据(最多1024个)\n");

    scanf("%d",&expect);
    if(expect > MaxSize)
    {
        printf("超过了最大值：");printf("%d\n",MaxSize);
        return;
    }
    for(i;i<expect;i++)
    {
      scanf("%d",&num);
      result = Push(stack,num);
      if(result<=0)
      {
          printf("入栈失败\n");
      }
    }

    printf("\n此时栈内元素为：\n");
    printfStack(stack);

    if(stack->top > 2)
    {
        popNum = Pop(stack);
        printf("出栈一个元素%d\n",popNum); 
        popNum = Pop(stack);
        printf("出栈一个元素%d\n",popNum);
    }

    if(stack->top >1)
    {
        // 出栈特定的数据
        printf("请输入要出栈的特定数据:");
        scanf("%d",&expect);
        PopToData(stack,expect);

         printf("\n此时栈内元素为：\n");
        printfStack(stack);
    }
}

