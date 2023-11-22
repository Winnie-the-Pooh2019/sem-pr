#ifndef SEM_PR_VECTOR_H
#define SEM_PR_VECTOR_H

template<typename T>
class IVector {
    virtual int size() = 0;

    virtual bool add(T e) = 0;

    virtual bool add(IVector<T> list) = 0;

    virtual bool add(T e, int to) = 0;

    virtual void clear() = 0;

    virtual bool contains(T e) = 0;

    virtual int indexOf(T e) = 0;

    virtual T remove(int index) = 0;

    virtual bool remove(T e) = 0;

    virtual bool remove(IVector<T> list) = 0;

    virtual void copy(T* source, int size) = 0;

    virtual void copy(IVector<T> source) = 0;

    virtual T& operator [] (int index) const = 0;
};

template<typename T>
class Vector : IVector<T> {
    T* values;
    int size;
    int capacity;

public:
    Vector() {
        size = 1;
        capacity = 1;

        values = new T[capacity];
    }

    Vector(int size) {
        this->size = size;
        capacity = size * 1.5;

        values = new T[capacity];
    }

    Vector(T* source, int size) {
        this->size = size;
        capacity = size * 1.5;

        values = new T[capacity];
        copy(source, size);
    }

    Vector(IVector<T> source) {
        this->size = source.size();
        capacity = size * 1.5;

        values = new T[capacity];
        copy(source);
    }

    bool add(T e) override {
        if (size == capacity)
            resize(size * 1.5);

        values[size + 1] = e;
        size *= 1.5;

        return false;
    }

    bool add(IVector<T> list) override {
        if (size + list.size() >= capacity)
            resize(size + list.size());

        for (int i = size; i < size + list.size(); i++)
            values[i] = list[i];

        size += list.size();

        return false;
    }

    bool add(T e, int to) override {
        return false;
    }

    void clear() override {

    }

    bool contains(T e) override {
        return false;
    }

    int indexOf(T e) override {
        return 0;
    }

    T remove(int index) override {
        return nullptr;
    }

    bool remove(T e) override {
        return false;
    }

    bool remove(IVector<T> list) override {
        return false;
    }

    T &operator[](int index) const override {
        return <#initializer#>;
    }

private:
    void copy(T* source, int size) override {
        for (int i = 0; i < size; i++)
            values[i] = source[i];
    }

    void copy(IVector<T> source) override {
        for (int i = 0; i < source.size(); i++)
            values[i] = source[i];
    }

    void resize(int newSize) {
        int newCapacity = newSize;
        T* newValues = new T[newCapacity];

        for (int i = 0; i < size && i < newSize; i++)
            newValues[i] = values[i];

        size = newSize;
        capacity = newSize * 1.5;
        delete[] values;
        values = newValues;
    }
};

#endif //SEM_PR_VECTOR_H
