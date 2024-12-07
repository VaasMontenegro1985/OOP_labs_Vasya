#include <gtest/gtest.h>
#include <stdexcept>
#include "../include/point.h"
#include "../include/NPC.h" 
#include "../include/vaas.h" 
#include "../include/buck.h" 
#include "../include/jason.h"
#include "../include/game.h" 

TEST(UtilsTest, testeqDouble)
{
    double a = 3.0;
    double b = 2.0;
    double c = 5.0;
    bool result = Utils::eqDouble(a + b, c);
    ASSERT_TRUE(result == true);
}

TEST(UtilsTest, testeqDoubleFalse)
{
    double a = 3.0;
    double b = 2.0;
    double c = 5.1;
    bool result = Utils::eqDouble(a + b, c);
    ASSERT_TRUE(result == false);
}

TEST(UtilsTest, testSTriangle)
{
    double a = 3.0;
    double b = 4.0;
    double c = 5.0;
    double s = 6.0;
    bool result = Utils::eqDouble(s, Utils::STriangle(a, b, c));
    ASSERT_TRUE(result == true);
}

TEST(UtilsTest, testSTriangleFalse)
{
    double a = 3.0;
    double b = 4.0;
    double c = 5.0;
    double s = 8.0;
    bool result = Utils::eqDouble(s, Utils::STriangle(a, b, c));
    ASSERT_TRUE(result == false);
}

TEST(PointTest, testConctructorAndEquality)
{
    Point<double> a;
    Point b(0.0, 0.0);
    bool result = (a == b);
    ASSERT_TRUE(result == true);
}

TEST(PointTest, testEqualityFalse)
{
    Point a(1.0, 2.0);
    Point b(1.0);
    bool result = (a == b);
    ASSERT_TRUE(result == false);
}

TEST(PointTest, getterX) {
    Point point(2.0, 3.0);
    double getXRes = point.getX();

    ASSERT_TRUE(getXRes == 2.0);
}

TEST(PointTest, getterY) {
    Point point(2.0, 3.0);
    double getYRes = point.getY();

    ASSERT_TRUE(getYRes == 3.0);
}
TEST(PointTest, testConctructorFalse)
{
    Point<double> a;
    Point b(1.0);
    bool result = (a == b);
    ASSERT_TRUE(result == false);
}

TEST(PointTest, testSummarize)
{
    Point a(1.0, 1.0);
    Point b(1.0, 2.0);
    Point c = a + b;
    Point d(2.0, 3.0);
    bool result = (c == d);
    ASSERT_TRUE(result == true);
}

TEST(PointTest, testSummarizeFalse)
{
    Point a(1.0, 1.0);
    Point b(1.0, 2.0);
    Point c = a + b;
    Point d(2.0, 4.0);
    bool result = (c == d);
    ASSERT_TRUE(result == false);
}

TEST(PointTest, testSubstraction)
{
    Point a(1.0, 1.0);
    Point b(1.0, 2.0);
    Point c(2.0, 3.0);
    Point d = c - b;
    bool result = (a == d);
    ASSERT_TRUE(result == true);
}

TEST(PointTest, testSubstractionFalse)
{
    Point a(1.0, 1.0);
    Point b(1.0, 2.0);
    Point c(2.0, 3.0);
    Point d = c - b;
    bool result = (b == d);
    ASSERT_TRUE(result == false);
}

TEST(PointTest, testProductNumber)
{
    Point a(1.0, 3.0);
    Point b = a * 3;
    Point c(3.0, 9.0);
    bool result = (b == c);
    ASSERT_TRUE(result == true);
}

TEST(PointTest, testProductNumberFalse)
{
    Point a(1.0, 3.0);
    Point b = a * 3;
    Point c(1.0, 3.0);
    bool result = (b == c);
    ASSERT_TRUE(result == false);
}

TEST(PointTest, testPosAbs) {
    Point p1(3, 4);
    bool result = Utils::eqDouble(p1.abs(), 5.0);
    ASSERT_TRUE(result == true);
}

TEST(PointTest, testPosAbsFalse) {
    Point p1(3, 4);
    bool result = Utils::eqDouble(p1.abs(), 5.3);
    ASSERT_TRUE(result == false);
}

TEST(PointTest, testNegAbs) {
    Point p1(-3, -4);
    bool result = Utils::eqDouble(p1.abs(), 5.0);
    ASSERT_TRUE(result == true);
}

TEST(PointTest, testNegAbsFalse) {
    Point p1(-3, -4);
    bool result = Utils::eqDouble(p1.abs(), 1.0);
    ASSERT_TRUE(result == false);
}

TEST(PointTest, testZerosAbs) {
    Point p1(0.0, 0.0);
    bool result = Utils::eqDouble(p1.abs(), 0.0);
    ASSERT_TRUE(result == true);
}

TEST(PointTest, testZerosAbsFalse) {
    Point p1(0.0, 0.0);
    bool result = Utils::eqDouble(p1.abs(), 0.2);
    ASSERT_TRUE(result == false);
}

