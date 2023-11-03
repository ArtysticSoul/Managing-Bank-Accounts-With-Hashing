#include "CubicProbing.h"

void CubicProbing::createAccount(std::string id, int count)
{
    // IMPLEMENT YOUR CODE HERE
    int kha = hash(id);
    if (size == -1)
    {
        bankStorage1d.resize(139703);
        for (int i = 0; i < 139703; i++)
        {
            bankStorage1d[i].balance = -69;
        }
        size = 0;
    }
    size++;
    long long check = kha;
    long long kabtak = 0;
    while (true)
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
        check = (kha + ((((kabtak * kabtak)%139703)*kabtak) % 139703)) % 139703;
    }
}

void CubicProbing::Mila(std::vector<int> &paisa, int pichhe, int bich, int aage)
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

void CubicProbing::Suljha(std::vector<int> &paisa, int pichhe, int aage)
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

std::vector<int> CubicProbing::getTopK(int k)
{
    // IMPLEMENT YOUR CODE HERE
    if(size<=0){
        std::vector<int> paisa;
        return paisa;
    }
    std::vector<int> paisa;
    for (long long bahar = 0; bahar < bankStorage1d.size(); bahar++)
    {
        if ((bankStorage1d[bahar]).balance >= 0)
        {
            paisa.push_back((bankStorage1d[bahar]).balance);
        }
    }
    Suljha(paisa, 0, paisa.size() - 1);
    long long n = paisa.size();
    std::vector<int> dikkat;
    if (paisa.size() > k)
    {
        for (long long number = 0; number < k; number++)
        {
            dikkat.push_back(paisa[n - 1 - number]);
        }
    }
    else{
        for (long long number = 0; number < paisa.size(); number++)
        {
            dikkat.push_back(paisa[n - 1 - number]);
        }
    }
    return dikkat;// Placeholder return value
}

int CubicProbing::getBalance(std::string id)
{
    // IMPLEMENT YOUR CODE HERE
    if(size<=0){
        return -1;
    }
    int kha = hash(id);
    long long check = kha;
    long long kabtak = 0;
    while (true)
    {
        if ((bankStorage1d[check]).balance >= 0)
        {
            std::string dhundh = (bankStorage1d[check]).id;
            if (dhundh == id)
            {
                return (bankStorage1d[check]).balance;
            }
        }
        if ((bankStorage1d[check]).balance == -69)
        {
            return -1;
        }
        kabtak++;
        check = (kha + ((((kabtak * kabtak)%139703)*kabtak) % 139703)) % 139703;
    }
    return -1; // Placeholder return value
}

void CubicProbing::addTransaction(std::string id, int count)
{
    // IMPLEMENT YOUR CODE HERE
    int kha = hash(id);
    if (size<=0 || (!doesExist(id)))
    {
        createAccount(id, count);
        return;
    }
    long long kabtak = 0;
    long long check = kha;
    while (true)
    {
        if ((bankStorage1d[check]).balance >= 0)
        {
            std::string dhundh = (bankStorage1d[check]).id;
            if (dhundh == id)
            {
                (bankStorage1d[check]).balance += count;
                return;
            }
        }
        kabtak++;
        check = (kha + ((((kabtak * kabtak)%139703)*kabtak) % 139703)) % 139703;
    }
}

bool CubicProbing::doesExist(std::string id)
{
    // IMPLEMENT YOUR CODE HERE
    if(size<=0){
        return false;
    }
    int kha = hash(id);
    long long check = kha;
    long long kabtak = 0;
    while (true)
    {
        if ((bankStorage1d[check]).balance >= 0)
        {
            std::string dhundh = (bankStorage1d[check]).id;
            if (dhundh == id)
            {
                return true;
            }
        }
        if ((bankStorage1d[check]).balance == -69)
        {
            return false;
        }
        kabtak++;
        check = (kha + ((((kabtak * kabtak)%139703)*kabtak) % 139703)) % 139703;
    }
    return false; // Placeholder return value
}

bool CubicProbing::deleteAccount(std::string id)
{
    // IMPLEMENT YOUR CODE HERE
    if(size<=0){
        return false;
    }
    int kha = hash(id);
    long long kabtak = 0;
    long long check = kha;
    while (true)
    {
        if ((bankStorage1d[check]).balance >= 0)
        {
            std::string dhundh = (bankStorage1d[check]).id;
            if (dhundh == id)
            {
                size--;
                (bankStorage1d[check]).balance = -7;
                return true;
            }
        }
        if ((bankStorage1d[check]).balance == -69)
        {
            return false;
        }
        kabtak++;
        check = (kha + ((((kabtak * kabtak)%139703)*kabtak) % 139703)) % 139703;
    }
    return false; // Placeholder return value
}
int CubicProbing::databaseSize()
{
    // IMPLEMENT YOUR CODE HERE
    if (size <= 0)
    {
        return 0;
    }
    return size; // Placeholder return value
}

int CubicProbing::hash(std::string id)
{
    // IMPLEMENT YOUR CODE HERE
    long long ans = 0;
    long long pta = 0;
    long long lambai = id.length();
    while (pta < lambai - 1)
    {
        char au = id[pta];
        ans += ((int)(au)) * (((((((pta + 1) * (pta + 1)) % 139703) * (pta + 1)) % 139703) * (pta + 1)) % 139703);
        ans %= 139703;
        pta++;
    }
    int final=ans;
    return final; // Placeholder return value
}

