#include "../tools.hpp"

bool isBufferHasSequence(std::vector<std::string> buffer, Sequence sequenceData){
    std::vector<std::string> sequence = sequenceData.getSequence();
    int bufferSize = buffer.size();
    int sequenceSize = sequence.size();
    int batasAtas = bufferSize - sequenceSize;
    bool found = false;
    int i = 0;
    while((i <= batasAtas) && (!found)){
        bool tempFound = true;
        for(int j=0;j<sequenceSize;j++){
            if (buffer[j+i] != sequence[j]){
                tempFound = false;
                break;
            }
        }
        i++;
        found = tempFound;        
    }

    return found;
}


bool isLangkahEqual(Langkah langkah, int i, int j ){
    return (langkah.i == i) && (langkah.j == j);
}