#ifndef SET_H
#define SET_H
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <typename T>
class Set
{
public:
    //default constructor
    Set(){
        maxCapacity = 8;
        arraySize = 0;
        array = new T[maxCapacity];
    }
    //copy constructor
    Set(const Set& other){
        this->arraySize = other.arraySize;
        this->maxCapacity = other.maxCapacity;
        this->array = new T[maxCapacity];

        for (int i = 0; i < arraySize; i++) {
            this->array[i] = other.array[i];
        }
    }
    //destructor
    ~Set() {
        delete array;
        cout << "deleting array" << endl;
    }
    //= operator
    Set operator=(const Set& other){
        this->arraySize = other.arraySize;
        this->maxCapacity = other.maxCapacity;
        T* temp = new T[maxCapacity];

        for (int i = 0; i < arraySize; i++) {
            temp[i] = other.array[i];
        }
        delete array;
        array = temp;
        return *this;
    }
    //returns a Set with all of the similarities between the two sets used as input
    Set<T> intersectionWith(const Set<T>& other) const{
        int tempCapacity = 8;
        if (this->maxCapacity >= other.maxCapacity)
            tempCapacity = this->maxCapacity;
        else
            tempCapacity = other.maxCapacity;

        T* tempArray = new T[tempCapacity];
        int tempIndex = 0;
        for (int i = 0; i < this->arraySize; i++){
            if(other.contains(this->array[i])){
                tempArray[tempIndex] = this->array[i];
                tempIndex += 1;
            }
        }
        Set<T> tempSet;
        delete tempSet.array;
        tempSet.array = tempArray;
        tempSet.arraySize = tempIndex;
        tempSet.maxCapacity = tempCapacity;

        return tempSet;

    }
    //adds an item to the given set if it isn't already there, and grows it if necessary
    void add(T item){
        int itemInArray = 0;
        if (arraySize == maxCapacity){
            maxCapacity = maxCapacity * 2;
            T* temp = new T[maxCapacity];

            for (int i = 0; i < this->arraySize; i++){
                temp[i] = this->array[i];

            }
            delete array;
            array = temp;
        }

        for (int i = 0; i < this->arraySize; i++){
            if (array[i] == item)
                itemInArray += 1;
        }

        if (itemInArray == 0) {
            array[arraySize] = item;
            arraySize += 1;
        }
    }
    //removes an item from the given set and compacts the array
    void remove(T item){
        int locationOfItem = 0;
        for (int i = 0; i < arraySize; i++){
            if (this->array[i] == item){
                locationOfItem = i;
            }
        }
        for (int x = locationOfItem; x < this->arraySize; x++){
            this->array[x] = this->array[x+1];
        }
        this->arraySize -= 1;
    }
    //sets the array size to 0
    void clear() {
        arraySize = 0;
    }
    //returns true if the two sets are equal and false if they are not
    bool operator==(const Set<T>& other) const{
        int arraySimilarities = 0;
        if (arraySize == other.arraySize){
            for (int i = 0; i < arraySize; i++){
                for (int j = 0; j < arraySize; j++){
                    if (this->array[i] ==  other.array[j]){
                        arraySimilarities += 1;
                    }
                }
            }
        }
        if (arraySimilarities == arraySize){
            return true;
        }else{
            return false;
        }

    }
    //returns true if the set contains the given item and false if not
    bool contains(T item) const{
        int containsItem = 0;
        for (int i = 0; i < arraySize; i++){
            if (array[i] == item)
                containsItem += 1;
        }
        if (containsItem > 0)
            return true;
        else
            return false;
    }
    //returns the array size
    int getSize() const{
        return arraySize;
    }
    //converts the set into a string and returns it
    string toString(){
        ostringstream temp;
        temp << "{";
        if (arraySize > 0){
            for (int i = 0; i < arraySize; i++){
                temp << array[i];
                if (i < arraySize - 1)
                    temp << ", ";
            }
        }
        temp << "}";
        return temp.str();
    }
    //removes the smallest item from the set
    T removeSmallest(){
        if(this->arraySize == 0){
            exit(0);
        }

        T theSmallest = this->array[0];
        int smallestAtLocation = 0;

        for (int i = 0; i < this->arraySize; i++){
            if (this->array[i] < theSmallest){
                theSmallest = this->array[i];
                smallestAtLocation = i;
            }
        }

        for (int x = smallestAtLocation; x < this->arraySize; x++){
            this->array[x] = this->array[x+1];
        }
        this->arraySize -= 1;

        return theSmallest;

    }

private:
    int maxCapacity;
    int arraySize;
    T* array;
};




#endif // SET_H
