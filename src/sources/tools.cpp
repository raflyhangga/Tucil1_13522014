#include "../header/tools.hpp"

bool isBufferHasSequence(Arraydin<std::string> &buffer, Sequence &sequenceData){
    Arraydin<std::string> sequence = sequenceData.getSequence();
    int bufferSize = buffer.size();
    int sequenceSize = sequence.size();
    int batasAtas = bufferSize - sequenceSize;
    bool found = false;
    int i = 0;
    while((i <= batasAtas) && (!found)){
        bool tempFound = true;
        for(int j=0;j<sequenceSize;j++){
            if (buffer.data[j+i] != sequence.data[j]){
                tempFound = false;
                break;
            }
        }
        i++;
        found = tempFound;        
    }

    return found;

}


bool isLangkahEqual(Langkah &langkah, int i, int j ){
    return (langkah.i == i) && (langkah.j == j);
}