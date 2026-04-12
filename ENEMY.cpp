#include "ENEMY.h"
#include "CHARACTER.h"
#include <iostream>
#include "WEAPON.h"
#include "ARMOR.h"
#include "RandomUtil.h"
#include "Global.h"

Enemy::Enemy(std::string name) : Character(name) {
    
    // constructor implementation
    generateStats();

}

//Member Functions
void Enemy::generateStats() {

    int hp;
    int damage;
    int accuracy;

    if (difficulty == 1) {

        hp = randomInt(16, 18);
        damage = randomInt(7, 9);
        accuracy = randomInt(7, 8);

    }
    else if (difficulty == 2) {
    
        hp = randomInt(17, 20);
        damage = randomInt(8, 10);
        accuracy = randomInt(6, 8);
    }
    else {
    
        hp = randomInt(18, 22);
        damage = randomInt(10, 12);
        accuracy = randomInt(6, 9);
    }

    setHealth(hp);
    setDamage(damage);
    setAccuracy(accuracy);

}


