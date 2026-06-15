#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <string>
#include <vector>

class Directory
{
private:
    std::string name;
    Directory* parent;
    std::vector<Directory*> children;

public:
    Directory(const std::string& directoryName,
              Directory* parentDirectory = nullptr);

    std::string getName() const;

    Directory* getParent() const;

    const std::vector<Directory*>& getChildren() const;

    void addChild(Directory* child);
};

#endif