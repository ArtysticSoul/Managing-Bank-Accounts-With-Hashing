#include "Chaining.h"

void Chaining::createAccount(std::string id, int count)
{
    // IMPLEMENT YOUR CODE HERE
    int kha = hash(id);
    // std::vector<std::vector<Account>> bankStorage2d;
    // std::string id;
    // int balance;
    if (bankStorage2d.size() <= kha)
    {
        bankStorage2d.resize(kha + 1, {});
    }
    Account nyawala;
    nyawala.id = id;
    nyawala.balance = count;
    bankStorage2d[kha].push_back(nyawala);
    return;
}

void Chaining::Mila(std::vector<int> &paisa, int pichhe, int bich, int aage)
{
    int n1 = bich - pichhe + 1;
    int n2 = aage - bich;
    std::vector<int> pehla(n1);
    std::vector<int> dusra(n2);
    for (int i = 0; i < n1; i++)
    {
        pehla[i] = paisa[pichhe + i];
    }
    for (int i = 0; i < n2; i++)
    {
        dusra[i] = paisa[bich + 1 + i];
    }
    int i = 0, j = 0, k = pichhe;
    while (i < n1 && j < n2)
    {
        if (pehla[i] <= dusra[j])
        {
            paisa[k] = pehla[i];
            i++;
        }
        else
        {
            paisa[k] = dusra[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        paisa[k] = pehla[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        paisa[k] = dusra[j];
        j++;
        k++;
    }
    return;
}

void Chaining::Suljha(std::vector<int> &paisa, int pichhe, int aage)
{
    if (pichhe < aage)
    {
        int bich = pichhe + (aage - pichhe) / 2;
        Suljha(paisa, pichhe, bich);
        Suljha(paisa, bich + 1, aage);
        Mila(paisa, pichhe, bich, aage);
    }
    return;
}

std::vector<int> Chaining::getTopK(int k)
{
    // IMPLEMENT YOUR CODE HERE
    std::vector<int> paisa;
    for (int bahar = 0; bahar < bankStorage2d.size(); bahar++)
    {
        for (int andar = 0; andar < bankStorage2d[bahar].size(); andar++)
        {
            int money = (bankStorage2d[bahar][andar]).balance;
            paisa.push_back(money);
        }
    }
    Suljha(paisa, 0, paisa.size() - 1);
    int n = paisa.size();
    std::vector<int> dikkat;
    if (paisa.size() > k)
    {
        for (int number = 0; number < k; number++)
        {
            dikkat.push_back(paisa[n - 1 - number]);
        }
    }
    else{
        for (int number = 0; number < paisa.size(); number++)
        {
            dikkat.push_back(paisa[n - 1 - number]);
        }
    }
    return dikkat; // Placeholder return value
}

int Chaining::getBalance(std::string id)
{
    // IMPLEMENT YOUR CODE HERE
    if (doesExist(id))
    {
        int kha = hash(id);
        for (int andar = 0; andar < bankStorage2d[kha].size(); andar++)
        {
            std::string dhundh = (bankStorage2d[kha][andar]).id;
            if (dhundh == id)
            {
                return (bankStorage2d[kha][andar]).balance;
            }
        }
    }
    return -1; // Placeholder return value
}

void Chaining::addTransaction(std::string id, int count)
{
    // IMPLEMENT YOUR CODE HERE
    int kha = hash(id);
    if (!doesExist(id))
    {
        createAccount(id, count);
        return;
    }
    for (int andar = 0; andar < bankStorage2d[kha].size(); andar++)
    {
        std::string dhundh = (bankStorage2d[kha][andar]).id;
        if (dhundh == id)
        {
            ((bankStorage2d[kha][andar]).balance) += count;
            return;
        }
    }
}

bool Chaining::doesExist(std::string id)
{
    // IMPLEMENT YOUR CODE HERE
    int kha = hash(id);
    if (kha < bankStorage2d.size())
    {
        for (int andar = 0; andar < bankStorage2d[kha].size(); andar++)
        {
            std::string dhundh = (bankStorage2d[kha][andar]).id;
            if (dhundh == id)
            {
                return true;
            }
        }
    }
    return false; // Placeholder return value
}

bool Chaining::deleteAccount(std::string id)
{
    // IMPLEMENT YOUR CODE HERE
    int kha = hash(id);
    if (doesExist(id))
    {
        for (int andar = 0; andar < bankStorage2d[kha].size(); andar++)
        {
            std::string dhundh = (bankStorage2d[kha][andar]).id;
            if (dhundh == id)
            {
                (bankStorage2d[kha]).erase(bankStorage2d[kha].begin() + andar);
                return true;
            }
        }
    }
    return false; // Placeholder return value
}

int Chaining::databaseSize()
{
    // IMPLEMENT YOUR CODE HERE
    int insaan = 0;
    for (int bahar = 0; bahar < bankStorage2d.size(); bahar++)
    {
        for (int andar = 0; andar < bankStorage2d[bahar].size(); andar++)
        {
            insaan++;
        }
    }
    return insaan; // Placeholder return value
}

int Chaining::hash(std::string id)
{
    // IMPLEMENT YOUR CODE HERE
    long long ans = 0;
    long long pta = 0;
    long long lambai = id.length();
    while (pta < lambai - 1)
    {
        char au = id[pta];
        ans += ((int)(au)) * (((((((pta + 1) * (pta + 1)) % 9973) * (pta + 1)) % 9973) * (pta + 1)) % 9973);
        ans %= 9973;
        pta++;
    }
    int final=ans;
    return final; // Placeholder return value
}

