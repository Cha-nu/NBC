#include <iostream>
#include <vector>

using namespace std;

// HP, MP, 공격력, 방어력, 레벨, HP포션, MP포션
vector<int> status = {0, 0, 0, 0, 1, 5, 5};
    

void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
    if(count == 1)
    {
        if(*p_HPPotion > 0)
        {
            status[1]+= 20;
            cout << "HP 20 증가 \n";
            (*p_HPPotion)--;
        }
        else cout << "HP 물약 부족\n";
    }
    else
    {
        if(*p_MPPotion > 0)
        {
            status[1]+= 20;
            cout << "MP 20 증가 \n";
            (*p_MPPotion)--;
        }
        else cout << "MP 물약 부족\n";
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1)
    {
        int HP, MP;
        char a;
        cout << "HP/MP 입력\n";
        if (!(cin >> HP >> MP)) {
            cin.clear(); // 오류 플래그 초기화
            cin.ignore(256, '\n'); // 버퍼 비우기
            cout << "입력 형식이 잘못되었습니다. 100 100 형식\n";
            continue;
        }   
        if(HP < 50 || MP < 50)
        {
            cout << "다시 입력해주세요.\n";
            continue;
        }
        status[0] = HP;
        status[1] = MP;
        break;
    }
    while(1)
    {
        int ATK, DEF;
        cout << "공격력/방어력 입력\n";
        if (!(cin >> ATK >> DEF)) {
            cin.clear(); // 오류 플래그 초기화
            cin.ignore(256, '\n'); // 버퍼 비우기
            cout << "입력 형식이 잘못되었습니다. 100 100 형식\n";
            continue;
        }   
        if(ATK < 0 || DEF < 0)
        {
            cout << "다시 입력해주세요.\n";
            continue;
        }
        status[2] = ATK;
        status[3] = DEF;
        break;
    }
    while(1)
    {
        int command;
        cout << "1.HP UP / 2.MP UP / 3.공격력 UP / 4.방어력 UP / 5.현재 능력치 / 6.Level Up / 0.나가기\n";
        cin >> command;
        switch (command)
        {
        case 0:
            cout << "종료";
            return 0;
        case 1:
        case 2:
            setPotion(command, &status[6], &status[7]);
            break;
        case 3:
            status[2] <<= 1;
            cout << "공격력 증가\n";
            break;
        case 4:
            status[3] <<= 1;
            cout << "방어력 증가\n";
            break;
        case 5:
            cout << "HP: " << status[0] << " MP: " << status[1] << " 공격력: " << status[2] << " 방어력: " << status[3] << " Level: " << status[4] << " HP포션: " << status[5] << " MP포션: " << status[6] << "\n";
            break;
        case 6:
            cout << "레벨 업! 포션을 1개씩 다시 더해줍니다.\n";
            status[4]++;
            status[5]++;
            status[6]++;
            break;
        default:
            cout << "다시 입력해주세요.\n";
        }
    }
    return 0;
}