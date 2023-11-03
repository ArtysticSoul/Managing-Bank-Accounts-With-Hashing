// #include "QuadraticProbing.h"

// void QuadraticProbing::createAccount(std::string id, int count)
// {
//     // IMPLEMENT YOUR CODE HERE
//     int kha = hash(id);
//     if (size == -1)
//     {
//         bankStorage1d.resize(200003);
//         for (int i = 0; i < 200003; i++)
//         {
//             bankStorage1d[i].balance = -69;
//         }
//         size = 0;
//     }
//     size++;
//     long long check = kha;
//     long long kabtak = 0;
//     while (kabtak < bankStorage1d.size())
//     {
//         if (bankStorage1d[check].balance < 0)
//         {
//             Account nyawala;
//             nyawala.id = id;
//             nyawala.balance = count;
//             bankStorage1d[check] = nyawala;
//             return;
//         }
//         kabtak++;
//         check = (kha + ((kabtak * kabtak) % 200003)) % 200003;
//     }
// }

// void QuadraticProbing::Mila(std::vector<int> &paisa, int pichhe, int bich, int aage)
// {
//     int n1 = bich - pichhe + 1;
//     int n2 = aage - bich;
//     std::vector<int> pehla(n1);
//     std::vector<int> dusra(n2);
//     for (int i = 0; i < n1; i++)
//     {
//         pehla[i] = paisa[pichhe + i];
//     }
//     for (int i = 0; i < n2; i++)
//     {
//         dusra[i] = paisa[bich + 1 + i];
//     }
//     int i = 0, j = 0, k = pichhe;
//     while (i < n1 && j < n2)
//     {
//         if (pehla[i] <= dusra[j])
//         {
//             paisa[k] = pehla[i];
//             i++;
//         }
//         else
//         {
//             paisa[k] = dusra[j];
//             j++;
//         }
//         k++;
//     }
//     while (i < n1)
//     {
//         paisa[k] = pehla[i];
//         i++;
//         k++;
//     }
//     while (j < n2)
//     {
//         paisa[k] = dusra[j];
//         j++;
//         k++;
//     }
//     return;
// }

// void QuadraticProbing::Suljha(std::vector<int> &paisa, int pichhe, int aage)
// {
//     if (pichhe < aage)
//     {
//         int bich = pichhe + (aage - pichhe) / 2;
//         Suljha(paisa, pichhe, bich);
//         Suljha(paisa, bich + 1, aage);
//         Mila(paisa, pichhe, bich, aage);
//     }
//     return;
// }

// std::vector<int> QuadraticProbing::getTopK(int k)
// {
//     // IMPLEMENT YOUR CODE HERE
//     std::vector<int> paisa;
//     for (int bahar = 0; bahar < bankStorage1d.size(); bahar++)
//     {
//         if ((bankStorage1d[bahar]).balance >= 0)
//         {
//             paisa.push_back((bankStorage1d[bahar]).balance);
//         }
//     }
//     Suljha(paisa, 0, paisa.size() - 1);
//     int n = paisa.size();
//     std::vector<int> dikkat;
//     if (paisa.size() > k)
//     {
//         for (int number = 0; number < k; number++)
//         {
//             dikkat.push_back(paisa[n - 1 - number]);
//         }
//     }
//     else{
//         for (int number = 0; number < paisa.size(); number++)
//         {
//             dikkat.push_back(paisa[n - 1 - number]);
//         }
//     }
//     return dikkat; // Placeholder return value
// }

// int QuadraticProbing::getBalance(std::string id)
// {
//     // IMPLEMENT YOUR CODE HERE
//     int kha = hash(id);
//     long long check = kha;
//     long long kabtak = 0;
//     while (kabtak < bankStorage1d.size())
//     {
//         if ((bankStorage1d[check]).balance >= 0)
//         {
//             std::string dhundh = (bankStorage1d[check]).id;
//             if (dhundh == id)
//             {
//                 return (bankStorage1d[check]).balance;
//             }
//         }
//         if ((bankStorage1d[check]).balance == -69)
//         {
//             return -1;
//         }
//         kabtak++;
//         check = (kha + ((kabtak * kabtak) % 200003)) % 200003;
//     }
//     return -1; // Placeholder return value
// }

