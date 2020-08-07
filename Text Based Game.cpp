#include <iostream>
#include<windows.h>
#include<string>

void Story();
void HUD();
void combat();
void CombatHud();
void Moving();
void CreatMonster();

bool intro = true, secondStory = false;
std::string name = " ", race = " ", sex = " ";
int level =0, Exp = 0, health = 0 , totalHealth = 0, maxHealth = 0,toLevle = 0, heal = 0;
std::string monsterNames[] ={"war" , "jazz" , "mask" , "robot", "Rao"};
std::string currentMonster = " ";
int monsterHp = 0, monsterExp = 0, monsterLevel = 0;
int counter = 0;

int main()
{
    std::cout << "Enter Player Name :";
    std::cin>> name;
    std::cout << "Enter charcters Race: ";
    std::cin>> race;
    std::cout << "Enter Sex: ";
    std::cin>> sex;
    std::cout << "Creating Charchter....\n";
    Sleep(1);
    std::cout << "Creating Charchter.........\n";
    Sleep(1);
    std::cout << "Creating Charchter................\n";
    Sleep(1);
    system("cls");
    level = 1;
    Exp = 0;
    toLevle = 76;
    health = 100;
    totalHealth = health;
    maxHealth = totalHealth;

    intro = true;
    Story();
    HUD();
    Moving();
    return 0;
}

void HUD()
{
    Sleep(1);
    system("cls");
    std::cout << "Name: " << name << "         Health      " << totalHealth << "\nRace:" << race <<
          "\nSex: "<< sex << "\nLevel:" << level << "\nExp: "<< Exp << "\nExp To Level:" <<toLevle << std::endl;
}
 void CombatHud()
 {
     Sleep(1);
     system("cls");
     std::cout << "Name: " << name <<  "   |    Monster Name " << currentMonster << "\nHealth: " << totalHealth << "   | Monster Health " <<
     monsterHp << "\nLevel: "<< level << "   | monster Level: " << monsterLevel << std::endl;

 }
void combat()
{
 CombatHud();

 int playerAttack;
 int playerDamage = 8 * level / 2;
 int monsterAttack = 6 * monsterLevel / 2; //check

 if(totalHealth>= 1 && monsterHp >= 1)
 {
     std::cout << std::endl;
     std::cout << "1. Attack" << std::endl;
     std::cout << "2. Block" << std::endl;
     std::cout<< "3. Run!" << std::endl;
     //std::cout " 4. Help" << std::endl;

     std::cout << std::endl <<std::endl;
     std::cin >> playerAttack;


     if(playerAttack == 1)
    {
         std::cout<<"Attacking........ Wait"<< playerDamage <<"to the" << currentMonster << std::endl;
         monsterHp = monsterHp - playerDamage;
         Sleep(1);
         CombatHud();
         if(monsterHp >= 1)
        {
             std::cout << "\n \n";
             std::cout << "Beast is Attacking......" << std::endl;
             totalHealth = totalHealth - monsterAttack;
             std::cout << "YOur Suffer " << monsterAttack << "hp" << totalHealth << std::endl;
             if(totalHealth <=0)
       {


             totalHealth = 0;


        }
         else if (monsterHp <= 0)
         {
             monsterHp = 0;
         }
     Sleep(1);
     CombatHud();
     combat();
     }
     else if (playerAttack == 2)
     {
         std::cout << "Blocking" << std::endl;

         int i = rand()% 100 +1 ;
         if (i >= 50)
         {
             std::cout << "Attack Blocked" << std::endl;
             heal = level *10 / 2;
             std::cout << "you Heald " << "to you total health" << std::endl;
             totalHealth += heal ;
             Sleep(1);
             CombatHud();
             combat();
         }

         else{
            std::cout<< "you Faild to block the monster attacks" << std::endl;
            totalHealth = totalHealth - monsterAttack;
            std::cout << "you suffer" << monsterAttack << "hp" << totalHealth << std::endl;
            Sleep(1);
            CombatHud();
            combat();
            }
         }else if (playerAttack == 3)
         {
             std::cout << "you try to run away " <<std::endl;
             int x = rand() % 100 +1 ;
             if(x >= 50)
             {
                 std::cout<<"you ran away!" << std::endl;
                 HUD();
                 Moving();
             }
             else{
                std::cout <<"you faild to run away" << std::endl;
                std::cout << "monster Attack " << std::endl;
                totalHealth = totalHealth - monsterAttack;
                std::cout << " you suffer " << monsterAttack << "hp" << totalHealth << std::endl;
                CombatHud();
                combat();
             }
        }
         else{
            std::cout << "invalid Number" << std::endl;
            combat();
         }
      }

         if(totalHealth <=1)
         {
             system("cls");
             std::cout << "you died " << "you were levl " << "you got killed by " << currentMonster << std::endl;
             Sleep(1);
                 exit(0);
         }
          if (monsterHp <=1)
          {
              HUD();
              Exp = monsterExp;
              std::cout << std::endl << std::endl;
              std::cout<<"you defeted monster "<< currentMonster << "you are rewarded with" << monsterExp << " exp well done" << std::endl;
              counter = 0;
              Sleep(1);
          }
          if (Exp = toLevle)
            {
                level++;
                totalHealth = 100;
                totalHealth += 20*level;
                maxHealth = totalHealth;
                std::cout<< "Level up" << level << std::endl;
                std::cout<< "total health is increasd by 20 points "<< totalHealth << std::endl;
                Sleep(1);
                HUD();
                toLevle = toLevle * level+ 1;
            }
            system("pause");
            HUD();
            Moving();
 }}



