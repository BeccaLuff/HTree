#include "hforest.hh"

bool compare_trees(HTree::tree_ptr_t t1, HTree::tree_ptr_t t2){
return t1->get_value() < t2->get_value();
}

//Constructs a Forest of size 0
HForest::HForest(){
    std::vector<HTree::tree_ptr_t> trees_ {};
}

HForest::~HForest(){}

int HForest::size() const{return trees_.size();}

void HForest::add_tree(HTree::tree_ptr_t tree){trees_.push_back(tree);} //Adds tree to back of vector

HTree::tree_ptr_t HForest::pop_tree(){
    std::make_heap(trees_.begin(),trees_.end(),compare_trees); //Orders trees
    std::pop_heap(trees_.begin(),trees_.end(),compare_trees); // moves largest tree to back
    HTree::tree_ptr_t largestTree = trees_.back();           // Saves a pointer to largest tree
    trees_.pop_back();                                       // Actually removes the tree
    return largestTree;
}
