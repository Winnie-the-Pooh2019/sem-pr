#ifndef SEM_PR_VECTOR_H
#define SEM_PR_VECTOR_H

template<typename T>
class IVector {
public:
    virtual int length() = 0;

    virtual void add(T e) = 0;

    virtual void add(IVector<T>* list) = 0;

    virtual void add(T e, int to) = 0;

    virtual void clear() = 0;

    virtual bool contains(T e) = 0;

    virtual int indexOf(T e) = 0;

    virtual bool removeByIndex(int index) = 0;

    virtual bool remove(T e) = 0;

    virtual void removeAll(IVector<T>* list) = 0;

    virtual void copy(T* source, int size) = 0;

    virtual void copy(IVector<T>* source) = 0;

    virtual T& operator [] (int index) const = 0;
};

template<typename T>
class Vector : public IVector<T> {
    T* values;
    int size;
public:
    int capacity;

public:
    Vector() {
        size = 0;
        capacity = 0;

        values = nullptr;
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

    Vector(IVector<T>* source) {
        this->size = source->length();
        capacity = size * 1.5;

        values = new T[capacity];
        copy(source);
    }

    int length() override {
        return size;
    }

    void add(T e) override {
        if (size == capacity)
            resize();

        values[size] = e;
        size++;
    }

    void add(IVector<T>* list) override {
        for (int i = 0; i < list->length(); i++)
            add((*list)[i]);
    }

    void add(T e, int to) override {
        if (size == capacity)
            resize();

        if (!shift(to))
            return;

        values[to] = e;
        size++;
    }

    void clear() override {
        size = 0;
    }

    bool contains(T e) override {
        for (int i = 0; i < size; i++) {
            if (values[i] == e)
                return true;
        }

        return false;
    }

    int indexOf(T e) override {
        for (int i = 0; i < size; i++) {
            if (values[i] == e)
                return i;
        }

        return -1;
    }

    bool removeByIndex(int index) override {
        if (index < 0 || index >= size)
            return false;

        return shift(index, -1);
    }

    bool remove(T e) override {
        int index = indexOf(e);

        if (index < 0 || index >= size)
            return false;

        shift(index, -1);

        return true;
    }

    void removeAll(IVector<T>* list) override {
        for (int i = 0; i < list->length(); i++) {
            int index = indexOf(list->operator[](i));

            if (index < 0 || index >= size)
                return;

            shift(index, -1);
        }
    }

    void fit() {
        if (capacity <= size * 1.5)
            return;

        capacity = size * 1.5;
        T* newValues = new T[capacity];
        for (int i = 0; i < size; i++)
            newValues[i] = values[i];

        delete[] values;
        values = newValues;
    }

    T &operator[](int index) const override {
        return values[index];
    }

private:
    void copy(T* source, int size) override {
        for (int i = 0; i < size; i++)
            values[i] = source[i];
    }

    void copy(IVector<T>* source) override {
        for (int i = 0; i < source->length(); i++)
            values[i] = (*source)[i];
    }

    void resize(int newSize) {
        int newCapacity = newSize * 1.5;
        T* newValues = new T[newCapacity];

        for (int i = 0; i < size && i < newSize; i++)
            newValues[i] = values[i];

        size = newSize;
        capacity = newCapacity;
        delete[] values;
        values = newValues;
    }

    void resize() {
        capacity = (capacity == 0) ? 1 : capacity * 2;

        T* newValues = new T[capacity];

        for (int i = 0; i < size; i++)
            newValues[i] = values[i];

        delete[] values;
        values = newValues;
    }

    bool shift(int from, int count = 1) {
        if (count + size <= 0 || size + count > capacity)
            return false;

        if (count >= 0) {
            for (int i = size - count - 1; i >= from; i--)
                values[count + i] = values[i];
        } else {
            for (int i = from; i < size; i++)
                values[i] = values[i - count];
        }

        return true;
    }
};

#endif //SEM_PR_VECTOR_H
