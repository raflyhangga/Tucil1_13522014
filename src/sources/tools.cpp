#include "../tools.hpp"

bool isBufferHasSequence(std::vector<std::string> &buffer, Sequence &sequenceData){
    
    // std::vector<std::string> sequence = sequenceData.getSequence();
    // int bufferSize = buffer.size();
    // int sequenceSize = sequence.size();

    // if (sequenceSize > bufferSize) {
    //     return false;
    // }

    // auto seqIterator = sequence.begin();
    // for (std::string token: buffer){
    //     buffer
    // }
    std::vector<std::string> sequence = sequenceData.getSequence();
    int bufferSize = buffer.size();
    int sequenceSize = sequence.size();
    int batasAtas = bufferSize - sequenceSize;
    bool found = false;
    int i = 0;
    int j = 0;
    while ((i <= batasAtas) && (!found)){
        // int j = i;
        if (buffer[i+j] == sequence[j]){
            j++;
            if (j == sequenceSize-1){
                found = true;
            }
        }
        else {
            j = 0;
            i++;
        }

    }
    // while((i <= batasAtas) && (!found)){
    //     bool tempFound = true;
    //     for(int j=0;j<sequenceSize;j++){
    //         if (buffer[j+i] != sequence[j]){
    //             tempFound = false;
    //             break;
    //         }
    //     }
    //     i++;
    //     found = tempFound;        
    // }

    return found;

}


bool isLangkahEqual(Langkah &langkah, int i, int j ){
    return (langkah.i == i) && (langkah.j == j);
}