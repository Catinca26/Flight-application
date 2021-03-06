#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
#include <regex>

using namespace std;
class Operator
{
public:
    void login();
    void detaliiZbor();
};
void Operator ::login()
{
    string numeOp;
    string parola;
    string _numeOp;
    string _parola;
    string separator = " ";
    ifstream readFile("users_operatori.txt");
    int ok = 0;
    cout << "Introduceti nume de utilizator/adresa de mail:\n";
    cin >> numeOp;
    cout << "Introduceti parola:\n";
    cin >> parola;
    try
    {

        while (getline(readFile, separator))
        {
            stringstream iss(separator);
            iss >> _numeOp >> _parola;
            if (numeOp == _numeOp && parola == _parola)
                ok = 1;
        }

        if (ok == 0)
        {
            throw "Logare operator invalida\n";
        }
        cout << "Logare operator cu succes!\n";
    }
    catch (const char *err)
    {
        cout << err << "Doriti sa mai incercati o data?(d|n)\n";
        char optiune;
        cout << "Alegeti optiunea\n";
        cin >> optiune;
        switch (optiune)
        {
        case 'd':
            login();
            break;
        case 'n':
            break;

        default:
            break;
        }
    }
}
int verificareData(string data)
{
    const regex pattern("[0-9]{2}-[0-9]{2}-[0-9]{4}");
    return regex_match(data, pattern);
}

void Operator ::detaliiZbor()
{
    ofstream outfile;
    string data, oras;

    outfile.open("zboruri.txt", ios_base::app);
    outfile << endl;
    cout << "Se introduce un zbor si se verifica corectitudinea datelor introduse\n ";
    cout << "Data zborului este(zz-ll-aaaa)\n";
    cin >> data;
    try
    {
        if (verificareData(data) == 0)
        {
            throw "Data este incorect introdusa\n";
        }
        cout << "Data a fost introdusa corect\n";
        //o adaugam in programul de zboruri
        outfile << data << " ";
    }
    catch (const char *err)
    {
        cout << err << "Mai aveti o sansa sa introduceti data corect!\n";
        cin >> data;
    }
    string tara;
    string taraExistenta;
    string separator = " ";
    ifstream readFile("tari.txt"); //am folosit doar tarile din Europa
    int ok = 0;
    cout << "Introduceti tara:\n";
    cin >> tara;

    try
    {
        while (getline(readFile, separator))
        {
            stringstream iss(separator);
            iss >> taraExistenta;
            if (tara == taraExistenta)
                ok = 1;
        }
        if (ok == 0)
        {
            throw "Tara nu este corecta\n";
        }
        cout << "Tara introdusa este valida!\n";
        //o adaugam in programul de zboruri
        outfile << tara << endl;
    }
    catch (const char *err)
    {
        cout << err << "Mai aveti o sansa sa introduceti tara corecta\n";
        cin >> tara;
    }
}

class Utilizator
{
public:
    void login();
    void autentificare();
    void rezervareZbor();
};
void Utilizator ::login()
{
    string utilizator;
    string parola;
    string _utilizator;
    string _parola;
    string separator = " ";
    ifstream readFile("user.txt");
    int ok = 0;
    cout << "Introduceti nume de utilizator/adresa de mail:\n";
    cin >> utilizator;
    cout << "Introduceti parola:\n";
    cin >> parola;
    try
    {

        while (getline(readFile, separator))
        {
            stringstream iss(separator);
            iss >> _utilizator >> _parola;
            if (utilizator == _utilizator && parola == _parola)
                ok = 1;
        }

        if (ok == 0)
        {
            throw "Logare invalida\n";
        }
        cout << "Logare cu succes!\n";
    }
    catch (const char *err)
    {
        cout << err << "Nu aveti cont in sistem,doriti sa creati unul?(d|n)\n";
        char optiune;
        cout << "Alegeti optiunea\n";
        cin >> optiune;
        switch (optiune)
        {
        case 'd':
            autentificare();
            break;
        case 'n':
            break;

        default:
            break;
        }
    }
}
int verificareEmail(string email)
{
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email, pattern);
}

