/**
*	@author 
*	@date 
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList() 
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	/** TODO 
		Fix this method
	*/
        
	return(m_size); //return member variabe value for list size
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;
	bool isFound = false;

	/** TODO 
		Fix this method
	*/
        if (temp != nullptr) //check to see if there is an existing Node
        {
            //loop until the end of the list is reached
            do 
            {
                if (temp->getValue() == value)
                {   //found value
                    isFound = true; 
                    break;
                }            
                else
                    temp = temp->getNext(); //get next Node
            } while (temp->getNext() != nullptr); 
            
            if (temp->getValue() == value) //found value
                isFound = true; 
            else //value is not in the list
                isFound = false; 
        }
        //list is empty
        else
            isFound = false; 
        
	return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);	
	
}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);	
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );		
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;
	bool isRemoved = false;

	/** TODO 
		Fix this method
	*/
        int track = 0;
        
        if (!isEmpty())
        {
            lastNode = m_front;
            secondintoLast = m_front;
            
            //find the end of the list
            while (lastNode->getNext() != nullptr)
            {
                lastNode = lastNode->getNext(); //get next pointer
                track++; //track current position in list
            }
            //find second to last Node
            for(int i = 1; i < track; i++)
                secondintoLast = secondintoLast->getNext(); 
            
            //have the second to last Node now point to nullptr
            secondintoLast->setNext(nullptr);
            
            //delete the final Node
            delete lastNode;
            //decrement size of list
            m_size--;
            //return true for successful removal
            isRemoved = true;
        }
        //return false for empty list
        else
            isRemoved = false;
        
	return(isRemoved);
}	

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
