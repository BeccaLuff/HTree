#include "htree.hh"
#include <assert.h>
#include <iostream>

void test0(){ //test tree in HW6
    auto leaf1(std::make_shared<const HTree>(9,0,nullptr,nullptr));
    auto leaf2(std::make_shared<const HTree>(3,0,nullptr,nullptr));
    auto leaf3(std::make_shared<const HTree>(12,0,nullptr,nullptr));
    auto leaf4(std::make_shared<const HTree>(6,0,leaf1,nullptr));
    auto leaf5(std::make_shared<const HTree>(-5,0,leaf3,leaf4));
    auto leaf6(std::make_shared<const HTree>(12,0,leaf2,nullptr));
    HTree tree(126,0,leaf5,leaf6);
    
    assert(tree.get_child(HTree::Direction::LEFT) == leaf5);
    assert(tree.get_child(HTree::Direction::RIGHT) == leaf6);
    assert((*leaf6).get_child(HTree::Direction::LEFT) == leaf2);
    assert((*leaf6).get_child(HTree::Direction::RIGHT) == nullptr);
    assert((*leaf3).get_child(HTree::Direction::RIGHT) == nullptr);
    assert((*leaf3).get_child(HTree::Direction::LEFT) == nullptr);
    
    assert(toString(tree.path_to(126)) == "");
    assert(toString(tree.path_to(-5)) == "L");
    assert(toString(tree.path_to(12)) == "LL");
    assert(toString(tree.path_to(3)) == "RL");
    assert(toString(tree.path_to(9)) == "LRL");
    
    std::cout<<"Correct"<<std::endl;
}

//Tree with 1 leafs :(
void test1(){
    HTree tree(1, 0);
    
    assert(tree.get_child(HTree::Direction::LEFT) == nullptr);
    assert(tree.get_child(HTree::Direction::RIGHT) == nullptr);
    
    assert(toString(tree.path_to(1)) == "");
    
    std::cout<<"Correct"<<std::endl;
    
}

//test tree in HW 6 but with all the same value
void test2(){
    auto leaf1(std::make_shared<const HTree>(1,0,nullptr,nullptr));
    auto leaf2(std::make_shared<const HTree>(1,0,nullptr,nullptr));
    auto leaf3(std::make_shared<const HTree>(1,0,nullptr,nullptr));
    auto leaf4(std::make_shared<const HTree>(1,0,leaf1,nullptr));
    auto leaf5(std::make_shared<const HTree>(1,0,leaf3,leaf4));
    auto leaf6(std::make_shared<const HTree>(1,0,leaf2,nullptr));
    HTree tree(1,0,leaf5,leaf6);
    //get_child already tested on same form of tree
    
    assert(toString(tree.path_to(1)) == "LL");
   
    std::cout<<"Correct"<<std::endl;
}
int main(){
    test0();
    test1();
    test2();
}
