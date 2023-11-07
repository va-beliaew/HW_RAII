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
	smart_array(const smart_array &c) {
		count = c.count;
		counter = c.counter;
		New();
		for (int i = 0; i < count; ++i) {
			arr[i] = c.arr[i];
		}
	}
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
		if (loc >= counter || loc < 0)
			throw std::range_error("Выход за пределы диапазона массива");
		return arr[loc];
	}

	smart_array& operator= (const smart_array& c) {
		if (&c != this) {
			counter = c.counter;
			delete[] arr;
			arr = new int[c.count];
			for (int i = 0; i < c.count; ++i) {
				arr[i] = c.arr[i];
			}
		}
		return *this;
	} 
	void print(std::string s) {
		std::cout << s << ':' << std::endl;
		for (int i = 0; i < count; ++i) {
			std::cout << arr[i] << ' ';
		}
		std::cout << std::endl;
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
		smart_array new_arr(num);
		arr.add_element(3);
		arr.add_element(43);
		arr.add_element(-2);
		arr.add_element(25);
		arr.add_element(-55);
		arr.add_element(23);
		new_arr.add_element(5);
		new_arr.add_element(74);
		new_arr.add_element(29);
		arr.print("arr before");
		arr = new_arr;
		arr.print("arr after");
		new_arr.print("new_arr");
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