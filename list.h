#ifndef LIST_H
#define LIST_H
#include "setlunch.h"

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
        const Base* operator *();
     protected:
        Node *node;
    };
    friend Iterator;
    List();
    ~List();
    List(const List&);
    void addNode(const Dish);
    void addNode(const SetLunch);
    void addNode(const Base*);
    void deleteNode(Iterator&);
    void deleteNode(const Base*);
    void deleteNode(const Dish);
    void deleteNode(const SetLunch);
    void deleteList();
    void writeInFile(std::string fileName);
    void readFromFile(std::string fileName);
    Iterator begin() const;
    Iterator end() const;
    int getLength() const;
    const Base* findDish(const float &) const;
    const Base* findDishByName(const std::string &);
    const Base* findByNameAndEnergy(const float&, const std::string &);
    bool operator == (List const &) const;
    bool operator != (List const &) const;
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