
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


template<typename T>
class dynamic_array
{
	T* data;
	size_t n;

public:
	dynamic_array(int n)
	{
		this->n = n;
		data = new T[n];
	}

	dynamic_array(const dynamic_array<T>& other)
	{
		n = other.n;
		data = new T[n];

		for (int i = 0; i < n; i++)
		{
			data[i] = other[i];
		}
	}

	T& operator[](int index)
	{
		return data[index];
	}

	const T& operator[](int index) const
	{
		return data[index];
	}

	T& at(int index)
	{
		if (index < n)
		{
			return data[index];
		}

		throw "index out of range";
	}

	size_t size() const
	{
		return n;
	}

	~dynamic_array()
	{
		delete[] data;
	}

	// operator 연산
	T* begin() { return data; }
	const T* begin() const { return data; }
	T* end() { return data + n; }
	const T* end() const { return data + n; }

	
	friend dynamic_array<T> operator+(const dynamic_array<T>& arr1, dynamic_array<T>& arr2)
	{
		dynamic_array<T> result(arr1.size() + arr2.size());
		std::copy(arr1.begin(), arr1.end(), result.begin());
		std::copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());

		return result;
	}

	std::string to_string(const std::string& sep = ", ")
	{
		if (n == 0)
			return "";

		ostringstream os;
		os << data[0];

		for (int i = 1; i < n; i++)
		{
			os << sep << data[i];
		}

		return os.str();
	}


};

struct student
{
	std::string name;
	int standard;
};

std::ostream& operator<<(std::ostream& os, const student& s)
{
	os << "[" << s.name << ", " << s.standard << "]";
	return os;
}



int main()
{
	int nStudent;

	std::cout << "1반 학생 수를 입력하세요: ";
	std::cin >> nStudent;

	dynamic_array<student> class1(nStudent);
	for (int i = 0; i < nStudent; i++)
	{
		std::string name;
		int standard;
		std::cout << i + 1 << "번째 학생 이름과 나이를 입력하세요: ";
		std::cin >> name >> standard;
		class1[i] = student{ name, standard };
	}

	try
	{
		class1.at(nStudent) = student{ "John, 8" };
		
	}

	catch (...)
	{
		std::cout << "예외 발생!" << std::endl;
	}
	
	auto class2 = class1;
	std::cout << "1반을 복사하여 2반 생성: " << class2.to_string() << std::endl;
	
	auto class3 = class1 + class2;
	std::cout << "1반과 2반을 합쳐 3반 생성: " << class3.to_string() << std::endl;

	return 0;

}
