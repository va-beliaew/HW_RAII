#include <iostream>

class smart_array {
private:
	unsigned int count = 0;
	int* arr;
	int counter = 0;

	void New() {
		arr = new int[count] {};
	}

public:
		smart_array(int count_) {
			if (count_ < 1) 
			throw std::underflow_error("Нулевое или отрицательное количество элементов массива");
			else {
				count = count_;
				New();
			}
		}
	void add_element(int num) {
		if (counter >= count)
			throw std::overflow_error("Превышение выделенной памяти на массив");
		arr[counter] = num;
		counter++;
	}

	int get_element(int loc) {
		if (loc >= count || loc < 0)
			throw std::range_error("Выход за пределы диапазона массива");
		return arr[loc];
	}

		~smart_array() {
	delete[] arr;
}
};

int main() {
	setlocale(LC_ALL, "rus");
	const int num = 6;
	try {
		smart_array arr(num);
		arr.add_element(3);
		arr.add_element(43);
		arr.add_element(-2);
		arr.add_element(25);
		arr.add_element(-55);
		arr.add_element(23);
		std::cout << arr.get_element(3) << '\n' << arr.get_element(4) << '\n';
	}
	catch (const std::underflow_error& er) {
		std::cout << er.what();
	}
	catch (const std::overflow_error& er) {
		std::cout << er.what();
	}
	catch (const std::range_error& er) {
		std::cout << er.what();
	}
	return 0;
}