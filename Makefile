CXX=g++
CXXFLAGS= -Wall -Wextra -pedantic -Werror -std=c++17 -g

all:  test_hforest

test_hforest: test_hforest.o hforest.o htree.o
	$(CXX) $(CXXFLAGS) -o test_hforest test_hforest.o hforest.o htree.o

test_hforest.o: test_hforest.cc hforest.hh
	$(CXX) $(CXXFLAGS) -c test_hforest.cc

hforest.o: hforest.cc hforest.hh
	$(CXX) $(CXXFLAGS) -c hforest.cc

htree.o: htree.cc htree.hh
	$(CXX) $(CXXFLAGS) -c htree.cc

clean:
	rm -rf *.o test_hforest
