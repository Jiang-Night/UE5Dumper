#ifndef OFFSETS_H
#define OFFSETS_H

#include "Mem.h"

namespace Offsets {
    //Global
    kaddr GWorld;
    kaddr GNames;
    kaddr GUObjectArray;
    kaddr PointerSize;
    kaddr FUObjectItemPadd;
    kaddr FUObjectItemSize;
    //-----PUBG Lite-----//
    kaddr PGLEncSelect;
    kaddr PGLBlockSlice1;
    kaddr PGLBlockShift;
    kaddr PGLBlockSlice2;

    //---------SDK-----------//
    //---------4.23+---------//
    //Class: FNamePool
    kaddr FNameStride;
    kaddr GNamesToFNamePool;//NamePoolData, alignas(FNamePool)
    kaddr FNamePoolToCurrentBlock;
    kaddr FNamePoolToCurrentByteCursor;
    kaddr FNamePoolToBlocks;
    //Class: FNameEntry
    kaddr FNameEntryToLenBit;
    kaddr FNameEntryToString;
    //Class: UStruct
    kaddr UStructToChildProperties;
    //Class: FField
    kaddr FFieldToClass;
    kaddr FFieldToNext;
    kaddr FFieldToName;
    //---------4.18+---------//
    //Class: FNameEntry
    kaddr FNameEntryToNameString;
    //-----------------------//
    //Class: FUObjectArray
    kaddr FUObjectArrayToTUObjectArray;
    //Class: TUObjectArray
    kaddr TUObjectArrayToNumElements;
    //Class: UObject
    kaddr UObjectToInternalIndex;
    kaddr UObjectToClassPrivate;
    kaddr UObjectToFNameIndex;
    kaddr UObjectToOuterPrivate;
    //Class: UField
    kaddr UFieldToNext;
    //Class: UStruct
    kaddr UStructToSuperStruct;
    kaddr UStructToChildren;
    //Class: UFunction
    kaddr UFunctionToFunctionFlags;
    kaddr UFunctionToFunc;
    //Class: UProperty
    kaddr UPropertyToElementSize;
    kaddr UPropertyToPropertyFlags;
    kaddr UPropertyToOffsetInternal;
    //Class: UBoolProperty
    kaddr UBoolPropertyToFieldSize;
    kaddr UBoolPropertyToByteOffset;
    kaddr UBoolPropertyToByteMask;
    kaddr UBoolPropertyToFieldMask;
    //Class: UObjectProperty
    kaddr UObjectPropertyToPropertyClass;
    //Class: UClassProperty
    kaddr UClassPropertyToMetaClass;
    //Class: UInterfaceProperty
    kaddr UInterfacePropertyToInterfaceClass;
    //Class: UArrayProperty
    kaddr UArrayPropertyToInnerProperty;
    //Class: UMapProperty
    kaddr UMapPropertyToKeyProp;
    kaddr UMapPropertyToValueProp;
    //Class: USetProperty
    kaddr USetPropertyToElementProp;
    //Class: UStructProperty
    kaddr UStructPropertyToStruct;
    //Class: UWorld
    kaddr UWorldToPersistentLevel;
    //Class: ULevel
    kaddr ULevelToAActors;
    kaddr ULevelToAActorsCount;

    


    void patch_64() {
        //Class: FNamePool
        FNameStride = 0x2;
        GNamesToFNamePool = 0x30;
        FNamePoolToCurrentBlock = 0x8;
        FNamePoolToCurrentByteCursor = 0xC;
        FNamePoolToBlocks = 0x10;
        //Class: FNameEntry
        FNameEntryToLenBit = 6;
        FNameEntryToString = 0x2;
        //Class: TUObjectArray
        TUObjectArrayToNumElements = 0x14;
        //Class: UStruct
        UStructToChildProperties = 0x44;
        //Class: FField
        FFieldToClass = 0x8;
        FFieldToNext = 0x20;
        FFieldToName = 0x28;
    }

    void patchCustom_64() {

        //Class: UStruct
        UStructToSuperStruct = 0x40;
        UStructToChildren = 0x48;
        UStructToChildProperties = 0x50;
        //Class: UProperty
        UPropertyToElementSize = 0x38;
        UPropertyToPropertyFlags = 0x40;
        UPropertyToOffsetInternal = 0x4C;
        //Class: UFunction
         UFunctionToFunctionFlags = 0xB0;
        UFunctionToFunc = 0xD8;
        //Class: UBoolProperty
        UBoolPropertyToFieldSize = 0x78;
        UBoolPropertyToByteOffset = 0x79;
        UBoolPropertyToByteMask = 0x7A;
        UBoolPropertyToFieldMask = 0x7B;
        //Class: UObjectProperty
        UObjectPropertyToPropertyClass = 0x78;
        //Class: UClassProperty
        UClassPropertyToMetaClass = 0x80;
        //Class: UInterfaceProperty
        UInterfacePropertyToInterfaceClass = 0x80;
        //Class: UArrayProperty
        UArrayPropertyToInnerProperty = 0x78;
        //Class: UMapProperty
        UMapPropertyToKeyProp = 0x78;
        UMapPropertyToValueProp = 0x80;
        //Class: USetProperty
        USetPropertyToElementProp = 0x78;
        //Class: UStructProperty
        UStructPropertyToStruct = 0x78;
    }
    
    
    void initOffsets_64() {
        //Global
        PointerSize = 0x8;
        FUObjectItemPadd = 0x0;
        FUObjectItemSize = 0x18;

        //---------SDK-----------
        //Class: FNameEntry
        FNameEntryToNameString = 0x10;
        //Class: FUObjectArray
        FUObjectArrayToTUObjectArray = 0x10;
        //Class: TUObjectArray
        TUObjectArrayToNumElements = 0xC;
        //Class: UObject
        UObjectToInternalIndex = 0xC;
        UObjectToClassPrivate = 0x10;
        UObjectToFNameIndex = 0x18;
        UObjectToOuterPrivate = 0x20;
        //Class: UField
        UFieldToNext = 0x28;
        //Class: UStruct
        UStructToSuperStruct = 0x30;
        UStructToChildren = 0x38;
        //Class: UFunction
        UFunctionToFunctionFlags = 0xB0;
        UFunctionToFunc = 0xD8;
        //Class: UProperty
        UPropertyToElementSize = 0x34;
        UPropertyToPropertyFlags = 0x38;
        UPropertyToOffsetInternal = 0x44;
        //Class: UBoolProperty
        UBoolPropertyToFieldSize = 0x70;
        UBoolPropertyToByteOffset = 0x71;
        UBoolPropertyToByteMask = 0x72;
        UBoolPropertyToFieldMask = 0x73;
        //Class: UObjectProperty
        UObjectPropertyToPropertyClass = 0x70;
        //Class: UClassProperty
        UClassPropertyToMetaClass = 0x78;
        //Class: UInterfaceProperty
        UInterfacePropertyToInterfaceClass = 0x78;
        //Class: UArrayProperty
        UArrayPropertyToInnerProperty = 0x70;
        //Class: UMapProperty
        UMapPropertyToKeyProp = 0x70;
        UMapPropertyToValueProp = 0x78;
        //Class: USetProperty
        USetPropertyToElementProp = 0x70;
        //Class: UStructProperty
        UStructPropertyToStruct = 0x70;
        //Class: UWorld
        UWorldToPersistentLevel = 0x30;
        //Class: ULevel
        ULevelToAActors = 0x98;
        ULevelToAActorsCount = 0xA0;
        
        patch_64();
        patchCustom_64();
    }
    
}

#endif
