#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Meniu{
protected:
    int pret;
public:
  virtual string descriere()=0;  
  virtual int getPret()
  {
      return pret;
  }
};

class CuRacoritoare : public Meniu{
    Meniu* m;
public:
    CuRacoritoare(Meniu* m1) : m(m1){}
    int getPret() override
    {
        return m->getPret() + 4; 
    }
    
    string descriere() override
    {
        return m->descriere() + " cu racoritoare";
    }
    
    ~CuRacoritoare()
    {
        delete m;
    }
};

class CuCafea : public Meniu{
    Meniu* m;
public:
    CuCafea(Meniu* m1) : m(m1){}
    int getPret() override
    {
        return m->getPret() + 5; 
    }
    
    string descriere() override
    {
        return m->descriere() + " cu cafea";
    }
    
    ~CuCafea()
    {
        delete m;
    }
};

class MicDejun : public Meniu{
private:
    string denumire;
public:
    MicDejun(int pret1,string denumire1)
    {
        pret = pret1;
        denumire = denumire1;
    }
    
    string descriere() override
    {
        return denumire;
    }
    
};

vector<Meniu*> f()
{
    vector<Meniu*> v;
    MicDejun* m1 = new MicDejun(15,"Omleta");
    CuRacoritoare* r1 = new CuRacoritoare(m1);
    CuCafea* c1 = new CuCafea(r1);
    v.push_back(c1);
    
    MicDejun* m2 = new MicDejun(10,"Ochiuri");
    CuCafea* c2 = new CuCafea(m2);
    v.push_back(c2);
    
    MicDejun* m3 = new MicDejun(15,"Omleta");
    v.push_back(m3);
    return v;
}


int main()
{
    vector<Meniu*> v = f();
    for(int i=0;i<v.size();i++)
        cout << v[i]->descriere() << endl;
    
    return 0;
}
