#include "dumper.h"
#include "Offsets.h"
#include "SDK.h"

using namespace std;

const char *short_options = "hanp:o:g:u:";
const struct option long_options[] = {
        {"help",       no_argument,       nullptr, 'h'},
        {"sdku",       no_argument,       nullptr, 'a'},
        {"package",    required_argument, nullptr, 'p'},
        {"output",     required_argument, nullptr, 'o'},
        {"gname",      required_argument, nullptr, 'g'},
        {"guobj",      required_argument, nullptr, 'u'},
        {nullptr, 0,                      nullptr, 0}
};

void Usage() {
    printf("UE5Dumper v0.01\n");
    printf("Usage: ./ue5dumper <option(s)>\n");
    printf(" Options:\n");
    printf("--SDK Dump With GObjectArray Args--------------------------------------------------------\n");
    printf("  --sdku                              Dump SDK with GUObject\n");
    printf("  --gname <address>                   GNames Pointer Address\n");
    printf("  --guobj <address>                   GUObject Pointer Address\n");
    printf("--Other Args-----------------------------------------------------------------------------\n");
    printf("  --package <packageName>             Package Name of App(Default: com.tencent.ig)\n");
    printf("  --output <outputPath>               File Output path(Default: /sdcard)\n");
    printf("  --help                              Display this information\n");
}

kaddr getHexAddr(const char *addr) {
#ifndef __SO64__
    return (kaddr) strtoul(addr, nullptr, 16);
#else
    return (kaddr) strtoull(addr, nullptr, 16);
#endif
}

int main(int argc, char *argv[]) {
    int c;
    string outputpath("/sdcard");
    bool isValidArg = true,
            isSdkDump = false;
            

    while ((c = getopt_long(argc, argv, short_options, long_options, nullptr)) != -1) {
        switch (c) {
            case 'p':
                pkg = optarg;
                break;
            case 'o':
                outputpath = optarg;
                break;
            case 'g':
                Offsets::GNames = getHexAddr(optarg);
                break;
            case 'u':
                Offsets::GUObjectArray = getHexAddr(optarg);
                break;
            case 'a':
                isSdkDump = true;
                break;
            default:
                isValidArg = false;
                break;
        }
    }

#if defined(__LP64__)
    Offsets::initOffsets_64();
    
    
#else
    puts("Not Support 32Bit");
    return -1;
    
#endif

    
    if (!isValidArg ||
        (!isSdkDump)) {
        printf("Wrong Arguments, Please Check!!\n");
        Usage();
        return -1;
    }

    //Find PID
    target_pid = find_pid(pkg.c_str());
    if (target_pid == -1) {
        cout << "Can't find the process" << endl;
        return -1;
    }
    cout << "Process name: " << pkg.c_str() << ", Pid: " << target_pid << endl;

    //Lib Base Address
    libbase = get_module_base(lib_name);
    if (libbase == 0) {
        cout << "Can't find Library: " << lib_name << endl;
        return -1;
    }
    cout << "Base Address of " << lib_name << " Found At " << setbase(16) << libbase << setbase(10)
         << endl;


    if (isSdkDump) {
        if (Offsets::GNames < 1 || Offsets::GUObjectArray < 1) {
            printf("Please Enter Correct GName and GUObjectArray Addresses!!\n");
            Usage();
            return -1;
        }
        DumpSDK(outputpath);
        cout << endl;
    }

    return 0;
}