void CreatMonster()
{


    monsterHp = 30;
    monsterLevel =(rand()%3)+ level;
    if(monsterLevel == 0)
    {
        monsterLevel =(rand()%3)+ level;
    }
    monsterHp = (rand() % 30 ) * monsterLevel ;
      if (monsterHp ==0)
      {
          monsterHp = (rand()%30) * monsterLevel ;
      }
      monsterExp = monsterHp;
}

void Moving()
{
 int choice ;
 std::cout << std::endl;
 std::cout<<"1 Move Forward" << std::endl;
 std::cout <<"2 Relaxe"<< std::endl;
 std::cout<<"3 Move Backward"<<std::endl;
 std::cout << std::endl << std::endl;
 std::cin >> choice;

 if (choice == 1)
{
     int temp = rand()% 100 + 1;
     std::cout << "you begain move forward " << std::endl;
     if(temp >= 50)
     {
         CreatMonster();
         std::string temp = monsterNames[rand()%3];
         std::cout << "monster is ready for battel " <<std::endl;
         currentMonster= temp;
         Sleep(1);
         combat();
     }
     counter = 0 ;
     std::cout << "you find nothing of intrst" <<std::endl;
     Sleep(1);
     HUD();
     Moving();
}
else if (choice ==2)
{
    std::cout<< "you just want to chill out for a second"<< std::endl;
    if (counter <=2)
    {
        counter++;
        if (totalHealth <=99)
        {
            totalHealth + 10 * level;
            if(totalHealth > 100 && level == 1)
            {
                totalHealth - 100;
            }
            else if(totalHealth > 120&& level == 2)
            {
                totalHealth = 120;
            }

            else if(totalHealth >140 && level == 3)
            {
                totalHealth = 140;

            }
            else if(totalHealth > 160 && level == 4)
            {
                totalHealth = 160;
            }
        }
        std::cout<< "You heald by reasting "<< totalHealth << std::endl;
    }
    else{
        std::cout<< "you are not able to heal " <<std::endl;
    }
    Sleep(1);
    HUD();
    Moving();
}
        else if(choice == 3)
        {
           int temp = rand()%100 + 1;

        std::cout << "you begain to mmove forward>......."<< std::endl;
        if(temp >= 50)
        {
            //Encounter monster
            CreatMonster();
            std::string temp = monsterNames[rand()%3];
            std::cout << "a Monster! prepare for fight" << temp << std::endl;
            currentMonster = temp;
            Sleep(1);
            combat();
        }
        counter = 0;
    }
    else
    {
        std::cout << "invalid Input pick from 1, 2 , 3"<< std::endl;
        Sleep(1);
        HUD();
        Moving();
    }
}

 void Story()
 {
     std::string Intro_story = "you awake to darknees in the dark forest no one is there only Huge masive tree \n"
            "you try to remmber what happend to you and how you end up in this masiv Jungle \n"
            "And you want to find out how you wnd up hear.\n\n";

 if (intro)
 {
     int i = 0;
     while(Intro_story[i]!='\0')
        Sleep(1);
     i++;
      }
 intro = false;
 system("pause");



 system ("cls");
 std::cout << "clearing consol...";
 Sleep(1);
 system("cls");
 std::cout<<"clearing consol.........";
 system("cls");
 std::cout<<"clearing consol............";
 system("cls");
 std::cout<<"clearing consol................";
 Sleep(1);
 std::cout<<" consol resuming......................";
 Sleep(1);
 system ("cls");

}




