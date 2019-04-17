#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

#include <python_plugin.hh>
#include <rs274ngc_interp.hh>
extern Interp *pinterp;
Interp dummy_interp;
#include <stdio.h>

// KLUDGE fix missing symbol the ugly way
struct _inittab builtin_modules[] = {
    { nullptr, nullptr }
};

int main (int argc, char * argv[]) {
    // KLUDGE just to satisfy saicanon dependencies, not used in tests
    dummy_interp = Interp();
    pinterp = &dummy_interp;
    _outfile = fopen("test_interp_canon.log", "w");
    PythonPlugin::instantiate(builtin_modules);
    return Catch::Session().run( argc, argv );
}
