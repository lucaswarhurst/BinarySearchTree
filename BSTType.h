///////////////////////////////////////////////////////////////////////////////
//Lucas Warhurst
//Program 4
//Due: 11/01/2019
// This .h file contains all the functions needed for a binary search tree that will be used for the .cpp file
///////////////////////////////////////////////////////////////////////////////



#ifndef BSTTYPE__H
#define BSTTYPE__H



#include "BTNodeType.h"
#include <iostream>

enum TravType {PRE,POST,IN};

template <class T>
class BSTType {
public:
    BSTType();
    BSTType (const BSTType<T>&);
    const BSTType<T>& operator =(const BSTType<T>&);
    ~BSTType();
    bool empty() const;
    void erase (const T&);
    bool find (const T&) const;
    void insert (const T&);
    size_t size() const;
    void traverse (std::ostream&, TravType) const;
protected:
    BTNodeType<T> *root;
    size_t count;
private:
    void copy(BTNodeType<T>*&, BTNodeType<T>*);
    void destroy(BTNodeType<T>*&);
    void erase (const T&, BTNodeType<T>*&);
    bool find (const T&, BTNodeType<T>*) const;
    void inorder (std::ostream&, BTNodeType<T>*) const;
    void postorder (std::ostream&, BTNodeType<T>*) const;
    void preorder (std::ostream&, BTNodeType<T>*) const;
    void insert (const T&, BTNodeType<T>*&);
    const T& predecessor (BTNodeType<T>*);
};


///////////////////////////////////////////////////////////////////////////////
//Function BSTType()
//Description: this makes the root for the search tree.
//PreConditions: a tree needs to be created
//Postconditions: the root, end, of the tree is created
///////////////////////////////////////////////////////////////////////////////

template <class T>
BSTType<T>::BSTType() {
    root=nullptr;
    count=0;
}

///////////////////////////////////////////////////////////////////////////////
//Function:BsTType(const Bsttype<T>& src)
//Description: this calls the copy function that's public
//Preconditions: source is created.
//Postconditions: the source and the count is copied.
///////////////////////////////////////////////////////////////////////////////

template <class T>
BSTType<T>::BSTType(const BSTType<T>& src) {
    copy(root, src.root);
    count=src.count;
}

////////////////////////////////////////////////////////////////////////////////
//BSTType<T>& BSTTYPE<T>::operator=(const BSTType<T>)
//Description: this copies the new source.
//Preconditions: Destroy, copy, and source needs to be created
//Postconditions: the oold source is destroyed and source is copied
///////////////////////////////////////////////////////////////////////////////

template <class T>
const BSTType<T>&  BSTType<T>::operator=(const BSTType<T>& source) {
    if(this!= source) {
        destroy();
        copy(source);
        count=source.count;
    }
}

///////////////////////////////////////////////////////////////////////////////
//function: ~BSTType()
//description: the destroy function is called
//Preconditions: There needs to be a tree that exists
//Postconditions: an item is destroyed
///////////////////////////////////////////////////////////////////////////////

template <class T>
BSTType<T>::~BSTType() {
    destroy(this->root);
}

///////////////////////////////////////////////////////////////////////////////
//function: empty() const
//description: checks to see if the tree is empty
//Preconditions: a tree must exist
//Postconditions: if the tree is empty then it will show it being empty.
///////////////////////////////////////////////////////////////////////////////

template <class T>
bool BSTType<T>::empty() const {
    return root==nullptr;
}

///////////////////////////////////////////////////////////////////////////////
//Function: erase(const T&)
//Description: the item from the root is erased
//Precondtions: there needs to be an item in the root
//Postcondtions: the item is erased
///////////////////////////////////////////////////////////////////////////////

template <class T>
void BSTType<T>::erase(const T& item) {
    erase(item,root);
}

///////////////////////////////////////////////////////////////////////////////
//function: find(const T&) const
//Description: this function searches for an item in the root
//Preconditions: there needs to be a value in the root
//Postconditions: if the item is found then it will be reported back
///////////////////////////////////////////////////////////////////////////////

template <class T>
bool BSTType<T>::find(const T& item) const {
    return find(item,root);
}

///////////////////////////////////////////////////////////////////////////////
//function: insert (const T&)
//description: an item will be placed in the root
//Preconditions: there needs to be a tree
//Postconditions: an item will be placed in the root
///////////////////////////////////////////////////////////////////////////////

template <class T>
void  BSTType<T>::insert(const T& item) {
    insert(item,root);
}

///////////////////////////////////////////////////////////////////////////////
//function: size() const
//description: shows the count of the tree
//Precondtions: a tree will be recommended
//Postconditions: the count will be returned.
///////////////////////////////////////////////////////////////////////////////


template <class T>
size_t  BSTType<T>::size() const {
    return count;
}

///////////////////////////////////////////////////////////////////////////////
//function: BSTType<T>::traverse(std::ostream&, TravType) const
//description: switch is used to determine what order should be used
//Preconditions: a rree must exist, along with IN, PRE, POST functions
//Postcondititons: the right order is called.
///////////////////////////////////////////////////////////////////////////////


template <class T>
void BSTType<T>::traverse(std::ostream& out, TravType traverse) const {
    switch(traverse) {
    case PRE:
        preorder(out,root);
        break;

    case IN:
        inorder(out,root);
        break;

    case POST:
        postorder(out,root);
    }
}

