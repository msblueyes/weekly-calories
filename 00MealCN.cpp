//Catherine Nicholson
//COSC 1437
//Program Set #3-1
//References:Youtube:ASCII Codes,Calorie Counting Program with OOP
// Revel Starting out With C++ from Control Structures to Objects, Tony Gaddis:ASCII Appendix


//This program allows the user to enter up to 21 meals and calculates the total 
// calories consumed for the week.

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;



class Meal {
public:// constructor with optional paramters to initalize the calories and entrees
    Meal(const std::string& entrée = " ", int calories = 0)
        : entrée_{ entrée }, calories_{ calories } {
        weeklyTotal_ += calories_;
    }
    //static function to get the total calories for the week
    static int getWeeklyTotal() {
        return weeklyTotal_;
    }
    //overloaded output operator to display meal information entered by user
    friend std::ostream& operator<<(std::ostream& os, const Meal& meal) {
        os << meal.entrée_ << ": " << meal.calories_ << " calories";
        return os;
    }
    //overloaded input operator to allow user to enter the meal details
    friend std::istream& operator>>(std::istream& is, Meal& meal) {
        const char e = (char)130;//ASCII code for ` and e together to display right output of entree
        std::cout << "Entr" << e << "e: ";
        std::getline(is, meal.entrée_);
        std::cout << "Calorie Count: ";
        is >> meal.calories_;
        std::cout << endl;
        weeklyTotal_ += meal.calories_;
        return is;
    }
    // Overloaded + operator to calculate the total number of calories consumed in a day.
    friend Meal operator+(const Meal& lhs, const Meal& rhs) {
        return Meal{ "Daily Total", lhs.calories_ + rhs.calories_ };
    }
    

private:
    std::string entrée_;//entree entered by user
    int calories_;//calories entered by user

    //static function to keep track of calories consumed
    static int weeklyTotal_;
};
//intialized the weeklyTotal to 0 
int Meal::weeklyTotal_ = 0;

int main() {
    const int kNumMeals = 21;//intialize array of 21 meals
    Meal meals[kNumMeals];//store the meals in the array

    //user input of entree name and calorie count to be stored in the Meal class
    for (int i = 0; i < kNumMeals; ++i) { 
        std::cout << "Enter the details for meal " << i + 1 <<endl;
        std::cin >> meals[i];
        std::cin.ignore();
    }
    //display total calorie count
    std::cout << "_________________________________________" << endl;
    std::cout << "\nYour total calories for the week are: " << Meal::getWeeklyTotal() << std::endl;

    return 0;
}
