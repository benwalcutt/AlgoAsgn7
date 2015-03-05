#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

class Item {
	public:
	int price;
	int weight;
	bool used;
	
	Item() {
		price = 0;
		weight = 0;
		used = 0;
	}
};

class Bag {
	public:
	int capacity;
};

void sort_items(Item * items, int item_count) {
	int temp = 0;
	for (int i = 1; i <= item_count; i++) {
		for (int j = i + 1; j <= item_count; j++) {
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

int find_max(Item * items, int item_count, int weight) {
	int oldv = 0;
	int newv = 0;
	int max = 0;
	int test_index = 0;
	int result = 0;
	
	int * the_array;
	
	the_array = new int[((item_count + 1) * weight - 1) * 2];

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
				newv = items[i].price + the_array[((i-1)*weight + 1) + (j - items[i].weight)];
				oldv = oldv = the_array[((i-1)*weight + 1) + j];
				max = oldv > newv ? oldv : newv;
				the_array[(i*weight + 1) + j] = max;
			}
			
		} // end j loop which loops through the weights
		
	} // end i loop which loops through the items
	
	test_index = weight - 1;
	for (int m = item_count; m > 0; m--) {
		oldv = the_array[(m*weight + 1) + test_index];
		newv = the_array[((m-1)*weight + 1) + test_index];
		
		if (oldv > newv) {
			items[m].used = true;
			test_index -= items[m].weight;
		}
	}
/*
		cout << "item:     ";
	for (int k = 0; k <= weight; k++) {
		cout << k << " ";
	}
	cout << endl;
	for (int i = 0; i <= item_count; i++) {
		cout << "item: " << i << " - ";
		for (int j = 0; j < weight; j++) {
			cout << setw(3) << the_array[(i*weight + 1) + j] << " ";
		}
		cout << endl;
	}
*/	
	for (int i = 1; i <= item_count; i++) {
		if (items[i].used) {
			result += items[i].price;
		}
	}

	return result;
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
	
	cin >> num_of_cases;
	cin.ignore();
	
	while (num_of_cases-- != 0) {
		cin >> num_of_items;
		
		item_array = new Item[num_of_items + 1];
		item_array[0].weight = 0;
		item_array[0].price = 0;
		
		for (int i = 1; i <= num_of_items; i++) {
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
			for (int j = 1; j <= num_of_items; j++) {
				item_array[j].used = false;
			}
			//the_array = NULL;
			//the_array = new int[(num_of_items + 1) * bag_array[i].capacity];
			result = find_max(item_array, num_of_items, bag_array[i].capacity + 1);

			total += result;

		} // end find_max loop

		cout << total << endl;
		
		//delete[] item_array;
		//delete[] bag_array;
		//delete[] the_array;
		
	} // end large while loop
	
	return 0;
} // end int main