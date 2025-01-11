#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Character 
{
public:
    string name;
    int strength;
    int defense;
    int mp;
    int maxMP;
    int hp;
    int maxHP;
    int gold;  

    // ��l�ƨ���
    Character(string name) 
	{
        this->name = name;
        this->strength = 5;
        this->defense = 2;
        this->mp = 10;
        this->maxMP = 20;
        this->hp = 100;
        this->maxHP = 100;
        this->gold = 50;  
    }


    // �����Ǫ� 
    int attack() 
	{
        int damage = strength;
        cout << name << " �����F�Ǫ��A�y�� " << damage << " �I�ˮ`�I" << endl;
        return damage;
    }

    // �v���ۤv
    void heal() 
	{
        if (mp >= 20) 
		{
            mp -= 20;
            int healAmount = 20;  // �C���v����_20 HP
            hp += healAmount;
            if (hp > maxHP) hp = maxHP;  // �T�O���W�L�̤jHP
            cout << name << " �ϥΪv���ޯ�A��_�F " << healAmount << " �I�ͩR�ȡI" << endl;
        } else 
            cout << name << " �� MP �����A�L�k�ϥΪv���ޯ�I" << endl;
    }

// �ө��ʶR���~
    bool shop() 
	{
        int choice;
        cout << "\n�ө�: �ثe����: " << gold << " ����\n";
        cout << "1. �ʶR�Z�� (+5 �O�q) �� 100 ����\n";
        cout << "2. �ʶR���� (+5 ���m) �� 100 ����\n";
        cout << "3. �h�X�ө�\n";
        cout << "�п��: ";
        cin >> choice;

        if (choice == 1) 
		{
            if (gold >= 100) 
			{
                gold -= 100;
                strength += 5;
                cout << name << " �ʶR�F�Z���A�O�q�W�[ 5�I\n";
                return true;  // �ʶR���~�A�����^�X
            } else 
                cout << "���������A�L�k�ʶR�Z���I\n";
        } else if (choice == 2) 
		{
            if (gold >= 100) 
			{
                gold -= 100;
                defense += 5;
                cout << name << " �ʶR�F���ҡA���m�W�[ 5�I\n";
                return true;  // �ʶR���~�A�����^�X
            } else 
                cout << "���������A�L�k�ʶR���ҡI\n";
        } else if (choice == 3) 
            cout << "���}�ө�\n";
        else 
            cout << "�L�Ŀ�ܡI\n";
        return false;  // ���ʶR���~�A�~��ާ@
    }


    // ��X���⪬�A
    void printStatus() 
	{
        cout << "����: " << name 
             << ", HP: " << hp << "/" << maxHP 
             << ", MP: " << mp << "/" << maxMP 
             << ", �O�q: " << strength 
             << ", ���m�O: " << defense 
             << ", ����: " << gold << endl;
    }

    // �O�_�s��
    bool isAlive() 
	{
        return hp > 0;
    }
};

class Enemy 
{
public:
    string name;
    int hp;
    int maxHP;
    int attackPower;
    int defense;
    int goldDrop;

    Enemy(string name, int hp, int attackPower, int defense, int goldDrop) 
	{
        this->name = name;
        this->hp = hp;
        this->maxHP = hp;
        this->attackPower = attackPower;
        this->defense = defense;
        this->goldDrop = goldDrop;
    }

    // �����Ǫ� 
    int attack(Character& player) 
	{
        int damage = attackPower - player.defense;
        if (damage < 0) damage = 0; // �T�O�ˮ`���|�O�t��
        cout << name << " �����F " << player.name << "�A�y�� " << damage << " �I�ˮ`�I" << endl;
        return damage;
    }

    // �O�_�s��
    bool isAlive() 
	{
        return hp > 0;
    }
};

