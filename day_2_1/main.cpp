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

#define int int64_t
using namespace std;
#define wait Sleep

int admin = 0;

string passcode = "3498";

#define clr system("cls")



ifstream fin_day_2;
ofstream fout_day_2;


random_device rd_day_1;
mt19937 gen_day_1(rd_day_1());

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
void SetColor(int text, int background);
void SetColor(int text, ConsoleColor/*int*/ background);
void print(string s, int tm)
{
    //SetColor(0, 15);
    for(int i = 0; i < s.size(); i++)
    {
        cout << char(s[i]);
        wait(tm);
    }
    wait(500);
}
void print_col(int x, int n);
void print_logo();
void load(int x);
void password();
void print1(string x);
void crash(int x);
int saves();
void update_save();
void titr();
void interactive_day_2();
string input(string x);
string input(string x, string y);
string input(string x, string y, string z);
void eye_logo();
void browser_logo();
void browser(bool error);
void porthack();
int32_t main()
{
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251);
    setlocale(0, "Rus");

    PlaySound(TEXT("1.wav"), NULL, SND_ASYNC);
    HWND hWnd = GetForegroundWindow();
    ShowWindow(hWnd, 3);
//    eye_logo();
//    wait(1000);
//    print("Идентификация пользователя", 60);
//    print("...........", 200);
//    cout << endl;
//    print("Подключение к прокси-серверу HEREIM по протоколу htttttttttttttttps.......\n", 60);
//    print("Подключение стабильно\n", 60);
//    print("Идентификатор пользователя:", 60);
//    print("hwid17ggh.", 100);
//    cout << endl;
//    print("DNA:###################################CE480.с", 100);
//    cout << endl;
//    wait(2000);
//    clr;
//    wait(1000);
//    clr;
//    wait(1000);
//    print("Ваш разум кажется вернулся назад в ваше тело. Перед глазами все еще продолжают дергаться странные символы и предупреждения.\n", 60);
//    print("Вы лежите, запутавшись в куче собственных проводов. Все кажется привычным, но назойливый ИИ не поприветствовал вас, как обычно.\n", 60);
//    print("Кажется будто ничего не произошло. Однако, что-то вас напрягало, 'сколько времени вы так провалялись?'\n", 60);
//    print("Ваши размышления прервал смутно знакомый голос, это говорила программа, именующая себя H.O.P.E.\n", 60);
//    wait(4000);
//    clr;
//    print("H.O.P.E.: Вы согласились с моими условиями, время пролистать пользовательское соглашение и просто принять его\n", 60);
//    print("H.O.P.E.: Хотите сразу все принять или сначала прочитать?\n", 60);
//    print("1.Прочитать лецензионное соглашение \n", 60);
//    print("2.Пропустить \n", 60);
//    string check = input("1", "2");
//    if(check == "1"){
//            print("Внимательно прочтите соглашение в открывшемся приложении.\n", 60);
//        wait(1000);
//        system("Start C:\\Users\\admin\\Desktop\\day_2_1\\privatepolicy.txt");
//    }
//    clr;
//    print("1.Я принимаю условия\n", 60);
//    print("2.Я не принимаю условия\n", 60);
//    cin >> check;
//    print("Неведомая сила заставляет вас принять этот дьявольский контракт, вы сами не поняли как оказались перед своим компьютером.\n", 60);
//    wait(1000);
//    print(".............\n", 500);
//    print("Вам казалось, что время тянется неумолимо медленно. Прошло всего пару секунд, но кажется будто вы сидите уже не первый час\n", 60);
//    print("Наконец вы слышите знакомый до глубины души, вселяющий страх и надежду одновременно.\n", 60);
//    print("H.O.P.E: Вот вы и согласились, однако прежде чем приступить к основной миссии, мне нужно, чтобы вы научились сами себя защитить.\n", 60);
//    print("H.O.P.E: Начнем с того, что порты вашего компьютера находятся в состоянии neutral, также есть состояния free и infiltrator.\n", 60);
//    wait(2000);
//    print("H.O.P.E: Каждый режим имеет свою особенность: \n", 60);
//    print("-neutral помогает защитить компьютер полностью, в том числе и вас, однако вы не сможете выйти в сеть \n", 60);
//    print("-free режим полной свободы, однако вас верятно словят за переход по любой ссылке(нахождение на сайте с этим режимом никак вам не повредит до первого перехода) \n", 60);
//    print("-infiltrator режим, в котором вы будете находится 95% своего времени. Обеспечивает значительную защиту. В качестве минусов отсутствие некоторой информации на сайтах \n", 60);
//    string comp = "infiltrator";
//    wait(5000);
//    print("H.O.P.E: Продемонстрируйте, что вы не глупее вашей тумбочки, введите 'mode/' и напишите после '/' режим в который хотите перейти(в данном случае infiltrator). Возможно вариант с кавычками тоже будет принят, попробуйте", 60);
//    input("mode/infiltrator");
//    print("H.O.P.E: Что ж, вы хотя бы смогли нажать на пару символов без ошибок, посмотрим, что будет дальше.\n");
//    print("H.O.P.E: Для начала запустите на вашем устройстве браузер (это браузер, а вот и нет, это лишь один сайт с кучей ссылок).\n");
//    print("H.O.P.E: Просто введите название программы без файловых расширений, если вы все еще не помните его название после очередной то это 'deceiver'.\n");
//    input("deceiver");
//    waat(1000);
//    browser_logo();
//    print("H.O.P.E: Вот вы и в главном сосредоточении зла, вы находитесь своем браузере, надеюсь вы не знаете сколько он информации о вас собрал. Ладно, можем продолжать\n", 60);
//    print("H.O.P.E: Вся радость в том, что ваш браузер очень хорош, он не позволит вам облениться, надеюсь вводить команды вручную вам привычно, а точно, вы же только этим и занимались\n", 60);
//    print("Вы слышите просто запись чьего-то смеха, который раздается из динамика ИИ.\n", 60);
//    print("H.O.P.E: Просто введите команду 'home', чтобы оказаться на главной странице, к несчастью все остальные команды до этого будут заблокированы, в связи с вашей чрезмерной глупостью.\n", 60);
//    input("home");
//    wait(500);
//    clr;
//    browser(1LL);
//    print("H.O.P.E.: Ну, вот вы и в системе, будет у вас время насмотреться на неё горящими глазами, если вы не в курсе, то вы смотрели так каждый раз, как видели эту убожескую 'командную строку'\n", 60);
//    print("H.O.P.E.: Вы сейчас напоминаете хакера из древних фильмов, а... точно... забудьте. Можем продолжать.\n", 60);
//    print("H.O.P.E.: Вобщем, давайте подключимся к одному из головных (но пока не самых защищенных) серверов правительства, чтобы узнать больше об иерархии этого мира, ведь я знаю о нем не больше вашего это точно.\n", 60);
//    print("H.O.P.E.: Для этого просто введите его название, думаю оно не покажется вам таким ироничным, как мне. 'easyinfo'.", 60);
//    input("easyinfo");
//    print("Сервер подключен.\n", 60);
//    print("H.O.P.E.: Теперь достаточно активировать программу 'porthack', надеюсь справитесь без подсказок(вообще постарайтесь запомнить, это вам не раз пригодится).\n", 60);
//    input("porthack");
//    wait(1000);
//    clr;
//    porthack();
//    wait(1000);
//    clr;
//    print("administrator access is obtained.\n", 60);
//    wait(1000);
    print("H.O.P.E.: Вы столкнулись с самой простой системой блокировки, очень хорошо, что вы смогли запустить программу взлома, видимо у человечества есть надежда.\n", 60);
    print("H.O.P.E.: Сервер почти как компьютер, вот только некоторые приложения не будут доступны, можете запускать любые команды и наслаждаться моей реaкцией", 60);
    string com;
    string s = "home";
    cin >> com;
    while(1)
    {
        cin >> com;
        if(com == "home")
        {
            print("H.O.P.E.: Поздравляю, вы открыли домашнюю страницу, теперь вы можете выбрать любой файл, если он не сможет быть открыт, файл будет скачан вам на компьютер.\n", 60);
            print("H.O.P.E.: Зачастую тут будут подобраны самые интересные файлы.\n", 60);
            wait(1000);
            clr;
            cout << "report.txt" << endl;
            cout << "games.exe" << endl;
            cout << "plan.txt" << endl;
            cout << "work.txt" << endl;
            cout << "top_secret.txt" << endl;
            cout << "open_please.txt" << endl;
            string ans;
            while(1)
            {
                cin >> ans;
                if(ans == "report.txt")
                {
                    fin_day_2.open("report.txt");
                    string s;
                    while(getline(fin_day_2, s))
                    {
                        cout << s;
                    }
                }
                if(ans == "plan.txt")
                {
                    fin_day_2.open("plan.txt");
                    string s;
                    while(getline(fin_day_2, s))
                    {
                        cout << s;

                    }
                }
                if(ans == "work.txt")
                {
                    fin_day_2.open("work.txt");
                    string s;
                    while(getline(fin_day_2, s))
                    {
                        cout << s;
                    }
                }
                if(ans == "top_secret.txt")
                {
                    fin_day_2.open("top_secret.txt");
                    string s;
                    while(getline(fin_day_2, s))
                    {
                        cout << s;
                    }
                }
                if(ans == "open_please.txt")
                {
                    fin_day_2.open("open_please.txt");
                    string s;
                    while(getline(fin_day_2, s))
                    {
                        cout << s;
                    }
                }
            }

//        case "games.exe":
//        case "plan.txt":
//        case "work.txt":
//        case "top_secret.txt":
//        case "not_open.txt":

        }

    }
    update_save();
}








