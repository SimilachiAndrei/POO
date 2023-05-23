#include <iostream>
#include <vector>

using namespace std;
enum class Tip {
    Prieten, Cunoscut, Coleg
};
class Contact
{
protected:
    string name;
public:
    Contact(const string& nume) :name(nume) {};
    virtual string GetName()const = 0;
    virtual Tip GetTip()const = 0;
};
class Prieten :public Contact
{
protected:
    string data_nastere, adresa, nr_telefon;
public:
    Prieten(const string& nume, const string& data_n, const string& adr, const string& nr_tel) :Contact(nume), data_nastere(data_n), adresa(adr), nr_telefon(nr_tel) {};
    string GetAdresa() { return adresa; }
    string GetDataNastere() { return data_nastere; }
    string GetNrTelefon() { return nr_telefon; }
    string GetName()const override { return name; }
    Tip GetTip()const override { return Tip::Prieten; }

};

class Cunoscut :public Contact
{
protected:
    string nr_telefon;
public:
    Cunoscut(const string& nume, const string& nr_tel) :Contact(nume), nr_telefon(nr_tel) {};
    string GetNrTelefon() { return nr_telefon; }
    string GetName()const override { return name; }
    Tip GetTip()const override { return Tip::Cunoscut; }
};

class Coleg :public Contact
{
protected:
    string nr_telefon, serviciu, adresa;
public:
    Coleg(const string& nume, const string& serv, const string& adr, const string& nr_tel) :Contact(nume), adresa(adr), nr_telefon(nr_tel), serviciu(serv) {};

    string GetNrTelefon() { return nr_telefon; }
    string GetServiciu() { return serviciu; }
    string GetAdresa() { return adresa; }
    string GetName()const override { return name; }
    Tip GetTip()const override { return Tip::Coleg; }
};

class Agenda
{
    vector<Contact*> Contacte;
public:
    void Adauga(Contact* c) { Contacte.push_back(c); }
    void Sterge(const string& nume)
    {
        for (auto it = Contacte.begin(); it != Contacte.end(); )
        {
            if ((*it)->GetName() == nume)
            {
                it = Contacte.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }

    Contact* Cauta(const string& nume)
    {
        for (auto it = Contacte.begin(); it != Contacte.end(); ++it)
        {
            if ((*it)->GetName() == nume)
            {
                return *it;
            }
        }
        return nullptr;
    }

    vector<Contact*> GetPrieteni()
    {
        vector<Contact*> res;
        for (auto it : Contacte)
        {
            if (it->GetTip() == Tip::Prieten)
            {
                res.push_back(it);
            }
        }
        return res;
    }
};

int main() {
    Agenda agenda;
    Contact* prieten1 = new Prieten("Ion", "1980-05-15", "123456789", "123 Str Frunzei");
    Contact* prieten2 = new Prieten("Ana", "1992-11-30", "987654321", "456 Str Fagului");
    Contact* cunoscut1 = new Cunoscut("Bobi", "555555555");
    Contact* coleg1 = new Coleg("Mihai", "111111111", "Compania A", "789 Bd Independentei");

    agenda.Adauga(prieten1);
    agenda.Adauga(prieten2);
    agenda.Adauga(cunoscut1);
    agenda.Adauga(coleg1);

    string numeCautat = "Ana";
    Contact* contactCautat = agenda.Cauta(numeCautat);
    if (contactCautat != nullptr) {
        cout << "Contact found: " << contactCautat->GetName() << endl;
    }
    else {
        cout << "Contact not found." << endl;
    }

    string numeSters = "Bobi";
    agenda.Sterge(numeSters);

    vector<Contact*> prieteni = agenda.GetPrieteni();
    cout << "List of friends:" << endl;
    for (const auto& prieten : prieteni) {
        cout << prieten->GetName() << endl;
    }

    delete prieten1;
    delete prieten2;
    delete cunoscut1;
    delete coleg1;
    return 0;
}

