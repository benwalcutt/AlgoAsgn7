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

void sort_items(Item * items, int item_count) {
	int temp = 0;
	for (int i = 0; i < item_count; i++) {
		for (int j = 1; j < item_count; j++) {
			if (items[j].weight < items[i].weight) {
				temp = items[i].price;
				items[i].price = items[j].price;
				items[j].price = temp;
				
				temp = items[i].weight;
				items[i].weight = items[j].weight;
				items[j].weight = temp;
			}
		}
	}
}

int find_max(Item * items, int item_count, int weight, int * the_array) {
	int oldv = 0;
	int newv = 0;
	int max = 0;
	for (int i = 0; i <= item_count; i++) {
		for (int j = 0; j <= weight; j++) {
			if (i == 0) {
				the_array[(i*weight) + j] = 0;
			} // end the i = 0 top part of the table
			else if (j == 0) {
				the_array[(i*weight + 1)] = 0;
			} // end of the j = 0 which sets all to 0 because a 0 bag cant take any weight
			else if (items[i].weight > j) {
				the_array[(i*weight + 1) + j] = the_array[((i-1)*weight + 1) + j];
			}
			else if (items[i].weight == j) {
				oldv = the_array[((i-1)*weight + 1) + j];
				newv = items[i].price;
				max = oldv > newv ? oldv : newv;
				the_array[(i*weight + 1) + j] = max;
			}
			else if (items[i].weight < j) {
				newv = items[i].weight + the_array[((i-1)*weight + 1) + j - items[i].weight];
				oldv = oldv = the_array[((i-1)*weight + 1) + j];
				max = oldv > newv ? oldv : newv;
				the_array[(i*weight + 1) + j] = max;
			}
			
		} // end j loop which loops through the weights
		
	} // end i loop which loops through the items
	
} // end find_max function

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
		
		sort_items(item_array, num_of_items);
		total = 0;
		for (int i = 0; i < num_of_bags; i++) {
			the_array = new int[(num_of_items + 1) * bag_array[i].capacity];
			result = find_max(item_array, num_of_items, bag_array[i].capacity, the_array);
			total += result;
		} // end find_max loop
		
				
	}; // end large while loop
} // end int main