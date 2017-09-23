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
	int HP;//�������ֵ
	int AT;//��ҹ�����
	int AP;//���ħ��ֵ
	int DE;//��ҷ�����
	int Money;//��ҽ��
	int EXP;//��Ҿ���
	int Exp;
	int LV;//��ҵȼ�

	int judge;//�ж�˫�����
	int boss;//�ж�boss�Ƿ񱻻���

public:
	Player()
	{
		//��ʼ����
		HP = 1000;
		AT = 20;
		AP = 0;
		DE = 20;
		Money = 0;
		EXP = 100;
		Exp = 0;
		LV = 1;

		judge = 0;
		boss = 1;//bossδ������
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

	int getHp();//��ȡ�������ֵ
	void incHp(int ihp);//�����������ֵ
	int decHp(int dhp);//�����������ֵ

	int getAT();//��ȡ��ҹ�����
	void incAT(int iat);//������ҹ�����
	void decAT(int dat);//������ҹ�����

	int getAP();//��ȡ���ħ��ֵ
	void incAP(int ap);//������ħ��ֵ

	int getDe();//��ȡ��ҷ�����
	void incDe(int ide);//������ҷ�����
	void decDe(int dde);//������ҷ�����

	int getMoney();//��ȡ��ҽ��
	void incMoney(int imoney);//������ҽ��
	int decMoney(int dmoney);//������ҽ��

	void change(int hp, int at, int de, int money);//�ı��������

	int getEXP();//��ȡ��Ҿ�������
	void incEXP(int exp1);//������Ҿ�������

	int getExp();//��ȡ��Ҿ���
	void incExp(int Exp1);//������Ҿ���

	int getLV();//��ȡ��ҵȼ�
	void incLV(int lv);//������ҵȼ�

	void double_money();//˫�����
	int getjudge();
	int beat_boss();//��սboss

	void show();//��ʾ�������
};


//��ȡ����
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

//��������
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

//��ʾ��ҵ�ǰ����
void Player::show()
{
	std::cout << " �ȼ���" << LV << std::endl;
	std::cout << " ����ֵ��" << HP << std::endl;
	std::cout << " ��������" << AT << std::endl;
	std::cout << " ħ��ֵ��" << AP << std::endl;
	std::cout << " ��������" << DE << std::endl;
	std::cout << " ��ң�  " << Money << std::endl;
	std::cout << " ���飺" << Exp << "/" << EXP << std::endl;
	std::cout << std::endl;
}

void Player::change(int hp, int at, int de, int money)
{
	HP = hp;
	AT = at;
	DE = de;
	Money = money;
}

