#ifndef __LIST_H
#define __LIST_H

namespace m34 {

template <class T> class Node {
  public:
    T data;
    Node *next;
    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }
    Node(T data, Node *next) {
        this->data = data;
        this->next = next;
        next->next = nullptr;
    }

    void operator=(Node *other) {
        this->data = other->data;
        this->next = other->next;
    }

    static Node *CreateNode(T data) {
        Node<T> *node = new Node<T>(data);
        return node;
    }

	void push_back(T data)
	{
		if(this->next == nullptr)
			this->next = CreateNode(data);
		else
			(*this->next).push_back(data);
	}

	class iterator
	{
		Node* pointer;
	public:
		iterator(Node* ptr) : pointer(ptr) {}

		Node& operator*()
		{
			return *pointer;
		}

		iterator& operator++()
		{
			pointer = pointer->next;
			return *this;
		}

		iterator operator++(int)
		{
			iterator tmp = *this;
			operator++();
			return tmp;
		}

		iterator& operator+=(int value)
		{
			while(value--)
			{
				pointer = pointer->next;
			}
			return *this;
		}

		friend bool operator==(iterator lhs, iterator rhs)
		{
			return lhs.pointer == rhs.pointer; 
		}
	
		friend bool operator!=(iterator lhs, iterator rhs)
		{
			return !(lhs == rhs);	
		}
	};
	
	m34::Node<T>::iterator begin()
	{
		return iterator(this);
	}

	m34::Node<T>::iterator end()
	{
		auto tmp = this;
		while(tmp->next != nullptr)
		{
			tmp = tmp->next;
		}
		return iterator(tmp->next);
	}

};
} // namespace m34

#endif
