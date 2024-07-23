#include <iostream>
#include <string>
using namespace std;

class Recipe
{
private:
    string name;
    string ingredients;
    string instructions;
    string review;

public:

    Recipe(string name, string ingredients, string instructions, string review)
        : name(name), ingredients(ingredients), instructions(instructions), review(review){}

    void setName(string name)
    {
        this->name = name;
    }
    
    void setIngregients(string ingredients)
    {
        this->ingredients = ingredients;
    }

    void setInstructions(string instructions)
    {
        this->instructions = instructions;
    }

    void setReview(string review)
    {
        this->review = review;
    }

    void displayRecipe()
    {
        cout << name << endl;
        cout << "Ingredients: " << ingredients << endl;
        cout << "Instructions: " << instructions << endl;
        cout << "Review: " << review << endl;
    }

    string getName() const
    {
        return name;
    }

    string getIngredients() const
    {
        return ingredients;
    }

    string getInstructions() const
    {
        return instructions;
    }

    string getReview() const
    {
        return review;
    }
};

int main()
{
    Recipe r1("Pizza", "Faina, drojdie, apa, etc.","Pregatim aluatul iar apoi adaugam toppinguri.", "Foarte buna!");
    r1.setReview("Excelenta!");
    r1.displayRecipe();
}