TEST(PointTest, testCopy) {
    Point p1(1.0, 2.0);
    Point p2(2.0, 2.0);
    Point p3 = p1;
    bool result = (p1 == p3);
    bool result1 = (p2 == p3);
    ASSERT_TRUE(result == true);
    ASSERT_TRUE(result1 == false);
}


TEST(Npc, unique_name_free) {
    ASSERT_NO_THROW({
        {
            Vaas vaas(Point(3, 5), "npc_free");
        }
        {
            Buck vaas2(Point(3, 5), "npc_free");
        }
    });
}

TEST(Npc, enough_close) {
    Vaas vaas1(Point(1, 2), "vaas1");
    std::shared_ptr<Vaas> vaas2 = std::make_shared<Vaas>(Point(5, 5), "vaas2");
    
    bool result = vaas1.isClose(vaas2);

    ASSERT_TRUE(result == true);
}

TEST(Npc, not_enough_close) {
    Vaas vaas1(Point(1, 2), "vaas1");
    std::shared_ptr<Vaas> vaas2 = std::make_shared<Vaas>(Point(6, 5), "vaas2");
    
    bool result = vaas1.isClose(vaas2);

    ASSERT_TRUE(result == false);
}

TEST(Npc, getter_Coords) {
    Vaas vaas1(Point(1, 2), "vaas1");

    Point result = vaas1.getCoords();

    ASSERT_TRUE(result == Point(1, 2));
}

TEST(Npc, getter_name) {
    Vaas vaas1(Point(1, 2), "Montenegro");

    std::string result = vaas1.getName();

    ASSERT_TRUE(result == "Montenegro");
}

TEST(NpcBuck, accept_true) {
    std::shared_ptr<NPC> murderer = std::make_shared<Vaas>(Point(6, 5), "murderer");
    std::shared_ptr<NPC> victim = std::make_shared<Jason>(Point(6, 5), "victim");

    bool result = victim->accept(murderer);

    ASSERT_TRUE(result == true);
}

TEST(NpcBuck, accept_false) {
    std::shared_ptr<NPC> murderer = std::make_shared<Vaas>(Point(6, 5), "murderer");
    std::shared_ptr<NPC> victim = std::make_shared<Buck>(Point(6, 5), "victim");

    bool result = victim->accept(murderer);

    ASSERT_TRUE(result == false);
}

TEST(NpcVaas, constructor) {
    Vaas vaas(Point(3, 5), "vaas.constructor");

    NPCType result = vaas.getType();

    ASSERT_TRUE(result == NPCType::VaasMontenegro);
}

TEST(NpcVaas, win_vaas) {
    Vaas murderer(Point(3, 5), "murderer");
    Vaas victim(Point(3, 5), "victim");

    bool result = murderer.fight(victim);

    ASSERT_TRUE(result == true);
}

TEST(NpcVaas, win_jason) {
    Vaas murderer(Point(3, 5), "murderer");
    Jason victim(Point(3, 5), "victim");

    bool result = murderer.fight(victim);

    ASSERT_TRUE(result == true);
}

TEST(NpcVaas, win_buck) {
    Vaas murderer(Point(3, 5), "murderer");
    Buck victim(Point(3, 5), "victim");

    bool result = murderer.fight(victim);

    ASSERT_TRUE(result == false);
}

TEST(NpcJason, constructor) {
    Jason jason(Point(3, 5), "jason.constructor");

    NPCType result = jason.getType();

    ASSERT_TRUE(result == NPCType::JasonBrody);
}

TEST(NpcJason, win_vaas) {
    Jason murderer(Point(3, 5), "murderer");
    Vaas victim(Point(3, 5), "victim");

    bool result = murderer.fight(victim);

    ASSERT_TRUE(result == false);
}

TEST(NpcJason, win_jason) {
    Jason murderer(Point(3, 5), "murderer");
    Jason victim(Point(3, 5), "victim");

    bool result = murderer.fight(victim);

    ASSERT_TRUE(result == false);
}

TEST(NpcJason, win_buck) {
    Jason murderer(Point(3, 5), "murderer");
    Buck victim(Point(3, 5), "victim");

    bool result = murderer.fight(victim);

    ASSERT_TRUE(result == true);
}

TEST(NpcBuck, constructor) {
    Buck buck(Point(3, 5), "buck.constructor");

    NPCType result = buck.getType();

    ASSERT_TRUE(result == NPCType::BuckHughes);
}

TEST(NpcBuck, win_vaas) {
    Buck murderer(Point(3, 5), "murderer");
    Vaas victim(Point(3, 5), "victim");

    bool result = murderer.fight(victim);

    ASSERT_TRUE(result == false);
}

TEST(NpcBuck, win_jason) {
    Buck murderer(Point(3, 5), "murderer");
    Jason victim(Point(3, 5), "victim");

    bool result = murderer.fight(victim);

    ASSERT_TRUE(result == false);
}

