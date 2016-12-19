#include <iostream>

#include "translator_impl.h"
#include "code_generator.h"

using namespace mathvm;

Status* TranslatorImpl::translate(const string& program, Code** code) 
{
    Parser parser;
    Status* status = parser.parseProgram(program);
    if (status->isError())
    {
        return status;
    }
    CodeGenerator code_generator(*code);
    return code_generator.handleFunction(parser.top());
}

Translator* Translator::create(const string& impl) 
{
    return new TranslatorImpl();
}