///////////////////////////////////////////////////////////////////////////////
//function: copy(BTNodeType<T>*&, BTNodeType<T>*&)
//Description: copies the source tree into a new tree
//Preconditions: a source needs to exist
//Postconditions: the source tree is then copied into a new tree
///////////////////////////////////////////////////////////////////////////////

template <class T>
void BSTType<T>::copy(BTNodeType<T>*& node, BTNodeType<T>* source) {
    if(source!=nullptr) {
        node= new BTNodeType<T>;
        node->item=source->item;
        copy(node->left,source->left);
        copy(node->right,source->right);
    }
    else {
        node=nullptr;
    }
}

template <class T>
void BSTType<T>::destroy(BTNodeType<T>*& node) {
    if(node!=nullptr) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

///////////////////////////////////////////////////////////////////////////////
//function: erase (const T&, BTNodeType<T>*&)
//Description: erases an item
//Preconditions: item should be a parameter from the public
//Postconditions: the item is erased
///////////////////////////////////////////////////////////////////////////////

template <class T>
void BSTType<T>::erase(const T& item, BTNodeType<T>*& node) {

    if (node != nullptr) {
        if (item == node->item) {
            if (node->right == nullptr) {
                BTNodeType<T>* temp = node;
                node = node->left;
                delete temp;
                --count;
            }
            else if ( node->left == nullptr) {
                BTNodeType<T>* temp = node;
                node = node->right;
                delete temp;
                --count;
            }
            else {
                node->item= predecessor(node->left);
                erase(node->item, node->left);
            }
        }
        else if(item < node->item) {
            erase(item, node->left);
        }
        else {
            erase(item, node->right);
        }
    }
}

///////////////////////////////////////////////////////////////////////////////
//function: fine(const T&, BTNodeType<T>*) const
//description: searches for an item
//Preconditions: a tree must exist for the item to be found
//Postconditions: if the item is found then it will be reported back a true
///////////////////////////////////////////////////////////////////////////////

template <class T>
bool BSTType<T>::find(const T& item, BTNodeType<T>* node) const {
    if(node!=nullptr) {
        if(item==node->item) 
	    return true;
        
        else if(item<node->item) 
            return find(item,node->left);
        
        else 
	    return find(item,node->right);
        
    }
    
    return false;
    
}

///////////////////////////////////////////////////////////////////////////////
//inorder(std::ostream, BTNodeType<T>*) const
//description: outputs the tree inorder
//preconditions: there needs to be a tree created
//postconditions: the tree wil be outputted inorder.
///////////////////////////////////////////////////////////////////////////////
template <class T>
void BSTType<T>::inorder(std::ostream& out, BTNodeType<T>* node) const {
    if(node!=nullptr) {
        inorder(out,node->left);
        out << node->item << " ";
        inorder(out,node->right);
    }
}

///////////////////////////////////////////////////////////////////////////////
//function: insert(const T& BTNodeType<T>*&)
//description: the item will be inserted through a parameter
//Preconditions: there needs to be a tree so an item will be inserted
//Postcondititons: the item is now inserted.
///////////////////////////////////////////////////////////////////////////////

template <class T>
void BSTType<T>::insert(const T& item, BTNodeType<T>*& node) {
    if(node==nullptr) {
        node = new BTNodeType<T>;
        node->item=item;
        node->right=nullptr;
        node->left=nullptr;
        ++count;
    }
    else {
        if(item<node->item) {
            insert(item,node->left);
        }
        else if(item>node->item) {
            insert(item,node->right);
        }
    }
}

///////////////////////////////////////////////////////////////////////////////
//function: BSTType<T>::postorder(std::ostream&, BTNodeType<T>*) const
//description: an order how the tree will be outputted
//Preconditons: a tree must exist with items
//Postconditions: the tree will be outputted in a post order
///////////////////////////////////////////////////////////////////////////////

template <class T>
void BSTType<T>::postorder(std::ostream& out, BTNodeType<T>* node) const {
    if(node != nullptr) {
        postorder(out,node->left);
        postorder(out,node->right);
        out << node->item << " ";
    }
}

///////////////////////////////////////////////////////////////////////////////
//fucntion: const T& BSTType<T>::predecessor(BTNodeType<T>*)
//decription: finds the largest value along the left side of the tree
//Preconditons: there needs to be a tree
//Postconditions: the largest value is returned
///////////////////////////////////////////////////////////////////////////////

template <class T>
const T& BSTType<T>::predecessor(BTNodeType<T>* node) {
    while(node->right != nullptr) {
        node=node->right;
    }
    return node->item;
}

///////////////////////////////////////////////////////////////////////////////
//function:BSTType<T>::preorder(std::ostream&, BTNodeType<T>*) const
//decription: an order how the tree will be outputted
//Preconditions: a tree must exits with items
//Postconditions: the tree will be outputted in a pre order
///////////////////////////////////////////////////////////////////////////////

template <class T>
void BSTType<T>::preorder(std::ostream& out, BTNodeType<T>* node) const {
    if(node!=nullptr) {
        out << node->item << " ";
        preorder(out,node->left);
        preorder(out,node->right);
    }
}










#endif

