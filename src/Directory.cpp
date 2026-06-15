#include "../include/Directory.h"

Directory::Directory(const std::string& directoryName,
                     Directory* parentDirectory)
    : name(directoryName),
      parent(parentDirectory)
{
}

std::string Directory::getName() const
{
    return name;
}

Directory* Directory::getParent() const
{
    return parent;
}

const std::vector<Directory*>& Directory::getChildren() const
{
    return children;
}

void Directory::addChild(Directory* child)
{
    children.push_back(child);
}