#include <iostream>
#include "player.h"
#include "warrior.h"
#include "magician.h"
#include "thief.h"
#include "archer.h"
#include "monster.h"
using namespace std;

// 메인 함수
int main() {
    string jobs[] = { "전사", "마법사", "도적", "궁수" };
    int job_choice = 0;
    string nickname;

    Player* player = nullptr;

    cout << "* 닉네임을 입력해주세요: ";
    cin >> nickname;

    cout << "<전직 시스템>" << endl;
    cout << nickname << "님, 환영합니다!" << endl;
    cout << "* 원하시는 직업을 선택해주세요." << endl;

    for (int i = 0; i < 4; i++) {
        cout << (i + 1) << ". " << jobs[i] << endl;
    }

    cout << "선택: ";
    cin >> job_choice;

    switch (job_choice) {
    case 1: 
	    player = new Warrior(nickname);
	    break;
    case 2: 
	    player = new Magician(nickname);
	    break;
    case 3: 
	    player = new Thief(nickname);
	    break;
    case 4: 
	    player = new Archer(nickname); 
	    break;
    default:
        cout << "잘못된 입력입니다." << endl;
        return 1;
    }

    string monster_name;
    cout << "* 싸울 몬스터의 이름을 입력해주세요: ";
    cin >> monster_name;

    Monster* monster = new Monster(monster_name);
    cout << monster->getName() << "이(가) 나타났습니다!" << endl;
		
		// switch문으로 공격, 회복, 상태확인 선택
    int action_choice = 0;
    while (monster->getHP() > 0 && player->getHP() > 0) {
        cout << "\n<행동 선택>" << endl;
        cout << "1. 공격" << endl;
        cout << "2. 회복" << endl;
        cout << "3. 상태 확인" << endl; 
        cout << "선택: ";
        cin >> action_choice;
        switch (action_choice) {
        case 1:
            player->attack(monster);
            break;
        case 2:
            player->setHP(player->getHP() + 10);
            cout << player->getNickname() << "의 HP가 10 회복되었습니다!" << '\n';
            break;
        case 3:
            player->printPlayerStatus();
        default:
            cout << "다시 입력하십시오." << endl;
        }
        if (monster->getHP() > 0)
            monster->attack(player);
    }
    // 몬스터가 생존하지 못했을 경우 플레이어의 승리 문구 출력
    if (monster->getHP() <= 0)
    {
        cout << monster->getName() << "이(가) 쓰러졌습니다!" << endl;
        cout << player->getNickname() << "님, 승리하셨습니다!" << endl;
    }
    // 플레이어가 생존하지 못했을 경우 몬스터의 승리 문구 출력
    else if (player->getHP() <= 0)
    {
        cout << player->getNickname() << "님이 쓰러졌습니다!" << endl;
        cout << monster->getName() << "이(가) 승리하였습니다!" << endl;
    }

    if(player != nullptr)
      delete player;

    return 0;
}