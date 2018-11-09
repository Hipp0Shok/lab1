#include "list.h"
#include "dish.h"
#include <cassert>
#include <fstream>

float absoluteDiff(float first, float second)
{
    return first > second ? first - second : second - first;
}

List::Iterator::Iterator():
    node(nullptr)
{
}

List::Iterator::Iterator(const Iterator&) = default;

List::Iterator::Iterator(Node *existing):
    node(existing)
{
}

List::Iterator::~Iterator() = default;

Base List::Iterator::operator*()
{
    return *(node->object);
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
        tempDish = new Base(*(existingNode->object));
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
            tempDish = new Base(*(existingNode->object));
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

void List::addNode(const Dish& existing)
{
    if(!head)
    {
        head = new Node;
        head->object = new Dish(existing);
        head->next = nullptr;
        head->prev = nullptr;
        tail = head;
    }
    else
    {
        Node* temp = head;
        while(temp)
        {
            if(temp->object->getEnergyValueOn100() > existing.getEnergyValueOn100())
                break;
            temp = temp->next;
        };
        Node* added = new Node;
        added->object = new Dish(existing);
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
                head = temp->next;
                head->prev = nullptr;
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
    this->deleteNode(current.node);
}

Base List::findDish(const float &energyValue) const
{
    Iterator iterator;
    iterator = this->begin();
    iterator++;
    Base answer;
    answer = *(head->object);
    float difference;
    difference = absoluteDiff(answer.getEnergyValueOn100(), energyValue);
    for(; iterator != nullptr; iterator++)
    {
        if(absoluteDiff((*iterator).getEnergyValueOn100(), energyValue) < difference)
        {
            answer = *iterator;
            difference = absoluteDiff((*iterator).getEnergyValueOn100(), energyValue);
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
    bool answer = true;
    for(firstIterator = Iterator(head), secondIterator = Iterator(existingList.head);
        firstIterator != nullptr; firstIterator++, secondIterator++)
    {
        if(*firstIterator != *secondIterator)
        {
            answer = false;
        }
    }
    return answer;
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

void List::writeInFile(std::string fileName)
{
    std::fstream file;
    file.open(fileName, std::ios::out | std::ios::binary);
    List::Iterator iter;
    Base temp;
    std::string name;
    float fats, proteins, carbohydrates, organicAcids, alimentaryFibers, weight;
    int length;
    length = getLength();
    file.write(reinterpret_cast<char*>(&length), sizeof (int));
    for(iter = end(); iter != nullptr; iter--)
    {
        temp = *iter;
        name = temp.getName();
        length = static_cast<int>(name.size())+1;
        file.write(reinterpret_cast<char*>(&length), sizeof (int));
        file.write(name.c_str(), length);
        fats = temp.getFats();
        file.write(reinterpret_cast<char*>(&fats), sizeof (fats));
        proteins = temp.getProteins();
        file.write(reinterpret_cast<char*>(&proteins), sizeof (proteins));
        carbohydrates = temp.getCarbohydrates();
        file.write(reinterpret_cast<char*>(&carbohydrates), sizeof (carbohydrates));
        organicAcids = temp.getOrganicAcids();
        file.write(reinterpret_cast<char*>(&organicAcids), sizeof (organicAcids));
        alimentaryFibers = temp.getAlimentaryFibers();
        file.write(reinterpret_cast<char*>(&alimentaryFibers), sizeof (alimentaryFibers));
        weight = temp.getWeight();
        file.write(reinterpret_cast<char*>(&weight), sizeof (weight));
    }
    file.close();
}

void List::readFromFile(std::string fileName)
{
    deleteList();
    std::fstream file;
    file.open(fileName, std::ios::in | std::ios::binary);
    int amount;
    file.read(reinterpret_cast<char*>(&amount), sizeof(int));
    Dish temp;
    char buffer[50];
    std::string name;
    float fats, proteins, carbohydrates, organicAcids, alimentaryFibers, weight;
    int length;
    while(amount)
    {
        file.read(reinterpret_cast<char*>(&length), sizeof (int));
        file.read(reinterpret_cast<char*>(&buffer), length);
        name = buffer;
        temp.setName(name);
        file.read(reinterpret_cast<char*>(&fats), sizeof (fats));
        temp.changeFats(fats);
        file.read(reinterpret_cast<char*>(&proteins), sizeof (proteins));
        temp.changeProteins(proteins);
        file.read(reinterpret_cast<char*>(&carbohydrates), sizeof (carbohydrates));
        temp.changeCarbohydrates(carbohydrates);
        file.read(reinterpret_cast<char*>(&organicAcids), sizeof (organicAcids));
        temp.changeOrganicAcids(organicAcids);
        file.read(reinterpret_cast<char*>(&alimentaryFibers), sizeof (alimentaryFibers));
        temp.changeAlimentaryFibers(alimentaryFibers);
        file.read(reinterpret_cast<char*>(&weight), sizeof (weight));
        temp.setWeight(weight);
        addNode(temp);
       amount--;
    }
    file.close();
}