int main() 
{
    string name1, name2;

    // ��J����m�W
    cout << "���a1�A�п�J����m�W: ";
    cin >> name1;
    cout << "���a2�A�п�J����m�W: ";
    cin >> name2;

    // ���a1���¾�~
    int choice1;
    cout << "���a1�A��ܧA��¾�~:\n1. �Ԥh (Warrior)\n2. �]�k�v (Mage)\n3. �g�� (Archer)\n��� (1�B2 �� 3): ";
    cin >> choice1;
    Character* player1;
    if (choice1 == 1) 
	{
        player1 = new Character(name1);  
        player1->strength = 6;
        player1->defense = 8;
        player1->mp = 0;
        player1->maxMP = 50;
    } else if (choice1 == 2) 
	{
        player1 = new Character(name1);
        player1->strength = 8;
        player1->defense = 6;
        player1->mp = 0;
        player1->maxMP = 50;
    } else if (choice1 == 3) 
	{
        player1 = new Character(name1);
        player1->strength = 10;
        player1->defense = 3;
        player1->mp = 0;
        player1->maxMP = 50;
    }

    // ���a2���¾�~
    int choice2;
    cout << "���a2�A��ܧA��¾�~:\n1. �Ԥh (Warrior)\n2. �]�k�v (Mage)\n3. �g�� (Archer)\n��� (1�B2 �� 3): ";
    cin >> choice2;
    Character* player2;
    if (choice2 == 1) 
	{
        player2 = new Character(name2);  
        player2->strength = 6;
        player2->defense = 8;
        player2->mp = 0;
        player2->maxMP = 50;
    } else if (choice2 == 2) 
	{
        player2 = new Character(name2);
        player2->strength = 8;
        player2->defense = 6;
        player2->mp = 0;
        player2->maxMP = 50;
    } else if (choice2 == 3) 
	{
        player2 = new Character(name2);
        player2->strength = 10;
        player2->defense = 3;
        player2->mp = 0;
        player2->maxMP = 50;
    }

    // �ЫةǪ�
    Enemy enemy("�Ǫ�", 200, 15, 5, 50);  

    // �C���}�l
    cout << "�C���}�l�I\n";

    // �i��^�X��԰�
    while (player1->isAlive() && player2->isAlive() && enemy.isAlive()) 
	{
        // ��ܪ��a�M�Ǫ������A
        player1->printStatus();
        player2->printStatus();
        cout << "�Ǫ������A: HP: " << enemy.hp << "/" << enemy.maxHP << endl;

        // ���a1��ܦ��
        int choice;
        bool endTurn = false;  // �X�СA��ܬO�_�����^�X
        while (!endTurn) 
		{
        	cout << "\n���a1���^�X�G\n1. �����Ǫ�\n2. �v���ۤv\n3. �i�J�ө�\n��� (1�B2 �� 3): ";
        	cin >> choice;
        	if (choice == 1) 
			{
            	int damage = player1->attack();
            	enemy.hp -= damage;
            	endTurn = true;  // �����ᵲ���^�X
        	} else if (choice == 2) 
            	player1->heal();  
        	else if (choice == 3) 
			{
            	if(player1->shop()) 
				{
                    endTurn = true;  // �p�G�ʶR�F���~�A�����^�X
                };
        	}
		}
        // ���a2��ܦ��
        endTurn = false;  // ���m�X��
        while (!endTurn) 
		{
			cout << "\n���a2���^�X�G\n1. �����Ǫ�\n2. �v���ۤv\n3. �i�J�ө�\n��� (1�B2 �� 3): ";
        	cin >> choice;
        	if (choice == 1) 
			{
            	int damage = player2->attack();
            	enemy.hp -= damage;
            	endTurn = true;  // �����ᵲ���^�X
        	} else if (choice == 2) 
			{
            	player2->heal();
        	} else if (choice == 3) 
			{
            	if(player2->shop());
				{
                    endTurn = true;  // �p�G�ʶR�F���~�A�����^�X
                };
        	}
		
		}
        // �p�G�Ǫ����M�s���A�Ǫ��i�����
        if (enemy.isAlive()) 
		{
            int damage1 = enemy.attack(*player1);
            player1->hp -= damage1;
            int damage2 = enemy.attack(*player2);
            player2->hp -= damage2;
        }

		// �C�^�X�����ɼW�[����
        player1->gold += 20;
        player2->gold += 20;
        // �C�^�X�����ɼW�[mp
		player1->mp += 5;
        player2->mp += 5;
		// ��ܦ^�X�������A
        cout << "\n�^�X�����I\n";


        // �p�G���a���F�A�����C��
        if (!player1->isAlive()) 
		{
            cout << "���a1 �Q���ѡI�C�������I\n";
            break;
        }
        if (!player2->isAlive()) 
		{
            cout << "���a2 �Q���ѡI�C�������I\n";
            break;
        }
    }

    // ����O����
    delete player1;
    delete player2;

    return 0;
}

