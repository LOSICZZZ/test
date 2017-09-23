#pragma  once
// #ifndef CODEFORLAB7_H_  
// 
// 
// #define CODEFORLAB7_H_

#include <iostream>
#include "windows.h"

class Player
{
private:
	int HP;//玩家生命值
	int AT;//玩家攻击力
	int AP;//玩家魔法值
	int DE;//玩家防御力
	int Money;//玩家金币
	int EXP;//玩家经验
	int Exp;
	int LV;//玩家等级

	int judge;//判断双倍金币
	int boss;//判断boss是否被击败

public:
	Player()
	{
		//初始属性
		HP = 1000;
		AT = 20;
		AP = 0;
		DE = 20;
		Money = 0;
		EXP = 100;
		Exp = 0;
		LV = 1;

		judge = 0;
		boss = 1;//boss未被击败
	}
	Player(Player &p)
	{
		HP = p.HP;
		AT = p.AT;
		AP = p.AP;
		DE = p.DE;
		Money = p.Money;
		judge = p.judge;
		EXP = p.EXP;
		Exp = p.Exp;
		LV = p.LV;
	}

	~Player()
	{
		HP = 1;
		AT = 1;
		DE = 1;
		Money = 1;
	}

	int getHp();//获取玩家生命值
	void incHp(int ihp);//增加玩家生命值
	int decHp(int dhp);//减少玩家生命值

	int getAT();//获取玩家攻击力
	void incAT(int iat);//增加玩家攻击力
	void decAT(int dat);//减少玩家攻击力

	int getAP();//获取玩家魔法值
	void incAP(int ap);//提高玩家魔法值

	int getDe();//获取玩家防御力
	void incDe(int ide);//增加玩家防御力
	void decDe(int dde);//减少玩家防御力

	int getMoney();//获取玩家金币
	void incMoney(int imoney);//增加玩家金币
	int decMoney(int dmoney);//减少玩家金币

	void change(int hp, int at, int de, int money);//改变玩家属性

	int getEXP();//获取玩家经验上限
	void incEXP(int exp1);//增加玩家经验上限

	int getExp();//获取玩家经验
	void incExp(int Exp1);//增加玩家经验

	int getLV();//获取玩家等级
	void incLV(int lv);//增加玩家等级

	void double_money();//双倍金币
	int getjudge();
	int beat_boss();//挑战boss

	void show();//显示玩家属性
};


//获取属性
int Player::getHp()
{
	return HP;
}

int Player::getAT()
{
	return AT;
}

int Player::getAP()
{
	return AP;
}

int Player::getDe()
{
	return DE;
}

int Player::getMoney()
{
	return Money;
}

int Player::getjudge()
{
	return judge;
}

int Player::getEXP()
{
	return EXP;
}

int Player::getExp()
{
	return Exp;
}

int Player::getLV()
{
	return LV;
}


void Player::incHp(int ihp)
{
	HP += ihp;
}

void Player::incAT(int iat)
{
	AT += iat;
}

void Player::incAP(int iap)
{
	AP += iap;
}

void Player::incDe(int ide)
{
	DE += ide;
}

void Player::incMoney(int imoney)
{
	Money += imoney;
}

void Player::incEXP(int exp1)
{
	EXP += exp1;
}

void Player::incExp(int Exp1)
{
	Exp += Exp1;
}

void Player::incLV(int lv)
{
	LV += lv;
}

//减少属性
int Player::decHp(int dhp)
{
	HP -= dhp;
	return HP;
}

void Player::decAT(int dat)
{
	AT -= dat;
}

void Player::decDe(int dde)
{
	DE -= dde;
}

int Player::decMoney(int dmoney)
{
	Money -= dmoney;
	return Money;
}

//显示玩家当前属性
void Player::show()
{
	std::cout << " 等级：" << LV << std::endl;
	std::cout << " 生命值：" << HP << std::endl;
	std::cout << " 攻击力：" << AT << std::endl;
	std::cout << " 魔法值：" << AP << std::endl;
	std::cout << " 防御力：" << DE << std::endl;
	std::cout << " 金币：  " << Money << std::endl;
	std::cout << " 经验：" << Exp << "/" << EXP << std::endl;
	std::cout << std::endl;
}

void Player::change(int hp, int at, int de, int money)
{
	HP = hp;
	AT = at;
	DE = de;
	Money = money;
}

