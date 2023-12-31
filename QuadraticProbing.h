// #ifndef QUADRATICPROBING_H
// #define QUADRATICPROBING_H

// #include "BaseClass.h"
// #include <iostream>

// class QuadraticProbing : public BaseClass {
// public:
//     void createAccount(std::string id, int count) override;
//     std::vector<int> getTopK(int k) override;
//     int getBalance(std::string id) override;
//     void addTransaction(std::string id, int count) override;
//     bool doesExist(std::string id) override;
//     bool deleteAccount(std::string id) override;
//     int databaseSize() override;
//     int hash(std::string id) override;

// private:
//     // Other data members and functions specific to Quadratic Probing
//     void Mila(std::vector<int> &paisa, int pichhe, int bich, int aage);
//     void Suljha(std::vector<int> &paisa, int pichhe , int aage);
//     int size=-1;
// };

// #endif // QUADRATICPROBING_H

#ifndef QUADRATICPROBING_H
#define QUADRATICPROBING_H

#include "BaseClass.h"
#include <iostream>

class QuadraticProbing : public BaseClass {
public:
    void createAccount(std::string id, int count) override;
    std::vector<int> getTopK(int k) override;
    int getBalance(std::string id) override;
    void addTransaction(std::string id, int count) override;
    bool doesExist(std::string id) override;
    bool deleteAccount(std::string id) override;
    int databaseSize() override;
    int hash(std::string id) override;

private:
    bool first=true;
    std::vector<int> balances;
    // Other data members and functions specific to Quadratic Probing
};

#endif // QUADRATICPROBING_H
