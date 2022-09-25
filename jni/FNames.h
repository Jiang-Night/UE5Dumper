#ifndef FNAMES_H
#define FNAMES_H

using namespace std;

uint32 MAX_SIZE = 100;
uint32 GNameLimit = 170000;

struct WideStr {
    static int is_surrogate(UTF16 uc) {
        return (uc - 0xd800u) < 2048u;
    }

    static int is_high_surrogate(UTF16 uc) {
        return (uc & 0xfffffc00) == 0xd800;
    }

    static int is_low_surrogate(UTF16 uc) {
        return (uc & 0xfffffc00) == 0xdc00;
    }

    static wchar_t surrogate_to_utf32(UTF16 high, UTF16 low) {
        return (high << 10) + low - 0x35fdc00;
    }

    static wchar_t *w_str(kaddr str, size_t len) {
        wchar_t *output = new wchar_t[len + 1];

        UTF16 *source = ReadArr<UTF16>(str, len);

        for (int i = 0; i < len; i++) {
            const UTF16 uc = source[i];
            if (!is_surrogate(uc)) {
                output[i] = uc;
            } else {
                if (is_high_surrogate(uc) && is_low_surrogate(source[i]))
                    output[i] = surrogate_to_utf32(uc, source[i]);
                else
                    output[i] = L'?';
            }
        }

        free(source);

        output[len] = L'\0';
        return output;
    }

    static string getString(kaddr StrPtr, int StrLength) {
        wstring str = w_str(StrPtr, StrLength);

        string result(MAX_SIZE, '\0');

        wcstombs((char *) result.data(), str.c_str(), MAX_SIZE);

        return result;
    }
};

string GetFNameFromID(uint32 index) {

    uint32 Block = index >> 16;
    uint16 Offset = index & 65535;

    kaddr FNamePool = getRealOffset(Offsets::GNames) + Offsets::GNamesToFNamePool;

    kaddr NamePoolChunk = getPtr(
            FNamePool + Offsets::FNamePoolToBlocks + (Block * Offsets::PointerSize));
    kaddr FNameEntry = NamePoolChunk + (Offsets::FNameStride * Offset);

    int16 FNameEntryHeader = Read<int16>(FNameEntry);
    kaddr StrPtr = FNameEntry + Offsets::FNameEntryToString;
    int StrLength = FNameEntryHeader >> Offsets::FNameEntryToLenBit;

    ///Unicode Dumping Not Supported Yet
    if (StrLength > 0 && StrLength < 250) {
        bool wide = FNameEntryHeader & 1;
        if (wide) {
            return WideStr::getString(StrPtr, StrLength);
        } else {
            return ReadStr2(StrPtr, StrLength);
        }
    } else {
        return "None";
    }

}



#endif