//增加玩家属性
Player increaseplayer(Player p1)
{
loop:
{
	std::cout << " 1、玩家1增加生命值" << std::endl;
	std::cout << " 2、玩家1增加攻击力" << std::endl;
	std::cout << " 3、玩家1增加防御力" << std::endl;
	std::cout << " 4、玩家1增加金币" << std::endl;
	std::cout << " 5、返回上一级" << std::endl;

	int select2;
	std::cin >> select2;
	if (select2 > 0 && select2 <= 5)
	{
		switch(select2)
		{
		//增加生命值
		case 1:
			{
				std::cout << " 请输入增加的生命值" << std::endl;
				int hp;
				std::cin >> hp;
				
				p1.incHp(hp);
				if (p1.getHp() <= 0)
				{
					system("cls");
					for (int i = 5; i > 0; i--)
					{
						std::cout << "			DAME OVER" << std::endl;
						std::cout << "\t\t\t" << i << "秒后退出游戏" << std::endl;	
						Sleep(1000);
						system("cls");
					}
					exit(0);
				}
				else 
				{
					system("cls");
					p1.show();
				}

			}
			break;

		//增加攻击力	
		case 2:
			{
				std::cout << " 请输入增加的攻击力" << std::endl;
				int at2;
				std::cin >> at2;
				p1.incAT(at2);
				system("cls");
				p1.show();
			}
			break;

		//增加防御力
		case 3:
			{
				std::cout << " 请输入增加的防御力" << std::endl;
				int de2;
				std::cin >> de2;
				p1.incDe(de2);
				system("cls");
				p1.show();
			}
			break;
			
		//增加金币
		case 4:
			{
				std::cout << " 请输入增加的金币" << std::endl;
				int money2;
				std::cin >> money2;
				if (p1.getjudge() == 0)
				{
					p1.incMoney(money2);
					system("cls");
					p1.show();
				}
				if (p1.getjudge() == 1)
				{
					p1.incMoney(money2 * 2);
					system("cls");
					p1.show();
				}

			}
			break;

		case 5:
			{
				system("cls");
				p1.show();
			}
			break;
		}
	}

	else
	{
		std::cout << " 输入有误，请重新选择" << std::endl;
		system("cls");
		p1.show();
		goto loop;
	}
}
	return p1;
}

//减少玩家属性
Player decreaseplayer(Player p1)
{
loop:
{
	std::cout << " 1、玩家1减少生命值" << std::endl;
	std::cout << " 2、玩家1减少攻击力" << std::endl;
	std::cout << " 3、玩家1减少防御力" << std::endl;
	std::cout << " 4、玩家1减少金币" << std::endl;
	std::cout << " 5、返回上一级" << std::endl;
	
	int select2;
	std::cin >> select2;
	if (select2 > 0 && select2 <= 5)
	{
		switch(select2)
		{
		//减少生命值
		case 1:
			{
				std::cout << " 请输入关怪物的攻击力，防御力，生命值，经验值" << std::endl;
				int at1, de1, hp1, hp, exp1;
				std::cin >> at1 >> de1 >> hp1 >> exp1;
				hp = ((at1 - p1.getDe()) * 3 - ((p1.getAT() - de1) * 4) + (hp1 * (0.6 - 0.01 * p1.getAP()))) * 2;//伤害计算公式
				if (hp <= 0 || p1.getAT() >= 5 * at1)
				{
					p1.incExp(exp1);
					while (p1.getExp() / p1.getEXP() >= 1)
					{
						p1.incExp(-p1.getEXP());
						p1.incEXP(p1.getEXP() * 0.5);
						p1.incLV(1);
						p1.incAP(p1.getLV() * 0.35);
					}	
					system("cls");
					p1.show();
				}
				else
				{
					p1.decHp(hp);
					p1.incExp(exp1);
					while (p1.getExp() / p1.getEXP() >= 1)
					{
						p1.incExp(-p1.getEXP());
						p1.incEXP(p1.getEXP() * 0.5);
						p1.incLV(1);
						p1.incAP(p1.getLV() * 0.4);
					}
					system("cls");
					p1.show();
				}			
			}
			break;
		
		//减少攻击力
		case 2:
			{
				std::cout << " 请输入减少的攻击力" << std::endl;
				int at;
				std::cin >> at;
				p1.decAT(at);
				system("cls");
				p1.show();
			}
			break;
		
		//减少防御力
		case 3:
			{
				std::cout << " 请输入减少的防御力" << std::endl;
				int de;
				std::cin >> de;
				p1.decDe(de);
				system("cls");
				p1.show();
			}
			break;
		
		//减少金币
		case 4:
			{
				std::cout << " 请输入减少的金币" << std::endl;
				int money;
				std::cin >> money;
				p1.decMoney(money);
				system("cls");
				p1.show();
			}
			break;

		case 5:
			{
				system("cls");
				p1.show();
			}
			break;
		}
	}
	else
	{
		std::cout << " 输入有误，请重新选择" << std::endl;
		system("cls");
		p1.show();
		goto loop;
	}
}
	return p1;
}

