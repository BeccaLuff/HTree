CXX=g++
CXXFLAGS= -Wall -Wextra -pedantic -Werror -std=c++17 -g

all:  test_htree

test_tree: test_htree.o htree.o
	$(CXX) $(CXXFLAGS) -o test_htree test_htree.o htree.o

test_tree.o: htest_tree.cc htree.hh
	$(CXX) $(CXXFLAGS) -c test_htree.cc

htree.o: htree.cc htree.hh
	$(CXX) $(CXXFLAGS) -c htree.cc

clean:
	rm -rf *.o test_htree
