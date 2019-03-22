//This program tests the hforrest class
#include "hforest.hh"
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

//trees of one with different root nodes
void testTrees0(){
    auto leaf1(std::make_shared<const HTree>(9,0,nullptr,nullptr));
    auto leaf2(std::make_shared<const HTree>(3,0,nullptr,nullptr));
    auto leaf3(std::make_shared<const HTree>(12,0,nullptr,nullptr));
    auto leaf4(std::make_shared<const HTree>(6,0,leaf1,nullptr));
    auto leaf5(std::make_shared<const HTree>(-5,0,leaf3,leaf4));
    auto leaf6(std::make_shared<const HTree>(12,0,leaf2,nullptr));
    auto tree0(std::make_shared<const HTree>(126,0,leaf5,leaf6));
    
    auto leaf11(std::make_shared<const HTree>(9,0,nullptr,nullptr));
    auto leaf22(std::make_shared<const HTree>(3,0,nullptr,nullptr));
    auto leaf33(std::make_shared<const HTree>(12,0,nullptr,nullptr));
    auto leaf44(std::make_shared<const HTree>(6,0,leaf11,nullptr));
    auto leaf55(std::make_shared<const HTree>(-5,0,leaf33,leaf44));
    auto leaf66(std::make_shared<const HTree>(12,0,leaf22,nullptr));
    auto tree1(std::make_shared<const HTree>(1,0,leaf55,leaf66));
    
    auto leaf111(std::make_shared<const HTree>(9,0,nullptr,nullptr));
    auto leaf222(std::make_shared<const HTree>(3,0,nullptr,nullptr));
    auto leaf333(std::make_shared<const HTree>(12,0,nullptr,nullptr));
    auto leaf444(std::make_shared<const HTree>(6,0,leaf111,nullptr));
    auto leaf555(std::make_shared<const HTree>(-5,0,leaf333,leaf444));
    auto leaf666(std::make_shared<const HTree>(12,0,leaf222,nullptr));
    auto tree2(std::make_shared<const HTree>(200,0,leaf555,leaf666));
    
    HForest hforrest_;
    
    assert(hforrest_.size() == 0);
    
    hforrest_.add_tree(tree0);
    hforrest_.add_tree(tree1);
    hforrest_.add_tree(tree2);

    assert(hforrest_.size() == 3);

    assert(hforrest_.pop_tree() == tree2);
    assert(hforrest_.size() == 2);
    assert(hforrest_.pop_tree() == tree0);
    assert(hforrest_.size() == 1);
    assert(hforrest_.pop_tree() == tree1);
    assert(hforrest_.size() == 0);

    std::cout << "Correct" << std::endl;	
}

void testTrees1(){
    auto tree0(std::make_shared<const HTree>(5, 0, nullptr, nullptr));

    auto leaf1(std::make_shared<const HTree>(1,0,nullptr,nullptr));
    auto leaf2(std::make_shared<const HTree>(1,0,nullptr,nullptr));
    auto leaf3(std::make_shared<const HTree>(1,0,nullptr,nullptr));
    auto leaf4(std::make_shared<const HTree>(1,0,leaf1,nullptr));
    auto leaf5(std::make_shared<const HTree>(1,0,leaf3,leaf4));
    auto leaf6(std::make_shared<const HTree>(1,0,leaf2,nullptr));
    auto tree1(std::make_shared<const HTree>(1,0,leaf5,leaf6));

    auto leaf11(std::make_shared<const HTree>(3,0,nullptr,nullptr));
    auto leaf22(std::make_shared<const HTree>(19,0,nullptr,nullptr));
    auto leaf33(std::make_shared<const HTree>(400,0,nullptr,nullptr));
    auto leaf44(std::make_shared<const HTree>(5,0,leaf11,nullptr));
    auto leaf55(std::make_shared<const HTree>(6,0,leaf33,leaf44));
    auto leaf66(std::make_shared<const HTree>(9,0,leaf2,nullptr));
    auto tree2(std::make_shared<const HTree>(10,0,leaf55,leaf66));    
    
    HForest hforrest_;
    //add trees to forrest in different orders to ensure order does not change result
    hforrest_.add_tree(tree0);
    assert(hforrest_.size() == 1);
    hforrest_.add_tree(tree2);
    assert(hforrest_.size() == 2);
    hforrest_.add_tree(tree1);
    assert(hforrest_.size() == 3);

    assert(hforrest_.pop_tree() == tree2);
    assert(hforrest_.pop_tree() == tree0);
    assert(hforrest_.pop_tree() == tree1);

    hforrest_.add_tree(tree0);
    hforrest_.add_tree(tree1);
    hforrest_.add_tree(tree2);

    assert(hforrest_.pop_tree() == tree2);
    assert(hforrest_.pop_tree() == tree0);
    assert(hforrest_.pop_tree() == tree1);


    hforrest_.add_tree(tree1);
    hforrest_.add_tree(tree0);
    hforrest_.add_tree(tree2);

    assert(hforrest_.pop_tree() == tree2);
    assert(hforrest_.pop_tree() == tree0);
    assert(hforrest_.pop_tree() == tree1);

    std::cout << "Correct" << std::endl;
}

int main(){
    test0();
    test1();
    test2();
    testTrees0();
    testTrees1();
    return 0;
}
