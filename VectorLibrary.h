#ifdef VECTORS_EXPORTS
#define VECTORS_API __declspec(dllexport)
#else
#define VECTORS_API __declspec(dllimport)
#endif

namespace VectorFuns {
	class Vector {
	private:
		int n, i;
		char* array;
	public:
		VECTORS_API Vector(); //конструктор по умолчанию
		VECTORS_API Vector(int N); //конструктор с кол-во элементов
		VECTORS_API Vector(char a[]); //конструктор с массивом символов
		VECTORS_API ~Vector(); //деконструктор
		VECTORS_API void push_back(char a); //добавление элемента в конец вектора
		VECTORS_API void emplace(int j, char a); //присваивает значение элементу на конкретной позиции
		VECTORS_API void clear(); //очистка массива символов
		VECTORS_API void pop_back(); //удаление последнего элемента
		VECTORS_API void erase(int j); //удаляет элемент с конкретной позиции
		VECTORS_API void erase(int begin, int end); //удаляет элементы с позиции begin до end
		VECTORS_API int size(); //возвращает кол-во элементов вектора
		VECTORS_API bool empty(); //проверяет пуст ли вектор
		VECTORS_API void resize(int N); //изменяет размер вектора
		VECTORS_API void swap(int a, int b); //поменять значения местами
		VECTORS_API void show(); //вывод целого вектора
		VECTORS_API char show(int j); //возвращает значение конкретного элемента
	};
}