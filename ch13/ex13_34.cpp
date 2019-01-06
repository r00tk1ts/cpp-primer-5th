#include "ex13_34.h"
#include <iostream>

void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    lhs.remove_from_Folders();
    rhs.remove_from_Folders();

    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);

    lhs.add_to_Folders(lhs);
    rhs.add_to_Folders(rhs);
}

void Message::save(Folder &f)
{
    addFldr(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    remFldr(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
    for(auto f : m.folders)
        f->addMsg(this);
}

void Message::remove_from_Folders()
{
    for(auto f : folders)
        f->remMsg(this);
}

Message::Message(const Message &m) 
    : contents(m.contents), folders(m.folders) 
{
    add_to_Folders(m);
}

Message::~Message() 
{ 
    remove_from_Folders(); 
}

Message &Message::operator=(const Message &rhs) 
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

void Message::print_debug() 
{ 
    std::cout << contents << std::endl; 
}

void swap(Folder &lhs, Folder &rhs) 
{
    using std::swap;
    lhs.remove_from_Message();
    rhs.remove_from_Message();

    swap(lhs.msgs, rhs.msgs);
    
    lhs.add_to_Message(lhs);
    rhs.add_to_Message(rhs);
}

void Folder::add_to_Message(const Folder &f) 
{
    for (auto m : f.msgs)
        m->addFldr(this);
}

Folder::Folder(const Folder &f) 
    : msgs(f.msgs) 
{ 
    add_to_Message(f); 
}

void Folder::remove_from_Message() 
{
    for (auto m : msgs)
        m->remFldr(this);
}

Folder::~Folder() 
{ 
    remove_from_Message(); 
}

Folder &Folder::operator=(const Folder &rhs) 
{
    remove_from_Message();
    msgs = rhs.msgs;
    add_to_Message(rhs);
    return *this;
}

void Folder::print_debug() 
{
    for (auto m : msgs)
        std::cout << m->contents << " ";
    std::cout << std::endl;
}