#ifndef SEM_PR_VECTOR_H
#define SEM_PR_VECTOR_H

template<typename T>
class IVector {
    virtual bool add(T e) = 0;

    virtual bool add(IVector<T> list) = 0;

    virtual bool add(T e, int to) = 0;

    virtual void clear() = 0;

    virtual bool contains(T e) = 0;

    virtual int indexOf(T e) = 0;

    virtual T remove(int index) = 0;

    virtual bool remove(T e) = 0;

    virtual bool remove(IVector<T> list) = 0;
};

#endif //SEM_PR_VECTOR_H