// void QuadraticProbing::addTransaction(std::string id, int count)
// {
//     // IMPLEMENT YOUR CODE HERE
//     int kha = hash(id);
//     if (!doesExist(id))
//     {
//         createAccount(id, count);
//         return;
//     }
//     long long kabtak = 0;
//     long long check = kha;
//     while (kabtak < bankStorage1d.size())
//     {
//         if ((bankStorage1d[check]).balance >= 0)
//         {
//             std::string dhundh = (bankStorage1d[check]).id;
//             if (dhundh == id)
//             {
//                 (bankStorage1d[check]).balance += count;
//                 return;
//             }
//         }
//         kabtak++;
//         check = (kha + ((kabtak * kabtak) % 200003)) % 200003;
//     }
// }

// bool QuadraticProbing::doesExist(std::string id)
// {
//     // IMPLEMENT YOUR CODE HERE
//     int kha = hash(id);
//     long long check = kha;
//     long long kabtak = 0;
//     while (kabtak < bankStorage1d.size())
//     {
//         if ((bankStorage1d[check]).balance >= 0)
//         {
//             std::string dhundh = (bankStorage1d[check]).id;
//             if (dhundh == id)
//             {
//                 return true;
//             }
//         }
//         if ((bankStorage1d[check]).balance == -69)
//         {
//             return false;
//         }
//         kabtak++;
//         check = (kha + ((kabtak * kabtak) % 200003)) % 200003;
//     }
//     return false; // Placeholder return value
// }

// bool QuadraticProbing::deleteAccount(std::string id)
// {
//     // IMPLEMENT YOUR CODE HERE
//     int kha = hash(id);
//     long long kabtak = 0;
//     long long check = kha;
//     while (kabtak < bankStorage1d.size())
//     {
//         if ((bankStorage1d[check]).balance >= 0)
//         {
//             std::string dhundh = (bankStorage1d[check]).id;
//             if (dhundh == id)
//             {
//                 size--;
//                 (bankStorage1d[check]).balance = -7;
//                 return true;
//             }
//         }
//         if ((bankStorage1d[check]).balance == -69)
//         {
//             return false;
//         }
//         kabtak++;
//         check = (kha + ((kabtak * kabtak) % 200003)) % 200003;
//     }
//     return false; // Placeholder return value
// }
// int QuadraticProbing::databaseSize()
// {
//     // IMPLEMENT YOUR CODE HERE
//     if (size <= 0)
//     {
//         return 0;
//     }
//     return size; // Placeholder return value
// }

// int QuadraticProbing::hash(std::string id)
// {
//     // IMPLEMENT YOUR CODE HERE
//     long long ans = 0;
//     long long pta = 0;
//     long long lambai = id.length();
//     while (pta < lambai - 1)
//     {
//         char au = id[pta];
//         ans += ((int)(au)) * (((((((pta + 1) * (pta + 1)) % 200003) * (pta + 1)) % 200003) * (pta + 1)) % 200003);
//         ans%=200003;
//         pta++;
//     }
//     int final=ans;
//     return final; // Placeholder return value
// }

// #include "QuadraticProbing.h"

// void merge3(std::vector<int> &v, int l, int m, int r) {
//     int s1=m-l+1, s2=r-m;
//     std::vector<int> v1, v2;
//     for (int i=0; i<s1; i++) v1.push_back(v[l+i]);
//     for (int i=0; i<s2; i++) v2.push_back(v[m+i+1]);
//     int a=0, b=0, index=0;
//     while (a<s1 || b<s2) {
//         if (a>=s1) {
//             v[l+index]=v2[b];
//             index++;
//             b++;
//         }
//         else if (b>=s2) {
//             v[l+index]=v1[a];
//             index++;
//             a++;
//         }
//         else {
//             if (v1[a]>=v2[b]) {
//                 v[l+index]=v1[a];
//                 index++;
//                 a++;
//             }
//             else {
//                 v[l+index]=v2[b];
//                 index++;
//                 b++;
//             }
//         }
//     }
// }

// void msort3(std::vector<int> &v, int x, int y) {
//     if (x<y) {
//         int z=x+(y-x)/2;
//         msort3(v, x, z);
//         msort3(v, z+1, y);
//         merge3(v, x, z, y);
//     }
// }

// void QuadraticProbing::createAccount(std::string id, int count) {
//     // IMPLEMENT YOUR CODE HERE
//     if (first) {
//         first=false;
//         for (int i=0; i<200003; i++) {
//             Account a;
//             a.balance=-1;
//             bankStorage1d.push_back(a);
//         }
//     }
//     long long counter=0;
//     int hid=hash(id);
//     while (true) {
//         int current=(hid+counter*counter)%200003;
//         if (bankStorage1d[current].balance<0) {
//             bankStorage1d[current].id=id;
//             bankStorage1d[current].balance=count;
//             break;
//         }
//         else counter++;
//     }
//     balances.push_back(count);
// }

