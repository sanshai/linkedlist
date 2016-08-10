#include <iostream>
#include <stdio.h>

template <class T>
class KList
{
public:
    KList();
    void            UnInit();
    bool            PopFront(T &TempValue);
    bool            PushBack(T x);
    bool            IsEmpty();
    unsigned int    GetSize();

private:
    template<class T>
    class KListNode
    {
    public:
        KListNode()
        {
            m_pNext = NULL;
        }
        T            m_Value;
        KListNode    *m_pNext;
    };
    bool            DeleteFront();
    unsigned int    m_uListLength;
    KListNode<T>    *m_LastNode;
    KListNode<T>    *m_HeadNode;
    KListNode<T>    *m_Node;///temp node
};

template <class T>
KList<T> ::KList()
{
    m_Node          = NULL;
    m_HeadNode      = NULL;
    m_LastNode      = NULL;
    m_uListLength   = 0;
}

template <class T>
void KList<T> ::UnInit()
{
    while (DeleteFront());
}

template <class T>
bool KList<T> ::DeleteFront()
{
    KListNode<T> *TempNode = m_HeadNode;
    if (TempNode == NULL)
        return false;
    else
    {
        m_HeadNode = TempNode->m_pNext;
        if (!TempNode->m_pNext)
            m_LastNode = NULL;
        delete TempNode;
        m_uListLength--;
        return true;
    }
}

template <class T>
bool KList<T> ::PopFront(T &TempValue)
{
    if (!IsEmpty())
    {
        TempValue = m_HeadNode->m_Value;
        return DeleteFront();
    }
    else
        return false;
}

template <class T>
bool KList<T> ::PushBack(T x)
{
    m_Node = new KListNode<T>();
    if (!m_Node)
        return false;
    m_Node->m_Value = x;
    if (!m_LastNode)
    {
        m_HeadNode = m_Node;
        m_LastNode = m_Node;
    }
    else
    {
        m_LastNode->m_pNext = m_Node;
        m_LastNode          = m_Node;
    }
    m_uListLength++;
    return true;
}

template <class T>
bool KList<T> ::IsEmpty()
{
    return m_uListLength == 0;
}

template <class T>
unsigned int KList<T> ::GetSize()
{
    return m_uListLength;
}

int main()
{
    return 0;
}