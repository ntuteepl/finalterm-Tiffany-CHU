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

    // 初始化角色
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


    // 攻擊怪物 
    int attack() 
    {
        int damage = strength;
        cout << name << " 攻擊了怪物，造成 " << damage << " 點傷害！" << endl;
        return damage;
    }

    // 治療自己
    void heal() 
    {
        if (mp >= 20) 
	{
            mp -= 20;
            int healAmount = 20;  // 每次治療恢復20 HP
            hp += healAmount;
            if (hp > maxHP) hp = maxHP;  // 確保不超過最大HP
            cout << name << " 使用治療技能，恢復了 " << healAmount << " 點生命值！" << endl;
        } else 
            cout << name << " 的 MP 不足，無法使用治療技能！" << endl;
    }

// 商店購買物品
    bool shop() 
    {
        int choice;
        cout << "\n商店: 目前金幣: " << gold << " 金幣\n";
        cout << "1. 購買武器 (+5 力量) 需 100 金幣\n";
        cout << "2. 購買盔甲 (+5 防禦) 需 100 金幣\n";
        cout << "3. 退出商店\n";
        cout << "請選擇: ";
        cin >> choice;

        if (choice == 1) 
	{
            if (gold >= 100) 
	    {
                gold -= 100;
                strength += 5;
                cout << name << " 購買了武器，力量增加 5！\n";
                return true;  // 購買物品，結束回合
            } else 
                cout << "金幣不足，無法購買武器！\n";
        } else if (choice == 2) 
        {
            if (gold >= 100) 
	    {
                gold -= 100;
                defense += 5;
                cout << name << " 購買了盔甲，防禦增加 5！\n";
                return true;  // 購買物品，結束回合
            } else 
                cout << "金幣不足，無法購買盔甲！\n";
        } else if (choice == 3) 
            cout << "離開商店\n";
        else 
            cout << "無效選擇！\n";
        return false;  // 未購買物品，繼續操作
    }


    // 輸出角色狀態
    void printStatus() 
    {
        cout << "角色: " << name 
             << ", HP: " << hp << "/" << maxHP 
             << ", MP: " << mp << "/" << maxMP 
             << ", 力量: " << strength 
             << ", 防禦力: " << defense 
             << ", 金幣: " << gold << endl;
    }

    // 是否存活
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

    // 攻擊怪物 
    int attack(Character& player) 
    {
        int damage = attackPower - player.defense;
        if (damage < 0) damage = 0; // 確保傷害不會是負數
        cout << name << " 攻擊了 " << player.name << "，造成 " << damage << " 點傷害！" << endl;
        return damage;
    }

    // 是否存活
    bool isAlive() 
    {
        return hp > 0;
    }
};

int main() 
{
    string name1, name2;

    // 輸入角色姓名
    cout << "玩家1，請輸入角色姓名: ";
    cin >> name1;
    cout << "玩家2，請輸入角色姓名: ";
    cin >> name2;

    // 玩家1選擇職業
    int choice1;
    cout << "玩家1，選擇你的職業:\n1. 戰士 (Warrior)\n2. 魔法師 (Mage)\n3. 射手 (Archer)\n選擇 (1、2 或 3): ";
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

    // 玩家2選擇職業
    int choice2;
    cout << "玩家2，選擇你的職業:\n1. 戰士 (Warrior)\n2. 魔法師 (Mage)\n3. 射手 (Archer)\n選擇 (1、2 或 3): ";
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

    // 創建怪物
    Enemy enemy("怪物", 200, 15, 5, 50);  

    // 遊戲開始
    cout << "遊戲開始！\n";

    // 進行回合制戰鬥
    while (player1->isAlive() && player2->isAlive() && enemy.isAlive()) 
    {
        // 顯示玩家和怪物的狀態
        player1->printStatus();
        player2->printStatus();
        cout << "怪物的狀態: HP: " << enemy.hp << "/" << enemy.maxHP << endl;

        // 玩家1選擇行動
        int choice;
        bool endTurn = false;  // 旗標，表示是否結束回合
        while (!endTurn) 
	{
        	cout << "\n玩家1的回合：\n1. 攻擊怪物\n2. 治療自己\n3. 進入商店\n選擇 (1、2 或 3): ";
        	cin >> choice;
        	if (choice == 1) 
		{
                	int damage = player1->attack();
               		enemy.hp -= damage;
                	if (enemy.hp <= 0) 
                	{
                    		cout << "恭喜玩家1擊敗怪物！" << endl;
                    	return 0;  // 結束遊戲
                	}
                	endTurn = true;
            	} else if (choice == 2) 
            	{
        		player1->heal();
        		endTurn = true;  // 治療後結束回合
    		} else if (choice == 3) 
		{
            		if(player1->shop()) 
			{
                   		endTurn = true;  // 如果購買了物品，結束回合
                	}
        	}
	}
        // 玩家2選擇行動
        endTurn = false;  // 重置旗標
        while (!endTurn) 
	{
		cout << "\n玩家2的回合：\n1. 攻擊怪物\n2. 治療自己\n3. 進入商店\n選擇 (1、2 或 3): ";
        	cin >> choice;
        	if (choice == 1) 
		{
                	int damage = player2->attack();
                	enemy.hp -= damage;
                	if (enemy.hp <= 0) 
                	{
	                        cout << "恭喜玩家2擊敗怪物！" << endl;
                    		return 0;  // 結束遊戲
                	}
                	endTurn = true;
                } else if (choice == 2) 
	        {
            		player2->heal();
			endTurn = true;  // 治療後結束回合
		}else if (choice == 3) 
		{
            		if(player2->shop())
			{
                    		endTurn = true;  // 如果購買了物品，結束回合
                	}
        	}
		
	}
        // 如果怪物仍然存活，怪物進行攻擊
        if (enemy.isAlive()) 
	{
            int damage1 = enemy.attack(*player1);
            player1->hp -= damage1;
            int damage2 = enemy.attack(*player2);
            player2->hp -= damage2;
        }

	// 每回合結束時增加金幣
        player1->gold += 20;
        player2->gold += 20;
        // 每回合結束時增加mp
	player1->mp += 5;
        player2->mp += 5;
	// 顯示回合結束狀態
        cout << "\n回合結束！\n";

        // 如果玩家死了，結束遊戲
        if (!player1->isAlive()) 
	{
            cout << "玩家1 被擊敗！遊戲結束！\n";
            break;
        }
        if (!player2->isAlive()) 
	{
            cout << "玩家2 被擊敗！遊戲結束！\n";
            break;
        }
    }

    // 釋放記憶體
    delete player1;
    delete player2;

    return 0;
}

