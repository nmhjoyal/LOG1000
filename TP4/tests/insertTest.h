#include <string>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>

#include "../Vector.h"

using namespace CppUnit;
using namespace std;

//-----------------------------------------------------------------------------

class insertTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(insertTest);
    CPPUNIT_TEST(test1);
    CPPUNIT_TEST(test2);
    CPPUNIT_TEST_SUITE_END();
    
public:
    void setUp(void);
    void tearDown(void);
    
protected:
    void test1(void);
    void test2(void);
    void test3(void);
    void test4(void);
    
private:
    
    Vector *vec;
};

// ------------------------ IMPLEMENTATION ------------------------

void insertTest::test1(void)
{
	//index valide
	CPPUNIT_ASSERT(vec->insert(12, "Hello"));
	//capacite = 40
}

void insertTest::test2(void)
{
	//index valide
    CPPUNIT_ASSERT(vec->insert(12, "Hello"));
}

void insertTest::test3(void)
{
	//index < 0, invalide
    CPPUNIT_ASSERT(vec->insert(-1, "Hello"));
}

void insertTest::test4(void)
{
	//index > count, invalide
    CPPUNIT_ASSERT(vec->insert(30,"Hello"));
}


void insertTest::setUp(void)
{
	//on fixe le nombre d'éléments pour facilité les tests
    vec = new Vector(20, "Goodbye");
}

void insertTest::tearDown(void)
{
    delete vec;
}
