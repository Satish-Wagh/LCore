#ifndef CHANGELOG_H
#define CHANGELOG_H
/*
1]  Fri Aug 16 16:16:44 IST 2013
        -Added defines.h & ChangeLog.h files.

2]  Wed Aug 21 12:01:35 IST 2013
        -CheckDataExist replaced by isTableExists function.

3] Sat Aug 31 16:43:09 IST 2013
        -Added new images

4] Wed Oct  9 17:08:49 IST 2013 v1.0.1
        - Added two new option in wfclient.ini file.
            "PSpeedScreenMMAVideoEnabled=On"
            "PSpeedScreenMMAAudioEnabled=Off"

5] Sat Oct 12 15:25:14 IST 2013 v1.0.2
        - Seperated UpdateConnectionTable and SendSignalToTC
        - Giving check for both functions.

6] Thu Oct 24 15:39:15 IST 2013
    -Changed LockScreen call to "LockScreen user"
    -Custom FileDialog window title changed to "Open"

7] Thu Oct 31 15:11:40 IST 2013 v1.0.3
    - Modify smb command for ARM board

8] Thu Oct 31 17:12:58 IST 2013 v1.0.4
    - Modify nfs command for ARM board

9] Thu Nov  7 16:44:06 IST 2013 v1.0.5
    - Modification in ModifyStartup()

10] Tue Nov 12 15:04:12 IST 2013
    - Added class threaddevices to get lpinfo
    -Added funtions getLpInfo() and getDeviceUri()

11] Tue Nov 12 13:28:43 IST 2013 v1.0.6
    -   Added LCore in svn.

12] Thu Nov 14 16:23:51 IST 2013
    - Added default TimeZone for startup : changed in setTimeZone() function

13] Tue Nov 19 12:08:16 IST 2013
    - Made command common for X86 and ARM in ExecuteNFSCommand() function

14] Tue Nov 19 12:08:16 IST 2013
    - Made command common for X86 and ARM in ExecuteSMBCommand() function

15] Tue Nov 19 12:01:23 CET 2013 v1.0.7
    - Solved bugs regarding DST and add functions

16] Tue Nov 26 12:15:34 IST 2013
    -Changes in writesmbconf function, parameter 'security' changed and parameter 'map to guest' added.

17] Wed Nov 27 13:19:29 IST 2013
    -Changes made in writeprintersconf for restricting Serial and parallel printers for Arm.
    -Added function removePrinter(QString).

18] Thu Jan  2 14:34:03 CET 2014
    - Made changes in writeX11vncOptions() function : for 'Query user', changed index

19] Fri Jan  3 14:35:44 IST 2014
    - Added saveTimezone(QString) function in LCore

20] Wed Apr  2 11:41:13 IST 2014
    - SMB/NFS : when remove host then also smb/nfs creates folder : Solved

21] Thu Apr  3 17:05:05 IST 2014
    - ScreenSaver stops after 3 blinks : Solved

22] Sat Nov  8 15:42:16 IST 2014
    - Added default 'Hub' entry in createDefaultModularUSBTable() fn for ModularUSB

23] Wed Apr 29 14:48:34 IST 2015 --Ritesh
    - Set Auto (DHCP Provided) as default setting for FDMSettings,changes in function setDefaultSettingsToVMS(),(set DHCPParams = '1')

24] Sat May 16 15:03:52 IST 2015 --Ritesh
    - Set Manual as as default setting for FDMSettings,changes in function setDefaultSettingsToVMS(), (set DHCPParams = '0')

25] Thu Jun 11 11:30:38 IST 2015 --Ritesh
    - Set Auto (DHCP Provided) as default setting for FDMSettings, changes in function setDefaultSettingsToVMS(),(set DHCPParams = '1')
26] Fri Jun 12 12:20:20 IST 2015 --Ritesh
    - If restore factory settings is apply from FDM server,then after restore FDMSettings UI shows server details, chnages in setDefaultSettingsToVMS().

27] Mon Jun 15 15:26:34 IST 2015 --Ritesh
    - Added SpecialCharacter ("1Æ1Æ1Æ") before group name, While saving DHCP value to FDMSSettings.
    - If Manual Network is applied from configuration wizard after restore, manual settings should be applied to FDMSetting instead of Atuo DHCP.

28] Thu Jul  9 17:01:29 IST 2015 --Ritesh
    - Change file path for FDMSettings file on arm board (/data/FDMSettings),after restore factory through VMS.

   -- start
29]Thu Apr 27 17:38:19 IST 2017 --Namrata
  -if /sda1/data/.defaultvalues contains VMViewGlobal value then we read file
       and update VMviewGlobal table.

30]Thu May  4 13:31:51 IST 2017 --Namrata
       -added condition to add ctrl+Alt+L shortcut for logout if osbuild not contains TCS.

31]Sat May 20 12:28:20 IST 2017 --Sujeet
        -Chnages in addDNSserver() for adding entry for DNSSuffix and added "#" before domain for file '/etc/resolve.conf'

32] version "1.0.8"
       -Sat May 20 12:20:07 IST 2017 --jignesh
       -change in CheckServerExist function for remove port from ip address like 0.0.0.0:00

33] version "1.0.9"
          -Sat May 20 13:13:08 IST 2017  -- Manish sir
          -blacklist of two module for cloub desktop for vesa driver (nvidinfb , fb_sys_fops)
          - Remove the default rule for iptable in executefirewallsettings for TCS

34] version "1.0.10"
          -Tue May 30 12:01:59 IST 2017  -- jignesh
          -Change in  CreateTempIniFile function for bydefault port 1494

35] version "1.0.11"
          -Wed May 31 18:50:51 IST 2017
          -Change in getIPFromServerHostName(QString strHostname) function for "nmblookup" command for find ip address from hostname

36] version "1.0.12"
          -- Fri Jun 16 19:09:29 IST 2017 -- Mayur
          -- changes done for set resolution in descending order

37] version "1.0.13"
        -- Fri Jun 30 14:50:50 IST 2017  -- Mayur
        -- changes in Create_wvdialConfFile() function for "T-Mobile"

38] version "1.0.14"
        -- Fri Jun 30 19:27:11 IST 2017 -- Siddharth
        -- Changes done for Import/Export Settings

39] version "1.0.15"    --Mayur
        -- Thu Jul 13 12:18:40 IST 2017
        -- changes for getting multiple VGACards
        -- new functin added "QStringList getVGAcardList()";
40] version "1.0.16"    --Jigneshkumar
        -- Wed Jul 26 19:10:48 IST 2017
        -- Change for EncryptDecrypt -> problem for french keyboard for special charcter, handel with use[system(cmd) file concept]
        -- Change in lcore.h for printer-usb -> solve for japnese and spanse lang
        -- File Touch (/root/.vmsrestore) on remove "FDMCLIENT_DETAILS" ---Sanil
        -- Call Function getIPFromServerHostName in writeX11vncOptions for reverse VNC -- Sanil & Khemraj

41]     Sat Aug 19 20:32:59 IST 2017   version "1.0.17" // Mayur
        -- changes for BalloonMessage geometry in other language & in ::setDateTime function passed tr to if condition

42] Mon Aug 21 17:25:13 AST 2017    version "1.0.18" //Namrata
  --load .qm in constructor for translations.

43] (1)Thu Aug 24 11:10:02 IST 2017   version "1.0.19" //Sanil
    -- write table "hostsettings" for host entry on factory restore in Function setDefaultSettingsToVMS.
    (2)Thu Aug 24 19:17:33 IST 2017
    --write host entry to FDMCLIENT_DETAILS .
    -- revert some changes .
44] -- version - "1.0.20"
    -- Date: Thu Sep  7 16:24:52 IST 2017
    -- change in encryption decryption
    -- add extra encryption called as RSA for special charcter
45] -- version - "1.0.21" //Sanil
    -- Thu Oct 12 11:52:04 IST 2017
    -- Add default values in clientsettings table when Fdmdetails file is blank or client settings table is empty.
46] Fri Oct 13 18:59:35 IST 2017  "v-1.0.22" by Mayur
    -- changes for Date-Time
47] -- version - "1.0.23" //Sanil
    (1) Sat Oct 14 12:02:30 IST 2017
    -- default values added in clientsettings table when client settings table is empty .
    (2) Mon Oct 16 12:29:33 IST 2017
    -- Solved issue of Fdmdetails file is blank.

48] Mon Oct 23 15:50:08 IST 2017  version  1.0.24
    -- changes in encryptdecrypt function for special charcter, use fromutf8 logic
    -- ica connction add clearpassword

49] Wed Nov  1 14:32:35 AST 2017 version 1.0.24
   --change executePNA script path
   old path - "/usr/lib/ICAClient/util/executePNA"
   currunt path -""/usr/os-bin/executePNA"

50] Fri Nov 10 19:13:51 IST 2017 version 1.0.26
        -- Minor change done in UploadFile Function in case of ftps protocol - Siddharth

51]  Tue Nov 14 15:44:46 IST 2017  VERSION "1.0.27"
    - Added "N3350" for Checking CPU Name

52] Fri Nov 17 13:39:24 IST 2017 Version "1.0.28"
    - Solved issue of sync when restore client -Sanil

53]  Thu Nov 30 20:01:06 IST 2017 Version "1.0.29"
    -- changes for pasing NTPViaDHCP ip when applying ntp date in setNTPDate() function

54] Sat Dec 16 17:51:52 IST 2017 Version "1.0.30"
  -- Changes in writeVMViewUDMFile function for saving previous VMVIEWFILEPATH file contents on VMGlobal apply button


55]  Thu Dec 14 13:24:20 IST 2017 Version "1.0.31"
    -- Changes done for GetCertificate Function for VMS -Sanil

56] Fri Dec 22 17:47:02 IST 2017  VERSION "1.0.32"
     - Changes For Dual monitor  Firefox lauch

57] Fri Dec 29 18:57:44 IST 2017 VERSION "1.0.33"
     - Added implimentation of fusionms -Sanil

58] Fri Jan  5 19:35:46 IST 2018 Version "1.0.34"
    - Changes for Host in FDMClient Details - "Sanil"

59] Sat Jan 6 10:53:01 IST 2018 Version "1.0.35" by Varsha
    - Changes for Date-Time 12hr & 24hr formart apply in Kios Mode

60] Sat Jan 20 14:33:50 IST 2018  Version "1.0.36" by Mayur
    -- added changes for showing default deny or Allow classes of Citrix in PNAUDM
    -- changes CTH condition ( now read from .defaultfile)

61]  Tue Jan 23 13:07:54 IST 2018 Version "1.0.37" by Saicharan
    -- added new function getEthernetConnectStatus() for checking wired interface is connected or not.
    -- changed if(file.size() && entries.count() > 1) to if(file.exists) in executeNetworkSettings()

62] Fri Feb  2 15:40:28 IST 2018  Version "1.0.38" by Saicharan
    -- changes done for changing Timeout value for network
    -- checked respective timeout value from sysconf in writeDHCPConf() function

63]   Fri Feb  2 19:09:24 IST 2018 Version "1.0.39" by Sujeet
    -- Added Entry of Share Removable Storage field in VMViewGlobal Table

64]   Wed Feb  7 13:33:23 IST 2018  Version "1.0.40" by Sujeet
     -- Changes in getDevice() function

65]   Thu Feb  8 15:05:36 IST 2018 Version "1.0.41" By Sanil
    -- Changes done in setDefaultSettings() Function for blank host Settings.

66]     Wed Feb 14 15:14:47 IST 2018 Version "1.0.42" by Sujeet
        -- Added 3 parameters in 20-Screen file for 67 board

67]   Fri Feb 16 11:44:26 IST 2018 VERSION "1.0.43" by Varsha
    -- changes for disabling shortcut if sleep is not avilable in Menu list- varsha

68] Fri Feb 16 15:14:12 IST 2018 VERSION "1.0.44" by Kunal
    --changes done in SetValidation() function for restrict Special Character in “HostName Field”.

69] Mon Feb 19 19:08:32 IST 2018 VERSION "1.0.45" by Siddharth
    -- Changes made for Cloud Desktop License [Remote Agent Settings] in setDefaultSettingsToVMS() & writeFDMDetailsFile() Functions

70] Wed Feb 21 19:48:13 IST 2018 VERSION "1.0.46" by Mayur
    -- Solved bug "OS_Desktop kill Issue".

71] Thu Mar  1 11:50:19 IST 2018 VERSION "1.0.47"
    -Changes related to Admin password and also sync with x11vnc,smb,ssh Password, beacuse of franch charcters
    -Changes related in Lcore, Authentiction, administraton(Services) "by jignesh"

72] Mon Mar  5 18:56:03 IST 2018 VERSION "1.0.48"
    -- commented if condition for vmview in on_offImprivataForVC() function
    -- added two function getHostNameFromDmidecode(), checkForLenovoValidBoards().

74]   Thu Mar  8 18:02:42 IST 2018 VERSION "1.0.49"
        -- changes done in executeNetwork() function for setting host name by dhcp
        -- if host name if set manually then when n/w applied that time host name is set by DHCP

75]   Tue Mar 13 17:38:17 IST 2018   VERSION "1.0.50"
       -- Called  pre & post network custom scripts function ExecuteNetworkSettings().
       -- Called setNTPDate() funtion only is Network is available
       -- added 3 new functions bool getWirelessInterfaceConnectedStatus(), bool getWiredInterfaceConnectedStatus(), QStringList getavailableIP();

76]   Thu Mar 15 19:23:59 IST 2018 VERSION "1.0.51" by sujeet
    --  If S3 is Unchecked its shortcut should not worked.

77] Fri Mar 16 14:54:07 IST 2018 VERSION "1.0.52" by sujeet
    -- If HDXOverUDP Checkbox is checked in PNAgentGlobal then, Update "/root/.ICAClient/wfclient.ini" file  HDXOverUDP=On otherwise HDXOverUDP=Off

78] Fri Mar 16 19:07:17 IST 2018 VERSION "1.0.53" by kishor
    --make changes in download file fun for http and https protocol for return code (add parameter -w).

79]   Tue Mar 20 21:03:52 IST 2018 VERSION "1.0.54" by Kunal
     --  In isM715qRR() function we added "10VL","10VM","10VN","10VQ" MT list for  M715q RR.

80]   Wed Mar 21 18:46:47 IST 2018 VERSION "1.0.55" by Kishor
     -- make changes in executeNetworkSettings function.
     -- Changes made for hostname show in TCName Setting.

81]    Wed Mar 28 20:03:10 IST 2018 VERSION "1.0.56" by Sujeet
    -- Changes related to ICA reconnect from ICA global. Bug-71

82]  Thu Mar 29 12:51:16 IST 2018 VERSION "1.0.56" by Kunal
    -- Changes related to NFS ,not showing "Error in mounting..please check creditionals" message.

83]  Wed Apr  4 15:44:20 IST 2018  VERSION "1.0.57" by Varsha
    -- Changes done as strProcOP1 was returing 204 and thus while exporting error msg was displayed.

84] --Start--above-915 Thu Apr  5 19:00:57 IST 2018 Version "1.1.0" by Kishor
    1]  Made changes for hostaname in ExecuteNetworkSetting fun for DHCP by Kishor
    --End--915

85] --start--above-917 Fri Apr 13 14:00:41 IST 2018 Version "1.1.1" by mayur
    1]changes for Slideshow, /usr/os-bin/xlock command will be used which is developed in qt.
      This xlock is developed bcox of issue of /usr/bin/xlock on amdgpu board.
      xlock goes on defunct mode on amdgpu board if we keep screensaver for longer duration.
    2] added checkFolderExits() function .
    --End--917

86] --start--above-917 Mon Apr 16 19:19:07 IST 2018 Version "1.1.2" by Varsha
    Changes done so that JetDirect and avialable port(/dev/sda/lp) synchronization
    --End--917

87] --start--above-918 Tue Apr 17 19:53:18 IST 2018 Version "1.1.3" by jignesh
    Changes done so that in ExecuteJetDirectSettings() function  crash when two usb port is jetdirect data base but only one is connected
    --End--918

88] --start--above-918 Sat Apr 21 19:11:52 IST 2018 Version "1.1.4" by jignesh for
    Changes done in ExecuteJetDirectSettings() function  for USB port. beacus after reboot if lp0, lp1 port not find than pass by default.
    or if USB1 with lp0 and USB2 with lp1 shuld pass.
    --End--918

89] --start--above-918 Fri Apr 27 13:36:43 IST 2018 Version "1.1.5" by Mayur
    Changes done for 715QRR board. we don't add TearFree, EnablePageFlip, AccelMethod, ShadowPrimary options in "/usr/share/X11/xorg.conf.d/20-screen.conf file.
    --End--918

90] --start--above-919 Wed May  2 17:41:09 AST 2018 Version "1.1.6" by Namrata
    1]did changes in LaunchPNAgentAppsOnDesktop() function to add only app name in desktopwidget table if pna child is kept on desktop.
    2]did changes in Launch2XClientAppsOnDesktop() function to add only app name in desktopwidget table if pna child is kept on desktop.
    3]did changes in updateDB() fuction to delete child entry from desktopwidget when machine down and pna connection not properly disconnected.
    --End--919

91] --Start--above-918 Tue Apr 24 13:01:16 IST 2018 VERSION "1.1.7"  --by jignesh
    1]  Add new functionality for PNAgent store browse connection, in PNAgentGloble Settings 'Show FloatingBar' check box. so related changes in
      function insertValues_PNAgent for 6th value in table PNAgentGlobal.
--END--918

92] --Start--above-918 Tue Apr 24 17:23:34 IST 2018 VERSION "1.1.7"  --by jignesh
    1]  Changes done for default value in PNAgentGlobal table for ShowFloatingBar=1 in function createDefaultModularUSBTable
--END--918

93] --start--above-919 Thu May  3 13:29:44 IST 2018 Version "1.1.8" by jignesh
    1]changes for auto connection startup, if delay is smaller than 10, than sleep=10 bydefault in /usr/share/icewm/startup
    --End--919

94] --start--above-919 Thu May  3 13:29:44 IST 2018 Version "1.1.8" by jignesh
    1] changes done for SMB and NFS:- if NFS,SMB Extra1 value is '0' than SMB,NFS shuld mount
    --End--919

95] --Start--above-919 Thu May 10 19:59:11 IST 2018 Version "1.1.9" by Sujeet
        Changes in Configure8021xSecuritySettings regarding wps_supplicant command.
        If wps_supplicant command is already running it will not restart wps_supplicant command.
    --End--919

96] --start--above-919 Tue Apr 24 13:06:18 IST 2018 Version "1.2.0" by Sujeet
    1] Added
    QString checkPassord(QString,QString) -> for checking BIOS password is correct or not .
    QStringList getBootSequenceList(QString) -> For getting Current Boot sequence .
    QString echoCommand(QString, QString) -> For passing INformation to BIOS files.
    bool checkPasswordState(QString) -> To check currently BIOS password is set or not.
    QString getBIOSSettingPath() -> For getting BIOS configurations files path.
    QString ChangeBIOSPassword(QString,QString,QString) -> For Setting new password
    QString ChangeBootSequence(QString,QString,QString,bool) -> For updating new boot sequence.
    void RestoreDefaultConf(QString) -> to Restore default BIOS settings.
    --End--919

97] --start--above-919 Thu May 10 13:29:55 IST 2018 "1.2.0" by Sujeet
        Changes in RestoreDefaultConf function .Restore factory will happen only if OS Optimized Defaults value is Disabled.
    --End--919

98]  --Start--above-919  Mon Apr 23 11:44:59 IST 2018 VERSION "1.2.1" --by Sujeet
    1]   Changed condition for TCS image.Refered TCS condition from Defaultvalues file as 'TCSEnabled=1'.
    2]   For TCS image ,passed 'vers=3.0' for smbmount.
--END--919

99] --Start--above-921 Thu May 17 15:11:27 IST 2018 VERSION "1.2.2" --by Jignesh
      Added new function for shortcut key 'sighupICEWM()' if icewm version is not 1.3.7 than sighup othervise killall OS_Desktop
   --END--921

100] --Start--above-921 Sat May 19 11:09:22 IST 2018  VERSION "1.2.3" --by Sujeet
      Added isLM625 and checkBoardTypeForBIOS function for checking 600 and 625 board.For showing BIOSConfiguration module.
   --END--921

101] --Start--above-922 Mon May 21 16:05:21 IST 2018 VERSION "1.2.4" --by Sujeet
        In BIOSConfiguration if current password is incorrect it will show message "Incorrect current password".
   --END--922

102] --Start--above-922  Mon May 21 18:47:51 AST 2018  VERSION "1.2.5" --by Namrata
       solved bug : If we set French(Switzerland) in configuration wizard then it work as German(Switzerland)
   --END--922

103] --Start--above-923  Tue May 22 23:10:35 IST 2018 VERSION "1.2.6" --by Kishor
    1]  Made changes for hostaname in ExecuteNetworkSetting fun for DHCP by Kishor
   --END--922

104] --Start--above-926 Mon May 28 20:14:55 IST 2018 VERSION "1.2.7" --by Kunal
    1] Changes for SecondaryDNS if manualentry for DNS Server checkbox is unchecked and  SecondaryDNS value is updated.
    2] changes for adding wireless logs in "var/log/wireless.log" instead of "/tmp/debug"
    --END--926

105] -Start--above-927 Thu May 31 16:05:19 IST 2018 VERSION "1.2.8" --by Varsha
    1] Changes done as while importing .pfx certificate it was giving "Please provide Valid Credentials" msg when user name and password is blank.
    --END--927

106] --Start--above-927 Thu Jun 7 12:01:34 IST 2018 VERSION "1.2.9" --by Siddharth
    1] Solved Bug "When Image is restored with 0.0.0.0 IP in Remote Agent Settings, then after restore Trail License is seen on Image" [Changes done in writeFDMDetailsFile()] - Siddharth
--END--927

107]  --Start--above-928  Tue Jun 12 14:25:35 IST 2018 VERSION "1.3.0"  --by Sujeet
            Done chnages , Kill icewm before killing OS_Desktop.
       --End--928

108] --start--above-929 Wed Jun 13 13:08:23 IST 2018 VERSION "1.3.1" --by Jignesh/kishor
    *] Marging from oracle branch to 38-Dev0-merged branch
    1] Get child list on start menu for rdweb connection
     --End--929

109] --start--above-929 Wed Jun 13 16:37:02 IST 2018 VERSION "1.3.2" --by Jignesh
    1] Change done in LCore::DownloadFill, remove .pfx condtion and add condtion for credatials (bug no OS-BUG-39-75)
    --End--929

110] --start--above-929 Wed Jun 13 17:24:36 IST 2018 VERSION "1.3.3" --by Mayur
    1] Modify the logic for getavailableIP()
     --End--929

111] --start--above-929 Thu Jun 14 19:51:52 IST 2018 VERSION "1.3.4" --by Mayur
    1] added executeNmap() function.
     --End--929

112] --Start--above-929 Sat Jun 16 13:05:21 IST 2018 Version "1.3.5" by Sujeet
        Changes regarding wifi .
    --End--929
113] --Start--above-930 Thu Jun 18 18:51:21 IST 2018 Version "1.3.6" by Namrata
        changes in modifystartMenu function to write implemenion for new option added to start menu.(connection ,aplication,Control center & connection Manager)
    --End--930

114] --Start--above-930 Mon Jun 18 20:00:06 IST 2018 Version "1.3.7" by khemraj
        delete fusionms entry in hostssettings table in ExecuteVMSSetting() function
    --End--930

114] --Start--above-930 Tue Jun 19 11:45:49 IST 2018 Version "1.3.8" by khemraj
        Write fusionms entry in hostssettings table in ExecuteVMSSetting() function
    --End--930

115] --start--above-931 Tue Jun 19 19:17:42 IST 2018 Version "1.3.9" by Sujeet
        Added function getWifiSignalStrength() to get wifi signal strength for auoconnect wifi when it comes within range .
    --End--931

116]--start--above-931  Wed Jun 20 20:07:15 IST 2018 Version "1.4.0" by Sujeet
        Done changes regarding 802SecurityNetwork .
    --End--931

117]  --Start--above-932 Thu Jun 21 15:56:53 IST 2018 VERSION "1.4.1" --by Jignesh
    1] Changes done :- reduse default sleep time 10 to 5 in auto start connection
--END--932

118] --Start--above-932 Thu Jun 21 16:52:46 IST 2018 Version "1.4.2" by khemraj
        chenges in  ExecuteVMSSetting() function ( delete entry of fusionms from /etc/hosts)
    --End--932

119] --Start--above-932 Thu Jun 21 19:36:23 IST 2018 VERSION "1.4.3" by Siddharth
          1] Added function in LCore::isEfiImage() to check wheather Image is Efi or not - Siddharth
     --END--932
120] --Start--above-934 Mon Jun 25 18:56:23 IST 2018 VERSION "1.4.4" by Namrata
          solved bug releted to sleep in start menu is showing for some time after hard boot and shutdown if it is disable from userinterface.
     --END--934

121] --Start--above-934 Mon Jun 25 18:56:23 IST 2018 VERSION "1.4.5" by Kishor
         1] solved bug 'DHCP hostname not getting priority after restore image.
     --END--934

122] --Start--above-934 Wed Jun 27 19:09:47 IST 2018 VERSION "1.4.6" by Kunal
        1]  solved bug releted to After normal reboot/shutdown ,Wi-Fi log entry gets vanish.
     --END--934

123] --Start--above-934 Wed Jun 27 19:37:52 IST 2018 VERSION "1.4.7" by Mayur
        1] check for NetworkInterface is added in executeNetworksettings because after applying network link is not up for sometime even it connected.
        2] getAvailableIP() function is called in QFutureWatcher because it HANGS image because of QNetworkInterface
     --END--934

124] --Start--above-934 Thu Jun 28 10:41:12 IST 2018 VERSION "1.4.8" by Mayur
        1] Changes in setGateways() function we check if condition as "Wireless" but it should check for "Ethernet"
     --END--934

125] --Start--above-941 Thu Jul  5 20:22:40 IST 2018 VERSION "1.4.9" by Mayur
        1] Time-Zone is not read from any site (freegioip.net ) because it is blocked.
     --END--941

126]  --Start--above-934 Thu Jul 5 22:19:54 IST 2018 "1.5.0" by Siddharth
        1] Changes done in ExecuteNetworkSettings() for Serial Number - Siddharth
      --END--941

127]  --Start--above-943 Mon Jul  9 19:55:18 IST 2018  "1.5.1" by Sujeet
       Done changes regarding bios configuration password check.
      --END--943

127]  --Start--above-943 Mon Jul  9 20:03:41 IST 2018 "1.5.2" by Mayur
        1] Changes in setGateways() function revert changes check if condition as "Wireless".
        2] In same function else part done same thing like Ethernet to route gateway (Wired to Wireless switching ) .
      --END--943
128]  --Start--above-945 Tue Jul  10 15:20:41 IST 2018 "1.5.3" by Namrata
        1] "In Desktop mode if we uncheck connection option from start menu from user interface & in Rdweb connection
            if we check connection on start menu, connection on desktop, connection on boot up options then RDWeb
            connection listed in Start menu."
      --END--945

129]    --Start--above-945 Thu Jul 12 17:06:00 IST 2018 "1.5.4" by kunal
      1] changes done to remove "=" from if condition(readlist[2].length() >"=" 0) because when we log in as any user,
         Lockscreen window was always appearing.
      --END--945
130]    --Start--above-946 Thu Jul 12 20:06:00 IST 2018 "1.5.5" by Namrata
      1] did changes in checknetworkip() to solve issue when we launch browser it stuck for some time.
      --END--946

131]    --Start--above-946 Thu Jul 12 20:06:00 IST 2018 "1.5.6" by Mayur
      1] made changes to return way of getavailableIP() function.
      --END--946

132] Start--above-947 Thu Jul 19 15:49:35 IST 2018 VERSION "1.5.7" by Sujeet
            Done changes regarding CheckServerExits function.
            Added parameter bgscan=simple:10:-60:30 in wpasupplicant.ini file.
      --END--947

133] -Start--above-950 Tue Jul 24 12:21:17 IST 2018 VERSION "1.5.8" by Jigneshkumar
        1) LCore (DisplayErrorMessageBox): Error messages for all connection are proper and in center of display.
           related changes in LaunchCommand, VOSSelfServices
      --END--950

134] -Start--above-952 Wed Jul 25 14:38:11 IST 2018 VERSION "1.5.9" by namrata
        1) Resolve issue :- Repository manager option displays in start menu
      --END--952

134] -Start--above-954 Tue Jul 31 11:18:17 IST 2018 VERSION "1.6.0" by Varsha
        When we Disable Reconnect option from ICA global, then reconnect will not performed.
      --END--954

135] -Start--above-954 Tue Jul 31 13:36:13 IST 2018 VERSION "1.6.1" by Siddharth
    - Added #define for /tmp/application.log file
    - Added Function processApplicationLogFile() & getNumberofLinesFromFile() for /tmp/application.log file

136] --Start--above-954 Wed Aug  1 11:45:20 IST 2018 VERSION "1.6.2" --by Varsha
     New Implementation of FreeRDP("Display Apps on Desktop" and "SSO")
    --END--954

137]  --Start--above-955 Sat Aug 18 17:04:28 IST 2018 VERSION "1.6.3" --by Kishor
        1. Added Debugs
    --END--955

138]--Start--above-955 Thu Aug 23 15:57:23 IST 2018VERSION "1.6.4" --by Mayur
    1] Changes for settings current host name to "hostname" command and write in "/etc/resolve.conf" file where HostName is added in sysconf and checked HostName is set by DHCP.
    --END--955

139] -Start--above-955 Thu Aug 23 15:57:23 IST 2018VERSION "1.6.5" by kunal
        1] Changes done in Screensaver() Function for slideshow ,removed "path" parameter from command.
      --END--955
140] -Start--above-968 Tue Nov  6 18:41:15 IST 2018 VERSION "1.6.6" by kunal
        1]Changes done in getDevice() Function for flash size not seen in SystemInfo on NVME Board.
      --END--968

141] -Start--above-968 Fri Nov 16 19:57:17 IST 2018 VERSION "1.6.7" by Mayur [Merger from       -Start--above-954m-0 Tue Sep  4 16:18:01 IST 2018 VERSION "1.6.0" by Mayur]
        1) Changes done in writeShortcutKeyFile() function to disable ScreenCapture shortcut functionality in session if disabled in TC.
      --END--968

142] -Start--above-968 Fri Nov 16 21:27:58 IST 2018  VERSION "1.6.8" by Mayur [-Start--above-954i  Fri Aug 24 19:18:42 IST 2018 VERSION "1.6.0" by kunal]
        1) changes for Airtel-4G
      --END--968

143]--Start--above-968 Mon Nov 19 19:52:12 IST 2018 VERSION "1.6.9" --by Mayur [Merged from  --Start--above-954k-0 Thu Aug 23 17:24:06 IST 2018 VERSION "1.6.0" --by Jignesh]
        1] Changes for issue related Trial License, file '/tmp/.dmesg' write in startup 3
        2] Done changes regarding mouse focus on screensaver slideshow.(Merged from 966-BJC)
   --END--968

144]  -Start--above-968 Tue Nov 20 18:55:55 IST 2018 VERSION "1.7.0" by Mayur [Merged from -Start--above-954g Wed Aug 22 14:28:57 IST 2018 VERSION "1.6.2" by Sujeet]
            Done changes in Screensaver function, as new checkbox is added in ScreenSaver module
            if that is checked then ScreenSaver lock will be shown.
      --END--968

145] --Start--above-968 Wed Nov 21 18:04:03 IST 2018 VERSION "1.7.1" --by Mayur[ Merged From --Start--above-954b-2 Fri Aug 10 19:04:34 IST 2018 VERSION "1.6.1" --by Mayur]
    1] Changes for settings current host name to "hostname" command and write in "/etc/resolve.conf" file where HostName is added in sysconf and checked HostName is set by DHCP.
        --END--954b-2

    2]    --Start--above-954b-11 Tue Sep 11 18:47:09 IST 2018 VERSION "1.6.3" by Sujeet
                Done changes regarding wifi bgscan parameter , if in sysconf table WifiThresold values are present then
                it will take values from that for bgscan otherwise it will take 1:-40:5.
          --END--954b-11

    3]   --Start--above-954n-41(above 958) Sat Sep 15 15:04:52 IST 2018 VERSION "1.6.4" by Sujeet
                Done changes in screensaver function merged from mashreq branch.
          --END--954n-41(above 958)

    4]   --Start--above-954n-2 above-958 Tue Sep 18 15:06:41 IST 2018 VERSION "1.6.6" --by Mayur
                1) added getActiveWindowId(), getWindowClass(QString), sendClickSignal() functions.
                2) passed timeout for download tar through ftp or ftps protocol.
            --End-954n-2 above-958

    5] --Start--above-954n-4 (--above-960) Wed Sep 19 18:16:17 IST 2018 Version "1.6.7" by Sujeet
                Solved bug : Desktops / Apllications list of Citrix server is displayed with name on Desktop
                            (through Display Apps on Desktop functionality), but it is still displayed with Server name in Start Menu. (e.g. - xen:Agent1)
                Done changes in LaunchPNAgentAppsOnMenu function.
        --End-above-954n-4 (--above-960)
    --END--968

146] --Start--above-968  Thu Dec  6 12:35:54 IST 2018 VERSION "1.7.2" by Kunal
     --Changes for For ControlCenter and Connectionmanager different message is displayed when invoked through start menu/shortcut key.
       Changes done in writeShortcutKeyFile() Function.
     --END--968

147] --Start--above-968 Thu Dec 20 21:57:14 IST 2018 VERSION "1.7.3" by Mayur [ Merged from --Start--above-968n-0 Tue Dec 11 11:55:11 IST 2018 VERSION "1.6.9" by kunal]
            1]Changes done in getDevice() Function for flash size not seen in SystemInfo on NVME Board.
              --END--968n-0
         --Start--above-966n-0 Tue Dec 11 12:59:50 IST 2018 VERSION "1.7.0" --by Mayur [ Merged from ---Start--above-966b-4 Mon Dec 03 18:40:45 IST 2018 VERSION "1.6.9" --by Siddharth]
            1) Solved bug "WiFi connection failed if AP password is removed." (for DHCP, Database Values done Blank, which will Update is leases file is available, Changes done in ExecuteNetworkSettings())
         --End-above-966n-0
    --End-above-968

148]--Start--above-968 Fri Dec 21 12:03:13 IST 2018 VERSION "1.7.4"  --by Mayur [Merged from 966f-LauzonLtd --Start--above-966f-1  Fri Oct 26 11:29:52 IST 2018 VERSION "1.7.0"  --by Kunal
           --Changes done in ExecuteKeyboardSettings() Function for Euro Characters in French language.
        --End-968

149] --Start--above-968 Fri Dec 21 15:58:47 IST 2018 VERSION "1.7.5"  --by Mayur [Merged from 966j-Atlanitc_Technology ]
         --Start--above-966j-0  Fri Nov 23 18:48:51 IST 2018 VERSION "1.6.9"  --by kunal
              --New Implementation for DHCP Server Information in Show Info and System Information add "DHCP-SERVER-IDENTIFIER" intry into ExecuteNetworkSettings() Function.
        --End-966j-0
   --End-968

150] --Start--above-968 Fri Dec 21 16:59:15 IST 2018 VERSION "1.7.6" -- By Mayur [ Merged from 966l-SCEP ]
         --Start--above-966l-0 Fri Nov 30 19:04:17 IST 2018 VERSION "1.6.9" -- By Siddharth
            1] Added New Functions executeIPsecEnrollment(), getCertificateRequestEnrollmentStatus() for SCEP Manager Module
         --END-above-966l-0
     --END-above-968

151]   --Start--above-968 Fri Dec 21 18:11:11 IST 2018 VERSION "1.7.7" by Mayur [ Mearged from 966m-MillenniumBank ]
           --Start--above-966m  Mon Dec 17 17:15:35 IST 2018 VERSION "1.6.9" by Sujeet
                Done changes related to output of wpa_suplicant command will be redirected into /opt/debug file instead of /tmp/debug file.
                and backup of /opt/debug file get in /var/log/wpa_suplicant directory.
          --END--966m
      --END--968

152]--Start--above-968 Fri Dec 21 19:48:39 IST 2018 VERSION "1.7.8"  --by Mayur [ Mearged from 966d-IBERDOROLA ]
        143] --Start--above-961  Mon Sep 24 11:32:06 IST 2018 VERSION "1.6.8"  --by Mayur,Sujeet
                Remove changes done regarding Showing Screen Locked window in imprivata.
            --End-961
        144]--Start--above-966d-0 Fri Oct 12 18:03:58 IST 2018 VERSION "1.6.9"  --by Mayur
                Passed default icon path while including values in DesktopWidget from PNAgent connection if icon is not available from serverside.
            --End-966d-0
        145] --Start--above-966d-3 Thu Dec 13 15:07:28 IST 2018 VERSION "1.7.0" -- By Mayur [Merged from --Start--above-966l-0 Fri Nov 30 19:04:17 IST 2018 VERSION "1.6.9" -- By Siddharth
                1] Added New Functions executeIPsecEnrollment(), getCertificateRequestEnrollmentStatus() for SCEP Manager Module
             --END-above-966d-3
     --END-above-968

153] Start--above-968 Mon Dec 24 13:17:50 IST 2018 VERSION  "1.7.9" by Mayur [Mearged from 966k-MultiArch64 ]
    144]Start--above-966k Sat Dec  1 16:07:47 IST 2018  VERSION  "1.6.9" by Namrata
              1)execute ntpd command for datetime
          --END--966k
    145] --Start--above-966k-MultiArch-6 Sat Dec  1 18:49:26 IST 2018 VERSION "1.7.0" by Kunal
         --Changes for removed "/tmp/.reconnect" and "tmp/.kioskreconnect"  on cancel button of local Credential window.
         --END--966k-MultiArch-6
    146]  --Start--above-966k-MultiArch-7 Mon Dec  3 15:06:14 IST 2018 VERSION "1.7.1" by Kunal
         --Changes for For ControlCenter and Connectionmanager different message is displayed when invoked through start menu/shortcut key.
           Changes done in writeShortcutKeyFile() Function.
         --END--966k-MultiArch-7
    147] --Start--above-966-MultiArch-8 Fri Dec  7 15:33:32 IST 2018 VERSION "1.7.2" by Varsha
         -- Condition added because if we edit printer and check "map in RDP" option than in this case it was not getting mapped.
         --END--966-MultiArch-8
    148] -Start--above-966-MultiArch-10 Sat Dec 15 10:12:59 IST 2018 VERSION "1.7.3" by kunal
            1]Changes done in getDevice() Function for flash size not seen in SystemInfo on NVME Board.
          --END--966-MultiArch-10
  --END--968

154]--Start--above-968 Wed Dec 26 11:59:33 IST 2018 VERSION  "1.8.0" by Mayur [ Mearged from 966c-LA_PublicLIbrary ]
        144]--Start--above-966c Tue Oct  9 18:36:43 IST 2018  VERSION  "1.6.9" by Namrata
                  1) write function "getConnectionEdingTime(QString ConnectionName, QString ConnectionType)" to get connection ending reconnect delay time.
            --END--966c
        145]--Start--above-966c-1 Tue Oct 16 20:45:10 IST 2018 VERSION  "1.7.0" by Kunal
                --Changes done for Telnet ,Spice in getConnectionEdingTime() Function.
            --END--966c-1
        146]--Start--above-966c-4 Fri Oct 26 19:16:40 IST 2018 VERSION "1.7.1"  --by Mayur
                    1] Passed default icon path while including values in DesktopWidget from PNAgent connection if icon is not available from serverside. (Mearged from 966d [ IBERDOROLA]).
                    2] Added Server Socket for refresh TCCenter ui instade of (sendsignaltoTCCenter()).
            --End-966c-4
        147]--Start--above-966c-5 Wed Oct 31 17:31:39 IST 2018 VERSION "1.7.2"  --by Mayur
                    1] Changes done in Function setReconnetingInTCCenter() ,sendMessageToTCCenter() for sending Singnal to TCCenter and OS_Desktop. and also for QlocalServer - Socket not work proper.
            --End-966c-5
        148]--Start--above-966c-7 Fri Nov  2 18:44:39 IST 2018 VERSION "1.7.3"  --by Mayur
                1) Used QFutureWatcher for calling sendReconnectingSignal().
            --End-966c-7
        149] --Start--above-966c-8 Sat Nov  3 18:47:52 IST 2018 VERSION  "1.7.4" by Sujeet
                1] Added new function CheckLockScreenRunning() for checking LocKscreen is active or not
                  , if LockScreen is active then after login from lockscreen reconnect will start (for SearchDialog window).
            --END--966c-8
        150] --Start--above-966c-10 Sat Nov 17 12:21:24 IST 2018 VERSION  "1.7.5" by Kunal
                 --Removing "/tmp/.kioskreconnect" and "/tmp/.reconnect" file on Cancel button of Localcredentialdialog  to show tccenter.
             --END--966c-10
     --END--968

155] --Start--above-968 Wed Dec 26 16:11:19 IST 2018 VERSION "1.8.1" --by Mayur [ Mearged from 966g-L480 ]
        145] --Start--above-966g-1  Thu Nov 22 20:59:17 IST 2018 VERSION "1.7.0" --by kunal
              Changes done add new isL480() function for L480.
            --END--above-966g-1
     --END--above-968

156] --start--above-968 Wed Dec 26 19:16:47 IST 2018 Version "1.8.2" by Mayur [ Mearged from 913d-Valeo ]
        86] --start--above-913d-3 Tue Nov 27 16:06:51 IST 2018 Version "1.1.2" by Mayur
                1] Changes added for touchscreen calibration after Display rotate.
                2] Added common funtion for get touch screen id.
            --End--913d-3
        87] --start--above-913d-4 Thu Nov 29 14:17:08 IST 2018 Version "1.1.3" by Mayur
                1] Commented code for finding time zone, because freegeoip webside is closed.
                    and thats why curl command is getting stuck.
            --End--913d-4
        88]    --start--above-913d-4 Sat Dec  1 12:33:14 IST 2018  Version "1.0.2" by Namrata
                1]check for "/root/.tmpTouch" in ExecuteKeboardSetting()  file coz if user only check detect device then after x kill
                  keyboard left key fails to work properly.
            --End--913d-4
     --End--968
157]  --Start--above-969 Fri Dec 28 18:40:44 IST 2018T 2018 Version "1.8.3" by namrata
           1. write function to solved bug : After importing tar it shows wrong hostname in TC name settings call function from Lcore
    --End--969

158]--Start--above-969  Fri Dec 28 19:42:24 IST 2018 VERSION  "1.8.4" by Kunal
      --new Implementation for Touchscreen in ExcludeDeviceInVMVIEW()  add viewusb.ExcludeVidPid entry in /etc/vmware/config when we get vmview connection session.
    --END--969


159] -Start--above-969  Fri Dec 28 19:42:24 IST 2018 VERSION "1.8.5" by kunal
        1] Changes done for Custom script operation Fails to work on pre-networking and post-networking.
      --END--above-969

160] --Start--above-969 MultiArch Mon Dec 31 11:23:17 IST 2018 VERSION "1.8.6"  --by Varsha
    FQDN fails to work while searching application in Store Browse connection
     --END--969 MultiArch

160] -Start--above-969 Mon Dec 31 14:32:39 IST 2018  VERSION "1.8.7"  --by Jignesh
         Changes for Node not showing in GUI
        --End-969

161] -Start--above-970 Thu Jan  3 14:23:02 +0530 2019 VERSION "1.8.8"  --by Mayur
         1) Changes done for exclude touchscreen in sessions.
        --End-970

162] --Start--above-970MultiArch Thu Jan  3 14:31:11 IST 2019 VERSION "1.8.9"  --by Varsha
    FQDN fails to work while searching application in Store Browse connection
    Effective Code: LCore
     --END--970MultiArch

162] --Start--above-972 MultiArch Mon Jan  7 19:03:02 IST 2019 VERSION "1.9.0"  --by Namrata
     in Createlanguagelink function cp start button image acoording to selected language,
     solved bug : Desktop Mode-Start Button fails to display in language set in system settings tar
     --END--972_MultiArch

163] --Start--above-971 Wed Jan 9 15:46:17 IST 2019 VERSION "1.9.1"  --by Manikanta.
     1] Changes done in ExecuteVMSSettings() for VMSSettings new implementation, Auto & Manual functionality - Manikanta.
     2] Added new updateVmsLogsFile() for VmsLogs update - Khemraj.
     Impact Area : VMSClient, RemoteAgentSettings Modules.
     --END--971

164] --Start--above-973 Sat Jan 19 15:37:52 IST 2019 VERSION "1.9.2"  --by khemraj
     1] Changes done in ExecuteVMSSettings() for VMSSettings new implementation, Auto & Manual functionality.
     2] update VmsLogsFile after get IP from fusion, DHCP or Mannual.
     3] chnages writeFDMDetailsFile for new implementation, Auto & Manual functionality.
     Impact Area : VMSClient, RemoteAgentSettings Modules.
     --END--973

165] --Start--above-973  Wed Jan 23 18:06:00 IST 2019 VERSION "1.9.3"  --by kunal.
        --changes done In pnagent store browse/self service connection sound is not working for any video.
     --END--973

166] --Start--above-973  Wed Jan 23 18:06:00 IST 2019 VERSION "1.9.3"  --by kunal.
        --changes done in processApplicationLogFile() function changes defination for applicationlog file.
     --END--973

167]  --start--above-974 Fri Jan 25 16:43:09 IST 2019 Version "1.9.4" by Mayur
    89]  --start--above-913d-9 Sat Dec 29 20:07:38 IST 2018 Version "1.0.3" by Mayur/khemraj
        1) Added new function excludeVIDPID() for Touchscreen
         --End--913d-9
        2) Removed priviously unwanted functions related to touchscreen.
     --End--974

168]  --Start--above-974 Fri Jan 25 19:35:25 IST 2019 VERSION  "1.9.5" by Mayur
        144]Start--above-966t-1 Wed Jan 16 12:16:54 IST 2019 VERSION  "1.6.9" by Namrata
                  1) In setgetway function  did changes to solved networkswiching issue called ifmetric binary to switch network priority.
                  2)ifmetric is taken from standardubuntu machin.
              --END--966t-1
        145]Start--above-966t-2 Sat Jan 19 17:30:43 IST 2019  VERSION  "1.7.0" by Namrata
                  1)solved issue : If Wi-Fi and wired is configure and system goes into sleep .then after system gets up if we connect
                  connection and remove network cable then it fail to switch to Wi-Fi and connection gets disconnected
                  Solution : when wifi get properly configured then only ifmtric command get performed.
             --END--966t-2
     --END--974

169]  --Start--above-974 Mon Jan 28 19:26:52 IST 2019 VERSION "1.9.6" by Mayur
        146]  --Start--above-966g-4 Mon Dec 24 14:27:27 IST 2018 VERSION "1.7.1" by Sujeet
                        Added new function checkL480Laptop() , for checking laptop is L480 or not.
                        Used this function for Wifi configuration , IS laptop is L480 then for
                        wifi wpa_supplicant command "nl80211" this driver will be passed
                        otherwise "wext" driver will be passed through command.
              --END--966g-4
      --END--974

170]  --Start--above-979 Tue Feb  5 15:13:53 IST 2019  Version  "1.9.7" by Sujeet
            Added new entry in VMViewGlobal table in "Extra3" position for "Enable FIPS" option
       --END--979

171]  --Start--above-985 Wed Feb 13 17:20:56 IST 2019  Version  "1.9.8" by khemraj
      1] Very First Time , Server IP by default must be of TCS Server (10.249.235.144) and hear beat interval as 300 Sec. for TCS
      Impact Area : VMSClientSettings(VMSClient).
       --END--985

172]  --Start--above-985 Wed Feb 13 20:28:19 IST 2019 Version  "1.9.9" by Kunal (Mayur)
            1) Added default hostname read from database because when manual network is applied that time blank entry of host name is set in /etc/hosts.
       --END--985

173]  --Start--above-990 Tue Mar  5 14:31:19 IST 2019 Version  "2.0.0" by Jignesh
            1) bug resolved :- 0004427: In X11vnc service if we set Query Mode and perform Normal/Quick Reboot/Shutdown then Notification fails to display in Hot plugs
       --END--990

174]  --Start--above-988 Thu Feb 28 12:26:20 IST 2019 Version  "2.0.0" by Mayur
        136] -Start--above-954d-14 Thu Nov  1 14:12:15 IST 2018 VERSION "1.6.2" by Sujeet
                  Check defaultvalues for vrtule channel, if DisableVC=1 than VC not work in imrovata session in function 'on_offImprivataForVC'
              --END--954d-14
      --END--988

175] --Start--above-990 Tue Mar  5 13:17:28 IST 2019 VERSION "2.0.1" -- By Mayur
        146] --Start--above-966d-5 Fri Jan 18 14:03:41 IST 2019 VERSION "1.7.1" -- By Siddharth
                1] Minor Changes done in getCertificateRequestEnrollmentStatus() for Scep Manager Module
             --END-above-966d-5
        147] --Start--above-966d-7 Fri Feb 15 13:18:52 IST 2019 VERSION "1.7.2" -- By khemraj
                1] Added Alt+Ctrl+Del in writeShortcutkeysFile function
             --END-above-966d-7
        148] --Start--above-966d-8 Fri Feb 15 17:57:35 IST 2019 VERSION "1.7.3" -- By khemraj
                1] Added Ctrl+Alt+Del in writeShortcutkeysFile function
             --END-above-966d-8
        147] --Start--above-966d-9 Fri Mar  1 11:45:20 IST 2019 VERSION "1.7.4" -- By Jignesh
                1] Added Ctrl+Alt+Del And Ctrl+Alt+KP_Delete in writeShortcutkeysFile function for Block key combination.
             --END-above-966d-9
     --END-above-990

176]--Start--above-989 Thu Mar  7 22:37:47 IST 2019 VERSION "2.0.2"  --by Mayur
        144]--Start--above-966q-1 Sat Jan  5 10:15:25 IST 2019   VERSION "1.6.9"  --by Namrata
                did changes in 20-screen.conf i.e if driver = modesettings then not to write other option told by prashant sir.
            --End-966q-1
    --End-989

177]--Start--above-989 Thu Mar  7 23:16:53 IST 2019 VERSION "2.0.3"  --by Mayur
        140] --Start--above-954g-7 Thu Mar  7 15:06:47 IST 2019 VERSION "1.6.6" --by Mayur
                2) Modifide condition in above function for TCS to disable PrintScreen.
                3) Added disableKeyCode(QString) function.
            --END--954g-7
        140] --Start--above-954g-7 Thu Mar  7 17:06:47 IST 2019 VERSION "1.6.7" --by Mayur
                1) Called  disableKeyCode() function  writeShortcutKeyFile(), executeKeyboardSettings() function for diablePrintScreen.
            --END--954g-7
    --END--989

178]  --Start--above-989 Thu Mar  7 21:04:31 IST 2019 Version  "2.0.4" by khemraj
            1) if Remote Agent Setting serverip is 0.0.0.0 then it return from getcertificate function.
      Impact Area : VMSClient.
       --END--989

179]  --Start--above-990 Fri Mar  8 17:49:30 IST 2019 Version  "2.0.4" by Mayur
            1) Changes done in ExecuteTouchScreenAfterDisplaySettings() function as This is done because touchscreen Advance settings not work after reboot/shutdown
               and since we don't had any solution so returns after advance touchscreen settings.
            2) Added DownloadFile(QString), getWindowId(QString), acticateWindow(QString) functions.
       --END--990

180]  --Start--above-990 Fri Mar  8 18:30:46 IST 2019 Version  "2.0.5" by Jignesh
            1) RDWeb child not connected in Imprivata Connection, changes done in on_offImprivataForVC.
       --END--990

181]  --Start--above-990 Fri Mar 8 23:16:37 IST 2019 Version  "2.0.6" by Manikanta.
            1) (LTM)If we try to switch TC between 2 fusionms servers, after Normal/Quick Reboot/ShutDown TC was unable to switch.
       --END--990

182]  --Start--above-991 Sat Mar 16 16:20:46 IST 2019 Version  "2.0.7" by Manikanta.
            1) Solved Bug "0004360: Devices fails to auto-register with LTM after image flashing and restore, when DHCP Scope and Fusionms is configured in network".
               Impact Area : VMSClient (Fusionms).
            2) Minor changes done for DHCP HeartBeat value '60'.
               Impact Area : VMSClient (DHCP).
       --END--991

183]  --Start--above-992 Mon Mar 18 17:51:45 IST 2019 Version  "2.0.8" by Prajakta.
            1) Added PCOIPCLient Icon PCOIPClient.png Name in ModifyDesktop(), ModifyStartup() and ModifyStartMenu()
            2) Added path in defineslcore.h as PCOIPCLIENT_LIST_DIR
       --END--992

184]  --Start--above-992 Tue Mar 19 18:58:40 IST 2019 "2.0.9" by khemraj/nikhil sir.
            1] Display's 2 IP's shows in ShowInfo , DHCP IP was not getting applied into "ifconfig".
       --END--992

185]  --Start--above-992 Wed Mar 20 16:31:40 IST 2019 "2.1.0" by namrata/jignesh.
            1] 0003987: After 2nd Boot Network Speed default display which is 1000 Mb/s Full duplex.
       --END--992

186]  --Start--above-992 Fri Mar 22 17:08:58 IST 2019 "2.1.1" by Manikanta.
            1] Solved Bug "0004622: TC Fails to auto register with Fusionms when LTM Server configured with HTTP protocol is mapped in CName in Fusionms".
               Impact Area :- VMSClient (Fusionms HTTP).
       --END--992

187]  --Start--above-993 Mon Mar 25 19:35:55 IST 2019 "2.1.2" by khemraj.
            1] revert changes "0004622: TC Fails to auto register with Fusionms when LTM Server configured with HTTP protocol is mapped in CName in Fusionms".
               Impact Area :- VMSClient (Fusionms HTTP).
       --END--992
188]  --Start--above-994  Version Wed Mar 27 13:21:35 IST 2019 "2.1.3" by Namrata.
            1) solve bug : Ethernet to wireless switching fails to work with IQL and TC 68. -
               did changes in this function "getNetworkDeviceLinkStatus()"
       --END--994

189]  --Start--above-994 Version Sat Mar 30 19:21:57 IST 2019 "2.1.4" by Bhushan.
            1] "0004622: TC Fails to auto register with Fusionms when LTM Server configured with HTTP protocol is mapped in CName in Fusionms" - Khemraj.
               Impact Area :- VMSClient (Fusionms HTTP).
       --END--994

190]  --Start--above-999 Version Thu Apr  4 19:43:10 IST 2019 "2.1.5" by khemraj
            1] 0004815: If TC already registered in fusionms& in this case if we change fusionms server& perform restore,remote status shows “unmanaged”
       --END--999

191]  --Start--above-999 Version Thu Apr 5 19:43:10 IST 2019 "2.1.6" by Manikanta.
            1] Changes Reverted for Bug"0004815: If TC already registered in fusionms& in this case if we change fusionms server& perform restore,remote status shows “unmanaged”".
                Impact Area :- VMSClient (Fusionms).
       --END--999

192] -Start--above-1002 Tue Apr 16 11:23:12 IST 2019 VERSION "3.0.7" by Prajakta
        1) Changes Done in Localcredentialdialog to display Icon, Title, Logo, and Credentials on the basis of Default values of perticular fields.
     --END--1002

193] -Start--above-1003 Thu Apr 18 03:26:07 EDT 2019 VERSION "3.0.8" by khemraj
        1] Solved bug "0004815: If TC already registered in fusionms& in this case if we change fusionms server& perform restore,remote status shows “unmanaged”
        2] Solved bug "0004943: After reboot/shutdown ,remote agent swithes to "Fusionms"
        Impact Area :- VMSClient (Fusionms).
     --END--1003

194] -Start--above-1003 Thu Apr 18 15:13:02 IST 2019 VERSION "3.0.9" by Manikanta.
        1) If Server is in workgroup and if you register from server in this case VMSSigHandler gets kill - Khemraj.
            Impact Area :- VMSClient.
     --END--1003

195]  -Start--above-1003x32-0.0.2  Fri Apr 19 18:33:19 IST 2019  VERSION "4.0.0" by Kunal.
       Changes done
          -- Add New Implementation for  AT&T And Verizon Providers in Datacard in Create_wvdialConfFile().
       --END--1003x32-0.0.2

196] -Start--above-1003x32-0.0.3  Fri Apr 26 19:49:22 IST 2019 VERSION "4.0.1" by Kunal.
       Changes done
          -- Add New getCert9Key4DB() Function for cert9.db and key4.db for firefox
       --END--1003x32-0.0.3

 197]-Start--above-1001x64-0.0.6 Mon May  6 15:13:01 IST 2019 Version "4.0.2" by Mayur
     193]-Start--above-1001f-1 [Thinprint]  Fri Apr 26 10:30:53 IST 2019 Version "3.0.6" by Namrata
         -- did changes in start custom services if thinprintEnable is check then start "Thinprint" servive
        --END--1001f-1 [Thinprint]
    --END--1001x64-0.0.6

 198]-Start--above-1001x64-0.0.6 Mon May  6 15:13:01 IST 2019 Version "4.0.3" by Mayur
    1) In WriteModuleDotIni() function made btdefault "MultiMedia=On" for working webcam in PNA or ICA bydefault.
    Changes for following bugs 4393,3656 of mantis.
    --END--1001x64-0.0.6

 199]-Start--above-1001x64-0.0.8 Wed May  8 16:04:49 IST 2019 Version "4.0.4" by Mayur
    1) Bug resolved :- SAMBA printer password or share name with space name is not working.
    --END--1001x64-0.0.8

 200]-Start--above-1003x64-0.0.7 Thu May 9 11:38:41 IST 2019 Version "4.0.5" by Prajakta
    1) Did Changes in ExecuteSMBCommand() to write username password and domain in file to allow special characters as a password.
    --END--1003x64-0.0.7
 201]-Start--above-1003x64-0.0.8 Thu May 9 16:08:41 IST 2019 Version "4.0.6" by Namrata
    1) In DownLoadFile and uploadfile fuction pass password in double quote ,because its not working when password contains space and special character.
    --END--1003x64-0.0.8
202] -Start--above-1003x64-0.0.8 Thu May 9 17:13:43 IST 2019 Version "4.0.7" by Manikanta.
       1) If fusionms is running, very 1st time after flashing image TC failed to switch in fusionms.
          Impact Area :- VMSClient(Fusionms) Module.
          Note :- Added a function[writingDefaultSettingstoVMS()] which was called in ConfigurationWizard for very 1st time.
     --END--1003x64-0.0.8

 203]-Start--above-1003x64-0.1.0 Tue May 14 11:46:26 IST 2019 Version "4.0.8" by Prajakta
    1) Bug resolved :- 	0002894: For ConrolCenter and Connectionmanager different message is displayed when invoked through start menu/shortcut key
    --END--1003x64-0.1.0

 204]-Start--above-1003x64-0.1.0 Tue May 14 11:46:26 IST 2019 Version "4.0.9" by Mayur
    1) Added function to update "/etc/ntp.conf" file.
    --END--1003x64-0.1.0

 205]-Start--above-1003x64-0.1.1 Thu May 16 13:22:17 IST 2019 Version "5.0.0" by Manikanta.
    1) Solved Bug "0005533: Two server certificate entry shows in certificate manager".
    Impact Area - VMSClient.
    --END--1003x64-0.1.1

 206]-Start--above-1003x64-0.1.1 Fri May 17 13:33:13 IST 2019 Version "5.0.1" by Mayur
    1) Added "Stoney" driver entry while writing 20-screen.conf file.
    --END--1003x64-0.1.1

 207] --Start--above-1003x64-0.1.1 Sat May 18 15:19:52 IST 2019 VERSION "5.0.2" by Namrata
       1) Added "Mobile Storage" module in Storage section.
       2) Please add "mobile-mount.sh' and Mobile.png while creating os-bin.sq
       3) did changes in writesmbconf if mobile-storage is enable and share via smb is check then write entry in writeSMBconf.
    --END--1003x64-0.1.1

 208] --Start--above-1003x32-0.1.2 Sat May 18 18:09:12 IST 2019 VERSION "5.0.3" by Manikanta.
       1) Solved Bug "0005244: If TC already registered in fusionms, and we change fusionms server, perform restore, it shows two entries in Host/xhost".
            Impact Area - VMSClient HostsXhosts(fusionms).
    --END--1003x32-0.1.2

 209] -Start--above-1003x32-0.1.5 Fri May 24 12:35:53 IST 2019  VERSION "5.0.4" by Kunal.
       Changes done
          -- Add /usr/os-bin/firefox-mode/handlers.json file in getCert9Key4DB() Function for firefox.
       --END--1003x32-0.1.5

210] --Start--above-1003x64-0.1.7 Mon May 27 18:11:54 IST 2019  Version "5.0.5" by Namrata
     1)0005677: Reconnect timer fails to work with PCOIPClient connection
    --End--1003x64-0.0.7

211] --Start--above-1003x64-0.1.6 Tue May 28 18:56:29 IST 2019 Version "5.0.6" by Mayur
     1) Added new MT for M600 (in common and specific function).
    --End--1003x64-0.1.6

212]  --Start--above-1004 Wed May 29 16:41:52 IST 2019 Version "5.0.7" by Mayur
	193]  --Start--above-1001a-2 Tue May  7 05:45:21 EDT 2019 Version "3.0.6" by Jigneshkumar
	           1) Bug resolved, Black Screen apper in vmview connection after sesstion logout in Imprivata with smart card.
	              only for vmview connection.
	    --End--1001a-2
    --End--1004

212]  --Start--above-1004x64-0.0.2 Tue Jun  4 12:20:55 IST 2019 Version "5.0.8" by Namrata
               1) while doing Import and export Operation password filed not accepting "double quotes".
        --End--1004x64-0.0.2

213]  --Start--above-1004x64-0.0.3 Tue Jun  4 19:21:45 IST 2019 Version "5.0.9" by Mayur
               1) 0005767: Touchscreen fails to work when we change display rotation.
               2) 0005720: In Rotation After Sleep Calibration Fails to Work in Touch Screen with ThinkCenter Monitor
        --End--1004x64-0.0.3
214]  --Start--above-1004x64-0.0.3 Wed Jun  5 12:20:55 IST 2019 Version "5.1.0" by Namrata
               1) while doing Import and export Operation password filed not accepting "double quotes".
        --End--1004x64-0.0.3
215]  --Start--above-Thu Jun  6 11:46:59 IST 2019 Version "5.1.1" by Mayur
               1)solved bug : 0005790: Printer fails to map in RDP after edit.
        --End--1004x64-0.0.3

216]  --Start--above-1005 Fri Jun  7 19:53:49 IST 2019 Version "5.1.2" by khemraj
               1) solved bug : TC failed to switch fusionms to fusionms server
        --End--1005

217]  --Start--above-1006x64-0.0.1 Tue Jun 11 19:08:01 IST 2019 Version "5.1.3" by Manikanta.
               1) 0005241: If network is applied manually and we perform normal reboot/shutdown, the TC does not go in fusionms.
                  Impact Area :- VMSClient Fusionms.
        --End--1006x64-0.0.1


218]  --Start--above-1007 Wed Jun 19 16:44:25 IST 2019 Version "5.1.4" by Prajakta/Namrata.
               1) 0005810: With blank username, password and valid domain ,on application search if we enter FQDN and later remove @ domain gets enabled.
               2) Did changes in WriteWfclient() to write LastComPortNum entry in wfclient.ini file.
        --End--1007

219] --Start--above-1007x32-0.0.1 Wed Jun 19 17:14:04 IST 2019 VERSION "5.1.5"--by Kunal
          1] Added MobileStorage option when we select slideshow from combobox. changes define MOBILESTORAGE path in Lcore.
  --END--1007x32-0.0.1

220]  --Start--above-1007x32-0.0.2 Sat Jun 29 13:37:27 IST 2019 Version "5.1.6" by Mayur
            1) Removed unwanted CheckReconnectOption() function.
        --End--1007x32-0.0.2

221]  --Start--above-1007x64-0.0.4 Fri Jul 19 17:51:25 IST 2019 Version "5.1.7" by Prajakta
            1) Did changes in insertValues_PNAget() to write fullscreen value into database.
        --End--1007x64-0.0.4

222]  --Start--above-1007x32-0.0.4 Sat Jul 20 15:41:49 IST 2019 VERSION "5.1.8"--by Kunal
          1] Added Enable Floating Bar option In VMViewGlobalSettings.
       --END--1007x32-0.0.4

223]   Start--above-1007x32-0.0.3 Tue Jul 30 17:09:41 IST 2019 VERSION "5.1.9" by Jignesh
        1) Added new module ImprivataGlobal settings and Made changes for ImprivataGlobal settings
    --END--1007x32-0.0.3

224] -Start--above-1007x32-0.0.4 Thu Aug  1 17:26:13 IST 2019 VERSION "5.2.0" by Mayur
	193] -Start--above-1003r-0 Thu Jul  4 18:57:23 IST 2019 VERSION "3.0.6" by jignesh
	        1) Changes Done in checkBoardTypeForBIOS for BiosConfiduration support for M715q and M715qRR board.
	     --END--1003r-0
     --END--1007x32-0.0.4

225] -Start--above-1007x32-0.0.4 Thu Aug  1 17:45:31 IST 2019 VERSION "5.2.1" by Mayur
	193] -Start--above-1003n-0 Thu Jun 13 18:04:45 IST 2019 VERSION "3.0.6" by Mayur
    	    1) Added modifyAllRegionsINIFile() function for common use to change All_Regions.ini file.
	     --END--1003n-0
	193] -Start--above-1003n-1 Wed Jun 19 11:51:22 IST 2019  VERSION "3.0.7" by Mayur
	        1) did changes modifyAllRegionsINIFile() function for common use to change All_Regions.ini file.
	     --END--1003n-1
     --END--1007x32-0.0.4

226] -Start--above-1007x32-0.0.4 Fri Aug  2 12:36:21 IST 2019 VERSION "5.2.2" by Mayur
	193]  --Start--above-1003m-1  Tue Jun 25 16:17:52 IST 2019 VERSION "3.0.6" --by Namrata
    		    1. write LastComportNum Property in wfclient.ini
    	  --END--1003m-2
	194]  --Start--above-1003m-4  Tue Jul 23 16:35:35 IST 2019 VERSION "3.0.7" --by Prajakta
		        1. commented for NorthWestern university client To does not write comport entry in wfclient.ini file.
   		  --END--1003m-4
     --END--1007x32-0.0.4

227] -Start--above-1007x32-0.0.4 Fri Aug  2 13:41:35 IST 2019 VERSION "5.2.3" by Mayur
	193]  --Start--above-1001q-0 Fri Jun 21 15:32:31 IST 2019" 3.0.6" --by Kunal
    	 1) Changes done for define /root/.ICAClient/.eula_accepted file.
	   --END--1001q-0
   --END--1007x32-0.0.4

227] -Start--above-1007x32-0.0.4 Fri Aug  2 14:46:28 IST 2019 VERSION "5.2.4" by Mayur
		218]  --Start--above-1007b-x64-2 Sat Jun 29 19:43:14 IST 2019 Version "5.1.4" by khemraj.
		               1) After restore, "T" trail lience hotplug shows on cloud desktop board
		                  Impact Area :- VMSClient Cloud Desktop.
		        --End--1007b-x64-2
     --End--1007x32-0.0.4

227] -Start--above-1007x32-0.0.5 Sat Aug  3 14:57:29 IST 2019 VERSION "5.2.5" by Mayur
		193] --Start--above-1003o-1 Tue Jun 11 19:03:22 IST 2019 VERSION "3.0.6" by Mayur
        		1) Added changes related to WiFi by applying patches provided by Mr. Nikhil sir.
		     --END--1003o-1
		194] --Start--above-1003o-1 Wed Jun 12 14:11:44 IST 2019 VERSION "3.0.7" by Kunal
		     1] Changes done for added Debugs in all functions.
		     --END--1003o-1
		195] --Start--above-1003o-2 Thu Jun 13 19:11:44 IST 2019 VERSION "3.0.8" by Namrata
		      Changes bgscan parameters value as Signal Strength = -45, Short Interval = 30 , Long Interval = 300.
		      --END--1003o-2
		196] --Start--above-1003o-4 Fri Jun 14 18:05:08 IST 2019 VERSION "3.0.9" by Namrata
		      solved bug : Manual entry for DNS server option is by default checked when we configure Wi-Fi network
		      --END--1003o-4
      --END--1007x32-0.0.5

228] -Start--above-1007x32-0.0.5 Mon Aug  5 14:21:44 IST 2019 VERSION "5.2.6" by Mayur
		193] --Start--above-1003o-1 Tue Jun 11 19:03:22 IST 2019 VERSION "3.0.6" by Mayur
			        1) Added changes related to WiFi by applying patches provided by Mr. Nikhil sir.
		     --END--1003o-1
		194] --Start--above-1003o-1 Wed Jun 12 14:11:44 IST 2019 VERSION "3.0.7" by Kunal
			     1] Changes done for added Debugs in all functions.
		     --END--1003o-1
		195] --Start--above-1003o-2 Thu Jun 13 19:11:44 IST 2019 VERSION "3.0.8" by Namrata
			      Changes bgscan parameters value as Signal Strength = -45, Short Interval = 30 , Long Interval = 300.
		      --END--1003o-2
		196] --Start--above-1003o-4 Fri Jun 14 18:05:08 IST 2019 VERSION "3.0.9" by Namrata
			      solved bug : Manual entry for DNS server option is by default checked when we configure Wi-Fi network
		      --END--1003o-4
		197] --Start--above-1003s-2 Mon Jul  8 19:15:22 IST 2019  VERSION "3.1.0" by Namrata
				     solved bug :  added function To get bssid to solve issue releted same name wifi connecting issue.
			 --END--1003s-2
		198] --Start--above-1003s-3 Mon Jul  11 19:15:22 IST 2019  VERSION "3.1.1" by Namrata
				     solved bug : After applying valeo patch on commonOSv43 image ,name server entry(192.168.2.101) from resolve.conf file gets deleted.
			 --END--1003s-3
		199] --Start--above-1003s-3  Tue Jul 23 18:46:53 IST 2019 VERSION 3.1.2" by Nikhil Sir
			     1] Convert Wifi Frequency MHz to GHz
			--END--1003s-3
		200] --Start--above-1003s-5 Wed Jul 24 16:03:21 IST 2019 VERSION 3.1.3" by Jignesh
			     1] Resolved Issue:- Image stuck at addDNSserver function,
			--END--1003s-5
		201] --Start--above-1003s-7 Thu Aug  1 16:11:09 IST 2019 VERSION 3.1.4" by khemraj
			     1] Added getMHzFrequencies() for wireless Module.
			--END--1003s-7
	--END--1007x32-0.0.5

229] -Start--above-1007x32-0.0.5 Mon Aug  5 19:56:52 IST 2019 VERSION "5.2.7" by Mayur
		193]   --Start--above-1003v-1 Fri Jul 19 14:54:00 IST 2019 Version  "3.0.6" by Namrata
			         1) write function to get username if we pass($hostname, $assettag, $serialnumber) in connection.
			         2) write function to know the username added in connection is between ($hostname, $assettag, $serialnumber)
		       --END--1003v-1
		194]   --Start--above-1003v-1 Sat Jul 20 14:54:00 IST 2019 Version  "3.0.7" by Namrata
			        1) Local login window credential issue in case of ($hostname, $assettag, $serialnumber)
			        2) Changes Done in checkBoardTypeForBIOS for BiosConfiduration support for M715q and M715qRR board.
		       --END--1003v-1
		195]   --Start--above-1003v-1 Mon Jul 22 18:41:21 IST 2019 Version  "3.0.8" by Prajakta
			        1) Changes done in LaunchPNAgentAppsonDesktop and LaunchPNAgentAppsonMenu to display apps name based on its default value.
		       --END--1003v-1
		196]   --Start--above-1003v-1 Sat Mon Jul 22 20:03:00 IST 2019 Version  "3.0.9" by Prajakta
			        1) changes done to display error message when $serialnumber and $assettag value is invalid
		       --END--1003v-1
		197]   --Start--above-1003v-2 Tue Jul 23 15:43:47 IST 2019 Version  "3.0.0" by Prajakta
			        1) changes done in LCore to display error message when $serialnumber and $assettag and $hostname value is invalid
		       --END--1003v-2
		198]   --Start--above-1003v-2 Tue Jul 23 17:56:44 IST 2019 Version  "3.0.1" by Prajakta
			        1) Changes done in LocalCredentialDialog to work FQDN when we pass username with domain as $hostname@vdi.com/vdi.com\$hostname
		       --END--1003v-2
		199]   --Start--above-1003v-4 Wed Jul 24 18:45:44 IST 2019 Version  "3.0.2" by Prajakta
			        1)Changes done in LaunchPNAAppsonMenu and LaunchPNAAppsonDesktop to display Tooltip and Application Name properly based on its default value
		       --END--1003v-4
		200]   --Start--above-1003v-4 Thu Jul 25 14:07:48 IST 2019 Version  "3.0.3" by Prajakta
			        1) Changes done in LocalcredentialDialog when domain is not entered in domain field then wrong error message get diaplayed on ok button click.
		       --END--1003v-4
      --END--1007x32-0.0.5

230] --Start--above-1007x32-0.0.5 Tue Aug  6 18:51:18 IST 2019 VERSION "5.2.8" by Mayur
		218]  --Start--above-1007a-0 Mon Jun 24 15:29:15 IST 2019 Version "5.1.4" by Mayur
		            1) added following functions related to LivePen image and it's liscensing
	                   getUSBPENSerialNumber(), is_probably_full_disk(char *name), checkForUSBImage(), getBootDevice(), getDeviceVidPid(QString),
    	               getDeviceNames(), getVIDClassPIDSubclassName(QString, QString), liveImageUSBRestrict();
        		    2) Included lib  -ludev.
             --End--1007a-0
		219] --Start--above-1007a-0 Thu Jun 27 11:53:57 IST 2019 Version "5.1.5" by Mayur
		            1) Removed unwanted CheckReconnectOption() function.
		     --End--1007a-0
		220] --Start--above-1007ax64.0.3 Wed Jul 17 17:10:15 IST 2019 Version "5.1.6" by Khmeraj
        		    1] added fillCloudDesktopAllowLicenceEntry() for LTM Cloud desktop entry in db.
		     --End--1007ax64.0.3
		221] --Start--above-1007ax64-0.0.4 Tue Jul 23 13:51:02 IST 2019 Version "5.1.7" by khemraj.
				    1] 1. If TC1 is registered with pen drive -serial number after that if we restore TC and connect it to another TC2 which is already register with another pen driver -serial number  then in this case after LivePen image up it shows “trial license” till it auto register with LTM server after being managed, it reboot and trail  license hot plug gets remove.
				       2. If there is no connection or TC is unmanaged then  “trial license” remains. So, it should not display ‘T’ icon in any case after consuming license.
				    2] If TC1 is registered with pen drive -serial number(PD1) and TC2 is register with another pen drive -serial number(PD2), in this case, if we interchange pen drives, if we send any task on TC1 then it will reflect on TC2 or vice versa, so we will have to sync inventory.
			 --END--1007ax64-0.0.4
		222] --Start--above-1007ax64-0.0.4 Tue Jul 23 19:12:00 IST 2019 Version "5.1.8" by Mayur.
		            1] Added code to exclude for pendrive of livepen in session. in function  writeUSBFile() and  writeVMViewUDMFile().
		            2] Added default argument in excludeVIDPID(), liveImageUSBRestrict();
		     --END--1007ax64-0.0.4
		223] --Start--above-1007ax64-0.0.4 Thu Aug 1 17:28:27 IST 2019 Version "5.1.9" by Manikanta.
		            1] Solved Bug "When Fusionms is in network, flash image without network cable, connect network cable when image wakes up, reboot the TC, it gets registered on LTM server, but fails to auto-reboot."
        		       Impact Area :- VMSClient Fusionms(LivePen).
		               Note:- Added condition "If Normal reboot selected then only the VMSClient ClientScan will be sent to server" in SetdefaultSettingstoVMS.
	         --END--1007ax64-0.0.4
	--END--1007x32-0.0.5

231] --Start--above-1007x32-0.0.5 Wed Aug  7 15:05:29 IST 2019 VERSION "5.2.9" by Mayur
		193] --Start--above-1001C-0  Tue Apr 23 13:17:53 IST 2019 VERSION "4.0.1" by Kunal [Merged from --Start--above-1003x32-0.0.2  Fri Apr 19 18:33:19 IST 2019  VERSION "4.0.0" by Kunal].
		       Changes done
        		  -- Add New Implementation for  AT&T And Verizon Providers in Datacard in Create_wvdialConfFile().
		     --END--1000C-0
		194]  --Start--above-1003c-2  Tue Jun 25 16:17:52 IST 2019 VERSION "4.0.2" --by Namrata
		        1. write LastComportNum Property in wfclient.ini
		    --END--1003c-2
		194]  --Start--above-1003c-3  Thu Jul  4 14:06:57 IST 2019VERSION "4.0.3" --by Namrata
			        1.Remove code releted to LastComportNum & comport  Property in wfclient.ini as due to this comport fails to rediret
			        it only write in all_region.ini file.....as told by nikhil sir
 		      --END--1003c-4
		195] -Start--above-1003c-5  Sat Jul  6 13:00:22 IST 2019 "4.0.4" by Namrata
			        1. write LastComportNum Property in wfclient.ini
		     --END--1003c-5
		196] -Start--above-1003c-5 Tue Jul 23 17:54:58 IST 2019 VERSION "4.0.5" by jignesh
			        1) Changes Done in checkBoardTypeForBIOS for BiosConfiduration support for M715q and M715qRR board.
		     --END--1003c-5
		197] -Start--above-1003c-6 Mon Aug  5 12:17:17 IST 2019 VERSION "4.0.6" by Namrata
			        1) Did changes in sensignalToTC() fuction,as we implement local server socket instead of "signal 10" to chnage connection status and add connection.
		     --END--1003c-6
		198] -Start--above-1003c-7 Tue Aug  6 17:16:29 IST 2019  VERSION "4.0.7" by Namrata
			        1) remove commented code from sendsignalTOTC();
		     --END--1003c-7
     --END--1007x32-0.0.5

232]   --Start--above-1007x32-0.0.5 Thu Aug  8 15:34:50 IST 2019 VERSION "5.3.0" by Kunal.
         1] New Implementation Relaunch Mode for applications in VMViewGlobal.changes in  insertValues_VMView() function.
            --END--1007x32-0.0.5

233] --Start--above-1007x32-0.0.6 Fri Aug 9 11:35:38 IST 2019 VERSION "5.3.1" by Manikanta.
         1] Merged changes regarding USB License. - khemraj.
            Impact Area :- VMSClient Module (LivePen).
         2] Added ModifyAll_RegionINIFileForComPort for ICAGlobal COMPort.
            Impact Area :- VMSClient ICAGlobal Module.
     --END--1007x32-0.0.6

234] --Start--above-1007x32-0.0.6 Thu Aug  8 15:13:01 IST 2019 VERSION "5.3.2" by Prajakta
        1] changes to inser values in VMVieWGlobal table.
     --END--1007x32-0.0.6

235] --Start--above-1007x32-0.0.7 Sat Aug 17 12:50:16 IST 2019 VERSION "5.3.3" by Jignesh
        1] changes writeImprivataGlobalTable function for return value of status
     --END--1007x32-0.0.7

236] --Start--above-1007x32-0.0.8 Tue Aug 27 14:47:55 IST 2019 Version "5.3.4" by Mayur
       1) Added function for writing data in socket.
    --End--1007x32-0.0.8
237] --Start--above-1007x32-0.0.9 Fri Aug 30 17:42:13 IST 2019 Version "5.3.5" by Mayur
    0006184:solved issue Error message of duplicate entry is displayed when we change Hostname of TCNameSettings
            when tc has internal wifi or dongal connected then we didnot get wifi ip but here by default "127.0.0.1 hostname" is write in /etc/hosts/
            so for that if wired is connected then we given priority to wired to write in hosts file
    --End--1007x32-0.0.9

238] -Start--above-1007x32-0.0.8  Tue Sep  3 17:20:41 IST 2019 VERSION "5.3.6" by prajakta
     1] did changes to kill "usbarbitrator" instead of killing "/usr/lib/vmware/view/usb/vmware-usbarbitrator" by whole path.
    --END--1007x32-0.0.8

239] -Start--above-1007x32-0.0.9  Wed Sep  4 14:27:39 IST 2019 VERSION "5.3.7" by prajakta
     1] did changes to get the username and domain if we pass username@domain or dimain\username.
    --END--1007x32-0.0.9

239] -Start--above-1007x32-0.0.9 Fri Sep  6 20:02:45 IST 2019 VERSION "5.3.8" by Mayur
            1) 0004980: USB pendrive gets auto mount even after adding class rule for deny mass storage from Local UDM.
                Changes done :- In writeVMViewUDMFile(bool) function added check for Mass Storage from "ModularUSB" table.
                                and If blocked there then also block in VMView.
    --END--1007x32-0.0.9

240] -Start--above-1007x32-0.0.9 Mon Sep  9 16:55:12 IST 2019 VERSION "5.3.9" by Mayur
		193] --Start--above-1003x-0 Thu Aug 22 17:23:45 IST 2019 VERSION "3.0.6" by Mayur
		        1) Called fillDummyTimeZoneFile() function to save timezone in dummy file.
		        2) Called readDummyTimeZoneFile() function in to read value if table is blank.
		        3) Add sqlite query error debugs.
		    --END--1003x-0
		194] --Start--above-1003x-1 Tue Aug 27 17:01:32 IST 2019 VERSION "3.0.7" by Mayur
		        1) Default time zone is read from defaultvalues file if not available there then taken America/New_York.
		    --END--1003x-1
		195] --Start--above-1003x-3 Wed Aug 28 13:50:27 IST 2019 VERSION "3.0.8" by Mayur
		        1) Added Default argument in fillDummyTimeZoneFile() function.
		        2) Removed fillDummyTimeZoneFile() function call from lcore.
		    --END--1003x-3
		196] --Start--above-1003x-3 Wed Aug 28 18:32:56 IST 2019 VERSION "3.0.9" by Mayur
		        1) Added changes to save proper values in timezone table as in readDummyTimeZoneFile() table becames blank.
		    --END--1003x-3
    --END--1007x32-0.0.9

241] -Start--above-1007x32-0.0.9 Mon Sep  9 17:57:37 IST 2019 VERSION "5.4.0" by Mayur
		193] -Start--above-1001B-0 Tue Aug 20 17:39:45 IST 2019 VERSION "3.0.6" by Kunal.
		        1) Changes Done for Checked Fabulatech process showing 2 instarnces  after quick reboot.
		      --END--1001B-0
      --END--1007x32-0.0.9

241] -Start--above-1007x32-0.0.9 Mon Sep  9 18:17:07 IST 2019 VERSION "5.4.1" by Mayur
		// Already in 45-Dev
	203] --Start--above-1003c-2  Sat Aug 31 11:54:33 IST 2019  VERSION 3.1.7" by Namrata
		     1] 0006184:solved issue Error message of duplicate entry is displayed when we change Hostname of TCNameSettings
		                when tc has internal wifi or dongal connected then we didnot get wifi ip but here by default "127.0.0.1 hostname" is write in /etc/hosts/
		                so for that if wired is connected then we given priority to wired to write in hosts file
		--END--1003c-2
	--END--1007x32-0.0.9

242] -Start--above-1007x32-0.0.9 Mon Sep  9 18:36:29 IST 2019 VERSION "5.4.2" by Mayur
		193] --Start--above-1001z-0 Fri Aug  2 16:33:53 IST 2019 VERSION "3.0.6" by Mayur
		        1) Added condition for lenovo laptop L14W same as L480.
		    --END--1001z-0
		194] --Start--above-1001z-1 Mon Sep  9 16:17:28 IST 2019 VERSION "3.0.7" by kunal
		        1] Added MachineType for lenovo laptop L14W.
		    --END--1001z-1
    --END--1007x32-0.0.9

242] -Start--above-1007x32-0.0.9 Tue Sep 10 14:59:05 IST 2019 VERSION "5.4.3" by kunal
        -- handlers.json file is not copied when we launched Connection.
      --END--1007x32-0.0.9

243] -Start--above-1007x32-0.1.0 Wed Sep 11 16:48:49 IST 2019 VERSION "5.4.4" by Jignesh
        1] Changes done in DisplayErrorMessageBox function if message is blank than Message not display
      --END--1007x32-0.1.0

244] -Start--above-1007x32-0.1.0 Wed Sep 11 16:48:49 IST 2019 VERSION "5.4.5" by Prajakta
        1] 	0002757: Printer fails to map in RDP after edit.
      --END--1007x32-0.1.0

245] -Start--above-1007x32-0.1.0 Wed Sep 11 18:08:49 IST 2019 VERSION "5.4.6" by Namrata
        1] In ExecuteNetworkSetting  if for wireless leases file is empty the give priorty to eth0.
      --END--1007x32-0.1.0

246] -Start--above-1007x32-0.1.1 Thu Sep 12 14:24:44 IST 2019 VERSION "5.4.7" by Manikanta.
        1] Solved Bug 0005228: Restore Factory Inheritance Settings option fails to work.
            Impact Area: VMSClient RestoreFactory Ineritance.
        2] Solved Bug 0006249: Swithing fails to work. - Khemraj.
      --END--1007x32-0.1.1

247] -Start--above-1007x32-0.1.1 Wed Sep 11 18:08:49 IST 2019 VERSION "5.4.8" by Prajakta
        1] 0004989: Credentials window is displayed disabled (grey out) at the time of search application without credentials
      --END--1007x32-0.1.1

248] -Start--above-1007x32-0.1.2 Fri Sep 13 16:38:32 IST 2019 VERSION "5.4.9" by Prajakta
        1] when we write connectionname.ini file in CreateTempIniFile() for ica connection the it write password in decrypted form.
      --END--1007x32-0.1.1

249]   Start--above-1007x32-0.1.2 Fri Sep 13 21:01:49 IST 2019 VERSION "5.5.0" by Jignesh
        1) Bug Resolved :- Added closeButton for Citrix workspcae
    --END--1007x32-0.1.2

250]   Start--above-1007x32-0.1.3 Mon Sep 16 21:23:06 IST 2019 VERSION "5.5.1" by Mayur
        1) 0006574: In Wireless module all credential are getting displayed same of wired Network
            Chanegs done :- 1) Revert back changes in ExecuteNetworkSettings() function and added condition for file
                               size before writing OSParams table
        2) 0004980: USB pendrive gets auto mount even after adding class rule for deny mass storage from Local UDM
            Chanegs done :- 1) Update count in writeVMViewUDMFile() function if Mass storage is exclude in Local USM
    --END--1007x32-0.1.2

251]   Start--above-1007x32-0.1.4 Tue Sep 17 20:11:50 IST 2019 VERSION "5.5.2" by Manikanta.
        1) 0006578: With fusionms, heartbeat value gets reset to 60 seconds, after restore.
            Chanegs done :- 1) Changes done in executevmssettings().
                               Impact Area: VMSClient fusionms Module.
    --END--1007x32-0.1.4

252]   Start--above-1007x32-0.1.4 Tue Sep 17 21:57:55 IST 2019 VERSION "5.5.3" by Mayur.
        1) 0004231: Touch Screen is redirected as removal in VMView Connection and Touch screen fails to work in VMView RDP protocol
            Chanegs done :- 1) In excludeVIDPID() function changes done in vmview case.
    --END--1007x32-0.1.4

253]   Start--above-1007x32-0.1.5 Wed Sep 18 16:24:13 IST 2019 VERSION "5.5.4" by Jignesh
        1) Added callWindowFocusHackForCitriWorkSpcae for resolved TaskBar shown issue in CtrixWorkspace Desktop connect
    --END--1007x32-0.1.5

254]   Start--above-1007x32-0.1.5 Wed Sep 18 20:10:13 IST 2019 VERSION "5.5.5" by Mayur
        1) Added readNetworkDetailsFromTableAndFillFromFile() function to read and add networkdetails.
    --END--1007x32-0.1.5
255]  -- Start--above-1008 Wed Sep 25 19:33:13 IST 2019 Version "5.5.6" by Namrata
           1]added readMD5SUMTableAndWriteAfterExtract() function to save and add md5sum old table after setting import.
    --End--1008

256] -- Start--above-1008x32.0.0.1 Thu Sep 26 20:59:16 IST 2019 Version "5.5.7" by kunal
           1] removed Asset Tag entry for TCS Client.
    --End--1008 x32.0.0.1

257] -- Start--above-1008x32.0.0.2 Fri Sep 27 17:29:34 IST 2019 Version "5.5.8" by Manikanta.
           1] 14W Laptop failed to register on LTM server.--khemraj
    --End--1008 x32.0.0.2

258] -- Start--above-1008x32.0.0.3 Mon Sep 30 18:30:01 IST 2019  Version "5.5.9" by Jigneshkumar.
        1] Bug resolved :- Smartcard authentication not work on citrix Imprivata.
            Changes :- File '/opt/Citrix/ICAClient/config/module.ini' write 'SmartCard=Off' in case of SmartCardTreatAsProxCard=true in Imprivata
    --End--1008 x32.0.0.3

259] --Start--above-1008x32-0.0.3 Mon Sep 30 18:30:01 IST 2019  Version "5.6.0" by Namrata
    1]solved issue : In keyboards, right alt to behave as left fails to work.
     did changes in ExcuteKeyboardSetting for l14w laptop sett 113 keycode for alt.
    --End--1008x32-0.0.3

260] -- Start--above-1008x32.0.0.3 Mon Sep 30 18:02:30 IST 2019 Version "5.6.1" by kunal
       --Changes Done
        1] In TC Name setting, hostname by Auto generated is wrong (it shows only Let).
       --End--1008 x32.0.0.3

261]  Start--above-1009f-1 Wed Oct 16 18:17:18 IST 2019 Version "5.6.2" by Namrata
        1] Added condition to not write imprivataGlobal table or write "Imprivata=Deactive" in imprivataGlobal on Gio6 Image and for Gio6-Cloud Desktop.
           in insertDefaultValues_ImprivataGlobal() function.
--END--1009f-1

262] Start--above-tunck Wed Nov 20 12:00:11 IST 2019 Version "5.6.3" by Namrata (merged from 1009g-gasco)
    261] -- Start--above-1009g-0 Wed Oct 23 16:19:17 IST 2019 Version "5.6.2" by kunal
       --Changes Done
        1] browser connection name contains space then citrix connection is not invoked through firefox.
       --End--1009g-0
--END--Trunk

263] Start--above-tunck Wed Nov 20 12:45:11 IST 2019 Version "5.6.4" by Namrata (merged from 1009b-Interiorhealth)
    261] -- Start--above-1009b-0 Mon Oct 14 18:28:06 IST 2019 Version "5.6.2" by Prajakta
        1] Did changes in insertValues_VMView() to store Desktop Pool Value in database.
       --End--1009b-0
--END--Trunk
264] Start--above-tunck Sat Nov 30 11:58:44 IST 2019  Version "5.6.5" by Namrata (merged from 1009g-gasco)
    262]--Start--above-1009g-1 Wed Nov 27 18:02:20 IST 2019 VERSION "5.6.4"--by Prajakta
        1] added IgnoreXErrors=55.0/9,60.0/13 in /root/.ICAClient/wfclient.ini to ignore the errors that are occurring while launching the Seamless Apps
    --END--1009g-1
 --END--Trunk

265] Start--above-tunck Sat Nov 30 15:58:44 IST 2019  Version "5.6.6" by Namrata (merged from 1009g-gasco)
    261] -- Start--above-1009g-1 Wed Oct 23 16:19:17 IST 2019 Version "5.6.3" by Bhushan
       --Changes Done
        1] Add two functions "checkForZeroClientInOSConf" and "readOSConfFromLeasesFile" for read resective leases file and read data from it
       --End--1009g-1
--END--Trunk

266] --Start--above-1009l-10  Mon Jan 13 16:32:47 IST 2020 Version "5.6.7" by Bhushan.
     1] “NTP through DHCP Server” task fails with group and template
     --END--1009l-10

266] --Start-above Mon Dec  2 12:04:05 IST 2019 Version "5.6.7" by Jignesh (merged from 1009h-Baystate)
	261]  --Start--above-1009h-0 Wed Nov  6 13:59:39 IST 2019 VERSION "5.6.2"--by Jignesh
       Changed Done--
        1] Changes done in executeVMViewGlobal function to resolve vmview connection connecting roaming time.
    --END--1009h-0

	262] --Start--above-1009h-2 Wed Nov 13 11:00:00 IST 2019 VERSION "5.6.3" --by Bhavika
       --Chnages Done--
       1]When creating a USB device or class rule, to allow a specific device or class of devices to be redirected using USB redirection,
         all other types of devices are excluded, and will not be able to redirect, even if they would normally redirect.
         To solve this issue added the condition for deny in writeVMViewUDMFile Function.
     --END--1009h-2

	263] --Start--above-1009h-7 Thu Nov 21 15:46:47 IST 2019 Version "5.6.4" by Prajakta
      1] Did changes to store values in PNAgentGlobal and VMViewGlobal values in database.
      2] Did changes in LocalCredentialDialog To show values in LocalCredentialDialog based on its preset Login Info stored in Global settings.
      3] Did changes in insertValues_VMView() to store Desktop Pool Value in database.
     --End--1009h-7

	264] --Start--above-1009h-8  Fri Nov 22 16:13:29 IST 2019 Version "5.6.5" by Bhushan
      1] If we uncheck ‘USB Redirection’ in VMView Global, still devices gets redirect in session.
        Impact Area:- usb redirection in vmware conncetion
    --End--1009h-8

	264] --Start--above-1009h-8  Fri Nov 22 20:29:43 IST 2019 Version "5.6.6" by Bhushan
      1] If we uncheck ‘USB Redirection’ in VMView Global, still devices gets redirect in session.
        Impact Area:- usb redirection in vmware conncetion
    --End--1009h-8

	265] --Start--above-1009h-11 Fri Nov 29 15:25:39 IST 2019 Version "5.6.7" by Prajaktaa
        1] Added Functionality to hide BaloonToolTip.
    --END-1009h-11
--END-Trunk

267] --Start-above Wed Jan  8 12:56:40 IST 2020 "5.6.8" by Jignesh (merged from 1009r-ImprivataPIE)
		267] --Start--above-1009r-0 Thu Dec 12 11:26:13 IST 2019 Version "5.6.8" by Jignesh
            1] Changes Done for ImprivataPIE, if ImprivataPIE is enebled than os virtual channel not work,
	            Imprivata provide it's own virtual channel.
	    --END--1009r-0

		267] --Start--above-1009r-3 Fri Dec 20 18:47:43 IST 2019 Version "5.6.9" by Jignesh
	        1] Bug Resolved :- Virtual Channel not work in Imprivata PiE in Citrix session.
	    --END--1009r-3
--END-Trunk

268] --Start-above Wed Jan  8 15:22:21 IST 2020 "5.6.9" by Jignesh (merged from 1009a-L14W)
		261] -- Start--above-1009a1 Fri Nov 15 11:59:06 IST 2019 Version "5.6.2" by Rutuja
	         1) Added Function in LCore setTouchPaddAccelertion() and writeTouchPadConfigurationFile() for Touchpad setting.
	       --End--1009a1
		262] -- Start--above-1009a-2 Thu Nov 21 02:33:55 EST 2019 Version "5.6.3" by Rutuja
	         1) Did changes in touchpadConfigurationForLaptop() to solve bug After restore all touch pad settings fails to work.( it will work only after clicking on apply button).
	         2) Did changes in writeTouchPadConfigurationFile() to solve bug " Coasting Speed " functionality works when it is unchecked and didn’t work when it is checked.
	     --End--1009a-2
		263] -- Start--above-1009a-6 Fri Dec 13 12:08:21 IST 2019 Version "5.6.4" by Prajakta
		     --merged from 8551 revision
	    263]--Start--above-1009-0.0.3 Thu Dec 12 10:32:03 IST 2019  Version "5.6.4" by Namrata
	          1)While accessing the mobile hotspot, if the special character is present in the mobile name then LeTOS can not connect to that particular hotspot through wireless..
	       --End-1009-0.0.3
	    --End-1009a-6
	--END-Trunk-268

269] --Start-above Thu Jan 16 15:27:47 IST 2020 "5.7.0" by Namrata (merged from OSD-2.0.45-1009k-ZeroClient)

    262]  Start--above-1009k-0 Sat Dec  7 16:10:21 IST 2019 Version "5.6.3" by Mayur
        1) In ExecuteNetworkSettings() function check for "zc:" for osconf (130) scope and after configure wifi called readAndAddWiFiDetails().
        2) Added sleep and debug in findIPs() function because some time it will not gives proper output.
        3) Added reading and writing "wifidetails" table in readNetworkDetailsFromTableAndFillFromFile() function to save wifi credentials.
        4) Added readAndAddWiFiDetails(), readOSConfFromLeasesFile(), checkForZeroClientInOSConf(), updateOSBuild(), checkForZC(),
            getAvailableSizeInFolderOrFile(), calculateMd5sum() function for ZeroClient Implementation.
    --END--1009k-0

    266] --Start--above-1009o-1 Tue Dec 10 15:07:25 IST 2019 VERSION "5.6.8" --by Prajakta
        1) Changes To Store DefaultValue as "1" for AliasName.
    --END--1009o-1

    268] Start--above-1009o-1 Wed Dec 11 16:06:07 IST 2019 Version "5.6.9" by Prajakta
      268] Start--above-1009n-2  Tue Dec  3 15:27:53 IST 2019 Version "5.6.9" by Namrata
        1] restrict to save PresetLogin Option on basis of defaultvalues "ShowPresetLogin" for ICAGlobal and PNAGentGlobal Connection.
      --END-1009n-3
        2] Added Functionality to alterTable(), createTable() and insertTableValues() in lcore.
    --END--1009o-1
--END-Trunk 269

270] Start--above-trunk Fri Jan 17 16:14:11 IST 2020 Version "5.7.0" by Namrata [merged from OSD-2.0.45-1009o-Maimonides]
        267] --Start--above-1009o-2 Thu Dec 12 16:05:20 IST 2019  VERSION "5.7.0"  --by Namrata.
            1] change some pna releted condition according to new requirement of connection method.
        --END--1009o-2

        268] --Start--above-1009o-3 Wed Dec 18 18:07:52 IST 2019 VERSION "5.7.1"  --by Varsha.
            When we Press Escape on local login window after Cancelling the account selection window, list of VD's get Displayed.
        --END--1009o-3
        269] --Start--above-1009o-4 Wed Dec 18 16:46:46 IST 2019  VERSION "5.7.2" --by Namrata
            1] When application is invoked from customized selfservice/store/workspace/pnaagent legacy connections then a window appears named as notification area.
        --END--1009o-2
        270] --Start--above-1009o-7 Mon Dec 30 17:35:04 IST 2019 VERSION "5.7.3" --by Namrata
            1] if domain is empty then its not showing please enter "Domain" msg. on Localcredentialdialog when click on search connection button.
        --END--1009o-7
        271] --Start--above-1009o-7 Tue Dec 31 15:41:06 IST 2019 VERSION "5.7.4" --by Namrata
            1]  click on search button then on local login window come then we write someting i domain and then write in username then domain field get disbled.
            2]  solved issue send signal to osDesktop to refresh desktop , when TCCenter is not open its fails to updates the green symbol from Desktop.
        --END--1009o-7
--END-Trunk 270

271] Start--above-trunk Tue Jan 21 16:39:45 IST 2020 Version "5.7.1" by kunal [merged from OSD-2.0.45-1009c-LivePen]
        261] -- Start--above-1009c  Wed Oct 16 19:04:11 IST 2019 Version "5.6.2" by Bhushan.
       --Changes Done
        1] Unable to register LTM/Fusion server (Livepen)
         Note - we put entry in "/tmp/.LivePenSerialNumber" in "getUSBPENSerialNumber()" function and that entry from that file if file is present.
       --End--1009c
        262] --Start--above-1009 Tue Oct 15 11:25:11 IST 2019 Version "5.6.3" by Mayur
       1) Hardware clock is not set/sink in case of LivePen.
       2) Return from setDateTime() function which is used for set Manual Date-Time.
    --End--1009

        263] --Start--above-1009c-1 Fri Oct 18 12:33:53 IST 2019 Version "5.6.4" by Khemraj
       1) After restore, "T" trail lience hotplug shows on LivePen Image
          Impact Area :- VMSClient Livepen
    --End--1009c-1

         264] --Start--above-1009c-3 Wed Nov  6 11:44:46 IST 2019 VERSION "5.6.5" by kunal
       Changes done for:
            1] Show only Autogenerated and Manual Hostname for Live Pen.
--END-Trunk 271

272] Start--above-trunk Fri Jan 24 12:22:17 IST 2020 Version "5.7.2" by Varsha [merged from OSD-2.0.45-1009d-Foreaero]
    1]" --Start--above-1009d-3 Thu Nov  7 11:36:31 IST 2019  Version ""5.6.2"" by Prajakta
        1) Did changes in LocalCredentialDialog ui to call CredentialDialog.
        2) Changes Done in LocalCredentialDialog To set Title Icon Based on the connectionType.( Rev 8291)
    --END--1009d-3x32"
    2]"--Start--above-1009d-4 Fri Nov  8 14:46:17 IST 2019 Version ""5.6.3"" by Varsha
        Window title changed in Freerdp application Localcredentialdialog message appears. ( Rev 8300)
    --END--1009d-4x32"
    3]"-Start--above-1009d-5 Mon Nov 11 16:26:05 IST 2019 Version ""5.6.4"" by Varsha
        When we search application without network cable then error message displays as ""Please try once again, server may slow !""  instead of “server not reachable/invalid"".
        Solution: for this new function CheckServerExistUsingCurlCmd(QString ) is written in liblcore.( Rev 8309)
    --END--1009d-5x32"
--END-Trunk 272

273] Start--above-trunk Fri Jan 24 14:12:17 IST 2020 Version "5.7.3" by Manoj [merged from OSD-2.0.45-1009t-Sorbonne_University ]
	1]-Start--above-1009t Mon Dec 16 19:30:21 IST 2019 VERSION "5.7.1" --by Manoj [merged from 1000b-sorbonne university]
       1) Promoted QlineEdit of password with leforpassword class to show eye icon in QlineeditPassword
          merge from OSD-2.0.43-1001b-Sorbonne_University to OSD-2.0.45-1009t-Sorbonne_University.
       2) Added it in LCore leforpassword class (Rev 8596).
    --END--1009t    
	2]  --Start--above-1001b-11 Wed Nov 27 18:19:21 IST 2019 VERSION "5.7.4" --by Manoj
       1)Removing mycustom.h header file.
     --END--1009c-3
	3] --Start--above-1009t Thu Jan 02 17:41:21 IST 2020 VERSION "5.7.5" --by Manoj
       1) Promoted QlineEdit of password set Tabfocus Policy and tab order list arrange properly (Rev 8681)

    4]--Start--above-1009t Thu Jan 08 18:01:21 IST 2020 VERSION "5.7.6" --by Manoj
       1) Promoted QlineEdit of password setTabfocus to replace strong focus beacuse mouse cursor
          focus Policy is not showing and tab order list arrange properly (Rev 8700)
    --END--1009t
--END-Trunk 273

274] Start--above-trunk Tue Jan 28 15:35:00 IST 2020 Version "5.7.4" by Namrata [merged from OSD-2.0.45-1009t-Sorbonne_University ]
        71] Start--above-1009t-1 Tue Dec 17 14:16:53 IST 2019 Version "5.7.2" by Namrata [merged from 1000b-sorbonne university]

        192] -Start--above-1000 Tue Apr  9 18:43:04 IST 2019 VERSION "3.0.5" by Prajakta
                1) Changes Done in Localcredentialdialog to display Icon, Title, Logo, and Credentials on the basis of Default values of perticular fields.
             --END--1000

        193] -Start--above-1001b-2 Tue Sep 24 14:58:15 IST 2019 VERSION "3.0.6" by Prajakta
                1) Changes Done in LocalCredentialDialog to add Keyboard Layout button , Title and Logo of sorbonne university based on its default values.
             --END--1001b-2
        194]  --Start--1001b-5  Fri Oct 11 15:27:20 IST 2019 Version "3.0.7" by Namrata
                 1] Write shortcutkeys for sound as "ctrl+shift+K" as per CurrentLoggedIn user.
              --END--above-1001b-5

        194] -Start--above-1001b-5 Fri Oct 11 16:59:53 IST 2019 VERSION "3.0.8" by Prajakta
                1) Changes Done in LocalCredentialDialog to show Title, Logo and Window Icon of sorbonne university based on its default values CitrixLWTitle=1, CitrixLogo=1, CitrixIcon=1 for Logo path should be /root/Sorbonne_Logo.png and for Icon path should be /root/Sorbonne_Icon.png.
             --END--1001b-5

        195] -Start--above-1001b-6 Mon Oct 14 17:27:58 IST 2019 VERSION "3.0.9" by Prajakta
                1) Changes Done in LocalCredentialDialog to show Logo Properly scaled based on its size.
             --END--1001b-6

        196] -Start--above-1001b-7 Wed Oct 23 17:57:37 IST 2019 VERSION "3.1.0" by Prajakta
                1) Changes Done in LocalCredentialDialog to show Title set to CitrixLWTitle.
             --END--1001b-7
        197] --Start--above-1001b-8  Fri Oct 25 14:57:03 IST 2019VERSION "3.1.1"  --by Namrata
             1] Added shortcut to change Layout to default and switch layout acoording to list.
             --END--1001b-8
        198] --Start--above-1001b-8 Fri Nov  1 16:52:53 IST 2019  VERSION "3.1.2"  --by Namrata
             1] Added 3 function to alter Keyboardsettings table bcoz 7 extra column are added in table;
               alterTable() , createTable(), insertTableValues().
             2] added Condition to show KeyboardLayout in taskbar on the basis of taskbarproperties and applienceproperties value.
             3] added function to  retrive KeyboardLayout and KeyboardVariant Full name.
             --END--1001b-8
        199] --Start--above-1001b-11 Mon Nov 25 15:59:21 IST 2019 VERSION "3.1.3" --by Manoj
               1) Promoted QlineEdit of password with leforpassword class to show eye icon in QlineeditPassword .
            --END--1001b-11
        200]  --Start--above-1001b-11 Wed Nov 27 18:19:21 IST 2019 VERSION "3.1.4" --by Manoj
               1)Removing mycustom.h header file.
               --END--1001b-11

        201]  --Start--above-1001b-12 Wed Dec 11 17:46:31 IST 2019 VERSION "3.1.5" --by Prajakta
               1) Did Changes to  Logo of Sorbonne university displayed at the left on local login window of PNAgent Connection. (It should be displayed in center).
               2) When we try to search application, then no fields (e.g.- Username, Password etc.) are displayed on local login window of PNAgent Connection
              --END--1001b-12
        --END--1009t-1
--END-Trunk 274

275] --Start--above-trunk-0.0.1 Wed Jan 29 18:41:35 IST 2020 Version "5.7.5" by Prajakta [merged from OSD-2.0.45-1009h-Baystate]
     1] Changes Done in ExecuteNetworkSettings() by adding condition readGrubFile(QString("zero")). (Mayur)
  --END-Trunk-0.0.1

276] --Start--above-trunk-0.0.1 Thu Jan 30 14:15:31 IST 2020 Version "5.7.6" by Prajakta [merged from OSD-2.0.45-1009n-LenovoChina]
   "266] Start--above-1009n-1 Mon Dec  2 05:05:45 EST 2019 VERSION ""5.6.8"" by Prajakta (8460 → Rev 8461)
        1] Did changes to write Server in connectionname.ini file for ICA Connection.
    --END--1009n-1"
   "269] -- Start--above-1009n-2 Tue Dec  3 15:43:56 IST 2019 Version ""5.7.0"" by Prajakta (8479 → Rev 8480 )
           1] Did changes in to write server properly in connectionname.ini file when we provide port with server.
    --End--1009n-2"
   "270] -- Start--above-1009n-3 Thu Jan  2 11:46:03 IST 2020 Version ""5.7.1"" by Rutuja (8666 → Rev 8667)
           1] Add an process environment variable in getFlashSize();in spanish, german,french lanuage it showing comma insted of dot.
    --End--1009n-3"
   "271] -- Start--above-1009n-4 Thu Jan 30 01:02:14 EST 2020 Version ""5.7.2"" by Mayur (8843 → Rev 8844 )
           1) Added condition for ""M75TC"" Lenovo board as ""15d8"" and ""Picasso"" in ModifyXorgFileForScreen() function.
    --End--1009n-4"
  --END-Trunk-0.0.1

277] --Start--above-Trunk Thu Jan 30 17:58:42 IST 2020 VERSION "5.7.7"--by Bhushan
      1] changes marge frrom Leverpool to TCS branch for RDC
--END-Trunk 277

278]  --Start--above-trunk-0.0.1Fri Jan 31 14:22:15 IST 2020 Version "5.7.8" by Kunal [merged from OSD-2.0.45-1009j-TCS]
       261] -- Start--above--x64-1009j-1 Sat Nov 16 18:32:40 IST 2019 Version "5.6.2" by khemraj
             --Changes Done
            1] Fusionms switching fails to work after restoring image.
            changes done for Fusionms flow
            --End--x64-1009j-1

       263] --Start--above-1009j-4 Mon Nov 25 19:40:01 IST 2019 VERSION "5.6.4"--by Kunal
         Changed Done For TCS--
         1] Changes done for system get locked on windows+L button.
         --END--1009j-4

       264] --Start--above-1009j-4 Tue Nov 26 10:50:01 IST 2019 VERSION "5.6.5"--by Manikanta/Khemraj.
         Changed Done For TCS--
          1] In Remote Agent settings, if focus is on 'Manual' radio button, it gets reset after normal reboot/shutdown.
          2] Default entry '10.249.235.144' in host/xhost, gets deleted after restore when DHCP/fusionms is present in network.
        --END--1009j-4

       265] --Start--above-1009j-5 Sat Nov 30 11:23:51 IST 2019 VERSION "5.6.6"--by Bhushan.
         Changed Done For TCS--
         1] If Image is flashed or restored with network cable and fusionms/DHCP is not present in network, it should show 10.249.235.144 in remote agent settings.
         2] If Image is flashed without network cable, it should show 10.249.235.144 in remote agent settings.
          Discription:- writingDefaultSettingstoVMS().
         --END--1009j-5

       266] --Start--above-1009j-4 Sat Nov 30 12:33:42 IST 2019 VERSION "5.6.7"--by Kunal
          Changed Done For TCS--
          1]  Certificates are not reflect in firefox connection for TCS.
         --END--1009j-5

        267] --Start--above-1009j-10 Wed Dec 11 18:51:21 IST 2019 VERSION "5.6.8"--by Kunal
          Changed Done For TCS--
          1] Changes related to CIFS to disable SMB1 to  remove vulnerability.
        --END--1009j-10
--END-Trunk 278

279] --Start--above-x64-Trunk-0.0.2 Fri Feb  7 17:57:00 IST 2020 Version "5.7.9" by Bhushan [merged from OSD-2.0.45-1009l-Liverpool]

    264] --Start--above-1009l-3 Tue Dec 31 12:15:05 IST 2019 VERSION "5.6.5" --by Mayur
            1) Chages done in createDefaultModularUSBTable() and insertValues_VMView_PNAgent(() function added extra argument for PNA and VMView UDM.
            2) Changes added in writeUSBFile() and writeVMViewUDMFile() function to add all rules from ModularUSB (localUDM) as
                per new inplementation. Also write device rules before Class rules.
            3) Changes done in insertDefaultPNA_UDMValues() function to create table for upgrade patch and DefaultPNAUDMSettings table.
     --END--1009l-3
    265] --Start--above-1009l-6 Tue Jan  7 14:39:37 IST 2020 VERSION "5.6.6" --by Mayur
            1) Changes added in writeUSBFile(bool) function for solving multiple entries of Audio rule.
            2) For adding entry for touchpannel in PNAUDM.
     --END--1009l-6
    266] --Start--above-1009l-10  Mon Jan 13 16:32:47 IST 2020 Version "5.6.7" by Bhushan.
     1] “NTP through DHCP Server” task fails with group and template
     --END--1009l-10

    267]--Start--above-1009l-11 Tue Jan 14 15:41:30 IST 2020 Version "5.6.8" by khemraj
        1] If Restore Factory Inheritance Is enabled, and we drag and drop TC from one group to another group (Group should contain policies), policies get applied with logged in user and SPAdmin both.
            Impact Area : VMSClient Restore Default Configuration
        --END--1009l-11
    268]--Start--above-1009l-12 Wed Jan 15 15:37:45 IST 2020 Version "5.6.9." by Namrata [merged from OSD-2.0.45-1009h-Baystate]
        261]  --Start--above-1009h-0 Wed Nov  6 13:59:39 IST 2019 VERSION "5.6.2"--by Jignesh
        Changed Done--
            1] Changes done in executeVMViewGlobal function to resolve vmview connection connecting roaming time.
    --END--1009h-0
    262] --Start--above-1009h-2 Wed Nov 13 11:00:00 IST 2019 VERSION "5.6.3" --by Bhavika
        --Chnages Done--
        1]When creating a USB device or class rule, to allow a specific device or class of devices to be redirected using USB redirection,
             all other types of devices are excluded, and will not be able to redirect, even if they would normally redirect.
            To solve this issue added the condition for deny in writeVMViewUDMFile Function.
     --END--1009h-2
    263] --Start--above-1009h-7 Thu Nov 21 15:46:47 IST 2019 Version "5.6.4" by Prajakta
        1] Did changes to store values in PNAgentGlobal and VMViewGlobal values in database.
        2] Did changes in LocalCredentialDialog To show values in LocalCredentialDialog based on its preset Login Info stored in Global settings.
        3] Did changes in insertValues_VMView() to store Desktop Pool Value in database.
     --End--1009h-7
    264] --Start--above-1009h-8  Fri Nov 22 16:13:29 IST 2019 Version "5.6.5" by Bhushan
        1] If we uncheck ‘USB Redirection’ in VMView Global, still devices gets redirect in session.
            Impact Area:- usb redirection in vmware conncetion
        --End--1009h-8
    264] --Start--above-1009h-8  Fri Nov 22 20:29:43 IST 2019 Version "5.6.6" by Bhushan
        1] If we uncheck ‘USB Redirection’ in VMView Global, still devices gets redirect in session.
            Impact Area:- usb redirection in vmware conncetion
    --End--1009h-8
    265] --Start--above-1009h-11 Fri Nov 29 15:25:39 IST 2019 Version "5.6.7" by Prajaktaa
        1] Added Functionality to hide BaloonToolTip.
    --END-1009h-11
    266] --Start--above-1009h-13 Wed Dec  4 16:19:13 IST 2019 Version "5.6.8" by Prajaktaa
            1] Added Functionality to alterTable(), createTable() and insertTableValues() in lcore.
        --END-1009h-13
    --END--1009l-12
    269] -Start--above-1009l-13 Thu Jan 16 19:20:58 IST 2020 VERSION "5.7.0" --by Kunal
            Changes done:
                1] removed "-k" parameter for HTTPS and FTPS protocol.
                2] write getFTPS_HTTPSSHostnamefromIP() function for HTTPS& FTPS protocol.
    --End--1009l-13
    270] -Start--above-1009l-13 Fri Jan 17 15:31:31 IST 2020 VERSION "5.7.1" --by khemraj
        1] In case of Client Drag Drop (in Same group)- RDC settings gets successful but device does not gets Restore.
    --End--1009l-13
    271] -Start--above-1009l-13 Fri Jan 17 15:31:31 IST 2020 VERSION "5.7.2" --by Mayur
            1) Chanegs done in setNTPDate() function for settings DateTime mannuallu after set via NTP is DST is unchecked.
            2) Added isInDST(QString continent, QString region) , getDSTList(QString cont_Region, QString year ),
            applyDateTimeAfterConfigurationUpdate(QString), getUrlDataSeperatly(QString strUrl) functions.
    --End--1009l-13
    272] --Start--1009l-16 Sat Jan 18 12:15:46 IST 2020 VERSION "5.7.3" --by Prajakta.
            1] did changes for IQL Board to for mmcblk.
    --End--1009l-16
    273]   --Start--1009l-16 Sat Jan 18 12:15:46 IST 2020 VERSION "5.7.4" --by Kunal.
            1] solve bug  for Certificate to download certifiacate automatically for HTTP and FTP protocol (3rd parameter not getting properly issue solved).
    --End--1009l-16
    274]   --Start--1009l-19 Mon Jan 20 11:38:14 IST 2020 VERSION "5.7.5" --by Khemraj/Nikhil sir
            1] change in getFTPS_HTTPSSHostnamefromIP  [ if nslookup doesn't get output then return IP ]
    --End--1009l-19
    275]   --Start--1009l-23 Fri Jan 24 20:27:24 IST 2020 VERSION "5.7.6" --by Mayur
            1) In restoreFactorySettings() function created tar for certificates on "BackupCertificatesAndKeys=1" condition.
            2) In restoreFactorySettings() function taken network backup on "EnableNetworkBackUp=1" condition.
            3) Changes added in readNetworkDetailsFromTableAndFillFromFile() function to take all netwok details back.
            4) Chanegs done in readFile(Qstring), readGrubFile() function.
            5) Added ADSJoinOnLogin() function to join ADS.
            6) Added editSmbConf() function for common usage.
            7) Added getMaximumResolutionAndRefreshRate() function to get maximum resolution with specific desktop.
            8) Adeed following functions getDisplayResolutionList(),  getResolutionAndRefreshList();
            9) Added readAndAddWiFiDetails() functions to read and apply Network Details.
            10) Added  setProperDisplayResolutionRefreshRate() function for adding highest resolution in database after Import/FirmwareUpdate.
       --End--1009l-23
    274]   --Start--1009l-26 Wed Feb  5 16:00:48 IST 2020 VERSION "5.7.7" --by Mayur
            1] Added changes related to store n/w timeout of Wired and Wireless network timeout while taking n/w backup.
    --End--1009l-26
    275]   --Start--1009l-26 Wed Feb  5 16:00:48 IST 2020 VERSION "5.7.8" --by Mayur
            1) Changes added for taking backup of Hostname on "EnableHostnameBackUp=1" defaultvalue condition.
                added readAndAddHostnameDetails(), readHostnameDetailsFromAndToTableFromFile() function of same.
    --End--1009l-26
--End--x64-Trunk-0.0.2

280]  --Start--above-x64-46-0.0.1 Wed Feb 19 11:54:50 IST 2020 VERSION "5.8.1"--by Namrata [ Merged from 46-dev ]

    261] --Start--above-1009 Fri Oct 11 19:42:29 IST 2019 Version "5.6.2" by Kunal
          1] Added New Implemetation for MobileStorage mapping.
          2] 0006902: If Firefox has space in connection name and we try to connect Citrix Server, then Open With window is displayed

        --End--1009

    262] --Start--above-1010 Sat Nov  2 11:38:07 IST 2019 Version "5.6.3" by Prajakta
          1] Did changes to store values in PNAgentGlobal and VMViewGlobal values in database.
          2] Did changes in LocalCredentialDialog To show values in LocalCredentialDialog based on its preset Login Info stored in Global settings.
        --End--1010

    263] -- Start--above-1010 Sat Nov  2 15:40:11 IST 2019 Version "5.6.4" by Prajakta
            1] Did changes in insertValues_VMView() to store Desktop Pool Value in database.
           --End--1010

    264]-Start--above-1009 Wed Nov 20 18:20:11 IST 2019 Version "5.6.5" by Varsha
        1] Added new Check Box named as "Browser Content Redirection" and on that file "/etc/icaclient/nls/en/module.ini" is written ie on "WebPageRedirection= On" and ""WebPageRedirection= Off" on uncheck for PNAgentGlobal
        2] Added new 10 columns named as "BrowserContentRedirection INTEGER, Extra6 INTEGER, Extra7 INTEGER, Extra8 INTEGER, Extra9 INTEGER, Extra10 VARCHAR(30), Extra11 VARCHAR(30), Extra12 VARCHAR(30), Extra13 VARCHAR(30), Extra14 VARCHAR(30)"
      --End--1009

    265]--Start--above-1009 Fri Nov 29 16:01:27 IST 2019 Version  "5.6.6" by Prajakta
          1) Changes to store EnableMultimedia Redirection value into VMViewGlobal Table.
        --End-1009
    266]--Start--above-1009 Thu Dec  5 11:41:18 IST 2019 Version "5.6.7" by Namrata
          1) When we try to connect Store Browse connection with local login window, and when we press “Esc” key on local login window then account selection window is displayed and then Citrix login window is displayed.
        --End-1009
    267]--Start--above-1009-0.0.3 Thu Dec 12 10:32:03 IST 2019  Version "5.6.8" by Namrata
          1)While accessing the mobile hotspot, if the special character is present in the mobile name then LeTOS can not connect to that particular hotspot through wireless..
        --End-1009-0.0.3

    268] --Start--above-64x1009-0.0.5 Tue Jan  7 17:46:21 IST 2020 Version "5.6.9" by Prajakta
        1] Did Changes To call Credential Dialog from LaunchConnection callCredentialDialog().
        --End--64x1009-0.0.5

    268] --Start--above-64x1009-0.0.5 Thu Jan  9 12:33:53 IST 2020 Version "5.7.0" by Prajakta
        1] Multimedia Redirection option displayed blank by default in VMView Global
        --End--64x1009-0.0.5

    269]  --Start--above-64x1009-0.0.6 Tue Jan  7 17:46:21 IST 2020 Version "5.7.1" by Parag
            1] changes :Did changes to read and write password in encrypted and Decrypted form from /tmp.sso and usrpwd file.
               Bug: in files when we write password it is in Decrypted form so anyone can see it.
         --END--64x1009-0.0.6

    270]  --Start--above-64x1009-0.0.7  Fri Jan 24 09:08:47 EST 2020 Version "5.7.2" by Parag
            1] changes : Did changes to read password Decrypted form usrpwd file.
          --END--64x1009-0.0.7

    271]  --Start--above-64x1009-0.0.7  Mon Jan 27 05:05:44 EST 2020 Version "5.7.3" by Rutuja
            1] VMView dialog fails to invoke if we click on apply button in VN-Global creating
               VMView connection.chnge in insertValues_VMView()function.
          --END--64x1009-0.0.7

    272] --Start--above--64X1009-0.0.7 Tue Jan 28 15:41:42 IST 2020 Version "5.7.4" by Prajakta
            1] Did Implementation of Blast Proxy and High Efficiency Video Decoding and CRL [Certificate Revocation List] Revocation Check for VMView Connection.
               Changes : Done in insertValues_VMView() in LCore.
         --End--64x1009-0.0.7

    273] --Start--above--1009-0.0.7 Thu Jan 30 12:04:51 IST 2020 Version "5.7.5" by Bhavika & Mayur
            1) Replace xrandr with xrandr.orig to obtain proper output.
            2) Added functions as getMultiMonitorResolutionList(), ExecuteMultiMonitorSettings() , mapMonitorPosition(), getPosition(),
                setMonitorPosition(), setMultiMonitor(), getLSUSBOutput(), getMaximumResolutionAndRefreshRate(),checkAndCallForDisplayLink()
                getMonitorList(),getDisplayResolutionList(), getDefaultRefreshrate().
            3) Replace "DisplaySettings" with "MultipleDisplay".
            4) Also added function used for DisplayLink.
         --End--1009-0.0.7

    273] --Start--above--1009-0.0.7 Thu Jan 30 12:04:51 IST 2020 Version "5.7.6" by Bhavika & Mayur
            1] Resolved wrong commit.
         --End--1009-0.0.7

    274] --Start--above--1009-0.0.7 Thu Jan 30 12:04:51 IST 2020 Version "5.7.7" by Bhavika & Mayur
            1] Added function getCardCount(), getDriverName(), getCardDriverMap() .
         --End--1009-0.0.7
    275] --Start--above--1009-0.0.9 Mon Feb 03 15:41:42 IST 2020 Version "5.7.8" by Manoj
            1] Did Implementation of VMviewglobal settings added combo box. In combo box logLevel insert.
               Changes : Done in insertValues_VMView() in LCore.
          -END--1009-0.0.9
    276] --Start--above--1009-0.1.2 Tue Feb 11 15:35:44 IST 2020 Version "5.7.9" by Manoj
            1] Multimedia redirection options set by default "Enable" in VMViewGlobal settings.
         --End--1009-0.1.2
    277] --Start--above--1009-0.1.2 Tue Feb 11 15:35:44 IST 2020 Version "5.8.0" by Manoj
            1] Flash size display in system info replace "findfs LABEL=sukshm" to "findfs LABEL=sukshm2"
          --End--1009-0.1.2
--End--x64-46-0.0.1
    278]  --start--above-1009-0.1.2 Thu Feb 20 10:15:39 IST 2020 version "5.8.1" by Bhavika
           1) Added changes to solve issue of multiple Manufacturer tag in edid.
   --End--1009-0.1.2

    278]  --start--above-1009-0.1.2 Thu Feb 24 16:34:39 IST 2020 version "5.8.2" by Mayur
           1) Added callCitrixwindow() function in lcore.cpp to called from Localcredentialdialog.
   --End--1009-0.1.2

    279] -- Start--above-64x1009-0.1.4 Thu Feb 27 18:23:00 IST 2020 Version "5.8.3" by Prajakta
         1] Changes to remove callCitrixwindow() from LCore.
    --End--64x1009-0.1.4

281] --Start--above-1009-0.1.4Thu Feb 27 18:10:48 IST 2020 VERSION "5.8.4"--by Kunal [ Merged from 1009n-LenovoChina ]
      272] -- Start--above-1009n-5 Fri Jan 31 04:15:28 EST 2020 Version "5.7.3" by Mayur
           1) Changes added while writing 20-screen.conf adding "ShadowPrimary" option.
                Filled "ShadowPrimary    off" in file is vga card contains "15d8" or "Picasso".
        --End--1009n-5

       273] -- Start--above-1009n-6 Tue Feb  4 15:16:05 IST 2020 Version "5.7.4" by Mayur
           1) Removed condition of "amdgpu" as issue occures on rysen M715q.
        --End--1009n-6

       274]  Start--above-1009n-8 Tue Feb 18 12:23:52 IST 2020 VERSION "5.7.5" by kunal
             1] Changes done to add Machine Type of the M75n.
         --End-1009n-8
--End--1009-0.1.4
281] --Start--above-1009-0.1.6 Wed Mar 11 18:10:03 IST 2020 VERSION "5.8.5"--by Namrata
    1] Implementation : backtrace segmentationfault  in Module print ModuleName, Class Name, functionName, line Number append output in /tmp/applicationlog.txt
    eg : (Segmentation fault) : TCCenter : Duplicate::on_PB_OK_clicked() at /home/OSDOS/OSD-2.0.45-1009/OSD-2.0.46-Dev-Release/build-TCCenter-Qt_4_8_5-Release/../TCCenter/duplicate.cpp:42
--End--1009-0.1.4

282] --Start--above-1009-0.1.6 Fri Mar 13 13:10:03 IST 2020 VERSION "5.8.6"--by Namrata
    1] Implementation : backtrace segmentationfault  in Module print ModuleName, Class Name, functionName, line Number append output in /tmp/applicationlog.txt
       Added currunt time in dbug.
        eg : (Segmentation fault) : TCCenter : Duplicate::on_PB_OK_clicked() at /home/OSDOS/OSD-2.0.45-1009/OSD-2.0.46-Dev-Release/build-TCCenter-Qt_4_8_5-Release/../TCCenter/duplicate.cpp:42
--End--1009-0.1.4

283] -- Start--above-1009.0.1.6 Fri Mar 13 12:08:43 IST 2020 Version "5.8.7" by Prajakta
         1] Issue:- In Authentication when we set Imprivata and apply after that when we set Desktop mode in UserInterface then Start Menu get hide.
           Changes:- added condition to show that icon only when Imprivata is logged in fore that read the Status from SysConf table if it is "loggedin" then in "/usr/share/icewm/preferences" file "TaskBarShowStartMenu=0" get written.
    --End--1009.0.1.6
284] -- Start--above-64x1009-0.1.7 Mon Mar 16 18:37:26 IST 2020 Version "5.8.8" by Manoj
         1] Tab sequnce set proper.
    --End--64x1009-0.1.7
285]  -- Start--above-64x1009-0.1.7  Mon Mar 16 19:40:04 IST 2020 Version "5.8.9" by Bhushan
         1] If deny is selected in local UDM, and we change deny to allow in PNAgent & VMView global settings, error message is not displayed, task gets succeeded which should be failed.
          Impact Area :- LCore (insertUDMValues function added).
    --End--64x1009-0.1.7

286] 9] -- Start--above-64x1009-0.1.7 Fri Mar 20 12:18:35 IST 2020 VERSION "5.9.0" --by Varsha
    Changes in ui as string was getting trimmed for French language
    --End--64x1009-0.1.7

287]  --Start--above-x64-46-0.2.1 Mon Mar 23 12:11:28 IST 2020 VERSION "5.9.1"--by Namrata [ Merged from Diligenta ]
284] Start--above-1009w-0 Mon Mar  2 16:18:34 IST 2020 VERSION 5.8.7 by Namrata
     1)Implement : For ADSPassword field in sysconf is  Store encrypted in database.
    --END--1009w-1

285] Start--above-1009A-3 Wed Mar 18 16:05:55 IST 2020 VERSION 5.8.8 by Prajakta
     1) For ICA Connection Password get display when we launch connection through launch command.
     2) When we add SAMBA printer then password written in database DeviceURI in decrypted format.
 --END--1009A-3
--END--x64-46-0.2.2

286]  -- Start--above-64x1009-0.2.3  Thu Mar 26 21:23:54 IST 2020 VERSION "5.9.1" --by Namrata
1 Shortcut need to change for SwitchKeyboardLayout ; CHANGE TO ALT+S - SOLVED
2 In ADS when Screen Saver in Enable, after timeout when we try to unlock lock screen lock it fails to unlock with ADS user password. Done
3 In ADS when we Launch Connection With SSO enable then it display Error message for password "Unknown username or bad password". Done

287] -- Start--above-64x1009-0.2.3 Thu Mar 26 23:23:45 IST 2020 VERSION "5.9.2" --by Mayur
         1) Changes done for dual/ multi display changes on defaultvalue "EnableMultiDisplay"
            NOTE : "EnableMultiDisplay=1" ==> Multidisplay
    --End--64x1009-0.2.3

288] -- Start--above-64x1009-0.2.4 Sat Mar 28 09:53:29 IST 2020  Version "5.9.3" by Jignesh, Marged from 1009W
	1] Implimentation:- reduce romaing logout time in imprivata.
        2] Bug Resolved:- Virtual channel not working in non-imprivata mode if enabled in imprivataglobal.
        3] Bug Resolved:- Mouse focus issue in Citrix xenapps with epic application.
    --End--64x1009-0.2.4

289] -- Start--above-64x1009-0.2.7 Thu Apr  2 14:46:57 IST 2020  Version "5.9.4" by Jignesh
        1] if Source sting is blank then return also blank in encryptDecryptString function.
    --End--64x1009-0.2.7

290] --Start--above-64x1009-0.2.7 Wed Apr  8 17:06:05 IST 2020  Version "5.9.5" by kunal
        1] BugResolved :- Jetdirect printer unable to redirect in firefox browser connection.
    --End--64x1009-0.2.7

291] --Start--above-64x1009-0.2.7 Sat Apr 11 16:56:41 IST 2020 Version "5.9.6" by Mayur
        1) Changes modified in executenetworksetting() function don't set hostname for live pen image.
    --End--64x1009-0.2.8
<<<<<<< .mine
292] Start--above-1009A-3 Tue Apr 14 18:18:56 IST 2020 VERSION 5.9.7 by Mayur
=======

292] Start--above-1009A-3 Tue Apr 14 18:18:56 IST 2020 VERSION 5.9.7 by Mayur
>>>>>>> .r9487
	265] --Start--above-1009c-6 Sat Apr 11 15:20:21 IST 2020 VERSION "5.6.6" by Mayur
     	       1) Added "Picasso" and "15d8" option while writing 20-screen.conf file.
     	       2) Changes added to configure wifi with ESSID contains "'s".
     	       3) addded function getSpecialESSID(), getUrlDataSeperatly()
       	         getFTPS_HTTPSSHostnamefromIP() => to get hostname from IP.
       	         readAndWriteFile()  => to read or write whole file or on specific condition.
       	         restServerRequest(), writeCallback() => to communicate and read data from rest server.
      	          createEnterPasswordUI() ,getRandomString(),invokeTerminalFromLineEdit() => creates dynamic ui, to ask password to invoke terminal.
     	       4) added qjson.cpp to read and parse json data.
	       5)Added base64BitEncodeAndDecode() function for encrypt decrept string to base 64.
               6) In createEnterPasswordUI() function added starting of x11vnc service.
               7) Added hard code password number check while opening terminal through invokeTerminalFromLineEdit() function.
     --END--1009-0.2.8

293] --Start--above-64x1009-0.2.9 Thu Apr 16 17:42:11 IST 2020 Version "5.9.8" by Jignesh
        1] Modified in getBootDevice() function for live pen cogo image.
            In cogo image mount point /sda1 showing device /dev/loop, but USB device actally connect on /dev/sdb{1-9}.
            It's handle by checking serial number of usb devices.
    --End--64x1009-0.2.9

<<<<<<< .mine
<<<<<<< .mine
264] --Start--above-1009l-3 Tue Dec 31 12:15:05 IST 2019 VERSION "5.6.5" --by Mayur
            1) Chages done in createDefaultModularUSBTable() and insertValues_VMView_PNAgent(() function added extra argument for PNA and VMView UDM.
             2) Changes added in writeUSBFile() and writeVMViewUDMFile() function to add all rules from ModularUSB (localUDM) as
                per new inplementation. Also write device rules before Class rules.
            3) Changes done in insertDefaultPNA_UDMValues() function to create table for upgrade patch and DefaultPNAUDMSettings table.
     --END--1009l-3

265] --Start--above-1009l-6 Tue Jan  7 14:39:37 IST 2020 VERSION "5.6.6" --by Mayur
            1) Changes added in writeUSBFile(bool) function for solving multiple entries of Audio rule.
            2) For adding entry for touchpannel in PNAUDM.
     --END--1009l-6

266] --Start--above-1009l-10  Mon Jan 13 16:32:47 IST 2020 Version "5.6.7" by Bhushan.
     1] “NTP through DHCP Server” task fails with group and template
     --END--1009l-10

267]--Start--above-1009l-11 Tue Jan 14 15:41:30 IST 2020 Version "5.6.8" by khemraj
    1] If Restore Factory Inheritance Is enabled, and we drag and drop TC from one group to another group (Group should contain policies), policies get applied with logged in user and SPAdmin both.
        Impact Area : VMSClient Restore Default Configuration
     --END--1009l-11

268]--Start--above-1009l-12 Wed Jan 15 15:37:45 IST 2020 Version "5.6.9." by Namrata [merged from OSD-2.0.45-1009h-Baystate]

    261]  --Start--above-1009h-0 Wed Nov  6 13:59:39 IST 2019 VERSION "5.6.2"--by Jignesh
       Changed Done--
        1] Changes done in executeVMViewGlobal function to resolve vmview connection connecting roaming time.
    --END--1009h-0

    262] --Start--above-1009h-2 Wed Nov 13 11:00:00 IST 2019 VERSION "5.6.3" --by Bhavika
       --Chnages Done--
       1]When creating a USB device or class rule, to allow a specific device or class of devices to be redirected using USB redirection,
         all other types of devices are excluded, and will not be able to redirect, even if they would normally redirect.
         To solve this issue added the condition for deny in writeVMViewUDMFile Function.
     --END--1009h-2

    263] --Start--above-1009h-7 Thu Nov 21 15:46:47 IST 2019 Version "5.6.4" by Prajakta
      1] Did changes to store values in PNAgentGlobal and VMViewGlobal values in database.
      2] Did changes in LocalCredentialDialog To show values in LocalCredentialDialog based on its preset Login Info stored in Global settings.
      3] Did changes in insertValues_VMView() to store Desktop Pool Value in database.
     --End--1009h-7

    264] --Start--above-1009h-8  Fri Nov 22 16:13:29 IST 2019 Version "5.6.5" by Bhushan
      1] If we uncheck ‘USB Redirection’ in VMView Global, still devices gets redirect in session.
        Impact Area:- usb redirection in vmware conncetion
    --End--1009h-8

    264] --Start--above-1009h-8  Fri Nov 22 20:29:43 IST 2019 Version "5.6.6" by Bhushan
      1] If we uncheck ‘USB Redirection’ in VMView Global, still devices gets redirect in session.
        Impact Area:- usb redirection in vmware conncetion
    --End--1009h-8

    265] --Start--above-1009h-11 Fri Nov 29 15:25:39 IST 2019 Version "5.6.7" by Prajaktaa
        1] Added Functionality to hide BaloonToolTip.
    --END-1009h-11

    266] --Start--above-1009h-13 Wed Dec  4 16:19:13 IST 2019 Version "5.6.8" by Prajaktaa
        1] Added Functionality to alterTable(), createTable() and insertTableValues() in lcore.
    --END-1009h-13
--END--1009l-12

269] -Start--above-1009l-13 Thu Jan 16 19:20:58 IST 2020 VERSION "5.7.0" --by Kunal
        Changes done:
            1] removed "-k" parameter for HTTPS and FTPS protocol.
            2] write getFTPS_HTTPSSHostnamefromIP() function for HTTPS& FTPS protocol.
    --End--1009l-13

270] -Start--above-1009l-13 Fri Jan 17 15:31:31 IST 2020 VERSION "5.7.1" --by khemraj
        1] In case of Client Drag Drop (in Same group)- RDC settings gets successful but device does not gets Restore.
    --End--1009l-13

271] -Start--above-1009l-13 Fri Jan 17 15:31:31 IST 2020 VERSION "5.7.2" --by Mayur
        1) Chanegs done in setNTPDate() function for settings DateTime mannuallu after set via NTP is DST is unchecked.
        2) Added isInDST(QString continent, QString region) , getDSTList(QString cont_Region, QString year ),
            applyDateTimeAfterConfigurationUpdate(QString), getUrlDataSeperatly(QString strUrl) functions.
    --End--1009l-13

272] --Start--1009l-16 Sat Jan 18 12:15:46 IST 2020 VERSION "5.7.3" --by Prajakta.
        1] did changes for IQL Board to for mmcblk.
    --End--1009l-16

273]   --Start--1009l-16 Sat Jan 18 12:15:46 IST 2020 VERSION "5.7.4" --by Kunal.
        1] solve bug  for Certificate to download certifiacate automatically for HTTP and FTP protocol (3rd parameter not getting properly issue solved).
       --End--1009l-16

274]   --Start--1009l-19 Mon Jan 20 11:38:14 IST 2020 VERSION "5.7.5" --by Khemraj/Nikhil sir
        1] change in getFTPS_HTTPSSHostnamefromIP  [ if nslookup doesn't get output then return IP ]
       --End--1009l-19

275]   --Start--1009l-23 Fri Jan 24 20:27:24 IST 2020 VERSION "5.7.6" --by Mayur
        1) In restoreFactorySettings() function created tar for certificates on "BackupCertificatesAndKeys=1" condition.
        2) In restoreFactorySettings() function taken network backup on "EnableNetworkBackUp=1" condition.
        3) Changes added in readNetworkDetailsFromTableAndFillFromFile() function to take all netwok details back.
        4) Chanegs done in readFile(Qstring), readGrubFile() function.
        5) Added ADSJoinOnLogin() function to join ADS.
        6) Added editSmbConf() function for common usage.
        7) Added getMaximumResolutionAndRefreshRate() function to get maximum resolution with specific desktop.
        8) Adeed following functions getDisplayResolutionList(),  getResolutionAndRefreshList();
        9) Added readAndAddWiFiDetails() functions to read and apply Network Details.
        10) Added  setProperDisplayResolutionRefreshRate() function for adding highest resolution in database after Import/FirmwareUpdate.
       --End--1009l-23

274]   --Start--1009l-26 Wed Feb  5 16:00:48 IST 2020 VERSION "5.7.7" --by Mayur
        1] Added changes related to store n/w timeout of Wired and Wireless network timeout while taking n/w backup.
       --End--1009l-26

275]   --Start--1009l-26 Wed Feb  5 16:00:48 IST 2020 VERSION "5.7.8" --by Mayur
       1) Changes added for taking backup of Hostname on "EnableHostnameBackUp=1" defaultvalue condition.
            added readAndAddHostnameDetails(), readHostnameDetailsFromAndToTableFromFile() function of same.
       --End--1009l-26

276]   --Start--1009l-27 Wed Feb 12 17:55:12 IST 2020 VERSION "5.7.9" --by Mayur
            1) Changes done in DownloadFile() function to return error code of certificate expire for server.
            2) added chenges in writeVMViewUDMFile() function as ";" is added in config file before rule name
                (e.g. viewusb.ExcludeFamily = ;printer)
            3) Changes done in excludeVIDPID() function for writing config file in proper formarat.
            4) In getUrlDataSeperatly() function replaces space with "%20" in file path.
            5) Changes added in getFTPS_HTTPSSHostnamefromIP() function for finding proper IP when server name is provided eith alise name
                which is provided in HostXhost;
            6) Added getINIDirectoryInfo(QString strDirURLPath), getReturnCodeForCurlCmd(QString strUrlType, int nProcExitCode, QStringList strOutPutList)
                functions for finding file on server.
       --End--1009l-27


75] --Start--above-64x1009-0.2.9 Thu Apr 16 17:42:11 IST 2020 Version "5.9.9" by Mayur
=======
294] --Start--above-64x1009-0.2.9 Thu Apr 16 17:42:11 IST 2020 Version "5.9.9" by Mayur
>>>>>>> .r9487
        1) Added condition to pass device type to curl POST and PUT methods in dummyRestServerRequest() function.
    --End--64x1009-0.2.9

295] --Start--above-64x1009-0.3.0 Fri Apr 17 16:18:01 IST 2020  Version "6.0.1" by Prajakta
        1] Did changes to write files "/root/.local/share/Amazon Web Services/Amazon WorkSpaces/RegistrationList.json" and "/root/.local/share/Amazon Web Services/Amazon WorkSpaces/UserSettings.json" for Generic Settings.
    --End--64x1009-0.3.0

296] --Start--above-64x1009-0.3.2 Sun Apr 19 00:34:27 IST 2020 Version "6.0.2" by Mayur
        1) In checkForUSBImage() function checked "/tmp/.USBPEN" file and if present then return true.
    --End--64x1009-0.3.2

297] --Start--above-64x1009-0.3.3 Sun Apr 19 22:05:57 IST 2020 Version "6.0.3" by Mayur
        1)Added condition for "getidinfo" in dummyRestServerRequest() function.
    --End--64x1009-0.3.3

298] --Start--above-64x1009-0.3.4 Mon Apr 20 18:00:56 IST 2020 Version "6.0.4" by Mayur
        1) In Authentication when we set Imprivata and apply after that when we set Desktop mode in UserInterface then Start Menu get hide.
    --End--64x1009-0.3.4

299] --Start--above-64x1009-0.3.4 Tue Apr 21 16:03:25 IST 2020 "6.0.5" by Jignesh
        1] Modified in getBootDevice() function for live pen cogo image.
            get connected usb device using blkid cmd.
     --End--1009x64-0.3.4
300] --Start--above-1009-0.3.4 Wed Apr 22 17:09:38 IST 2020 Version "6.0.6" by Mayur
        1) Changed password comparison logic with md5sum in invokeTerminalFromLineEdit() function.
     --End--1009-0.3.4

301] --Start--above-1009-0.3.5 Wed Apr 22 17:09:38 IST 2020 Version "6.0.7" by Mayur
        1) Changes added in readAndWriteFile() function in append new line case.
        2) Added debugs in dummyRestServerRequest() function.
     --End--1009-0.3.5

302]  -- Start--above-64x1009-0.3.7 Sat Apr 25 14:51:53 IST 2020  VERSION "6.0.8" --by Namrata
        1] new requirement to Add Firmware-update Icon on desktop, so write entry in packageinfo table for cogo image
    --End--64x1009-0.3.7

303]  -- Start--above-64x1009-0.3.8 Sun Apr 26 23:27:44 IST 2020 VERSION "6.0.9" --by Mayur
        1) Added changes in createEnterPasswordUI() function to start x11vnc.
    --End--64x1009-0.3.8

304] --Start--above-64x1009-0.4.0 Tue Apr 28 13:31:16 IST 2020 Version "6.1.0" by Kunal
         --Changes Done
            1] When we connect VMView blast connection with H264 option check then black screen displays after launching any desktop.
--END--64x1009-0.4.0

305] --Start--above-64x1009-0.4.0 Tue Apr 28 22:37:28 IST 2020 Version "6.1.1" by Mayur
            1) In downloadfile() function changes done for compair.
--END--64x1009-0.4.0

306] --Start--above-64x1009-0.4.1 Thu Apr 30 13:47:18 IST 2020 Version "6.1.2" by Mayur
            1) changed default timeout to reach server made to 120 sec. in dummyRestServerRequest() function.
--END--64x1009-0.4.1

307] --Start--above-64x1009-0.4.1 u Apr 30 17:29:15 IST 2020 Version "6.1.3" by Bhushan
            1) minor changes for Generic Settings Module
--END--64x1009-0.4.1

#######################################
308] --Start--above-64x1009-0.3.2  Tue Apr 21 16:19:28 IST 2020 "6.0.2" by Namrata [merged from Liverpool]
277] --Start--above-1009l-29 Fri Feb 14 10:53:34 IST 2020 Version "5.8.0" by Varsha
        sleep command is changed and now passed as "::sleep()"
    --END--above-1009l-29

278] --Start--above-1009l-29 Mon Feb 17 14:59:58 IST 2020 Version "5.8.1" by Mayur
        1) Changes done in setNTPDate() function as if ntpdate cmd failed then don't subtract time.
    --END--above-1009l-29

279]   Start--above-1009l-29 Tue Feb 18 15:07:05 IST 2020 VERSION 5.8.2 by khemraj
        1] Issue:- In immediate template [ VMSclient ], autostart not working in connection
    --END--1009l-29

280]   Start--above-1009l-29 Tue Feb 18 16:03:42 IST 2020 VERSION 5.8.3 by Mayur
        1) Changes added in getUrlDataSeperatly() function if nornal url is there with space in folder name then addedd "%20".
        2) In getINIDirectoryInfo() function added "/" before path.
    --END--1009l-29

281]   Start--above-1009l-30 Tue Feb 18 22:04:39 IST 2020 VERSION 5.8.4 by Mayur
        1) Reimplementated Certificate backup logic in restoreFactorySettings() function.
        2) Like importexportsettings created "/tmp/certificate" folder and create tar.
            [ Bug :- 1) After Restore Certificates fails to get Reflect in VMView Connection.
                     2) After Restore Certificates fails to get Reflect in Firefox Browser Connection.
        3) Changes added for in writeVMViewUDMFile() function while adding "viewusb.ExcludeAllDevices = True ".
            [Bug :- In VM-UDM if device rule - default is selected as "deny" and we add rule for deny then "exclude all devices "
                line gets delete from config file hence that particular added rule for  blocks the device  but other devices are not blocked.]
    --END--1009l-30

282]   Start--above-1009l-31 Wed Feb 19 17:22:41 IST 2020 VERSION 5.8.5 by Mayur
        1) All download fails if we try to download with hostname.
    --END--1009l-31

283]   Start--above-1009l-32 Wed Feb 19 20:58:23 IST 2020 VERSION 5.8.6 by Mayur
        1) After Restore Certificates not stored.
            ( steps:- ExportSettings TC settings then resotore TC. after boot Certificates not retain.)
        2) Added NODEV option while mounting /sda1.
    --END--1009l-32

284]   Start--above-1009l-26  Mon Feb 25 07:43:47 EST 2020 VERSION 5.8.7 by Namrata
        1) implimantation- New PopupModule in Taskbar
        2] added getsystemTrayStatus function is added.
        3) some changes in Writing icewm menu file because Schema of TaskbarProperties() and AppilanaceProperties()
    --END--1009l-26

285] -- Start--above-1009l-33 Thu Feb 20 18:45:23 IST 2020 Version "5.8.8" by Prajakta
            1) Changes for Preset Login Info to store "None" as default value instead of storing "Set User/Domain From Last Login" in VMViewGlobal and PNAgentGlobal.
    --End--1009l-33

285] -- Start--above-1009l-35 Thu Mar  5 16:52:18 IST 2020 Version "5.8.9" by Mayur
            1) Renamed insertValues_VMView_PNAgent() function call to insertUDMValues().
            2) Changes done in UploadFile() , DownloadFile() function for passing user name or credentials.
			3) Removed insertValuesInDatabase() function.
    --End--1009l-35

286] -- Start--above-1009l-35 Thu Mar  5 16:52:18 IST 2020 Version "5.9.0" by Mayur
            1) Changes added while calling insertUDMValues() function passed "0" instead of "" for serial id.
            2) Checked ParenID while writing writeUSBFile() file as blank entries are added in config file for serial id.
    --End--1009l-35

287] --start--above-1009l-36 Fri Mar 27 11:30:03 IST 2020 VERSION "5.9.1" --by Kunal [Merged from 1009z-normal]
      261] -- Start--above-1009z-0 Thu Feb 13 11:16:36 IST 2020 Version "5.6.2" by kunal[jignesh]
          --Changes Done
         1] For printer node was not showing( in backend it is showing lp1 instead lp0).
        --End--1009z-0
      --End--1009l-36

288] --start--above-1009l-38 Sat Mar 28 19:36:12 IST 2020 VERSION "5.9.2" --by Mayur
         1) Changes for taking Firmware tar md5sum table back on default values on restore.
         2)Chages added for removing normar network back from readNetworkDetailsFromTableAndFillFromFile() function and added backupNetworkDetailsForUpdate() for same.
         3)In ADSJoinOnLogin() function added field for Computer name.
         4) Added function for writing firmware log in file readOrAddFirmwareDetails().
         5) Added function to find bus and port number of mounted device as getMountedDivicePortBusNo().
         6) Added function to take domain credentials backup on restore TC on the default values “EnableDomainBackUp=1”. And aging join ADS in executenetworksettings function after restore.
         7) Added some changes to connect wifi from mobile device, and image up on M75 board.
      --End--1009l-38

289] --start--above-1009l-39 Tue Mar 31 12:35:38 IST 2020 VERSION "5.9.3" --by Mayur
         1) Added condition to take configuration backup in restoreFactorySettings() on files which are writen in VMS when RDC signal is came.
      --End--1009l-39

290] --Start--above-1009l-39 Tue Mar 31 20:32:38 IST 2020 Version "5.9.4" by Mayur
        1) Changes done for reading dafault value which is bymistake read at 1.
--END--1009L-39

291] --Start--above-1009l-43 Mon Apr 13 20:29:37 IST 2020 Version "5.9.5" by Jignesh
        1) Bug Resolved :- Firmware update not working throw Global access LTM server.
           ISSUE:-nslookup cmd not giving proper output(server certificate bound url) for Global access LTM server url.
--END--1009L-43

292] --Start--above-1009l-50 Mon Mon Apr 27 13:13:01 IST 2020 Version "5.9.6" by Kunal
         --Changes Done
            1] When we connect VMView blast connection with H264 option check then black screen displays after launching any desktop.
--END--1009L-50

293] --Start--above-1009l-50 Mon Apr 27 19:52:38 IST 2020 Version "5.9.7" by Kunal
         --Changes Done
            1] When we connect VMView blast connection with H264 option check then black screen displays after launching any desktop.
--END--1009L-50

294] --Start--above-1009l-52 Thu Apr 30 12:46:09 IST 2020 Version "5.9.8" by Khemraj
            1] ftps repository not wroking,
            --Changes Done - changes in Doenload file function
--END--1009L-52

295] --Start--above-1009l-53 Tue May  5 16:34:45 IST 2020 Version "5.9.9" by Khemraj
            1] ftps repository not wroking,
            --Changes Done - changes in Doenload file function and Uploadfile
--END--1009L-53
--End--64x1009-0.4.3

296] --Start--above-64x1009-0.4.3 Thu May 14 17:30:52 IST 2020 "6.0.6" by Prajakta
         1] changes to Compare QString with Database Value
     --End--1009x64-0.4.3

297] --Start--above-64x1009-0.4.6 Fri May 15 15:29:31 IST 2020 Version "6.0.7" by Mayur
         1) Changes done in ChangeResolutionInDB() function as in headless mode resolution get blank.
     --End--1009x64-0.4.6

297] -- Start--above-1009-0.4.6 Fri May 15 18:34:40 IST 2020 Version "6.0.8" by Namrata
        solved issue :
        When we check and uncheck sleep option from shutdwon procedure and user Interface(Desktop mode) ,then black window blink at blackground
    -End--64x1009-0.4.6

298] -- Start--above-1009-0.4.7 Mon May 18 19:37:24 IST 2020 Version "6.0.9" by Namrata
        solved issue :
   1]  Resolved 802 PEAP TLS connectivity issue.
   -End--64x1009-0.4.7

299] -- Start--above-1009-0.5.1 Mon May 25 17:00:49 IST 2020 Version "6.1.0" by Namrata
        1)solved bug :
    "Fonts module gets crash when click on apply without giving url
    -End--64x1009-0.5.2

300] -- Start--above-1009-0.5.2  Tue May 26 15:43:35 IST 2020 Version "6.1.1" by Namrata
        1)solved bug :
        In wpasupplicant.conf file in 802security network case encrypted password is writen in file.
        as wrong number values is used.
    -End--64x1009-0.5.3

301] -- Start--above-1011 Fri May 29 20:03:22 IST 2020Version "6.1.2" by Kunal
        1] New implemetation for to show osversion for ImpactOS.
      -End--64x1011

302]  -- Start--above-1012 Mon Jun  1 21:10:08 IST 2020  Version "6.1.3" by Varsha
       changes as LEpassword text was not reflecting properrrrly in lockscreen so changes in setPlaceholderText() function.
      -End--64x1011

303] -- Start--above-64x1009-1028 Mon Jul 27 14:13:12 IST 2020 VERSION "6.1.4" --by prajakta
        1] Implementation For Autogenerated Hostname for Impact by writting getHostnameForImpact() function to generate hostname.
    --End--64x1009-1028

304] -- Start--above-64x1009-1030 Thu Jul 30 12:32:00 IST 2020 Version "6.1.5" by Jignesh
       --Changes Done
          In dhclient cmd commented because '-r' option releases lease file so we have used '-x' option instead of that.
          This issue occurred in Keck Medicine where third party multiple dhcp servers ware available and every network apply it was changing the ip address.
     --End--64x1009-1030

305]-- Start--above-64x1009-1028 Mon Jul 30 15:38:20 IST 2020 VERSION "6.1.6" --by Varsha
     In Applications chinese,german , spanish  language, for data card ,file manager ,web cam
      --End--64x1009-1028

306] -- Start--above-64x1009-1032 Fri Jul 31 19:02:00 IST 2020 VERSION "6.1.7" --by Varsha
      1.When we create/delete any connection ,then xkill gets perform
      2.When we create any connection then connection gets launch and control center displays infront of the connection.
      3.When we create any connection then on confirmation window, cursor gets auto switch from yes to no button.
    --End--64x1009-1031

307]-- Start--above-64x1036 Fri Aug  7 16:25:42 IST 2020 VERSION "6.1.8" --by Prajakta
      1] On some TC, Image gets up with hostname which is ITL + Serial Number And On 3-4 devices, Image gets up with hostname which is ITL + MAC but when I change it to Serial number and again switch to auto generated without closing module window, then hostname is displayed as ITL + Serial number.
      --End--64x1036

308] -- Start--above x64-006-1040-0.0.3 Mon Sep  7 12:23:41 IST 2020 "6.1.9" by Bhushan
       1)for 14W laptop,put condition that communication should always happen with wireless mac address.
       End - x64-006-1040-0.0.3

309] -- Start--above-64x-1040-0.0.4 Mon Sep  7 12:18:36 IST 2020 VERSION "6.2.0" --by Namrata
        1) Did citrix optimization Implemention:
          -Added Optimization tab  in PNAgentGlobal which contain 5 checkbox.
            Check boxes
            1) Microsoft Teams
            2) Skype for Business (RTME)
            3) Zoom
            4) WebEx
            5) Cisco JVDI (need to remove from Services)
            Write module.ini file for above option as per there values.

           2]Write default values for above 5 checkboxes in PNAgentGlobal table.
 --End--64x-1040-0.0.4

310]-- Start--above-64x-1040-0.0.5 Tue Sep  8 15:13:50 IST 2020 VERSION "6.2.1" --by Namrata[ Merged From OSD-2.0.46-PostRelease ]

        303]  -- Start--above-1018-0.0.0 Wed Jun 10 10:30:47 IST 2020 Version "6.1.4" by Jignesh
                Added function to Store Log value with Start time and End time.
              -End--1018-0.0.0

        304] - Start--above-1018-0.0.0 Thu Jun 11 11:02:09 IST 2020 Version "6.1.5" by Varsha
                Done changes for the implementation of saving Application logs in database LogsTable.
              -End--1018-0.0.0

        305] - Start--above-1018-0.0.0 Thu Jun 11 16:02:09 IST 2020 Version "6.1.6" by Namrata
               Added Function readLogsTableWritteAfterExtract(bool) to preservd Logstable while importing settings.
              -End--1018-0.0.0

        306] - Start--above-1018-0.0.0 Thu Jun 30 15:15:09 IST 2020 Version "6.1.7" by Prajakta
               Added Function cleanUpLogs() To write cleanuplogs in file /var/logs/cleanup.log.
              -End--1018-0.0.0

        307] - Start--above-1018-0.0.0 Thu Jun 30 15:15:09 IST 2020 Version "6.1.8" by Prajakta
               Changed Filename in defineslcore.h file /var/logs/cleanup.log.
              -End--1018-0.0.0
--End--64x-1040-0.0.5

311] --Start--above-64x1040-0.0.4 Thu Sep 10 16:15:35 IST 2020  Version "6.2.2" by Prajakta [Merged from OSD-2.0.46-PostRelease]
      306] - Start--above-1018-0.0.0 Thu Jun 30 15:15:09 IST 2020 Version "6.1.7" by Prajakta
            Added Function cleanUpLogs() To write cleanuplogs in file /var/logs/cleanup.log.
           -End--1018-0.0.0
     307] - Start--above-1018-0.0.0 Thu Jun 30 15:15:09 IST 2020 Version "6.1.8" by Prajakta
           Changed Filename in defineslcore.h file /var/logs/cleanup.log.
         -End--1018-0.0.0
    --End--64x1040-0.0.4

312]-- Start--above-64x-1040-0.0.5 Mon Sep  14 15:13:50 IST 2020 VERSION "6.2." --by Namrata[ Merged From OSD-2.0.46-PostRelease ]
    308]-- Start--above-64x1040C-1 Wed Aug 26 17:56:13 IST 2020 VERSION "6.1.9" --by Namrata
          1] Did changes for Multiple printer Redirection issue in Citrix changes .

      Solution : As Given by prashant sir
         In order to map multiple printers in Citrix session,we need to modify below option in wfclient.ini
         ClientPrinterList=Printer1;wd=Citrix Universal Printer:Printer2;wd=Driver Name:
         wd, is the window driver name.
         No, need to write DefaultPrinterDriver
          --End--64x1040C-1

    309]-- Start--above-64x1040C-1 Thu Aug 27 17:35:04 IST 2020 VERSION "6.2.0" --by Namrata
          1] solved issue
             On Maimonides build, multiple printer redirection is working in Citrix session, but when we delete any printer
             locally then other printers also fails to redirect in session.
         --End--64x1040C-1
--End--64x1040-0.0.4-

--Start--above-x64-1040.0.0.5 Mon Sep 14 15:53:22 IST 2020 VERSION "6.2.3" by Bhushan marged from wychavon.
    309]   --Start--above-x64-1040E-1 Thu Sep 10 19:02:44 IST 2020 VERSION "6.2.0" by Bhushan.
        1) modify getHWdata() function for hardisk detailes.
    -End--x64-006-1040E-1
-End--x64-1040.0.0.5

--Start--above-x64-1040.0.0.5 Thu Sep 17 13:18:43 IST 2020 VERSION "6.2.4" by Bhushan marged from wychavon.
        1) modify getHWdata() function for hardisk detailes for multiple keyboards.
-End--x64-1040.0.0.5

313]-- Start--above-64x-1040-0.0.6 Tue Sep 29 13:58:34 IST 2020 VERSION "6.2.5" --by Prajakta[ Merged From  OSD-2.1.x64-006-1040H-BIOSConfiguration]
      308] --Start--above-x64-1009H-1  Fri Sep 18 12:42:41 IST 2020 VERSION "6.1.9" --by Prajakta
        1] Changes Done to show BootSequence on UI Based on the BootMode present in /BootPriority file.
      --END--above-x64-1009H-1

      309] --Start--above-x64-1009H-1  Fri Sep 25 10:55:21 IST 2020 VERSION "6.2.0" --by Prajakta
        1] excute /usr/sbin/lshw in 64 bit machine and /usr/os-bin/lshw in 32-machine
      --END--above-x64-1009H-1
--End--64x1040-0.0.6

314]-- Start--above-64x-1040-0.0.6 Wed Sep 30 16:47:27 IST 2020 VERSION "6.2.6" --by Prajakta
      1] CiscoMeetingsVirtualChannel=On/Off parameter wriiten in module.ini file for enabling/disabling the cisco webx in Citrix.
--End--64x1040-0.0.6

315]-- Start--above-64x-1040-0.1.1 Tue Nov 10 16:09:21 IST 2020 VERSION "6.2.7" --by Kunal [Merge from 1040B-Valeo Rev No 9935,9976 ,9987]
    308] -- Start--above-64x-1040B-2  Wed Sep  9 18:15:28 IST 2020 Version "6.1.9" by Namrata
     1] solved issue :
       if we use Chinese characters in connection name and set connection on start then local login window
       (with VPN) or "Server is not reachable/invalid" message (without VPN) fails to display after boot
   -End---64x-1040B-2

	309] -- Start--above-64x1040B-3 Fri Sep 18 16:55:31 IST 2020 VERSION "6.2.0" --by Namrata
        1] .If we use Chinese character in connection name then in start menu connection name fails to display.
        but when we launch RDWEb or pnagent connection jumk chanracter display
    --End--1040B-3

	310] -- Start--above-64x1040B-3 Fri Sep 25 17:11:23 IST 2020 VERSION "6.2.1" --by Namrata
        1] when we connect Store connection from desktop and in misc connection kept on desktop and on menu then from Satrt menu all option vanishes (on start menu only store connection with its desktop list remains)
        2] when we connect Rdweb without search application from connection manager ,and logoff desktop then all options vanishes from start menu.
    --End--1040B-3
--End--1040-0.1.1 

316]-- Start--above-64x-1040-0.1.1 Tue Nov 10 16:09:21 IST 2020 VERSION "6.2.8" --by Varsha [Merge from 1040C-Maimonides Rev No 10087]
    310]-- Start--above-64x1040C-3 Tue Nov 3 17:35:04 IST 2020 VERSION "6.2.1" --by Varsha
      1] solved issue
            For SAMBA pprinters if  we pass special symbols like "@ and "%" in password than printer fails to configured.
     --End--64x1040C-3
--End--1040-0.1.1

317]-- Start--above-64x-1040-0.1.2 Wed Nov 11 16:09:21 IST 2020 VERSION "6.2.9" --by Sarang
        Replace the Changes of fusionms to webias with checking condition of impact.
--End--1040-0.1.2


29]--Start--above-64x1040-0.1.1  Thu Nov 12 10:26:49 IST 2020 Version "6.3.1" by Prajakta [merge from 1040A-Impact]
   309]   --Start--above-x64-1040E-1 Thu Sep 10 19:02:44 IST 2020 VERSION "6.2.0" by Bhushan.
       1) modify getHWdata() function for hardisk detailes.
   -End--x64-006-1040E-1
   310} --Start--above-x64-1040E-2 Mon Sep 14 18:37:42 IST 2020 VERSION "6.19" by Bhushan.[Merged from wychavon branch by Namrata]
     1) modify getHWdata() function for hardisk detailes.
     While executing lshw command set enviromentvariable LC_ALL= english because in french its giving output in french.
   -End--x64-006-1040E-2
   311] -- Start--above-64x1040A-12 Sun Nov  8 14:36:55 IST 2020 VERSION "6.2.1" --by Prajakta
       1] Did Changes to write writeAppliDisConfigFile() in /tmp/connectionname.xml file to launch FreeRDP AppliDis.
      --End--64x1040A-12
    --End--1040-0.1.1

318] -- Start--above-64x1040-1029 Thr Nov  12 14:36:55 IST 2020 VERSION "2.2.7" --by Varsha [Merged from Memonides]
        -- Start--above-x64-1040C-6 Fri Nov 13 20:44:01 IST 2020 VERSION "6.2.2" --by Varsha
        1.For SAMBA pprinters if  we pass special symbols like "/" in password than printer fails to configured.
        2.Credential window appears when print is taken from  SAMB printer .
        3.Modify /root/.sshow file from Screensaver for if audio is running, screensaver will not appear
        --End--64x1040C-6
   -- End--1060-1029

319] --Start--above-64x1040-0.1.3  Thu Nov 19 13:50:53 IST 2020 Version "6.3.2" by Sahil [merge from 1040L-Mackenzie]
       308] -- Start--above-x64-1040L Fri Nov  6 20:44:01 IST 2020 VERSION "6.1.9" --by Sahil
        1] Changed checkforLaptop Function to check for BAT in /sys/class/power_supply.
        2] Changed to use checkForlaptop Function instead of acpi command.
    --End--64x1040L
    --End--1040-0.1.3

320] --Start--above-64x1040-0.1.3 Thu Nov 19 17:31:28 IST 2020 Version "6.3.3" by Kunal [merge from 1040G-ADNOC] [Revision No: 10180,10029,10023]
     308]-- Start--above-64x1040G-1 Mon Oct  5 20:15:09 IST 2020 VERSION "6.1.9" --by Kunal
      1]  Add Option  "AccelMethod"   "glamor" & Option  "TearFree"  "on" lines need to be added in 20-sceen.conf only for "RADEON" driver.
          told by Nikhil sir For ADNOC.
       --End--64x1040G-1

      309]-- Start--above-64x1040G-2 Tue Oct  6 18:49:43 IST 2020 VERSION "6.2.0" --by Kunal
      1]  remove install nouveau /bin/false entry from  blacklist file if drivername contains Nvdia told by Prashant sir For ADNOC.
      --End--64x1040G-2

321]-- Start--above-64x-1040-0.1.5 Fri Nov 27 18:40:21 IST 2020 VERSION "6.3.4" --by Sahil
        1] solved issue:-
            VMware version does not reflect in system information
--End--1040-0.1.5

322]-- Start--above-64x-1040-0.1.6 Fri Dec 01 18:40:21 IST 2020 VERSION "6.3.5" --by Sarang
        1] solved issue:-
            unable to open VMSSeting Module(Segmentationfault).
--End--1040-0.1.6

323]-- Start--above-64x-1040-0.2.2 Wed Dec 30 11:20:21 IST 2020 VERSION "6.3.6" --by Sahil [merge from 1040A-Impact]
        315] --Start--above-x64-1040A-20 Thu Nov 26 12:50:44 IST 2020 VERSION "6.2.5" by Sahil.
            1) Did Changes to write custom writeAppliDisConfigFile() in /tmp/connectionname.xml file to launch FreeRDP AppliDis..
        -End--x64-006-1040A-20
--End--1040-0.2.2

324]-- Start--above-64x-1040-0.2.2 Wed Dec 30 12:20:21 IST 2020 VERSION "6.3.7" --by Prashant [merge from 1040A-Impact]
        316] --Start--above-x64-1040A-24 Mon Dec 28 17:46:45 IST 2020 IST 2020 VERSION "6.2.6" by Prashant.
            1) Did Changes for EyeICON which is present in the password field should not visible if once we save the password and reopen the same tab again in PressPushButton() function.
        -End--x64-006-1040A-24
--End--1040-0.2.2

325]-- Start--above-64x-1040-0.2.3 Mon Jan 11 12:26:58 IST 2021 VERSION "6.3.8" --by Prashant [merge from 1040A-Impact]
        317] --Start--above-x64-1040A-26 Tue Jan  5 12:37:51 IST 2021 VERSION "6.2.7" by Prashant.
            1) EyeICON fails to disable when connection is connect by quickconnection check password and do changes w.r.t in setText and PressPushButton() function.
        -End--x64-006-1040A-26
--End--1040-0.2.3

326]-- Start--above-64x-1040-0.2.3 Mon Jan 11 12:26:58 IST 2021 VERSION "6.3.9" --by Prashant [merge from 1040A-Impact]
        308] --Start--above-1040O- Tue Nov 24 19:37:47 IST 2020 Version "6.1.9" by Prashant
            1] added rfbport command for x11vnc port.
        --END--above-1040O
--End--1040-0.2.3

327] -- Start--above-64x-1040-0.2.3 Mon Jan 11 18:26:58 IST 2021 VERSION "6.4.0" --by Sahil
    1] Removed Modified condition to check package information for new vmware package as issue was with package.
    --End--1040-0.2.3

328] -- Start--above-64x-1040-0.2.4 Thu Jan 14 14:14:17 IST 2021 VERSION "6.4.1" --by Prajakta [Merged From Makenzie]
   309] -- Start--above-64x1040L-3 Thu Nov  19 14:25:01 IST 2020 VERSION "6.2.1" --by Prajakta
      1] Did changes to Fill Default value in VMViewGlobal table as "Info" instead of "Trace" for USB Log level.
      --End--64x1040L-3
   311] --Start--above-x64-1040L-8 Tue Dec  8 20:16:01 IST 2020 VERSION "6.2.3" --by Sarang
        1]Changed Format in function uptime[DD:HH:MM:SS].
       --End--64x1040L-9
  --End--1040-0.2.4

329] -- Start--above-64x-1040-0.2.4 Fri Jan 15 13:34:07 IST 2021 VERSION "6.4.2" --by Prajakta [Merged From Maimonides]
  314] -- Start--above-x64-1040C-9 Thu Nov 26 14:32:52 IST 2020 VERSION "6.2.5" --by Prajakta
       1] Did Changes to write LaunchSelfServiceAfterLogin option Default value in ImprivataGlobal Table.
    --End--64x1040C-9
  315] -- Start--above-x64-1040C-14 Mon Dec 21 17:07:58 IST 2020 VERSION "6.2.6" --by Prajakta
       1] When multiple connections get Launched at the same time in imprivata it shows error messge as module.ini file is not exists.
    --End--64x1040C-14
  316] -- Start--above-x64-Wed Jan 13 17:22:30 IST 2021 VERSION "6.2.7" --by Prajakta
       1] LockScreen option from start menu should be hidden in imprivata.
    --End--64x1040C-17
   --End--1040-0.2.4

330] -- Start--above-64x-1040-0.2.5 Fri Jan 22 13:34:07 IST 2021 VERSION "6.4.3" --by Varsha [Merged From Memonides]

    310] -- Start--above-64x1040C-3 Tue Nov 3 17:35:04 IST 2020 VERSION "6.2.1" --by Varsha
            1] solved issue
            For SAMBA pprinters if  we pass special symbols like "@ and "%" in password than printer fails to configured.
        --End--64x1040C-3

    311] -- Start--above-x64-1040C-6 Fri Nov 13 20:44:01 IST 2020 VERSION "6.2.0" --by Varsha
            1.For SAMBA pprinters if  we pass special symbols like "/" in password than printer fails to configured.
            2.Credential window appears when print is taken from  SAMB printer .
            3.Modify /root/.sshow file from Screensaver for if audio is running, screensaver will not appear
        --End--64x1040C-6

    312] -- Start--above-x64-1040C-7 Fri Nov 20 20:44:01 IST 2020 VERSION "6.2.3" --by Varsha
        1.Modify /root/.sshow  and idle_os file from Screensaver for if audio is running, screensaver will not appear
        --End--64x1040C-7

    313]  -- Start--above-x64-1040C-8 Tue Nov 24 20:44:01 IST 2020  --by Varsha
       1] Changes to check while audio running in background MonitorPowerSettings should not get applied
       2] while taking printer through SAMBA printer Authentication window appears
        --End--64x1040C-8
      --End--1040-0.2.5

331]-- Start--above-64x-1040-0.2.6 Mon Sep 14 15:13:50 IST 2020 VERSION "6.4.4" --by Kunal[ Merged From 1040A-Impact ]
     Add isImpactNotebook() & getImpactNotebook() fun for Impact Notebook requirements.
-End--64x-1040-0.2.6

332]-- Start--above-64x-1040-0.2.7 Fri Mar 12 12:37:19 IST 2021 VERSION "6.4.5" --by Aboli
     RDP ui changed to RDesktop .
-End--64x-1040-0.2.7

333]-- Start--above-64x-1040-0.2.7  Wed Mar 31 13:33:23 IST 2021 VERSION "6.4.6" --by Aboli
     Merege BootSequence changes from x64-006-1040R-BARTS branch .
-End--64x-1040-0.2.8

334] --Start--above-64x1040-0.3.4 Sat Apr 10 17:23:43 IST 2021 Version "6.4.7" by Prajakta--[Merged from Maimonides]
    317] -- Start--above-64x1040C-23 Tue Feb 9 10:32:52 IST 2021 VERSION "6.2.8" --by Prajakta
        1 .when two connection launching simultaneously after disconnecting from TCCenter OS_Desktop and Start Menu all the icons from desktop should get remove
            added function DisconnectAllConnectionFromImprivata();
    --End--64x1040C-23
    317] -- Start--above-64x1040C-24 Tue Mar 2 18:31:43 IST 2021 VERSION "6.2.9" --by Prajakta
        1] Multiple entries of connections are displayed in Start Menu after previous user disconnected issues..Multiple entries of connections are displayed in Start Menu after previous user disconnected issues..
    --End--64x1040C-24
    318] -- Start--above-64x1040C-25 Wed Mar 17 20:10:19 IST 2021 VERSION "6.3.0" --by Prajakta
        1] Icons of Desktops/Applications of previous session are displayed on desktop in case of Proximity Card and Secure Walk Away both..
    --End--64x1040C-25
    318] -- Start--above-64x1040C-25 Wed Mar 17 20:10:19 IST 2021 VERSION "6.3.0" --by Prajakta
        1] Icons of Desktops/Applications of previous session are displayed on desktop in case of Proximity Card and Secure Walk Away both..
    --End--64x1040C-25
    319] -- Start--above-64x1040C-28 Wed Mar 31 17:25:19 IST 2021 VERSION "6.3.1" --by Sahil
        1] If we switch users in open session, then Desktops and Applications for both users are displayed in Connection Manager.
    --End--64x1040C-28
  --End--64x1040-0.3.4

335]  --Start--above-2.1x64-0.3.4 Mon Apr 12 13:16:26 IST 2021 Version "6.4.8" by Sahil merge from [Impact]
        318] --Start--above-64x1040A-32 Wed Jan 20 16:18:01 IST 2021  Version  "6.2.8" by Sahil.
            1) Made changes to write values in wfclient.ini file for New implemention of PhilipsSpeech.
        -End--x64-006-1040A-32
--End--64x1040-0.3.4

336]  --Start--above-2.1x64-0.3.4 Mon Apr 12 16:16:26 IST 2021 Version "6.4.9" by Sahil merge from [INCOMINTER]
    312] --Start--above-x64-1040S-0 Wed Jan 27 19:06:00 IST 2021 VERSION "6.2.3" by Sahil.
            1] Removed ccpd/fifo implementation for Canon printers.
    -End--x64-006-1040S-0

    313] --Start--above-x64-1040S-1 Tue Feb 23 11:20:00 IST 2021 VERSION "6.2.4" by Sahil.
            1] Did Changes in lcore.h to list Down the Device uir for Custom Url in Printer.
    -End--x64-006-1040S-1

    314] --Start--above-x64-1040S-2 Tue Feb 23 20:50:00 IST 2021 VERSION "6.2.5" by Sahil.
            1] Solved issue where list of the Device uir where not proper for Custom Url in Printer.
    -End--x64-006-1040S-2

    315] --Start--above-x64-1040S-5 Mon Mar 1 18:45:00 IST 2021 VERSION "6.2.6" by Sahil.
            1] Did Changes in lcore.h for list down make and model of Printer for Custom Url in Printer.
    -End--x64-006-1040S-5

337]  --Start--above-2.1x64-0.3.4 Thu Apr 15 12:01:47 IST 2021 Version "6.5.0" by Aboli
            1] In TCName settings domain field content changes from domain to DNS IP after Reboot/Shutdown .
      --End--64x1040-0.3.4

338] --Start--above-64x1040-0.3.8 Tue Apr 20 17:53:08 IST 2021 Version "6.5.1" by Prajakta
        1] Written strFrequency in /etc/wpa_supplicat/wpa_supplicat.conf file in case of 802SecurityNetwork when we set TLS for Wireless.
    --End--64x1040-0.3.8

339] --Start--above-64x1040-0.3.8 Fri Apr 23 18:39:25 IST 2021 Version "6.5.2" by Manoj
        1] When we press the Alt+up keys and Alt+Down keys then brightness incress  and decress
    --End--64x1040-0.3.8

340] --Start--above-64x1040-0.3.8 Fri Apr 30 18:15:58 IST 2021 Version "6.5.3" by Prashant
        1] Add 82N8 & 82N9  series in isL14W() & checkForLenovoValidBoards() function.
    --End--64x1040-0.3.8

341]--Start--above-64x1040-0.4.0 Mon May 10 13:36:43 IST 2021 Version "6.5.4" by Aboli
        1] In TCName settings domain field content changes from domain to DNS IP after Reboot/Shutdown .
    --End--64x1040-0.4.0

342]--Start--above-64x1040-0.4.0 Mon May 10 13:36:43 IST 2021 Version "6.5.5" by Aboli
        1] BIOS Configuration changes for L14.
    --End--64x1040-0.4.0

343]--Start--above-64x1040-0.4.5 Thu May 13 15:36:43 IST 2021 Version "6.5.6" by Sahil
        1] Bug Resolved:- In services module,Cisco-Jvdi service is in running state(When it is unchekced.
    --End--64x1040-0.4.5
344] --Start--above-64x1040-0.4.8 Thu May 20 14:48:32 IST 2021 IST 2021 Version "6.5.7" by Manoj
        1] Key => key in changes capital key to small key
    --End--64x1040-0.4.8

345] --Start--above-64x1040-0.4.8 Thu May 20 17:48:32 IST 2021 IST 2021 Version "6.5.8" by Sahil
        1] Bug Resolved:- screen saver of slide show fails to work it remain on black screen need to preview it first then it plays
    --End--64x1040-0.4.8

346] --Start--above-64x1040-0.5.0 Thu May 20 17:48:32 IST 2021 IST 2021 Version "6.5.9" by Sahil
        1] Did changes in ScreenSaver function for SSHOW file to handle "\" for Screen Saver.
    --End--64x1040-0.5.0

347] --Start--above-64x1040-0.5.0 Thu May 24 15:28:02 IST 2021 IST 2021 Version "6.6.0" by Prashant
        1] Did changes in getUrlDataSeperatly function to seperate url when two "@" are thier.
    --End--64x1040-0.5.0

348] --Start--above-64x1040-0.5.0 Wed May 26 10:36:34 IST 2021 Version "6.6.1" by Aarti
        PNAgent : Error launching session:ServerLaunchFailure[0] (blue color in Error mesaage title bar)
    --End--64x1040-0.5.0

349]--Start--above-64x1040-0.5.0 Mon May 31 14:25:29 IST 2021 Version "6.6.2" by Aboli
        1] BIOS Configuration changes for L14.
    --End--64x1040-0.5.0

350]--Start--above-64x1043 Mon Jun 14 13:10:29 IST 2021 Version "6.6.3" by Sahil/Prajakta
        1]Application settings are get reset after full OS upgrade patch.
    --End--64x1043

351]--Start--above-64x1045 Thu Jun 24 16:10:29 IST 2021 Version "6.6.4" by Sahil
        1]Added changes for checking pulse audio in use or not in screensaver scripts
    --End--64x1045

352]--Start--above-64x1045 Thu Jun 24 18:10:29 IST 2021 Version "6.6.5" by Sahil/Nikhil sir
        1] SSID with any character will be connected
    --End--64x1045

353]--Start--above-64x1050 Fri Jul 16 19:44:29 IST 2021 Version "6.6.6" by Sahil/Nikhil sir
        1]Modified path of module.ini.
    --End--64x1050

354]--Start--above-64x1054 Mon Aug 02 12:21:29 IST 2021 Version "6.6.7" by Sahil/Nikhil sir
        1]New printer logic is implemented.
    --End--64x1054

355]  --Start--above-64x1056 Wed Aug  11 16:07:15 IST 2021 Version "6.6.8" by Prajakta
        1] commented getIPFromHostName() called to get serverIp because SMB/NFS doesn't get mount.
   --End--6

356] --Start--above-64x1056 Wed Aug  11 16:07:15 IST 2021 Version "6.6.9" by Prajakta
        1]commented getIPFromHostName() called to get serverIp because SMB/NFS doesn't get mount.
    --End--64x1056

357] --Start--above-64x1062 Tue Aug 24 13:30:15 IST 2021 Version "6.7.0" by Sahil
       Bug Resolved:- 1)Added changes related to WiFi WEP Security issue by applying patches provided by Mr. Nikhil sir.
    --End--64x1062

358] --Start--above-64x1067 Fri Sep 17 22:04:47 IST 2021 Version "6.7.1" by Prajakta
       1] Did changes to convert hardware into Impact Technologies based on default value ImpactManufacturer=1.
    --End--64x1067

359] --Start--above-64x1070 Mon Oct 25 14:06:19 IST 2021 Version "6.7.2" by Prajakta
       1] Did changes to make CloseWdwOnSessionEnd character 'C' to small 'c'.
    --End--64x1070


358] --Start--above-64x1079 Wed Dec 15 16:37:59 IST 2021  Version "6.7.3" by Prajakta
        1] Did changes to write ShadowPrimary=off in "/usr/share/X11/xorg.conf.d/20-screen.conf" this file.
           used ShadowPrimaryOff=1 default value to write in file.
    --End--64x1079

359] --Start--above-64x1082 Fri Jan 28 11:40:44 IST 2022  Version "6.7.4" by Prajakta Merged from 64x1066B
    359] --Start--above-64x1066B-0.0.4 Mon Nov 22 16:51:21 IST 2021  Version "6.7.4" by Prajakta
        1] Did changes to execute commands to connect 4 display in extended and clone mode properly.
    --End--64x1066B-0.0.4
    --End--64x1082

360] --Start--above-64x1082 Fri Jan 28 11:40:44 IST 2022  Version "6.7.5" by Sahil
        1] Resloved issue related to touchScreen for impact.
        2] Added Changes related to Listing direct printer in Custom URL.
     --End--64x1082

361]--Start--above-64x1083 Mon Feb 14 13:18:46 IST 2022  Version "6.7.6" by Prajakta
    --Start--above-64x1066B-0.0.0 Thu Sep 16 11:06:43 IST 2021 Version "6.7.1" by Prajakta -- merging from Masraf_Bank
    308]-- Start--above-64x1040N-1 Mon Nov 23 11:39:01 IST 2020 VERSION "6.1.9" --by Kunal
        1] Show Imprivata  in authentication using ImprivataOS=1 and mac id start with 006072.
        2] Show Imprivata  in authentication using ImprivataCloudDesktop=1 for cloud desktop.
       -End--64x1040N-1
    --End--64x1066B-0.0.0
     --End--64x1083

362]--Start--above-64x1085 Wed Feb 16 18:18:46 IST 2022  Version "6.7.7" by Sahil
     1]Did changes to VM Shutdown value as desktoptimout in config.xml
     --End--64x1085

363]--Start--above-64x1085 Wed Feb 16 18:18:46 IST 2022  Version "6.7.8" by Sahil
     1]Did changes to make desktopTimout character 't' to small 'T'.
     --End--64x1085
364]--Start--above-64x1089 Thu Feb 24 14:56:59 IST 2022 Version "6.7.9" by Namrata
        1] Added Some Missing Changes.
    --End--64x1089

365]--Start--above-64x1090 Mon Feb 28 10:00:03 IST 2022 Version "6.7.10" by Prajakta
        1]In Display module, Resolution and Rotation fails to set ( But Settings applied successfully message is displayed ), And Settings gets applied after normal boot.
    --End--64x1090

366]--Start--above-64x1092  Thu Mar 10 14:14:44 IST 2022 Version "6.8.0" by Namrata
        1]"KeyPassthroughEscapeShift"
          "KeyPassthroughEscapeChar"
          updated these parameter value on the basis on combobox value given in CitrixGlobal, value svae in ICAGlobal Table.
    --End--64x1092

367]--Start--above-64x1093 Wed Mar 16 17:14:44 IST 2022 Version "6.8.1" by Sahil
        1] Did changes to write path as /usr/local/bin instead of /usr/bin in config.xml file for AppliDis.
    --End--64x1093

368]--Start--above-64x1094 Wed Mar 26 19:14:44 IST 2022 Version "6.8.2" by Sahil
        1] Bug Resolved:- After applying upgrade patch through FirmwareUpdate Display Resolution was getting set as highest resolution.
    --End--64x1093

369]--Start--above-64x1099 Tue Apr 05 18:14:44 IST 2022 Version "6.8.3" by Sahil
        1] Did changes to pass "/" at end of /usr/local/bin .
        2] Did changes to not pass "desktoptimeout" parameter when VMshutdown is unchecked.
    --End--64x1099

370]--Start--above-64x1102 Thu Apr 07 16:14:44 IST 2022 Version "6.8.4" by Sahil
        1]Bug resolved:- After Applying dual Display settings dual display fails to work.
    --End--64x1102

371]--Start--above-64x1103 Fri Apr 08 16:14:44 IST 2022 Version "6.8.5" by Sahil
        1]Bug resolved:- After Applying dual Display settings dual display fails to work.
    --End--64x1103
371]--Start--above-64x1105 Tue Apr 12 15:27:11 IST 2022 Version "6.8.6" by Namrata
        1]Bug resolved:-In SystemInfo VMView Version not showing Properly.
    --End--64x1105
372]--Start--above-64x1105 Wed Apr 13 22:24:37 IST 2022 Version "6.8.7" by Namrata
        1]Bug resolved:-In Imprivata  VMware connection with RDP Protocol fails to launch, due to /vc:vchanimp paramerter, in new freerdp package
        need to create link at new path = /usr/local/lib/freerdp3/
        "ln", QStringList() << "-s" << "/usr/os-bin/libvchanimpclient.so" << "/usr/local/lib/freerdp3/libvchanimp-client.so");
    --End--64x1105
373]--Start--above-64x1113 Thu May 19 12:45:52 IST 2022 Version "6.8.8" by Namrata
        1]Bug resolved:-In Multidisplay when we set 2/1 potision and set scree2 as primary screen in exented
                        mode but after reboot it up into clone mode.
    --End--64x1113

374]--Start--above-64x1114 Tue May 24 12:50:52 IST 2022 Version "6.8.9" by Snehal
        1]Added Changes to SetMaxLength() for Connection Name field, added microfunction "#define LEMAXLENGTH 200"
    --End--64x1114

375]--Start--above-64x1116 Wed Jun 01 11:20:52 IST 2022 Version "6.9.0" by Sahil
        1] Resolved :- Logout on all apps/desktop gets closed in imprivata
    --End--64x1116

376]--Start--above-64x1118 Wed Jun 06 12:20:52 IST 2022 Version "6.9.1" by Namrata
        1] Resolved :- Did changes in isImprivataLogout function for Count checkig for PNAgent Table,
            After logged in with Imprivata, when we sign out the desktop of VMWare session then auto logout fails to perform..
    --End--64x1118

377]--Start--above-64x1128 Fri Jun 17 11:13:49 IST 2022 Version "6.9.20" by Namrata
Did Changes for Dominose  in defaultvalues EnableDMN=1
Did changes to set Timezone for dominose.
 Time zone should be Asia- Kolkata
 --End--64x1128

378]--Start--above-64x1130 Thu Aug 11 17:13:49 IST 2022 Version "6.9.3" by Sahil
          1]Changed path of ALLREGIONINIFILE from /root/.ICAClient/All_Regions.ini to /etc/icaclient/config/All_Regions.ini
 --End--64x1130
379] -- Start--above-64x1134 Wed Aug 24 14:53:02 IST 2022 Version "6.9.4" by Namrata
        1] did some changes in isEfiImage() function  releted to EFI lable.
     --End--64x1134
380]--Start--above-64x1136 Wed Sep 14 11:35:06 IST 2022 Version "6.9.5" by Namrata
      Done changes for IPV6 is Disable on boards so its giving only one count..
     so changed the condition for Wifi.(change count condition)
    --End--64x1136
381]--Start--above-64x1136 Mon Sep 26 12:35:10 IST 2022 Version "6.9.6" by Namrata
     1]Added condition in ModifyXorgFileForScreen() to check two VGACARD entrise 15e7 and Barcelo for amdgpu driver
    --End--64x1136
382]--Start--above-64x1141 Fri Oct 07 19:35:10 IST 2022 Version "6.9.7" by Snehal
     1]Added changes for Dual ethernet.
    --End--64x1131

383]--Start--above-64x1141 Wed Oct 12 19:35:10 IST 2022 Version "6.9.8" by Sahil
        1] Added changes/modified in getResolutionList() ExecuteSecondDisplaySettings() getDisplayDevice() for multipledisplay.
        2] Added entries of Mointor 3 and Monitor 4 in ModifyXorgFileForScreenOLD().
    --End--64x1131

382]--Start--above-64x1147 Thu Oct 20 17:58:59 IST 2022 Version "6.9.9" by Sahil
        1] Added Changes for icon in modifyStartup and modifyDesktop for Microsoft Edge Browser.
    --End--64x1147

383]--Start--above-64x1147 Fri Oct 20 17:58:59 IST 2022 Version "7.0.0" by Sahil
        1] Added changes to get domainlist as per new script.
    --End--64x1147

384]--Start--above-64x1149 Tue Nov 01 13:22:34 IST 2022 Version "7.0.1" by Sahil
        1]Bug Resolved:- sleep command is changed and now passed as "::sleep()"
      -End--64x1149

385]--Start--above-64x1151 Mon Nov  7 17:36:19 IST 2022 Version "7.0.2" by Namrata
        1] when full credentials(username, Password, domain) are given in freerdp applidis of SSO is checked the added <modeConsole>1</modeConsole>
           under <system> tag in xml file.
        2] Deactivated the power management for Wifi.
      -End--64x1151
380] -- Start--above-64x1155 Mon Nov 21 16:09:44 IST 2022 Version "7.0.3" by Namrata
        1] Did changes in encryptDecryptString() function, call AESLibrary Function,
           to encrypt and decrypt Password
        2]AES releted .CPP .h files added in LCore.
     --End--64x1155
380] -- Start--above-64x1156 Tue Nov 22 16:09:44 IST 2022 Version "7.0.4" by Namrata
        1]copied "/root/multipleDisplay.sh" to "/opt/multipleDisplay.sh"
        2] Added two events in /etc/acpi/events/lid-open and /etc/acpi/events/lid-close in os-bin-base.sq
     --End--64x1156
380] -- Start--above-64x1157 Tue Nov 29 15:50:44 IST 2022 Version "7.0.5" by Namrata
        1]Added Encryption Changes on default Values PWDConvert=1 it will Convert Password With AES Encryption,
          PWDConvert=0  it will Convert Password with old logic.
          If PWDConvert=0 not Exist in file then it convert Password with old logic.
     --End--64x1157

381] -- Start--above-64x1158 Thusrday Dec 15 16:50:44 IST 2022 Version "7.0.6" by Snehal
        1]Added fucntions saveVMSSettingsFromFDMFile() and saveVMSSettingsFromDHCPParams() for Impact Group Inheritance Issue.
     --End--64x1158
382]--Start--above-64x1159 Mon Dec 26 15:55:57 IST 2022 Version "7.0.7" by Namrata
        1]In Dual Display on laptop when lid open and lid close acpi events get called from  /etc/acpi/event/lid-open and /etc/acpi/event/lid-close.
         we pass two argument from acpi event script to OS_Desktop to set proper Background Image.
        2]Execute "/usr/os-bin/enable_touchscreen" script for issue Touchscree fails to work in dusla display scenerion.
      -End--64x1159

383]--Start--above-64x1167  Mon Jan 30 16:19:46 IST 2023 Version "7.0.8" by Namrata
   1] Resolved License Issue : After Activating License from windows, Allowlicense=1,ETYBHGtvsasaj=(encrypted mac),
so did proper section while reding Value from /sda1/data/FDMClientDetails.
    --End--64x1167

384]--Start--above-64x1167  Mon Feb 20 18:27:11 IST 2023 Version "7.0.9" by Namrata
   1] Added NetworkButton Related entry in ImprivataGlobal Table.
    --End--64x1167
385] --Start--above-64x1072 Wed Apr 05 16:26:41 IST 2023  Version "7.1.0" by Namrata
        1] DId changes to remove "iptable -F" command from ExecutteFirewallsetting() as told by mr.prashant pokhriyal sir
    --End--64x1072
386] -- Start--above-64x1183 Wed May 31 15:11:28 IST 2023 Version "7.1.1" by Namrata
       Did changes in ScreenSaver Function to write /root/.ssaver file, for issue When we set ScreenSaver and LockScreen Desktop get Display.
     --End--64x1183
387] --Start--above-64x1184 Wed Jun 14 16:08:20 IST 2023  Version "7.1.2" by Namrata
        1] Did changes for Launch application connection by myuser, some file path are changes.
    --End--64x1184
388] --Start--above-64x1190 Mon Aug 28 11:19:47 IST 2023 Version "7.1.3" by Namrata
        1] Did Changes to add UDM Rules for PNAgent, CONNECT Entry in usb.conf file.
    --End--64x1190

389] --Start--above-64x1191 Tue Sep 12 14:24:47 IST 2023 Version "7.1.4" by Namrata
    1]  One Issue reported by deligenta releted to Firmware upgrade failed to updata,
    2]  We are passing hostname and below command nslookup command retriving ip from it trying to download tar from ip.
    3]  They had block  downloading from IP address from there enviroment, due to this firmware failed to upgrad.
    4]  Through hostname tar is properly getting downloaded
    5]  so put nslookup condition on DefaultValues
--End--64x1191

390] --Start--above-64x1192 Thu Sep 14 11:46:48 IST 2023 Version "7.1.5" by Namrata
        1] #define NEWOSBUILDFILE "/sda1/data/.osbuild-new" added this changes to read OSBuild from new file if exist otherwise it will show old osbuild changes.
    --End--64x1192

391] --Start--above-64x1196  Tuesday 23 July 2024 11:23:03 AM IST  Version "7.1.6" by Namrata
        1]Bug Resolved:- When we launch VMWare session and logout it through walkaway somtimes it fails to logout.
           solution :
            1] Added Debugs In this Function liblcore.sendMessageToTCCenter("/tmp/OSSigHandler", "logout");
            2] Added Debugs on Default Value "EnableImprivataLogs=1"
    --End--64x1196

392] --Start--above-64x1196 Wed Aug 28 12:57:30 IST 2024 Version "7.1.7" by Namrata
        1] Did changes to start Block_Clipboard service, which is required for Generic Setting misc option Disable Clipboard.
    --End--64x1196

393] --Start--above-64x1196 Friday September 06 17:57:30 IST 2024 Version "7.1.8" by Snehal
        1] Rename OS_Manufacturer to "Sundyne".
    --End--64x1196
394] --Start--above-64x1196  Tuesday 06 SEP 2024 11:23:03 AM IST  Version "7.1.9" by Namrata
        Implemented LDAP Changes-
        1] Older LDAP function was deprecated so used newer fuction of ldap library
        2] From TestJoin in  authentication used LDAP_AUTH_NONE authentication method. and login window used LDAP_SASL_SIMPLE when we authenticate from login window.
        3] check with online test server , server=ldap.forumsys.com  , base =cn=read-only-admin,dc=example,dc=com, user=newton, password=password
        server url : https://www.forumsys.com/2022/05/10/online-ldap-test-server/
    --End--64x1196.1

395] --Start--above-64x1197 Friday September 13 17:57:30 IST 2024 Version "7.2.0" by Snehal
        1] Updated the LICENSESERVERPATH to https://license.sundynetech.com/licenseserver/.
    --End--64x1197

396] --Start--above-64x1200 Wed Oct 9 17:57:30 IST 2024 Version "7.2.1" by Namrata
        1]  DiD changes by LDap Authentication -by  nikhil sir
    --End--64x1200

397] --Start--above-64x1204 Mon Oct 14 11:32:50 IST 20224 Version "7.2.2" by Namrata
        1] Resolved issue- Waking up screensaver on login screen, Login window gets disable and Control Center icon display at top left corner on the screen in desktop mode
Note : On resume display logon password checkbox is check.
    --End--64x1204
398] --Start--above-64x1204 Mon Oct 14 11:32:50 IST 20224 Version "7.2.3" by Namrata
        1] Resolved issue-Authentication module---> Unable to set Admin User as default User with Change Admin Password settings
    (On Applying, system fails to show dialog box)
     Function has return type and didnt return any value so it was crashing at runtime.
    --End--64x1204
399] --Start--above-64x1204 Wed Oct 23 11:32:50 IST 20224 Version "7.2.4" by Namrata
        1] Did Changes in getPkgVersion()  function Replace "-" with "_" to get pkgs version as told by satish sir for TCS Image
    --End--64x1204
400] --Start--above-64x1204 Wed Oct 24 11:32:50 IST 20224 Version "7.2.5" by Namrata
        1] Did changes in setDateTime function, hwclock date format is change.
        Resolved issue manual Date Time Failed to set.
    --End--64x1204
401] --Start--above-64x1206  Thu Oct 24 11:28:10 IST 2024 "7.2.6" by Namrata
         1] Commented Changes to write in blacklist.conf file.
         Resolved Issue :  on changing display resolution to any e.g.1920*1080 (Note here mulitple resolution list is avaliable) after Desktop Kill default background appear and after
         that on performing boot it display only one resolution i.e. 1024*768
     --End---64x1206
402] --Start--above-64x1206  Thu Oct 24 11:28:10 IST 2024 "7.2.7" by Namrata
         1] Did changes to open Configuration Password
     --End---64x1206
402] --Start--above-64x1206  Thu Oct 29 11:28:10 IST 2024 "7.2.8" by Namrata
         1] change shortcut of Lockscreen "ctrl+shift+L" to "Super+L"
     --End---64x1206
403] --Start--above-64x1206  Oct Nov 05 11:28:10 IST 2024 "7.2.9" by Namrata
         1] Did changes in customfiledialog to sho /home contain, need to restrict "Custom" user
     --End---64x1206
404] --Start--above-64x1209  Oct Nov 22 12:28:10 IST 2024 "7.3.0" by Snehal
         1] Use unifiedx instead of fusionms as the alias name of DNS for UEM auto-discovery in the network.
     --End---64x1209
405] -- Start--above-64x1210 Fri Nov  22 11:51:18 IST 2024 VERSION "7.3.1" --by Namrata
        1] replace hostname command with hostnamectl as told by prashan pokhriyal sir
    --End--64x1210
406] --Start--above-64x1211 Tue Nov 26 11:28:10 IST 2024 "7.3.2" by Namrata
       Did changes for Bel Client
       1.  Did changes to set continent/region as asia kolkata
       2. For Bel they need all Application on Desktop by default
   --End---64x1211
407] --Start--above-64x1222 Thu Jan 09 11:28:10 IST 2024 "7.3.3" by Namrata
       Did changes for Bel Client
       1. Client is facing issue in Network Configuration, after shutdown ip get change, and sometime Network fails to configure
          prashant sir manages it from there side using Network service
          so for Bel :restricted deletion of /var/lib/dhclient/dhclient-"+device+".leases file in ExecuteNetworkSettings
   --End---64x1222
    */
#endif // CHANGELOG_H
