#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class ResourceHandler
{
private:
    int* data;
    int size;
    ofstream file;
    string name;
public:
    ResourceHandler()
    {
        size = 3;
        data = new int[size];
    }

    ResourceHandler(const string& name)
    {
        this->name = name;
        file.open(name);
        if (!file.is_open())
            cout << "Error while opening the file";

    }

    ~ResourceHandler()
    {
        delete[] data;
        data = nullptr;
        cout << "Data was destroyed" << endl;

        if (file.is_open())
        {
            file.close();
            cout << "File was closed" << endl;
        }
        else
        {
            cout << "File was not open" << endl;
        }
    }

    void setValue(int x, int index)
    {
        if (index >= 0 && index < size)
            data[index] = x;
        else
            cout << "Error while setting the value";
    }

    int getValue(int index) const
    {
        if (index >= 0 && index < size)
            return data[index];
        else
            cout << "Error while getting the value";
    }

    int getSize() const
    {
        return size;
    }

    void writeValue(int value)
    {
        if (file.is_open())
            file << value << " ";
    }
};

int main()
{
    
    ResourceHandler r("resource.txt");
    ResourceHandler arr;
    arr.setValue(10, 0);
    arr.setValue(27, 1);
    arr.setValue(34, 2); 
    for (int i = 0; i < arr.getSize(); i++)
       r.writeValue(arr.getValue(i));
    
}






class MagicCreature
{
private:
	string name;
	string type;
	int age;
	int magicLevel;
public:
	MagicCreature()
	{
		name = "Unnamed";
		type = "Unknown";
		age = 0;
		magicLevel = 0;
	}

	MagicCreature(string name, string type, int age, int magicLevel)
	{
		this->name = name;
		this->type = type;
		this->age = age;
		this->magicLevel = magicLevel;
	}

	MagicCreature(const MagicCreature& creature)
	{
		this->name = creature.name;
		this->type = creature.type;
		this->age = creature.age;
		this->magicLevel = creature.magicLevel;

		cout << "Copy constructor conjured!" << endl;
	}

	void setName(string name)
	{
		this->name = name;
	}

	string getName() const
	{
		return name;
	}

	void setType(string type)
	{
		this->type = type;
	}

	string getType() const
	{
		return type;
	}

	void setAge(int age)
	{
		this->age = age;
	}

	int getAge() const
	{
		return age;
	}

	void setMagicLevel(int magicLevel)
	{
		this->magicLevel = magicLevel;
	}

	int getMagicLevel() const
	{
		return magicLevel;
	}

	void display() const
	{
		cout << "Creature name: " << name << endl;
		cout << "Creature type: " << type << endl;
		cout << "Age: " << age << endl;
		cout << "Magic Level: " << magicLevel << endl;
		cout << endl;
	}

	void display(string name) const
	{
		cout << "Creature name: " << name << endl;
		cout << "Creature type: " << type << endl;
		cout << "Age: " << age << endl;
		cout << "Magic Level: " << magicLevel << endl;
		cout << endl;
	}


};

int main()
{
	MagicCreature c1, c2("Dragon", "Reptilian", 5000, 10), c3(c2);
	c1.display("Unicorn");
	c2.display();
	c3.setAge(3000);
	c3.display();
}
