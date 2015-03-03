#include <cstdlib>
#include <iostream>

using namespace std;

class Item {
	public:
	int price;
	int weight;
	
	Item() {
		price = 0;
		weight = 0;
	}
};

class Bag {
	public:
	int capacity;
};

int find_max(Item * items, int item_count, int weight, int * the_array) {
	
}

int main() {
	int num_of_cases = 0;
	int num_of_items = 0;
	int num_of_bags = 0;
	int input = 0;
	int result = 0;
	int total = 0;
	
	Item * item_array;
	Bag * bag_array;
	int * the_array;
	
	cin >> num_of_cases;
	cin.ignore();
	
	while (num_of_cases-- != 0) {
		cin >> num_of_items;
		
		item_array = new Item[num_of_items];
		
		for (int i = 0; i < num_of_items; i++) {
			cin >> input;
			cin.ignore();
			item_array[i].price = input;
			cin >> input;
			cin.ignore();
			item_array[i].weight = input;
		} // end item loop
		
		cin >> num_of_bags;
		cin.ignore();
		
		bag_array = new Bag[num_of_bags];
		
		for (int i = 0; i < num_of_bags; i++) {
			cin >> input;
			cin.ignore();
			bag_array[i].capacity = input;
		} // end bag loop
		
		total = 0;
		for (int i = 0; i < num_of_bags; i++) {
			the_array = new int[num_of_items * bag_array[i].capacity];
			result = find_max(item_array, num_of_items, bag_array[i].capacity, the_array);
			total += result;
		} // end find_max loop
		
				
	}; // end large while loop
} // end int main