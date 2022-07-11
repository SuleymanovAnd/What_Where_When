#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
int main() {
    int gamers = 0;
    cout << "How many players will play?" << std::endl;
    cin >> gamers;

    while (gamers < 0 || gamers > 10) {cout << "incorrect number of players. Enter again: "; cin >> gamers;}


    string filesQuestions [13] = {"E:\\SkillboxProject\\19_practice\\what_where_when\\question1.txt",
                         "E:\\SkillboxProject\\19_practice\\what_where_when\\question2.txt",
                         "E:\\SkillboxProject\\19_practice\\what_where_when\\question3.txt",
                         "E:\\SkillboxProject\\19_practice\\what_where_when\\question4.txt",
                         "E:\\SkillboxProject\\19_practice\\what_where_when\\question5.txt",
                         "E:\\SkillboxProject\\19_practice\\what_where_when\\question6.txt",
                         "E:\\SkillboxProject\\19_practice\\what_where_when\\question7.txt",
                         "E:\\SkillboxProject\\19_practice\\what_where_when\\question8.txt",
                         "E:\\SkillboxProject\\19_practice\\what_where_when\\question9.txt",
                         "E:\\SkillboxProject\\19_practice\\what_where_when\\question10.txt",
                         "E:\\SkillboxProject\\19_practice\\what_where_when\\question11.txt",
                         "E:\\SkillboxProject\\19_practice\\what_where_when\\question12.txt",
                         "E:\\SkillboxProject\\19_practice\\what_where_when\\question13.txt"};

    string filesAnswers [13]= {"E:\\SkillboxProject\\19_practice\\what_where_when\\answer1.txt",
                           "E:\\SkillboxProject\\19_practice\\what_where_when\\answer2.txt",
                           "E:\\SkillboxProject\\19_practice\\what_where_when\\answer3.txt",
                           "E:\\SkillboxProject\\19_practice\\what_where_when\\answer4.txt",
                           "E:\\SkillboxProject\\19_practice\\what_where_when\\answer5.txt",
                           "E:\\SkillboxProject\\19_practice\\what_where_when\\answer6.txt",
                           "E:\\SkillboxProject\\19_practice\\what_where_when\\answer7.txt",
                           "E:\\SkillboxProject\\19_practice\\what_where_when\\answer8.txt",
                           "E:\\SkillboxProject\\19_practice\\what_where_when\\answer9.txt",
                           "E:\\SkillboxProject\\19_practice\\what_where_when\\answer10.txt",
                           "E:\\SkillboxProject\\19_practice\\what_where_when\\answer11.txt",
                           "E:\\SkillboxProject\\19_practice\\what_where_when\\answer12.txt",
                           "E:\\SkillboxProject\\19_practice\\what_where_when\\answer13.txt"};
    bool gamersWin = false;
    bool audienceWin = false;
    int playerPoints = 0;
    int audiencePoints = 0;
    bool wonBackSectors [13] = {true,true,true,true,true,
                                true,true,true,true,true,
                                true,true,true};
    ifstream file;
    int gamer = 1;
    int sector = 0;
    system ("cls");
    while (!gamersWin && !audienceWin){

        cout << "player number " << gamer << " is playing"<< endl;
        cout << "Enter offset: ";
        int offset;
        cin >> offset;

        system ("cls");

        sector += abs(offset)%13; // вычисляем сектор
        if (sector >13) {sector -= 13;}
        if (sector == 0) {sector = 1;}
        cout << "sector is " << sector << endl;

        while (!wonBackSectors[sector-1]){ // если уже играли в этот сектор
            //меняем игрока
            if (gamer < gamers){gamer++;}
            else {gamer = 1;}

            cout << "you have already played in this sector. Turn goes to player " << gamer << endl;
            cout << "Enter offset: ";
            cin >> offset;
            system ("cls");
            sector += abs(offset)%13;
            if (sector >13) {sector -= 13;}
            if (sector == 0) {sector = 1;}
            cout << "sector is " << sector << endl;
        }

        wonBackSectors[sector-1] = false; // присваиваем сектору значение отыгранный

        // работа с вопросом
        file.open (filesQuestions[sector-1]);
        if (!file.is_open()) {cout << "error"; break;}

        while (!file.eof()){ // выводим вопрос
            string temp;
            file >> temp;
            cout << temp<< " ";
        }
        file.close ();
        //

        //спрашиваем ответ
        string answer;
        cout << endl << "Enter answer: ";
        cin >> answer;

        // работа с файлом ответа
        file.open (filesAnswers[sector-1],ios::binary);
            int size = 0;
            char buffer [100];

        string rightAnswer;
            // читаем правильный ответ
        while(!file.eof()){


            file.read (buffer,10); // читаем в буфер
            size = (int)file.gcount();

            for (int i =0; i < size;i++){
                rightAnswer.push_back (buffer[i]); // добавляем из буфера в строку
            }
        }
            // выводим правильный ответ
        cout << "right answer is "<< rightAnswer << endl;
        // даем очки
        if (answer == rightAnswer){playerPoints ++;cout << "player give point"<<endl;}
        else {audiencePoints++;cout << "audience give point"<<endl;}
            // условие завершения
        if (playerPoints >=6) {gamersWin = true;}
        if (audiencePoints >=6) {audienceWin = true;}
        file.close ();
        system ("cls");
    }
    // вывод победителя
   if (gamersWin) {cout << "gamers WIN!!!";}
   if (audienceWin) {cout << "gamers Lost. Audience win";}
}
