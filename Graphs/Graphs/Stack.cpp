#include "Stack.h"

Stack::Stack() { pStart = pEnd = nullptr; }

double Stack::front()
{
    return pStart->Value;
}

double Stack::back()
{
    return pEnd->Value;
}

bool Stack::IsEmpty()
{
    return pStart == nullptr;
}

void Stack::push(double value)
{
    Node* NewNode = new Node();
    NewNode->Value = value;
    NewNode->pLast = pEnd;

    if (pStart == nullptr)
    {
        pStart = NewNode;
        pEnd = pStart;
        return;
    }

    pEnd->pNext = NewNode;
    pEnd = NewNode;
}

double Stack::pop()
{
    if (pEnd == nullptr) {
        std::exit(-1);
    }

    double Value;
    if (pEnd == pStart)
    {
        Value = pEnd->Value;
        delete pEnd;
        pEnd = pStart = nullptr;
        return Value;
    }

    Node* LastNode = pEnd;
    pEnd = pEnd->pLast;
    pEnd->pNext = nullptr;

    Value = LastNode->Value;
    delete LastNode;
    return Value;
}

Stack::~Stack()
{
    Node* pList = pStart;
    while (pList != nullptr)
    {
        Node* OldNode = pList;
        pList = pList->pNext;
        delete OldNode;
    }
}

std::ostream& operator<<(std::ostream& out, Stack& MyStack)
{
    Node* pList = MyStack.pStart;
    while (pList != nullptr)
    {
        out << pList->Value << " ";
        pList = pList->pNext;
    }
    return out;
}
