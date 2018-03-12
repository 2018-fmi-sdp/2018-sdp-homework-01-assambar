#pragma once

#include "String.h"

class Command {
public:
    virtual ~Command() {}
    
    Command(const String& name) : _name(name) {}
    
    virtual bool execute(const String& cmdLine, String* output) = 0;
    
    const String& GetName() const { return _name; }
    
private:
    String _name;
};

class QuitCmd : public Command {
public:
    QuitCmd() : Command("quit") {}
    
    bool execute(const String& cmdLine, String* output) {
        return false;   // false means we end the repl
    }
};

class PromptCmd : public Command {
public:
    PromptCmd(String* prompt) : Command("cmd.prompt"), _prompt(prompt) {}
    
    bool execute(const String& cmdLine, String* output) {
        // cmd.prompt somestuff => somestuff
        // we need substring of cmdLine from strlen("cmd.prompt ") till the end
        String newPrompt = subString(cmdLine, GetName().size() + 1);
        *_prompt = newPrompt;
        return true;
    }
private:
    String* _prompt;
};
