#ifndef TESTMODULE_HPP
#define TESTMODULE_HPP

#include <SDL2TK/Module.hpp>

class TestModule : public SDL2TK::Module
{
    public:
        TestModule();
        virtual ~TestModule();

        virtual void OnOpen();
        virtual void OnClose();
        virtual void OnLoop();

        virtual void OnResize(int width, int height);
    protected:
    private:
};

#endif