// std::vector<int> QuadraticProbing::getTopK(int k) {
//     // IMPLEMENT YOUR CODE HERE
//     int bsz=balances.size();
//     msort3(balances, 0, bsz-1);
//     if (k>=bsz) return balances;
//     else {
//         std::vector<int> temp;
//         for (int i=0; i<k; i++) temp.push_back(balances[i]);
//         return temp;
//     }
// }

// int QuadraticProbing::getBalance(std::string id) {
//     // IMPLEMENT YOUR CODE HERE
//     if (bankStorage1d.size()==0) return -1;
//     int hid=hash(id);
//     for (long long i=0; i<200003; i++) {
//         int h=(hid+i*i)%200003;
//         if (bankStorage1d[h].balance==-1) return -1;
//         else if (bankStorage1d[h].balance>0 && bankStorage1d[h].id==id) return bankStorage1d[h].balance;
//         else if (bankStorage1d[h].balance==-2 && bankStorage1d[h].id==id) return -1;
//     }
//     return -1;
// }

// void QuadraticProbing::addTransaction(std::string id, int count) {
//     // IMPLEMENT YOUR CODE HERE
//     if (bankStorage1d.size()==0) {
//         createAccount(id, count);
//         return;
//     }
//     int hid=hash(id);
//     for (long long i=0; i<200003; i++) {
//         int h=(hid+i*i)%200003;
//         if (bankStorage1d[h].balance==-1) {
//             createAccount(id, count);
//             return;
//         }
//         else if (bankStorage1d[h].balance>0 && bankStorage1d[h].id==id) {
//             int index;
//             for (int j=0; j<balances.size();j++) if (balances[j]==bankStorage1d[h].balance) index=j;
//             balances[index]+=count;
//             bankStorage1d[h].balance+=count;
//             return;
//         }
//         else if (bankStorage1d[h].balance==-2 && bankStorage1d[h].id==id) {
//             createAccount(id, count);
//             return;
//         }
//     }
//     createAccount(id, count);
//     return;
// }

// bool QuadraticProbing::doesExist(std::string id) {
//     // IMPLEMENT YOUR CODE HERE
//     if (bankStorage1d.size()==0) return false;
//     int hid=hash(id);
//     for (long long i=0; i<200003; i++) {
//         int h=(hid+i*i)%200003;
//         if (bankStorage1d[h].balance==-1) return false;
//         else if (bankStorage1d[h].balance>0 && bankStorage1d[h].id==id) return true;
//         else if (bankStorage1d[h].balance==-2 && bankStorage1d[h].id==id) return false;
//     }
//     return false;
// }

// bool QuadraticProbing::deleteAccount(std::string id) {
//     // IMPLEMENT YOUR CODE HERE
//     if (bankStorage1d.size()==0) return false;
//     int hid=hash(id);
//     for (long long i=0; i<200003; i++) {
//         int h=(hid+i*i)%200003;
//         if (bankStorage1d[h].balance==-1) return false;
//         else if (bankStorage1d[h].balance>0 && bankStorage1d[h].id==id) {
//             int index;
//             for (int j=0; j<balances.size();j++) if (balances[j]==bankStorage1d[h].balance) index=j;
//             balances.erase(balances.begin()+index);
//             bankStorage1d[h].balance=-2;
//             return true;
//         }
//         else if (bankStorage1d[h].balance==-2 && bankStorage1d[h].id==id) return false;
//     }
//     return false;
// }
// int QuadraticProbing::databaseSize() {
//     // IMPLEMENT YOUR CODE HERE
//     return balances.size();
// }

// int QuadraticProbing::hash(std::string id) {
//     // IMPLEMENT YOUR CODE HERE
//     int num=0, current;
//     long long multiplier=7;
//     for (int i=0; i<id.size(); i++) {
//         current=(((int)(id[i]))*(multiplier%200003)*334541)%200003;
//         multiplier*=7;
//         num=(num+current)%200003;
//     }
//     return num%200003;
// }

#include "QuadraticProbing.h"

void merge3(std::vector<int> &v, int l, int m, int r) {
    int s1=m-l+1, s2=r-m;
    std::vector<int> v1, v2;
    for (int i=0; i<s1; i++) v1.push_back(v[l+i]);
    for (int i=0; i<s2; i++) v2.push_back(v[m+i+1]);
    int a=0, b=0, index=0;
    while (a<s1 || b<s2) {
        if (a>=s1) {
            v[l+index]=v2[b];
            index++;
            b++;
        }
        else if (b>=s2) {
            v[l+index]=v1[a];
            index++;
            a++;
        }
        else {
            if (v1[a]>=v2[b]) {
                v[l+index]=v1[a];
                index++;
                a++;
            }
            else {
                v[l+index]=v2[b];
                index++;
                b++;
            }
        }
    }
}

