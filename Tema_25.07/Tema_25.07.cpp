#include <iostream>
using namespace std;

//3
//class Shape
//{
//public:
//    Shape() = default;
//    virtual void draw()
//    {
//        cout << "Am desenat o forma" << endl;
//    }
//};
//
//class Circle : public Shape
//{
//public:
//    Circle() = default;
//    void draw() override
//    {
//        cout << "Am desenat un cerc" << endl;
//    }
//};
//
//class Rectangle : public Shape
//{
//public:
//    Rectangle() = default;
//    void draw() override
//    {
//        cout << "Am desenat un dreptunghi" << endl;
//    }
//};
//
//int main()
//{
//    Shape* s = new Rectangle;
//    s->draw();
//    delete s;
//    Circle c;
//    s = &c;
//    s->draw();
//
//}

//4

//class Shape
//{
//public:
//    Shape() = default;
//    virtual void draw() = 0;
//};
//
//class Circle : public Shape
//{
//public:
//    Circle() = default;
//    void draw()
//    {
//        cout << "Am desenat un cerc" << endl;
//    }
//};
//
//class Rectangle : public Shape
//{
//public:
//    Rectangle() = default;
//    void draw()
//    {
//        cout << "Am desenat un dreptunghi" << endl;
//    }
//};
//
//int main()
//{
//    Circle c;
//    Shape* s = &c;
//    s->draw();
//
//}

//5


class Printable
{
public:
	virtual void print() = 0;
	virtual void printSize() = 0;
};

class Document : public Printable
{
public:
	void print()
	{
		cout << "Print from document\n";
	}
	virtual void printSize() {
	}
};

class Image : public Printable
{
public:
	void print()
	{
		cout << "Print from Image\n";
	}
	virtual void printSize(){
		cout << "Print size from Image\n";
	}
};

class PNG : public Image
{
public:
	void print()
	{
		cout << "Print from PNG\n";
	}
};

int main()
{
	Printable* p = new PNG;
	p->print();
	p->printSize();
}