//�����������
Player increaseplayer(Player p1)
{
loop:
{
	std::cout << " 1�����1��������ֵ" << std::endl;
	std::cout << " 2�����1���ӹ�����" << std::endl;
	std::cout << " 3�����1���ӷ�����" << std::endl;
	std::cout << " 4�����1���ӽ��" << std::endl;
	std::cout << " 5��������һ��" << std::endl;

	int select2;
	std::cin >> select2;
	if (select2 > 0 && select2 <= 5)
	{
		switch(select2)
		{
		//��������ֵ
		case 1:
			{
				std::cout << " ���������ӵ�����ֵ" << std::endl;
				int hp;
				std::cin >> hp;
				
				p1.incHp(hp);
				if (p1.getHp() <= 0)
				{
					system("cls");
					for (int i = 5; i > 0; i--)
					{
						std::cout << "			DAME OVER" << std::endl;
						std::cout << "\t\t\t" << i << "����˳���Ϸ" << std::endl;	
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

		//���ӹ�����	
		case 2:
			{
				std::cout << " ���������ӵĹ�����" << std::endl;
				int at2;
				std::cin >> at2;
				p1.incAT(at2);
				system("cls");
				p1.show();
			}
			break;

		//���ӷ�����
		case 3:
			{
				std::cout << " ���������ӵķ�����" << std::endl;
				int de2;
				std::cin >> de2;
				p1.incDe(de2);
				system("cls");
				p1.show();
			}
			break;
			
		//���ӽ��
		case 4:
			{
				std::cout << " ���������ӵĽ��" << std::endl;
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
		std::cout << " ��������������ѡ��" << std::endl;
		system("cls");
		p1.show();
		goto loop;
	}
}
	return p1;
}

//�����������
Player decreaseplayer(Player p1)
{
loop:
{
	std::cout << " 1�����1��������ֵ" << std::endl;
	std::cout << " 2�����1���ٹ�����" << std::endl;
	std::cout << " 3�����1���ٷ�����" << std::endl;
	std::cout << " 4�����1���ٽ��" << std::endl;
	std::cout << " 5��������һ��" << std::endl;
	
	int select2;
	std::cin >> select2;
	if (select2 > 0 && select2 <= 5)
	{
		switch(select2)
		{
		//��������ֵ
		case 1:
			{
				std::cout << " ������ع���Ĺ�������������������ֵ������ֵ" << std::endl;
				int at1, de1, hp1, hp, exp1;
				std::cin >> at1 >> de1 >> hp1 >> exp1;
				hp = ((at1 - p1.getDe()) * 3 - ((p1.getAT() - de1) * 4) + (hp1 * (0.6 - 0.01 * p1.getAP()))) * 2;//�˺����㹫ʽ
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
		
		//���ٹ�����
		case 2:
			{
				std::cout << " ��������ٵĹ�����" << std::endl;
				int at;
				std::cin >> at;
				p1.decAT(at);
				system("cls");
				p1.show();
			}
			break;
		
		//���ٷ�����
		case 3:
			{
				std::cout << " ��������ٵķ�����" << std::endl;
				int de;
				std::cin >> de;
				p1.decDe(de);
				system("cls");
				p1.show();
			}
			break;
		
		//���ٽ��
		case 4:
			{
				std::cout << " ��������ٵĽ��" << std::endl;
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
		std::cout << " ��������������ѡ��" << std::endl;
		system("cls");
		p1.show();
		goto loop;
	}
}
	return p1;
}

//˫�����
void Player::double_money()
{
	judge = 1;
}

//��սboss
int Player::beat_boss()
{
	return boss = 0;
}

//�̵�
Player game_store(Player p1)
{
	std::cout << " 1�������̵�" << std::endl;
	std::cout << " 2���м��̵�" << std::endl;
	std::cout << " 3���߼��̵�" << std::endl;
	std::cout << " 4����Ч�̵�" << std::endl;
	std::cout << " 5���������˵�" << std::endl;

	int select1, select2, time;
	std::cin >> select1;
	switch (select1)
	{
	//�����̵�
	case 1:
		{
			std::cout << " 1��������" << std::endl;
			std::cout << " 2��������" << std::endl;
			std::cout << " 3������ֵ" << std::endl;
			std::cin >> select2;
			switch(select2)
			{
			case 1:
				{
					std::cout << " ���򼸴�����" << std::endl;
					std::cin >> time;
					if(p1.decMoney(100 * time) > 0)
					{
						p1.incAT(10 * time);
					}
					else
					{
						p1.incMoney(100 * time);
						std::cout << " ��Ҳ���" << std::endl;
						Sleep(1000);
					}
				}
				break;

			case 2:
				{
					std::cout << " ���򼸴�����" << std::endl;
					std::cin >> time;
					if(p1.decMoney(100 * time) > 0)
					{
						p1.incDe(10 * time);
					}
					else
					{
						p1.incMoney(100 * time);
						std::cout << " ��Ҳ���" << std::endl;
						Sleep(1000);
					}
				}
				break;

			case 3:
				{
					std::cout << " ���򼸴�����" << std::endl;
					std::cin >> time;
					if(p1.decMoney(100 * time) > 0)
					{
						p1.incHp(100 * time);
					}
					else
					{
						p1.incMoney(100 * time);
						std::cout << " ��Ҳ���" << std::endl;
						Sleep(1000);
					}
				}
				break;
			}		
		}
		break;

	//�м��̵�
	case 2:
		{
			std::cout << " 1��������" << std::endl;
			std::cout << " 2��������" << std::endl;
			std::cout << " 3������ֵ" << std::endl;
			std::cin >> select2;
			switch(select2)
			{
			case 1:
				{
					std::cout << " ���򼸴�����" << std::endl;
					std::cin >> time;
					if(p1.decMoney(150 * time) > 0)
					{
						p1.incAT(20 * time);
					}
					else
					{
						p1.incMoney(150 * time);
						std::cout << " ��Ҳ���" << std::endl;
						Sleep(1000);
					}
				}
				break;
				
			case 2:
				{
					std::cout << " ���򼸴�����" << std::endl;
					std::cin >> time;
					if(p1.decMoney(150 * time) > 0)
					{
						p1.incDe(20 * time);
					}
					else
					{
						p1.incMoney(150 * time);
						std::cout << " ��Ҳ���" << std::endl;
						Sleep(1000);
					}
				}
				break;
				
			case 3:
				{
					std::cout << " ���򼸴�����" << std::endl;
					std::cin >> time;
					if(p1.decMoney(150 * time) > 0)
					{
						p1.incHp(200 * time);
					}
					else
					{
						p1.incMoney(150 * time);
						std::cout << " ��Ҳ���" << std::endl;
						Sleep(1000);
					}
				}
				break;
			}
		}
		break;

	//�߼��̵�
	case 3:
		{
			std::cout << " ���򼸴�����" << std::endl;
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
				std::cout << " ��Ҳ���" << std::endl;
				Sleep(1000);
			}

		}
		break;

	//��Ч�̵�
	case 4:
		{
			std::cout << " ���򼸴�����" << std::endl;
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
				std::cout << " ��Ҳ���" << std::endl;
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