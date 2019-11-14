#ifndef BST_H
#define BST_H

#include <cstddef>
#include <algorithm>
#include <iostream>
#include <functional>

template <class T>
struct node
{
    T data;
    node<T> *lLink, *rLink;
};



template <class T>
class BST{
    //typedef void (*Callback)(const T &t);
    using Callback = std::function<void(const T& t)>; //void(*)(const T& t);
private:
    void copyTree(node<T>* &copyRoot, node<T>* otherRoot);
    void inOrder(node<T> *p, Callback c) const;
    //void inOrder(node<T> *p) const;
    void preOrder(node<T> *p) const;
    void postOrder(node<T> *p) const;
    void destroy(node<T>* &p);
    node<T>* nodeInsert(node<T>* newNode, node<T>* parentNode);
    bool searchTree(node<T>* searchNode ,const T& searchItem) const;

    node<T> *root;

public:
    BST(const BST<T>& otherTree);
    BST();
    ~BST();

    node<T>* returnNode(node<T> *p);
    const BST<T>& operator=(const BST<T>&);
    /**
    * @brief  traverses with in order through the tree using callback function pointer
    *
    * @param function pointer of BST type
    */
    void inOrderTraversal(Callback c) const;
    //void inOrderTraversal() const;
    /**
    * @brief  traverses with pre order through the tree
    */
    void preOrderTraversal() const;
    /**
    * @brief  traverses with post order through the tree
    */
	void postOrderTraversal() const;
	/**
    * @brief  clears and removes the tree
    */
	void removeTree();
	/**
    * @brief  searches the tree for BST type input
    *
    * @param BST type input
    */
	bool searchTree(const T& searchItem) const;
	/**
    * @brief  inputs data into the tree of BST type input
    *
    * @param BST type input
    */
	void nodeInsert(const T& insertItem);
};

template <class T>
BST<T>::BST()
{
    root = nullptr;
}

template <class T>
BST<T>::BST(const BST<T>& otherTree)
{
    if (otherTree.root == nullptr){
        root = nullptr;
    } else {
        copyTree(root, otherTree.root);
    }
}

template <class T>
BST<T>::~BST()
{
    destroy(root);
}

template <class T>
const BST<T>& BST<T>::operator=(const BST<T>& otherTree){
    if (this != &otherTree){
        if(root != nullptr){
            destroy(root);
        }
        if(otherTree.root == nullptr){
            root = nullptr;
        } else {
            copyTree(root, otherTree.root);
        }
    }
    return *this;
}

//template <class T>
//void BST<T>::inOrderTraversal() const
//{
//    inOrder(root);
//}

template <class T>
void BST<T>::preOrderTraversal() const
{
    preOrder(root);
}

template <class T>
void BST<T>::postOrderTraversal() const
{
    postOrder(root);
}

template <class T>
void BST<T>::copyTree(node<T>* &copyRoot, node<T>* otherRoot){
    if(otherRoot == nullptr){
        copyRoot = nullptr;
    } else {
        copyRoot = new node<T>;
        copyRoot->data = otherRoot->data;
        copyTree(copyRoot->lLink, otherRoot->lLink);
        copyTree(copyRoot->rLink, otherRoot->rLink);
    }
}

//template <class T>
//void BST<T>::inOrder(node<T> *p) const
//{
//    if (p != nullptr)
//    {
//        inOrder(p->lLink);
//        std::cout << p->data << " ";
//        inOrder(p->rLink);
//    }
//}

template <class T>
void BST<T>::preOrder(node<T> *p) const
{
    if (p != nullptr)
    {
        std::cout << p->data << " ";
        preOrder(p->lLink);
        preOrder(p->rLink);
    }
}

template <class T>
void BST<T>::postOrder(node<T> *p) const
{
    if (p != nullptr)
    {
        postOrder(p->lLink);
        postOrder(p->rLink);
        std::cout << p->data << " ";
    }
}

template <class T>
bool BST<T>::searchTree(const T& searchItem) const
{
    bool found;
    found = false;
    if (root == nullptr){
        std::cout << "No data has been read." << std::endl;
    } else {
        if(root->data == searchItem){
            found = true;
        }
        else if(root->data > searchItem){
            return searchTree(root->lLink, searchItem);
        }
        else{
            return searchTree(root->rLink, searchItem);
        }
    }
    return found;
}

template <class T>
bool BST<T>::searchTree(node<T>* searchNode, const T& searchItem) const
{
    bool found;
    found = false;
    if (searchNode == nullptr){
        found = false;
    } else {
        if(searchNode->data == searchItem){
            found = true;
        }
        else if(searchNode->data > searchItem){
            return searchTree(searchNode->lLink, searchItem);
        }
        else{
            return searchTree(searchNode->rLink, searchItem);
        }
    }
    return found;
}

template <class T>
void BST<T>::nodeInsert(const T& insertItem)
{
    node<T> *newNode;
    newNode = new node<T>;
    newNode->data = insertItem;
    newNode->lLink = nullptr;
    newNode->rLink = nullptr;

    if (root == nullptr){
        root = newNode;
    } else {
        nodeInsert(newNode, root);
    }
}

template <class T>
node<T>* BST<T>::nodeInsert(node<T>* newNode, node<T>* parentNode)
{
    if(newNode->data < parentNode->data){
        if(parentNode->lLink == nullptr){
            parentNode->lLink = newNode;
        } else {
            nodeInsert(newNode, parentNode->lLink);
        }
    }
    else if(newNode->data > parentNode->data) {
        if(parentNode->rLink == nullptr){
            parentNode->rLink = newNode;
        } else {
            nodeInsert(newNode, parentNode->rLink);
        }
    } else {
        std::cout << "Duplicate data found" << std::endl;
    }
}
template <class T>
void BST<T>::destroy(node<T>* &p)
{
    if (p != nullptr){
        destroy(p->lLink);
        destroy(p->rLink);
        delete p;
        p = nullptr;
    }
}

template <class T>
void BST<T>::removeTree()
{
    destroy(root);
}

template <class T>
void BST<T>::inOrderTraversal(Callback c) const {
	return inOrder(root, c);
}

template <class T>
void BST<T>::inOrder(node<T> *p, Callback c) const {
	if (p != nullptr)
    {
        inOrder(p->lLink, c);
        c(p->data);
        inOrder(p->rLink, c);
    }
}

#endif // BST_H
