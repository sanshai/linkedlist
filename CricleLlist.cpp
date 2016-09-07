#include <iostream>
#include <stdio.h>

template <class T>
class KCircleList
{
public:
    KCircleList();
    bool            Init(int nSize);
    bool            UnInit();
    bool            Push(T TempValue);
    bool            Pop(T &TempValue);

private:
    bool            IsEmpty();
    unsigned int    GetSize();
    T               *m_List;
    int             m_nEndPos;
    int             m_nStartPos;
    int             m_nListSize;
    unsigned int    m_nSubscript;
};

template <class T>
KCircleList<T> ::KCircleList()
{
    m_List         = NULL;
    m_nEndPos      = -1;
    m_nStartPos    = 0;
    m_nListSize    = 0;
    m_nSubscript   = 0;
}

template <class T>
bool KCircleList<T>::Init(int nSize)
{
    m_List = new T [nSize];
    if (!m_List)
        return false;
    else
    {
        m_nListSize = nSize;
        return true;
    }
}

template <class T>
bool KCircleList<T>::UnInit()
{
    if (GetSize())
    {
        delete []m_List;
        return true;
    }
    else
        return false;
}

template <class T>
bool KCircleList<T>::Push(T TempValue)
{
    if (m_nSubscript == GetSize())
        return false;
    else
    {
        m_nSubscript++;
        if (m_nSubscript == GetSize() - 1)
            m_nEndPos = 0;
        else
            m_nEndPos++;
        m_List[m_nEndPos] = TempValue;
        return true;
    }
}

template <class T>
bool KCircleList<T>::Pop(T &TempValue)
{
    if (!IsEmpty())
    {
        TempValue = m_List[m_nStartPos];
        m_nSubscript--;
        if (m_nStartPos == GetSize() - 1)
            m_nStartPos = 0;
        else
            m_nStartPos++;
        return true;
    }
    else
        return false;
}

template <class T>
bool KCircleList<T>::IsEmpty()
{
    return m_nSubscript == 0;
}

template <class T>
unsigned int KCircleList<T> ::GetSize()
{
    return m_nListSize;
}

int main()
{
    return 0;
}