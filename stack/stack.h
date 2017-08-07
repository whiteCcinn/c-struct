/*************************************************************************
  > File Name: stack.h
  > Author: Caiwh
  > Mail: 471113744@qq.com
  > Created Time: Sun 06 Aug 2017 08:52:02 PM PDT
 ************************************************************************/

#ifndef _STACK_H
#define _STACK_H
#endif

#define DataType int
// 栈存储数量
#define MaxSize 1024 

// 栈结构
typedef struct {
    DataType data[MaxSize];
    int top;
}SeqStack,*pSeqStack;

// API1.初始化栈
pSeqStack initStack();
// API2.判断是否栈空
int isEmpty(pSeqStack stack);
// API3.判断是否栈满
int isFulled(pSeqStack stack);
// API4.进栈
int Push(pSeqStack stack,int data);
// API5.出栈
int Pop(pSeqStack stack);
// API6.打印栈内数据
void printfStack(pSeqStack stack);
// 额外API7.让特定的值出栈
int PopToData(pSeqStack stack,int data);