//双倍金币
void Player::double_money()
{
	judge = 1;
}

//挑战boss
int Player::beat_boss()
{
	return boss = 0;
}

//商店
Player game_store(Player p1)
{
	std::cout << " 1、初级商店" << std::endl;
	std::cout << " 2、中级商店" << std::endl;
	std::cout << " 3、高级商店" << std::endl;
	std::cout << " 4、特效商店" << std::endl;
	std::cout << " 5、返回主菜单" << std::endl;

	int select1, select2, time;
	std::cin >> select1;
	switch (select1)
	{
	//初级商店
	case 1:
		{
			std::cout << " 1、攻击力" << std::endl;
			std::cout << " 2、防御力" << std::endl;
			std::cout << " 3、生命值" << std::endl;
			std::cin >> select2;
			switch(select2)
			{
			case 1:
				{
					std::cout << " 购买几次属性" << std::endl;
					std::cin >> time;
					if(p1.decMoney(100 * time) > 0)
					{
						p1.incAT(10 * time);
					}
					else
					{
						p1.incMoney(100 * time);
						std::cout << " 金币不足" << std::endl;
						Sleep(1000);
					}
				}
				break;

			case 2:
				{
					std::cout << " 购买几次属性" << std::endl;
					std::cin >> time;
					if(p1.decMoney(100 * time) > 0)
					{
						p1.incDe(10 * time);
					}
					else
					{
						p1.incMoney(100 * time);
						std::cout << " 金币不足" << std::endl;
						Sleep(1000);
					}
				}
				break;

			case 3:
				{
					std::cout << " 购买几次属性" << std::endl;
					std::cin >> time;
					if(p1.decMoney(100 * time) > 0)
					{
						p1.incHp(100 * time);
					}
					else
					{
						p1.incMoney(100 * time);
						std::cout << " 金币不足" << std::endl;
						Sleep(1000);
					}
				}
				break;
			}		
		}
		break;

	//中级商店
	case 2:
		{
			std::cout << " 1、攻击力" << std::endl;
			std::cout << " 2、防御力" << std::endl;
			std::cout << " 3、生命值" << std::endl;
			std::cin >> select2;
			switch(select2)
			{
			case 1:
				{
					std::cout << " 购买几次属性" << std::endl;
					std::cin >> time;
					if(p1.decMoney(150 * time) > 0)
					{
						p1.incAT(20 * time);
					}
					else
					{
						p1.incMoney(150 * time);
						std::cout << " 金币不足" << std::endl;
						Sleep(1000);
					}
				}
				break;
				
			case 2:
				{
					std::cout << " 购买几次属性" << std::endl;
					std::cin >> time;
					if(p1.decMoney(150 * time) > 0)
					{
						p1.incDe(20 * time);
					}
					else
					{
						p1.incMoney(150 * time);
						std::cout << " 金币不足" << std::endl;
						Sleep(1000);
					}
				}
				break;
				
			case 3:
				{
					std::cout << " 购买几次属性" << std::endl;
					std::cin >> time;
					if(p1.decMoney(150 * time) > 0)
					{
						p1.incHp(200 * time);
					}
					else
					{
						p1.incMoney(150 * time);
						std::cout << " 金币不足" << std::endl;
						Sleep(1000);
					}
				}
				break;
			}
		}
		break;

	//高级商店
	case 3:
		{
			std::cout << " 购买几次属性" << std::endl;
			std::cin >> time;
			if (p1.decMoney(200 * time) > 0)
			{
				p1.incAT(10 * time);
				p1.incDe(10 * time);
				p1.incHp(300 * time);
			}
			else
			{
				p1.incMoney(200 * time);
				std::cout << " 金币不足" << std::endl;
				Sleep(1000);
			}

		}
		break;

	//特效商店
	case 4:
		{
			std::cout << " 购买几次属性" << std::endl;
			std::cin >> time;
			if (p1.decMoney(500 * time) >= 0)
			{
				p1.incAT(20 * time);
				p1.incDe(10 * time);
				p1.incHp(500 * time);
			}
			else
			{
				p1.incMoney(500 * time);
				std::cout << " 金币不足" << std::endl;
				Sleep(1000);
			}

		}
		break;

	case 5:
		{
			system("cls");
			p1.show();
		}
		break;
	}

	return p1;
}