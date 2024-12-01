#pragma once
#include <fstream>
#include "../npc.h" 
#include "../vaas.h" 
#include "../buck.h" 
#include "../jason.h"

class FactoryFile
{
private:
    std::size_t readCount;
    std::size_t inFileCount;
    std::ifstream file;
public:
    FactoryFile(std::string filename);
    ~FactoryFile();

    bool endOfFile();
    std::shared_ptr<NPC> createNPCfromFile(){};
    
    class NPCSaver { 
            private: 
                std::ofstream file; 
             
            public: 
                NPCSaver(std::string filename, std::size_t writeCount); 
                ~NPCSaver(); 
 
                void saveNPC (const std::shared_ptr<NPC> &npc); 
        }; 
};