TEST(NpcBuck, win_buck) {
    Buck murderer(Point(3, 5), "murderer");
    Buck victim(Point(3, 5), "victim");

    bool result = murderer.fight(victim);

    ASSERT_TRUE(result == false);
}

TEST(Random_factory, create_vaas) {
    FactoryRandom factory(500, 100);

    std::shared_ptr<NPC> npc = factory.CreateVaas();
    NPCType result = npc->getType();

    ASSERT_TRUE(result == NPCType::VaasMontenegro);
}

TEST(Random_factory, create_jason) {
    FactoryRandom factory(500, 100);

    std::shared_ptr<NPC> npc = factory.CreateJason();
    NPCType result = npc->getType();

    ASSERT_TRUE(result == NPCType::JasonBrody);
}

TEST(Random_factory, create_buck) {
    FactoryRandom factory(500, 100);

    std::shared_ptr<NPC> npc = factory.CreateBuck();
    NPCType result = npc->getType();

    ASSERT_TRUE(result == NPCType::BuckHughes);
}

TEST(Random_factory, create_vaas_type) {
    FactoryRandom factory(500, 100);

    std::shared_ptr<NPC> npc = factory.CreateNPC(NPCType::VaasMontenegro);
    NPCType result = npc->getType();

    ASSERT_TRUE(result == NPCType::VaasMontenegro);
}

TEST(Random_factory, create_jason_type) {
    FactoryRandom factory(500, 100);

    std::shared_ptr<NPC> npc = factory.CreateNPC(NPCType::JasonBrody);
    NPCType result = npc->getType();

    ASSERT_TRUE(result == NPCType::JasonBrody);
}

TEST(Random_factory, create_buck_type) {
    FactoryRandom factory(500, 100);

    std::shared_ptr<NPC> npc = factory.CreateNPC(NPCType::BuckHughes);
    NPCType result = npc->getType();

    ASSERT_TRUE(result == NPCType::BuckHughes);
}

TEST(Random_factory, error_type) {
    FactoryRandom factory(500, 100);

    ASSERT_THROW(factory.CreateNPC(NPCType::Unknown), std::logic_error);
}

TEST(Random_factory, Coordinates) {
    FactoryRandom factory(500, 100);

    std::shared_ptr<NPC> npc = factory.CreateRandomNPC();
    Point Coords = npc->getCoords();
    
    bool result = 0 <= Coords.getX() && Coords.getX() < 500 && 0 <= Coords.getY() && Coords.getY() < 100;

    ASSERT_TRUE(result == true);
}

TEST(Factory_file, factory_file) {
    Point<int> Coords1, Coords2, Coords3;
    std::string name1, name2, name3;
    {
        FactoryFile::NPCSaver saver("test_save.save", 3);

        FactoryRandom factory(500, 100);

        std::shared_ptr<NPC> npc1 = factory.CreateVaas();
        std::shared_ptr<NPC> npc2 = factory.CreateJason();
        std::shared_ptr<NPC> npc3 = factory.CreateBuck();

        Coords1 = npc1->getCoords();
        Coords2 = npc2->getCoords();
        Coords3 = npc3->getCoords();

        name1 = npc1->getName();
        name2 = npc2->getName();
        name3 = npc3->getName();

        saver.saveNPC(npc1);
        saver.saveNPC(npc2);
        saver.saveNPC(npc3);
    }

    {
        FactoryFile factory("test_save.save");
        
        std::shared_ptr<NPC> npc1 = factory.createNPCFromFile();
        std::shared_ptr<NPC> npc2 = factory.createNPCFromFile();
        std::shared_ptr<NPC> npc3 = factory.createNPCFromFile();

        bool result = npc1->getType() == NPCType::VaasMontenegro &&
        npc1->getName() == name1 &&
        npc1->getCoords() == Coords1 &&
        npc2->getType() == NPCType::JasonBrody &&
        npc2->getName() == name2 &&
        npc2->getCoords() == Coords2 &&
        npc3->getType() == NPCType::BuckHughes &&
        npc3->getName() == name3 &&
        npc3->getCoords() == Coords3;

        ASSERT_TRUE(result == true);
    }
}

TEST(ClassObserver, observer) {
    Murder event("", "");

    class ConcreteObserver : public IObserver<Murder> {
        private:
            Murder *eventPtr;
        
        protected:
            void notify (Murder event) override {
                eventPtr->Murderer = event.Murderer;
                eventPtr->Victim = event.Victim;
            } 

        public:
            ConcreteObserver (Murder *ptr) : eventPtr{ptr} {};  
    };

    std::shared_ptr<ConcreteObserver> observer = std::make_shared<ConcreteObserver>(&event);

    FactoryRandom factory(500, 100);

    std::shared_ptr<NPC> murderer = std::make_shared<Vaas>(Point(3, 5), "murderer");
    std::shared_ptr<NPC> victim = std::make_shared<Jason>(Point(3, 5), "victim");

    murderer->subscribe(observer);
    victim->accept(murderer);

    bool result = event.Murderer == "murderer" && event.Victim == "victim";

    ASSERT_TRUE(result);
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}