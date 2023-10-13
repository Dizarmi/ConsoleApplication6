#include <iostream>
#include <string>

// Abstract classes for dungeon objects
class Dungeon {
public:
    Dungeon(const std::string& description) : description(description) {}
    std::string getDescription() const {
        return description;
    }

private:
    std::string description;
};

class Monster {
public:
    Monster(const std::string& description) : description(description) {}
    std::string getDescription() const {
        return description;
    }

private:
    std::string description;
};

class Treasure {
public:
    Treasure(const std::string& description) : description(description) {}
    std::string getDescription() const {
        return description;
    }

private:
    std::string description;
};

// Abstract dungeon factory
class AbstractDungeonFactory {
public:
    virtual Dungeon* createDungeon() = 0;
    virtual Monster* createMonster() = 0;
    virtual Treasure* createTreasure() = 0;
};

// Concrete factory for "Dragon Dungeons"
class DragonDungeonFactory : public AbstractDungeonFactory {
public:
    Dungeon* createDungeon() {
        return new Dungeon("Dragon Dungeons");
    }

    Monster* createMonster() {
        return new Monster("Fire-breathing dragon");
    }

    Treasure* createTreasure() {
        return new Treasure("Gold and emeralds");
    }
};

// Concrete factory for "Vampire Dungeons"
class VampireDungeonFactory : public AbstractDungeonFactory {
public:
    Dungeon* createDungeon() {
        return new Dungeon("Vampire Dungeons");
    }

    Monster* createMonster() {
        return new Monster("Bloodthirsty vampire");
    }

    Treasure* createTreasure() {
        return new Treasure("Glass bottles of blood");
    }
};

// Concrete factory for "Treasure Dungeons"
class TreasureDungeonFactory : public AbstractDungeonFactory {
public:
    Dungeon* createDungeon() {
        return new Dungeon("Treasure Dungeons");
    }

    Monster* createMonster() {
        return new Monster("Treasure guardian");
    }

    Treasure* createTreasure() {
        return new Treasure("Treasure coin");
    }
};

int main() {
    AbstractDungeonFactory* dragonFactory = new DragonDungeonFactory();
    Dungeon* dragonDungeon = dragonFactory->createDungeon();
    Monster* dragonMonster = dragonFactory->createMonster();
    Treasure* dragonTreasure = dragonFactory->createTreasure();

    AbstractDungeonFactory* vampireFactory = new VampireDungeonFactory();
    Dungeon* vampireDungeon = vampireFactory->createDungeon();
    Monster* vampireMonster = vampireFactory->createMonster();
    Treasure* vampireTreasure = vampireFactory->createTreasure();

    AbstractDungeonFactory* treasureFactory = new TreasureDungeonFactory();
    Dungeon* treasureDungeon = treasureFactory->createDungeon();
    Monster* treasureMonster = treasureFactory->createMonster();
    Treasure* treasureTreasure = treasureFactory->createTreasure();

    // Output information about dungeon objects
    std::cout << "In " << dragonDungeon->getDescription() << ": " << dragonMonster->getDescription() << ", " << dragonTreasure->getDescription() << std::endl;
    std::cout << "In " << vampireDungeon->getDescription() << ": " << vampireMonster->getDescription() << ", " << vampireTreasure->getDescription() << std::endl;
    std::cout << "In " << treasureDungeon->getDescription() << ": " << treasureMonster->getDescription() << ", " << treasureTreasure->getDescription() << std::endl;

    return 0;
}
