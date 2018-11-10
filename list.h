#ifndef LIST_H
#define LIST_H
#include "dish.h"

class List
{
private:
    struct Node;
public:
    class Iterator
    {
    public:
        friend List;
        Iterator();
        Iterator(const Iterator&);
        Iterator(Node *);
        ~Iterator();
        Iterator& operator ++();
        Iterator operator ++(int);
        Iterator& operator --();
        Iterator operator --(int);
        bool operator == (Iterator const &) const;
        bool operator != (Iterator const &) const;
        Base operator *();
     protected:
        Node *node;
    };
    friend Iterator;
    List();
    virtual ~List();
    List(const List&);
    virtual void addNode(const Dish&);
    virtual void deleteNode(Iterator&);
    void deleteNode(Dish const &);
    virtual void deleteList();
    virtual void writeInFile(std::string fileName);
    virtual void readFromFile(std::string fileName);
    virtual Iterator begin() const;
    virtual Iterator end() const;
    virtual int getLength() const;
    Base findDish(const float &) const;
    virtual bool operator == (List const &) const;
    virtual bool operator != (List const &) const;
private:
    struct Node
    {
        Base* object;
        Node *next, *prev;
    };
    void deleteNode(Node*);
    Node *head, *tail;
    int _length;
};



#endif // LIST_H