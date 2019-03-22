//definition of tree.hh file. A simple recursive data structure to hold keys and values.
#include "htree.hh"
#include <memory>
#include <list>
#include <iostream>
#include <assert.h>


// Initialize with a key and a value:
HTree::HTree(int key,
      uint64_t value,
      tree_ptr_t left,
      tree_ptr_t right){
        key_ = key;
        value_ = value;
        left_ = left;
        right_ = right;
}

//destroy tree
HTree::~HTree(){}

int HTree::get_key() const{  // Return key in current node
        return this -> key_;
}
uint64_t HTree::get_value() const{      // Return value in current node
        return this ->value_;
}

// Return the child of this node indicated by dir.
// If the child is nullptr (current node is a leaf), returns nullptr.
HTree::tree_ptr_t HTree::get_child(Direction dir) const{
    if(dir == Direction::LEFT)      return left_;
    if(dir == Direction::RIGHT)     return right_;
    return nullptr;
}

bool HTree::inTree(int key) const {
        if(key_ == key)      return true;
        
        if(left_ ){
                if(left_ ->inTree(key))    return left_ -> inTree(key);
        }
        if(right_){
                if(right_ ->inTree(key))    return right_ -> inTree(key);
        }
        return false;
}

HTree::path_t HTree::path_maker(int key, HTree::path_t path)const {
 if(inTree(key)){
        if(left_ && left_ -> inTree(key)){ 
            path.push_back(Direction::LEFT);
            return left_ -> path_maker(key, path);
        }
        else if(right_ && right_ -> inTree( key)){
            path.push_back(Direction::RIGHT);
            return right_ -> path_maker(key, path);
        }
        else if(key_ == key){
            return path;
        }
        return path;
    }

    else{std::cout << "not in tree" << std::endl; assert(false);}
}
// Return a list of directions from root to a node of a given key.
// Crashes (with an assert) if key not contained in this tree
HTree::path_t HTree::path_to(int key) const{
    HTree::path_t path = {};
    path = path_maker(key, path);
    return path;
}

std::string toString(HTree::path_t path){
    std::string pathStr = "";
    for(auto i : path){
        if( i == HTree::Direction::LEFT){    
            pathStr += "L";
        }
        if( i == HTree::Direction::RIGHT){
            pathStr += "R";
        }   
    }
    return pathStr;
}

