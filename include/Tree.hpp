#pragma once
#include <memory>
#include <vector>
#include <stack>
#include <algorithm>

template <typename T>
class Tree;

template <typename T>
class TreeIterator
{
    std::stack<Tree<T> *> stack;

public:
    TreeIterator(Tree<T> &root);
    TreeIterator();

    TreeIterator &operator++();   //prefix
    TreeIterator operator++(int); //postfix

    T &operator*();

    bool operator!=(const TreeIterator& other);
};

template <typename T>
class Tree
{
    T value;
    std::vector<std::unique_ptr<Tree<T>>> children;

public:
    Tree(T value);

    void addChild(T leaf);

    void addChild(std::unique_ptr<Tree> subTree);

    const Tree & operator[](std::size_t indx) const noexcept;
    Tree & operator[](std::size_t indx) noexcept;

    void removeChild(std::size_t indx);

    bool isLeaf() const noexcept;

    T &getValue();
    const T &getValue() const;

    void setValue(const T &v);

    std::size_t countChildren() const;

    TreeIterator<T> begin();
    TreeIterator<T> end();

};

template <typename T>
TreeIterator<T>::TreeIterator(Tree<T> &root)
{
    stack.push(&root);
}

template <typename T>
TreeIterator<T>::TreeIterator(){}

template <typename T>
TreeIterator<T> &TreeIterator<T>::operator++()
{
    Tree<T>& root = *stack.top();
    stack.pop();
    for (int i = root.countChildren() - 1; i >= 0; --i)
    {
        stack.push(&root[i]);
    }
    return *this;
}

template <typename T>
TreeIterator<T> TreeIterator<T>::operator++(int)
{
    auto copy = *this;
    ++(*this);
    return copy;
}

template <typename T>
T &TreeIterator<T>::operator*()
{
    return stack.top()->getValue();
}

template<typename T>
bool TreeIterator<T>::operator!=(const TreeIterator& other)
{
    return stack.size() != 0;
}

template <typename T>
Tree<T>::Tree(T value) : value{value}
{}

template <typename T>
void Tree<T>::addChild(T leaf)
{
    children.push_back(std::make_unique<Tree<T>>(leaf));
}

template <typename T>
void Tree<T>::addChild(std::unique_ptr<Tree> subTree)
{
    children.push_back(std::move(subTree));
}

template <typename T>
const Tree<T> &Tree<T>::operator[](std::size_t indx) const noexcept
{
    return *children[indx];
}

template <typename T>
Tree<T> &Tree<T>::operator[](std::size_t indx) noexcept
{
    return *children[indx];
}

template <typename T>
void Tree<T>::removeChild(std::size_t indx)
{
    children.erase(children.begin() + indx);
}

template <typename T>
bool Tree<T>::isLeaf() const noexcept
{
    return children.size() == 0;
}

template <typename T>
T &Tree<T>::getValue()
{
    return value;
}

template <typename T>
const T &Tree<T>::getValue() const
{
    return value;
}

template <typename T>
void Tree<T>::setValue(const T &v)
{
    value = v;
}

template <typename T>
std::size_t Tree<T>::countChildren() const
{
    return children.size();
}

template <typename T>
TreeIterator<T> Tree<T>::begin()
{
    return TreeIterator(*this);
}

template <typename T>
TreeIterator<T> Tree<T>::end()
{
    return TreeIterator<T>();
}