int verificaLungime(char p[])
{
    int i;
    int l = strlen(p);
    if (l < 6)
        return 1;
    else
    {
        return 0;
    }
}
int literaMare(char p[])
{
    int i, ok = 0;
    int l;
    l = strlen(p);
    for (i = 0; i < l - 1; i++)
        if (isupper(p[i]))
            ok++;
    if (ok)
        return 1;
    else
    {
        return 0;
    }
}
int literaMica(char p[])
{
    int i, ok = 0;
    int l;
    l = strlen(p);
    for (i = 0; i < l - 1; i++)
        if (islower(p[i]))
            ok++;
    if (ok)
        return 1;
    else
    {
        return 0;
    }
}
int caracterSpecial(char p[])
{
    int i, ok = 0;
    int l;
    l = strlen(p);
    for (i = 0; i < l - 1; i++)
        if (ispunct(p[i]))
            ok++;
    if (ok)
        return 1;
    else
    {
        return 0;
    }
}
int verificareParola(char parola[])
{
    int i;
    if (verificaLungime(parola) && literaMare(parola) && literaMica(parola) && caracterSpecial(parola))
        return 1;
    else
    {
        return 0;
    }
}

void Utilizator ::autentificare()
{
    string UserName;
    char Parola[30], Parola_1[30];
    cout << "Introduceti numele de utilizator/adresa de mail:\n";
    cin >> UserName;
    cout << "Introduceti parola:\n";
    cin >> Parola;
    try
    {
        if (verificareEmail(UserName) == 0)
        {
            throw "Adresa invalida!\n";
        }
        cout << "Adresa valida!\n";
    }
    catch (const char *err)
    {
        cout << err << "Mai introduceti o data adresa!(d|n)\n";
        char optiune;
        cout << "Alegeti optiunea\n";
        cin >> optiune;
        switch (optiune)
        {
        case 'd':
            cin >> UserName;
            break;
        case 'n':
            break;

        default:
            break;
        }
    }
    try
    {
        if (verificareParola(Parola) == 0)
        {
            throw "Parola nu este suficient de puternica!\n";
        }
        cout << "Parola este ok!\n";
    }
    catch (const char *err)
    {
        cout << err << "Introduceti alta parola!\n";
        int k = 1;
        string _Parola;
        cin >> _Parola;
        if (Parola == _Parola)
            cout << "Parola este corecta\n";
        else
        {
            cout << "Ati epuizat incercarile\n";
        }
    }
    try
    {
        cout << "Introduceti a doua oara parola de logare :\n";
        cin >> Parola_1;
        if (strcmp(Parola, Parola_1))
        {
            throw "Parola repetata nu e corecta\n";
        }
        cout << "Parola setata cu succes\n";
    }
    catch (const char *err)
    {
        cout << err << "Repetati inca o data parola\n";

        int k = 1;
        string _Parola_1;
        cin >> _Parola_1;
        if (Parola_1 == _Parola_1)
            cout << "Parola repetata este corecta\n";

        else
        {
            cout << "Ati epuizat incercarile\n";
        }
    }
}

void Utilizator::rezervareZbor() //?????? MAINE
{
    //utilizatorul introduce un zbor si se verifica daca data dorit de el corespunde cu data din orarul de zbor
    string dataZbor;
    string taraCeruta;
    string data;
    string destinatie;
    string separator = " ";
    ifstream readFile("zboruri.txt");
    int ok = 0;
    cout << "Introduceti data la care se doreste plecarea:\n";
    cin >> dataZbor;
    cout << "Introduceti tara destinatie:\n";
    cin >> taraCeruta;
    try
    {

        while (getline(readFile, separator))
        {
            stringstream iss(separator);
            iss >> data >> destinatie;
            if (data == dataZbor && destinatie == taraCeruta)
                ok = 1;
        }
        if (ok == 0)
        {
            throw "Nu s a gasit zbor la datele specificate\n";
        }
        cout << "Zbor gasit\n";
    }
    catch (const char *err)
    {
        cout << err << "Introduceti alte date pentru zbor si se incearca gasirea urmatoarei date pentru destinatia respeciva\n";
        cin >> dataZbor;
        cin >> taraCeruta;
        string data;
        string destinatie;
        string separator = " ";
        ifstream readFile("zboruri.txt");

        while (getline(readFile, separator))
        {
            stringstream iss(separator);

            iss >> data >> destinatie;
            if (taraCeruta == destinatie && dataZbor != data)
            {
                cout << "Cea mai apropiata data este: " << data << endl;
                break;
            }
            else
            {
                cout << "Ne pare foarte rau, dar nu exista zbor momentan\n";
            }
        }
    }
}

int main()
{
    Utilizator user;
    Operator op;
    user.login();
    user.rezervareZbor();
}
