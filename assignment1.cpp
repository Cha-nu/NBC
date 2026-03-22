#include <iostream>
#include <vector>

using namespace std;

// 0:HP, 1:MP, 2:ATK, 3:DEF, 4:STR, 5:DEX, 6:INT, 7:LUK, 8:Level, 9:HPPotion, 10:MPPotion
vector<int> status = {0, 0, 0, 0, 0, 0, 0, 0, 1, 5, 5};

void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
    if(count == 1) // HP 포션 사용
    {
        if(*p_HPPotion > 0)
        {
            status[0] += 20; // HP 증가 (기존 status[1] 오타 수정)
            cout << "HP 20 증가 (남은 포션: " << --(*p_HPPotion) << ")\n";
        }
        else cout << "HP 물약 부족\n";
    }
    else // MP 포션 사용
    {
        if(*p_MPPotion > 0)
        {
            status[1] += 20;
            cout << "MP 20 증가 (남은 포션: " << --(*p_MPPotion) << ")\n";
        }
        else cout << "MP 물약 부족\n";
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. HP/MP 입력
    while(1)
    {
        int HP, MP;
        cout << "초기 HP/MP 입력 (예: 100 100): ";
        if (!(cin >> HP >> MP)) {
            cin.clear(); cin.ignore(256, '\n');
            cout << "입력 형식이 잘못되었습니다.\n";
            continue;
        }   
        if(HP < 50 || MP < 50) {
            cout << "50 이상의 값을 입력해주세요.\n";
            continue;
        }
        status[0] = HP; status[1] = MP;
        break;
    }

    // 2. ATK/DEF 입력
    while(1)
    {
        int ATK, DEF;
        cout << "초기 공격력/방어력 입력 (예: 10 5): ";
        if (!(cin >> ATK >> DEF)) {
            cin.clear(); cin.ignore(256, '\n');
            continue;
        }   
        status[2] = ATK; status[3] = DEF;
        break;
    }

    // 3. STR/DEX/INT/LUK 입력 (추가된 부분)
    while(1)
    {
        int s, d, i, l;
        cout << "STR DEX INT LUK 입력 (예: 10 10 10 10): ";
        if (!(cin >> s >> d >> i >> l)) {
            cin.clear(); cin.ignore(256, '\n');
            continue;
        }
        status[4] = s; status[5] = d; status[6] = i; status[7] = l;
        break;
    }

    // 메인 루프
    while(1)
    {
        int command;
        cout << "\n--- 메뉴 ---\n";
        cout << "1.HP UP | 2.MP UP | 3.ATK x2 | 4.DEF x2 | 5.스탯 확인 | 6.Level Up | 0.나가기\n";
        cout << "선택: ";
        if(!(cin >> command)) { cin.clear(); cin.ignore(256, '\n'); continue; }

        switch (command)
        {
        case 0:
            cout << "게임을 종료합니다.\n";
            return 0;
        case 1:
        case 2:
            // 포션 인덱스는 현재 9(HP), 10(MP)입니다.
            setPotion(command, &status[9], &status[10]);
            break;
        case 3:
            status[2] <<= 1;
            cout << "공격력이 두 배로 증가했습니다!\n";
            break;
        case 4:
            status[3] <<= 1;
            cout << "방어력이 두 배로 증가했습니다!\n";
            break;
        case 5:
            cout << "\n=== 현재 능력치 ===\n";
            cout << "Level: " << status[8] << "\n";
            cout << "HP: " << status[0] << " / MP: " << status[1] << "\n";
            cout << "ATK: " << status[2] << " / DEF: " << status[3] << "\n";
            cout << "STR: " << status[4] << " | DEX: " << status[5] << " | INT: " << status[6] << " | LUK: " << status[7] << "\n";
            cout << "HP포션: " << status[9] << "개 | MP포션: " << status[10] << "개\n";
            break;
        case 6:
            cout << "레벨 업! 모든 스탯이 상승하고 포션을 보급받습니다.\n";
            status[8]++;    // Level
            status[4] += 2; // STR
            status[5] += 2; // DEX
            status[6] += 2; // INT
            status[7] += 2; // LUK
            status[9]++;    // HP Potion
            status[10]++;   // MP Potion
            break;
        default:
            cout << "잘못된 입력입니다.\n";
        }
    }
    return 0;
}
