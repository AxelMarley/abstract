#include <QtCore/QCoreApplication>
#include <iostream>
#include <stdlib.h>
#include <QTextCodec>
#include <QString>


class student
{
protected:
    int kurs;
    double sr_ball;
public:
    student(int kr, double sb);
    student(int kr, double kursachi, double zachety, double ekzameny);
//    student(int kr, double kursachi, double zachety, double ekzameny, int praktika);
    virtual int Getkurs() = 0;
    virtual double Getsr_ball() = 0;
};


student::student(int kr, double sb)
{
    kurs = kr;
    sr_ball = sb;
}

student::student(int kr, double kursachi, double zachety, double ekzameny)
{
    kurs = kr;
    sr_ball = (kursachi + zachety + ekzameny)/3;
}

//student::student(int kr, double kursachi, double zachety, double ekzameny, int praktika)
//{
//    kurs = kr;
//    sr_ball = (kursachi + zachety + ekzameny + praktika)/4;
//}
////////////////////////////////////////////



class chetniy_kurs : public student
{
public:
    chetniy_kurs(int kr, double sb);
    chetniy_kurs(int kr, double kursachi, double zachety, double ekzameny);
    virtual int Getkurs();
    virtual double Getsr_ball();
};



chetniy_kurs::chetniy_kurs(int kr, double sb):student( kr, sb)
{
}

chetniy_kurs::chetniy_kurs(int kr, double kursachi, double zachety, double ekzameny):student( kr, kursachi, zachety, ekzameny)
{
}

int chetniy_kurs::Getkurs()
{
    return kurs;
}

double chetniy_kurs::Getsr_ball()
{
    return sr_ball;
}
////////////////////////////////////////////




class NEchetniy_kurs : public student
{
public:
    NEchetniy_kurs(int kr, double sb);
    NEchetniy_kurs(int kr, double kursachi, double zachety, double ekzameny);
    virtual int Getkurs();
    virtual double Getsr_ball();
};


NEchetniy_kurs::NEchetniy_kurs(int kr, double sb):student( kr, sb)
{
}

NEchetniy_kurs::NEchetniy_kurs(int kr, double kursachi, double zachety, double ekzameny):student( kr, kursachi, zachety, ekzameny)
{
}

int NEchetniy_kurs::Getkurs()
{
    return kurs;
}

double NEchetniy_kurs::Getsr_ball()
{
    return sr_ball;
}
////////////////////////////////////////////




class praktika
{
private:
    int kurs;
    double sr_ball;
public:
    praktika(chetniy_kurs CK, int prakt);
    praktika(NEchetniy_kurs NK);
    int Getkurs();
    double Getsr_ball();
};



praktika::praktika(chetniy_kurs CK, int prakt)
{
    kurs = CK.Getkurs();
    sr_ball = (CK.Getsr_ball() + prakt)/2;
}

praktika::praktika(NEchetniy_kurs NK)
{
    kurs = NK.Getkurs();
    sr_ball = NK.Getsr_ball();
}

int praktika::Getkurs()
{
    return kurs;
}

double praktika::Getsr_ball()
{
    return sr_ball;
}
////////////////////////////////////////////



class dekanat
{
public:
    dekanat();
    QString Calculate(praktika calc);
};


dekanat::dekanat()
{
}

QString dekanat::Calculate(praktika calc)
{
    return "kurs: " + QString::number(calc.Getkurs())
            + ",  sr_ball = " + QString::number(calc.Getsr_ball());
}
////////////////////////////////////////////



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    chetniy_kurs *Ivanov = new chetniy_kurs(2, 9);
    chetniy_kurs *Sidorov = new chetniy_kurs(2, 8 ,8 ,9);
    chetniy_kurs *Petrov = new chetniy_kurs(4, 7, 9, 9);

    NEchetniy_kurs *Pushkin = new NEchetniy_kurs(1, 4);
    NEchetniy_kurs *Lermontov = new NEchetniy_kurs(3, 5);
    NEchetniy_kurs *Tolstoy = new NEchetniy_kurs(5, 6, 6, 6);

    praktika *bntu = new praktika(*Ivanov, 9);
    praktika *bank = new praktika(*Sidorov, 8);
    praktika *wargaming = new praktika(*Petrov, 7);
    praktika *ogorod = new praktika(*Pushkin);
    praktika *derevnya = new praktika(*Lermontov);
    praktika *dacha = new praktika(*Tolstoy);

    dekanat *result = new dekanat();
    std::cout<<result->Calculate(*bntu).toStdString()<<std::endl;
    std::cout<<result->Calculate(*wargaming).toStdString()<<std::endl;
    std::cout<<result->Calculate(*dacha).toStdString()<<std::endl;
    std::cout<<result->Calculate(*bank).toStdString()<<std::endl;

    return a.exec();
}
