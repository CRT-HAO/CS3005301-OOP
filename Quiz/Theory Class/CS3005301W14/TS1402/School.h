// Name: 張皓鈞 (B11030202@mail.ntust.edu.tw)
// Date: May 25, 2023
// Last Update: May 25, 2023
// Problem statement: School Inheritance

#pragma once

#include <iostream>
#include <string>

class School
{
protected:
    std::string name;
    float studentAmount;
    float studentAmountNextYear;

public:
    School(const std::string &name, float studentAmount)
        : name(name), studentAmount(studentAmount),
          studentAmountNextYear(studentAmount) {}

    // Indent: Adds the amount to the total student amount this year
    // Pre: The variable amount is the number to add
    virtual inline void admissions(float amount)
    {
        this->studentAmount += amount;
    }

    // Indent: Subtracts the amount from the number of students this year
    // Pre: The variable amount is the number to subtract
    virtual inline void dropouts(float amount)
    {
        if ( (this->studentAmount - amount) < 0 )
            return;
        this->studentAmount -= amount;
    }

    // Indent: Deducts from the student amount of current
    //         and transfers them to another school
    // Pre: The variables amount is the number to transfer,
    //      toSchool is the school to receive
    virtual inline void transfer(float amount, School &toSchool)
    {
        if ( amount > this->studentAmountNextYear )
            return;

        this->dropouts(amount);
        toSchool.admissions(amount);
    }

    friend std::ostream &operator<<(std::ostream &ostream, const School &school)
    {
        ostream
            << school.name << '\t'
            << int(school.studentAmount) << '\t'
            << int(school.studentAmountNextYear);
        return ostream;
    }
};

class PrivateSchool : public School
{
protected:
    int dropoutsTimes{0};
    static const int PENALTY = 100;

public:
    PrivateSchool(const std::string &name, float studentAmount)
        : School(name, studentAmount) {}

    // Indent: Subtracts the amount from the number of students this year
    // Pre: The variable amount is the number to subtract
    inline void dropouts(float amount) override
    {
        if ( (this->studentAmount - amount) < 0 )
            return;
        if ( dropoutsTimes > 0 )
            this->studentAmountNextYear -= PrivateSchool::PENALTY;
        School::dropouts(amount);
        dropoutsTimes += 1;
    }
};

class PublicSchool : public School
{
protected:
    float growing_rate{0.05};
    static const int PENALTY = 100;

public:
    PublicSchool(const std::string &name, float studentAmount)
        : School(name, studentAmount) {}

    // Indent: Increases amount of students able to admit next year
    inline void apply_growth()
    {
        this->studentAmountNextYear +=
            this->growing_rate * this->studentAmountNextYear;
    }

    // Indent: Subtracts the amount from the number of students this year
    // Pre: The variable amount is the number to subtract
    inline void dropouts(float amount) override
    {
        if ( (this->studentAmount - amount) < 0 )
            return;
        if ( amount > PublicSchool::PENALTY )
            this->studentAmountNextYear -= this->studentAmountNextYear * 0.05;
        School::dropouts(amount);
    }
};