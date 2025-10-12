

#include <string>


   Person::Person(std::string nom, int a){
         name(nom), age(a), SpousePtr(nullptr) 
    }

    void setName(const std::string& nom) { 
        name = nom; 
    }
    void setAge(int a) { 
        age = a;
     }
    std::string getName() const { 
        return name; 
    }
    int getAge() const { 
        return age; 
    }

    // Attempt to marry another person
    bool getMarrie(Person* partner) {
        if (partner == nullptr || partner == this) return false;

        if (SpousePtr != nullptr || partner->SpousePtr != nullptr) return false;
        SpousePtr = partner;
        partner->SpousePtr = this;
        return true;
    }

    void setSpouse(Person* spouse) {
        SpousePtr = spouse;
    }

    Person* getSpouse() const {
        return SpousePtr;
    }


