#include <iostream>

template<class T>
class Auto_ptr4
{
	T* m_ptr;
public:
	Auto_ptr4(T* ptr = nullptr) : m_ptr(ptr){}

	~Auto_ptr4()
	{
		delete m_ptr;
	}

	// Copia el constructor
	// Hacer copia profunda de a.m_ptr a m_ptr
	Auto_ptr4(const Auto_ptr4& a)
	{
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
	}

	// Mover el constructor
	// Transferir la propiedad de a.m_ptr a m_ptr
	Auto_ptr4(Auto_ptr4&& a) : m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr;
	}

	// Mover la asignación
	// Transferir la propiedad de a.m_ptr a m_ptr
	Auto_ptr4& operator=(Auto_ptr4&& a)
	{
		// Detección de auto-asignación
		if (&a == this)
			return *this;

		// Libera cualquier recurso que tengamos
		delete m_ptr;

		// Transferir la propiedad de a.m_ptr a m_ptr
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;

		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

Auto_ptr4<Resource> generateResource()
{
	Auto_ptr4<Resource> res(new Resource);
	return res; // este valor de retorno invocará al constructor del movimiento
}

int main()
{
	Auto_ptr4<Resource> mainres;
	mainres = generateResource(); // esta asignación invocará la asignación de la movimiento

	return 0;
}
