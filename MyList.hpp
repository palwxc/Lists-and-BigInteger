//Programmer: Phillip LaFrance	//Student ID: 12398940
//Intructor: Patrick Taylor		//Section: A		//Date: 03/19/2018
//File: MyList.hpp			    //Description: Defines functions for MyList.h

/* Define all your MyVector-related functions here.
 * You do not need to include the h file.
 * It included this file at the bottom.
 */

//Node already defined

/**Default constructor*/
template <typename T>
MyList<T>::MyList()
{
    m_head = new Node<T>(NULL, NULL, NULL);
    m_head->m_next = m_tail = new Node<T>(NULL, m_head, NULL);
    m_size = 0;
}

/**Destructor*/
template <typename T>
MyList<T>::~MyList()
{
    Node<T> *curr;
    while(m_head != NULL)
    {
        curr = m_head;
        m_head = m_head->m_next;
        delete curr;
    }
}

/**Operator =*/
//shallow copy??
template <typename T>
MyList<T>& MyList<T>::operator=(const MyList<T> &source)
{

    if(this != &source)
    {
        /*
        m_head = source.m_head;
        m_tail = source.m_tail;
        m_size = source.m_size;
        */
        m_head = new Node<T>(NULL, NULL, NULL);
        m_head->m_next = m_tail = new Node<T>(NULL, m_head, NULL);
        m_size = 0;

        Node<T> *curr = source.m_head;
        while(curr)
        {
            T tmp = curr->m_element;
            push_back(tmp);
            curr = curr->m_next;
        }
    }
    return *this;
}

/**Copy constructor*/
//deep copy constructor
template <typename T>
MyList<T>::MyList(const MyList<T> &source)
{
    if(this != &source)
    {
        m_head = new Node<T>(NULL, NULL, NULL);
        m_head->m_next = m_tail = new Node<T>(NULL, m_head, NULL);
        m_size = 0;

        Node<T> *curr = source.m_head;
        while(curr)
        {
            T tmp = curr->m_element;
            push_back(tmp);
            curr = curr->m_next;
        }
    }
}

/**front*/
//returns element of head
template <typename T>
T & MyList<T>::front()
{
    return m_head->m_element;
}

/**back*/
//returns element of tail
template <typename T>
T & MyList<T>::back()
{
    return m_tail->m_element;
}

/**assign*/
//recreates dll with length=count and m_element=value for all nodes
template <typename T>
void MyList<T>::assign(int count, const T &value)
{
    clear();
    for (int i=0; i<count; i++)
        push_back(value);
}

/**clear*/
//removes all nodes using pop_back
template <typename T>
void MyList<T>::clear()
{
    int tmp = m_size;
    for(auto i = 0; i < tmp; i++)
        pop_back();
}

/**push_front*/
//adds node to front of dll
template <typename T>
void MyList<T>::push_front(const T &x)
{
    if(m_size == 0)
    {
        Node<T> *newNode = new Node<T>(x, NULL, NULL);
        m_head = newNode;
        m_tail = newNode;
    }
    else
    {
        Node<T> *newNode = new Node<T>(x, NULL, m_head);
        m_head->m_prev=newNode;
        m_head=newNode;
    }
    m_size++;
}

/**push_back*/
//adds node to back of dll
template <typename T>
void MyList<T>::push_back(const T &x)
{
    /*
    if(m_head == NULL)
    {
        cout << "m_head" << endl;
    }
    Node<T> *newNode = new Node<T>(x, m_tail->m_prev, m_tail);
    m_tail->m_next = newNode;
    //delete m_tail??
    m_tail = newNode;
    m_size++;
    //cout << "push_back complete" << endl;
*/
    if(m_size == 0)
    {
        Node<T> *newNode = new Node<T>(x, NULL, NULL);
        m_head = newNode;
        m_tail = newNode;
    }
    else
    {
        Node<T> *newNode = new Node<T>(x, m_tail, NULL);
        m_tail->m_next=newNode;
        m_tail=newNode;
    }
    m_size++;
    /*
    m_size++;
    Node<T> *newNode = new Node<T>(NULL, NULL, NULL);
    new (&(newNode->m_element)) T(x);
    newNode->m_next = NULL;
    newNode->m_prev = m_tail;
    if(m_head == NULL && m_tail == NULL)
    {
        cout << "first node" << endl;
        m_head = m_tail = newNode;
    }
    else
    {
        cout << "new node" << endl;
        m_tail->m_next = newNode;
        m_tail = newNode;
    }*/
}

