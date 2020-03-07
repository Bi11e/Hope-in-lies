#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <windows.h>
#include <random>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <clocale>

//#define int int64_t
using namespace std;
#define wait Sleep


#define clr system("cls")



ifstream fin;
ofstream fout;




random_device rd;
mt19937 gen(rd());
void print(string s, int tm)
{
    for(int i = 0; i < s.size(); i++)
    {
        cout << char(s[i]);
        wait(tm);
    }
    wait(500);
}

#define print(s, tm); print(s, 0);
#define Sleep(a) Sleep(0)
enum ConsoleColor
{
    Black         = 0,
    Blue          = 1,
    Green         = 2,
    Cyan          = 3,
    Red           = 4,
    Magenta       = 5,
    Brown         = 6,
    LightGray     = 7,
    DarkGray      = 8,
    LightBlue     = 9,
    LightGreen    = 10,
    LightCyan     = 11,
    LightRed      = 12,
    LightMagenta  = 13,
    Yellow        = 14,
    White         = 15
};

void SetColor(int text, int background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void SetColor(int text, ConsoleColor/*int*/ background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void print_col(int x, int n)
{
    while(n--)
    {
        cout << x << ' ';
    }
}

void print_logo()
{
    int f = 0;
    int ff = 1;
    int i = 5;
    while(i--)
    {
        print_col(ff, 5);
        cout << endl;
        cout << ff << ' ';
        print_col(f, 3);
        cout << ff << endl;
        cout << ff << ' ' << f << ' ' << ff << ' ' << f << ' ' << ff << endl;
        cout << ff << ' ';
        print_col(f, 3);
        cout << ff << endl;
        print_col(ff, 5);
        cout << endl;
        f = 1 - f;
        ff = 1 - ff;
        wait(1000);
        clr;
    }

}

void load(int x)
{
    string s;
    for(int i = 0; i <= x; i++)
    {
        cout << i  << '%' << endl;
        cout << s;
        s += '_';
        wait(80);
        clr;
    }
}

void print1(string x)
{
    for (int i=0; i<x.size(); ++i)
    {
        cout << x[i];
        wait(75);
    }
}

void crash(int x)
{
    for (int j = 0; j < x; ++j)
    {
        SetColor(gen()%16, gen()%16);
        cout << ' ';
        for (int i=0; i<gen()%100+50; ++i)
        {
            cout << char (gen()%50+10);/*wait(1);*/
        }
        cout << ' ';
    }
    SetColor( 15, 0);
    clr;
    wait (1500);
    string ans="Fatal error 453";
    print1(ans);
    wait (1500);
    cout << endl;
    print1 ("Ïåðåçàãðóçêà.....");
    cout<<endl;
    wait (1500);
    print1 ("Âîññòàíîâëåíèå äàííûõ.....");
    wait (1500);
    SetColor( 15, 0);
    clr;
    wait(2000);
    SetColor( 15, 0);
    clr;
}

void tasks()
{
    int col = 95998762;
    vector <pair <int,int> > a = {{2, 2}, {2, 2}, {0, 0}, {4, 1}, {4, 3}, {64754347, 34666346}};
    for(int i = 0 ; i < 6 ; i++)
    {
        print1("Ïðîöåññîâ îñòàëîñü:");
        cout << col;
        cout << endl;
        int ot = a[i].first + a[i].second;
        cout << a[i].first << '+' << a[i].second << '=';
        int x = -1;
        cin >> x;
        if(i == 5)
        {
            wait(2000);
            crash(500);
            return;
        }
        while(x != ot)
        {
            clr;
            print1("L.A.I:Âû íåóäà÷íî ðåøèëè ïðîöåññ, ïîïðîáóéòå åùå ðàç");
            cout << endl;
            print1("Ïðîöåññîâ îñòàëîñü:");
            cout << col;
            cout << endl;
            cout << a[i].first << '+' << a[i].second << '=';
            cin >> x;
        }
        col--;

        clr;
    }
}

void update_save()
{
    fin.open("saves.txt");
    int x;
    fin >> x;
    fin.close();
    fout.open("saves.txt", ios_base::trunc);
    fout << x + 1;
    fout.close();
}


int saves()
{
    int nm;
    fin.open("saves.txt");
    fin >> nm;
    fin.close();
    if(nm == 1)
    {
        return 1;
    }
    print("Õîòèòå ïðîäîëæèòü ñ ïîñëåäíåãî ñîõðàíåíèÿ? (Y/N)", 60);
    cout << endl;
    print("Ââîä ïîëüçîâàòåëÿ:", 60);
    string save;
    while(save!= "Y" && save != "N")
    { 
        cin >> save;
        if(save!= "Y" && save != "N")
        {
            cout << endl;
            print("Ñèñòåìíîå îïîâåùåíèå: Ïîâòîðèòå ïîïûòêó ââîäà...", 60);
            cout << endl;
        }
    }
    int num_save;
    if(save == "Y")
    {
        fin.open("saves.txt");
        fin >> num_save;
        fin.close();
        return num_save;
    }
    int nm_save;
    print("Ââåäèòå íîìåð ãëàâû îò 1 äî 12.", 60);
    cout <<endl;
    while(num_save < 1 || num_save >12)
    {
        print("Ââîä ïîëüçîâàòåëÿ: ", 60);
        cin >> num_save;
        if(num_save < 1 || num_save > 12)
        {
            cout << endl;
            print("Ñèñòåìíîå îïîâåùåíèå: Ïîâòîðèòå ïîïûòêó ââîäà...", 60);
            cout << endl;
        }
        else
        {


            fin.open("saves.txt");
            fin >> nm_save;
            if(nm_save < num_save)
                print("Ñèñòåìíîå îïîâåùåíèå: Ïîâòîðèòå ïîïûòêó ââîäà, âû íå èìååòå äîñòóïà ê ýòîé ãëàâå...", 60);
            cout << endl;
            fin.close();

        }
    }
    clr;
    fin.close();

}


void check_nick()
{
    fin.open("nick.txt");
    string nickname;
    fin >> nickname;
    fin.close();
    if (nickname == "")
    {
        print("Âû åùå íå ïðåäñòàâèëèñü ñèñòåìå, ââåäèòå èìÿ âàøåãî ïåðñîíàæà â ôîðìàòå ÈÌß_ÔÀÌÈËÈß", 60);
        cout << endl;
        cin >> nickname;
        while(nickname != "Steve175RN34_Emptine")
        {
            print("SYSTEM: Ýòî èìÿ óæå çàíÿòî, èç ñâîáîäíûõ òîëüêî Steve175RN34_Emptine", 60);
            cout << endl;
            cin >> nickname;
        }
        print("Ïîëüçîâàòåëü óñïåøíî çàðåãèñòðèðîâàí, ïðèÿòíîãî äíÿ.", 60);
        fout.open("nick.txt");
        fout << nickname;
        fout.close();
        crash(500);
    }
}


void titr()
{
    print ("Îøèáêà âîññòàíîâëåíèÿ äàííûõ.....", 50);
    cout <<endl;
    wait (1000);
    print ("Óòåðÿ äàííûõ.", 50);
    cout <<endl;
    wait (1000);
    print ("Cáðîñ äàííûõ ïîëüçîâàòåëÿ.....", 50);
    cout<<endl;
    wait (2000);
    print ("Cïàñèáî çà ïðîâåä¸ííîå âðåìÿ â èãðå Hope In Lies.",60);
    wait (3000);
    cout <<endl;
    print ("Ïðîäîëæåíèå ñëåäóåò...", 150);
    cout << endl;
    wait (1500);
    print ("Ïðåäëîæåíèÿ ñâîèõ èäåé äëÿ ïðîäîëæåíèÿ ñþæåòà, îòïðàâëÿòü â ëè÷íûå ñîîáùåíèÿ ãðóïïû, ññûëêà â ôàéëå contacts.txt.",60);
    cout<<endl;
    wait(1000);
    clr;
    print("Âî âñåì åñòü êðàñîòà, íî íå êàæäûé åå çàìå÷àåò. Ýíäè Óîðõîë(ñ).", 60);
    cout << endl;
    wait(3000);
    clr;
    print("Àâòîð èäåè: Bill, Dedalius.", 60);
    cout << endl;
    print("Òåõíè÷åñêèå íàðàáîòêè è ðåëèç: Dedalius, game ruiner, TemaTop.", 60);
    cout << endl;
    print("Äèçàéí: Êóñêîâà Þëèÿ, Áàëþêîíèñ Ìèëàíà.", 60);
    cout << endl;
    print("Ìåíåäæåð êîìàíäû ðàçðàáîòêè: VaryaSch.", 60);
    cout << endl;
    wait(3000);
    print("Îãðîìíàÿ áëàãîäàðíîñòü âñåì íàøèì äðóçüÿì è áëèçêèì, ñïàñèáî, ÷òî âåðèëè â íàñ.", 60);
    cout << endl;
    wait(1000);
    print("Çàâåðøåíèå ðàáîòû.", 60);
    print("...", 160);
}



void estimation()
{
    print("Èäåíòèôèêàöèÿ ïîëüçîâàòåëÿ", 60);
    print("...........", 200);
    cout << endl;
    wait(400);
    clr;
    print("L.A.I:Âàñ ñíîâà ïðèâåòñòâóåò L.A.I", 50);
    cout << endl;
    wait(1000);
    print("L.A.I:Äîáðîå óòðî, Steve175RN34 Emptine", 60);
    cout << endl;
    wait(1000);
    print("L.A.I: Ïðîøó ñíîâà îöåíèòå âàøå ñàìî÷óâñòâèå ïî øêàëå îò 1 äî 1000, íå çàáûâàéòå, ÷òî âàø èäåíòèôèêàòîð ïîäîçðèòåëüíîñòè íà äàííûé ìîìåíò ðàâåí 0", 60);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    print("L.A.I:Îæèäàíèå ââîäà ïîëüçîâàòåëÿ", 50);
    print("...", 1000);
    cout << endl;
    print("Steve:", 60);
    int player_in_estimation;
    cin >> player_in_estimation;
    if(player_in_estimation <= 300)
    {
        print("L.A.I:Âîçìîæíî ýòîãî íåäîñòàòî÷íî, óâåëè÷èòü äîçó", 60);
        clr;
        estimation();
    }
    if(player_in_estimation >= 301 && player_in_estimation <= 999)
    {
        print("L.A.I:Äóìàþ ìû ïî÷òè äîáèëèñü ðåçóëüòàòà, óâåëè÷èòü äîçó", 60);
        cout << endl;
        clr;
        print("Âû ÷óâñòâóåòå, ÷òî îòêëþ÷àåòåñü", 60);
        estimation();
    }
    if(player_in_estimation >= 1000)
    {
        print("L.A.I:Î÷åíü õîðîøî, ïðîäîëæèì íàø ðàçãîâîð", 60);
        clr;
        return;
    }

}


string input(string x, string y)
{
    string ans;
    int k = 0;
    cin >> ans;
    while(ans != x && ans != y)
    {
        print("Îøèáêà ââîäà, ïîâòîðèòå ïîïûòêó\n", 60);
        cin >> ans;
    }
    return ans;
}

string input(string x, string y, string z)
{
    string ans;
    int k = 0;
    cin >> ans;
    while(ans != x && ans != y && ans != z)
    {
        print("Îøèáêà ââîäà, ïîâòîðèòå ïîïûòêó\n", 60);
        cin >> ans;
    }
    return ans;
}

void interactive_day_1()
{
    int dey = -1;
    int act[] = {1, 1, 1, 1, 1};
    while(dey != 4)
    {
        cin >> dey;

        while(dey > 5 || dey < 1 || act[dey - 1] != 1)
        {
            print("Íåêîððåêòíûé ââîä. Ïîâòîðèòå ïîïûòêó ââîäà.\n", 60);
            cin >> dey;
        }
        if(dey == 1)
        {
            if(act[0] == 1)
            {
                act[0] = 0;
                wait(1000);
                print("Íåìíîãî ïîâîçèâøèñü ñ ïîêîðåæåííîé òóìáîé, âû íàêîíåö ñìîãëè âûòàùèòü åäèíñòâåííûé íåçàïåðòûé ÿùèê èç êàêîãî-òî ñòðàííîãî âèäà ïëàñòìàññû(êàê íè ñòðàííî îñòàëüíûå áûëè ïðîñòî öåëèêîì èç ñòàëüíûõ ïëàñòèí).\n", 60);
                print("Âíûòðè ëåæàëî 3 òîëñòåííûõ êíèãèâ øåáóðøàùåé îáëîæêå.\n", 60);
                print("Ýòî áûëè òðè òîìà â 1000 ñòðàíèö, íà êàæäîé áûëî íàïèñàíî: 'ÊÀÊ ÁÛÒÜ ÕÎÐÎØÈÌ ÃÐÀÆÄÀÍÈÍÎÌ. ÇÍÀÉ ÇÀÊÎÍÛ È ÏÐÀÂÀ' è êîíå÷íî òîì 1, 2, 3(êàê îêàçàëîñü èõ 175)./n", 60);
                print("Áîëüøå íè÷åãî èíòåðåñíîãî â îïøàðïàíîé òóìáî÷êå íå îêàçàëîñü.\n", 60);
                wait(1000);
                print("Îäíàêî âàøå âíèìàíèÿ ïðèâëåê ïîãðûçåííûé ñâåðòîê áóìàãè, ïîëíîñòüþ ïðîïå÷àòàííûé íàäïèñÿìè âðîäå: 'ÍÀØÀ ÑÒÐÀÍÀ...', 'ÏÎÇÄÐÀÂÈÌ ÃÎÑÏÎÄÈÍÀ X Ñ 122-ËÅÒÈ...', 'ÑÀÌÛÅ ÂÛÃÎÄÍÛÅ ÂÀÊÀÍ...'\n", 60);
                print("Îò íåãî âåÿëî ñòðàííûì, îòòàëêèâàþùèì, è â òîæå âðåìÿ ïðèòÿãèâàþùèì àðîìàòîì\n", 60);
                print("Âàñ ïðîñòî âëå÷åò...\n", 60);
                print("Âû íå â ñèëàõ ñîïðîòèâëÿòñÿ...\n", 60);
                print("Êàê âäðóã âû çàñòûëè â ñàíòèìåòðå îò ñòðàííîãî ñâåðòêà...\n", 60);
                print("1. Ëèçíóòü ãàçåòó\n", 60);
                print("2. Áðîñèòü åå òóò\n", 60);
                while(1)
                {
                    int gazet;
                    cin >> gazet;
                    if(gazet == 1)
                    {
                        print("Åäâà êîñíóâøèñü åå ÿçûêîì, âû ïî÷óâñòâîâàëè íåïðåîäîëèìîå âëå÷åíèå\n", 30);
                        print("Âû çâåðñêè íàáðîñèëèñü íà ýòîò ëèñòîê\n", 30);
                        print("Îí âìèã áûë ïðîãëî÷åí\n", 30);
                        wait(3000)
                        print("Ëèøü ïî ïðîøåñòâèè íåñêîëüêèõ ñåêóíä âû ïðèøëè, äàæå ïîíÿòü, ÷òî ñ âàìè ïðîèçîøëî âû íå ìîæåòå, îäíàêî ÷óâñòâî ãîëîäà çàìåòíî óáàâèëîñü\n", 60);
                        print("×òîáû åùå ÷åãî íå íàòâîðèòü, âû îòîøëè ïîäàëüøå îò òóìáû è ðåøèëè ïîãëÿäåòü íà ÷òî-íèáóäü ìåíåå îïàñíîå\n", 60);
                        wait(2000);
                        clr;
                        break;
                    }
                    else if(gazet == 2)
                    {
                        print("Âû äóìàåòå, ÷òî îáû÷íûé ëèñòîê íå äîñòîèí âàøåãî âíèìàíèÿ è ïðîñòî óäàëÿåòåñü îò òóìáû\n", 60)
                        wait(1000);
                        clr;
                        break;
                    }
                    else
                    {
                        print("Ïîâòîðèòå ïîïûòêó ââîäà\n", 60);
                        wait(1000);
                    }
                    clr;
                    cout << "1. Ëèçíóòü ãàçåòó\n";
                    cout << "2. Áðîñèòü åå òóò\n";
                }
            }


        }
        if(dey == 2)
        {
            act[1] = 0;
            print("Âû âèäåòå îáû÷íóþ ìåòàëè÷åñêóþ ìèñêó ñ âàøèì èìåíåì ñáîêó.\n", 60);
            print("Âû ñðàçó âñïîìèíàåòå, êàê ñ ïåðâîé çàðïëàòû ïîòðàòèëè âíóøèòåëüíóþ ñóììó íà òàêîé ùåäðûé ïîäàðîê ñàìîìó ñåáå.\n", 60);
            print("Òîãäà ýòî êàçàëîñü î÷åíü âíóøèòåëüíîé ïîêóïêîé.\n", 60);
            print("Çàãëÿíóâ â íåå âû âèäèòå âîîäóøåâëÿþùóþ íàäïèñü, êîòîðóþ êîìïàíèÿ SLOPO.inc îñòàâëÿåò íà êàæäîì ñâîåì òîâàðå, 'Çíàé ñâîå ìåñòî', ãëàñèëà îíàþ\n", 60);
            print("Äóìàþ íå ñòîèò ïðåçðèòåëüíî îòíîñèòñÿ ê ñîáñòâåííîé ìèñêå.\n", 60);
            wait(1000);
            print("1. Íàäåòü ìèñêó íà ãîëîâó(áîþñü ìåíÿ íå òàê ïîéìóò)\n", 60);
            print("2. Óäàëèòüñÿ\n", 60);
            while(1)
            {
                int cask;
                cin >> cask;
                if(cask == 1)
                {
                    clr;
                    fin.open("flag.txt");
                    string flag;
                    while(getline(fin, flag))
                    {
                        for(int i = 0; i < flag.size(); i++)
                        {
                            if(flag[i] == '%')
                            {
                                SetColor(4, 0);
                            }
                            else
                            {
                                SetColor(14, 0);
                            }
                            cout << flag[i];
                        }
                        cout << endl;
                    }
                    fin.close();
                }
            }

        }
        if(dey == 3)
        {
            act[2] = 0;
            print("Êàê áû âû íè ñòàðàëèñü, âû ïðîñòî íå ìîæåòå âñïîìíèòü, ÷òî äîëæåí äåëàòü ýòîò 'ìîíñòð'.\n", 60);
            print("Âû áûëî ñîâñåì îò÷àÿëèñü ðàçîáðàòüñÿ ñ ýòèì, êàê âäðóã ïðèáîð ïðåîáðåë ñåò÷àòóþ ñòðóêòóðó, êàê-áóäòî ïåðåä âàìè ãîëîãðàììà.\n", 60);
            print("Ïåðåä ãëàçàìè áåøåíî ïîáåæàëè ñèìâîëû, áóäòî â âàø ìîçã âøèëè òåëåâèçîðþ\n", 60);
            wait(1000);
            for(int i = 0; i < 29998 * 4; i++)
            {
                cout <<char(gen() % 256);
            }
            clr;
            print("Âû ñðàçó âñïîìíèëè âñå îá ýòîì, à ìîæåò è óçíàëè äàæå áîëüùå, âàñ íåìíîãî òîøíèò.\n", 60);
            print("ÈÈ ñîîáùèë, ÷òî ýòî âñòðîåííàÿ ñèñòåìà ðàñïîçíîâàíèÿ îáúåêòîâ, èìïëàíò ïðîåöèðóåò èçîáðàæåíèå ïðÿìî â ìîçã, î÷åíü ïîëåçíàÿ âåùü.\n", 60);
            print("Êàê îêàçàëîñü 'ìîíñòð' - ýòî ïðîñòî ñèñòåìà âûäà÷è çàðïëàòû\n", 60);
            print("Âàì áîëüøå íå÷åãî äåëàòü âîçëå SLOPE(òàê åãî íàçâàë ÈÈ, êñòàòè òîæå ïðîèçâåäåí SLOPPO.inc).\n", 60);
            wait(1000);
        }
        if(dey == 4)
        {
            act[3] = 0;
            print("Âû ïîäõîäèòå ê ïûëüíîé ñòåíå, êàæåòñÿ, áóäòî àëëþìèíèåâûå ëèñòüÿ âîò-âîò îòâàëÿòñÿ îò ñòàëüíîãî êàðêàñà\n", 60);
            print("Îò ïëàêàòà âååò ïðåêðàñíûì àðîìàòîì. Ñóäÿ ïî çàïàõó, îí ïðîëåæàë íå îäèí äåíü ñ ñî÷íûìè îòáèâíûìè â îäíîé òàðåëêå\n", 60);
            print("Òàêæå âèäíà åãî íåîáû÷íàÿ òåêñòóðà, ïðÿìî êàê ó äåðåâà ñ âëàæíûõ áîëîò, äà è òîëùèíà â 1 ñì âàì êàæåòñÿ ñòðàííîé\n", 60);
            print("Èíòåðåñíî îòêóäà ýòè ñòðàííûå ñðàâíåíèÿ, è ÷òî ýòî ñ âàìè ñòàëî?\n", 60);
            print("Õîòÿ ìîæåò ýòî èç-çà ñêàçàííîãî ÈÈ.\n", 60);
            wait(1000);
        }
        if(dey == 5)
        {
            print("Äóìàþ ñ ìåíÿ õâàòèò, ïîäóìàëè âû. Âû âîçðàùàåòåñü â öåíòð êîìíàòû, õîòÿ ÈÈ âèäèìî óñëûøèò âàñ èç ëþáîé òî÷êè ýòîé ïëàíåòû.\n", 60);
            wait(1000);
            break;
        }
        clr;
        if(act[0] == 0)
            SetColor(8, 0);
        print("1.Ïîðûòüñÿ â òóìáî÷êå.", 60);
        cout << endl;
        SetColor(7, 0);
        if(act[1] == 0)
            SetColor(8, 0);
        print("2.Îñìîòðåòü ìåòàëëè÷åñêóþ ìèñêó.", 60);
        cout << endl;
        SetColor(7, 0);
        if(act[2] == 0)
            SetColor(8, 0);
        print("3.Ïîïûòàòüñÿ áîëüøå óçíàòü îá óæàñàþùåì ïðèáîðåÞ, òîð÷àùåãî èç ñòåíû.", 60);
        cout << endl;
        SetColor(7, 0);
        if(act[3] == 0)
            SetColor(8, 0);
        print("4.Îñìîòðåòü ïëàêàò íà ñòåíå.", 60);
        cout << endl;
        SetColor(7, 0);
        if(act[4] == 0)
            SetColor(8, 0);
        print("5.Äóìàþ ñ ìåíÿ õâàòèò (âåðíóòüñÿ ê LAI).", 60);
        SetColor(7, 0);
    }
}



void logo()
{


    cout<<"##~~##~~####~~#####~~#####~~~~~~##~~~~~######~#####"<<endl;
    wait(1000);
    cout<<"##~~##~##~~##~##~~##~##~~~~~~~~~##~~~~~~~##~~~##"<<endl;
    wait(1000);
    cout<<"######~##~~##~#####~~####~~~~~~~##~~~~~~~##~~~####"<<endl;
    wait(1000);
    cout<<"##~~##~##~~##~##~~~~~##~~~~~~~~~##~~~~~~~##~~~##"<<endl;
    wait(1000);
    cout<<"##~~##~~####~~##~~~~~#####~~##~~######~######~#####"<<endl;
    wait(1000);
    for(int i = 0; i < 10; i++)
    {
        clr;
        cout<<"##~~##~~####~~#####~~#####~~~~~~##~~~~~######~#####"<<endl;
        cout<<"##~~##~##~~##~##~~##~##~~~~~~~~~##~~~~~~~##~~~##"<<endl;
        cout<<"######~##~~##~#####~~####~~~~~~~##~~~~~~~##~~~####"<<endl;
        cout<<"##~~##~##~~##~##~~~~~##~~~~~~~~~##~~~~~~~##~~~##"<<endl;
        cout<<"##~~##~~####~~##~~~~~#####~~##~~######~######~#####"<<endl;
        clr;
        wait(gen()%200);
    }
    wait(3000);
    clr;
}


