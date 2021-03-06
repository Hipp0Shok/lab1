#include "list.h"
#include <cassert>
#include <fstream>

Base* factory(Kind kind){
    if(kind == BASE)
        return nullptr;
    if(kind == DISH)
    {
            return new Dish;
    }
    if(kind == SETLUNCH)
    {
            return new SetLunch;
    }
    return nullptr;
}

float absoluteDiff(float first, float second)
{
    return first > second ? first - second : second - first;
}

List::Iterator::Iterator():
    node(nullptr)
{
}

List::Iterator::Iterator(const Iterator& existing):
    node(existing.node)
{

}

List::Iterator::Iterator(Node *existing):
    node(existing)
{
}

List::Iterator::~Iterator() = default;

const Base *List::Iterator::operator *()
{
    return node->object;
}

List::Iterator& List::Iterator::operator++()
{
    node = node->next;
    return *this;
}

List::Iterator List::Iterator::operator ++(int)
{
    Iterator prev = *this;
    node = node->next;
    return prev;
}

List::Iterator& List::Iterator::operator--()
{
    node = node->prev;
    return *this;
}

List::Iterator List::Iterator::operator --(int)
{
    Iterator* prev = new Iterator(*this);
    node = node->prev;
    return *prev;
}

bool List::Iterator::operator == (Iterator const &right) const
{
    return node == right.node;
}

bool List::Iterator::operator != (Iterator const &right) const
{
    return node != right.node;
}

List::List():
    head(nullptr),
    tail(nullptr),
    _length(0)
{
}

List::List(const List &existing):
    head(nullptr),
    tail(nullptr)
{
    Node *newNode, *existingNode = existing.head;
    Base *tempDish;
    _length = 0;
    if(existing._length)
    {
        tempDish = factory(existingNode->object->getKind());
        *tempDish = *(existingNode->object);
        newNode = new Node;
        newNode->object = tempDish;
        newNode->prev = nullptr;
        existingNode = existingNode->next;
        _length++;
        head = newNode;
        tail = head;
        tail->next = nullptr;
        while(existingNode)
        {
            tempDish = factory(existingNode->object->getKind());
            *tempDish = *(existingNode->object);
            tail = new Node;
            newNode->next = tail;
            tail->prev = newNode;
            tail->next = nullptr;
            tail->object = tempDish;
            existingNode = existingNode->next;
            newNode = tail;
            _length++;
        }
    }

}

List::~List()
{
    while(head)
    {
        tail = head->next;
        delete head;
        head = tail;
    }
}

void List::addNode(const Dish existing)
{
    addNode(&existing);
}

void List::addNode(const SetLunch existing)
{
    addNode(&existing);
}

void List::addNode(const Base* existing)
{
    if(!head)
    {
        head = new Node;
        head->object = factory(existing->getKind());
        *(head->object) = *existing;
        head->next = nullptr;
        head->prev = nullptr;
        tail = head;
    }
    else
    {
        Node* temp = head;
        while(temp)
        {
            if(temp->object->getEnergyValueTotal() > existing->getEnergyValueTotal())
                break;
            temp = temp->next;
        };
        Node* added = new Node;
        added->object = factory(existing->getKind());
        *(added->object) = *existing;
        if(!temp)
        {
            tail->next = added;
            added->next = nullptr;
            added->prev = tail;
            tail = added;
        }
        else
        {
            added->next = temp;
            added->prev = temp->prev;
            if( temp == head)
            {
                head = added;
            }
            else
            {
                temp->prev->next = added;
            }
            temp->prev = added;
        }
    }
    _length++;
}

void List::deleteNode(Node* existing)
{
    Node* temp = head;
    do
    {
        if(temp == existing)
        {
            if(temp == head)
            {
                if(head != tail)
                {
                    head = temp->next;
                    head->prev = nullptr;
                }
                else
                {
                    head = tail = nullptr;
                }
            }
            else
            {
                if(temp == tail)
                {
                    tail = temp->prev;
                    tail->next = nullptr;
                }
                else
                {
                    temp->next->prev = temp->prev;
                    temp->prev->next = temp->next;
                }
            }
            delete existing;
            _length--;
            break;
        }
        else
        {
            temp = temp->next;
        }
    }while(temp);
}

void List::deleteNode(const Dish existing)
{
    List::Iterator iter;
    iter = begin();
    for(;iter != nullptr; iter++)
    {
        if((*iter)->getKind() == existing.getKind())
        {
            if(*dynamic_cast<const Dish*>(*iter) == existing)
            {
                deleteNode(iter);
                break;
            }
        }
    }

}

void List::deleteNode(const SetLunch existing)
{
    List::Iterator iter;
    iter = begin();
    for(;iter != nullptr; iter++)
    {
        if((*iter)->getKind() == existing.getKind())
        {
            if(*dynamic_cast<const SetLunch*>(*iter) == existing)
            {
                deleteNode(iter);
                break;
            }
        }
    }
}


