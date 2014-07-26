/**
  A demo to show how to suppress unused parameters in functions.

  @author ettl martin
  @date   2012-08-05
*/

/*  ---------------------------------------------------------------------------- */
/*  macros to avoid compiler warnings */
/*  ---------------------------------------------------------------------------- */

/*  Macro to cut down on compiler warnings. */
#if 1 /*  there should be no more any compilers needing the "#else" version */
    #define UNUSED(identifier) /* identifier */
#else  /*  stupid, broken compiler */
    #define UNUSED(identifier) identifier
#endif

// This testfunction causes a compiler warning about an unused parameter
void vTest(int iVar)
{
}


/// Possibility 1:
void vTest1(int UNUSED(dVar))
{

}


/// Possibility 2:
void vTest2(int i __attribute__((unused)))
{

} 

/// Possibility 3:
void vTest3(int i)
{
	(void)i;
}

/// Possibility 4:
/// cppcheck gives a waring: [../src/Application.cpp:35]: (warning) Redundant assignment of "i" to itself
/// clang warning: Application.cpp:36:3: warning: explicitly assigning a variable of type 'int' to itself [-Wself-assign]
//      i=i;
///     ~^~

void vTest4(int i)
{
	i=i;
}



int main()
{
	vTest1(0);
	vTest2(0);
	vTest3(0);
	vTest4(0);
	return 0;
}

