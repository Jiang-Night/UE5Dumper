## UE5Dumper(Unreal Engine 5 Dumper)
Unreal Engine 5 Dumper for Android Devices, Generate Structure SDK of Supported Game in Android. 
## Changelog
- v0.01: First Release

## Features
- No need of Ptrace
- Bypass Anti Debugging
- Dumping of Game Structure SDK file(Need to Find Pointers Manually)
- Support Fast Dumping(Might Miss some data)
- Support SDK Dumping for UE5 Based Android Games

## Note
- Only for Educational or Learning Purpose.
- Use 64bit Version on Respected Arch of Game.
- Recommend to use in Training Mode for PUBG Mobile.
- Some Games with Modified UE5 Might not Dump Correctly.
- For Modified Engines, You May Need Put Your Custom Offsets For That Game.
- If it stuck during Generating SDK, Then Simply Stop it, Check Dump file and If needed then Try again.
 
## How to use
- Needs Either Root Access or Virtual Space
- Put Executable in folder like /data/local/tmp (/sdcard not allow to execute binary so don't put it there)
- Get Either Root Shell through Adb or Terminal Apps(type and run: 'su') or Normal Shell into Virtual Space via Terminal Apps in that folder
- Give it executable permission with either 'chmod +x ue5dumper' or 'chmod 755 ue5dumper'
- Run './ue5dumper -h' For Usage Help
	```
    ./ue5dumper -h
    	 
    UE5Dumper v0.01
    Usage: ./ue5dumper <option(s)>
     Options:
    --SDK Dump With GObjectArray Args--------------------------------------------------------
      --sdku                              Dump SDK with GUObject
      --gname <address>                   GNames Pointer Address
      --guobj <address>                   GUObject Pointer Address
    --Other Args-----------------------------------------------------------------------------
      --package <packageName>             Package Name of App(Default: com.tencent.ig)
      --output <outputPath>               File Output path(Default: /sdcard)
      --help                              Display this information
    ```
	
## How to Build
- Clone this repo
- Install Android NDK, if not already.
- Open Shell/CMD in Project Folder
- Drag ndk-build from NDK in Shell or CMD and then Execute
- Output will be in libs Folder.

## End
The project is modified according to the large project of kp7742 [project line]([https://markdown.com.cn ](https://github.com/kp7742/UE4Dumper "Go To Github")
This project is jointly completed by JiangNight (Sixi) and Xiaohei
Project Credits: Xiao Hei