/**pop_back*/
//removes node from back of dll
template <typename T>
void MyList<T>::pop_back()
{
    /*
    if(m_size==0)
        return;
    Node<T> *tmpNode = m_tail;
    m_tail = m_tail->m_prev;
    m_tail->m_next = NULL;
    delete tmpNode;
    m_size--;
    return;
    */
    if(m_size==0)
        return;
    if(m_size == 1)
    {
        delete m_tail;
        m_tail = m_head = NULL;
        m_size--;
        return;
    }
    Node<T> *tmp = m_tail->m_prev;
    tmp->m_next = NULL;
    delete m_tail;
    m_tail = tmp;
    m_size--;
}

/**insert*/
//0 is start of dll & m_size is end of dll
//therefore, one is the second position in the dll
// Simplified version that only takes one position
template <typename T>
void MyList<T>::insert(int i, const T &x)
{
    if(m_size==0)
    {
        cout << "ERROR - erase: no elements in list" << endl;
        return;
    }
    if(i<0 || i>m_size)
    {
        cout << "ERROR - erase: invalid number for i" << endl;
        return;
    }
    if(i==m_size)
    {
        push_back(x);
        return;
    }
    if(i==0)
    {
        push_front(x);
        return;
    }

    Node<T> *pre = m_head;
    for(int k=0; k<i-1; k++)
        pre = pre->m_next;
    Node<T> *aft = pre->m_next;
    Node<T> *newNode = new Node<T>(x, pre, aft);
    aft->m_prev = newNode;
    pre->m_next = newNode;
    m_size++;
}

/**remove*/
//removes all occurrences of i
template <typename T>
void MyList<T>::remove(T i)
{
    if(m_size==0)
    {
        cout << "ERROR - erase: no elements in list" << endl;
        return;
    }
    while(m_head->m_element == i)
    {
        Node<T> *tmp = m_head->m_next;
        tmp->m_prev = NULL;
        delete m_head;
        m_head = tmp;
        m_size--;
    }
    while(m_tail->m_element == i)
    {
        pop_back();
    }

    Node<T> *removedNode = m_head;
    for (int k=0; k<m_size; k++)
    {
        if(removedNode->m_element == i)
        {
            Node<T> *tmpNode = removedNode->m_prev;
            removedNode->m_prev->m_next = removedNode->m_next;
            removedNode->m_next->m_prev = removedNode->m_prev;
            delete removedNode;
            removedNode = tmpNode;
            m_size--;
        }
        removedNode=removedNode->m_next;
    }
}

/**erase*/
//erases element at index i
//0 is head
//m_size-1 is tail
template <typename T>
void MyList<T>::erase(int i)
{
    if(m_size==0)
    {
        cout << "ERROR - erase: no elements in list" << endl;
        return;
    }
    if(i<0 || i>m_size)
    {
        cout << "ERROR - erase: invalid number for i" << i << endl;
        return;
    }
    if(i==m_size || i==m_size-1) //because dll is from 0 to m_size-1, yet m_size works for standard list
    {
        pop_back();
        return;
    }
    if(i==0)
    {
        Node<T> *tmp = m_head->m_next;
        tmp->m_prev = NULL;
        delete m_head;
        m_head = tmp;
        m_size--;
        return;
    }

    Node<T> *removedNode = m_head;
    for(int k=0; k<i; k++)
        removedNode = removedNode->m_next;
    //cout << endl << removedNode->m_element << endl << endl;
    removedNode->m_prev->m_next = removedNode->m_next;
    removedNode->m_next->m_prev = removedNode->m_prev;
    delete removedNode;
    m_size--;
}

/**reverse*/
//reverses dll by swapping m_next and m_prev for each node, and swapping m_head and m_tail
template <typename T>
void MyList<T>::reverse()
{
    if(m_size==0 || m_size==1)
        return;
    Node<T> *tmp = NULL;
    Node<T> *curr = m_head;
    while(curr != NULL)
    {
        tmp = curr->m_prev;
        curr->m_prev = curr->m_next;
        curr->m_next = tmp;
        curr = curr->m_prev;
    }
    //if(tmp != NULL)
    m_tail = m_head;
        m_head = tmp->m_prev;
    //cout << "reverse has finished" << endl;
}

/**resize*/
//resizes dll, uses 0 as element if dll is growing
template <typename T>
void MyList<T>::resize(int count)
{
    if(count<0)
    {
        cout << "ERROR - resize: invalid number for count" << endl;
        return;
    }
    if(count < m_size)
        for (int i=m_size; i>count; i--)
            pop_back();
    else if (count > m_size)
        for (int i=m_size; i<count; i++)
            push_back(0);
    else return;
}

/**empty*/
//true if empty, false if not empty
template <typename T>
bool MyList<T>::empty()
{
    if(m_size==0)
        return true;
    return false;
}

/**size*/
template <typename T>
int MyList<T>::size()
{
    return m_size;
}
