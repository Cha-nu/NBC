#pragma once
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

struct Item
{
    string name_;
    int price_;

    Item() : name_(""), price_(0) {}
    Item(const string& name, int price) : name_(name), price_(price) {}

    int getPrice() const { return price_; }
    void PrintInfo() const {
        cout << "[이름: " << name_ << ", 가격: " << price_ << "G] \n";
    }
};


template <typename T>
class Inventory { 
public: 
    Inventory(int capacity);
    ~Inventory();

    void AddItem(const T& item);
    void RemoveLastItem();
    void PrintAllItems();
    int GetSize() const;
    int GetCapacity() const;

    // 도전
    Inventory(const Inventory<T>& other);
    void Assign(const Inventory<T>& other);
    void Resize(int newCapacity);
    bool CompareItemsByPrice(const Item& a, const Item& b) const;
    void SortItems();

private:
    T* pItems_;
    int capacity_;
    int size_;
};

template <typename T>
inline Inventory<T>::Inventory(int capacity) : capacity_(capacity), size_(0) {
    pItems_ = new T[capacity_];
}

template <typename T>
inline Inventory<T>::Inventory(const Inventory<T> &other)
{
    capacity_ = other.capacity_;
    size_ = other.size_;
    pItems_ = new T[capacity_];
    for (int i = 0; i < size_; ++i) {
        pItems_[i] = other.pItems_[i];
    }
    cout << "인벤토리 복사 완료" << endl;
}

template <typename T>
inline void Inventory<T>::Assign(const Inventory<T> &other)
{
    if (this != &other) {
        delete[] pItems_;
        capacity_ = other.capacity_;
        size_ = other.size_;
        pItems_ = new T[capacity_];
        for (int i = 0; i < size_; ++i) {
            pItems_[i] = other.pItems_[i];
        }
    }
        cout << "인벤토리 할당 완료" << endl;
}

template <typename T>
inline void Inventory<T>::Resize(int newCapacity)
{
    if (newCapacity <= capacity_) {
        cout << "Resize 오류" << endl;
        return;
    }
    T* newItems = new T[newCapacity];
    for (int i = 0; i < size_; ++i) {
        newItems[i] = pItems_[i];
    }
    delete[] pItems_;
    pItems_ = newItems;
    capacity_ = newCapacity;
    cout << "인벤토리 크기 확장 완료 (현재 용량: " << capacity_ << ")" << endl;
}

template <typename T>
inline bool Inventory<T>::CompareItemsByPrice(const Item &a, const Item &b) const
{
    return a.price_ < b.price_;
}

template <typename T>
inline void Inventory<T>::SortItems()
{
    sort(pItems_, pItems_ + size_, [this](const T& a, const T& b) {
        return compareItemsByPrice(a, b);
    });
    cout << "인벤토리 아이템 정렬 완료" << endl;
}

template <typename T>
inline Inventory<T>::~Inventory()
{
    delete[] pItems_;
}

template <typename T>
inline void Inventory<T>::AddItem(const T& item)
{
    if(size_ >= capacity_)
    {
        this->Resize(capacity_ * 2);
    }
    pItems_[size_++] = item;
}

template <typename T>
inline void Inventory<T>::RemoveLastItem()
{
    if(size_ <= 0)
    {
        cout << "인벤토리가 비어있습니다." << endl;
    }
    else
    {
        --size_;
        cout << "아이템 제거 완료" << endl;
    }
}

template <typename T>
inline void Inventory<T>::PrintAllItems()
{
    if(size_ <= 0)
    {
        cout << "인벤토리가 비어있습니다." << endl;
        return;
    }
    for(int i = 0; i < size_; i++)
    {
        cout << "아이템 " << i + 1 << ": ";
        pItems_[i].PrintInfo();
    }
}

template <typename T>
inline int Inventory<T>::GetSize() const
{
    return size_;
}

template <typename T>
inline int Inventory<T>::GetCapacity() const
{
    return capacity_;
}
