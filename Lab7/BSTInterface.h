#ifndef BST_INTERFACE_H
#define BST_INTERFACE_H

template <class T>
class BSTInterface {
public:
    virtual bool isEmpty() const = 0;
    virtual bool add(const T& newItem) = 0;
    virtual void removeItem(const T& delItem) = 0;
    virtual void clearTree() = 0;
    virtual bool contains(const T& findItem) const = 0;


    //TODO traversals
    virtual void inorderTraverse() const = 0;   //void visit(T&)
private:

};

#endif /* BST_INTERFACE_H */
