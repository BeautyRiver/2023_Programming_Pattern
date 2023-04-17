#include <iostream>

using namespace std;

class MobilePhone
{
public:
    MobilePhone()
    {
        cout << "MobilePhone을 생성합니다." << endl;
    }

    ~MobilePhone()
    {
        cout << "MobiePhone을 소멸시킵니다." << endl;
    }

    void TurnOn()
    {
        cout << "MobiePhone을 켭니다." << endl;
    }

    void TurnOff()
    {
        cout << "MobiePhone을 끕니다." << endl;
    }
};

class IPhone : public MobilePhone
{
public:
    IPhone()
    {
        cout << "IPhone을 생성합니다." << endl;
    }
    ~IPhone()
    {
        cout << "IPhone을 소멸시킵니다." << endl;
    }
    void ApplePay()
    {
        cout << "ApplePlay : 1000만원 결제되었습니다." << endl;
    }
    void Siri()
    {
        cout << "Siri : 안녕하세요 Siri입니다." << endl;
    }
        

};

class Galaxy : public MobilePhone
{
public:
    Galaxy()
    {
        cout << "Galaxy을 생성합니다." << endl;
    }
    ~Galaxy()
    {
        cout << "Galaxy을 소멸시킵니다." << endl;
    }
    void SamsungPay()
    {
        cout << "SamsungPay : 1000원이 결제 되었습니다." << endl;
    }
    void Bixby()
    {
        cout << "Bixby : 안녕하세요 제이름은 Bixby입니다." << endl;
    }
};


int main()
{
    cout << "MobiePhone에 대한 예제입니다." << endl;

    IPhone *i = new IPhone();
    /*Galaxy *g = new Galaxy();*/
    Galaxy g;
    cout << "\n";
    i->Siri();    
    g.Bixby();
    cout << "\n";

    delete(i);
    

}

