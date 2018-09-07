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

class getTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(getTest);
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
    
private:
    
    Vector *vec;
};

// ------------------------ IMPLEMENTATION ------------------------

void getTest::test1(void)
{
	//index < 0 
    CPPUNIT_ASSERT("Hello" == vec->get(-1));
}

void getTest::test2(void)
{
	// index > 0 et < 20
    CPPUNIT_ASSERT("Hello" == vec->get(12));
}

void getTest::test3(void)
{
	//index > 20
    CPPUNIT_ASSERT("Hello" == vec->get(50));
}

void getTest::setUp(void)
{
	//On modifie initialisation pour facilité les tests 
    vec = new Vector(20, "Hello");
}

void getTest::tearDown(void)
{
    delete vec;
}
