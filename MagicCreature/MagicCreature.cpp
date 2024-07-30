#include <iostream>
#include <string>
using namespace std;

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