void List::deleteList()
{
    while(head)
    {
        tail = head->next;
        delete head;
        head = tail;
    }
    head = tail = nullptr;
    _length = 0;
}

int List::getLength() const
{
    return _length;
}

List::Iterator List::begin() const
{
    Iterator temp(head);
    return temp;
}

List::Iterator List::end() const
{
    Iterator temp(tail);
    return temp;
}

void List::deleteNode(Iterator &current)
{
    Node* save = current.node->prev;
    this->deleteNode(current.node);
    current.node = save;
}

const Base* List::findDish(const float &energyValue) const
{
    Iterator iterator;
    iterator = this->begin();
    iterator++;
    const Base* answer;
    answer = head->object;
    float difference;
    difference = absoluteDiff(answer->getEnergyValueTotal(), energyValue);
    for(; iterator != nullptr; iterator++)
    {
        if(absoluteDiff((*iterator)->getEnergyValueTotal(), energyValue) < difference)
        {
            answer = *iterator;
            difference = absoluteDiff((*iterator)->getEnergyValueTotal(), energyValue);
        }
    }
    return answer;
}

bool List::operator==(List const &existingList) const
{
    Iterator firstIterator, secondIterator;
    if( _length != existingList._length)
    {
        return false;
    }
    for(firstIterator = Iterator(head), secondIterator = Iterator(existingList.head);
        firstIterator != nullptr; firstIterator++, secondIterator++)
    {
        if((*firstIterator)->getKind() != (*secondIterator)->getKind())
        {
            return false;
        }
        else
        {
            switch((*firstIterator)->getKind())
            {
            case(DISH):
                if(*(dynamic_cast<const Dish*>(*firstIterator)) != *dynamic_cast< const Dish*>(*secondIterator))
                {
                    return false;
                }
                break;
            case(SETLUNCH):
                if(*dynamic_cast<const SetLunch*>(*firstIterator) != *dynamic_cast<const SetLunch*>(*secondIterator))
                {
                    return false;
                }
                break;
            }
        }
    }
    return true;
}

bool List::operator!=(List const &existingList) const
{
    Iterator firstIterator, secondIterator;
    if( _length != existingList._length)
    {
        return true;
    }
    bool answer = false;
    for(firstIterator = Iterator(head), secondIterator = Iterator(existingList.head);
        firstIterator != nullptr; firstIterator++, secondIterator++)
    {
        if(*firstIterator != *secondIterator)
        {
            answer = true;
            break;
        }
    }
    return answer;
}

void List::writeInFile(QString fileName)
{
    std::ofstream file;
    file.open(fileName.toStdString(), std::ios::out | std::ios::binary);
    if(!file.is_open())
        return;
    List::Iterator iter;
    std::string name;
    int length;
    length = getLength();
    file.write(reinterpret_cast<char*>(&length), sizeof (int));
    for(iter = end(); iter != nullptr; iter--)
    {
        (*iter)->writeKind(file);
        (*iter)->write(file);
    }
    file.close();
}

void List::readFromFile(QString fileName)
{
    deleteList();
    std::ifstream file;
    file.open(fileName.toStdString(), std::ios::in | std::ios::binary);
    int amount;
    file.read(reinterpret_cast<char*>(&amount), sizeof(int));
    Base* temp;
    Kind tmpKind;
    std::string name;
    while(amount)
    {
        tmpKind = Base::readKind(file);
        temp = factory(tmpKind);
        temp->read(file);
        addNode(temp);
       amount--;
    }
    file.close();
}

void List::deleteNode(const Base *existing)
{
    Iterator iter;
    for( iter = begin(); iter != nullptr; iter++)
    {
        if((*iter) == existing)
        {
            deleteNode(iter);
            break;
        }
    }
}

const Base* List::findDishByName(const QString &name)
{
    List::Iterator iter;
    iter = begin();
    for( ; iter != nullptr; iter++)
    {
        if((*iter)->getKind() == DISH)
        {
            if(dynamic_cast<const Dish*>((*iter))->getName() == name)
            {
                return *iter;
            }
        }
        else
        {
            if(dynamic_cast<const SetLunch*>(*iter)->getNameTotal() == name)
            {
                return *iter;
            }
        }
    }
    return nullptr;
}

const Base* List::findByNameAndEnergy(const float& energy, const QString & name)
{
    List::Iterator iter;
    iter = begin();
    for( ; iter != nullptr; iter++)
    {
        if((*iter)->getKind() == DISH)
        {
            if(dynamic_cast<const Dish*>((*iter))->getName() == name &&
                    qFuzzyCompare( dynamic_cast<const Dish*>((*iter))->getEnergyValueTotal(), energy))
            {
                return *iter;
            }
        }
        else
        {
            if(dynamic_cast<const SetLunch*>(*iter)->getNameTotal() == name &&
                    qFuzzyCompare((*iter)->getEnergyValueTotal(), energy))
            {
                return *iter;
            }
        }
    }
    return nullptr;
}
