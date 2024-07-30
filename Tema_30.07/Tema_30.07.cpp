#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <string>
using namespace std;

//2

class Shape
{
public:
    virtual double area() const = 0;

	friend void printTotalArea(vector<Shape*>& v);

};

class Rectangle : public Shape
{
private:
    double width;
    double height;
public:
    Rectangle(double width, double height)
    {
        this->width = width;
        this->height = height;
    }
    double area() const
    {
        return width * height;
    }
};

class Circle : public Shape
{
private:
    double radius;
public:
    Circle(double radius)
    {
        this->radius = radius;
    }
    double area() const
    {
        return M_PI * radius * radius;
    }
};

void printTotalArea(vector<Shape*>& v)
{
	double suma = 0;
	for (auto el : v)
		suma += el->area();
	cout << suma;
}

int main()
{
    Rectangle* r = new Rectangle(2,2);
    Rectangle* r2 = new Rectangle(2,1);
    Circle* c = new Circle(3.5);
    vector<Shape*> v;
    v.push_back(r);
    v.push_back(r2);
    v.push_back(c);
    printTotalArea(v);
    delete r;
    delete r2;
    delete c;
}

//3

class Avion
{
private:
	string producator;
	string model;
public:
	void setProducator(string producator)
	{
		this->producator = producator;
	}
	string getProducator() const
	{
		return producator;
	}
	void setModel(string model)
	{
		this->model = model;
	}
	string getModel() const
	{
		return model;
	}
};

class AvionMilitar : public Avion
{
private:
	string unitateMilitara;
public:
	void setUnitateMilitara(string unitateMilitara)
	{
		this->unitateMilitara = unitateMilitara;
	}
	string getUnitateMilitara() const
	{
		return unitateMilitara;
	}
};

class AvionLupta : public AvionMilitar
{
private:
	int numarRachete;
public:
	void setNumarRachete(int numarRachete)
	{
		this->numarRachete = numarRachete;
	}
	int getNumarRachete() const
	{
		return numarRachete;
	}
};

class AvionVanatoare : public AvionLupta
{
private:
	float vitezaMaxima;
public:
	void setVitezaMaxima(float vitezaMaxima)
	{
		this->vitezaMaxima = vitezaMaxima;
	}
	float getVitezaMaxima() const
	{
		return vitezaMaxima;
	}
};

class Bombardier : public AvionLupta
{
private:
	int capacitateBombe;
public:
	void setCapacitateBombe(int capacitateBombe)
	{
		this->capacitateBombe = capacitateBombe;
	}
	int getCapacitateBombe() const
	{
		return capacitateBombe;
	}
};

class AvionTransport : public AvionMilitar
{
private:
	float capacitateTransport;
public:
	void setCapacitateTransport(float capacitateTransport)
	{
		this->capacitateTransport = capacitateTransport;
	}
	float getCapacitateTransport() const
	{
		return capacitateTransport;
	}
};

