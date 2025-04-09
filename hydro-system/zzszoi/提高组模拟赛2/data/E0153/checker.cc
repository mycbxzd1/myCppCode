#include "testlib.h"

int main(int argc, char* argv[]) {
    setName("compares two signed integers");
    registerTestlibCmd(argc, argv);
    int T = inf.readInt();
    while(T--){
        int a1=ans.readInt(),o1=ouf.readInt(),a2,o2;
        if(a1!=-1) a2=ans.readInt();
        if(o1!=-1) o2=ouf.readInt();
        if((a1==-1&&o1!=-1)||(a1!=-1&&o1==-1))
            quitf(_wa,"wa on -1");
        if(a1==-1) continue;
        if(std::to_string(a1)+std::to_string(a2)!=std::to_string(o1)+std::to_string(o2))
            quitf(_wa,"wa on link");
    }
    quitf(_ok,"ok");
}