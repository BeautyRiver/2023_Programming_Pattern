#include <iostream>

using namespace std;

class MobilePhone
{
public:
    MobilePhone()
    {
        cout << "MobilePhone을 생성합니다." << endl;
    }

    virtual ~MobilePhone()
    {
        cout << "MobiePhone을 소멸시킵니다." << endl;
    }

    virtual void TurnOn()
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
    void TurnOn()
    {
        cout << "Apple TurnON" << endl;
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
    void TurnOn()
    {
        cout << "SamSung TurnON" << endl;
    }
};


int main()
{
    cout << "MobiePhone에 대한 예제입니다." << endl;
    cout << endl;

    MobilePhone** mp = new MobilePhone*[2];
    mp[0] = new IPhone();
    IPhone *ip = (IPhone*)mp[0];
    mp[1] = new Galaxy();            
    
    for (size_t i = 0; i < 2; i++)
    {
        mp[i]->TurnOn();           
    }
    
    delete(mp[0]);
    delete(mp[1]);
}

