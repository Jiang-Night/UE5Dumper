#ifndef GUOBJECTS_H
#define GUOBJECTS_H

#include "FNames.h"
#include "StructsSDK.h"

using namespace std;

int32 GetObjectCount() {
    return Read<int32>(getRealOffset(Offsets::GUObjectArray) +
                       Offsets::FUObjectArrayToTUObjectArray +
                       Offsets::TUObjectArrayToNumElements);

}

kaddr GetUObjectFromID(uint32 index) {
    kaddr TUObjectArray = getPtr(
            getRealOffset(Offsets::GUObjectArray) + Offsets::FUObjectArrayToTUObjectArray);
    kaddr Chunk = getPtr(TUObjectArray + ((index / 0x10000) * Offsets::PointerSize));

    return getPtr(Chunk + Offsets::FUObjectItemPadd +
                  ((index % 0x10000) * Offsets::FUObjectItemSize));

}



#endif