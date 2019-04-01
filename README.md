# HTree and HForest

Imeplemting of HTree and HForest classes.
HTree is a class to represent a tree node with two values: a key and a value
HForest is a collection of independent HTrees where each HTree in the collection is the root of its own tree.

## Getting Started

Download the HTree files, Unzip it and place it somewhere easy to get to from your terminal

### Prerequisites

An basic understanding of using terminal

### Installing and Building

#Download the files, use make file to compile, run test_hforest (tests HTrees as well)

## Design Choices
The majority of design choices in HForest are self explanatory; however, two functions need more discussion,
specifically the add_tree and pop_tree functions. Instead of doing make_heap with the comparison in pop_heap,
we used push_heap with the comparison after adding the tree in add_tree to create the heap in descending order. 
This simplifies the pop_tree functions so one does not need to make a heap and pop from the heap. We did this 
because we couldn't get make_heap to work as expected. 
The majority of HTree is just revisions from the previous tree with a key difference. The path_to function is 
drastically simplified by using a helper function that can take the current path so the function can be called 
recursively. 



## Authors

* **Becca Luff** - *Initial work* - [BeccaLuff](https://github.com/BeccaLuff)
* **Devin Arrants** - *Initial work* - [DevinArrants](https://github.com/DevinArrants)


