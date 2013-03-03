#include <iostream>

using namespace std;

class VertexBag {

private:
	int size;
	int lengthOfArray;
	int* bagArray;
	
	/* Where the last vertex is located */
	int counter;



public:
	/**
	*	Initalizes the Bag
	*/
	void create() {
		lengthOfArray = 16;
		bagArray = malloc(sizeof(int)*lengthOfArray);
		counter = -1;
		size = 0;
	}

	/**
	*	Returns the number of vertices in the bag
	*/
	int size() {
		return size;
	}

	void put(int vertex) {
		if (! exists(vertex)) {	
			bagArray[++counter] = vertex;
			size++;
		}
	}

	int get() {
		size--;
		return bagArray[counter--];
	}

	void join(VertexBag otherBag) {
		while (otherBag.size() != 0) {
			add(otherBag.get());
		}
	}

	void split(int numberOfBags){

	}

	bool exist(int vertex) {
		for (int i = 0; i < size; i++) {
			if (vertex == bagArray[i]) {
				return true;
			}
		}
		return false;
	}

	bool isEmpty(){
		return size() == 0;
	}

}