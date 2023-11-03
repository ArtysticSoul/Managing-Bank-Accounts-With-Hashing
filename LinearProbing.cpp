#include "LinearProbing.h"

void LinearProbing::createAccount(std::string id, int count)
{
    // IMPLEMENT YOUR CODE HERE
    int kha = hash(id);
    if (size == -1)
    {
        bankStorage1d.resize(143053);
        for (int i = 0; i < 143053; i++)
        {
            bankStorage1d[i].balance = -69;
        }
        size = 0;
    }
    size++;
    long long check = kha;
    long long kabtak = 0;
    while (kabtak < bankStorage1d.size())
    {
        if (bankStorage1d[check].balance < 0)
        {
            Account nyawala;
            nyawala.id = id;
            nyawala.balance = count;
            bankStorage1d[check] = nyawala;
            return;
        }
        kabtak++;
        check = (check + 1) % 143053;
    }
    // std::vector<Account> bankStorage1d;
    // std::string id;
    // int balance;
}

void LinearProbing::Mila(std::vector<int> &paisa, int pichhe, int bich, int aage)
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

void LinearProbing::Suljha(std::vector<int> &paisa, int pichhe, int aage)
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

std::vector<int> LinearProbing::getTopK(int k)
{
    // IMPLEMENT YOUR CODE HERE
    std::vector<int> paisa;
    for (int bahar = 0; bahar < bankStorage1d.size(); bahar++)
    {
        if ((bankStorage1d[bahar]).balance >= 0)
        {
            paisa.push_back((bankStorage1d[bahar]).balance);
        }
    }
    Suljha(paisa, 0, paisa.size()-1);
    int n=paisa.size();
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
    return dikkat;// Placeholder return value
}

int LinearProbing::getBalance(std::string id)
{
    // IMPLEMENT YOUR CODE HERE
    int kha = hash(id);
    long long check = 0;
    while (check < bankStorage1d.size())
    {
        if ((bankStorage1d[kha]).balance >= 0)
        {
            std::string dhundh = (bankStorage1d[kha]).id;
            if (dhundh == id)
            {
                return (bankStorage1d[kha]).balance;
            }
        }
        if ((bankStorage1d[kha]).balance == -69)
        {
            return -1;
        }
        kha = (kha + 1) % 143053;
        check++;
    }
    return -1; // Placeholder return value
}

void LinearProbing::addTransaction(std::string id, int count)
{
    // IMPLEMENT YOUR CODE HERE
    int kha = hash(id);
    if (!doesExist(id))
    {
        createAccount(id, count);
        return;
    }
    int check = 0;
    while (check < bankStorage1d.size())
    {
        if ((bankStorage1d[kha]).balance >= 0)
        {
            std::string dhundh = (bankStorage1d[kha]).id;
            if (dhundh == id)
            {
                (bankStorage1d[kha]).balance += count;
                return;
            }
        }
        kha = (kha + 1) % 143053;
        check++;
    }
}

bool LinearProbing::doesExist(std::string id)
{
    // IMPLEMENT YOUR CODE HERE
    int kha = hash(id);
    long long check = 0;
    while (check < bankStorage1d.size())
    {
        if ((bankStorage1d[kha]).balance >= 0)
        {
            std::string dhundh = (bankStorage1d[kha]).id;
            if (dhundh == id)
            {
                return true;
            }
        }
        if ((bankStorage1d[kha]).balance == -69)
        {
            return false;
        }
        kha = (kha + 1) % 143053;
        check++;
    }
    return false; // Placeholder return value
}

bool LinearProbing::deleteAccount(std::string id)
{
    // IMPLEMENT YOUR CODE HERE
    int kha = hash(id);
    long long check = 0;
    while (check < bankStorage1d.size())
    {
        if ((bankStorage1d[kha]).balance >= 0)
        {
            std::string dhundh = (bankStorage1d[kha]).id;
            if (dhundh == id)
            {
                size--;
                (bankStorage1d[kha]).balance = -7;
                return true;
            }
        }
        if ((bankStorage1d[kha]).balance == -69)
        {
            return false;
        }
        kha = (kha + 1) % 143053;
        check++;
    }
    return false; // Placeholder return value
}
int LinearProbing::databaseSize()
{
    // IMPLEMENT YOUR CODE HERE
    if (size <= 0)
    {
        return 0;
    }
    return size; // Placeholder return value
}

int LinearProbing::hash(std::string id)
{
    // IMPLEMENT YOUR CODE HERE
    long long ans = 0;
    long long pta = 0;
    long long lambai = id.length();
    while (pta < lambai - 1)
    {
        char au = id[pta];
        ans += ((int)(au)) * (((((((pta + 1) * (pta + 1)) % 143053) * (pta + 1)) % 143053) * (pta + 1)) % 143053);
        ans %= 143053;
        pta++;
    }
    int final=ans;
    return final; // Placeholder return value
}