void msort3(std::vector<int> &v, int x, int y) {
    if (x<y) {
        int z=x+(y-x)/2;
        msort3(v, x, z);
        msort3(v, z+1, y);
        merge3(v, x, z, y);
    }
}

void QuadraticProbing::createAccount(std::string id, int count) {
    // IMPLEMENT YOUR CODE HERE
    if (first) {
        first=false;
        for (int i=0; i<200003; i++) {
            Account a;
            a.balance=-1;
            bankStorage1d.push_back(a);
        }
    }
    long long counter=0;
    int hid=hash(id);
    while (true) {
        int current=(hid+counter*counter)%200003;
        if (bankStorage1d[current].balance<0) {
            bankStorage1d[current].id=id;
            bankStorage1d[current].balance=count;
            break;
        }
        else counter++;
    }
    balances.push_back(count);
}

std::vector<int> QuadraticProbing::getTopK(int k) {
    // IMPLEMENT YOUR CODE HERE
    int bsz=balances.size();
    msort3(balances, 0, bsz-1);
    if (k>=bsz) return balances;
    else {
        std::vector<int> temp;
        for (int i=0; i<k; i++) temp.push_back(balances[i]);
        return temp;
    }
}

int QuadraticProbing::getBalance(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    if (bankStorage1d.size()==0) return -1;
    int hid=hash(id);
    for (long long i=0; i<200003; i++) {
        int h=(hid+i*i)%200003;
        if (bankStorage1d[h].balance==-1) return -1;
        else if (bankStorage1d[h].balance>0 && bankStorage1d[h].id==id) return bankStorage1d[h].balance;
        else if (bankStorage1d[h].balance==-2 && bankStorage1d[h].id==id) return -1;
    }
    return -1;
}

void QuadraticProbing::addTransaction(std::string id, int count) {
    // IMPLEMENT YOUR CODE HERE
    if (bankStorage1d.size()==0) {
        createAccount(id, count);
        return;
    }
    int hid=hash(id);
    for (long long i=0; i<200003; i++) {
        int h=(hid+i*i)%200003;
        if (bankStorage1d[h].balance==-1) {
            createAccount(id, count);
            return;
        }
        else if (bankStorage1d[h].balance>0 && bankStorage1d[h].id==id) {
            int index;
            for (int j=0; j<balances.size();j++) if (balances[j]==bankStorage1d[h].balance) index=j;
            balances[index]+=count;
            bankStorage1d[h].balance+=count;
            return;
        }
        else if (bankStorage1d[h].balance==-2 && bankStorage1d[h].id==id) {
            createAccount(id, count);
            return;
        }
    }
    createAccount(id, count);
    return;
}

bool QuadraticProbing::doesExist(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    if (bankStorage1d.size()==0) return false;
    int hid=hash(id);
    for (long long i=0; i<200003; i++) {
        int h=(hid+i*i)%200003;
        if (bankStorage1d[h].balance==-1) return false;
        else if (bankStorage1d[h].balance>0 && bankStorage1d[h].id==id) return true;
        else if (bankStorage1d[h].balance==-2 && bankStorage1d[h].id==id) return false;
    }
    return false;
}

bool QuadraticProbing::deleteAccount(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    if (bankStorage1d.size()==0) return false;
    int hid=hash(id);
    for (long long i=0; i<200003; i++) {
        int h=(hid+i*i)%200003;
        if (bankStorage1d[h].balance==-1) return false;
        else if (bankStorage1d[h].balance>0 && bankStorage1d[h].id==id) {
            int index;
            for (int j=0; j<balances.size();j++) if (balances[j]==bankStorage1d[h].balance) index=j;
            balances.erase(balances.begin()+index);
            bankStorage1d[h].balance=-2;
            return true;
        }
        else if (bankStorage1d[h].balance==-2 && bankStorage1d[h].id==id) return false;
    }
    return false;
}
int QuadraticProbing::databaseSize() {
    // IMPLEMENT YOUR CODE HERE
    return balances.size();
}

int QuadraticProbing::hash(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    int num=0, current=0;
    long long multiplier=13;
    for (int i=0; i<id.size(); i++) {
        current=(((int)(id[i]))*(i+1)*(i+1)*(multiplier%200003)*320000)%200003;
        multiplier*=13;
        num+=current;
    }
    return num%200003;
}