#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

class Counter {

private:
	int sum = 0; 
	int count = 0; 

public:
	void operator()(int number) {
		if (number % 3 == 0) {
			sum += number;
			count++;
		}
	}

	int get_sum() { return sum; }
	int get_count() { return count; }
};

int main() {

	setlocale(LC_ALL, "Russian");
	vector<int> numbers = { 4, 1, 3, 6, 25, 54 };

	Counter counter;
	counter = for_each(numbers.begin(), numbers.end(), counter);

	cout << "Сумма чисел, делящихся на 3 = " << counter.get_sum() << endl; 
	cout << "Количество чисел, делящихся на 3 = " << counter.get_count() << endl; 

	return 0;
}