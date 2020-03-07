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

using namespace std;
#define wait(a); Sleep(a);


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

//#define print(s, tm); print(s, 0);
//#define Sleep(a) Sleep(0)
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
    print1 ("Перезагрузка.....");
    cout<<endl;
    wait (1500);
    print1 ("Восстановление данных.....");
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
    for(int i = 0 ; i < 6 ; i++)
    {
        print1("Процессов осталось:");
        cout << col;
        cout << endl;
        int a = gen()%4, b = gen()%5;
        int ot = a + b;
        cout << a << '+' << b << '=\n';if(i == 5)cout << "3453468928938 + 34547677634\n";
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
            print1("L.A.I:Вы неудачно решили процесс, попробуйте еще раз");
            cout << endl;
            print1("Процессов осталось:");
            cout << col;
            cout << endl;
            cout << a << '+' << b << '=';
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
    print("Хотите продолжить с последнего сохранения? (Y/N)", 60);
    cout << endl;
    print("Ввод пользователя:", 60);
    string save;
    while(save!= "Y" && save != "N")
    {
        cin >> save;
        if(save!= "Y" && save != "N")
        {
            cout << endl;
            print("Системное оповещение: Повторите попытку ввода...", 60);
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
    print("Введите номер главы от 1 до 12.", 60);
    cout <<endl;
    while(num_save < 1 || num_save >12)
    {
        print("Ввод пользователя: ", 60);
        cin >> num_save;
        if(num_save < 1 || num_save > 12)
        {
            cout << endl;
            print("Системное оповещение: Повторите попытку ввода...", 60);
            cout << endl;
        }
        else
        {


            fin.open("saves.txt");
            fin >> nm_save;
            if(nm_save < num_save)
                print("Системное оповещение: Повторите попытку ввода, вы не имеете доступа к этой главе...", 60);
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
        print("Вы еще не представились системе, введите имя вашего персонажа в формате ИМЯ_ФАМИЛИЯ", 60);
        cout << endl;
        cin >> nickname;
        while(nickname != "Steve175RN34_Emptine")
        {
            print("SYSTEM: Это имя уже занято, из свободных только Steve175RN34_Emptine", 60);
            cout << endl;
            cin >> nickname;
        }
        print("Пользователь успешно зарегистрирован, приятного дня.", 60);
        fout.open("nick.txt");
        fout << nickname;
        fout.close();
        crash(500);
    }
}


void titr()
{
    print ("Ошибка восстановления данных.....", 50);
    cout <<endl;
    wait (1000);
    print ("Утеря данных.", 50);
    cout <<endl;
    wait (1000);
    print ("Cброс данных пользователя.....", 50);
    cout<<endl;
    wait (2000);
    print ("Cпасибо за проведённое время в игре Hope In Lies.",60);
    wait (3000);
    cout <<endl;
    print ("Продолжение следует...", 150);
    cout << endl;
    wait (1500);
    print ("Предложения своих идей для продолжения сюжета, отправлять в личные сообщения группы, ссылка в файле contacts.txt.",60);
    cout<<endl;
    wait(1000);
    clr;
    print("Во всем есть красота, но не каждый ее замечает. Энди Уорхол(с).", 60);
    cout << endl;
    wait(3000);
    clr;
    print("Автор идеи: Bill, Dedalius.", 60);
    cout << endl;
    print("Технические наработки и релиз: Dedalius, game ruiner, TemaTop.", 60);
    cout << endl;
    print("Дизайн: Кускова Юлия, Балюконис Милана.", 60);
    cout << endl;
    print("Менеджер команды разработки: VaryaSch.", 60);
    cout << endl;
    wait(3000);
    print("Огромная благодарность всем нашим друзьям и близким, спасибо, что верили в нас.", 60);
    cout << endl;
    wait(1000);
    print("Завершение работы.", 60);
    print("...", 160);
}



void estimation()
{
    print("Идентификация пользователя", 60);
    print("...........", 200);
    cout << endl;
    wait(400);
    clr;
    print("L.A.I:Вас снова приветствует L.A.I", 50);
    cout << endl;
    wait(1000);
    print("L.A.I:Доброе утро, Steve175RN34 Emptine", 60);
    cout << endl;
    wait(1000);
    print("L.A.I: Прошу снова оцените ваше самочувствие по шкале от 1 до 1000, не забывайте, что ваш идентификатор подозрительности на данный момент равен 0", 60);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    print("L.A.I:Ожидание ввода пользователя", 50);
    print("...", 1000);
    cout << endl;
    print("Steve:", 60);
    int player_in_estimation;
    cin >> player_in_estimation;
    if(player_in_estimation <= 300)
    {
        print("L.A.I:Возможно этого недостаточно, увеличить дозу", 60);
        clr;
        estimation();
    }
    if(player_in_estimation >= 301 && player_in_estimation <= 999)
    {
        print("L.A.I:Думаю мы почти добились результата, увеличить дозу", 60);
        cout << endl;
        clr;
        print("Вы чувствуете, что отключаетесь", 60);
        estimation();
    }
    if(player_in_estimation >= 1000)
    {
        print("L.A.I:Очень хорошо, продолжим наш разговор", 60);
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
        print("Ошибка ввода, повторите попытку\n", 60);
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
        print("Ошибка ввода, повторите попытку\n", 60);
        cin >> ans;
    }
    return ans;
}

void interactive_day_1()
{
    int dey = -1;
    int act[] = {1, 1, 1, 1, 1};
    int ach = 0;
    while(dey != 4)
    {
        cin >> dey;

        while(dey > 5 || dey < 1 || act[dey - 1] != 1)
        {
            print("Некорректный ввод. Повторите попытку ввода.\n", 60);
            cin >> dey;
        }
        if(dey == 1)
        {
            if(act[0] == 1)
            {
                act[0] = 0;
                wait(1000);
                print("Немного повозившись с покореженной тумбой, вы наконец смогли вытащить единственный незапертый ящик из какого-то странного вида пластмассы (как ни странно остальные были просто целиком из стальных пластин).\n", 60);
                print("Внутри лежало множество разнообразной литературы разной степени качества. На самом верху виднелись три толстенных книги в пыльной, почти что каменной обложке. От самой книги так и пахло старой и забытой типографией.\n", 60);
                print(" В разных местах, между огромным количеством страниц лежат неаккуратно вырезанные вами закладки, похожие на обрывки вашей утренней газеты. Сами книги представляли из себя тома в более чем 1000 страниц, на каждой была надпись вроде: 'КАК БЫТЬ ХОРОШИМ ГРАЖДАНИНОМ' и 'ЗНАЙ ЗАКОНЫ И ПРАВА'. Странно, но сами книги содержали не только бесконечные законы, но и наказание следующие за их нарушение разной степени жестокости./n", 60);
                print(" На обороте было написано: 'ПРОЧТИТЕ ПОЛНЫЙ ЦИКЛ ИЗ 175 СБОРНИКОВ СБОРНИКОВ ЗАКОНОВ И СТАНЬТЕ ВЕРНЫМ ГРАЖДАНИНОМ!'. Чуть ниже виднелся номер издания и надпись: Издательство 'Правда'.", 70);
                print(" Вы хорошо помните как руководство прислало вам эти тома бумажек с чернилами, как напоминание того, как должен вести себя верный своей стране гражданин и что происходит с 'неправильными' гражданами. ", 60);
                print(" Под тяжёлыми томами лежала она -", 70);
                wait(500);
                print(" В прочной глянцевой обложке, покрытой тонким аккуратным слоем лака, отражающим лучи тусклой лампы, фолиант, с кучей цветных закладок, образующих целый красочный лес из ленточек разных размеров и так приятных глазу красок, которых всегда так мало в вашей комнате.", 70);
                print(" Издание будто поглащало свет лампы и преумножала его в несколько раз, а потом отбрасывало на вас тёплые, щекочущие ваше лицо лучики.", 70);
                wait(700);
                print(" Оно сияло.", 80);
                print(" Сияло, как маленькое солнце, что вы уже очень давно не видели.", 80);
                print(" Сама книга была за издательством министерства правды. Повествовала она об удивительных приключениях так похожего на вас гражданина без имени, что встречается с разными трудностями и путём своего знания законов и правил выбирается из любых передряг.", 70);
                print(" Издание не сильно отличалась от тех трёх томов текста, в ней даже не было никаких картинок. По сути в ней были всё теже законы, краска и бумага, но в другой, немного более цветастой обёртке.", 70);
                print(" Однако вам совсем не до этого. Вы помнили лишь хорошее об этой книге, вы читали её несколько раз, возможно уже и с десяток, некоторые реплики вы знали наизусть, это была ваша первая книга, первая книга заработанная только вами, за ваши деньги, полная истёртых закладок, сделаных из кусочков плаката, ещё кое-как сохранивших свои прежние цвета.", 70);
                print(" Свет, излучаемый рассказом в обложке, был даже тусклее вашей и так тусклой лампы.", 70);
                print(" Вы ещё несколько минут улыбались, листая шебуршавшие совсем немного пожелтевшие страницы и вспоминая о сюжете книги, вы даже немного посмеивались бережно листая страницы.", 70);
                print(" Больше ничего интересного в опшарпаной тумбочке не оказалось.\n", 60);
                print(" Вы бережно положили вашу находку в самый низ, и осторожно положили на неё тома законов, после чего закрыли ящик.", 70);
                wait(1000);
                print("Больше ничего интересного в опшарпаной тумбочке не оказалось.\n", 60);
                wait(1000);
                print("Однако ваше внимания привлек погрызенный сверток бумаги, полностью пропечатанный надписями вроде: 'НАША СТРАНА...', 'ПОЗДРАВИМ ГОСПОДИНА X С 122-ЛЕТИ...', 'САМЫЕ ВЫГОДНЫЕ ВАКАН...'\n", 60);
                print("От него веяло странным, отталкивающим, и в тоже время притягивающим ароматом\n", 60);
                print("Вас просто влечет...\n", 60);
                print("Вы не в силах сопротивлятся...\n", 60);
                print("Как вдруг вы застыли в сантиметре от странного свертка...\n", 60);
                print("1. Лизнуть газету\n", 60);
                print("2. Бросить ее тут\n", 60);
                while(1)
                {
                    int gazet;
                    cin >> gazet;
                    if(gazet == 1)
                    {
                        print("Едва коснувшись ее языком, вы почувствовали непреодолимое влечение\n", 30);
                        print("Вы зверски набросились на этот листок\n", 30);
                        print("Он вмиг был проглочен\n", 30);
                        wait(3000);
                        print("Лишь по прошествии нескольких секунд вы пришли, даже понять, что с вами произошло вы не можете, однако чувство голода заметно убавилось\n", 60);
                        print("Чтобы еще чего не натворить, вы отошли подальше от тумбы и решили поглядеть на что-нибудь менее опасное\n", 60);
                        wait(2000);
                        clr;
                        break;
                    }
                    else if(gazet == 2)
                    {
                        print("Вы думаете, что обычный листок не достоин вашего внимания и просто удаляетесь от тумбы\n", 60)
                        wait(1000);
                        clr;
                        ach++;
                        break;
                    }
                    else
                    {
                        print("Повторите попытку ввода\n", 60);
                        wait(1000);
                    }
                    clr;
                    cout << "1. Лизнуть газету\n";
                    cout << "2. Бросить ее тут\n";
                }
            }


        }
        if(dey == 2)
        {
            act[1] = 0;
            print("Вы видете обычную металическую миску с вашим именем сбоку.\n", 60);
            print("Вы сразу вспоминаете, как с первой зарплаты потратили внушительную сумму на такой щедрый подарок самому себе.\n", 60);
            print("Тогда это казалось очень внушительной покупкой.\n", 60);
            print("Заглянув в нее вы видите воодушевляющую надпись, которую компания SLOPO.inc оставляет на каждом своем товаре, 'Знай свое место', гласила онаю\n", 60);
            print("Думаю не стоит презрительно относится к собственной миске.\n", 60);
            wait(1000);
            print("1. Надеть миску на голову(боюсь меня не так поймут)\n", 60);
            print("2. Удалиться\n", 60);
            while(1)
            {
                int cask;
                cin >> cask;
                if(cask == 1)
                {
                    clr;
                    fin.open("flag.txt");
                    string flag;
                    ach++;
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
                else
                {
                    break;
                }

            }

        }
        if(dey == 3)
        {
            act[2] = 0;
            print("Как бы вы ни старались, вы просто не можете вспомнить, что должен делать этот 'монстр'.\n", 60);
            print("Вы было совсем отчаялись разобраться с этим, как вдруг прибор преобрел сетчатую структуру, как-будто перед вами голограмма.\n", 60);
            print("Перед глазами бешено побежали символы, будто в ваш мозг вшили телевизорю\n", 60);
            wait(1000);
            for(int i = 0; i < 29998 * 4; i++)
            {
                cout <<char(gen() % 256);
            }
            clr;
            print("Вы сразу вспомнили все об этом, а может и узнали даже больще, вас немного тошнит.\n", 60);
            print("ИИ сообщил, что это встроенная система распознования объектов, имплант проецирует изображение прямо в мозг, очень полезная вещь.\n", 60);
            print("Как оказалось 'монстр' - это просто система выдачи зарплаты\n", 60);
            print("Вам больше нечего делать возле SLOPE(так его назвал ИИ, кстати тоже произведен SLOPPO.inc).\n", 60);
            wait(1000);
        }
        if(dey == 4)
        {
            act[3] = 0;
            print("Вы подходите к пыльной стене, кажется, будто аллюминиевые листья вот-вот отвалятся от стального каркаса\n", 60);
            print("От плаката веет прекрасным ароматом. Судя по запаху, он пролежал не один день с сочными отбивными в одной тарелке\n", 60);
            print("Также видна его необычная текстура, прямо как у дерева с влажных болот, да и толщина в 1 см вам кажется странной\n", 60);
            print("Интересно откуда эти странные сравнения, и что это с вами стало?\n", 60);
            print("Хотя может это из-за сказанного ИИ.\n", 60);
            wait(1000);
        }
        if(dey == 5)
        {
            print("Думаю с меня хватит, подумали вы. Вы возращаетесь в центр комнаты, хотя ИИ видимо услышит вас из любой точки этой планеты.\n", 60);
            wait(1000);
            break;
        }
        if(dey == 6 && act[5] == 0){
            print("6.ДИМА! тут каккое-нибудь действие типа просто постоять у окна(его нет) или типа того.", 60);
        }
        int root = 0;
        for(int i = 0; i < 4; i++)
            root += act[i];
        clr;
        if(act[0] == 0)
            SetColor(8, 0);
        print("1.Порыться в тумбочке.", 60);
        cout << endl;
        SetColor(7, 0);
        if(act[1] == 0)
            SetColor(8, 0);
        print("2.Осмотреть металлическую миску.", 60);
        cout << endl;
        SetColor(7, 0);
        if(act[2] == 0)
            SetColor(8, 0);
        print("3.Попытаться больше узнать об ужасающем прибореЮ, торчащего из стены.", 60);
        cout << endl;
        SetColor(7, 0);
        if(act[3] == 0)
            SetColor(8, 0);
        print("4.Осмотреть плакат на стене.", 60);
        cout << endl;
        SetColor(7, 0);
        if(act[4] == 0)
            SetColor(8, 0);
        print("5.Думаю с меня хватит (вернуться к LAI).", 60);
        SetColor(7, 0);
        if(root == 0)
        {
            act[5] = 0;
            fout.open("achievement.txt");
            fout << "Geduld, mein Freund";
            fout.close();
        }
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

using namespace std;
#define wait(a); Sleep(a);


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

//#define print(s, tm); print(s, 0);
//#define Sleep(a) Sleep(0)
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
    print1 ("Перезагрузка.....");
    cout<<endl;
    wait (1500);
    print1 ("Восстановление данных.....");
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
    for(int i = 0 ; i < 6 ; i++)
    {
        print1("Процессов осталось:");
        cout << col;
        cout << endl;
        int a = gen()%4, b = gen()%5;
        int ot = a + b;
        cout << a << '+' << b << '=\n';if(i == 5)cout << "3453468928938 + 34547677634\n";
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
            print1("L.A.I:Вы неудачно решили процесс, попробуйте еще раз");
            cout << endl;
            print1("Процессов осталось:");
            cout << col;
            cout << endl;
            cout << a << '+' << b << '=';
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
    print("Хотите продолжить с последнего сохранения? (Y/N)", 60);
    cout << endl;
    print("Ввод пользователя:", 60);
    string save;
    while(save!= "Y" && save != "N")
    {
        cin >> save;
        if(save!= "Y" && save != "N")
        {
            cout << endl;
            print("Системное оповещение: Повторите попытку ввода...", 60);
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
    print("Введите номер главы от 1 до 12.", 60);
    cout <<endl;
    while(num_save < 1 || num_save >12)
    {
        print("Ввод пользователя: ", 60);
        cin >> num_save;
        if(num_save < 1 || num_save > 12)
        {
            cout << endl;
            print("Системное оповещение: Повторите попытку ввода...", 60);
            cout << endl;
        }
        else
        {


            fin.open("saves.txt");
            fin >> nm_save;
            if(nm_save < num_save)
                print("Системное оповещение: Повторите попытку ввода, вы не имеете доступа к этой главе...", 60);
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
        print("Вы еще не представились системе, введите имя вашего персонажа в формате ИМЯ_ФАМИЛИЯ", 60);
        cout << endl;
        cin >> nickname;
        while(nickname != "Steve175RN34_Emptine")
        {
            print("SYSTEM: Это имя уже занято, из свободных только Steve175RN34_Emptine", 60);
            cout << endl;
            cin >> nickname;
        }
        print("Пользователь успешно зарегистрирован, приятного дня.", 60);
        fout.open("nick.txt");
        fout << nickname;
        fout.close();
        crash(500);
    }
}


void titr()
{
    print ("Ошибка восстановления данных.....", 50);
    cout <<endl;
    wait (1000);
    print ("Утеря данных.", 50);
    cout <<endl;
    wait (1000);
    print ("Cброс данных пользователя.....", 50);
    cout<<endl;
    wait (2000);
    print ("Cпасибо за проведённое время в игре Hope In Lies.",60);
    wait (3000);
    cout <<endl;
    print ("Продолжение следует...", 150);
    cout << endl;
    wait (1500);
    print ("Предложения своих идей для продолжения сюжета, отправлять в личные сообщения группы, ссылка в файле contacts.txt.",60);
    cout<<endl;
    wait(1000);
    clr;
    print("Во всем есть красота, но не каждый ее замечает. Энди Уорхол(с).", 60);
    cout << endl;
    wait(3000);
    clr;
    print("Автор идеи: Bill, Dedalius.", 60);
    cout << endl;
    print("Технические наработки и релиз: Dedalius, game ruiner, TemaTop.", 60);
    cout << endl;
    print("Дизайн: Кускова Юлия, Балюконис Милана.", 60);
    cout << endl;
    print("Менеджер команды разработки: VaryaSch.", 60);
    cout << endl;
    wait(3000);
    print("Огромная благодарность всем нашим друзьям и близким, спасибо, что верили в нас.", 60);
    cout << endl;
    wait(1000);
    print("Завершение работы.", 60);
    print("...", 160);
}



void estimation()
{
    print("Идентификация пользователя", 60);
    print("...........", 200);
    cout << endl;
    wait(400);
    clr;
    print("L.A.I:Вас снова приветствует L.A.I", 50);
    cout << endl;
    wait(1000);
    print("L.A.I:Доброе утро, Steve175RN34 Emptine", 60);
    cout << endl;
    wait(1000);
    print("L.A.I: Прошу снова оцените ваше самочувствие по шкале от 1 до 1000, не забывайте, что ваш идентификатор подозрительности на данный момент равен 0", 60);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    print("L.A.I:Ожидание ввода пользователя", 50);
    print("...", 1000);
    cout << endl;
    print("Steve:", 60);
    int player_in_estimation;
    cin >> player_in_estimation;
    if(player_in_estimation <= 300)
    {
        print("L.A.I:Возможно этого недостаточно, увеличить дозу", 60);
        clr;
        estimation();
    }
    if(player_in_estimation >= 301 && player_in_estimation <= 999)
    {
        print("L.A.I:Думаю мы почти добились результата, увеличить дозу", 60);
        cout << endl;
        clr;
        print("Вы чувствуете, что отключаетесь", 60);
        estimation();
    }
    if(player_in_estimation >= 1000)
    {
        print("L.A.I:Очень хорошо, продолжим наш разговор", 60);
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
        print("Ошибка ввода, повторите попытку\n", 60);
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
        print("Ошибка ввода, повторите попытку\n", 60);
        cin >> ans;
    }
    return ans;
}

void interactive_day_1()
{
    int dey = -1;
    int act[] = {1, 1, 1, 1, 1};
    int ach = 0;
    while(dey != 4)
    {
        cin >> dey;

        while(dey > 5 || dey < 1 || act[dey - 1] != 1)
        {
            print("Некорректный ввод. Повторите попытку ввода.\n", 60);
            cin >> dey;
        }
        if(dey == 1)
        {
            if(act[0] == 1)
            {
                act[0] = 0;
                wait(1000);
                print("Немного повозившись с покореженной тумбой, вы наконец смогли вытащить единственный незапертый ящик из какого-то странного вида пластмассы(как ни странно остальные были просто целиком из стальных пластин).\n", 60);
                print("Внутри лежало 3 толстенных книги ывв шебуршащей обложке.\n", 60);
                print("Это были три тома в 1000 страниц, на каждой было написано: 'КАК БЫТЬ ХОРОШИМ ГРАЖДАНИНОМ. ЗНАЙ ЗАКОНЫ И ПРАВА' и конечно том 1, 2, 3(как оказалось их 175)./n", 60);
                print("Больше ничего интересного в опшарпаной тумбочке не оказалось.\n", 60);
                wait(1000);
                print("Однако ваше внимания привлек погрызенный сверток бумаги, полностью пропечатанный надписями вроде: 'НАША СТРАНА...', 'ПОЗДРАВИМ ГОСПОДИНА X С 122-ЛЕТИ...', 'САМЫЕ ВЫГОДНЫЕ ВАКАН...'\n", 60);
                print("От него веяло странным, отталкивающим, и в тоже время притягивающим ароматом\n", 60);
                print("Вас просто влечет...\n", 60);
                print("Вы не в силах сопротивлятся...\n", 60);
                print("Как вдруг вы застыли в сантиметре от странного свертка...\n", 60);
                print("1. Лизнуть газету\n", 60);
                print("2. Бросить ее тут\n", 60);
                while(1)
                {
                    int gazet;
                    cin >> gazet;
                    if(gazet == 1)
                    {
                        print("Едва коснувшись ее языком, вы почувствовали непреодолимое влечение\n", 30);
                        print("Вы зверски набросились на этот листок\n", 30);
                        print("Он вмиг был проглочен\n", 30);
                        wait(3000);
                        print("Лишь по прошествии нескольких секунд вы пришли, даже понять, что с вами произошло вы не можете, однако чувство голода заметно убавилось\n", 60);
                        print("Чтобы еще чего не натворить, вы отошли подальше от тумбы и решили поглядеть на что-нибудь менее опасное\n", 60);
                        wait(2000);
                        clr;
                        break;
                    }
                    else if(gazet == 2)
                    {
                        print("Вы думаете, что обычный листок не достоин вашего внимания и просто удаляетесь от тумбы\n", 60)
                        wait(1000);
                        clr;
                        ach++;
                        break;
                    }
                    else
                    {
                        print("Повторите попытку ввода\n", 60);
                        wait(1000);
                    }
                    clr;
                    cout << "1. Лизнуть газету\n";
                    cout << "2. Бросить ее тут\n";
                }
            }


        }
        if(dey == 2)
        {
            act[1] = 0;
            print("Вы видете обычную металическую миску с вашим именем сбоку.\n", 60);
            print("Вы сразу вспоминаете, как с первой зарплаты потратили внушительную сумму на такой щедрый подарок самому себе.\n", 60);
            print("Тогда это казалось очень внушительной покупкой.\n", 60);
            print("Заглянув в нее вы видите воодушевляющую надпись, которую компания SLOPO.inc оставляет на каждом своем товаре, 'Знай свое место', гласила онаю\n", 60);
            print("Думаю не стоит презрительно относится к собственной миске.\n", 60);
            wait(1000);
            print("1. Надеть миску на голову(боюсь меня не так поймут)\n", 60);
            print("2. Удалиться\n", 60);
            while(1)
            {
                int cask;
                cin >> cask;
                if(cask == 1)
                {
                    clr;
                    fin.open("flag.txt");
                    string flag;
                    ach++;
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
                else
                {
                    break;
                }

            }

        }
        if(dey == 3)
        {
            act[2] = 0;
            print("Как бы вы ни старались, вы просто не можете вспомнить, что должен делать этот 'монстр'.\n", 60);
            print("Вы было совсем отчаялись разобраться с этим, как вдруг прибор преобрел сетчатую структуру, как-будто перед вами голограмма.\n", 60);
            print("Перед глазами бешено побежали символы, будто в ваш мозг вшили телевизорю\n", 60);
            wait(1000);
            for(int i = 0; i < 29998 * 4; i++)
            {
                cout <<char(gen() % 256);
            }
            clr;
            print("Вы сразу вспомнили все об этом, а может и узнали даже больще, вас немного тошнит.\n", 60);
            print("ИИ сообщил, что это встроенная система распознования объектов, имплант проецирует изображение прямо в мозг, очень полезная вещь.\n", 60);
            print("Как оказалось 'монстр' - это просто система выдачи зарплаты\n", 60);
            print("Вам больше нечего делать возле SLOPE(так его назвал ИИ, кстати тоже произведен SLOPPO.inc).\n", 60);
            wait(1000);
        }
        if(dey == 4)
        {
            act[3] = 0;
            print("Вы подходите к пыльной стене, кажется, будто аллюминиевые листья вот-вот отвалятся от стального каркаса\n", 60);
            print("От плаката веет прекрасным ароматом. Судя по запаху, он пролежал не один день с сочными отбивными в одной тарелке\n", 60);
            print("Также видна его необычная текстура, прямо как у дерева с влажных болот, да и толщина в 1 см вам кажется странной\n", 60);
            print("Интересно откуда эти странные сравнения, и что это с вами стало?\n", 60);
            print("Хотя может это из-за сказанного ИИ.\n", 60);
            wait(1000);
        }
        if(dey == 5)
        {
            print("Думаю с меня хватит, подумали вы. Вы возращаетесь в центр комнаты, хотя ИИ видимо услышит вас из любой точки этой планеты.\n", 60);
            wait(1000);
            break;
        }
        if(dey == 6 && act[5] == 0){
            print("6.ДИМА! тут каккое-нибудь действие типа просто постоять у окна(его нет) или типа того.", 60);
        }
        int root = 0;
        for(int i = 0; i < 4; i++)
            root += act[i];
        clr;
        if(act[0] == 0)
            SetColor(8, 0);
        print("1.Порыться в тумбочке.", 60);
        cout << endl;
        SetColor(7, 0);
        if(act[1] == 0)
            SetColor(8, 0);
        print("2.Осмотреть металлическую миску.", 60);
        cout << endl;
        SetColor(7, 0);
        if(act[2] == 0)
            SetColor(8, 0);
        print("3.Попытаться больше узнать об ужасающем прибореЮ, торчащего из стены.", 60);
        cout << endl;
        SetColor(7, 0);
        if(act[3] == 0)
            SetColor(8, 0);
        print("4.Осмотреть плакат на стене.", 60);
        cout << endl;
        SetColor(7, 0);
        if(act[4] == 0)
            SetColor(8, 0);
        print("5.Думаю с меня хватит (вернуться к LAI).", 60);
        SetColor(7, 0);
        if(root == 0)
        {
            act[5] = 0;
            fout.open("achievement.txt");
            fout << "Geduld, mein Freund";
            fout.close();
        }
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


