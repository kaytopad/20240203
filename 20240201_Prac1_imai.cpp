/*
ゲーム内にはプレイヤーキャラクターと敵キャラクターが存在し、プレイヤーは敵を倒して得点を稼ぐことが目標です。
各キャラクターは位置座標 (x, y) を持ち、プレイヤーは敵を攻撃することができます。
また、各キャラクターは体力（HP）を持っており、HPが0になるとキャラクターは撃破されます。
プレイヤーキャラクターと敵キャラクターのクラスを実装してください。
各クラスは以下の要件を満たしている必要があります。



1,プレイヤーキャラクタークラス (PlayerCharacter):
位置座標 (x, y) を保持するプライベートメンバ変数。
体力（HP）を保持するプライベートメンバ変数。
体力（HP）はランダムで50〜250までとします。
攻撃メソッド (attack()) を持ち、敵キャラクターを攻撃することができる。
攻撃力は固定の値とする。
ダメージを受けるメソッド (takeDamage(int damage)) を持ち、与えられたダメージ分だけ体力を減少させる。
体力が0以下になると、キャラクターが撃破されたことを示すメッセージを表示するメソッド (displayDefeatMessage()) を持つ。

2,敵キャラクタークラス (EnemyCharacter):
位置座標 (x, y) を保持するプライベートメンバ変数。
体力（HP）を保持するプライベートメンバ変数。
攻撃メソッド (attack()) を持ち、プレイヤーキャラクターを攻撃することができる。
攻撃力はランダムで0〜10とします。
ダメージを受けるメソッド (takeDamage(int damage)) を持ち、与えられたダメージ分だけ体力を減少させる。
体力が0以下になると、キャラクターが撃破されたことを示すメッセージを表示するメソッド (displayDefeatMessage()) を持つ。
*/
#include<iostream>
#include<string.h>
#include<cstdlib>//ランダム関数
#include<ctime>//その都度ランダムの初期化

class PlayerCharacter
{
public:
	PlayerCharacter(int initialX, int initialY) :x(initialX), y(initialY) {
		srand(time(0));
		hp = rand() % 201 + 50;
	};
	~PlayerCharacter() {};
	//攻撃メソッド
	void attack();
	//受けたダメージメソッド
	void takeDamege();
	int getPlayerhp();


private:
	//X,Y座標
	int x, y;
	//体力
	int hp;
	//ダメージが0以下になった時メッセージ描画メソッド
	void displayInfo();
};

class  EnemyCharacter
{
public:
	EnemyCharacter(int initialX, int initialY) :x(initialX), y(initialY) {
		srand(time(0));
		hp = rand() % 201 + 50;
	};;
	~EnemyCharacter() {};

	//攻撃メソッド
	void attack();
	//受けたダメージメソッド
	void takeDamege(int damage);

	//敵のHP
	int getEnemyhp();

private:
	//X,Y座標
	int x, y;
	//体力
	int hp;
	//ダメージが0以下になった時メッセージ描画メソッド
	void displayInfo();

};



/// <summary>
/// プレイヤー攻撃メソッド
/// </summary>
void PlayerCharacter::attack() {
	std::cout << "敵に攻撃しました。" << std::endl;
}
/// <summary>
/// プレイヤー受けたダメージメソッド
/// </summary>
/// <param name="damage">受けたダメージ</param>
void PlayerCharacter::takeDamege()
{
	int damage;
	srand(time(0));
	damage = rand() % 11;
	//ダメージ計算
	hp -= damage;
	std::cout << "敵から" << damage << "点のダメージを受けました。残りのHPは" << hp << "点です\n" << std::endl;
	if (hp <= 0)
	{
		displayInfo();
	}

}
/// <summary>
/// プレイヤーGAMEOVERメソッド
/// </summary>
void PlayerCharacter::displayInfo()
{
	std::cout << "敵の勝利です。\n" << std::endl;
}
/// <summary>
/// プレイヤーGetメソッドHP
/// </summary>
/// <returns>プレイヤーHP</returns>
int PlayerCharacter::getPlayerhp()
{
	return hp;
}


/// <summary>
/// 敵攻撃メソッド
/// </summary>
void EnemyCharacter::attack() {
	std::cout << "プレイヤーに攻撃しました。" << std::endl;
}
/// <summary>
/// 敵受けたダメージメソッド
/// </summary>
/// <param name="damage">受けたダメージ</param>
void EnemyCharacter::takeDamege(int damage)
{
	//ダメージ計算
	hp -= damage;
	std::cout << "プレイヤーから" << damage << "点のダメージを受けました。残りのHPは" << hp << "点です\n" << std::endl;
	if (hp <= 0)
	{
		displayInfo();
	}

}

/// <summary>
/// 敵GAMEOVERメソッド
/// </summary>
void EnemyCharacter::displayInfo()
{
	std::cout << "プレイヤーの勝利です。\n" << std::endl;
}
/// <summary>
/// 敵のGetメソッドHP
/// </summary>
/// <returns>敵のHP</returns>
int EnemyCharacter::getEnemyhp()
{
	return hp;
}


int main()
{
	//PlayerとEnemyをインスタンス化
	PlayerCharacter* player;
	EnemyCharacter* enemy;

	player = new PlayerCharacter(10, 10);
	enemy = new EnemyCharacter(15, 15);

	//ゲームの進行
	while (true)
	{
		int attackDamage;
		std::cout << "プレイヤーのターンです\n" << "1～10までで入力したください。" << std::endl;
		std::cin >> attackDamage;

		player->attack();
		enemy->takeDamege(attackDamage);

		int plyHP = player->getPlayerhp();
		if (plyHP <= 0)
		{
			break;
		}
		std::cout << "敵のターンです\n" << std::endl;
		enemy->attack();
		player->takeDamege();
		int emyHp = enemy->getEnemyhp();
		if (emyHp <= 0)
		{
			break;
		}

	}



}